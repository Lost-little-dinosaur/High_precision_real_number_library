#include "divisesignedbignum.h"
#include "..\Model\struct.h"

int main(){
  SignedBigNum a,b,c;
  scanf("%s%s",a.numBody,b.numBody);
  a.flag = 1;
  b.flag = 1;
  c = DiviseSignedBigNum(a,b);
  printf("c length = %d,c = %d %s",c.length,c.flag,c.numBody);
  a.flag = 1;
  b.flag = -1;
  c = DiviseSignedBigNum(a,b);
  printf("c length = %d,c = %d %s",c.length,c.flag,c.numBody);
}
