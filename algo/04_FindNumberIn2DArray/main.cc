// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

// 时间复杂度O(n)
// 空间复杂度O(1)

#include <assert.h>
#include <stddef.h>

bool findNumberIn2DArray(const int** matrix,
                         size_t rows,
                         size_t cols,
                         int target) {
  assert(matrix != nullptr && rows != 0 && cols != 0);

  size_t i = 0;
  size_t j = cols - 1;
  while (i <= rows - 1 && j >= 0) {
    int val = matrix[i][j];
    if (val == target) {
      return true;
    } else if (val < target) {
      ++i;
    } else {
      --j;
    }
  }

  return false;
}

int main() {
  int matrix[][3] =
      {{1, 2, 8}, {2, 4, 9}, {4, 7, 10}, {6, 8, 11}};
  const int* a[4] = {matrix[0], matrix[1], matrix[2], matrix[3]};
  bool res = findNumberIn2DArray(a, 4, 4, 8);
  return 0;
}
