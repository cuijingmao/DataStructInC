//
// Created by Carey on 2020/5/14.
//  双向链表

#ifndef C_DULLINKLIST_H
#define C_DULLINKLIST_H

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

//     线性表的双向链表存储结构 （带头结点）

typedef struct DuLNode{
    ElemType  data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, * DuLinkList;

// 用数组  初始化 一个 双向链表
Status InitDuLinkList(DuLinkList & L,  ElemType * arr, int n);

// 获取链表第i个结点
DuLNode* GetElemP_DuL(DuLinkList &L,int i);


// 在带头结点的双循环线性表L中第i个位置之前插入元素e
Status ListInsert_DuL(DuLinkList &L, int i, ElemType e);

// 双向循环链表 删除元素
// 删除带头结点的双联表L的第i个元素, i的合法值 1<=i<=表长
Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e);

// 获取双向链表长度
int  DuLinkListLength(DuLinkList L);


// 打印双向链表数据内容
void PrintDuLinkList(DuLinkList &L);


#endif //C_DULLINKLIST_H

//    cout<<YELLOW<<"用数组 初始化 双向循环链表："<<endl;
//    cout<<WHITE;
//    ElemType arr[] {1,2,3,4,5,6,7,8,9};
//    DuLinkList L;
//    InitDuLinkList(L, arr, 9);
//    PrintDuLinkList(L);
//
//    cout<<YELLOW<<"用数组 初始化 双向循环链表："<<endl;
//    cout<<WHITE;
//    ListInsert_DuL(L, 12, 7);
//    PrintDuLinkList(L);
//
//    cout<<YELLOW<<"双向循环链表 删除元素："<<endl;
//    cout<<WHITE;
//    ElemType e;
//    ListDelete_DuL(L,3,e);
//    cout<<e<<endl;
//    PrintDuLinkList(L);