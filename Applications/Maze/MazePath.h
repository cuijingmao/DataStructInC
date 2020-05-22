//
// Created by Carey on 2020/5/17.
//  求解迷宫问题。

#ifndef C_MAZEPATH_H
#define C_MAZEPATH_H

// *************************************************************
// 以下是 辅助性的代码 非重点
// *************************************************************
#ifndef  MY_COMMON_BLOCK
#define  MY_COMMON_BLOCK

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace  std;

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define UNDERFLOW -3

typedef short Status;
#endif //MY_COMMON_BLOCK
// *************************************************************
// 以上是 辅助性的代码 非重点
// *************************************************************



#include <iostream>
#include <fstream>

#define MAZE_M 10     //  记得有两行围墙！故实际迷宫为 8*8
#define MAZE_N 10
struct mark{     //定义迷宫内点的坐标类型
    int x;
    int y;
};
static struct  mark  maze_default_start = {1,1};       // 迷宫默认入口
static struct  mark  maze_default_end = {MAZE_M -2,MAZE_N -2}; //迷宫默认出口
static int maze_true_path[(MAZE_M-2) * (MAZE_N -2)][2] = {0};    // 记录迷宫出宫 路径  记录每个结点的 x y


struct Element  // 链栈元素
{
    int x,y ;    //x行,y列
    int d;       //d下一步的方向   0、1、2、3分别对应 东西南北
};

typedef struct LStack  //链栈
{
    Element elem;
    struct LStack *next;
} *PLStack;


// 初始化空栈
int InitStack(PLStack &S);

// 判断栈是否为空
int StackEmpty(PLStack S);

// 压入新元素数据
int Push(PLStack &S, Element e);

// 栈顶元素初栈
int Pop(PLStack &S,Element &e);


//  建立迷宫
//void initmaze(int maze[M][N]);

//  从文件中读取迷宫矩阵
void  GetMazeFromFile(int maze[MAZE_M][MAZE_N]);

//  求迷宫路径函数
void MazePath(int maze[MAZE_M][MAZE_N],struct mark start = maze_default_start,
        struct mark end = maze_default_end, int [(MAZE_M-2) * (MAZE_N -2)][2] = maze_true_path);

// 打印迷宫路径
void  PrintMazePath(int maze[MAZE_M][MAZE_N], int arr[(MAZE_M-2) * (MAZE_N -2)][2] = maze_true_path);

#endif //C_MAZEPATH_H


//    cout<<YELLOW<<"基于栈的回溯方法求解迷宫问题："<<endl;
//    cout<<WHITE;
//    int sto[MAZE_M][MAZE_M];
//    GetMazeFromFile(sto);   //建立迷宫
//    MazePath(sto);  //  寻找路径
//    cout<<YELLOW<<"迷宫出路(0代表未走过的通路，1代表墙，2代表已走过的通路)："<<endl;
//    cout<<WHITE;
//    PrintMazePath(sto);