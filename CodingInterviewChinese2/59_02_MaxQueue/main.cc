// 面试题59（二）：队列的最大值
// 题目：请定义一个队列并实现函数 max 得到队列里的最大值，要求函数max、push_back 和 pop_front 的时间复杂度都是O(1)。

#include <deque>
#include <queue>

class MaxQueue {
 public:
  MaxQueue () {
  }

  int max_value() {
    return d.front();
  }

  void push_back(int value) {
    q.push(value);

    while (!d.empty() && d.back() < value) {
      d.pop_back();
    }
    d.push_back(value);
  }

  int pop_front() {
    int res = q.front();
    q.pop();

    if (res == d.front()) {
      d.pop_front();
    }

    return res;
  }

 private:
  std::queue<int> q;
  std::deque<int> d;
};

int main() {
  return 0;
}