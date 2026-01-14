#include "../AVLTreeLib/AVLTree.h"
#include "gtest/gtest.h"

TEST(AVLTree, leftRootRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(10, 10);
    tree.insert(20, 20);
    std::string expected = "([-1,10,10],,([0,20,20],,))";
    ASSERT_EQ(expected, tree.toString());
    tree.insert(30, 30);
    expected = "([0,20,20],([0,10,10],,),([0,30,30],,))";
    ASSERT_EQ(size_t{3}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, leftRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(60, 60);
    tree.insert(20, 20);
    tree.insert(70, 70);
    tree.insert(10, 10);
    tree.insert(30, 30);
    tree.insert(80, 80);
    tree.insert(25, 25);
    tree.insert(40, 40);
    std::string expected = "([1,60,60],([-1,20,20],([0,10,10],,),([0,30,30],([0,25,25],,),([0,40,40],,))),([-1,70,70],,([0,80,80],,)))";
    ASSERT_EQ(expected, tree.toString());
    tree.insert(50, 50);
    expected = "([1,60,60],([0,30,30],([0,20,20],([0,10,10],,),([0,25,25],,)),([-1,40,40],,([0,50,50],,))),([-1,70,70],,([0,80,80],,)))";
    ASSERT_EQ(size_t{9}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, rightLeftRootRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(10, 10);
    tree.insert(30, 30);
    std::string expected = "([-1,10,10],,([0,30,30],,))";
    ASSERT_EQ(size_t{2}, tree.size());
    ASSERT_EQ(expected, tree.toString());
    tree.insert(20, 20);
    expected = "([0,20,20],([0,10,10],,),([0,30,30],,))";
    ASSERT_EQ(size_t{3}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, rightLeftRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(60, 60);
    tree.insert(20, 20);
    tree.insert(70, 70);
    tree.insert(10, 10);
    tree.insert(30, 30);
    tree.insert(80, 80);
    tree.insert(25, 25);
    tree.insert(40, 40);
    std::string expected = "([1,60,60],([-1,20,20],([0,10,10],,),([0,30,30],([0,25,25],,),([0,40,40],,))),([-1,70,70],,([0,80,80],,)))";
    ASSERT_EQ(size_t{8}, tree.size());
    ASSERT_EQ(expected, tree.toString());
    tree.insert(22, 22);
    expected = "([1,60,60],([0,25,25],([0,20,20],([0,10,10],,),([0,22,22],,)),([-1,30,30],,([0,40,40],,))),([-1,70,70],,([0,80,80],,)))";
    ASSERT_EQ(size_t{9}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, rightRootRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(30, 30);
    tree.insert(20, 20);
    std::string expected = "([1,30,30],([0,20,20],,),)";
    ASSERT_EQ(size_t{2}, tree.size());
    ASSERT_EQ(expected, tree.toString());
    tree.insert(10, 10);
    expected = "([0,20,20],([0,10,10],,),([0,30,30],,))";
    ASSERT_EQ(size_t{3}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, rightRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(30, 30);
    tree.insert(20, 20);
    tree.insert(80, 80);
    tree.insert(10, 10);
    tree.insert(60, 60);
    tree.insert(90, 90);
    tree.insert(50, 50);
    tree.insert(70, 70);
    std::string expected = "([-1,30,30],([1,20,20],([0,10,10],,),),([1,80,80],([0,60,60],([0,50,50],,),([0,70,70],,)),([0,90,90],,)))";
    ASSERT_EQ(size_t{8}, tree.size());
    ASSERT_EQ(expected, tree.toString());
    tree.insert(40, 40);
    expected = "([-1,30,30],([1,20,20],([0,10,10],,),),([0,60,60],([1,50,50],([0,40,40],,),),([0,80,80],([0,70,70],,),([0,90,90],,))))";
    ASSERT_EQ(size_t{9}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, leftRightRootRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(30, 30);
    tree.insert(10, 10);
    std::string expected = "([1,30,30],([0,10,10],,),)";
    ASSERT_EQ(size_t{2}, tree.size());
    ASSERT_EQ(expected, tree.toString());
    tree.insert(20, 20);
    expected = "([0,20,20],([0,10,10],,),([0,30,30],,))";
    ASSERT_EQ(size_t{3}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, leftRightRotationAfterInsert) {
    AVLTree<int, int> tree;
    tree.insert(30, 30);
    tree.insert(20, 20);
    tree.insert(80, 80);
    tree.insert(10, 10);
    tree.insert(50, 50);
    tree.insert(90, 90);
    tree.insert(40, 40);
    tree.insert(60, 60);
    std::string expected = "([-1,30,30],([1,20,20],([0,10,10],,),),([1,80,80],([0,50,50],([0,40,40],,),([0,60,60],,)),([0,90,90],,)))";
    ASSERT_EQ(size_t{8}, tree.size());
    ASSERT_EQ(expected, tree.toString());
    tree.insert(70, 70);
    expected = "([-1,30,30],([1,20,20],([0,10,10],,),),([0,60,60],([1,50,50],([0,40,40],,),),([0,80,80],([0,70,70],,),([0,90,90],,))))";
    ASSERT_EQ(size_t{9}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, ConstructEmpty) {
    AVLTree<int, int> tree;
    std::string expected = "";
    ASSERT_EQ(size_t{0}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertToEmpty) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    std::string expected = "([0,10,100],,)";
    ASSERT_EQ(size_t{1}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe2LevelOnTheLeftThereIsNoRight) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    std::string expected = "([1,10,100],([0,5,50],,),)";
    ASSERT_EQ(size_t{2}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe2LevelOnTheRightThereIsNoLeft) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(20, 200);
    std::string expected = "([-1,10,100],,([0,20,200],,))";
    ASSERT_EQ(size_t{2}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe2LevelOnTheLeftThereIsRight) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(20, 200);
    tree.insert(5, 50);
    std::string expected = "([0,10,100],([0,5,50],,),([0,20,200],,))";
    ASSERT_EQ(size_t{3}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe2LevelOnTheRightThereIsLeft) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(20, 200);
    std::string expected = "([0,10,100],([0,5,50],,),([0,20,200],,))";
    ASSERT_EQ(size_t{3}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelLeftLeftThereIsNoRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(10, 100);
    std::string expected = "([1,50,500],([1,20,200],([0,10,100],,),),([0,80,800],,))";
    ASSERT_EQ(size_t{4}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelLeftLeftThereIsRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(30, 300);
    tree.insert(10, 100);
    std::string expected = "([1,50,500],([0,20,200],([0,10,100],,),([0,30,300],,)),([0,80,800],,))";
    ASSERT_EQ(size_t{5}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelLeftRightThereIsNoLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(30, 300);
    std::string expected = "([1,50,500],([-1,20,200],,([0,30,300],,)),([0,80,800],,))";
    ASSERT_EQ(size_t{4}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelLeftRightThereIsLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(10, 100);
    tree.insert(30, 300);
    std::string expected = "([1,50,500],([0,20,200],([0,10,100],,),([0,30,300],,)),([0,80,800],,))";
    ASSERT_EQ(size_t{5}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelRightLeftThereIsNoRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(70, 700);
    std::string expected = "([-1,50,500],([0,20,200],,),([1,80,800],([0,70,700],,),))";
    ASSERT_EQ(size_t{4}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelRightLeftThereIsRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(90, 900);
    tree.insert(70, 700);
    std::string expected = "([-1,50,500],([0,20,200],,),([0,80,800],([0,70,700],,),([0,90,900],,)))";
    ASSERT_EQ(size_t{5}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelRightRightThereIsNoLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(90, 900);
    std::string expected = "([-1,50,500],([0,20,200],,),([-1,80,800],,([0,90,900],,)))";
    ASSERT_EQ(size_t{4}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertOnThe3LevelRightRightThereIsLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(70, 700);
    tree.insert(90, 900);
    std::string expected = "([-1,50,500],([0,20,200],,),([0,80,800],([0,70,700],,),([0,90,900],,)))";
    ASSERT_EQ(size_t{5}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, insertExisting) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(70, 700);
    tree.insert(90, 900);
    tree.insert(50, 501);
    tree.insert(20, 201);
    tree.insert(80, 801);
    tree.insert(70, 701);
    tree.insert(90, 901);
    std::string expected = "([-1,50,501],([0,20,201],,),([0,80,801],([0,70,701],,),([0,90,901],,)))";
    ASSERT_EQ(size_t{5}, tree.size());
    ASSERT_EQ(expected, tree.toString());
}
TEST(AVLTree, findInEmpty) {
    AVLTree<int, int> tree;
    ASSERT_EQ(tree.find(10), nullptr);
}
TEST(AVLTree, findNotExisted) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(20, 200);
    ASSERT_EQ(tree.find(2), nullptr);
    ASSERT_EQ(tree.find(7), nullptr);
    ASSERT_EQ(tree.find(12), nullptr);
    ASSERT_EQ(tree.find(24), nullptr);
}
TEST(AVLTree, findOnThe1LevelNoChildren) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    ASSERT_EQ(100, *tree.find(10));
    tree.insert(5, 50);
    ASSERT_EQ(100, *tree.find(10));
    tree.insert(20, 200);
    ASSERT_EQ(100, *tree.find(10));
}
TEST(AVLTree, findOnThe1LevelIsLeftChild) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    ASSERT_EQ(100, *tree.find(10));
}
TEST(AVLTree, findOnThe1LevelIsRightChild) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(20, 200);
    ASSERT_EQ(100, *tree.find(10));
}
TEST(AVLTree, findOnThe1LevelAreChildren) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(20, 200);
    ASSERT_EQ(100, *tree.find(10));
}
TEST(AVLTree, findOnThe2LevelOnTheLeftThereIsNoRight) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    ASSERT_EQ(50, *tree.find(5));
}
TEST(AVLTree, findOnThe2LevelOnTheRightThereIsNoLeft) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(20, 200);
    ASSERT_EQ(200, *tree.find(20));
}
TEST(AVLTree, findOnThe2LevelOnTheLeftThereIsRight) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(20, 200);
    tree.insert(5, 50);
    ASSERT_EQ(50, *tree.find(5));
}
TEST(AVLTree, findOnThe2LevelOnTheRightThereIsLeft) {
    AVLTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(20, 200);
    ASSERT_EQ(200, *tree.find(20));
}
TEST(AVLTree, findOnThe3LevelLeftLeftThereIsNoRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(10, 100);
    ASSERT_EQ(100, *tree.find(10));
}
TEST(AVLTree, findOnThe3LevelLeftLeftThereIsRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(30, 300);
    tree.insert(10, 100);
    ASSERT_EQ(100, *tree.find(10));
}
TEST(AVLTree, findOnThe3LevelLeftRightThereIsNoLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(30, 300);
    ASSERT_EQ(300, *tree.find(30));
}
TEST(AVLTree, findOnThe3LevelLeftRightThereIsLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(10, 100);
    tree.insert(30, 300);
    ASSERT_EQ(300, *tree.find(30));
}
TEST(AVLTree, findOnThe3LevelRightLeftThereIsNoRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(70, 700);
    ASSERT_EQ(700, *tree.find(70));
}
TEST(AVLTree, findOnThe3LevelRightLeftThereIsRight) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(90, 900);
    tree.insert(70, 700);
    ASSERT_EQ(700, *tree.find(70));
}
TEST(AVLTree, findOnThe3LevelRightRightThereIsNoLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(90, 900);
    ASSERT_EQ(900, *tree.find(90));
}
TEST(AVLTree, findOnThe3LevelRightRightThereIsLeft) {
    AVLTree<int, int> tree;
    tree.insert(50, 500);
    tree.insert(20, 200);
    tree.insert(80, 800);
    tree.insert(70, 700);
    tree.insert(90, 900);
    ASSERT_EQ(900, *tree.find(90));
}
TEST(AVLTree, print0) {
    AVLTree<int, int> tree;
    std::ostringstream stream;
    tree.print(stream);
    auto s = stream.str();
    std::string s1 = "";
    ASSERT_EQ(s1, s);
}
TEST(AVLTree, print1) {
    AVLTree<int, int> tree;
    tree.insert(1, 1);
    std::ostringstream stream;
    tree.print(stream);
    auto s = stream.str();
    std::string s1 = "[0,1,1]\n";
    ASSERT_EQ(s1, s);
}
TEST(AVLTree, print3) {
    AVLTree<int, int> tree;
    tree.insert(2, 2);
    tree.insert(1, 1);
    tree.insert(3, 3);
    std::ostringstream stream;
    tree.print(stream);
    auto s = stream.str();
    std::string s1 = "[0,2,2]\n    L: [0,1,1]\n    R: [0,3,3]\n";
    ASSERT_EQ(s1, s);
}
TEST(AVLTree, print7) {
    AVLTree<int, int> tree;
    tree.insert(4, 4);
    tree.insert(2, 2);
    tree.insert(1, 1);
    tree.insert(3, 3);
    tree.insert(6, 6);
    tree.insert(5, 5);
    tree.insert(7, 7);
    std::ostringstream stream;
    tree.print(stream);
    auto s = stream.str();
    std::string s1 = "[0,4,4]\n    L: [0,2,2]\n        L: [0,1,1]\n        R: [0,3,3]\n    R: [0,6,6]\n        L: [0,5,5]\n        R: [0,7,7]\n";
    ASSERT_EQ(s1, s);
}
TEST(AVLTree, streamInsertionOperator0) {
    AVLTree<int, int> tree;
    std::ostringstream stream;
    stream << tree;
    auto s = stream.str();
    std::string s1 = "";
    ASSERT_EQ(s1, s);
}
TEST(AVLTree, streamInsertionOperator1) {
    AVLTree<int, int> tree;
    tree.insert(1, 1);
    std::ostringstream stream;
    stream << tree;
    auto s = stream.str();
    std::string s1 = "[0,1,1]\n";
    ASSERT_EQ(s1, s);
}
TEST(AVLTree, streamInsertionOperator3) {
    AVLTree<int, int> tree;
    tree.insert(2, 2);
    tree.insert(1, 1);
    tree.insert(3, 3);
    std::ostringstream stream;
    stream << tree;
    auto s = stream.str();
    std::string s1 = "[0,2,2]\n    L: [0,1,1]\n    R: [0,3,3]\n";
    ASSERT_EQ(s1, s);
}
TEST(AVLTree, streamInsertionOperator7) {
    AVLTree<int, int> tree;
    tree.insert(4, 4);
    tree.insert(2, 2);
    tree.insert(1, 1);
    tree.insert(3, 3);
    tree.insert(6, 6);
    tree.insert(5, 5);
    tree.insert(7, 7);
    std::ostringstream stream;
    stream << tree;
    auto s = stream.str();
    std::string s1 = "[0,4,4]\n    L: [0,2,2]\n        L: [0,1,1]\n        R: [0,3,3]\n    R: [0,6,6]\n        L: [0,5,5]\n        R: [0,7,7]\n";
    ASSERT_EQ(s1, s);
}
