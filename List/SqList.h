//
// Created by Carey on 2020/5/11.
// 顺序线性表

#ifndef C_SQLIST_H
#define C_SQLIST_H

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

#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMEMNT 10   //线性表存储空间的分配增量

typedef struct {
    ElemType  *elem;
    int length;   //当前长度
    int listsize;  //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

static Status myCompare(ElemType a, ElemType b){
    if(a==b)
        return OK;
    else
        return FALSE;
}

//初始化线性表
Status InitList_Sq(SqList &L);

//用含n个元素的数组 初始化线性表
// 要提供
Status InitList_Sq(SqList &L, const ElemType* data, int n);

//线性表插入
Status ListInsert_Sq(SqList &L, int i, ElemType e);

// 线性表删除
Status ListDelte_Sq(SqList & L, int i, ElemType &e);

//顺序线性表查找
//在顺序线性表L中查找第一个值与e满足compare()的元素的位序
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType,ElemType));

//有序顺序表合并
//已知顺序线性表La和Lb的元素按值非递减排列
//归并La和Lb得到新的顺序表Lc,Lc的元素也非递减排列
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);




//打印线性表信息
void PrintSqList(SqList &L);

#endif //C_SQLIST_H

//    cout<<YELLOW<<"使用数组初始化 顺序线性表："<<endl;
//    cout<<WHITE;
//    ElemType a[] { 6,3 ,5 ,4 ,9 ,1 ,8 ,2 ,7};
//    SqList L ;
//    InitList_Sq(L,a,8);
//    PrintSqList(L);
//
//    cout<<YELLOW<<"第4个位置插入5："<<endl;
//    cout<<WHITE;
//    ListInsert_Sq(L, 4,5);
//    PrintSqList(L);
//
//    cout<<YELLOW<<"删除第5个元素："<<endl;
//    cout<<WHITE;
//    int ss;
//    ListDelte_Sq(L, 5,ss);
//    PrintSqList(L);
//    cout<<ss<<endl;
//
//    cout<<YELLOW<<"查找第一个9所在位置："<<endl;
//    cout<<WHITE;
//    int cc = LocateElem_Sq(L,9,myCompare);
//    cout <<cc<<endl;
//
//    cout<<YELLOW<<"两顺序线性表归并："<<endl;
//    cout<<WHITE;
//    ElemType  b[] = {1,3, 5, 7,9};
//    SqList Lb;
//    InitList_Sq(Lb,b,5);
//    PrintSqList(Lb);
//
//    ElemType c[] = {2,4,6,8};
//    SqList Lc;
//    InitList_Sq(Lc,c,4);
//    PrintSqList(Lc);
//
//    SqList Ld;
//    MergeList_Sq(Lb,Lc,Ld);
//    PrintSqList(Ld);