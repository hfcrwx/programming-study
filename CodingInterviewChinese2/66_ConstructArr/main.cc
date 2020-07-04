// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其中B中的元素B[i] =A
// [0]×A[1]×… ×A[i-1]×A[i+1]×… ×A[n-1]。不能使用除法。

#include <vector>
#include <assert.h>

std::vector<int> constructArr(const std::vector<int>& a) {
  assert(!a.empty());

  std::vector<int> b;
  int sz = a.size();
  b.reserve(sz);

  b[0] = 1;
  for (int i = 1; i < sz; ++i) {
    b[i] = b[i-1] * a[i-1];
  }

  int tmp = 1;
  for (int i = sz-2; i >=0; --i) {
    tmp *= a[i+1];
    b[i] *= tmp;
  }

  return b;
}

int main() {
  return 0;
}
