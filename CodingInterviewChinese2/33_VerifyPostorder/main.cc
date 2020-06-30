// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

#include <stddef.h>

bool verifyPostorder(const int* seq, size_t len) {
  if (seq == nullptr || len == 0) {
    return false;
  }

  int root = seq[len - 1];
  size_t i = 0;
  for (; i < len - 1; ++i) {
    if (seq[i] > root) {
      break;
    }
  }

  for (size_t j = i + 1; j < len - 1; ++j) {
    if (seq[j] < root) {
      return false;
    }
  }

  bool left = true;
  if (i > 0) {
    left = verifyPostorder(seq, i);
  }
  if (!left) {
    return false;
  }

  bool right = true;
  if (i < len - 1) {
    right = verifyPostorder(seq + i, len - 1 - i);
  }
  if (!right) {
    return false;
  }

  return true;
}

int main() {
  return 0;
}
