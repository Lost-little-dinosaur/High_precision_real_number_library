//
// Created by seulAuguestine on 2022/5/29.
//
#include "..\Model\struct.h"
#include "Utils.h"
#include "string.h"
#define MAXSIZE 500


char addSignedBigNumFlag(struct SignedBigNum x) {//添加符号
    char f = ' ';
    if (x.flag == 1) {
        f = '+';
    } else if (x.flag == -1) {
        f = '-';
    }
    return f;
}

int cmpUnsignedBigNum(UnsignedBigNum x, UnsignedBigNum y) {//有符号数符号一致时简单比较
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

int judgeFloatBigNum(char x[]) {//判断高精度实数是正数负数还是0
    struct FloatBigNum FBN;
    char c = x[0];
    if (c == '+') {
        FBN.flag = 1;
    } else if (c == '-') {
        FBN.flag = -1;
    } else {
        FBN.flag = 0;
    }
    return FBN.flag;
}

int judgeSignedBigNum(char x[]) {//判断有符号整数是正数负数还是0
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

struct UnsignedBigNum removeSigndBigNumFlag(char x[]) {//移除有符号大整数的符号位得到numbody
    struct UnsignedBigNum SBN;
    memset(SBN.numBody,0, sizeof(SBN.numBody));
    SBN.length = strlen(x)-1;
    //printf("%d",SBN.length);
    for (int i = 1, j = 0; i < SBN.length+1, j < SBN.length ; ++i, ++j) {
        SBN.numBody[j] = x[i];
        //printf("%c",SBN.numBody[j]);
    }
    return SBN;
}

char *sepBigNumDe(char *x) {//输入带符号的实数 输出小数部分
    struct FloatBigNum FBN;
    memset(FBN.decimal, 0, sizeof(FBN.decimal));
    int j, k, len;
    int i;
    len = strlen(x);
    for (i = 0; i < len; i++) {
        if (x[i] == '.') {
            break;
        }
    }
    //printf("%d %d",i,len);
    j = i;
    for (i = j + 1, k = 0; i < len, k < len - j; ++i, ++k) {
        FBN.decimal[k] = x[i];
        //printf("%c",FBN.decimal[k]);
    }
    return FBN.decimal;
}

char *sepBigNumIn(char *x) {//输入带符号的实数 输出整数部分
    struct FloatBigNum FBN;
    memset(FBN.integer, 0, sizeof(FBN));
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
        //printf("%c", FBN.intager[k]);
    }
    return FBN.integer;
}