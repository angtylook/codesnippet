#include "bst.h"
#include <iostream>

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

bool BinarySearchTree::get(int key, std::string& value) {
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
    Node* node = search(root_, key);
    if(node) {
        remove(node);
        return true;
    }
    return false;
}

bool BinarySearchTree::remove_and_get(int key, std::string& value) {
    Node* node = search(root_, key);
    if(node) {
        value = node->value;
        remove(node);
        return true;
    }
    return false;
}

void BinarySearchTree::inorder_walk(const std::function<void (int, std::string)>& func) {
    inorder_walk(root_, func);
}

void BinarySearchTree::inorder_walk(Node* node, const std::function<void (int, std::string)>& func) {
    if(node) {
        inorder_walk(node->left, func);
        func(node->key, node->value);
        inorder_walk(node->right, func);
    }
}

BinarySearchTree::Node* BinarySearchTree::search(Node* node, int key) {
    while(node && node->key != key) {
        if(key < node->key) {
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

void BinarySearchTree::transplant(Node* to, Node* from) {
    if(!to->parent) {
        root_ = from;
    } else if(to == to->parent->left) {
        to->parent->left = from;
    } else {
        to->parent->right = from;
    }
    if(from)
        from->parent = to->parent;
}

void BinarySearchTree::remove(Node* node) {
    if(!node->left) {
        transplant(node, node->right);
    } else if(!node->right) {
        transplant(node, node->left);
    } else {
        // then mini's left must be null.
        // otherwist mini will not be minimum.
        Node* mini = minimum(node->right);
        if(mini->parent != node) {
            // after replace mini with its right
            // then mini is free to replace node
            transplant(mini, mini->right);
            // take off node's right
            mini->right = node->right;
            mini->right->parent = mini;
        }
        // if mini's parent is node
        // node's right is mini
        transplant(node, mini);
        // handle node's left
        mini->left = node->left;
        mini->left->parent = mini;
    }
    delete node;
}

void BinarySearchTree::destroy(Node* node) {
    if(node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

int main(int argc, char* argv[])
{
    BinarySearchTree bst;
    bst.insert(3, "three");
    bst.insert(2, "two");
    bst.insert(7, "seven");
    bst.insert(13, "13");
    bst.insert(15, "15");
    bst.insert(9, "nine");
    bst.insert(4, "four");
    bst.insert(6, "six");
    bst.insert(18, "18");
    bst.insert(20, "20");
    bst.insert(17, "17");
    std::cout << "{" << std::endl;
    bst.inorder_walk([](int key, std::string value) -> void {
        std::cout << "  { " << key << " : " << value << " }" << std::endl;
    });
    std::cout << "}" << std::endl;

    std::string val;
    if(bst.remove_and_get(7, val)) {
        std::cout << "remove { 7 : " << val << " }" << std::endl;
    }
    val.clear();
    if(bst.remove_and_get(17, val)) {
        std::cout << "remove { 17 : " << val << " }" << std::endl;
    }
    std::cout << "{" << std::endl;
    bst.inorder_walk([](int key, std::string value) -> void {
        std::cout << "  { " << key << " : " << value << " }" << std::endl;
    });
    std::cout << "}" << std::endl;

    return 0;
}
