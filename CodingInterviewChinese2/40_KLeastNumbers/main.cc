// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <set>
#include <vector>

#include <stddef.h>

void getLeastNumbers(const std::vector<int>& data,
                     size_t k,
                     std::multiset<int, std::greater<int>>& result) {
  result.clear();

  if (data.empty() || k == 0) {
    return;
  }

  for (std::vector<int>::const_iterator it = data.begin();
       it != data.end(); ++it) {
    if (result.size() < k) {
      result.insert(*it);
    } else {
      if (*it < *result.begin()) {
        result.erase(result.begin());
        result.insert(*it);
      }
    }
  }
}

int main() {
  return 0;
}
