// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
// 要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <assert.h>

void singleNumbers(const int* nums, int size, int* num1, int* num2) {
  assert(nums != nullptr && (size & 1) == 0 && size >= 4 && num1 != nullptr
             && num2 != nullptr);

  int xors = 0;
  for (int i = 0; i < size; ++i) {
    xors ^= nums[i];
  }
  assert(xors != 0);

  int pos = 0;
  while ((xors & 1) == 0/* && pos < 32*/) {
    xors >> 1;
    ++pos;
  }
//  assert(pos != 32);

  *num1 = 0;
  *num2 = 0;
  for (int i = 0; i < size; ++i) {
    if (((nums[i] >> pos) & 1) == 1) {
      *num1 ^= nums[i];
    } else {
      *num2 ^= nums[i];
    }
  }
}

int main() {
  return 0;
}
