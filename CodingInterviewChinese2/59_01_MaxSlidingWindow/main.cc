#include <deque>
#include <vector>

#include <assert.h>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    assert(k > 0 && k <= nums.size());

    std::vector<int> result;
    std::deque<int> q;
    for (std::vector<int>::size_type i = 0; i < nums.size(); ++i) {
      if (!q.empty() && q.front() == i - k) {
        q.pop_front();
      }
      while (!q.empty() && nums[q.back()] < nums[i]) {
        q.pop_back();
      }
      q.push_back(nums[i]);

      if (i >= k - 1) {
        result.push_back(nums[q.front()]);
      }
    }

    return result;
  }
};

int main() {
  return 0;
}