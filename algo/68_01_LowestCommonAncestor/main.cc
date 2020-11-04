// 面试题68（一）：树中两个结点的最低公共祖先
// 题目：给定一个二叉搜索树, 找到该树中两个指定结点的最近公共祖先。

#include <base/BinaryTree.h>
#include <assert.h>

BinaryTreeNode* lowestCommonAncestor(BinaryTreeNode* root,
                                     BinaryTreeNode* p,
                                     BinaryTreeNode* q) {
  assert(p != nullptr && q != nullptr);

  if (root == nullptr) {
    return nullptr;
  }
  if (root->value_ < p->value_ && root->value_ < q->value_) {
    return lowestCommonAncestor(root->right_, p, q);
  }
  if (root->value_ > p->value_ && root->value_ > q->value_) {
    return lowestCommonAncestor(root->left_, p, q);
  }

  return root;
}

class Solution {
 public:
  BinaryTreeNode* lowestCommonAncestor(BinaryTreeNode* root,
                                       BinaryTreeNode* p,
                                       BinaryTreeNode* q) {
    assert(p != nullptr && q != nullptr);

    while (root != nullptr) {
      if (root->value_ < p->value_ && root->value_ < q->value_) {
        root = root->right_;
      } else if (root->value_ > p->value_ && root->value_ > q->value_) {
        root = root->left_;
      } else {
        return root;
      }
    }

    return nullptr;
  }
};

int main() {
  return 0;
}
