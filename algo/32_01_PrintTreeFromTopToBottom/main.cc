// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

#include <base/BinaryTree.h>
#include <queue>
#include <stdio.h>

void printInorder(BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }

  printInorder(root->left_);
  printf("%d ", root->value_);
  printInorder(root->right_);
}

void levelOrder(const BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }

  std::queue<const BinaryTreeNode*> queue;
  queue.push(root);

  while (!queue.empty()) {
    const BinaryTreeNode* node = queue.front();
    queue.pop();
    printf("%d ", node->value_);

    if (node->left_ != nullptr) {
      queue.push(node->left_);
    }

    if (node->right_ != nullptr) {
      queue.push(node->right_);
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

  printInorder(node8);
  printf("\n");
  levelOrder(node8);
  printf("\n");

  DestroyTree(node8);
  return 0;
}
