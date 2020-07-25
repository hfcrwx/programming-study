// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个
// 数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的
// 数组{2, 3, 1, 0, 2, 5, 3}，那么对应的输出是重复的数字2或者3。

// {2, 3, 1, 0, 2, 5, 3}
// {1, 3, 2, 0, 2, 5, 3}
// {3, 1, 2, 0, 2, 5, 3}
// {0, 1, 2, 3, 2, 5, 3}
// {0, 1, 2, 3, [2], 5, 3}

// 时间复杂度O(n)
// 空间复杂度O(1)

#include <algorithm>
#include <stddef.h>

int findRepeatNumber(int* nums, size_t len) {
  if (nums == nullptr || len < 2) {
    return -1;
  }

  for (int i = 0; i < len; ++i) {
    if (nums[i] < 0 || nums[i] >= len) {
      return -1;
    }
  }

  for (int i = 0; i < len; ++i) {
    while (nums[i] != i) {
      if (nums[i] == nums[nums[i]]) {
        return nums[i];
      }
      std::swap(nums[i], nums[nums[i]]);
//      int tmp = nums[i];
//      nums[i] = nums[tmp];
//      nums[tmp] = tmp;
    }
  }

  return -1;
}

int main() {
  return 0;
}
