//
// Created by Dinosaur on 2022/5/27.
//


#include "../Model/struct.h"
#include <stdio.h>
#include <string.h>
#include "subtraction.h"
#include "..\Utils\IncludeZero.h"
#include "plus.h"
#include "..\Utils\Utils.h"

struct UnsignedBigNum plusUnsignedBigNum(struct UnsignedBigNum x, struct UnsignedBigNum y) {

    int a[MAXSIZE], b[MAXSIZE], result[MAXSIZE + 1];
    struct UnsignedBigNum r;
    memset(r.numBody, 0, sizeof(r.numBody));
    int len1 = x.length, len2 = y.length, len3 = len1 > len2 ? len1 : len2;
    int i, j, k, m, n, flag = 0;
    for (i = len1 - 1, k = 0; i >= 0, k < len1; i--, k++) {
        a[k] = x.numBody[i] - '0';
    }
    for (j = len2 - 1, m = 0; j >= 0, m < len2; j--, m++) {
        b[m] = y.numBody[j] - '0';
    }
    /*for (int i = 0; i < len1; ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
    for (int j = 0; j < len2; ++j) {
        printf("%d", b[j]);
    }
    printf("\n");*/
    if (len1 < len2) {
        for (int i = len1; i < len2; ++i) {
            a[i] = 0;
        }
    } else {
        for (int i = len2; i < len1; ++i) {
            b[i] = 0;
        }
    }
    /*for (int i = 0; i < len3; ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
    for (int j = 0; j < len3; ++j) {
        printf("%d", b[j]);
    }*/

    for (n = 0; n < len3; ++n) {
        result[n] = (a[n] + b[n] + flag) % 10;
        flag = (a[n] + b[n] + flag) / 10;
        //printf("%d ",flag);
    }
    //printf("\n%d ",n);
    result[n] = (a[n - 1] + b[n - 1] + flag) / 10;
    if (result[n] == 0) {
        n = n - 1;
    }
    int i1, n2;
    n2 = n;
    r.length = 0;
    for (i1 = 0; n >= 0, i1 <= n2; n--, i1++) {
        r.numBody[i1] = result[n] + '0';
        ++r.length;
        //printf("%d", r[i1]);
    }
    return r;
}

struct SignedBigNum plusSignedBigNum(struct SignedBigNum x, struct SignedBigNum y) {
    //SigndBigNum b;
    //SigndBigNum a;
    struct SignedBigNum result;
    memset(result.numBody, 0, sizeof(result.numBody));
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
        //printf("%s\n",e.numBody);

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

struct FloatBigNum plusFloatBigNum(FloatBigNum x, FloatBigNum y) {
    FloatBigNum r;
    SignedBigNum ai, ad, bi, bd, ri, rd;
    int len, len2;
    len = x.lengthDecimal > y.lengthDecimal ? x.lengthDecimal : y.lengthDecimal;
    strcpy(ad.numBody, x.decimal);
    strcpy(ai.numBody, x.integer);
    strcpy(bd.numBody, y.decimal);
    strcpy(bi.numBody, y.integer);
    ad.flag = x.flag;
    ai.flag = x.flag;
    bd.flag = y.flag;
    bi.flag = y.flag;
    ri = plusSignedBigNum(ai, bi);
    len2 = strlen(ri.numBody);
    rd = IncludeZeroSPlus(ad, bd);
    if (rd.length == len + 1)//小数相加有进位到整数部分
    {
        SignedBigNum bit;
        bit.flag = 1;
        bit.length = 1;
        strcpy(bit.numBody, "1");
        ri = plusSignedBigNum(ri, bit);
    }
    strcpy(r.integer, ri.numBody);
    r.lengthInteger = strlen(r.integer);
    r.flag = ri.flag;
    if (rd.length == len + 1)//小数相加有进位到整数部分
    {
        for (int i = 0, j = 1; i < len, j < rd.length; ++i, ++j) {
            r.decimal[i] = rd.numBody[j];
        }
    } else {
        strcpy(r.decimal, rd.numBody);
    }
    r.lengthDecimal = strlen(r.decimal);
    return r;
}