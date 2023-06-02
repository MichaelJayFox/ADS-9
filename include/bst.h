// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template<typename T>
class BST {
 private:
    struct Node {
        T data;
        int freq;
        Node* leftChild;
        Node* rightChild;
        explicit Node(const T& d, int f = 1, Node* l = nullptr, Node* r = nullptr)
            : data(d), freq(f), leftChild(l), rightChild(r) {}
    };
    void insert(Node*&, const T&);
 public:
    Node* root;
    BST():root(nullptr) {}
    int search (T value) {
        return searchNode(root, value);
    }
    int searchNode(Node* root, T value) {
        if (root == nullptr)
            return 0;
        if (value < root->value)
            return searchNode(root->leftChild, value);
        if (root->value == value)
            return root->freq;
        else
            return searchNode(root->rightChild, value);
    }
    int depth() {
        return getDepth(root) - 1;
    }
    int getDepth(Node* root) {
        if (root)
            return std::max(getDepth(root->leftChild), getDepth(root->rightChild)) + 1;
        else
            return 0;
    }
    void add(T value) {
        root = insertWords(root, value);
    }
    Node* insertWord(Node*& node, const T& data)
    {
     if (!node) {
         node = new Node(data); 
     } else if (node->data == data) {
        ++node->freq;
    } else if (data < node->data) {
        insert(node->leftChild, data);
    } else {
        insert(node->rightChild, data);
    }       
};   
#endif  // INCLUDE_BST_H_
