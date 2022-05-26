/*
*Created by sherlock on 23/5/2022
*/

/*
*此文件用于basicdivise的测试
*/

#include "basicdivise.h"

int main()
{
  char a[10001],b[10001],ans[10001],remindor[10001];
  scanf("%s%s",a,b);
  strcpy(ans,divise(a,b));
  printf("ans = %s\n",ans);
  strcpy(remindor,modulo(a,b));
  printf("remindor = %s\n",remindor);
  return 0;
}
