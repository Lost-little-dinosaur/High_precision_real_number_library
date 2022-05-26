//
// Created by seulAuguestine on 2022/5/22.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_PLUSUNSIGNDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_PLUSUNSIGNDBIGNUM_H
#define MAXSIZE 500
#include <string.h>
#include "../Model/struct.h"


struct UnsignedBigNum plusUnsigndBigNum( struct UnsignedBigNum x, struct UnsignedBigNum y) {

    int a[MAXSIZE], b[MAXSIZE], result[MAXSIZE + 1];
    struct UnsignedBigNum r;
    int len1 = x.length, len2 = y.length, len3 = len1 > len2 ? len1 : len2;
    int i, j, k, m, n, flag = 0;
    for (i = len1 - 1, k = 0; i >= 0, k < len1; i--, k++)
    {
        a[k] = x.numBody[i] - '0';
    }
    for (j = len2 - 1, m = 0; j >= 0, m < len2; j--, m++) {
        b[m] = y.numBody[i] - '0';
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
    for (i1 = 0; n >= 0, i1 <= n2; n--, i1++) {
        r.numBody[i1] = result[n] + '0';
        //printf("%d", r[i1]);
    }
    return r;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_PLUSUNSIGNDBIGNUM_H
