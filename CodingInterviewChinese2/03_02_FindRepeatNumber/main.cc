// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

// {2, 3, 5, 4, 3, 2, 6, 7}
// 1-4: 5; 5-7: 3
// 1-2: 2; 3-4: 3
// 3: 2; 4: 1

int countInRange(int* arr, int len, int begin, int end);

// 参数:
//        arr: 一个整数数组
//        len: 数组的长度
//        res: (输出) 数组中的一个重复的数字
// 返回值:
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，数组中没有重复的数字

// 时间复杂度O(nlogn)
// 空间复杂度O(1)

bool findRepeatNumber(int* arr, int len, int* res) {
  if (arr==nullptr || len <= 2) {
    return false;
  }

  int begin = 1;
  int end = len - 1;
  while (begin <= end) {
    int middle = begin + (end - begin) >> 1;
    int count = countInRange(arr, len, begin, middle);
    if (count == -1) {
      return false;
    }
    if (begin == end) {
      if (count > 1) {
        *res = begin;
        return true;
      } else {
        return false;
      }
    }
    if (count > middle - begin + 1) {
      end = middle;
    } else {
      begin = middle + 1;
    }
  }

  return false;
}

int countInRange(int* arr, int len, int begin, int end) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (arr[i] < 1 || arr[i] > len - 1) {
      return -1;
    }
    if (arr[i] >= begin && arr[i] <= end) {
      ++count;
    }
  }
  return count;
}

int main() {
  return 0;
}
