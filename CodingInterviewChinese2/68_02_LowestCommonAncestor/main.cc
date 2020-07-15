// 面试题68（二）：树中两个结点的最低公共祖先
// 题目：给定一个二叉树, 找到该树中两个指定结点的最近公共祖先。

#include <base/BinaryTree.h>

BinaryTreeNode* lowestCommonAncestor(BinaryTreeNode* root,
                                     BinaryTreeNode* p,
                                     BinaryTreeNode* q) {
  if (root == nullptr)
    return nullptr;
  if (p == root || q == root)
    return root; // 同时查找两个结点

  BinaryTreeNode* left = lowestCommonAncestor(root->left_, p, q);
  BinaryTreeNode* right = lowestCommonAncestor(root->right_, p, q);
  //如果left为空，说明这两个节点在root结点的右子树上，我们只需要返回右子树查找的结果即可
  if (left == nullptr)
    return right;
  //同上
  if (right == nullptr)
    return left;
  //如果left和right都不为空，说明这两个节点一个在root的左子树上一个在root的右子树上，
  //我们只需要返回root结点即可。
  return root; //ok!后续的遍历实际已经没有意义
}

int main() {
  return 0;
}
