// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，
// 它每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和 于k的格子。
// 例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

#include <assert.h>
#include <stddef.h>
#include <string.h>

size_t movingCount(int threshold,
                   size_t rows,
                   size_t cols,
                   size_t i,
                   size_t j,
                   bool* visited);

size_t movingCount(int threshold, size_t rows, size_t cols) {
  bool* visited = new bool[rows*cols];
  memset(visited, 0, rows*cols);
  size_t count = movingCount(threshold, rows, cols, 0, 0, visited);
  delete[] visited;
  return count;
}

size_t sum(size_t i) {
  size_t s = 0;
  while (i != 0) {
    s += i%10;
    i /= 10;
  }
  return s;
}

bool check(int threshold, size_t i, size_t j) {
  return sum(i) + sum(j) <= threshold;
}

size_t movingCount(int threshold,
                   size_t rows,
                   size_t cols,
                   size_t i,
                   size_t j,
                   bool* visited) {
  size_t count = 0;
  if (i < rows && j < cols && !visited[i*cols + j] && check(threshold, i, j)) {
    visited[i*cols + j] = true;
    count = 1 + movingCount(threshold, rows, cols, i, j + 1, visited)
        + movingCount(threshold, rows, cols, i + 1, j, visited);
  }
  return count;
}

int main() {
  assert(movingCount(15, 20, 20) == 359);
  return 0;
}
