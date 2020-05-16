//
// Created by Carey on 2020/5/12.
//

#include<stdio.h>
#include "LinkList.h"

//获取单列表第i个元素
//L为带头结点的单链表的头指针
//当第i个元素存在时， 其值赋给e 并返回OK ,否则返回False
Status GetElem_L(LinkList L,int i, ElemType &e){
    auto p = L->next; auto j=1;   //初始化时，p指向第一个结点，j为计数器
    while(p && j < i) {   //顺时针向后查找， 直到p指向第i个元素或p为空
        p = p->next; j++;

    }
    if(!p|| j>i) return ERROR;  //第i个元素不存在
    e = p->data;    //取第i个元素
    return OK;
}//GetElem_L

//在带头结点的单链表L中第i个位置之前插入元素e
Status ListInsert_L(LinkList & L, int i,ElemType e){
    auto p =L; auto j = 0;
    while(p &&  j <i-1){ //寻找第i-1个结点
        p=p->next; ++j;
    }
    if(!p || j>i-1) return ERROR;     // i小于1或者大于表长+1
    auto s =(LinkList) malloc(sizeof(LNode));  //生成新结点
    s->data = e; s->next = p->next;  //插入L中
    p->next = s;   //头插法
    return OK;
}

// 单链表删除结点
// 在带头结点的单链表L中, 删除第i个元素， 并由e返回其值
Status ListDelete_L(LinkList &L, int i, ElemType & e){
    LNode* p = L; int j=0;
    while(p->next && j<i-1){ //寻找第i个结点, 并令p指向其前驱
        p = p->next;
        ++j;
    }
    if(!(p->next) || j>i+1) return ERROR;
    LNode* q = p->next;
    p->next = q ->next;
    e = q->data;
    free(q);
    return OK;
}//ListDelete_L

//逆位序输入n个元素的值，建立带头结点的单链线性表L
void CreateList_L(LinkList &L, int n){
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;    //先建立一个带头结点的单链表
    for(int i =n; i>0; --i){
        auto p = (LinkList) malloc(sizeof(LNode)); //生成新结点
        cin>>p->data;
        p->next = L->next; L->next = p;    //插入到表头
    }
}

// 归并两个单链表
// 已知顺序单链表 La和 Lb的元素 按值非递减排列
// 归并La和Lb得到新的单链线性表 Lc, Lc的元素按值非递减排列
void MergeList_L(LinkList & La, LinkList &Lb, LinkList &Lc){
    auto pa = La ->next; auto pb = Lb->next;
    LinkList pc = La;
    Lc =  pc ;   //用La的头结点作为Lc的头结点
    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next=pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb; //插入剩余段
    free(Lb);   //释放Lb的头结点
}



// 利用数组 初始化顺序单链表
// 头插法 与 原数组保持顺序一致
void Init_LinkList(LinkList &L, ElemType* A, int n){
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;
    for(int i=n-1; i>=0 ;i--){
        auto p = (LinkList) malloc(sizeof(LNode));
        p->data = A[i];
        p->next = L->next;
        L->next=p;
    }
}

//打印链表信息
void PrintLinkList( LinkList & L){

    int length = 0;
    LNode *p = L->next;
    while(p){
        p =p->next;
        length ++;
    }
    cout<<"顺序单链表   长度: "<<length<<"  数据:  [ ";
    LNode *q = L->next;
    while(q){
        cout<<q->data;
        q =q->next;
        if(q) cout<<", ";
    }
    cout<<"]"<<endl;

}
