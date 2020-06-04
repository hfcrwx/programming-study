#include <base/List.h>

void deleteDuplicatedNode(ListNode** head) {
  if (head==nullptr || *head==nullptr) {
    return;
  }
  ListNode* pre = nullptr;
  ListNode* cur = *head;
  while (cur!=nullptr) {
    ListNode* next = cur->next_;
    bool found = false;
    if (next!=nullptr && next->value_==cur->value_) {
      found = true;
    }
    if (found) {
      int val = cur->value_;
      while (cur!=nullptr && cur->value_==val) {
        next = cur->next_;

        delete cur;
        cur = nullptr;

        cur = next;
      }
      if (pre==nullptr) {
        *head = next;
      } else {
        pre->next_ = cur;
      }
    } else {
      pre = cur;
      cur = next;
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

  deleteDuplicatedNode(&pNode1);
  return 0;
}
