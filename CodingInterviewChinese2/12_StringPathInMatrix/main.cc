// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// a b t g
// c f c s
// j d e h

#include <assert.h>
#include <stddef.h>
#include <string.h>

bool hasPathCore(const char* matrix,
                 size_t rows,
                 size_t cols,
                 const char* str,
                 size_t i,
                 size_t j,
                 size_t* len,
                 bool* visited);

bool hasPath(const char* matrix, size_t rows, size_t cols, const char* str) {
  assert(matrix!=nullptr && str!=nullptr);
  size_t len = 0;
  bool* visited = new bool[rows*cols];
  memset(visited, 0, rows*cols);

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (hasPathCore(matrix, rows, cols, str, i, j, &len, visited)) {
        return true;
      }
    }
  }
  return false;
}

bool hasPathCore(const char* matrix,
                 size_t rows,
                 size_t cols,
                 const char* str,
                 size_t i,
                 size_t j,
                 size_t* len,
                 bool* visited) {
  if (str[*len]=='\0') {
    return true;
  }
  if (0 < i && i < rows && 0 < j && j < cols && matrix[i*cols + j]==str[*len] && !visited[i*cols + j]) {
    ++*len;
    visited[i*cols + j] = true;

    bool has = hasPathCore(matrix, rows, cols, str, i, j - 1, len, visited)
        || hasPathCore(matrix, rows, cols, str, i, j + 1, len, visited)
        || hasPathCore(matrix, rows, cols, str, i - 1, j, len, visited)
        || hasPathCore(matrix, rows, cols, str, i + 1, j, len, visited);
    if (has) {
      return true;
    } else {
      --*len;
      visited[i*cols + j] = false;
      return false;
    }
  } else {
    return false;
  }
}

int main() {
  return 0;
}
