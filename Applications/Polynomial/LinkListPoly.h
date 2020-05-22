//
// Created by Carey on 2020/5/14.
// 从实用角度 重新定义 线性链表
// 带头、尾结点的线性链表

#ifndef C_LINKLISTPOLY_H
#define C_LINKLISTPOLY_H

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

//using namespace  Polynomial;
namespace  LinkListPoly{             // 为了避免函数定义冲突   此处必须使用命名空间
    typedef struct ElemType{  // 项的表示， 多项式的项作为LinkList的数据元素
        float coef;  // 系数
        int expn;    //指数
        ElemType& operator=(ElemType e){
            coef = e.coef;
            expn = e.expn;
            return *this;
        };

    } term, ElemType;  // 两个类型名: term用于本ADT，ElemType为LinkList的数据对象名
    typedef struct LNode{
        ElemType data;
        struct LNode *next;
//        LNode& operator=(LNode e){
//            data = e.data;
//            next = e.next;
//            return *this;
//        }
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

}


#endif //C_LINKLISTPOLY_H

