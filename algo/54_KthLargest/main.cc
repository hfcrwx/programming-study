// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中第k大的结点。

#include <base/BinaryTree.h>
#include <assert.h>

const BinaryTreeNode* kthLargestCore(const BinaryTreeNode* root, int& k) {
  if (root == nullptr || k <= 0) {
    return nullptr;
  }

  const BinaryTreeNode* target = kthLargestCore(root->right_, k);
  if (target != nullptr) {
    return target;
  }

  --k;
  if (k == 0) {
    return root;
  }

  return kthLargestCore(root->left_, k);
}

int kthLargest(const BinaryTreeNode* root, int k) {
  assert(root != nullptr && k > 0);
  return kthLargestCore(root, k)->value_;
}

int main() {
  return 0;
}
