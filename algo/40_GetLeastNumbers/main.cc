// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8这8个数字，
// 则最小的4个数字是1、2、3、4。

#include <set>
#include <vector>

#include <stddef.h>

void getLeastNumbers(const std::vector<int>& data,
                     size_t k,
                     std::multiset<int, std::greater<int>>& result) {
  result.clear();

  if (k == 0) {
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

#include <algorithm>
#include <assert.h>

class Solution {
 public:
  //STL using qsort to solve this problem
  std::vector<int> getLeastNumbers_buildin(std::vector<int>& nums, int k) {
    std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end());
    return std::vector<int>(nums.begin(), nums.begin() + k);
  }

  //qsort partition
  int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1, r = right;
    while (l <= r) {
      if (nums[l] > pivot && nums[r] < pivot) {
        std::swap(nums[l++], nums[r--]);
      }
      if (nums[l] <= pivot) {
        l++;
      }
      if (nums[r] >= pivot) {
        r--;
      }
    }
    std::swap(nums[left], nums[r]);
    return r;
  }

  void quickSort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }
    int pos = partition(nums, left, right);
    quickSort(nums, left, pos - 1);
    quickSort(nums, pos + 1, right);
  }

  std::vector<int> getLeastNumbers_qsort(std::vector<int>& nums, int k) {
    assert(k >0 && k <= nums.size());

    int left = 0, right = nums.size() - 1;
    while (true) {
      int pos = partition(nums, left, right);
      if (pos == k - 1) {
        return std::vector<int>(nums.begin(), nums.begin() + k);
      } else if (pos > k - 1) {
        right = pos - 1;
      } else {
        left = pos + 1;
      }
    }
  }

  std::vector<int> getLeastNumbers(std::vector<int>& nums, int k) {
    return getLeastNumbers_qsort(nums, k);
  }
};

int main() {
  Solution sln;
  std::vector<int> v;
  v.push_back(4);
  v.push_back(5);
  v.push_back(1);
  v.push_back(6);
  v.push_back(2);
  v.push_back(7);
  v.push_back(3);
  v.push_back(8);
//  std::vector<int> res = sln.getLeastNumbers(v, 4);
  std::vector<int> res = sln.getLeastNumbers_buildin(v, 4);

  return 0;
}
