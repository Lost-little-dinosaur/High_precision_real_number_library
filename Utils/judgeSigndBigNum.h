//
// Created by seulAuguestine on 2022/5/19.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGESIGNDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGESIGNDBIGNUM_H
#define MAXSIZE 500
#include "..\Model\struct.h"

int judgeSignedBigNum (char x[]) {//判断有符号整数是正数负数还是0
    struct SignedBigNum SBN;
    char c = x[0];
    if (c == '+') {
        SBN.flag = 1;
    } else if (c == '-') {
        SBN.flag = -1;
    } else {
        SBN.flag = 0;
    }
    return SBN.flag;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGESIGNDBIGNUM_H
