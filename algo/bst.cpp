#include "bst.h"

BinarySearchTree::BinarySearchTree()
: root_(nullptr) {
}

BinarySearchTree::~BinarySearchTree() {
    if(root_) {
        destroy(root_);
    }
}

bool BinarySearchTree::empty() {
    return root_ == nullptr;
}

bool BinarySearchTree::contain(int key) {
    Node* node = search(root_, key);
    return node && node->key == key;
}

bool BinarySearchTree::getValue(int key, std::string& value) {
    Node* node = search(root_, key);
    if(node && node->key == key) {
        value = node->value;
        return true;
    }
    return false;
}

bool BinarySearchTree::minimum(std::string& value) {
    Node* node = minimum(root_);
    if(node) {
        value = node->value;
        return true;
    }
    return false;
}

bool BinarySearchTree::maximum(std::string& value) {
    Node* node = maximum(root_);
    if(node) {
        value = node->value;
        return true;
    }
    return false;
}

bool BinarySearchTree::insert(int key, const std::string& value) {
    Node* node = search(root_, key);
    if(node)
        return false;
    node =  new Node();
    node->key = key;
    node->value = value;
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    insert(node);
    return true;
}

void BinarySearchTree::insert_or_assign(int key, const std::string& value) {
    Node* node = search(root_, key);
    if(node) {
        node->value = value;
    } else {
        node =  new Node();
        node->key = key;
        node->value = value;
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
        insert(node);
    }
}

bool BinarySearchTree::remove(int key) {
    return false;
}

BinarySearchTree::Node* BinarySearchTree::search(Node* node, int key) {
    while(node && node->key != key) {
        if(node->key < key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

BinarySearchTree::Node* BinarySearchTree::minimum(Node* node) {
    while(node && node->left) {
        node = node->left;
    }
    return node;
}

BinarySearchTree::Node* BinarySearchTree::maximum(Node* node) {
    while(node && node->right) {
        node = node->right;
    }
    return node;
}

BinarySearchTree::Node* BinarySearchTree::successor(Node* node, int key) {
    if(!node)
        return nullptr;
    if(node->right) {
        return minimum(node->right);
    }
    Node* parent = node->parent;
    while(parent && parent->right == node) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}

BinarySearchTree::Node* BinarySearchTree::predecessor(Node* node, int key) {
    if(!node)
        return nullptr;
    if(node->left) {
        return maximum(node->left);
    }
    Node* parent = node->parent;
    while(parent && parent->left == node) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}

BinarySearchTree::Node* BinarySearchTree::insert(Node* node) {
    Node* leaf = nullptr;
    Node* sentry = root_;
    while(sentry) {
        leaf = sentry;
        if(node->key < sentry->key) {
            sentry = sentry->left;
        } else {
            sentry = sentry->right;
        }
    }
    node->parent = leaf;
    if(!leaf) {
        root_ = node;
        return root_;
    } else if(node->key < leaf->key) {
        leaf->left = node;
    } else {
        leaf->right = node;
    }
    return node;
}

void BinarySearchTree::destroy(Node* node) {
    if(node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}
