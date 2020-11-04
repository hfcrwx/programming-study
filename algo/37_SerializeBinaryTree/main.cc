// 面试题37：序列化二叉树
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。

#include <base/BinaryTree.h>
#include <sstream>
#include <string>

void serialize(const BinaryTreeNode* root, std::ostringstream& os) {
  if (root == nullptr) {
    os << "# ";
    return;
  }

  os << root->value_ << ' ';
  serialize(root->left_, os);
  serialize(root->right_, os);
}

std::string serialize(const BinaryTreeNode* root) {
  std::ostringstream os;
  serialize(root, os);
  return os.str();
}

BinaryTreeNode* deserialize(std::istringstream& is) {
  std::string val;
  is >> val;

  if (val == "#"/* || val.empty()*/) {
    return nullptr;
  }

  BinaryTreeNode* root = new BinaryTreeNode;
  root->value_ = stoi(val);
  root->left_ = deserialize(is);
  root->right_ = deserialize(is);

  return root;
}

BinaryTreeNode* deserialize(const std::string& data) {
  std::istringstream is(data);
  return deserialize(is);
}

int main(int argc, char** argv) {
  std::string s = "1 2 3 # # 4 5 # # # #";
  if (argc > 1) {
    s = argv[1];
  }
  std::string str = serialize(deserialize(s));

  return 0;
}
