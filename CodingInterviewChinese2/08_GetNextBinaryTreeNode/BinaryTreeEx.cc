//
// Created by root on 2020/6/2.
//

#include "BinaryTreeEx.h"

BinaryTreeNodeEx* createBinaryTreeNodeEx(int value) {
  BinaryTreeNodeEx* node = new BinaryTreeNodeEx();
  node->value_ = value;
  node->left_ = nullptr;
  node->right_ = nullptr;
  node->parent_ = nullptr;
  return node;
}

void connectNodes(BinaryTreeNodeEx* parent, BinaryTreeNodeEx* left, BinaryTreeNodeEx* right) {
  if (parent!=nullptr) {
    parent->left_ = left;
    parent->right_ = right;
    if (left!=nullptr) {
      left->parent_ = parent;
    }
    if (right!=nullptr) {
      right->parent_ = parent;
    }
  }
}

void destroy(BinaryTreeNodeEx* root) {
  if (root!=nullptr) {
    BinaryTreeNodeEx* left = root->left_;
    BinaryTreeNodeEx* right = root->right_;
    delete root;
    root = nullptr;
    destroy(left);
    destroy(right);
  }
}
