// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

#include <vector>

#include <math.h>
#include <string.h>

using std::vector;

class Solution {
 public:
  vector<double> twoSum(int n) {
    int** dp = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i) {
      dp[i] = new int[6*n + 1];
    }

    for (int s = 1; s <= 6; ++s) {
      dp[1][s] = 1;
    }

    for (int i = 2; i <= n; ++i) {
      for (int s = i; s <= 6*i; ++s) {
        for (int cur = 1; cur < s && cur <= 6; cur++) {
          dp[i][s] += dp[i - 1][s - cur];
        }
      }
    }

    int all = static_cast<int>(pow(6, n));
    vector<double> ret;
    for (int i = n; i <= 6*n; i++) {
      ret.emplace_back(dp[n][i]*1.0/all);
    }

    return ret;
  }
};

int main() {
  return 0;
}
