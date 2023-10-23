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

#endif
