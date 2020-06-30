// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左、右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

#include <base/BinaryTree.h>
#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>

bool isBalanced(const BinaryTreeNode* root, uint32_t* depth) {
  assert(depth != nullptr);
  
  if (root == nullptr) {
    *depth = 0;
    return true;
  }

  uint32_t left = 0;
  uint32_t right = 0;
  if (isBalanced(root->left_, &left) && isBalanced(root->right_, &right)) {
    if (abs(left, right) <= 1) {
      *depth = (left > right ? left : right) + 1;
      return true;
    }
  }

  return false;
}

bool isBalanced(const BinaryTreeNode* root) {
  uint32_t depth = 0;
  return isBalanced(root, &depth);
}

int main() {
  return 0;
}
