// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历的下一个结点？树中的结点除了有两个分别指向
// 左、右子结点的指针，还有一个指向父结点的指针。

//             6
//      2         8
//   1     4    7    9
//       3   5

#include "BinaryTreeEx.h"
#include <assert.h>

BinaryTreeNodeEx* getNext(BinaryTreeNodeEx* node) {
  if (node == nullptr) {
    return nullptr;
  }

  BinaryTreeNodeEx* next;
  if (node->right_ != nullptr) {
    BinaryTreeNodeEx* tmp = node->right_;
    while (tmp->left_ != nullptr) {
      tmp = tmp->left_;
    }
    next = tmp;
  } else if (node->parent_ != nullptr) {
    if (node == node->parent_->left_) {
      next = node->parent_;
    } else {
      BinaryTreeNodeEx* tmp = node;
      while (tmp->parent_ != nullptr && tmp->parent_->right_ == tmp) {
        tmp = tmp->parent_;
      }
      next = tmp->parent_;
    }
  } else {
    next = nullptr;
  }

  return next;
}

int main() {
  BinaryTreeNodeEx* node1 = createBinaryTreeNodeEx(1);
  BinaryTreeNodeEx* node2 = createBinaryTreeNodeEx(2);
  BinaryTreeNodeEx* node3 = createBinaryTreeNodeEx(3);
  BinaryTreeNodeEx* node4 = createBinaryTreeNodeEx(4);
  BinaryTreeNodeEx* node5 = createBinaryTreeNodeEx(5);
  BinaryTreeNodeEx* node6 = createBinaryTreeNodeEx(6);
  BinaryTreeNodeEx* node7 = createBinaryTreeNodeEx(7);
  BinaryTreeNodeEx* node8 = createBinaryTreeNodeEx(8);
  BinaryTreeNodeEx* node9 = createBinaryTreeNodeEx(9);
  connectNodes(node6, node2, node8);
  connectNodes(node2, node1, node4);
  connectNodes(node8, node7, node9);
  connectNodes(node4, node3, node5);
  BinaryTreeNodeEx* r1 = getNext(node1);
  BinaryTreeNodeEx* r2 = getNext(node2);
  BinaryTreeNodeEx* r3 = getNext(node3);
  BinaryTreeNodeEx* r4 = getNext(node4);
  BinaryTreeNodeEx* r5 = getNext(node5);
  BinaryTreeNodeEx* r6 = getNext(node6);
  BinaryTreeNodeEx* r7 = getNext(node7);
  BinaryTreeNodeEx* r8 = getNext(node8);
  BinaryTreeNodeEx* r9 = getNext(node9);

  assert(r1 == node2);
  assert(r2 == node3);
  assert(r3 == node4);
  assert(r4 == node5);
  assert(r5 == node6);
  assert(r6 == node7);
  assert(r7 == node8);
  assert(r8 == node9);
  assert(r9 == nullptr);

  return 0;
}
