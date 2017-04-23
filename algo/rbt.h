#ifndef RBT_H_
#define RBT_H_

#include <string>
#include <functional>

class RedBlackTree
{
public:
    RedBlackTree();
    ~RedBlackTree();
public:
    bool empty();
    bool contain(int key);
    bool get(int key, std::string& value);
    bool minimum(std::string& value);
    bool maximum(std::string& value);

    bool insert(int key, const std::string& value);
    void insert_or_assign(int key, const std::string& value);
    bool remove(int key);
    bool remove_and_get(int key, std::string& value);

    void inorder_walk(const std::function<void (int, std::string)>& func);
private:
    enum Color {
        BLACK = 0,
        RED = 1
    };
    struct Node {
        int key;
        std::string value;
        Node* parent;
        Node* left;
        Node* right;
        Color color;
    };
private:
    // destroy tree with node as root
    void destroy(Node* node);
    // search key in tree node
    // return nullptr if not found.
    Node* search(Node* node, int key);
    // find the minimum node in tree
    // return nullptr if not found.
    Node* minimum(Node* node);
    // find the maximum node in tree
    // return nullptr if not found.
    Node* maximum(Node* node);
    // find key's successor
    // return nullptr if not found
    Node* successor(Node* node, int key);
    // find key's predecessor
    // return nullptr if not found
    Node* predecessor(Node* node, int key);
    // insert node into tree
    void insert(Node* node);
    void insert_fixup(Node* node);
    // replace to with from
    // assert to != nullptr && from != nullptr
    void transplant(Node* to, Node* from);
    // remove node, assert node != nullptr
    void remove(Node* node);
    void remove_fixup(Node* node);
    void inorder_walk(Node* node, const std::function<void (int, std::string)>& func);
    void left_rotate(Node* node);
    void right_rotate(Node* node);
private:
    Node* nil_;
    Node* root_;

};

#endif // BST_H_
