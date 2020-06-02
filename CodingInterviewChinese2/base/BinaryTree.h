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

#pragma once

struct BinaryTreeNodeEx
{
    int                    value_;
    BinaryTreeNodeEx*        left_;
    BinaryTreeNodeEx*        right_;
};

BinaryTreeNodeEx* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNodeEx* pParent, BinaryTreeNodeEx* pLeft, BinaryTreeNodeEx* pRight);
void PrintTreeNode(const BinaryTreeNodeEx* pNode);
void PrintTree(const BinaryTreeNodeEx* pRoot);
void DestroyTree(BinaryTreeNodeEx* pRoot);
