// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template<typename T>

class BST {
 private:
    struct Node {
        Node* left;
        Node* right;
        T val;
        int count;
    };
    Node* root;
    Node* add_Node(Node* root, T val) {
        if (!root) {
            root = new Node;
            root->val = val;
            root->count = 1;
            root->right = nullptr;
            root->left = nullptr;
        } else if (root->val > val) {
            root->left = add_Node(root->left, val);
        } else if (root->val < val) {
            root->right = add_Node(root->right, val);
        } else {
            ++root->count;
        }
        return root;
    }
    int Depth(Node* root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(Depth(root->left), Depth(root->right));
    }
    int Search(Node* root, T val) {
        int a = 0;
        if (root->val == val) {
            a = root->count;
        } else if (root->val > val) {
            a = Search(root->left, val);
        } else if (root->val < val) {
            a = Search(root->right, val);
        }
        return a;
    }

 public:
    BST():root(nullptr) {}
    void add(T val) {
        root = add_Node(root, val);
    }
    int search(T value) {
        return Search(root, value);
    }
    int depth() {
        return Depth(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
