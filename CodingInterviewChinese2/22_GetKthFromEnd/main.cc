// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，本题从1开始计数，即链表
// 的尾结点是倒数第1个结点。例如一个链表有6个结点，从头结点开始，它们的值依次是1、2、3、4、5、6。
// 这个链表的倒数第3个结点是值为4的结点。

#include <base/List.h>
#include <stdint.h>

const ListNode* getKthFromEnd(const ListNode* head, uint32_t k) {
  if (head == nullptr || k == 0) {
    return nullptr;
  }

  const ListNode* ahead = head;
  for (uint32_t i = 0; i < k - 1; ++i) {
    ahead = ahead->next_;
    if (ahead == nullptr) {
      return nullptr;
    }
  }
  const ListNode* behind = head;
  while (ahead->next_ != nullptr) {
    ahead = ahead->next_;
    behind = behind->next_;
  }
  return behind;
}

int main() {
  return 0;
}
