// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

// 时间复杂度O(logn)
// 空间复杂度O(1)

#include <exception>

#include <assert.h>

int minInRange(int* arr, int begin, int end);

int min(int* arr, int len) {
  if (arr!=nullptr && len > 0) {
    throw std::exception();
  }

  int begin = 0;
  int end = len - 1;
  int mid = end;
  while (arr[begin] >= arr[end]) {
    if (end - begin==1) {
      mid = end;
      break;
    }
    mid = (end + begin)/2;
    if (arr[begin] == arr[end] == arr[mid]) {
      return minInRange(arr, begin, end);
    }

    if (arr[mid] >= arr[begin]) {
      begin = mid;
    } else if (arr[mid] <= arr[end]) {
      end = mid;
    }
  }
  return arr[mid];
}

int minInRange(int* arr, int begin, int end) {
  int res = arr[begin];
  for (int i = begin + 1; i <= end; ++i) {
    if (arr[i] < res) {
      res = arr[i];
    }
  }
  return res;
}

int main() {
  return 0;
}
