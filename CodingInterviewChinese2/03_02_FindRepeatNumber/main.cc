// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至少有一个数字是重复的。请找
// 出数组中任意一个重复的数字，但不能修改输入的数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3,
// 2, 6, 7}，那么对应的输出是重复的数字2或者3。

// {2, 3, 5, 4, 3, 2, 6, 7}
// 1-4: 5; 5-7: 3
// 1-2: 2; 3-4: 3
// 3: 2; 4: 1

// 时间复杂度O(nlogn)
// 空间复杂度O(1)

#include <inttypes.h>

uint32_t countInRange(const uint32_t* arr,
                      uint32_t len,
                      uint32_t begin,
                      uint32_t end);
uint32_t findRepeatNumber(const uint32_t* arr, uint32_t len) {
  if (arr == nullptr || len < 2) {
    return 0;
  }

  uint32_t begin = 1; //1
  uint32_t end = len - 1; //n
  while (begin < end) {
    uint32_t middle = begin + ((end - begin) >> 1u);
    uint32_t count = countInRange(arr, len, begin, middle);

    if (count > middle - begin + 1) {
      end = middle;
    } else {
      begin = middle + 1;
    }
  }

  return begin;
}

uint32_t countInRange(const uint32_t* arr,
                      uint32_t len,
                      uint32_t begin,
                      uint32_t end) {
  uint32_t count = 0;
  for (int i = 0; i < len; ++i) {
    if (arr[i] >= begin && arr[i] <= end) {
      ++count;
    }
  }
  return count;
}

int main() {
  return 0;
}
