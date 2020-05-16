//
// Created by Carey on 2020/5/11.
//

#ifndef C_SQLIST_H
#define C_SQLIST_H

#include "../Common.h"
using namespace  Common;
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





/*  测试用例
 *      ElemType a[] { 6,3 ,5 ,4 ,9 ,1 ,8 ,2 ,7};

    SqList L ;
    InitList_Sq(L,a,8);
    PrintSqList(L);

    ListInsert_Sq(L, 4,5);
    PrintSqList(L);

    int ss;
    ListDelte_Sq(L, 5,ss);
    PrintSqList(L);
    cout<<ss<<endl;

    int cc = LocateElem_Sq(L,6,myCompare);
    cout <<cc<<endl;

    ElemType  b[] = {1,3, 5, 7,9};
    SqList Lb;
    InitList_Sq(Lb,b,5);
    PrintSqList(Lb);

    ElemType c[] = {2,4,6,8};
    SqList Lc;
    InitList_Sq(Lc,c,4);
    PrintSqList(Lc);

    SqList Ld;
    MergeList_Sq(Lb,Lc,Ld);
    PrintSqList(Ld);
 *
 *
 *
 *
 *
 */

#endif //C_SQLIST_H
