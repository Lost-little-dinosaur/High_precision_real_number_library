//
// Created by seulAuguestine on 2022/5/21.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
#define MAXSIZE 500
#include <string.h>

struct FloatBigNum {//超高精度实数
    int lengthIntager;//表示数据的位数
    int lengthDecimal;//表示数据的位数
    char intager[MAXSIZE];//整数部分
    char decimal[MAXSIZE];//小数部分
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

char  *sepBigNumIn (char *x) {//输入带符号的实数 输出整数部分
    struct FloatBigNum FBN;
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
        FBN.intager[k] = x[i];
        //printf("%c", FBN.intager[k]);
    }
    return FBN.intager;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
