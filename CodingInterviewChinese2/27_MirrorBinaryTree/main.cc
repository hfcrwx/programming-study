// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。

#include <base/BinaryTree.h>
#include <stack>

void mirrorBinaryTree(BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }
  if (root->left_ == nullptr && root->right_ == nullptr) {
    return;
  }

  BinaryTreeNode* tmp = root->left_;
  root->left_ = root->right_;
  root->right_ = tmp;

  if (root->left_ != nullptr) {
    mirrorBinaryTree(root->left_);
  }
  if (root->right_ != nullptr) {
    mirrorBinaryTree(root->right_);
  }
}

void mirrorBinaryTree2(BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }
  if (root->left_ == nullptr && root->right_ == nullptr) {
    return;
  }
  std::stack<BinaryTreeNode*> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    BinaryTreeNode* node = nodes.top();
    nodes.pop();

    BinaryTreeNode* tmp = node->left_;
    node->left_ = node->right_;
    node->right_ = tmp;

    if (node->right_ != nullptr) {
      nodes.push(node->right_);
    }

    if (node->left_ != nullptr) {
      nodes.push(node->left_);
    }
  }
}

int main() {
  return 0;
}