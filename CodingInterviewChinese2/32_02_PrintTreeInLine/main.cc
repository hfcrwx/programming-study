// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。

#include <base/BinaryTree.h>
#include <queue>
#include <stdio.h>

void levelOrder(BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }

  std::queue<BinaryTreeNode*> queue;
  queue.push(root);

  int numToBePrinted = 1;
  int numNextLine = 0;
  while (!queue.empty()) {
    BinaryTreeNode* node = queue.front();
    queue.pop();
    printf("%d ", node->value_);
    --numToBePrinted;

    if (node->left_ != nullptr) {
      queue.push(node->left_);
      ++numNextLine;
    }

    if (node->right_ != nullptr) {
      queue.push(node->right_);
      ++numNextLine;
    }

    if (numToBePrinted == 0) {
      printf("\n");
      numToBePrinted = numNextLine;
      numNextLine = 0;
    }
  }
}

int main() {
  BinaryTreeNode* node8 = CreateBinaryTreeNode(8);
  BinaryTreeNode* node6 = CreateBinaryTreeNode(6);
  BinaryTreeNode* node10 = CreateBinaryTreeNode(10);
  BinaryTreeNode* node5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* node7 = CreateBinaryTreeNode(7);
  BinaryTreeNode* node9 = CreateBinaryTreeNode(9);
  BinaryTreeNode* node11 = CreateBinaryTreeNode(11);

  ConnectTreeNodes(node8, node6, node10);
  ConnectTreeNodes(node6, node5, node7);
  ConnectTreeNodes(node10, node9, node11);

  levelOrder(node8);
  printf("\n");

  DestroyTree(node8);
  return 0;
}
