//
// Created by seulAuguestine on 2022/5/28.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_INCLUDEZERO_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_INCLUDEZERO_H

struct UnsignedBigNum IncludeZero (struct UnsignedBigNum x, struct UnsignedBigNum y);
struct SignedBigNum IncludeZeroSPlus(struct SignedBigNum x,struct SignedBigNum y);
struct SignedBigNum IncludeZeroSignedSub(struct SignedBigNum x,struct SignedBigNum y);
int cmpUnsignedBigNum_IZ(UnsignedBigNum x, UnsignedBigNum y);
#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_INCLUDEZERO_H
