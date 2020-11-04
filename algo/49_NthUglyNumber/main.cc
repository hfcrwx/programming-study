// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

#include <algorithm>
#include <vector>

int nthUglyNumber01(int n) {
  std::vector<int> v;
  v.push_back(1);

  int i = 0, j = 0, k = 0;
  while (v.size() < n) {
    int next = std::min(std::min(v[i]*2, v[j]*3), v[k]*5);
    v.push_back(next);
    if (next == v[i]*2) i++;
    if (next == v[j]*3) j++;
    if (next == v[k]*5) k++;
  }
  return v.back();
}

int main() {
  return 0;
}
