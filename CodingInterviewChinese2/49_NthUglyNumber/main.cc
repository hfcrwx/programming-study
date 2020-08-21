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