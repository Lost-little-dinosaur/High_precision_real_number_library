//
// Created by seulAuguestine on 2022/5/29.
//
#include "..\Model\struct.h"
#include "Utils.h"
#include "string.h"



#include <stdio.h>
#include <stdlib.h>


char addSignedBigNumFlag(struct SignedBigNum x) {//添加符号
    char f = ' ';
    if (x.flag == 1) {
        f = '+';
    } else if (x.flag == -1) {
        f = '-';
    }
    return f;
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

struct UnsignedBigNum removeSignedBigNumFlag(char x[]) {//移除有符号大整数的符号位得到numbody
    struct UnsignedBigNum SBN;
    memset(SBN.numBody, 0, sizeof(SBN.numBody));
    SBN.length = strlen(x) - 1;
    //printf("%d",SBN.length);
    for (int i = 1, j = 0; i < SBN.length + 1, j < SBN.length; ++i, ++j) {
        SBN.numBody[j] = x[i];
        //printf("%c",SBN.numBody[j]);
    }
    return SBN;
}

void sepBigNumDe(char *x,char *ans) {//输入带符号的实数 输出小数部分
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
        ans[k] = x[i];
        ans[k+1]='\0';
        //printf("%c",FBN.decimal[k]);
    }
}

void sepBigNumIn(char *x,char *ans) {//输入带符号的实数 输出整数部分
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
        ans[k] = x[i];
        ans[k+1]='\0';
        //printf("%c", FBN.intager[k]);
    }
}

int judgeOverflow(char num1[], char num2[]) {   //判断是否溢出 数据输入在main里执行
    int flag = 1, len1 = 0, len2 = 0;
    len1 = strlen(num1);
    len2 = strlen(num2);
    if (len1 > MAXSIZE || len2 > MAXSIZE) {
        flag = -1;
    }
    return flag;
}

int *judgeType(char x[], char y[]) {  //判断数据类型 如果type[0] type[1]不相等则输入错误（在main里实现）
    int *type = (int *) malloc(2 * sizeof(int));// 1表示无符号 2表示有符号 3表示浮点数 type[0]为第一个数的类型 type[1]为第二个数的类型
    type[0]=0;
    type[1]=0;
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

    if (type[0] != 3) {
        if (x[0] == '+' || x[0] == '-') {
            type[0] = 2;
        } else if (x[0] >= '1' && x[0] <= '9') {
            type[0] = 1;
        }
    }
    if (type[1] != 3) {
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

struct SignedBigNum unToSigned(int type[],char x[],char y[])//无符号转有符号 输出转换后的结构体
{
    struct SignedBigNum a, b;
    memset(a.numBody, 0, sizeof(a.numBody));
    memset(b.numBody, 0, sizeof(b.numBody));
    if (type[0] == 1 && type[1] == 2)//x:un y:sn
    {
        strcpy(a.numBody, x);
        a.flag = 1;
        a.length = strlen(x);
        return a;
    } else if (type[1] == 1 && type[0] == 2)//x:sn y:un
    {
        strcpy(b.numBody, y);
        b.flag = 1;
        b.length = strlen(y);
        return b;
    }
}

struct FloatBigNum unToFloat(int type[],char x[],char y[])//无符号转浮点 输出转换后的结构体
{
    struct FloatBigNum a, b;
    memset(a.integer, 0, sizeof(a.integer));
    memset(a.decimal, 0, sizeof(a.decimal));
    memset(b.integer, 0, sizeof(b.integer));
    memset(b.decimal, 0, sizeof(b.decimal));
    if (type[0] == 1 && type[1] == 3)//x:un y:fn
    {
        strcpy(a.integer, x);
        strcpy(a.decimal, "0");
        a.flag = 1;
        a.lengthInteger = strlen(x);
        a.lengthDecimal = 0;
        return a;
    } else if (type[1] == 1 && type[0] == 3)//x:fn y:un
    {
        strcpy(b.integer, y);
        strcpy(b.decimal, "0");
        b.flag = 1;
        b.lengthInteger = strlen(y);
        b.lengthDecimal = 0;
        return b;
    }
}

struct FloatBigNum snToFloat(int type[],char x[],char y[])//有符号转浮点 输出转换后的结构体
{
    struct FloatBigNum a, b;
    SignedBigNum c, d;
    UnsignedBigNum e, f;
    memset(c.numBody, 0, sizeof(c.numBody));
    memset(d.numBody, 0, sizeof(d.numBody));
    memset(e.numBody, 0, sizeof(e.numBody));
    memset(f.numBody, 0, sizeof(f.numBody));
    memset(a.integer, 0, sizeof(a.integer));
    memset(a.decimal, 0, sizeof(a.decimal));
    memset(b.integer, 0, sizeof(b.integer));
    memset(b.decimal, 0, sizeof(b.decimal));
    if (type[0] == 2 && type[1] == 3)//x:sn y:fn
    {
        c.flag = judgeSignedBigNum(x);
        a.flag = c.flag;
        e = removeSignedBigNumFlag(x);
        strcpy(a.integer, e.numBody);
        strcpy(a.decimal, "0");
        a.lengthInteger = strlen(e.numBody);
        a.lengthDecimal = 0;
        return a;
    } else if (type[1] == 2 && type[0] == 3)//x:fn y:sn
    {
        d.flag = judgeSignedBigNum(y);
        b.flag = d.flag;
        f = removeSignedBigNumFlag(x);
        strcpy(b.integer, f.numBody);
        strcpy(b.decimal, "0");
        b.lengthInteger = strlen(f.numBody);
        b.lengthDecimal = 0;
        return b;
    }
}