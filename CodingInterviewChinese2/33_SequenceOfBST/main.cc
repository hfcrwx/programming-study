// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

#include <stddef.h>

bool verifySequenceOfBST(const int* seq, size_t len) {
  if (seq==nullptr || len==0) {
    return false;
  }
  int root = seq[len-1];
  int i = 0;
  for (; i<len-1; ++i) {
    if (seq[i]>root) {
      break;
    }
  }
  for (int j=i+1; j<len-1; ++j) {
    if (seq[j]<root) {
      return false;
    }
  }

  bool left = true;
  if (i>0) {
    left = verifySequenceOfBST(seq, i);
  }
  bool right = true;
  if (i<len-1) {
    right = verifySequenceOfBST(seq+i, len-1-i);
  }
  return left&&right;
}

int main() {
  return 0;
}
