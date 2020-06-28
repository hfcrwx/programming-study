// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。

//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7

#include <base/BinaryTree.h>

bool doesTree1HasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2);

// find root2
bool isSubstructure(BinaryTreeNode* root1, BinaryTreeNode* root2) {
  bool result = false;
  if (root1 != nullptr && root2 != nullptr) {
    if (root1->value_ == root2->value_) {
      result = doesTree1HasTree2(root1, root2);
    }
    if (!result) {
      result = isSubstructure(root1->left_, root2);
    }
    if (!result) {
      result = isSubstructure(root1->right_, root2);
    }
  }

  return result;
}

// same root
bool doesTree1HasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2) {
  if (root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr) {
    return false;
  }

  return root1->value_ == root2->value_
      && doesTree1HasTree2(root1->left_, root2->left_)
      && doesTree1HasTree2(root1->right_, root2->right_);
}

int main() {
  return 0;
}
