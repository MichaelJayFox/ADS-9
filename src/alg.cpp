// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::string word;
    std::ifstream file(filename);
    if (file) {
        while (!file.eof()) {
            char words = toolower(file.get());
            if (!alpha(words)) {
            char words = tolower(file.get());
            if (!isalpha(words)) {
                if (!word.empty()) {
                    tree.add(word);
                }
                word.clear();
            } else {
                word += words;
            }
        }
    } else {
        std::cout << "Error file!" << std::endl;
    }
    file.close();
    return tree;
}
