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
#include "..\Model\struct.h"

struct SignedBigNum plusSignedBigNum(struct SignedBigNum x,struct SignedBigNum y) {
    //SigndBigNum b;
    //SigndBigNum a;
    struct SignedBigNum result;
    memset(result.numBody,0,sizeof(result.numBody));
    struct UnsignedBigNum c, d, e;//result不带符号
    strcpy(c.numBody, x.numBody);//方便后面无符号加法调用
    strcpy(d.numBody, y.numBody);
    c.length = strlen(x.numBody);
    d.length = strlen(y.numBody);
    //a.flag = x.flag;
    //b.flag = y.flag;
    if (x.flag == 1 && y.flag == 1) {//同+
        e = plusUnsignedBigNum(c, d);
        strcpy(result.numBody, e.numBody);
        printf("%s\n",e.numBody);

        result.flag = 1;
        result.length = strlen(result.numBody);
    } else if (x.flag == -1 && y.flag == -1) {//同-
        e = plusUnsignedBigNum(c, d);
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
        sign = cmpUnsignedBigNum(c, d);
        if (sign == 1) {
            result.flag = 1;
            e = subUnsignedBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = -1;
            e = subUnsignedBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        }
    } else if (x.flag == -1 && y.flag == 1) {
        int sign;
        sign = cmpUnsignedBigNum(c, d);
        if (sign == 1) {
            result.flag = -1;
            e = subUnsignedBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = 1;
            e = subUnsignedBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        }
    }
    return result;

}

char addSignedBigNumFlag(struct SignedBigNum x)
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
