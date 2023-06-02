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
        Node(const T& d, int f = 1, Node* l = nullptr, Node* r = nullptr)
            : data(d), freq(f), leftChild(l), rightChild(r) {}
    };
    Node* root;
    void insert(Node*&, const T&);
    void remove(Node*&, const T&);
    void destroy(Node*&);
 public:
    BST():root(nullptr) {}
    BST(const BST&) = default;
    BST& operator=(const BST&) = delete;
    ~BST() {destroy(root);}
    void insert(const T& data) { insert(root, data); }
    void remove(const T& data) { remove(root, data); }
    int search(const T&) const;
};

template<typename T>
void BST<T>::insert(Node*& node, const T& data) {
    if (!node) node = new Node(data);
    else if (node->data == data) ++node->freq;
    else if (data < node->data) insert(node->leftChild, data);
    else {
     insert(node->rightChild, data);
    }
}

template<typename T>
void BST<T>::remove(Node*& node, const T& data) {
    if (!node) return;
    if (node->data == data) {
        if (node->freq > 1) --node->freq;
        else {
            if (!node->leftChild && !node->rightChild) {
                delete node;
                node = nullptr;
            } else if (!node->leftChild) {
                Node* tmp = node;
                node = node->rightChild;
                delete tmp;
            } else if (!node->rightChild) {
                Node* tmp = node;
                node = node->leftChild;
                delete tmp;
            } else {
                Node* minNode = node->rightChild;
                while (minNode->leftChild) minNode = minNode->leftChild;
                node->data = minNode->data;
                node->freq = minNode->freq;
                remove(node->rightChild, minNode->data);
            }
        }
    } else if (data < node->data) remove(node->leftChild, data);
    else remove(node->rightChild, data);
}

template<typename T>
int BST<T>::search(const T& data) const {
    Node* current = root;
    while (current) {
        if (current->data == data) return current->freq;
        else if (data < current->data) current = current->leftChild;
        else current = current->rightChild;
    }
    return 0;
}

template<typename T>
void BST<T>::destroy(Node*& node) {
    if (node) {
        destroy(node->leftChild);
        destroy(node->rightChild);
        delete node;
        node = nullptr;
    }
}

#endif  // INCLUDE_BST_H_
