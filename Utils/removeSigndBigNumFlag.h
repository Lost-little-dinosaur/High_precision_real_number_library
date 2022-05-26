//
// Created by seulAuguestine on 2022/5/22.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_REMOVESIGNDBIGNUMFLAG_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_REMOVESIGNDBIGNUMFLAG_H
#define MAXSIZE 500
#include <string.h>
#include "../Model/struct.h"


struct UnsignedBigNum removeSigndBigNumFlag(char x[]) {//移除有符号大整数的符号位得到numbody
    struct UnsignedBigNum SBN;
    SBN.length = strlen(x);
    //printf("%d",SBN.length);
    for (int i = 1, j = 0; i < SBN.length, j < SBN.length - 1; ++i, ++j) {
        SBN.numBody[j] = x[i];
        //printf("%c",SBN.numBody[j]);
    }
    return SBN;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_REMOVESIGNDBIGNUMFLAG_H
