// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间结点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

int maxProfit(const int* prices, size_t len) {
  assert(prices != nullptr);
  assert(len != 0);

  if (len == 1) {
    return 0;
  }

  int min = prices[0];
  int maxDiff = prices[1] - prices[0];
  for (size_t i = 2; i < len; ++i) {
    if (prices[i - 1] < min) {
      min = prices[i - 1];
    }
    int diff = prices[i] - min;
    if (diff > maxDiff) {
      maxDiff = diff;
    }
  }
  return maxDiff;
}

int main() {
  return 0;
}
