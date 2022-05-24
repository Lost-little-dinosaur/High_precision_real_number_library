#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISEUNSIGNEDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISEUNSIGNEDBIGNUM_H

#include "basicdivise.h"
#include "..\Model\struct.h"


UnsigndBigNum DiviseUnsignedBigNum(UnsigndBigNum a,UnsigndBigNum b){
  UnsigndBigNum c;
  strcpy(c.numBody,divise(a.numBody,b.numBody));
  c.length = strlen(c.numBody);
  return c;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISEUNSIGNEDBIGNUM_H
/*
SigndBigNum DiviseSignedBigNum(SigndBigNum a,SigndBigNum b){
  SigndBigNum c;
  c.flag = a.flag * b.flag;
  strcpy(c.numBody,divise(a.numBody,b.numBody));
  c.length = strlen(c.numBody);
  return c;
}

FloatBigNum DivisFloatBigNum(FloatBigNum a,FloatBigNum b){
  FloatBigNum c;
  c.flag =  a.flag * b.flag;

}
*/
/*
int main(){
  UnsigndBignNum a;
  UnsigndBignNum b;
  scanf("%s%s",a.numBody,b.numBody);
  UnsigndBignNum c;
  c = DiviseUnsignedBignNum(a,b);
  printf("%s",c.numBody);
}
*/
