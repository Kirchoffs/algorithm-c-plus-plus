#ifndef BIN_SEARCH_TREE_HPP
#define BIN_SEARCH_TREE_HPP

class BinarySearchTreeNode {
public:
    int key;
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
    BinarySearchTreeNode* parent;

    BinarySearchTreeNode(int key);
    ~BinarySearchTreeNode();

    BinarySearchTreeNode* minimal_node();
    BinarySearchTreeNode* maximal_node();
    BinarySearchTreeNode* predecessor();
    BinarySearchTreeNode* successor();
};

class BinarySearchTree {
public:
    BinarySearchTreeNode* root;

    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int key);
    void remove(int key);
    BinarySearchTreeNode* search(int key);

private:
    void transplant(BinarySearchTreeNode* u, BinarySearchTreeNode* v);
};

#endif
