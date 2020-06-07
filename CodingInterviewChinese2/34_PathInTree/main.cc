// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#include <base/BinaryTree.h>
#include <vector>
#include <stdio.h>

void findPath(const BinaryTreeNode* root, int expectedSum, int& currentSum, std::vector<int>& path);

void findPath(const BinaryTreeNode* root, int expectedSum) {
  if (root==nullptr) {
    return;
  }
  int currentSum = 0;
  std::vector<int> path;
  findPath(root, expectedSum, currentSum, path);
}

void findPath(const BinaryTreeNode* root, int expectedSum, int& currentSum, std::vector<int>& path) {
  currentSum += root->value_;
  path.push_back(root->value_);
  if (currentSum==expectedSum && root->left_==nullptr && root->right_==nullptr) {
    for (std::vector<int>::iterator it = path.begin(); it != path.end(); ++it) {
      printf("%d, ", *it);
    }
    printf("\n");
  }

  if (root->left_!=nullptr) {
    findPath(root->left_, expectedSum, currentSum, path);
  }
  if (root->right_!=nullptr) {
    findPath(root->right_, expectedSum, currentSum, path);
  }

  currentSum -= root->value_;
  path.pop_back();
}

int main() {
  return 0;
}
