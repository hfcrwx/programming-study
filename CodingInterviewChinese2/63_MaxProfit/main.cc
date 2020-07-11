// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股票一次可能获得的利润是多少？
// 例如一只股票在某些时间节点的价格为{9, 11, 8, 5, 7, 12, 16, 14}。
// 如果我们能在价格为5的时候买入并在价格为16时卖出，则能收获最大的利润11。

#include <vector>

#include <assert.h>

int maxProfit(const std::vector<int>& prices) {
  assert(!prices.empty());

  int minPrice = prices[0];
  int maxProfit = 0;
  for (std::vector<int>::size_type i = 1; i != prices.size(); ++i) {
    if (prices[i] < minPrice) {
      minPrice = prices[i];
    }
    int profit = prices[i] - minPrice;
    if (profit > maxProfit) {
      maxProfit = profit;
    }
  }

  return maxProfit;
}

int main() {
  return 0;
}
