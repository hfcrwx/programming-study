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
      *head = nullptr;
      delete target;
      target = nullptr;
    } else {
      ListNode* prev = *head;
      while (prev->next_ != target) {
        prev = prev->next_;
      }
      prev->next_ = nullptr;
      delete target;
      target = nullptr;
    }
  }
}

//203
class Solution {
 public:
  ListNode* removeElements1(ListNode* head, int val) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* prev = head;
    while (prev->next_ != nullptr) {
      ListNode* curr = prev->next_;
      if (curr->value_ == val) {
        prev->next_ = curr->next_;
        delete curr;
      } else {
        prev = prev->next_;
      }
    }
    if (head->value_ == val) {
      ListNode* next = head->next_;
      delete head;
      return next;
    } else {
      return head;
    }
  }

  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy;
    dummy.next_ = head;

    ListNode* prev = &dummy;
    while (prev->next_ != nullptr) {
      ListNode* curr = prev->next_;
      if (curr->value_ == val) {
        prev->next_ = curr->next_;
        delete curr;
      } else {
        prev = prev->next_;
      }
    }

    return dummy.next_;
  }
};

int main() {
  return 0;
}
