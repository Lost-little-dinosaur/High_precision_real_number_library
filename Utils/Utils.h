//
// Created by seulAuguestine on 2022/5/29.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_UTILS_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_UTILS_H

char addSignedBigNumFlag(struct SignedBigNum x);
int judgeFloatBigNum (char x[]);
int judgeSignedBigNum (char x[]);
struct UnsignedBigNum removeSignedBigNumFlag(char x[]);

void sepBigNumDe (char *x,char *ans);
void sepBigNumIn (char *x,char *ans);

int judgeOverflow(char num1[],char num2[]);
int *judgeType(char x[],char y[]);
struct FloatBigNum unToFloat(int type[],char x[],char y[]);
struct FloatBigNum snToFloat(int type[],char x[],char y[]);
struct SignedBigNum unToSigned(int type[],char x[],char y[]);

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_UTILS_H
