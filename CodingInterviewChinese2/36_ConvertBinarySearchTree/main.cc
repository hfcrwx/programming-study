// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。

#include <base/BinaryTree.h>

void convertToListCore(BinaryTreeNode* root, BinaryTreeNode** last) {
  if (root==nullptr) {
    return;
  }

  if (root->left_!=nullptr) {
    convertToListCore(root->left_, last);
  }

  root->left_ = *last;
  if (*last!=nullptr) {
    (*last)->right_ = root;
  }
  *last = root;

  if (root->right_!=nullptr) {
    convertToListCore(root->right_, last);
  }
}

BinaryTreeNode* convertToList(BinaryTreeNode* root) {
  if (root==nullptr) {
    return nullptr;
  }
  BinaryTreeNode** last = nullptr;
  convertToListCore(root, last);
  BinaryTreeNode* head = *last;
  while (head->left_!=nullptr) {
    head = head->left_;
  }
  return head;
}

int main() {
  return 0;
}
