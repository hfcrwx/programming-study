// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二行按照从右到左
// 的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

#include <base/BinaryTree.h>
#include <stack>
#include <stdio.h>

void levelOrder(const BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }

  std::stack<const BinaryTreeNode*> stacks[2];
  int current = 0;
  int next = 1;
  stacks[current].push(root);

  while (!stacks[current].empty()) {
    const BinaryTreeNode* node = stacks[current].top();
    stacks[current].pop();
    printf("%d ", node->value_);

    if (current == 0) {
      if (node->left_ != nullptr) {
        stacks[next].push(node->left_);
      }
      if (node->right_ != nullptr) {
        stacks[next].push(node->right_);
      }
    } else {
      if (node->right_ != nullptr) {
        stacks[next].push(node->right_);
      }
      if (node->left_ != nullptr) {
        stacks[next].push(node->left_);
      }
    }

    if (stacks[current].empty()) {
      printf("\n");

      current = 1 - current;
      next = 1 - next;
    }
  }
}

int main() {
  return 0;
}
