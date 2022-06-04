//
// Created by Dinosaur on 2022/5/27.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLICATION_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLICATION_H

struct UnsignedBigNum multiplyUnsignedBigNum(struct UnsignedBigNum a, struct UnsignedBigNum b);//无符号大数乘法

struct SignedBigNum multiplySignedBigNum(struct SignedBigNum a, struct SignedBigNum b);//无符号大数乘法

struct FloatBigNum multiplyFloatBigNum(struct FloatBigNum a, struct FloatBigNum b);//高精度实数大数乘法

struct UnsignedBigNum exponentiationUnsignedBigNum(struct UnsignedBigNum a, int power);//无符号大数求幂

struct SignedBigNum exponentiationSignedBigNum(struct SignedBigNum a, int power);//有符号大数求幂

struct FloatBigNum exponentiationFloatBigNum(struct FloatBigNum a, int power);//高精度实数求幂

struct UnsignedBigNum factorialUnsignedBigNum(int factorialNum);//阶乘函数

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLICATION_H
