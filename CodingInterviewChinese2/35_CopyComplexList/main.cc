// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include <assert.h>

struct ComplexListNode {
  int value_;
  ComplexListNode* next_;
  ComplexListNode* sibling_;
};

void cloneNodes(ComplexListNode* head);
void connectSiblingNodes(ComplexListNode* head);
ComplexListNode* reconnectNodes(ComplexListNode* head);

ComplexListNode* cloneComplexList(ComplexListNode* head) {
  if (head==nullptr) {
    return nullptr;
  }
  cloneNodes(head);
  connectSiblingNodes(head);
  return reconnectNodes(head);
}

void cloneNodes(ComplexListNode* head) {
  ComplexListNode* node = head;
  while (node!=nullptr) {
    ComplexListNode* cloned = new ComplexListNode;
    cloned->value_ = node->value_;
    cloned->next_ = node->next_;
    cloned->sibling_ = nullptr;
    node->next_ = cloned;

    node = cloned->next_;
  }
}

void connectSiblingNodes(ComplexListNode* head) {
  ComplexListNode* node = head;
  while (node!=nullptr) {
    ComplexListNode* cloned = node->next_;
    if (node->sibling_!=nullptr) {
      cloned->sibling_ = node->sibling_->next_;
    }

    node = cloned->next_;
  }
}

ComplexListNode* reconnectNodes(ComplexListNode* head) {
  assert(head!=nullptr);
  ComplexListNode* clonedHead = head->next_;

  ComplexListNode* cloned = clonedHead;
  ComplexListNode* node = head;
  node->next_ = cloned->next_;
  node = node->next_;

  while (node!=nullptr) {
    cloned->next_ = node->next_;
    cloned = cloned->next_;

    node->next_ = cloned->next_;
    node = node->next_;
  }
  return clonedHead;
}

int main() {
  return 0;
}
