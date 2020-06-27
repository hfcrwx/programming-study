// 面试题18（一）：在O(1)时间内删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间内删除该结点。

#include <base/List.h>

void deleteNode(ListNode** head, ListNode* target) {
  if (head == nullptr || *head == nullptr || target == nullptr) {
    return;
  }

  if (target->next_ != nullptr) {
    ListNode* next = target->next_;
    target->value_ = next->value_;
    target->next_ = next->next_;
    delete next;
    next = nullptr;
  } else {
    if (target == *head) {
      delete target;
      target = nullptr;
      *head = nullptr;
    } else {
      ListNode* node = *head;
      while (node->next_ != target) {
        node = node->next_;
      }
      node->next_ = nullptr;
      delete target;
      target = nullptr;
    }
  }
}

int main() {
  return 0;
}
