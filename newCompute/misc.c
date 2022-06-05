//
// Created by Dinosaur on 2022/6/5.
//

#include "misc.h"
#include "compare.h"
#include "module.h"
#include "plus.h"
#include "division.h"
#include "multiplication.h"
#include <string.h>

void findPrimeNumbers(UnsignedBigNum a, UnsignedBigNum PrimeArr[MAXSIZE / 20]) {//MAXSIZE/20差不多是最多的质因数
    UnsignedBigNum b;
    long long i = 0;
    int flag;
    UnsignedBigNum tempOne;
    UnsignedBigNum tempNum;
    UnsignedBigNum tempA;

    tempOne.length = 1;
    tempOne.numBody[0] = '1';
    tempOne.numBody[1] = '\0';
    tempNum.flag = 1;
    tempNum.length = 1;
    tempNum.numBody[0] = '1';
    tempNum.numBody[1] = '\0';
    tempNum.flag = 1;

    b.length = 1;
    b.numBody[0] = '2';
    b.flag = 1;
    tempA = a;
//    tempA = DiviseUnsignedBigNum(a, b);//自动向下取整
//    tempA = plusUnsignedBigNum(tempA, tempOne);
    while (compareUnsignedBigNum(tempA, b) > 0) {
        flag = 0;
        tempNum.length = 1;
        tempNum.numBody[0] = '1';
        tempNum.numBody[1] = '\0';
        tempNum.flag = 1;
        while (compareUnsignedBigNum(b, tempNum) > 0) {
            if (ModUnsignedBigNum(b, tempNum).flag == 0 && (tempNum.numBody[0] != '1' || tempNum.length > 1)) {
                flag = 1;
                break;
            }
            tempNum = plusUnsignedBigNum(tempNum, tempOne);
        }
        if (flag == 0) {
            PrimeArr[i] = b;
            ++i;
        }
        b = plusUnsignedBigNum(b, tempOne);
    }

}

void findFactorNumbers(UnsignedBigNum a, UnsignedBigNum fillInArr[MAXSIZE / 20],
                       UnsignedBigNum PrimeArr[MAXSIZE / 20], int primeNum) {//MAXSIZE/20差不多是最多的质因数
    UnsignedBigNum b;
    long long i = 0;
    int flag = 0;
    UnsignedBigNum tempOne;
    UnsignedBigNum tempA;

    tempOne.length = 1;
    tempOne.numBody[0] = '1';
    tempOne.numBody[1] = '\0';
    tempOne.flag = 1;
    b.length = 1;
    b.numBody[0] = '2';
    b.flag = 1;
    tempA = DiviseUnsignedBigNum(a, b);//自动向下取整
    tempA = plusUnsignedBigNum(tempA, tempOne);
    while (compareUnsignedBigNum(tempA, b) > 0) {
        for (int j = 0; j < primeNum; ++j) {
            if (strcmp(PrimeArr[j].numBody, b.numBody) == 0) {
                if (ModUnsignedBigNum(a, b).flag == 0) {
                    fillInArr[i] = b;
                    ++i;
                }
            } else {
                continue;
            }
        }
        b = plusUnsignedBigNum(b, tempOne);
    }

}

void DecomposedPrimeFactor(UnsignedBigNum num, UnsignedBigNum fillInArr[MAXSIZE / 20], int factorNum) {
    UnsignedBigNum a, b, res;
    for (int i = 0; i < factorNum / 2; ++i) {
        a = fillInArr[i];
        for (int j = 0; j < factorNum; ++j) {
            b = fillInArr[j];
            res = multiplyUnsignedBigNum(a, b);
            if (strcmp(num.numBody, res.numBody) == 0) {
                printf("找到一个解：%s * %s = %s\n", a.numBody, b.numBody, res.numBody);
            }
        }
    }
}

void solveGoldbachConjecture(UnsignedBigNum num, UnsignedBigNum primeArr[MAXSIZE / 20], int primeNum) {
    UnsignedBigNum a, b, res;
    for (int i = 0; i < primeNum / 2; ++i) {
        a = primeArr[i];
        for (int j = 0; j < primeNum; ++j) {
            b = primeArr[j];
            res = plusUnsignedBigNum(a, b);
            if (strcmp(num.numBody, res.numBody) == 0) {
                printf("找到一个解：%s + %s = %s\n", a.numBody, b.numBody, res.numBody);
            }
        }
    }
}


void solveGoldbachConjectureAll(UnsignedBigNum num) {
    UnsignedBigNum b;
    UnsignedBigNum resArr[MAXSIZE / 20];
    UnsignedBigNum primeArr[MAXSIZE / 20];

    b.length = 1;
    b.numBody[0] = '2';
    b.numBody[1] = '\0';
    b.flag = 1;
    findPrimeNumbers(num, primeArr);
//    findPrimeNumbers(num, resArr);
    long primeNum = 0;
    long factorNum = 0;
    for (int i = 0; i < MAXSIZE / 20; ++i) {
        if (strcmp(primeArr[i].numBody, "") != 0) {
//            printf("%s\n", primeArr[i].numBody);
            ++primeNum;
        } else {
            break;
        }
    }
    printf("在小于等于%s的范围内一共找到%d个质数！\n", DiviseUnsignedBigNum(num, b).numBody, primeNum);

    solveGoldbachConjecture(num, primeArr, primeNum);
}

void DecomposedPrimeFactorAll(UnsignedBigNum a) {
    UnsignedBigNum b;
    UnsignedBigNum resArr[MAXSIZE / 20];
    UnsignedBigNum primeArr[MAXSIZE / 20];

    b.length = 1;
    b.numBody[0] = '2';
    b.numBody[1] = '\0';
    b.flag = 1;

    findPrimeNumbers(a, primeArr);
//    findPrimeNumbers(a, resArr);
    long primeNum = 0;
    long factorNum = 0;
    for (int i = 0; i < MAXSIZE / 20; ++i) {
        if (strcmp(primeArr[i].numBody, "") != 0) {
//            printf("%s\n", primeArr[i].numBody);
            ++primeNum;
        } else {
            break;
        }
    }
    printf("在小于等于%s的范围内一共找到%d个质数！\n", DiviseUnsignedBigNum(a, b).numBody, primeNum);

    findFactorNumbers(a, resArr, primeArr, primeNum);
    for (int i = 0; i < MAXSIZE / 20; ++i) {
        if (strcmp(resArr[i].numBody, "") != 0) {
            printf("%s\n", resArr[i].numBody);
            ++factorNum;
        } else {
            break;
        }
    }
    printf("在%d个质数里一共找到%d个质因数！\n", primeNum, factorNum);

}