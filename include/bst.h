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
        explicit Node(T data): freq(1), data(data), leftChild(nullptr), rightChild(nullptr) {}
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
        root = insertWords(root, data);
    }
    Node* insertWords(Node* node, T words) {
       if (!node) {
          node = new Node(words);
       } else if (node->data == words) {
          node->freq++;
       } else if (words < node->data) {
          node->leftChild = insertWords(node->leftChild, words);
       } else if (node-> < words) {
          node->rightChild = insertWords(node->rightChild, words);
       }
       return node;
    }
};
#endif  // INCLUDE_BST_H_
