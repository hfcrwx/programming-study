// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵
// 中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那
// 么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母
// 用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行
// 第二个格子之后，路径不能再次进入这个格子。
// a b t g
// c f c s
// j d e h

#include <assert.h>
#include <stddef.h>
#include <string.h>

//bool exist(const char* matrix,
//           size_t rows,
//           size_t cols,
//           const char* word,
//           size_t i,
//           size_t j,
//           size_t idx,
//           bool* visited) {
//  if (word[idx] == '\0') {
//    return true;
//  }
//  if (0 <= i && i < rows && 0 <= j && j < cols
//      && matrix[i*cols + j] == word[idx]
//      && !visited[i*cols + j]) {
//    visited[i*cols + j] = true;
//
//    bool has = exist(matrix, rows, cols, word, i, j - 1, idx + 1, visited)
//        || exist(matrix, rows, cols, word, i, j + 1, idx + 1, visited)
//        || exist(matrix, rows, cols, word, i - 1, j, idx + 1, visited)
//        || exist(matrix, rows, cols, word, i + 1, j, idx + 1, visited);
//    if (has) {
//      return true;
//    } else {
//      visited[i*cols + j] = false;
//      return false;
//    }
//  } else {
//    return false;
//  }
//}
//
//bool exist(const char* matrix, size_t rows, size_t cols, const char* str) {
//  assert(matrix != nullptr && str != nullptr);
//
//  bool* visited = new bool[rows*cols];
//  memset(visited, 0, rows*cols);
//
//  for (size_t i = 0; i < rows; ++i) {
//    for (size_t j = 0; j < cols; ++j) {
//      if (exist(matrix, rows, cols, str, i, j, 0, visited)) {
//        return true;
//      }
//    }
//  }
//
//  delete[] visited;
//  return false;
//}

bool exist(char* matrix,
           size_t rows,
           size_t cols,
           const char* word,
           size_t i,
           size_t j,
           size_t idx) {
  if (word[idx] == '\0') {
    return true;
  }
  if (0 <= i && i < rows && 0 <= j && j < cols
      && matrix[i*cols + j] == word[idx]) {
    matrix[i*cols + j] = '\0';

    bool has = exist(matrix, rows, cols, word, i, j - 1, idx + 1)
        || exist(matrix, rows, cols, word, i, j + 1, idx + 1)
        || exist(matrix, rows, cols, word, i - 1, j, idx + 1)
        || exist(matrix, rows, cols, word, i + 1, j, idx + 1);
    if (has) {
      return true;
    } else {
      matrix[i*cols + j] = word[idx];
      return false;
    }
  } else {
    return false;
  }
}

bool exist(char* matrix, size_t rows, size_t cols, const char* str) {
  assert(matrix != nullptr && str != nullptr);

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (exist(matrix, rows, cols, str, i, j, 0)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  return 0;
}
