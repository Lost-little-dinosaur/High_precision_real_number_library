//
// Created by Dinosaur on 2022/5/27.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISION_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISION_H

#include "..\Model\struct.h"

//无符号整数除法
UnsignedBigNum DiviseUnsignedBigNum(UnsignedBigNum a,UnsignedBigNum b);

//有符号整数除法
SignedBigNum DiviseSignedBigNum(SignedBigNum a,SignedBigNum b);

//浮点数除法
FloatBigNum DiviseFloatBigNum(FloatBigNum a,FloatBigNum b);

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISION_H
