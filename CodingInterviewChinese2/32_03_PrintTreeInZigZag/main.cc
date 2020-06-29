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
  int numCurrent = 1;
  int numNext = 0;

  while (!stacks[current].empty()) {
    const BinaryTreeNode* node = stacks[current].top();
    stacks[current].pop();
    printf("%d ", node->value_);
    --numCurrent;

    if (current == 0) {
      if (node->left_ != nullptr) {
        stacks[next].push(node->left_);
        ++numNext;
      }
      if (node->right_ != nullptr) {
        stacks[next].push(node->right_);
        ++numNext;
      }
    } else {
      if (node->right_ != nullptr) {
        stacks[next].push(node->right_);
        ++numNext;
      }
      if (node->left_ != nullptr) {
        stacks[next].push(node->left_);
        ++numNext;
      }
    }

    if (numCurrent == 0) {
      printf("\n");
      numCurrent = numNext;
      numNext = 0;

      current = 1 - next;
      next = 1- current;
    }
  }
}

int main() {
  return 0;
}
