#pragma once
#include <cassert>
#include <iomanip>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>

template <typename KeyType, typename ValueType>
class BinarySearchTree {
   private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* left;
        Node* right;

        Node(KeyType const& key, ValueType const& value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;
    size_t treeSize = 0;

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    };

    Node* remove(Node* node, KeyType const& key) {
        if (node == nullptr) return nullptr;

        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            // case 1 : no child or one child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                treeSize--;
                return temp;  // (prev)node points temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                treeSize--;
                return temp;  // (prev)node points temp;
            }

            // case 2 : two children
            Node* temp = findMax(node->left);  // Successor Node

            node->key = temp->key;
            node->value = temp->value;

            node->left = remove(node->left, temp->key);  // Delete the location of successor node (original node that should be removed)
        }
        return node;
    };

    Node* findMax(Node* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    void printHelper(Node* node, std::ostream& stream, std::string indent, std::string prefix) const {
        if (node == nullptr) return;

        stream << indent << prefix << "[" << node->key << ", " << node->value << "]\n";

        std::string nextIndent = indent;
        if (prefix != "") {
            nextIndent += "    ";
        } else if (indent == "") {
            nextIndent = "    ";
        }

        printHelper(node->left, stream, nextIndent, "L: ");
        printHelper(node->right, stream, nextIndent, "R: ");
    }

    void toStringHelper(Node* node, std::stringstream& ss) const {
        if (node == nullptr) return;

        ss << "([" << node->key << "," << node->value << "],";
        toStringHelper(node->left, ss);
        ss << ",";
        toStringHelper(node->right, ss);
        ss << ")";
    }

    void copyTreeHelper(Node*& dest, Node* src) {
        if (src == nullptr) {
            dest = nullptr;
            return;
        } else {
            dest = new Node(src->key, src->value);
            copyTreeHelper(dest->left, src->left);
            copyTreeHelper(dest->right, src->right);
        }
    }

   public:
    // Constructor
    BinarySearchTree() : root(nullptr), treeSize(0) {}

    // Destructor
    ~BinarySearchTree() { clear(root); }

    // Copy Constructor
    BinarySearchTree(const BinarySearchTree& other) : root(nullptr), treeSize(0) {
        copyTreeHelper(this->root, other.root);
        this->treeSize = other.treeSize;
    }

    // Copy Assignment Operator
    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this != &other) {
            clear(root);
            copyTreeHelper(this->root, other.root);
            this->treeSize = other.treeSize;
        }
        return *this;
    }

    size_t size() const { return treeSize; }

    void insert(KeyType const& key, ValueType const& value) {
        if (root == nullptr) {
            root = new Node(key, value);
            treeSize++;
            return;
        }

        Node* current = root;
        while (true) {
            if (key == current->key) {
                current->value = value;  // Update existing value
                return;
            }

            // Traverse to the left or right subtree
            if (key < current->key) {
                if (current->left == nullptr) {
                    current->left = new Node(key, value);
                    treeSize++;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(key, value);
                    treeSize++;
                    return;
                }
                current = current->right;
            }
        }
    }

    void remove(KeyType const& key) { root = remove(root, key); }

    ValueType* find(KeyType const& key) {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->key) {
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
};

template <typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& stream, BinarySearchTree<KeyType, ValueType> const& tree) {
    tree.print(stream);
    return stream;
}
