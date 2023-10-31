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

BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    delete this->root;
}

void BinarySearchTree::insert(int key) {
    BinarySearchTreeNode* node = new BinarySearchTreeNode(key);
    if (this->root == nullptr) {
        this->root = node;
        return;
    }
    BinarySearchTreeNode* parent = nullptr;
    BinarySearchTreeNode* current = this->root;
    while (current != nullptr) {
        parent = current;
        if (node->key < current->key) {
            current = current->left;
        } else if (node->key > current->key) {
            current = current->right;
        } else {
            return;
        }
    }

    node->parent = parent;
    if (node->key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

void BinarySearchTree::remove(int key) {
    BinarySearchTreeNode* node = this->search(key);
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr) {
        this->transplant(node, node->right);
    } else if (node->right == nullptr) {
        this->transplant(node, node->left);
    } else {
        BinarySearchTreeNode* successor = node->right->minimal_node();
        if (successor->parent != node) {
            this->transplant(successor, successor->right);
            successor->right = node->right;
            successor->right->parent = successor;
        }
        this->transplant(node, successor);
        successor->left = node->left;
        successor->left->parent = successor;
    }

    node->left = nullptr;
    node->right = nullptr;
    delete node;
}

BinarySearchTreeNode* BinarySearchTree::search(int key) {
    BinarySearchTreeNode* node = this->root;
    while (node != nullptr && node->key != key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

void BinarySearchTree::transplant(BinarySearchTreeNode* u, BinarySearchTreeNode* v) {
    if (u->parent == nullptr) {
        this->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != nullptr) {
        v->parent = u->parent;
    }
}
