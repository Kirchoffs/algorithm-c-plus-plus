#include "binary_search_tree.hpp"
#include <iostream>

int test_bianry_search_tree_node_minimal_maximal_node() {
    BinarySearchTreeNode* root = new BinarySearchTreeNode(5);
    root->left = new BinarySearchTreeNode(3);
    root->right = new BinarySearchTreeNode(7);
    root->left->left = new BinarySearchTreeNode(2);
    root->left->right = new BinarySearchTreeNode(4);
    root->right->left = new BinarySearchTreeNode(6);
    root->right->right = new BinarySearchTreeNode(8);
    
    int minimal_key = root->minimal_node()->key;
    if (minimal_key != 2) {
        std::cout << "test_minimal_maximal_node failed: expected 2, got " << minimal_key << std::endl;
        return 1;
    }

    int maximal_key = root->maximal_node()->key;
    if (maximal_key != 8) {
        std::cout << "test_minimal_maximal_node failed: expected 8, got " << maximal_key << std::endl;
        return 1;
    }
    
    delete root;
    return 0;
}

int test_binary_search_tree_node_predecessor_successor() {
    BinarySearchTreeNode* root = new BinarySearchTreeNode(5);
    root->left = new BinarySearchTreeNode(3);
    root->left->parent = root;
    root->right = new BinarySearchTreeNode(7);
    root->right->parent = root;
    root->left->left = new BinarySearchTreeNode(2);
    root->left->left->parent = root->left;
    root->left->right = new BinarySearchTreeNode(4);
    root->left->right->parent = root->left;
    root->right->left = new BinarySearchTreeNode(6);
    root->right->left->parent = root->right;
    root->right->right = new BinarySearchTreeNode(8);
    root->right->right->parent = root->right;
    
    int predecessor_key = root->left->right->predecessor()->key;
    if (predecessor_key != 3) {
        std::cout << "test_predecessor_successor failed: expected 3, got " << predecessor_key << std::endl;
        return 1;
    }

    int successor_key = root->left->right->successor()->key;
    if (successor_key != 5) {
        std::cout << "test_predecessor_successor failed: expected 5, got " << successor_key << std::endl;
        return 1;
    }
    
    delete root;
    return 0;
}

int test_binary_search_tree_insert() {
    BinarySearchTree* tree = new BinarySearchTree();
    tree->insert(5);
    tree->insert(3);
    tree->insert(7);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);
    
    int minimal_key = tree->root->minimal_node()->key;
    if (minimal_key != 2) {
        std::cout << "test_binary_search_tree_insert failed: expected 2, got " << minimal_key << std::endl;
        return 1;
    }

    int maximal_key = tree->root->maximal_node()->key;
    if (maximal_key != 8) {
        std::cout << "test_binary_search_tree_insert failed: expected 8, got " << maximal_key << std::endl;
        return 1;
    }
    
    delete tree;
    return 0;
}

int test_binary_search_tree_remove() {
    BinarySearchTree* tree = new BinarySearchTree();
    tree->insert(5);
    tree->insert(3);
    tree->insert(7);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);
    
    tree->remove(3);
    tree->remove(7);
    tree->remove(5);
    tree->remove(11);
    
    int minimal_key = tree->root->minimal_node()->key;
    if (minimal_key != 2) {
        std::cout << "test_binary_search_tree_remote failed: expected 2, got " << minimal_key << std::endl;
        return 1;
    }

    int maximal_key = tree->root->maximal_node()->key;
    if (maximal_key != 8) {
        std::cout << "test_binary_search_tree_remote failed: expected 8, got " << maximal_key << std::endl;
        return 1;
    }

    BinarySearchTreeNode* node = nullptr;

    node = tree->search(3);
    if (node != nullptr) {
        std::cout << "test_binary_search_tree_remote failed: expected nullptr, got " << node << std::endl;
        return 1;
    }

    node = tree->search(7);
    if (node != nullptr) {
        std::cout << "test_binary_search_tree_remote failed: expected nullptr, got " << node << std::endl;
        return 1;
    }

    node = tree->search(5);
    if (node != nullptr) {
        std::cout << "test_binary_search_tree_remote failed: expected nullptr, got " << node << std::endl;
        return 1;
    }
    
    delete tree;
    return 0;
}

int main() {
    if (test_bianry_search_tree_node_minimal_maximal_node() != 0) {
        return 1;
    }

    if (test_binary_search_tree_node_predecessor_successor() != 0) {
        return 1;
    }

    if (test_binary_search_tree_insert() != 0) {
        return 1;
    }

    if (test_binary_search_tree_remove() != 0) {
        return 1;
    }

    return 0;
}
