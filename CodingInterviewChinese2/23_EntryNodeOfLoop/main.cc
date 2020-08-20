// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8所示的链表中，环的入口结点是结点3。

#include <base/List.h>
#include <assert.h>
#include <stddef.h>

size_t loopSize(const ListNode* head) {
  if (head == nullptr) {
    return 0;
  }

  const ListNode* slow = head->next_;
  if (slow == nullptr) {
    return 0;
  }
  const ListNode* fast = slow->next_;

  while (slow != fast) {
    if (fast == nullptr) {
      return 0;
    }
    fast = fast->next_;
    if (fast == nullptr) {
      return 0;
    }
    fast = fast->next_;

    assert(slow != nullptr);
    slow = slow->next_;
  }

  size_t size = 1;
  assert(slow != nullptr);
  fast = slow->next_;
  while (fast != slow) {
    ++size;
    assert(fast != nullptr);
    fast = fast->next_;
  }

  return size;
}

const ListNode* entryNodeOfLoop(const ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }

  size_t size = loopSize(head);
  if (size == 0) {
    return nullptr;
  }

  const ListNode* ahead = head;
  for (size_t i = 0; i < size; ++i) {
    ahead = ahead->next_;
  }
  const ListNode* behind = head;
  while (behind != ahead) {
    ahead = ahead->next_;
    behind = behind->next_;
  }

  return ahead;
}

int main() {
  return 0;
}
