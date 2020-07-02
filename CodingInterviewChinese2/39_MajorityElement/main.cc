// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1
// , 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

#include <assert.h>
#include <stddef.h>

int majorityElement(const int* nums, size_t len) {
  assert(nums != nullptr && len != 0);

  int majority;
  size_t count = 0;
  for (size_t i = 0; i < len; ++i) {
    if (count == 0) {
      majority = nums[i];
      ++count;
    } else {
      nums[i] == majority ? ++count : --count;
      if (count > (len >> 1u)) {
        return majority;
      }
    }
  }

  return majority;
}

int main() {
  return 0;
}
