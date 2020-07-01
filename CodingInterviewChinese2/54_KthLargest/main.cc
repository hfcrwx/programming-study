// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中第k大的结点。

#include <base/BinaryTree.h>
#include <inttypes.h>

const BinaryTreeNode* kthLargest(const BinaryTreeNode* root, uint32_t k) {
  if (root == nullptr || k == 0) {
    return nullptr;
  }

  const BinaryTreeNode* target = nullptr;

  if (root->right_ != nullptr) {
    target = kthLargest(root->right_, k);
  }
  if (target == nullptr) {
    --k;
    if (k == 0) {
      target = root;
    }
  }
  if (target == nullptr && root->left_ != nullptr) {
    target = kthLargest(root->left_, k);
  }

  return target;
}

int main() {
  return 0;
}
