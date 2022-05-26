/*
* Created by sherlock on 25/5/2022
*/

/*
* 此文件实现无符号大数求余
*/
#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_MODSIGNEDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_MODSIGNEDBIGNUM_H

#include "basicdivise.h"
#include "..\Model\struct.h"

SignedBigNum ModSignedBigNum(SignedBigNum a,SignedBigNum b){
  SignedBigNum c;
  if(b.flag == 0)
  {
    strcpy(c.numBody,"除数不能为0！");
    c.length = 0;
    c.flag = 0;
    return c;
  }
  if(a.flag == 0 &&  b.flag != 0)
  {
     strcpy(c.numBody,"0");
     c.flag = 0;
     c.length = 1;
     return c;
  }
  strcpy(c.numBody,modulo(a.numBody,b.numBody));
  c.length = strlen(c.numBody);
  c.flag = a.flag;
  return c;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_MODSIGNEDBIGNUM_H
