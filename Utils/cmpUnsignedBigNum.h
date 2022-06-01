//
// Created by seulAuguestine on 2022/5/28.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_CMPUNSIGNEDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_CMPUNSIGNEDBIGNUM_H

#include "string.h"

#define MAXSIZE 500

#include "..\model\struct.h"

int cmpUnsignedBigNum(struct UnsignedBigNum x, struct UnsignedBigNum y) {
    int flag;
    if (x.length > y.length)
        flag = 1;
    else if (x.length == y.length) {
        if (strcmp(x.numBody, y.numBody) >= 0)
            flag = 1;
        else
            flag = 0;
    } else
        flag = 0;

    return flag;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_CMPUNSIGNEDBIGNUM_H
