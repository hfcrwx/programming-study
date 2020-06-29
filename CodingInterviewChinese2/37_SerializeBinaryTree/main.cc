// 面试题37：序列化二叉树
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。

#include <base/BinaryTree.h>
#include <iostream>

void serialize(const BinaryTreeNode* root, std::ostream& os) {
  if (root = nullptr) {
    os << "$,";
    return;
  }

  os << root->value_ << ',';
  serialize(root->left_, os);
  serialize(root->right_, os);
}

bool readStream(std::istream& is, int* num) {
  if (is.eof()) {
    return false;
  }

  char buf[32] = {0};
  int i = 0;
  while (!is.eof()) {
    is >> buf[i];
    if (buf[i] == ',') {
      buf[i] = '\0';
      break;
    }
    ++i;
  }

  if (i > 0 && buf[0] != '$') {
    *num = atoi(buf);
    return true;
  }

  return false;
}

void deserialize(BinaryTreeNode** root, std::istream& is) {
  int num;
  if (readStream(is, &num)) {
    *root = new BinaryTreeNode;
    (*root)->value_ = num;
    (*root)->left_ = nullptr;
    (*root)->right_ = nullptr;

    deserialize(&((*root)->left_), is);
    deserialize(&((*root)->right_), is);
  }
}

int main() {
  return 0;
}
