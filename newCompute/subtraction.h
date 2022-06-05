//
// Created by Dinosaur on 2022/5/27.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_SUBTRACTION_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_SUBTRACTION_H

int cmpUnsignedBigNum(struct UnsignedBigNum x, struct UnsignedBigNum y);
struct UnsignedBigNum subUnsignedBigNum (struct UnsignedBigNum x, struct UnsignedBigNum y);
struct SignedBigNum subSignedBigNum(struct SignedBigNum x,struct SignedBigNum y);
struct FloatBigNum subFloatBigNum(struct FloatBigNum x,struct FloatBigNum y);

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_SUBTRACTION_H
