//
// Created by DELL on 2022/6/2.
//

#include "gui.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "../Model/struct.h"

#include "../newCompute/plus.h"
#include "../newCompute/subtraction.h"
#include "../newCompute/compare.h"
#include "../newCompute/division.h"
#include "../newCompute/module.h"
#include "../newCompute/multiplication.h"


#include<Windows.h>

struct SignedBigNum SignedtoStruct(char a[]);

struct UnsignedBigNum UnsignedtoStruct(char a[]);

struct FloatBigNum FloattoStruct(char a[]);


int Menu() {
    GotoXY(3, 2);
    printf("欢迎来到大数计算程序，请选择想要使用的功能：");

    GotoXY(3, 4);
    printf("1.加法");
    GotoXY(3, 6);
    printf("2.减法");
    GotoXY(3, 8);
    printf("3.乘法");
    GotoXY(3, 10);
    printf("4.除法");
    GotoXY(3, 12);
    printf("5.比较");
    GotoXY(3, 14);
    printf("其他任意键退出大数运算程序，感谢您的使用！");

    //退出功能如何实现？
//    Hide();
    int ch;
    int result = 0;
    ch = getch();//接收用户输入的菜单选项

    switch (ch) {
        case '1':
            result = 1;
            break;
        case '2':
            result = 2;
            break;
        case '3':
            result = 3;
            break;
        case '4':
            result = 4;
            break;

        default:
            result = 0;
            break;

    }
//    system("cls");//这句话啥意思来着：调用系统命令cls完成清屏操作
    return result;
}

void Hide() {

    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cor_info = {1, 0};//CONSOLE_CURSOR_INFO里面有光标大小和光标是否可见
    SetConsoleCursorInfo(hout, &cor_info);
}


void GotoXY(int x, int y) {
    HANDLE hout;
    COORD cor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = (short) x;
    cor.Y = (short) y;
    SetConsoleCursorPosition(hout, cor);

}


//关于菜单实现
void About() {
    GotoXY(30, 12);
    printf("杭州电子科技大学——程序设计综合实践案例");
    GotoXY(43, 14);
    printf("大数计算");
    GotoXY(43, 16);
    printf("按任意键返回上级菜单");
    Hide();
    int ch = _getch();
    system("cls");

}

//帮助菜单实现
void Help() {
    GotoXY(40, 12);
    printf("w 上");
    GotoXY(40, 14);
    printf("s 下");
    GotoXY(40, 16);
    printf("a 左");
    GotoXY(40, 18);
    printf("d 右");
    GotoXY(40, 20);
    printf("当蛇撞墙或撞到自身时游戏结束");
    printf("a 左");
    GotoXY(40, 22);
    printf("按任意键返回上级菜单");
    Hide();
    //  int ch=_getch();
    system("cls");
}

void ScanfCheck(int result) {
    //sleep(2);
    printf(" hahahha");
    //sleep(2);
    printf("%d", result);
    sleep(3);
    int flag = 0, *type;
    UnsignedBigNum returnUB;
    SignedBigNum returnSB;
    FloatBigNum returnFB;
    char num1[MAXSIZE * 10] = "0", num2[MAXSIZE * 10] = "0";
    GotoXY(0, 0);
    printf("请输入第一个大数：");
    scanf("%s", &num1);
    GotoXY(10, 0);
    printf("请输入第二个大数：");
    scanf("%s", &num2);
    system("cls");
    flag = judgeOverflow(num1, num2);
    //printf("%d", flag);
    if (flag == -1) {
        GotoXY(0, 0);
        printf("ERROR!超过数据范围！\n 按任意键返回上级菜单");
        system("cls");
    }


    //printf("%d %d",type[0],type[1]);
    int *plus = judgeType(num1, num2);
    if (plus[0] != plus[1]) {
        GotoXY(0, 0);
        printf("ERROR!前后数据类型不一致！\n 按任意键返回上级菜单 ");
        system("cls");

    } else if (plus[0] == plus[1] == 1) {//无符号
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
        }
        /*}else if(result==5){
            char[]m =compareSignedBigNum(x, y);
        }*/

        printf("%s", returnUB.numBody);


    } else if (plus[0] == 2 && plus[1] == 2) {//有符号
        SignedBigNum x = SignedtoStruct(num1);
        SignedBigNum y = SignedtoStruct(num2);
        if (result == 1) {
            returnSB = plusSignedBigNum(x, y);
        } else if (result == 2) {
            returnSB = subSignedBigNum(x, y);
        } else if (result == 3) {
            returnSB = multiplySignedBigNum(x, y);
        } else if (result == 4) {
            returnSB = DiviseSignedBigNum(x, y);
        }
        /*}else if(result==5){
            char[]m =compareSignedBigNum(x, y);
        }*/
        if (returnSB.flag == -1) {
            printf("-");
        }
        printf("%s", returnSB.numBody);

    } else if (plus[0] == 3 && plus[1] == 3) {//浮点数
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
        }
        /*}else if(result==5){
            char[]m =compareSignedBigNum(x, y);
        }*/
        if (returnFB.flag == -1) {
            printf("-");
        }
        printf("%s.%s", returnFB.integer, returnFB.decimal);
    }
}

struct SignedBigNum SignedtoStruct(char a[]) {

    SignedBigNum x;
    UnsignedBigNum c;
    x.flag = judgeSignedBigNum(a);
//printf("flag=%d %d\n",x.flag,y.flag);
    x.length = strlen(a) - 1;
    c = removeSigndBigNumFlag(a);
    strcpy(x.numBody, c.numBody);
    return x;
}


struct UnsignedBigNum UnsignedtoStruct(char a[]) {
    UnsignedBigNum x;
    strcpy(x.numBody, a);
    x.length = strlen(a);
    if (a = "0") {
        x.flag = 0;
    } else {
        x.flag = 1;
    }
    return x;
}

struct FloatBigNum FloattoStruct(char a[]) {

    FloatBigNum x;
    scanf("%s", &a);
    strcpy(x.integer, sepBigNumIn(a));
    strcpy(x.decimal, sepBigNumDe(a));
    x.lengthInteger = strlen(x.integer);
    x.lengthDecimal = strlen(x.decimal);
    //      strcpy(y.integer, sepBigNumIn(b));
    //      strcpy(y.Decimal, sepBigNumOut(b));
    /*x.intager[MAXSIZE]=sepBigNumIn(a);
    y.intager[MAXSIZE]sepBigNumIn(b);
    x.decimal[MAXSIZE]=sepBigNumDe(a);
    y.decimal[MAXSIZE]=sepBigNumDe(b);
     */
    x.flag = judgeFloatBigNum(a);
    return x;

}


