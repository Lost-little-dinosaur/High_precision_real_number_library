//
// Created by hang on 2022/6/2.
//

#ifndef TEST_COMPARE_H
#define TEST_COMPARE_H

#include <stdio.h>
#include "..\Model\struct.h"

char* cmp_removezero(char x[]);
int int_compare(char a[],char b[]);
int float_compare(char a[],char b[]);

int compareUnsignedBigNum(UnsignedBigNum a,UnsignedBigNum b);

int compareSignedBigNum(SignedBigNum a,SignedBigNum b);

int compareFloatBigNum(FloatBigNum a,FloatBigNum b);


#endif //TEST_COMPARE_H
