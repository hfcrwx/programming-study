// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

// {2, 3, 1, 0, 2, 5, 3}
// {1, 3, 2, 0, 2, 5, 3}
// {3, 1, 2, 0, 2, 5, 3}
// {0, 1, 2, 3, 2, 5, 3}
// {0, 1, 2, 3, [2], 5, 3}

// 参数:
//        arr: 一个整数数组
//        len: 数组的长度
//        res: (输出) 数组中的一个重复的数字
// 返回值:
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字

// 时间复杂度O(n)
// 空间复杂度O(1)

bool duplicate(int* arr, int len, int* res) {
  if (arr==nullptr || len <= 2) {
    return false;
  }
  for (int i = 0; i < len; ++i) {
    if (arr[i] < 0 || arr[i] > len - 1) {
      return false;
    }
  }

  for (int i = 0; i < len; ++i) {
    while (arr[i]!=i) {
      if (arr[i]==arr[arr[i]]) {
        *res = arr[i];
        return true;
      }
      int tmp = arr[i];
      arr[i] = arr[tmp];
      arr[tmp] = tmp;
    }
  }

  return false;
}

int main() {
  return 0;
}
