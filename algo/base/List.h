/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

struct ListNode {
  int value_;
  ListNode* next_;
};

ListNode* createListNode(int value);
void connectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void printList(ListNode* pHead);
void destroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);