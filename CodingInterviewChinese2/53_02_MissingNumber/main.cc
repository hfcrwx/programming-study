// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0~n-1之内。在范围
// 0~n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

#include <assert.h>

int missingNumber(const int* nums, int size) {
  assert(nums != nullptr && size > 0);

  int low = 0;
  int high = size - 1;
  int mid;
  while (low <= high) {
    mid = (low + high)/2;
    if (nums[mid] == mid) {
      low = mid + 1;
    } else {
      if (mid == 0 || nums[mid - 1] == mid - 1) {
        return mid;
      } else {
        high = mid - 1;
      }
    }
  }
  if (low == size) {
    return size;
  }

  return -1;
}

int main() {
  return 0;
}
