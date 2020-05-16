//
// Created by Carey on 2020/5/13.
//
// 静态单链表

#ifndef C_SLINKLIST_H
#define C_SLINKLIST_H

#include "../Common.h"
using namespace  Common;

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





//***********************************************************************
//  用数组 初始化 静态链表
//***********************************************************************
//    ElemType arr[] {1,2,3,4,5,6,7};
//    SLinkList L;
//    InitSLinkList(L,arr,7);
//    PrintSLinkList(L);