// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复的结点被删除之后，链表如
// 图3.4（b）所示。

// 1 2 3 3 4 4 5
// 1 2 5

#include <base/List.h>

void deleteDuplication(ListNode** head) {
  if (head == nullptr || *head == nullptr) {
    return;
  }

  ListNode* prev = nullptr;
  ListNode* curr = *head;
  while (curr != nullptr) {
    ListNode* next = curr->next_;
    bool found = false;
    if (next != nullptr && next->value_ == curr->value_) {
      found = true;
    }
    if (found) {
      int val = curr->value_;
      while (curr != nullptr && curr->value_ == val) {
        next = curr->next_;

        delete curr;
        curr = nullptr;

        curr = next;
      }
      if (prev == nullptr) {
        *head = curr;
      } else {
        prev->next_ = curr;
      }
    } else {
      prev = curr;
      curr = next;
    }
  }
}

int main() {
  ListNode* pNode1 = createListNode(1);
  ListNode* pNode2 = createListNode(2);
  ListNode* pNode3 = createListNode(3);
  ListNode* pNode4 = createListNode(3);
  ListNode* pNode5 = createListNode(4);
  ListNode* pNode6 = createListNode(4);
  ListNode* pNode7 = createListNode(5);

  connectListNodes(pNode1, pNode2);
  connectListNodes(pNode2, pNode3);
  connectListNodes(pNode3, pNode4);
  connectListNodes(pNode4, pNode5);
  connectListNodes(pNode5, pNode6);
  connectListNodes(pNode6, pNode7);

  deleteDuplication(&pNode1);
  return 0;
}
