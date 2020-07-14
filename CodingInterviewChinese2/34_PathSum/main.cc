// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。从树的根结点开始往
// 下一直到叶结点所经过的结点形成一条路径。

#include <base/BinaryTree.h>
#include <vector>

void pathSum(const BinaryTreeNode* root,
             int expectedSum,
             int currentSum,
             std::vector<int>& path,
             std::vector<std::vector<int>>& result);

std::vector<std::vector<int>> pathSum(const BinaryTreeNode* root,
                                      int expectedSum) {
  std::vector<int> path;
  std::vector<std::vector<int>> result;
  pathSum(root, expectedSum, 0, path, result);

  return result;
}

void pathSum(const BinaryTreeNode* root,
             int expectedSum,
             int currentSum,
             std::vector<int>& path,
             std::vector<std::vector<int>>& result) {
  if (root == nullptr) {
    return;
  }

  currentSum += root->value_;
  path.push_back(root->value_);

  if (currentSum == expectedSum && root->left_ == nullptr
      && root->right_ == nullptr) {
    result.push_back(path);
  }

  pathSum(root->left_, expectedSum, currentSum, path, result);
  pathSum(root->right_, expectedSum, currentSum, path, result);

  path.pop_back();
}

int main() {
  return 0;
}
