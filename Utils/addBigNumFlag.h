//
// Created by seulAuguestine on 2022/5/28.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_ADDBIGNUMFLAG_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_ADDBIGNUMFLAG_H
#include "..\Model\struct.h"
char addSignedBigNumFlag(struct SignedBigNum x) {//添加符号
    char f = ' ';
    if (x.flag == 1) {
        f = '+';
    } else if (x.flag == -1) {
        f = '-';
    }
    return f;
}
#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_ADDBIGNUMFLAG_H
