//
// Created by DELL on 2022/5/17.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_GUI_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_GUI_H

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_GUI_H

#include <windows.h>//相当于C语言中的#include<stdio.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInst;   //HINSTANCE 是“句柄型”数据类型。---------

int WINAPI WinMain(//这一段约等于int main（）{

        HINSTANCE hInstance,   //实例句柄 instance handle

        HINSTANCE hPrevInstance, //win32下为NULL

        PSTR szCmdLine,//用来运行程序的命令行

        int iCmdShow//用来指明程序最初如何显示。(最大化到全屏，正常显示，最小化到任务栏)。

){

    static TCHAR szClassName[] = TEXT("Win32Demo");  //窗口类名

    HWND     hwnd;  //窗口句柄

    MSG      msg;  //消息

    WNDCLASS wndclass;  //窗口类

    hInst = hInstance;   //------------

    /**********第①步：注册窗口类**********/

    //为窗口类的各个字段赋值



    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //窗口风格:⑴CS_HREDRAW：一旦移动或尺寸调整使客户区的宽度发生变化，就重新绘制窗口； ⑵CS_VREDRAW：一旦移动或尺寸调整使客户区的高度发生变化，就重新绘制窗口。

    wndclass.lpfnWndProc  = WndProc;  //窗口过程

    wndclass.cbClsExtra   = 0;  //暂时不需要理解

    wndclass.cbWndExtra   = 0;  //暂时不需要理解

    wndclass.hInstance    = hInstance;  //当前窗口句柄

    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //窗口图标

    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //鼠标样式

    wndclass.hbrBackground= (HBRUSH) GetStockObject (GRAY_BRUSH);;  //窗口背景画刷（白色）

    wndclass.lpszMenuName = NULL ;  //窗口菜单

    wndclass.lpszClassName= szClassName;  //窗口类名

    //注册窗口

    RegisterClass(&wndclass);

    /*****第②步：创建窗口(并让窗口显示出来)*****/

    hwnd = CreateWindow(

            szClassName,  //窗口名字

            TEXT("大数计算Ｏ(≧▽≦)Ｏ "),  //窗口标题（出现在标题栏）

            WS_OVERLAPPEDWINDOW,  //窗口风格

            CW_USEDEFAULT,  //初始化时x轴的位置

            CW_USEDEFAULT,  //初始化时y轴的位置

            730,  //窗口宽度

            500,  //窗口高度

            NULL,  //父窗口句柄

            NULL,  //窗口菜单句柄

            hInstance,  //当前窗口的句柄

            NULL  //不使用该值

    );

    //显示窗口

    ShowWindow (hwnd, iCmdShow);

    //更新（绘制）窗口

    UpdateWindow (hwnd);





    /**********第③步：消息循环**********/

    while( GetMessage(&msg, NULL, 0, 0) ){

        TranslateMessage(&msg);  //翻译消息

        DispatchMessage (&msg);  //分派消息

    }

    return msg.wParam;

}

/**********第④步：消息循环**********/

//------------

LRESULT CALLBACK WndProc(

        HWND hWnd,

        UINT message,

        WPARAM wParam,

        LPARAM lParam

){

    int wmId, wmEvent;

    PAINTSTRUCT ps;

    HDC hdc;

    static HFONT hFont;

    static HWND hBtn1;
    static HWND hBtn2;
    static HWND hBtn3;
    static HWND hBtn4;

    static HWND hStatic;

    switch (message){

        case  WM_CREATE:

            //创建逻辑字体

            hFont = CreateFont(

                    -15/*高度*/, -7.5/*宽度*/, 0, 0, 400 /*一般这个值设为400*/,

                    FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,

                    DEFAULT_CHARSET,  //使用默认字符集

                    OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管

                    DEFAULT_QUALITY,  //默认输出质量

                    FF_DONTCARE,  //不指定字体族*/

                    TEXT("楷体")  //字体名

            );

            //创建静态文本控件

            hStatic = CreateWindow(

                    TEXT("static"),  //静态文本框的类名

                    TEXT("                   你好，欢迎来到大数计算应用程序，你想使用的功能是？"),  //控件的文本

                    WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | WS_BORDER /*带边框*/,

                    30 /*X坐标*/, 20/*Y坐标*/, 600/*宽度*/, 40/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)1,  //为控件指定一个唯一标识符

                    hInst,  //当前实例句柄

                    NULL

            );

            //创建按钮控件1

            hBtn1 = CreateWindow(

                    TEXT("button"), //按钮控件的类名

                    TEXT("加法"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    30 /*X坐标*/, 110 /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,

                    hWnd, (HMENU)2 /*控件唯一标识符*/, hInst, NULL

            );

            SendMessage(hStatic,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体

            SendMessage(hBtn1, WM_SETFONT, (WPARAM)hFont, NULL);//设置按钮字体

            //break;

            //创建按钮控件2

            hBtn2 = CreateWindow(

                    TEXT("button"), //按钮控件的类名

                    TEXT("减法"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    200 /*X坐标*/, 110 /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,

                    hWnd, (HMENU)2 /*控件唯一标识符*/, hInst, NULL

            );

            SendMessage(hStatic,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体

            SendMessage(hBtn2, WM_SETFONT, (WPARAM)hFont, NULL);//设置按钮字体


            hBtn3 = CreateWindow(

                    TEXT("button"), //按钮控件的类名

                    TEXT("乘法"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    370 /*X坐标*/, 110 /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,

                    hWnd, (HMENU)2 /*控件唯一标识符*/, hInst, NULL

            );

            SendMessage(hStatic,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体

            SendMessage(hBtn3, WM_SETFONT, (WPARAM)hFont, NULL);//设置按钮字体


            hBtn4 = CreateWindow(

                    TEXT("button"), //按钮控件的类名

                    TEXT("除法"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    540 /*X坐标*/, 110 /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,

                    hWnd, (HMENU)2 /*控件唯一标识符*/, hInst, NULL

            );

            SendMessage(hStatic,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体

            SendMessage(hBtn4, WM_SETFONT, (WPARAM)hFont, NULL);//设置按钮字体

            break;






        case WM_COMMAND:

            wmId    = LOWORD(wParam);

            wmEvent = HIWORD(wParam);

            switch (wmId){

                case 2:  //按下按钮

                    //更改文本框的内容

                    SetWindowText(hStatic, TEXT("你点击了下面的按钮"));

                    break;

                default:

                    //不处理的消息一定要交给 DefWindowProc 处理。

                    return DefWindowProc(hWnd, message, wParam, lParam);

            }

            break;

        case WM_PAINT:

            hdc = BeginPaint(hWnd, &ps);

            // TODO:  在此添加任意绘图代码...

            EndPaint(hWnd, &ps);

            break;

        case WM_DESTROY:

            //请做好善后工作

            DeleteObject(hFont);

            PostQuitMessage(0);

            break;

        default:

            return DefWindowProc(hWnd, message, wParam, lParam);

    }

    return 0;

}

