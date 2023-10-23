#include "binary_search_tree.hpp"

BinarySearchTreeNode::BinarySearchTreeNode(int key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

BinarySearchTreeNode::~BinarySearchTreeNode() {
    delete this->left;
    delete this->right;
}

BinarySearchTreeNode* BinarySearchTreeNode::minimal_node() {
    BinarySearchTreeNode* node = this;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BinarySearchTreeNode* BinarySearchTreeNode::maximal_node() {
    BinarySearchTreeNode* node = this;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

BinarySearchTreeNode* BinarySearchTreeNode::predecessor() {
    if (this->left != nullptr) {
        return this->left->maximal_node();
    }
    BinarySearchTreeNode* node = this;
    while (node->parent != nullptr && node->parent->left == node) {
        node = node->parent;
    }
    return node->parent;
}

BinarySearchTreeNode* BinarySearchTreeNode::successor() {
    if (this->right != nullptr) {
        return this->right->minimal_node();
    }
    BinarySearchTreeNode* node = this;
    while (node->parent != nullptr && node->parent->right == node) {
        node = node->parent;
    }
    return node->parent;
}
