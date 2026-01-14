#pragma once
#include <cassert>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <stack>
#include <string>

template <typename KeyType, typename ValueType>
class AVLTree {
   private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* left;
        Node* right;
        int bfactor;

        Node(KeyType const& k, ValueType const& v) : key(k), value(v), left(nullptr), right(nullptr), bfactor(0) {}
    };

    Node* root = nullptr;
    size_t tree_size = 0;

    // =================================
    // Clear
    // =================================
    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // =================================
    // R Rotation (LL case)
    // =================================
    void rotateToRight(Node*& root) {
        Node* p = root->left;

        if (root == nullptr) {
            std::cerr << "Error: rotateRight called with null root" << std::endl;
        } else if (root->left == nullptr) {
            std::cerr << "Error: rotateRight called with null left child" << std::endl;
        } else {
            root->left = p->right;
            p->right = root;
            root = p;
        }
    }

    // =================================
    // L Rotation (RR case)
    // =================================
    void rotateToLeft(Node*& root) {
        if (root == nullptr) {
            std::cerr << "Error: rotateLeft called with null root" << std::endl;
        } else if (root->right == nullptr) {
            std::cerr << "Error: rotateLeft called with null right child" << std::endl;
        } else {
            Node* p = root->right;
            root->right = p->left;
            p->left = root;
            root = p;
        }
    }

    // =================================
    // Balancing when left subtree is taller
    // =================================
    void balanceFromLeft(Node*& root) {
        Node* p;
        Node* w;

        p = root->left;

        switch (p->bfactor) {
            case 1:
                root->bfactor = 0;
                p->bfactor = 0;
                rotateToRight(root);
                break;
            case 0:
                std::cerr << "Error: balanceLeft called on balanced node" << std::endl;
                break;
            case -1:  // LR rotation (Zig-Zag)
                w = p->right;
                switch (w->bfactor) {
                    case 1:
                        root->bfactor = -1;
                        p->bfactor = 0;
                        break;
                    case 0:
                        root->bfactor = 0;
                        p->bfactor = 0;
                        break;
                    case -1:
                        root->bfactor = 0;
                        p->bfactor = 1;
                        break;
                }
                w->bfactor = 0;
                rotateToLeft(p);
                root->left = p;
                rotateToRight(root);
        }
    }

    // =================================
    // Balancing when right subtree is taller
    // =================================
    void balanceFromRight(Node*& root) {
        Node* p = root->right;
        Node* w;

        switch (p->bfactor) {
            case -1:  // RR Case (Right-Right)
                root->bfactor = 0;
                p->bfactor = 0;
                rotateToLeft(root);
                break;
            case 0:
                std::cerr << "Error: Cannot balance from the left." << std::endl;
                break;
            case 1:  // RL Case (Right-Left)
                w = p->left;
                switch (w->bfactor) {
                    case 1:
                        root->bfactor = 0;
                        p->bfactor = -1;
                        break;
                    case 0:
                        root->bfactor = 0;
                        p->bfactor = 0;
                        break;
                    case -1:
                        root->bfactor = 1;
                        p->bfactor = 0;
                        break;
                }
                w->bfactor = 0;
                rotateToRight(p);
                root->right = p;
                rotateToLeft(root);
        }
    }

    void insertHelper(Node*& root, KeyType const& key, ValueType const& value, bool& isTaller) {
        if (root == nullptr) {
            root = new Node(key, value);
            isTaller = true;
            this->tree_size++;
            return;
        }

        // Check for duplicate keys
        if (root->key == key) {
            root->value = value;  // Update value for existing key
            isTaller = false;
            return;
        }

        // Move to left subtree
        if (key < root->key) {
            insertHelper(root->left, key, value, isTaller);
            if (isTaller) {
                switch (root->bfactor) {
                    case 1:  // already left heavy -> -2 unbalanced
                        balanceFromLeft(root);
                        isTaller = false;
                        break;
                    case 0:  // balanced -> left heavy (1)
                        root->bfactor = 1;
                        isTaller = true;
                        break;
                    case -1:  // already right heavy -> balanced (0)
                        root->bfactor = 0;
                        isTaller = false;
                        break;
                }
            }
        } else {
            insertHelper(root->right, key, value, isTaller);
            if (isTaller) {
                switch (root->bfactor) {
                    case 1:  // already left heavy -> balanced (0)
                        root->bfactor = 0;
                        isTaller = false;
                        break;
                    case 0:  // balanced -> right heavy (-1)
                        root->bfactor = -1;
                        isTaller = true;
                        break;
                    case -1:  // already right heavy -> -2 unbalanced
                        balanceFromRight(root);
                        isTaller = false;
                        break;
                }
            }
        }
    }

    void toStringHelper(Node* node, std::stringstream& ss) const {
        if (node == nullptr) {
            return;
        }
        // ([bf,key,value],Left,Right)
        ss << "([" << node->bfactor << "," << node->key << "," << node->value << "],";
        toStringHelper(node->left, ss);
        ss << ",";
        toStringHelper(node->right, ss);
        ss << ")";
    }

    void printHelper(Node* node, std::ostream& stream, std::string indent, std::string prefix) const {
        if (node == nullptr) {
            return;
        }
        stream << indent << prefix << "[" << node->bfactor << "," << node->key << "," << node->value << "]\n";
        std::string nextIndent = indent;
        if (prefix != "") {
            nextIndent += "    ";
        } else if (indent == "") {
            nextIndent = "    ";
        }

        printHelper(node->left, stream, nextIndent, "L: ");
        printHelper(node->right, stream, nextIndent, "R: ");
    }

   public:
    AVLTree() : root(nullptr), tree_size(0) {}

    ~AVLTree() { clear(root); }

    size_t size() const { return tree_size; }

    void insert(KeyType const& key, ValueType const& value) {
        bool isTaller = false;
        insertHelper(root, key, value, isTaller);
    }

    ValueType* find(KeyType const& key) {
        Node* current = root;
        while (current != nullptr) {
            if (current->key == key) {
                return &(current->value);
            } else if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
    }

    std::string toString() const {
        std::stringstream ss;
        toStringHelper(root, ss);
        return ss.str();
    }

    void print(std::ostream& stream) const { printHelper(root, stream, "", ""); }

    // =================================
    // Iterator (const) for in-order traversal
    // =================================
    class ConstIterator {
       private:
        std::stack<Node*> nodeStack;

        void pushLeft(Node* node) {
            while (node != nullptr) {
                nodeStack.push(node);
                node = node->left;
            }
        }

       public:
        using pointer = const Node*;
        using reference = const Node&;
        using iterator_category = std::forward_iterator_tag;
        using value_type = Node;
        using difference_type = std::ptrdiff_t;

        ConstIterator(Node* root) { pushLeft(root); }
        ConstIterator() {}

        reference operator*() const { return *(nodeStack.top()); }
        pointer operator->() const { return nodeStack.top(); }

        ConstIterator& operator++() {
            Node* node = nodeStack.top();
            nodeStack.pop();

            if (node->right != nullptr) {
                pushLeft(node->right);
            }

            return *this;
        }

        bool operator==(const ConstIterator& other) const {
            if (nodeStack.empty() && other.nodeStack.empty()) {
                return true;
            } else if (!nodeStack.empty() && !other.nodeStack.empty()) {
                return nodeStack.top() == other.nodeStack.top();
            } else {
                return false;
            }
        }

        bool operator!=(const ConstIterator& other) const { return !(*this == other); }
    };

    using const_iterator = ConstIterator;

    const_iterator begin() const { return ConstIterator(root); }

    const_iterator end() const { return ConstIterator(); }

    const_iterator cbegin() const { return begin(); }

    const_iterator cend() const { return end(); }
};

template <typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& stream, AVLTree<KeyType, ValueType> const& tree) {
    tree.print(stream);
    return stream;
}