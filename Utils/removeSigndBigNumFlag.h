//
// Created by seulAuguestine on 2022/5/22.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_REMOVESIGNDBIGNUMFLAG_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_REMOVESIGNDBIGNUMFLAG_H
#define MAXSIZE 500
#include <string.h>

struct SigndBigNum {//有符号大整数
    int length;//表示数据的位数
    char numBody[MAXSIZE];//表示数据主体
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

char *removeSigndBigNumFlag(char x[]) {//移除有符号大整数的符号位得到numbody
    struct SigndBigNum SBN;
    SBN.length = strlen(x);
    //printf("%d",SBN.length);
    for (int i = 1, j = 0; i < SBN.length, j < SBN.length - 1; ++i, ++j) {
        SBN.numBody[j] = x[i];
        //printf("%c",SBN.numBody[j]);
    }
    return SBN.numBody;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_REMOVESIGNDBIGNUMFLAG_H
