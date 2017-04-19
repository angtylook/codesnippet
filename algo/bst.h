#ifndef BST_H_
#define BST_H_

#include <string>

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
public:
    bool empty();
    bool contain(int key);
    bool getValue(int key, std::string& value);
    bool minimum(std::string& value);
    bool maximum(std::string& value);

    bool insert(int key, const std::string& value);
    void insert_or_assign(int key, const std::string& value);
    bool remove(int key);
private:
    struct Node {
        int key;
        std::string value;
        Node* parent;
        Node* left;
        Node* right;
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
    Node* insert(Node* node);
private:
    Node* root_;
};

#endif // BST_H_