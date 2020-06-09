// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

#include <algorithm>

#include <assert.h>
#include <stddef.h>

//  —— j
// |
// i
int maxValue(const int* array, size_t rows, size_t cols) {
  assert(array != nullptr && rows != 0 && cols != 0);
  int** matrix = new int* [rows];
  for (size_t i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];
  }

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      int left = j > 0 ? matrix[i][j - 1] : 0;
      int up = i > 0 ? matrix[i - 1][j] : 0;
      matrix[i][j] = std::max(left, up) + *(array + i*cols + j);
    }
  }
  int max = matrix[rows - 1][cols - 1];

  for (size_t i = 0; i < rows; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;

  return max;
}
int main() {
  return 0;
}
