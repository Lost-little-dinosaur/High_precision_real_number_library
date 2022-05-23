#include<stdio.h>
#include<string.h>
int main()
{
char Num1[10000];
char Num2[10000];

scanf("%s %s",Num1,Num2);
/* check1(Num1);
check2(Num2);*/
int length1=Scanf(Num1);
int length2=Scanf(Num2);
calculate(Num1,Num2);
return 0;
}

/*void check1(char num1[]){
int len=strlen(num1);
int i;
for(i=0; i<len; i++){
if((num1[i]<0||num1[i]>9)&&num1[i]!="."){
printf("输入格式有误,请重新输入第一个大数\n");
scanf("%s",num1);
len=strlen(num1);}
}
}
void check2(char num2[]){
int len=strlen(num2);
int i;
for(i=0; i<len; i++){
if((num2[i]<0||num2[i]>9)&&num2[i]!="."){
printf("输入格式有误,请重新输入第二个大数\n");
scanf("%s ",num2);
len=strlen(num2);}
}


}
*/
int Scanf (char num[])
{
int len=strlen(num);
int i;
for(i=0; i<len; i++)
if(num[i]=='.')
break;
return i;
}
void calculate(char num1[],char num2[])
{
int length1=Scanf(num1);
int length2=Scanf(num2);
if(length1>length2){
printf("第一个数大于第二个数\n");}
else if(length1<length2){
printf("第二个数大于第一个数\n");}
else if(length1=length2){
zhuwei(num1,num2,length1);
}
}


int zhuwei(char num1[],char num2[],int length)
{
int i,j;
for(i=0; i<length; i++)
{
if(num1[i]!=num2[i])
break;
}
int sum=num1[i]-num2[i];
if(sum>0){
printf("第一个数大于第二个数\n");
}
else if(sum<0){
printf("第二个数大于第一个数\n");
}
else if(sum=0){
printf("两数相等\n");
}
}
#include<stdio.h>
#include<string.h>
int gps(char num[])//找到小数点所在的位置
{
int len=strlen(num);
int i;
for(i=0; i<len; i++)
if(num[i]=='.')
break;
return i;
}
int cmp1(char num1[],char num2[])//比较小数点的大小
{
int len=gps(num1);
return strcmp(num1+len,num2+len);
}
int cmp(char num1[],char num2[],int len)//比较大数的大小
{
int i;
for(i=0; i<len; i++)
{
if(num1[i]!=num2[i])
break;
}
int sum=num1[i]-num2[i];
if(i!=len)
return sum;
return 0;
}
/*int main()
{
char num1[10000];
char num2[10000];
while(scanf("%s %s",num1,num2)!=EOF)
{
int len1=gps(num1);
int len2=gps(num2);
if(len1>len2)
printf("1\n");
else if(len1<len2)
printf("-1\n");
else if(cmp(num1,num2,len1)>0)
printf("1\n");
else if(cmp(num1,num2,len2)<0)
printf("-1\n");
else if(cmp1(num1,num2)>0)
printf("1\n");
else if(cmp1(num1,num2)<0)
printf("-1\n");
else
printf("0\n");
}
}
*/
