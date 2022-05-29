//
// Created by seulAuguestine on 2022/5/29.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_UTILS_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_UTILS_H

char addSignedBigNumFlag(struct SignedBigNum x);
int cmpUnsignedBigNum(struct UnsignedBigNum x, struct UnsignedBigNum y);
int judgeFloatBigNum (char x[]);
int judgeSignedBigNum (char x[]);
struct UnsignedBigNum removeSigndBigNumFlag(char x[]);
char  *sepBigNumDe (char *x);
char  *sepBigNumIn (char *x);

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_UTILS_H
