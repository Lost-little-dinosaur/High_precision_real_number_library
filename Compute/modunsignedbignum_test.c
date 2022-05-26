#include "modunsignedbignum.h"

int main(){
  UnsignedBigNum a,b,c;
  scanf("%s%s",a.numBody,b.numBody);
  c = ModUnsignedBigNum(a,b);
  printf("c length = %d,c = %s",c.length,c.numBody);
}
