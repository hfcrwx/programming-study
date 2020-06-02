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

#include "List.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* createListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->value_ = value;
    pNode->next_ = nullptr;

    return pNode;
}

void connectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->next_ = pNext;
}

void PrintListNode(ListNode* pNode)
{ 
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->value_);
    }
}

void printList(ListNode* pHead)
{
    printf("printList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->value_);
        pNode = pNode->next_;
    }

    printf("\nprintList ends.\n");
}

void destroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->next_;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->value_ = value;
    pNew->next_ = nullptr;

    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next_ != nullptr)
            pNode = pNode->next_;

        pNode->next_ = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->value_ == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next_;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next_ != nullptr && pNode->next_->value_ != value)
            pNode = pNode->next_;

        if(pNode->next_ != nullptr && pNode->next_->value_ == value)
        {
            pToBeDeleted = pNode->next_;
            pNode->next_ = pNode->next_->next_;
        }
    }

    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}