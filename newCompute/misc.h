 //
// Created by Dinosaur on 2022/6/5.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_MISC_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_MISC_H

#include "..\Model\struct.h"

//void findFactorNumbers(UnsignedBigNum a, UnsignedBigNum fillInArr[MAXSIZE / 20], UnsignedBigNum PrimeArr[MAXSIZE / 20],
//                       int primeNum);//找到所有质因数

void DecomposedPrimeFactorAll(UnsignedBigNum a);//分解质因数

void solveGoldbachConjectureAll(UnsignedBigNum num);//验证哥德巴赫猜想

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_MISC_H
