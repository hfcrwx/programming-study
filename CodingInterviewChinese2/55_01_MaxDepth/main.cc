// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树
// 的一条路径，最长路径的长度为树的深度。

#include <base/BinaryTree.h>

int maxDepth(const BinaryTreeNode* root) {
  if (root == nullptr) {
    return 0;
  }

  int left = maxDepth(root->left_);
  int right =  maxDepth(root->right_);
  return (left > right ? left : right) + 1;
}

int main() {
  return 0;
}
