// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的
// 一个旋转，输出旋转数组的最小元素。例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该
// 数组的最小值为1。

// 时间复杂度O(logn)
// 空间复杂度O(1)

#include <assert.h>
#include <stddef.h>

int findMin(const int* arr, size_t len) {
  assert(arr != nullptr && len != 0);

  size_t left = 0;
  size_t right = len - 1;

  while (left < right) {
    size_t mid = left + ((right-left) >> 1u);

    if (arr[mid] < arr[right]) {
      right = mid;
    } else if (arr[mid] > arr[right]) {
      left = mid+1;
    } else {
      --right;
    }
  }

  return arr[left];
}

int main() {
  return 0;
}
