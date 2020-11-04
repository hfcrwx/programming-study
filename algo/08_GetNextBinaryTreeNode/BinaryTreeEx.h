//
// Created by root on 2020/6/2.
//

#ifndef CODINGINTERVIEWCHINESE2_BINARYTREEEX_H_
#define CODINGINTERVIEWCHINESE2_BINARYTREEEX_H_

struct BinaryTreeNodeEx {
  int value_;
  BinaryTreeNodeEx* left_;
  BinaryTreeNodeEx* right_;
  BinaryTreeNodeEx* parent_;
};

BinaryTreeNodeEx* createBinaryTreeNodeEx(int value);

void connectNodes(BinaryTreeNodeEx* parent, BinaryTreeNodeEx* left, BinaryTreeNodeEx* right);

void destroy(BinaryTreeNodeEx* root);

#endif //CODINGINTERVIEWCHINESE2_BINARYTREEEX_H_
