//
// Created by Carey on 2020/5/14.
//  双向链表

#ifndef C_DULLINKLIST_H
#define C_DULLINKLIST_H
#include "../Common.h"
using namespace  Common;

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


//    //***********************************************************************
//    //  用数组 初始化 双向循环链表
//    //***********************************************************************
//    ElemType arr[] {1,2,3,4,5,6,7,8,9};
//    DuLinkList L;
//    InitDuLinkList(L, arr, 9);
//    PrintDuLinkList(L);
//    //***********************************************************************
//    //   双向循环链表 插入元素
//    //***********************************************************************
//    ListInsert_DuL(L, 12, 7);
//    PrintDuLinkList(L);
//    //***********************************************************************
//    //   双向循环链表 删除元素
//    //***********************************************************************
//    ElemType e;
//    ListDelete_DuL(L,3,e);
//    cout<<e<<endl;
//    PrintDuLinkList(L);