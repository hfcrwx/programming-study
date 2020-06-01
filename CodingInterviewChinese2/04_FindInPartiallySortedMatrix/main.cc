// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

bool find(int* mat, int row, int column, int num) {
  if (mat==nullptr || row <= 0 || column <= 0) {
    return false;
  }

  int i = 0;
  int j = column - 1;
  while (i <= row - 1 && j >= 0) {
    int val = *(mat + i*column + j);
    if (num == val) {
      return true;
    } else if (num < val) {
      --j;
    } else {
      ++i;
    }
  }
  return false;
}

int main() {
  int matrix[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  bool res = find((int*)matrix, 4, 4, 8);
  return 0;
}
