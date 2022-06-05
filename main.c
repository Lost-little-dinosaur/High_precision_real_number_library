#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>
#include<Windows.h>
#include "GUI\gui.h"
#include <stdlib.h>

#include "newCompute\compare.h"
#include "newCompute\division.h"
#include "newCompute\module.h"
#include "newCompute\multiplication.h"
#include "newCompute\plus.h"
#include "newCompute\subtraction.h"

int width = 50, height = 30;

int test() {
    int choise;
    start:
    system("cls");
    GotoXY(2 * (width / 3), height / 3);
    printf("欢迎来到贪吃蛇小游戏！\n\n");
    GotoXY(2 * (width / 3), height / 2);
    printf("1：开始游戏\n");
    GotoXY(2 * (width / 3), height / 2 + 2);
    printf("2：系统设置\n");
    GotoXY(2 * (width / 3), height / 2 + 4);
    printf("3：退出\n");
    GotoXY(2 * (width / 3), height / 2 + 6);
    printf("请输入您的选择(1/2/3)：\n");
    while (1) {
        choise = getch(); //读取键值
        if (choise == 49) {
            return 1;
        } else if (choise == 50) {
            return 2;
        } else if (choise == 51) {
            return 3;
        } else {
            printf("输入错误，请重新输入...");
            Sleep(300);
            goto start;
        }

    }
}

int main() {
    system("chcp 65001");
    int flag=test();
    printf("%d ",flag);

    ScanfCheck(flag);


//    //防止控制台输出乱码
//    system("chcp 65001");
//    start:
//    srand((unsigned int) time(0));
//    int end = 1, result;
//    while (end) {
//        result = Menu();
//        if (result != 0) {
//            sleep(2);
//            ScanfCheck(result);
//            break;
//        } else {
//
//            printf("输入错误，请重新输入...");
//            Sleep(300);
//            goto start;
//
//        }
    return 0;
}