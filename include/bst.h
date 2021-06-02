// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <cassert>
template < typename T >
class BST {
 public:
  struct Node {
  T value;
  int c;
  Node* left;
  Node* right;
  };
BST(): root(nullptr) {}
~BST() {}
void add(T value) {
  root = addNode(root, value);
}
int depth() {
  return depthTree(root);
}
int search(T value) {
  return searchNode(root, value);
}

 private:
Node* root;
Node* addNode(Node* root, T value) {
        if (root == nullptr) {
            root = new Node;
            root-> value = value;
            root-> c = 1;
            root-> left = root-> right = nullptr;
        } else if (root-> value > value) {
             root-> left = addNode(root-> left, value);
        } else if (root-> value < value) {
             root-> right = addNode(root-> right, value);
        } else {
             root->c++;
        }
        return root;
}
int depthTree(Node* root) {
if (root == nullptr)
     return 0;
if ((root->left == nullptr) && (root->right == nullptr)) {
     return 0;
}
            int lh = depthTree(root->left);
            int rh = depthTree(root->right);
            return (lh > rh ? lh : rh) + 1;
}
int searchNode(Node* root, T value) {
if (root == nullptr)
    return 0;
else if (root->value > value)
    return searchNode(root->left, value);
else if (root->value < value)
    return searchNode(root->right, value);
else
    return root->c;
}
};

#endif  // INCLUDE_BST_H_
