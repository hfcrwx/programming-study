// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如，输入排序数组{1, 2, 3, 3, 3, 3, 4,
// 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

#include <assert.h>

int binarySearch(const int* nums, int low, int high, int target) {
  while (low <= high) {
    int mid = (low + high)/2;
    if (nums[mid] < target) {
      low = mid + 1;
    } else if (nums[mid] > target) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int searchRange(const int* nums, int size, int target) {
  assert(nums != nullptr && size > 0);
  int pos = binarySearch(nums, 0, size - 1, target);
  if (pos == -1) {
    return 0;
  }

//  int low;
//  int l = pos;
//  do {
//    low = l;
//    l = binarySearch(nums, 0, low-1, target);
//  } while (l > -1);

  int low = pos;
  int l;
  while ((l = binarySearch(nums, 0, low - 1, target)) > -1) {
    low = l;
  }

  int high = pos;
  int h;
  while ((h = binarySearch(nums, high + 1, size - 1, target)) > -1) {
    high = h;
  }

  return high - low + 1;
}

int main() {
  return 0;
}
