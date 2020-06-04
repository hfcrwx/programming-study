// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

void reorderArray(int* arr, int len) {
  if (arr==nullptr && len <= 0) {
    return;
  }
  int* begin = arr;
  int* end = arr + len - 1;
  while (begin < end) {
    while (begin < end && (*begin & 1)==1) {
      ++begin;
    }
    while (begin < end && (*end & 1)==0) {
      --end;
    }
    if (begin < end) {
      int tmp = *begin;
      *begin = *end;
      *end = tmp;
    }
  }
}

int main() {
  return 0;
}
