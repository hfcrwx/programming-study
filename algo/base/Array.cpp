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

#include <stdlib.h>
#include "Array.h"
#include <exception>

// Random Partition
int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition(int data[], int length, int start, int end)
{
    if(data == nullptr || length <= 0 || start < 0 || end >= length)
        throw new std::exception(/*"Invalid Parameters"*/);

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]); //end是选出的数

    int small = start - 1; //指向从头开始连续小于end的最后一个数
    for(int i = start; i < end; ++ i)
    {
        if(data[i] < data[end])
        {
            ++ small;
            if(small != i) //此时small指向从头开始大于end的第一个数
                Swap(&data[i], &data[small]);
        }
    }

    ++ small;
    Swap(&data[small], &data[end]);

    return small;
}
