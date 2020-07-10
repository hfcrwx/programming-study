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