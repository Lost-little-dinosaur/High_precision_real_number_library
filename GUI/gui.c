//
// Created by DELL on 2022/6/2.
//

#include "gui.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include<conio.h>
#include "../Model/struct.h"

#include "../newCompute/plus.h"
#include "../newCompute/subtraction.h"
#include "../newCompute/compare.h"
#include "../newCompute/division.h"
#include "../newCompute/module.h"
#include "../newCompute/multiplication.h"
#include "../newCompute/misc.h"

#include<Windows.h>

struct SignedBigNum SignedtoStruct(char a[]);

struct UnsignedBigNum UnsignedtoStruct(char a[]);

struct FloatBigNum FloattoStruct(char a[]);


void ScanfCheck(int result) {//第一步：进行检查和输入两个数
    /* //sleep(2);
     printf(" hahahha");
     //sleep(2);
     //printf("%d", result);
     sleep(3);*/
    system("cls");
    int flag = 0, *type;

    UnsignedBigNum returnUB;
    SignedBigNum returnSB;
    FloatBigNum returnFB;
    char num1[MAXSIZE * 10] = "0", num2[MAXSIZE * 10] = "0";

    printf("请输入第一个大数：");
    scanf("%s", &num1);

    printf("请输入第二个大数：");
    scanf("%s", &num2);
    if(num1[0]=='+'&&num2[0]!='+'&&num2[0]!='-'||num1[0]=='-'&&num2[0]!='+'&&num2[0]!='-')
    {
        strcpy(num2+1,num2);
        num2[0]='+';
    }
    if(num2[0]=='+'&&num1[0]!='+'&&num1[0]!='-'||num2[0]=='-'&&num1[0]!='+'&&num1[0]!='-')
    {
        strcpy(num1+1,num1);
        num1[0]='+';
    }
    printf("已接受输入");

    flag = judgeOverflow(num1, num2);

    printf("%d", flag);
    if (flag == -1) {
        printf("稍等片刻\n");
        printf("ERROR!超过数据范围！\n 按任意键返回上级菜单");
        system("cls");
    }

//第一种情况：两个数类型不一样

    //printf("%d %d",type[0],type[1]);
    int *plus = judgeType(num1, num2);
    if (plus[0] != plus[1]) {
//        GotoXY(0, 0);
        printf("稍等片刻\n");


        printf("ERROR!前后数据类型不一致！\n  ");

        printf("\n按任意键返回上级菜单\n");
        sleep(1);
        char ch = _getch();
        system("cls");



        //第二种情况，两个数都是无符号数


    } else if (plus[0] == 1 && plus[1] == 1) {//无符号
        UnsignedBigNum x = UnsignedtoStruct(num1);
        UnsignedBigNum y = UnsignedtoStruct(num2);
        if (result == 1) {
            returnUB = plusUnsignedBigNum(x, y);
        } else if (result == 2) {
            returnUB = subUnsignedBigNum(x, y);
        } else if (result == 3) {
            returnUB = multiplyUnsignedBigNum(x, y);
        } else if (result == 4) {
            returnUB = DiviseUnsignedBigNum(x, y);
        } else if (result == 5) {//返回的东西不一样！！！！！！！
            int B = compareUnsignedBigNum(x, y);
            if (B >= 0) {
                returnUB = x;
            } else {
                returnUB = y;

            }
        } else if (result == 6) {
            int power = atoi(num2);
            returnUB = exponentiationUnsignedBigNum(x, power);//无符号大数求幂*/
        } else if (result == 7) {
            int factorialNum = atoi(num1);
            factorialUnsignedBigNum(factorialNum);

        } else if (result == 8) {//求余
            returnUB = ModUnsignedBigNum(x, y);
        } else if (result == 9) {//

//！！！！！！！            它和下面的那个函数其实应该只需要输入一个数的

            solveGoldbachConjectureAll(x);//验证哥德巴赫猜想
            solveGoldbachConjectureAll(y);
        } else if (result == 10) {
            DecomposedPrimeFactorAll(x);//分解质因数9
            DecomposedPrimeFactorAll(y);//分解质因数
        }
        /*}else if(result==5){
            char[]m =compareSignedBigNum(x, y);
        }*/
        printf("\n");

        printf("%s\n", returnUB.numBody);
        printf("\n按任意键返回上级菜单\n");
        sleep(1);
        char ch = _getch();
        system("cls");


    }

        //都是有符号整数的情况


    else if (plus[0] == 2 && plus[1] == 2) {//有符号
        SignedBigNum x = SignedtoStruct(num1);
        SignedBigNum y = SignedtoStruct(num2);
        x.numBody[x.length] = '\0';
        y.numBody[y.length] = '\0';
        if (result == 1) {
            returnSB = plusSignedBigNum(x, y);
        } else if (result == 2) {
            returnSB = subSignedBigNum(x, y);
        } else if (result == 3) {
            returnSB = multiplySignedBigNum(x, y);
        } else if (result == 4) {
            returnSB = DiviseSignedBigNum(x, y);
        } else if (result == 5) {
            int B = compareSignedBigNum(x, y);
            if (B >= 0) {
                returnSB = x;
            } else {
                returnSB = y;
            }
        } else if (result == 6) {
            returnSB = multiplySignedBigNum(x, y);
        } else if (result == 7) {
            int power = atoi(num2);
            returnSB = exponentiationSignedBigNum(x, power);
        } else if (result == 8) {//求余
            returnSB = ModSignedBigNum(x, y);
        }
/*}else if(result==5){
    char[]m =compareSignedBigNum(x, y);
}*/


        printf("\n");
        if (returnSB.flag == -1) {
            printf("-");
        }
        printf("%s", returnSB.numBody);

        printf("按任意键返回上级菜单");
        sleep(1);
        char ch = _getch();
        system("cls");
        //   printf("\n3秒后返回原界面");

    }


        //最后一种，浮点数的情况



    else if (plus[0] == 3 && plus[1] == 3) {//浮点数
        if(num1[0]!='+'&&num1[0]!='-'){
            strcpy(num1+1,num1);
            num1[0]='+';
        }
        if(num2[0]!='+'&&num2[0]!='-'){
            strcpy(num2+1,num2);
            num2[0]='+';
        }
        FloatBigNum x = FloattoStruct(num1);
        FloatBigNum y = FloattoStruct(num2);

        if (result == 1) {
            returnFB = plusFloatBigNum(x, y);
        } else if (result == 2) {
            returnFB = subFloatBigNum(x, y);
        } else if (result == 3) {
            returnFB = multiplyFloatBigNum(x, y);
        } else if (result == 4) {
            returnFB = DiviseFloatBigNum(x, y);
        } else if (result == 5) {
            int B = compareFloatBigNum(x, y);
            if (B >= 0) {
                returnFB = x;
            } else {
                returnFB = y;
            }
        } else if (result == 7) {
            int power = atoi(num2);
            returnFB = exponentiationFloatBigNum(x, power);
        }


        if (returnFB.flag == -1) {
            printf("-");
        }
        printf("打印一下");
        printf("%s.%s", returnFB.integer, returnFB.decimal);

        printf("按任意键返回上级菜单");
        sleep(1);
        char ch = _getch();
        system("cls");
    }
}
void gdbh()
{
    system("cls");

    char num1[MAXSIZE * 10] = "0";

    printf("请输入一个大整数：");
    scanf("%s", &num1);
    UnsignedBigNum x = UnsignedtoStruct(num1);
    solveGoldbachConjectureAll(x);
    printf("\n");

    printf("按任意键返回上级菜单");
    sleep(1);
    char ch = _getch();
    system("cls");
}
void jc()
{
    system("cls");

    char num1[MAXSIZE * 10] = "0";

    printf("请输入一个大整数：");
    scanf("%s", &num1);
    int factorialNum = atoi(num1);
    UnsignedBigNum x =factorialUnsignedBigNum(factorialNum);
    printf("\n%s\n",x.numBody);

    printf("按任意键返回上级菜单");
    sleep(1);
    char ch = _getch();
    system("cls");
}
struct SignedBigNum SignedtoStruct(char a[]) {

    SignedBigNum x;
    UnsignedBigNum c;
    x.flag = judgeSignedBigNum(a);
//printf("flag=%d %d\n",x.flag,y.flag);
    x.length = strlen(a) - 1;
    c = removeSignedBigNumFlag(a);
    strcpy(x.numBody, c.numBody);
    return x;
}


struct UnsignedBigNum UnsignedtoStruct(char a[]) {
    UnsignedBigNum x;
    strcpy(x.numBody, a);
    x.length = strlen(a);
    if (strcmp(a, "0") == 0) {
        x.flag = 0;
    } else {
        x.flag = 1;
    }
    return x;
}

struct FloatBigNum FloattoStruct(char a[]) {

    FloatBigNum x;
//    scanf("%s", &a);
    sepBigNumIn(a, x.integer);
    sepBigNumDe(a,x.decimal);
    x.lengthInteger = strlen(x.integer);
    x.lengthDecimal = strlen(x.decimal);

    x.flag = judgeFloatBigNum(a);
    return x;

}


