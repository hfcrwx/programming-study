/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
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
    Swap(&data[index], &data[end]); //end��ѡ������

    int small = start - 1; //ָ���ͷ��ʼ����С��end�����һ����
    for(int i = start; i < end; ++ i)
    {
        if(data[i] < data[end])
        {
            ++ small;
            if(small != i) //��ʱsmallָ���ͷ��ʼ����end�ĵ�һ����
                Swap(&data[i], &data[small]);
        }
    }

    ++ small;
    Swap(&data[small], &data[end]);

    return small;
}
