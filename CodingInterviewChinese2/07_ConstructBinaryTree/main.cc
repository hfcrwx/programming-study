// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
// {1, 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，
// 则重建出图2.6所示的二叉树并输出它的头结点。

//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8

#include <base/BinaryTree.h>
#include <assert.h>

BinaryTreeNode* construct(int* preorder, int* inorder, int len) {
  assert(preorder!=nullptr && inorder!=nullptr && len > 0);
  int rootValue = preorder[0];
  BinaryTreeNode* root = new BinaryTreeNode();
  root->value_ = rootValue;
  root->left_ = nullptr;
  root->right_ = nullptr;
  if (len==1) {
    assert(inorder[0]==rootValue);
    return root;
  }
  int leftLen = 0;
  for (; *(inorder + leftLen)!=rootValue; ++leftLen) {
  }
  assert(leftLen < len);
  if (leftLen > 0) {
    root->left_ = construct(preorder + 1, inorder, leftLen);
  }
  if (len - 1 - leftLen > 0) {
    root->right_ = construct(preorder + 1 + leftLen, inorder + leftLen + 1, len - 1 - leftLen);
  }
  return root;
}

int main() {
  int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
  int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
  BinaryTreeNode* res = construct(preorder, inorder, sizeof(preorder)/sizeof(preorder[0]));
  return 0;
}
