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

#include <cstdio>
#include "BinaryTree.h"

BinaryTreeNodeEx* CreateBinaryTreeNode(int value)
{
    BinaryTreeNodeEx* pNode = new BinaryTreeNodeEx();
    pNode->value_ = value;
    pNode->left_ = nullptr;
    pNode->right_ = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNodeEx* pParent, BinaryTreeNodeEx* pLeft, BinaryTreeNodeEx* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left_ = pLeft;
        pParent->right_ = pRight;
    }
}

void PrintTreeNode(const BinaryTreeNodeEx* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->value_);

        if(pNode->left_ != nullptr)
            printf("value of its left child is: %d.\n", pNode->left_->value_);
        else
            printf("left child is nullptr.\n");

        if(pNode->right_ != nullptr)
            printf("value of its right child is: %d.\n", pNode->right_->value_);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const BinaryTreeNodeEx* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->left_ != nullptr)
            PrintTree(pRoot->left_);

        if(pRoot->right_ != nullptr)
            PrintTree(pRoot->right_);
    }
}

void DestroyTree(BinaryTreeNodeEx* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNodeEx* pLeft = pRoot->left_;
        BinaryTreeNodeEx* pRight = pRoot->right_;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
