//
// Created by Carey on 2020/5/12.
//
//  顺序单链表


#ifndef C_LINKLIST_H
#define C_LINKLIST_H
#include "../Common.h"
using namespace  Common;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//获取单列表第i个元素
//L为带头结点的单链表的头指针
//当第i个元素存在时， 其值赋给e 并返回OK ,否则返回False
Status GetElem_L(LinkList L,int i, ElemType &e);

//在带头结点的单链表L中第i个位置之前插入元素e
Status ListInsert_L(LinkList & L, int i,ElemType e);

// 单链表删除结点
Status ListDelete_L(LinkList &L, int i, ElemType & e);

//逆位序输入n个元素的值，建立带头结点的单链线性表L
void CreateList_L(LinkList &L, int n);

// 归并两个单链表
void MergeList_L(LinkList &, LinkList &, LinkList &);

// 利用数组 初始化顺序单链表
 void Init_LinkList(LinkList &, ElemType* , int);

//打印链表信息
void PrintLinkList( LinkList & L);

#endif //C_LINKLIST_H



//******************************************************
//   从键盘读数据 创建单链表
//******************************************************
//    LinkList  L;
//    CreateList_L(L,5);
//    PrintLinkList(L);

//******************************************************
//   通过数组构建单链表
//******************************************************
//    ElemType arr[] {1,2,3,4,5,6,7,8,9};
//    LinkList L;
//    Init_LinkList(L, arr, 9);
//    PrintLinkList(L);

//******************************************************
//   获取第i个结点的元素
//******************************************************
//    ElemType  e;
//    GetElem_L(L,4,e);
//    cout<<e<<endl;

//******************************************************
//   两个单链线性表的归并
//******************************************************
//    ElemType A[] { 1, 3, 5, 7};
//    ElemType B[] { 2, 4, 6, 8};
//    LinkList La , Lb, Lc;
//    Init_LinkList(La,A,4);
//    Init_LinkList(Lb,B,4);
//    MergeList_L(La,Lb,Lc);
//    PrintLinkList(Lc);

//******************************************************
//   单链表 结点插入
//******************************************************
//    ElemType arr[] { 1, 2, 3, 4, 5, 6, 7};
//    LinkList L;
//    Init_LinkList(L,arr,7);
//    ElemType e = 44;
//    ListInsert_L(L, 5, e);
//    cout<<e<<endl;
//    PrintLinkList(L);

//******************************************************
//   单链表 结点删除
//******************************************************
//    ElemType  arr[] { 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    LinkList L;
//    Init_LinkList(L, arr,9);
//    PrintLinkList(L);
//    ElemType tem;
//    ListDelete_L(L,5,tem);
//    cout<<tem<<endl;
//    PrintLinkList(L);