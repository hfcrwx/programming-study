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
      dp[i] = new int[6*i + 1];
    }

    for (int s = 1; s <= 6; ++s) {
      dp[1][s] = 1;
    }

    for (int i = 2; i <= n; ++i) {
      for (int s = i; s <= 6*i; ++s) {
        for (int t = 1; t < s && t <= 6; ++t) {
          dp[i][s] += dp[i - 1][s - t];
        }
      }
    }

    int all = static_cast<int>(pow(6, n));
    vector<double> ret;
    for (int s = n; s <= 6*n; s++) {
      ret.emplace_back(dp[n][s]*1.0/all);
    }

    for (int i = 0; i < n + 1; ++i) {
      delete[] dp[i];
    }
    delete[] dp;

    return ret;
  }
};

int main() {
  return 0;
}
