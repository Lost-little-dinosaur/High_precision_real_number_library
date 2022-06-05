//
// Created by seulAuguestine on 2022/5/29.
//
#include "..\Model\struct.h"
#include "string.h"
#include "Utils.h"
#include "IncludeZero.h"

#include "..\newCompute\plus.h"

/*int cmpUnsignedBigNum(UnsignedBigNum x, UnsignedBigNum y) {//有符号数符号一致时简单比较
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
*/
struct UnsignedBigNum IncludeZero (struct UnsignedBigNum x, struct UnsignedBigNum y) {//无符号减法不去掉前导0，方便浮点运算
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

    if (len1 < len2) {
        for (i = len1; i < len2; ++i) {
            a[i] = 0;
        }
    } else {
        for (i = len2; i < len1; ++i) {
            b[i] = 0;
        }
    }//短的那个数补0

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
    for (int i = 0,j=len3-1; i < len3,j>=0; ++i,--j) {
        r.numBody[i]=result[j]+'0';
        //printf("%c",r.numBody[i]);
    }

    r.length = strlen(r.numBody);
    return r;
}
struct SignedBigNum IncludeZeroSPlus(struct SignedBigNum x,struct SignedBigNum y) {//有符号加法不去掉前导0

    struct SignedBigNum result;
    memset(result.numBody,0,sizeof(result.numBody));
    struct UnsignedBigNum c, d, e;//result不带符号
    strcpy(c.numBody, x.numBody);//方便后面无符号加法调用
    strcpy(d.numBody, y.numBody);
    c.length = strlen(x.numBody);
    d.length = strlen(y.numBody);

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
            e = IncludeZero(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = -1;
            e =IncludeZero(c, d);
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
            e =IncludeZero(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        } else {
            result.flag = 1;
            e =IncludeZero(c, d);
            if (e.numBody == "0")
                result.flag = 0;
            strcpy(result.numBody, e.numBody);
            result.length = strlen(result.numBody);
        }
    }
    return result;

}
struct SignedBigNum IncludeZeroSignedSub(struct SignedBigNum x,struct SignedBigNum y) {//有符号减法不去掉前导0
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
        e = IncludeZero(c, d);
        strcpy(result.numBody, e.numBody);
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
        e = IncludeZero(c, d);
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