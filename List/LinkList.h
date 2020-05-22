//
// Created by Carey on 2020/5/12.
//
//  顺序单链表


#ifndef C_LINKLIST_H
#define C_LINKLIST_H

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

//    cout<<YELLOW<<"从键盘读5个数据 创建单链表："<<endl;
//    cout<<WHITE;
//    LinkList  L;
//    CreateList_L(L,5);
//    PrintLinkList(L);
//
//    cout<<YELLOW<<"通过数组构建单链表："<<endl;
//    cout<<WHITE;
//    ElemType arr[] {5,2,1,6,4,8,7,3,9};
//    LinkList L1;
//    Init_LinkList(L1, arr, 9);
//    PrintLinkList(L1);
//
//    cout<<YELLOW<<"获取第4个结点的元素："<<endl;
//    cout<<WHITE;
//    ElemType  e;
//    GetElem_L(L1,4,e);
//    cout<<e<<endl;
//
//    cout<<YELLOW<<"两个单链线性表的归并："<<endl;
//    cout<<WHITE;
//    ElemType A[] { 1, 3, 5, 7};
//    ElemType B[] { 2, 4, 6, 8};
//    LinkList La , Lb, Lc;
//    Init_LinkList(La,A,4);
//    PrintLinkList(La);
//    Init_LinkList(Lb,B,4);
//    PrintLinkList(Lb);
//    cout<<YELLOW<<"归并结果："<<endl;
//    cout<<WHITE;
//    MergeList_L(La,Lb,Lc);
//    PrintLinkList(Lc);
//
//    cout<<YELLOW<<"单链表 结点插入："<<endl;
//    cout<<WHITE;
//    ElemType arr2[] { 1, 2, 3, 4, 5, 6, 7};
//    LinkList L2;
//    Init_LinkList(L2,arr2,7);
//    PrintLinkList(L2);
//    cout<<YELLOW<<"在第5个位置插入44："<<endl;
//    cout<<WHITE;
//    ElemType e2 = 44;
//    ListInsert_L(L2, 5, e2);
//    cout<<e<<endl;
//    PrintLinkList(L2);
//
//    cout<<YELLOW<<"单链表 结点删除："<<endl;
//    cout<<WHITE;
//    ElemType  arr3[] { 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    LinkList L3;
//    Init_LinkList(L3, arr3,9);
//    PrintLinkList(L3);
//    ElemType tem;
//    ListDelete_L(L3,5,tem);
//    cout<<tem<<endl;
//    PrintLinkList(L3);

