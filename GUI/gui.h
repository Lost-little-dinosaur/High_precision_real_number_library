#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include "..\Model\struct.h"
#include "..\Utils\Utils.h"
int ScanfCheck() {
    int flag = 0,*type;
    char num1[MAXSIZE * 10] = "0", num2[MAXSIZE * 10] = "0";
    printf("请输入第一个大数：");
    scanf("%s", &num1);
    printf("请输入第二个大数：");
    scanf("%s", &num2);
    flag = judgeOverflow(num1,num2);
    //printf("%d", flag);
    if (flag == -1) {
        printf("ERROR!超过数据范围！\n 按任意键返回上级菜单");
        return 0;
    }
    type= judgeType(num1,num2);
    printf("%d %d",type[0],type[1]);
    if(type[0]!=type[1])
        printf("ERROR!前后数据类型不一致！\n 按任意键返回上级菜单 ");
    printf("");
    return type;
}




void GotoXY(int,int);
int Menu();
void Help();
void About();


void Help(){
    GotoXY(40,12);
    printf("w 上");
    GotoXY(40,14);
    printf("s 下");
    GotoXY(40,16);
    printf("a 左");
    GotoXY(40,18);
    printf("d 右");
    GotoXY(40,20);
    printf("当蛇撞墙或撞到自身时游戏结束");
    printf("a 左");
    GotoXY(45,22);
    printf("按任意键返回上级菜单");
//    Hide();
    char ch=_getch();
    system("cls");

}
int Menu(){
    GotoXY(3,2);
    printf("欢迎来到大数计算程序，请选择想要使用的功能：");

    GotoXY(3,4);
    printf("1.加法");
    GotoXY(3,6);
    printf("2.减法");
    GotoXY(3,8);
    printf("3.乘法");
    GotoXY(3,10);
    printf("4.除法");
    GotoXY(3,12);
    printf("5.比较");
    GotoXY(3,14);
    printf("其他任意键退出大数运算程序，感谢您的使用！");

    //退出功能如何实现？
    //Hide();
    char ch;
    int result = 0;
    ch=_getch();//接收用户输入的菜单选项
    switch(ch){
        case'1':result=1;break;
        case'2':result=2;break;
        case'3':result=3;break;
    }
    system("cls");//这句话啥意思来着：调用系统命令cls完成清屏操作
    return result;
}

void GotoXY(int x,int y){
    HANDLE hout;
    COORD cor;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X=x;
    cor.Y=y;
    SetConsoleCursorPosition(hout,cor) ;

}

//关于菜单实现
void About(){
    GotoXY(30,12);
    printf("杭州电子科技大学——程序设计综合实践案例");
    GotoXY(43,14);
    printf("大数计算");
    GotoXY(43,16);
    printf("按任意键返回上级菜单");
//    Hide();
    char ch = _getch();
    system("cls");

}


