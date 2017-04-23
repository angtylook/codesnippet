#include "rbt.h"
#include <iostream>

RedBlackTree::RedBlackTree()
: nil_(nullptr)
, root_(nullptr) {
    nil_ = new Node();
    nil_->parent = nullptr;
    nil_->left = nullptr;
    nil_->right = nullptr;
    nil_->color = BLACK;
}

RedBlackTree::~RedBlackTree() {
    if(root_) {
        destroy(root_);
    }
    delete(nil_);
}

bool RedBlackTree::empty() {
    return !root_;
}

bool RedBlackTree::contain(int key) {
    if(!root_)
        return false;
    Node* node = search(root_, key);
    return node != nil_ && node->key == key;
}

bool RedBlackTree::get(int key, std::string& value) {
    if(!root_)
        return false;
    Node* node = search(root_, key);
    if(node != nil_ && node->key == key) {
        value = node->value;
        return true;
    }
    return false;
}

bool RedBlackTree::minimum(std::string& value) {
    if(!root_)
        return false;
    Node* node = minimum(root_);
    if(node != nil_) {
        value = node->value;
        return true;
    }
    return false;
}

bool RedBlackTree::maximum(std::string& value) {
    if(!root_)
        return false;
    Node* node = maximum(root_);
    if(node != nil_) {
        value = node->value;
        return true;
    }
    return false;
}

bool RedBlackTree::insert(int key, const std::string& value) {
    Node* node = nil_;
    if(root_) {
        node = search(root_, key);
    }
    if(node != nil_)
        return false;
    node = new Node();
    node->key = key;
    node->value = value;
    node->parent = nil_;
    node->left = nil_;
    node->right = nil_;
    node->color = RED;
    insert(node);
    return true;
}

void RedBlackTree::insert_or_assign(int key, const std::string& value) {
    Node* node = nil_;
    if(root_) {
        node = search(root_, key);
    }
    if(node != nil_) {
        node->value = value;
    } else {
        node = new Node();
        node->key = key;
        node->value = value;
        node->parent = nil_;
        node->left = nil_;
        node->right = nil_;
        node->color = RED;
        insert(node);
    }
}

bool RedBlackTree::remove(int key) {
    Node* node = search(root_, key);
    if(node != nil_) {
        remove(node);
        return true;
    }
    return false;
}

bool RedBlackTree::remove_and_get(int key, std::string& value) {
    Node* node = search(root_, key);
    if(node != nil_) {
        value = node->value;
        remove(node);
        return true;
    }
    return false;
}

void RedBlackTree::inorder_walk(const std::function<void (int, std::string)>& func) {
    if(root_)
        inorder_walk(root_, func);
}

void RedBlackTree::inorder_walk(Node* node, const std::function<void (int, std::string)>& func) {
    if(node != nil_) {
        inorder_walk(node->left, func);
        func(node->key, node->value);
        inorder_walk(node->right, func);
    }
}

RedBlackTree::Node* RedBlackTree::search(Node* node, int key) {
    while(node != nil_ && node->key != key) {
        if(key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

RedBlackTree::Node* RedBlackTree::minimum(Node* node) {
    while(node != nil_ && node->left != nil_) {
        node = node->left;
    }
    return node;
}

RedBlackTree::Node* RedBlackTree::maximum(Node* node) {
    while(node != nil_ && node->right != nil_) {
        node = node->right;
    }
    return node;
}

RedBlackTree::Node* RedBlackTree::successor(Node* node, int key) {
    if(node == nil_)
        return nil_;
    if(node->right) {
        return minimum(node->right);
    }
    Node* parent = node->parent;
    while(parent != nil_ && parent->right == node) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}

RedBlackTree::Node* RedBlackTree::predecessor(Node* node, int key) {
    if(node == nil_)
        return nil_;
    if(node->left) {
        return maximum(node->left);
    }
    Node* parent = node->parent;
    while(parent != nil_ && parent->left == node) {
        node = parent;
        parent = node->parent;
    }
    return parent;
}

void RedBlackTree::insert(Node* node) {
    // find the insert point as leaf
    Node* leaf = nil_;
    Node* sentry = root_;
    while(sentry && sentry != nil_) {
        leaf = sentry;
        if(node->key < sentry->key) {
            sentry = sentry->left;
        } else {
            sentry = sentry->right;
        }
    }
    node->parent = leaf;
    if(leaf == nil_) {
        root_ = node;
    } else if(node->key < leaf->key) {
        leaf->left = node;
    } else {
        leaf->right = node;
    }
    insert_fixup(node);
}
// introduce to algorithms 3rd, ch 13 red black tree. 
void RedBlackTree::insert_fixup(Node* node) {
    while(node->parent->color == RED) {
        if(node->parent->parent->left == node->left) {
            Node* uncle = node->parent->parent->right;
            // case 1
            if(uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if(node == node->parent->right) {
                    // case 2
                    node = node->parent;
                    left_rotate(node);
                }
                // case 3
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(node->parent->parent);
            }
        } else {  // node->parent->parent->right == node->right
            Node* uncle = node->parent->parent->left;
            // case 1
            if(uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if(node == node->parent->left) {
                    // case 2
                    node = node->parent;
                    right_rotate(node);
                }
                // case 3
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(node->parent->parent);
            }
        }
    }
    root_->color = BLACK;
}

void RedBlackTree::transplant(Node* to, Node* from) {
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

void RedBlackTree::remove(Node* node) {
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

void RedBlackTree::left_rotate(Node* node)
{
    // save node's right, it will be in node position
    Node* right = node->right;
    // turn node.right.left as node.right
    node->right = right->left;
    if(node->right && node->right != nil_) {
        node->right->parent = node;
    }
    // replace node position with right
    right->parent = node->parent;
    if(right->parent == nil_) {
        root_ = right;
    } else if (node->parent->left == node) {
        node->parent->left = right;
    } else {
        node->parent->right = right;
    }
    // node as right.left
    right->left = node;
    node->parent = right;
}

void RedBlackTree::right_rotate(Node* node)
{
    // save node's left, it will be in node position
    Node* left = node->left;
    // turn node.left.right as node.left
    node->left = left->right;
    if(node->left && node->left != nil_) {
        node->left->parent = node;
    }
    // replace node position with left
    left->parent = node->parent;
    if(left->parent == nil_) {
        root_ = left;
    } else if (node->parent->left == node) {
        node->parent->left = left;
    } else {
        node->parent->right = left;
    }
    // node as left.right
    left->right = node;
    node->parent = left;
}

void RedBlackTree::destroy(Node* node) {
    if(node && node != nil_) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

int main(int argc, char* argv[])
{
    RedBlackTree bst;
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
/*
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
*/
    return 0;
}
