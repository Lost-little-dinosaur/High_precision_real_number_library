//
// Created by seulAuguestine on 2022/5/21.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
#define MAXSIZE 500
#include <string.h>
#include "..\Model\struct.h"

char  *sepBigNumIn (char *x) {//输入带符号的实数 输出整数部分
    struct FloatBigNum FBN;
    memset(FBN.integer,0,sizeof(FBN));
    int j, k, len;
    int i;
    len = strlen(x);
    for (i = 0; i < len; i++) {
        if (x[i] == '.') {
            break;
        }
    }
    j = i;
    for (i = 1, k = 0; i < j, k < j - 1; ++i, ++k) {
        FBN.integer[k] = x[i];
        //printf("%c", FBN.integer[k]);
    }
    return FBN.integer;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
