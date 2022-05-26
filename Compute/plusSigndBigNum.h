//
// Created by seulAuguestine on 2022/5/26.
//
#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_PLUSSIGNDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_PLUSSIGNDBIGNUM_H
#define MAXSIZE 500
#include <string.h>
#include<stdio.h>
#include"plusUnsigndBigNum.h"
#include "subUnsigndBigNum.h"
struct SigndBigNum {//有符号大整数
    int length;//表示数据的位数
    char numBody[MAXSIZE];//表示数据主体
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

struct SigndBigNum plusSigndBigNum(struct SigndBigNum x,struct SigndBigNum y) {
    //SigndBigNum b;
    //SigndBigNum a;
    struct SigndBigNum result;
    memset(result.numBody,0,sizeof(result.numBody));
    struct UnsigndBignNum c, d, e;//result不带符号
    strcpy(c.numBody, x.numBody);//方便后面无符号加法调用
    strcpy(d.numBody, y.numBody);
    c.length = strlen(x.numBody);
    d.length = strlen(y.numBody);
    //a.flag = x.flag;
    //b.flag = y.flag;
    if (x.flag == 1 && y.flag == 1) {//同+
        e = plusUnsigndBigNum(c, d);
        strcpy(result.numBody, e.numBody);
        printf("%s\n",e.numBody);

        result.flag = 1;
        result.length = strlen(result.numBody);
    } else if (x.flag == -1 && y.flag == -1) {//同-
        e = plusUnsigndBigNum(c, d);
        strcpy(result.numBody, e.numBody);
        result.flag = -1;
        result.length = strlen(result.numBody);
    } else if (x.flag == 0) {//a为0
        strcpy(result.numBody, y.numBody);
        result.length = strlen(y.numBody);
        result.flag = y.flag;
    } else if (y.flag == 0) {//b为0
        strcpy(result.numBody, x.numBody);
        result.length = strlen(x.numBody);
        result.flag = x.flag;
    } else if (x.flag == 1 && y.flag == -1) {
        int sign;
        sign = cmpUnsigndBigNum(c, d);
        if (sign == 1) {
            result.flag = 1;
            e = subUnsigndBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = -1;
            e = subUnsigndBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        }
    } else if (x.flag == -1 && y.flag == 1) {
        int sign;
        sign = cmpUnsigndBigNum(c, d);
        if (sign == 1) {
            result.flag = -1;
            e = subUnsigndBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = 1;
            e = subUnsigndBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        }
    }
    return result;

}

char addSigndBigNumFlag(struct SigndBigNum x)
{
    char f=' ';
    if(x.flag==1)
    {
        f='+';
    }
    else if(x.flag==-1)
    {
        f='-';
    }
    return f;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_PLUSSIGNDBIGNUM_H
