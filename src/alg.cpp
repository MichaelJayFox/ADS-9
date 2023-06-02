// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            std::string lowercaseWord;
            for (char c : word) lowercaseWord += tolower(c);
            tree.insert(lowercaseWord);
        }
        file.close();
    }
    return tree;
};
