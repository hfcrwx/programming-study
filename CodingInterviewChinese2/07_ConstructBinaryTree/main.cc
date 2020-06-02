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
