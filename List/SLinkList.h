//
// Created by Carey on 2020/5/13.
//
// 静态单链表

#ifndef C_SLINKLIST_H
#define C_SLINKLIST_H

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

typedef int ElemType;


#define MAXSIZE 1000  //链表的最大长度
typedef struct {
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE];

// 静态单链线性表L中查找第一个值为e的元素
// 若找到，返回它在L中的位序， 否则返回0
int LocateElemL_SL(SLinkList S, ElemType e);

// 初始化 静态链表
void InitSpace_SL(SLinkList &space);

// 若备用空间链表非空， 则返回分配的结点下标， 否则返回0
int Malloc_SL(SLinkList &space);

// 将下标为k的空闲结点回收到备用链表
void Free_SL(SLinkList &space, int k);

// 求两集合的差集
void difference(SLinkList &space, int &S);




// 用数组 初始化 静态链表
void InitSLinkList(SLinkList &, const ElemType *, int);

// 向静态链表插入数据
// 在静态链表的第i个位置 插入元素e
void InsertSLinkList(SLinkList &L, int i, ElemType e);

// 静态链表插入

// 打印静态链表信息
//  切记 0号 为头  不存储数据！
void PrintSLinkList(SLinkList L);

#endif //C_SLINKLIST_H

//    cout<<YELLOW<<"用数组 初始化 静态链表："<<endl;
//    cout<<WHITE;
//    ElemType arr[] {1,2,3,4,5,6,7};
//    SLinkList L;
//    InitSLinkList(L,arr,7);
//    PrintSLinkList(L);