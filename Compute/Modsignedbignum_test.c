#include "modsignedbignum.h"

int main(){
  SignedBigNum a,b,c;
  scanf("%s%s",a.numBody,b.numBody);
  a.flag = 1;
  b.flag = 1;
  c = ModSignedBigNum(a,b);
  printf("c length = %d \na %% b = %d %s",c.length,c.flag,c.numBody);
  a.flag = 1;
  b.flag = -1;
  c = ModSignedBigNum(a,b);
  printf("c length = %d \na %% b = %d %s",c.length,c.flag,c.numBody);
  a.flag = -1;
  b.flag = 1;
  c = ModSignedBigNum(a,b);
  printf("c length = %d \na %% b = %d %s",c.length,c.flag,c.numBody);
  a.flag = 0;
  b.flag = 1;
  c = ModSignedBigNum(a,b);
  printf("c length = %d \na %% b = %d %s",c.length,c.flag,c.numBody);
  a.flag = 1;
  b.flag = 0;
  c = ModSignedBigNum(a,b);
  printf("c length = %d \na %% b = %d %s",c.length,c.flag,c.numBody);
}
