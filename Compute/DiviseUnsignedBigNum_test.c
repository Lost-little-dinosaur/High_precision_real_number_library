#include "diviseunsignedbignum.h"
#include "..\Model\struct.h"

int main(){
  UnsignedBigNum a,b,c;
  scanf("%s%s",a.numBody,b.numBody);
  c = DiviseUnsignedBigNum(a,b);
  printf("c length = %d,c = %s",c.length,c.numBody);
  a.flag = 0;
  c = DiviseUnsignedBigNum(a,b);
  printf("c length = %d,c = %s",c.length,c.numBody);
}
