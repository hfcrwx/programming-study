// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}。

#include <deque>
#include <vector>

#include <assert.h>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    assert(k > 0 && k <= nums.size());

    std::vector<int> result;
    std::deque<int> d;
    for (std::vector<int>::size_type i = 0; i < nums.size(); ++i) {
      if (!d.empty() && d.front() == i - k) {
        d.pop_front();
      }
      while (!d.empty() && nums[d.back()] < nums[i]) {
        d.pop_back();
      }
      d.push_back(i);

      if (i >= k - 1) {
        result.push_back(nums[d.front()]);
      }
    }

    return result;
  }
};

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

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
  assert(k > 0 && k <= nums.size());
  std::vector<int> result;

  MaxQueue q;
  for (std::vector<int>::size_type i = 0; i < nums.size(); ++i) {
    q.push_back(nums[i]);
    if (i >= k-1) {
      result.push_back(q.max_value());
      q.pop_front();
    }
  }

  return result;
}

int main() {
  return 0;
}
