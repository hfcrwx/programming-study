// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之
// 后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

#include <queue>
#include <assert.h>

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {

  }

  void addNum(int num) {
    if (((max_.size() + min_.size()) & 1u) == 0) {
      if (!min_.empty() && num > min_.top()) {
        min_.push(num);
        num = min_.top();
        min_.pop();
      }
      max_.push(num);
    } else {
      if (!max_.empty() && num < max_.top()) {
        max_.push(num);
        num = max_.top();
        max_.pop();
      }
      min_.push(num);
    }
  }

  double findMedian() {
    assert(max_.size() + min_.size() != 0);
    if (((max_.size() + min_.size()) & 1) == 1) {
      return max_.top();
    } else {
      return (max_.top() + min_.top()) / 2.0;
    }
  }

 private:
  std::priority_queue<int, std::vector<int>, std::less<int>> max_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  MedianFinder mf;
  mf.addNum(1);
  double x = mf.findMedian();
  mf.addNum(2);
  x = mf.findMedian();
  mf.addNum(3);
  x= mf.findMedian();
  return 0;
}