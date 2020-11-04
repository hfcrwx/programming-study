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

#include "StringUtil.h"
#include <assert.h>

void reverse(char* begin, char* end) {
  assert (begin != nullptr && end != nullptr);

  while (begin < end) {
    char temp = *begin;
    *begin = *end;
    *end = temp;

    begin++;
    end--;
  }
}
