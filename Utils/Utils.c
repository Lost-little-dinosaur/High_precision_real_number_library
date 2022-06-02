//
// Created by seulAuguestine on 2022/5/29.
//
#include "..\Model\struct.h"
#include "Utils.h"
#include "string.h"
#define MAXSIZE 500
#include <stdio.h>

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

int judgeOverflow(char num1[],char num2[]) {   //判断是否溢出 数据输入在main里执行
    int flag = 1, len1 = 0, len2 = 0;
    len1 = strlen(num1);
    len2 = strlen(num2);
    if (len1 > MAXSIZE || len2 > MAXSIZE) {
        flag = -1;
    }
    return flag;
}

int *judgeType(char x[],char y[]) {  //判断数据类型 如果type[0] type[1]不相等则输入错误（在main里实现）
    int type[2] = {0, 0};// 1表示无符号 2表示有符号 3表示浮点数 type[0]为第一个数的类型 type[1]为第二个数的类型
    for (int i = 0; i < strlen(x); ++i) { //判断浮点数
        if (x[i] == '.') {
            type[0] = 3;
            break;
        }
    }
    for (int j = 0; j < strlen(y); ++j) {
        if (y[j] == '.') {
            type[1] = 3;
            break;
        }
    }

    if(type[0] !=3) {
        if (x[0] == '+' || x[0] == '-') {
            type[0] = 2;
        } else if (x[0] >= '1' && x[0] <= '9') {
            type[0] = 1;
        }
    }
    if(type[1] !=3) {
        if (y[0] == '+' || y[0] == '-') {
            type[1] = 2;
        } else if (y[0] >= '1' && y[0] <= '9') {
            type[1] = 1;
        }
    }
    if (x[0] == '0' && y[0] == '0') { //都为0，则默认为无符号
        type[0] = type[1] = 1;
    } else if (x[0] == '0' && y[0] != '0') { //一个为0，一个不为0，则为0大数的类型与不为0的大数相同
        type[0] = type[1];
    } else if (y[0] == '0' && x[0] != '0') {
        type[1] = type[0];
    }

    return type;
}