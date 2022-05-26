//
// Created by seulAuguestine on 2022/5/25.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_SUBUNSIGNDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_SUBUNSIGNDBIGNUM_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 500
#include "..\Model\struct.h"

int cmpUnsignedBigNum(struct UnsignedBigNum x, struct UnsignedBigNum y){
    int flag;
    if(x.length>y.length)
        flag= 1;
    else if(x.length==y.length) {
        if(strcmp(x.numBody,y.numBody)>=0)
            flag=1;
        else
            flag=0;
    }
    else
        flag=0;

    return flag;
}
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

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_SUBUNSIGNDBIGNUM_H
