// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>

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
 
 public:
    Node* root;
    BST():root(nullptr) {}
    int search(T data) {
        return searchNode(root, data);
    }
    int searchNode(Node* root, T data) {
        if (root == nullptr)
            return 0;
        if (data < root->data)
            return searchNode(root->leftChild, data);
        if (root->data == data)
            return root->freq;
        else
            return searchNode(root->rightChild, data);
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
    void add(T data) {
        root = insertWord(root, data);
    }
    Node* insertWord(Node* node, const T& data) {
       if (!node) {
          node = new Node(data);
     } else if (node->data == data) {
        ++node->freq;
    } else if (data < node->data) {
        insertWord(node->leftChild, data);
    } else {
        insertWord(node->rightChild, data);
    }
    return node;
}
};
#endif  // INCLUDE_BST_H_
