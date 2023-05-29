// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> bst;
    std::ifstream file(filename);
    std::string str;
    while (!file.eof()) {
        char c = file.get();
        if (c >= 65 && c <= 90) {
            c += 32;
            str += c;
            continue;
        }
        if (c >= 97 && c <= 122) {
            str += c;
        } else {
            if (!str.empty()) {
                bst.add(str);
            }
            str.clear();
        }
    }
    bst.add(str);
    file.close();
    return bst;
}
