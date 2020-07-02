// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

/*
1    2    3    4
5    6    7    8
9    10   11   12
13   14   15   16
*/

#include <stddef.h>
#include <stdio.h>

void print(int v);
void printCircle(const int** matrix, size_t rows, size_t cols, size_t start);

void spiralOrder(const int** matrix, size_t rows, size_t cols) {
  if (matrix == nullptr || rows == 0 || cols == 0) {
    return;
  }
  
  size_t min = rows < cols ? rows : cols;
  size_t startMax = (min + 1) >> 1u;
  for (size_t start = 0; start < startMax; ++start) {
    printCircle(matrix, rows, cols, start);
  }
}

//start,start           endX,start
//start,endY            endX,endY
//matrix[y][x]
void printCircle(const int** matrix, size_t rows, size_t cols, size_t start) {
  size_t endX = cols - 1 - start;
  size_t endY = rows - 1 - start;

  for (size_t x = start; x <= endX; ++x) {
    print(matrix[start][x]);
  }

  for (size_t y = start + 1; y <= endY; ++y) {
    print(matrix[y][endX]);
  }

  if (start < endY) {
    for (size_t x = endX - 1; x >= start; --x) {
      print(matrix[endY][x]);
    }
  }

  if (start < endX) {
    for (size_t y = endY - 1; y >= start + 1; --y) {
      print(matrix[y][start]);
    }
  }
}

void print(int v) {
  printf("%d, ", v);
}

int main() {
  return 0;
}
