//
// Created by Dinosaur on 2022/5/27.
//

#include "subtraction.h"
#include "string.h"
#include "plus.h"
#define MAXSIZE 500
#include "..\Model\struct.h"
#include "..\Utils\cmpUnsignedBigNum.h"

struct UnsignedBigNum subUnsignedBigNum (struct UnsignedBigNum x, struct UnsignedBigNum y) {
    int a[MAXSIZE], b[MAXSIZE], result[MAXSIZE + 1];
    struct UnsignedBigNum r;
    memset(r.numBody, 0, sizeof(r.numBody));
    int len1 = x.length, len2 = y.length, len3 = len1 > len2 ? len1 : len2;
    //printf("%d %d\n",len1,len2);
    int i, j, k, m, n, flag = 0, sign;
    sign = cmpUnsignedBigNum(x, y);
    //printf("sign=%d\n", sign);

    for (i = len1 - 1, k = 0; i >= 0, k < len1; i--, k++) {
        a[k] = x.numBody[i] - '0';
        //printf("%d ",a[k]);
    }
    //printf("%s",y.numBody);
    for (j = len2 - 1, m = 0; j >= 0, m < len2; j--, m++) {
        b[m] = y.numBody[j] - '0';
        //printf("%d ",b[m]);
    }//逆序放入两个数组

    /*for (int i = 0; i < len1; ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
    for (int j = 0; j < len2; ++j) {
        printf("%d", b[j]);
    }
    printf("\n");
*/
    if (len1 < len2) {
        for (i = len1; i < len2; ++i) {
            a[i] = 0;
        }
    } else {
        for (i = len2; i < len1; ++i) {
            b[i] = 0;
        }
    }//短的那个数补0
    /*for (int i = 0; i < len3; ++i) {
         printf("%d", a[i]);
     }
     printf("\n");
     for (int j = 0; j < len3; ++j) {
         printf("%d", b[j]);
     }*/
    //printf("%d ",len3);
    if (sign == 1) {
        for (i = 0; i < len3; i++) {
            a[i] -= flag;
            if (a[i] < b[i]) {
                a[i] += 10;
                flag = 1;
            } else
                flag = 0;
            result[i] = a[i] - b[i];
            //printf("\n%d=%d ",i,result[i]);
        }//逆序结果
    } else {
        for (i = 0; i < len3; ++i) {
            b[i] -= flag;
            if (a[i] > b[i]) {
                b[i] += 10;
                flag = 1;
            } else
                flag = 0;
            result[i] = b[i] - a[i];
            //printf("\n%d=%d ",i,result[i]);
        }
    }

    char tmp[1005];
    memset(r.numBody, 0, sizeof(r.numBody));
    for (i = len3 - 1; i >= 0 && result[i] == 0; --i);
    if (i >= 0) {
        for (j = 0; i >= 0, j < len3; --i, ++j) {
            tmp[j] = result[i] + '0';
            if (tmp[j] >= '0' && tmp[j] <= '9') {
                r.numBody[j] = tmp[j];
            }
            //printf("%c ", r.numBody[j]);
        }
    } else
        strcpy(r.numBody, "0");

    r.length = strlen(r.numBody);
    return r;
}
struct SignedBigNum subSignedBigNum(struct SignedBigNum x,struct SignedBigNum y) {
    //SigndBigNum b;
    //SigndBigNum a;
    struct SignedBigNum result;
    memset(result.numBody,0,sizeof(result.numBody));
    struct UnsignedBigNum c, d, e;
    strcpy(c.numBody, x.numBody);//方便后面无符号加法调用
    strcpy(d.numBody, y.numBody);
    c.length = strlen(x.numBody);
    d.length = strlen(y.numBody);
    //a.flag = x.flag;
    //b.flag = y.flag;
    if (x.flag == 1 && y.flag == 1) {//同+
        e = subUnsignedBigNum(c, d);
        strcpy(result.numBody, e.numBody);
        //printf("%s\n\n",e.numBody);
        if(cmpUnsignedBigNum(c,d)==1) {
            result.flag = 1;
        }
        else {
            result.flag = -1;
        }

        if (e.numBody == "0") {
            result.flag = 0;
        }
        result.length = strlen(result.numBody);
    } else if (x.flag == -1 && y.flag == -1) {//同-
        e = subUnsignedBigNum(c, d);
        strcpy(result.numBody, e.numBody);
        if(cmpUnsignedBigNum(c,d)==1) {
            result.flag = -1;
        }
        else {
            result.flag = 1;
        }
        if (e.numBody == "0")
            result.flag = 0;
        result.length = strlen(result.numBody);
    } else if (x.flag == 0) {//a为0
        strcpy(result.numBody, y.numBody);
        result.length = strlen(y.numBody);
        result.flag = y.flag*(-1);
    } else if (y.flag == 0) {//b为0
        strcpy(result.numBody, x.numBody);
        result.length = strlen(x.numBody);
        result.flag = x.flag;
    } else if (x.flag == 1 && y.flag == -1) {
        int sign;
        sign = cmpUnsignedBigNum(c, d);
        if (sign == 1) {
            result.flag = 1;
            e = plusUnsignedBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = -1;
            e = plusUnsignedBigNum(d, c);
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
            e = plusUnsignedBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = 1;
            e = plusUnsignedBigNum(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        }
    }
    return result;

}

struct FloatBigNum subFloatBigNum(FloatBigNum x,FloatBigNum y) {
    FloatBigNum r,y1;
    SignedBigNum ai, ad, bi, bd, ri, rd;
    int len, len2;
    len = x.lengthDecimal > y.lengthDecimal ? x.lengthDecimal : y.lengthDecimal;
    memset(y1.intager,0, sizeof(y1.intager));
    memset(y1.decimal,0, sizeof(y1.decimal));
    memset(r.intager,0, sizeof(r.intager));
    memset(r.decimal,0, sizeof(r.decimal));
    y1.flag=y.flag*(-1);

    strcpy(y1.intager,y.intager);
    strcpy(y1.decimal,y.decimal);
    y1.lengthDecimal=y.lengthDecimal;
    y1.lengthIntager=y.lengthIntager;
    r= plusFloatBigNum(x,y1);
    return r;
}