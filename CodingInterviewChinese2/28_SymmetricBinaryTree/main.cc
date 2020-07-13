// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。
// 如果一棵二叉树和它的镜像一样，那么它是对称的。

#include <base/BinaryTree.h>

bool isSymmetric(const BinaryTreeNode* node1, const BinaryTreeNode* node2) {
  if (node1 == nullptr && node2 == nullptr) {
    return true;
  }
  if (node1 == nullptr || node2 == nullptr) {
    return false;
  }

  return node1->value_ == node2->value_
      && isSymmetric(node1->left_, node2->right_)
      && isSymmetric(node1->right_, node2->left_);
}

bool isSymmetric(const BinaryTreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  return isSymmetric(root, root);
}

int main() {
  return 0;
}
