// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。

#include <base/BinaryTree.h>

void treeToDoublyList(BinaryTreeNode* root, BinaryTreeNode** last) {
  if (root == nullptr) {
    return;
  }

  if (root->left_ != nullptr) {
    treeToDoublyList(root->left_, last);
  }

  root->left_ = *last;
  if (*last != nullptr) {
    (*last)->right_ = root;
  }
  *last = root;

  if (root->right_ != nullptr) {
    treeToDoublyList(root->right_, last);
  }
}

BinaryTreeNode* treeToDoublyList(BinaryTreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }
  BinaryTreeNode** last = nullptr;
  treeToDoublyList(root, last);
  BinaryTreeNode* head = *last;
  while (head->left_ != nullptr) {
    head = head->left_;
  }
  return head;
}

class Solution {
 public:
  BinaryTreeNode* treeToDoublyList(BinaryTreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    BinaryTreeNode* head, * tail;
    treeToDoublyList(root, head, tail);
    head->left_ = tail;
    tail->right_ = head;
    return head;
  }

  void treeToDoublyList(BinaryTreeNode* r,
                        BinaryTreeNode*& head,
                        BinaryTreeNode*& tail) {
    if (r == nullptr) {
      return;
    }

    BinaryTreeNode* lhead = nullptr;
    BinaryTreeNode* ltail = nullptr;
    if (r->left_ != nullptr) {
      treeToDoublyList(r->left_, lhead, ltail);
      head = lhead;

      r->left_ = ltail;
      ltail->right_ = r;
    } else {
      head = r;
    }

    BinaryTreeNode* rhead = nullptr;
    BinaryTreeNode* rtail = nullptr;
    if (r->right_ != nullptr) {
      treeToDoublyList(r->right_, rhead, rtail);
      tail = rtail;

      r->right_ = rhead;
      rhead->left_ = r;
    } else {
      tail = r;
    }
  }
};

class Solution2 {
 public:
  BinaryTreeNode* treeToDoublyList(BinaryTreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    BinaryTreeNode* head, * tail;
    treeToDoublyList(root, &head, &tail);
    head->left_ = tail;
    tail->right_ = head;
    return head;
  }

  void treeToDoublyList(BinaryTreeNode* r,
                        BinaryTreeNode** head,
                        BinaryTreeNode** tail)
  {
    if (r == nullptr) {
      return;
    }

    BinaryTreeNode* lhead = nullptr;
    BinaryTreeNode* ltail = nullptr;
    if (r->left_ != nullptr) {
      treeToDoublyList(r->left_, &lhead, &ltail);
      *head = lhead;

      r->left_ = ltail;
      ltail->right_ = r;
    }
    else {
      *head = r;
    }

    BinaryTreeNode* rhead = nullptr;
    BinaryTreeNode* rtail = nullptr;
    if (r->right_ != nullptr) {
      treeToDoublyList(r->right_, &rhead, &rtail);
      *tail = rtail;

      r->right_ = rhead;
      rhead->left_ = r;
    }
    else {
      *tail = r;
    }
  }
};

int main() {
  return 0;
}
