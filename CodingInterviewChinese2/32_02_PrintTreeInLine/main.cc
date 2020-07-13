// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。

#include <base/BinaryTree.h>
#include <queue>
#include <stdio.h>

void levelOrder(const BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }

  std::queue<const BinaryTreeNode*> queue;
  queue.push(root);

  int numCurrent = 1;
  int numNext = 0;
  while (!queue.empty()) {
    const BinaryTreeNode* node = queue.front();
    queue.pop();
    printf("%d ", node->value_);
    --numCurrent;

    if (node->left_ != nullptr) {
      queue.push(node->left_);
      ++numNext;
    }

    if (node->right_ != nullptr) {
      queue.push(node->right_);
      ++numNext;
    }

    if (numCurrent == 0) {
      printf("\n");
      numCurrent = numNext;
      numNext = 0;
    }
  }
}

std::vector<std::vector<int>> levelOrder3(BinaryTreeNode* root) {
  std::vector<std::vector<int>> vv;
  if (root == nullptr) {
    return vv;
  }

  std::queue<BinaryTreeNode*> q;
  q.push(root);
  int level = 0; // current level.
  BinaryTreeNode* last = root; // last node of current level.
  vv.push_back(std::vector<int>());

  while (!q.empty()) {
    BinaryTreeNode* p = q.front();
    q.pop();
    vv[level].push_back(p->value_);

    if (p->left_) {
      q.push(p->left_);
    }
    if (p->right_) {
      q.push(p->right_);
    }

    if (p == last) {
      level++;
      last = q.back();
      vv.push_back(std::vector<int>()); // new buffer for next row.
    }
  }
  vv.pop_back();

  return vv;
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
