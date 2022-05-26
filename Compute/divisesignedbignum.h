#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISESIGNEDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISESIGNEDBIGNUM_H

#include "basicdivise.h"
#include "..\Model\struct.h"


SignedBigNum DiviseSignedBigNum(SignedBigNum a,SignedBigNum b){
  SignedBigNum c;
  c.flag = a.flag * b.flag;
  strcpy(c.numBody,divise(a.numBody,b.numBody));
  c.length = strlen(c.numBody);
  return c;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_DIVISESIGNEDBIGNUM_H
