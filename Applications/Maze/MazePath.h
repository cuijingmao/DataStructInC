//
// Created by Carey on 2020/5/17.
//  求解迷宫问题。

#ifndef C_MAZEPATH_H
#define C_MAZEPATH_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../../Common.h"
using namespace  std;
#define M 10     //  记得有两行围墙！
#define N 10


struct mark{     //定义迷宫内点的坐标类型
    int x;
    int y;
};

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
void  GetMazeFromFile(int maze[M][N]);

//  求迷宫路径函数
void MazePath(struct mark start, struct mark end, int maze[M][N]);

#endif //C_MAZEPATH_H


//int sto[M][N];
//struct  mark  start, end;   // start, end 为入口和出口的坐标
//GetMazeFromFile(sto);   //建立迷宫
//start.x = 1;
//start.y =1;
//end.x = 8;
//end.y = 8;
//MazePath(start,end,sto);  //  寻找路径