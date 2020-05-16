//
// Created by Carey on 2020/5/14.
// 从实用角度 重新定义 线性链表
// 带头、尾结点的线性链表

#ifndef C_LINKLISTPOLY_H

#include "../Common.h"
using namespace  Common;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} *Link, *Position;

typedef struct {     //链表类型
    Link head, tail;    //分别指向线性表中的头结点 和 最后一个结点
    int len;            //指示线性表中数据元素的个数
} LinkList;

int compare(ElemType a, ElemType b);



// 分配由p指向的值为e的结点， 并返回OK; 若分配失败,则返回ERROR
Status MakeNode( Link &p, ElemType e);

// 释放p所指结点
void FreeNode(Link &p);

// 构造一个空的线性链表L
Status InitList(LinkList &);

// 销毁线性链表L,L不再存在
Status DestroyList(LinkList &L);

// 将线性表L重置为空表, 并释放原链表的结点空间
Status ClearList(LinkList &L);

// 已知h指向线性链表的头结点， 将s所指结点插入在第一个结点之前
Status InsFirst(Link h, Link s);

// 已知h指向线性链表的头结点， 删除链表中的第一个结点并以q返回
Status DelFirst(Link h, Link &q);

// 将指针s所指的一串结点链接在线性表L的最后一个结点之后，
//并改变链表L的尾指针指向新的尾结点
Status Append(LinkList & L, Link s);

// 删除线性链表L中的尾结点并以q返回，
// 改变链表L的尾指针指向新的尾结点
Status Remove(LinkList& L,Link &q);

// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前
// 并修改指针p指向新插入的结点
Status InsBefore(LinkList &L, Link& p,Link s);

// 已知p指向线性链表L中的一个节点，将s所指结点插入在p所指结点之后,
// 并修改指针p指向新插入的结点
Status InsAfter(LinkList &L, Link &p, Link s);

// 已知p指向线性表中的一个结点， 用e更新p所指结点中数据元素的值
Status SetCurElem(Link & p, ElemType e);

// 已知p指向线性链表中的一个结点， 返回p所指结点中数据元素的值
ElemType GetCurElem(Link p);

// 若线性链表L为空表，则返回TRUE，否则返回FALSE
Status ListEmpty(LinkList L);

// 返回线性链表中L中元素个数
int ListLength(LinkList L);

// 返回线性链表的头结点的位置
Position  GetHead(LinkList L);

// 返回线性链表L中最后一个节点的位置
Position GetLast(LinkList L);

// 已知p指向线性链表L中的一个节点， 返回p所指结点的直接前驱的位置
// 若无前驱， 则返回NULL
Position PriorPos(LinkList L, Link p);

// 已知p指向线性链表L中的一个节点， 返回p所指结点的直接后继的位置
// 若无后继，则返回NULL
Position NextPos(LinkList L, Link &p);

// 返回p 指示线性链表L中第i个结点的位置并返回ok, i不合法时返回ERROR;
Status LocatePos(LinkList L,int i,Link & p );

// 返回线性链表L中第1个与e满足函数ompare()判定关系的元素的位置
// 若不存在这样的元素，则返回NULL
Position LocateElem(LinkList L, ElemType e, Status (*compare) (ElemType, ElemType));

//依次对L的每个元素调用函数 visit(). 一旦Visit()失败，则操作失败
Status ListTraverse(LinkList L, Status (*visit)());

// 在带头结点的单链线性表L的第i个元素之前插入元素e
Status ListInsert_L(LinkList  &L, int i, ElemType e);

// 使用数组 初始化线性链表
Status InitLinkListH(LinkList &L, ElemType * arr, int n);

// 已知单链表La和Lb的元素 按值非递减排列
// 归并La和Lb得到新的单链表Lc, Lc的元素也按值非递减
Status MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc, int(*compare)(ElemType, ElemType));

// 打印 带头结点的线性链表
void PrintLinkListH(LinkList L);

#endif //C_LINKLISTPOLY_H



//******************************************************
//  使用数组初始化  线性列表
//******************************************************
//    ElemType arr[] {1,2,3,4};
//    LinkList L;
////    InitList(L);
//    cout<<YELLOW<<"用数组初始化线性链表:"<<endl;
//    cout<<WHITE;
//    InitLinkListH(L, arr, 4);
//    PrintLinkListH(L);
//
////    DestroyList(L);
////    ClearList(L);
//    cout<<YELLOW<<"将新结点插入到第一个结点之前："<<endl;
//    cout<<WHITE;
//    Link s = (Link) malloc(sizeof(LNode));
//    s->data =8;
//    InsFirst(L.head,s);
//    L.len ++;
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"删除第一个结点："<<endl;
//    cout<<WHITE;
//    Link q;
//    DelFirst(L.head, q);
//    L.len --;
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"附加结点串： "<<endl;
//    cout<<WHITE;
//    s->data = 7;
//    Link tem = (Link) malloc(sizeof(Link));
//    tem->data = 12;
//    s->next=tem;
//    Append(L, s);
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"删除尾结点： "<<endl;
//    cout<<WHITE;
//    Remove(L,q);
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"在指定结点前插入： "<<endl;
//    cout<<WHITE;
//    Link tem1,tem2;
//    tem1 = L.head->next->next->next;
//    tem2 = (Link) malloc(sizeof(LNode));
//    tem2->data=11;
//    InsBefore(L, tem1,tem2 );
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"在指定结点之后插入： "<<endl;
//    cout<<WHITE;
//    Link tem3,tem4;
//    tem3 = L.head->next->next->next;
//    tem4 = (Link) malloc(sizeof(LNode));
//    tem4->data= 16;
//    InsAfter(L, tem3,tem4 );
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"更新结点数据： "<<endl;
//    cout<<WHITE;
//    SetCurElem(L.head->next->next->next, 23);
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"获取指定结点数据： "<<endl;
//    cout<<WHITE;
//    ElemType e;
//    e = GetCurElem(L.head->next->next->next->next->next);
//    PrintLinkListH(L);
//    cout<<e<<endl;
//
//    cout<<YELLOW<<"判断列表是否为空： "<<endl;
//    cout<<WHITE;
//    PrintLinkListH(L);
//    cout<<ListEmpty(L)<<endl;
//
//    cout<<YELLOW<<"返回列表长度： "<<endl;
//    cout<<WHITE;
//    PrintLinkListH(L);
//    cout<<ListLength(L)<<endl;
//
//    cout<<YELLOW<<"获取前驱结点： "<<endl;
//    cout<<WHITE;
//    Link tem5,tem6;
//    tem5 = L.head->next->next->next;
//    tem6 = PriorPos(L,tem5);
//    cout<<"当前结点数据为： "<<tem5->data<< " 前驱结点数据为："<< tem6->data<<endl;
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"获取后继结点： "<<endl;
//    cout<<WHITE;
//    Link tem7,tem8;
//    tem7 = L.head->next->next->next;
//    tem8 = NextPos(L,tem5);
//    cout<<"当前结点数据为： "<<tem7->data<< " 后继结点数据为："<< tem8->data<<endl;
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"获取指定位次结点： "<<endl;
//    cout<<WHITE;
//    Link tem9;
//    LocatePos(L,6,tem9);
//    cout<<"第6个结点数据为： "<<tem9->data<<endl;
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"在指定位次结点前插入结点： "<<endl;
//    cout<<WHITE;
//    cout<<"在第5个结点位置前插入数据17: "<<endl;
//    ListInsert_L(L,5,17);
//    PrintLinkListH(L);
//
//    cout<<YELLOW<<"两非递减线性列表归并： "<<endl;
//    cout<<WHITE;
//    LinkList La,Lb,Lc;
//    InitList(Lc);
//    ElemType a[] {1, 3,5,7,7,9};
//    ElemType b[] {2,4,6,6,8};
//    InitLinkListH(La,a,6);
//    InitLinkListH(Lb,b, 5);
//    PrintLinkListH(La);
//    PrintLinkListH(Lb);
//    MergeList_L(La,Lb,Lc,compare);
//    cout<<"归并后: "<<endl;
//    PrintLinkListH(Lc);