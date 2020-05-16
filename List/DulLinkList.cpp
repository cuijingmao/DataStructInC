//
// Created by Carey on 2020/5/14.
//

#include "DulLinkList.h"

// 获取链表第i个结点
// 如果i 大于表长 则返回表尾
DuLNode* GetElemP_DuL(DuLinkList &L,int i){
    // L即头结点
    DuLNode* head = L;
    auto p = L->next; int j =1;    // 初始化， p指向第一个结点， j为计数器
    while(p!= head && j<i){
        p = p->next; ++j;
    }
    if( !p|| j>i) return ERROR;   //第i个元素不存在
    return p;
}

// 用数组  初始化 一个 双向链表
Status InitDuLinkList(DuLinkList & L,  ElemType * arr, int n){
    L = (DuLNode*) malloc(sizeof(DuLNode));
    DuLNode* head = L;
    head->next=head;
    head->prior=head;
    head->data= -1;
    for(int i = n-1; i  >= 0 ;i--){   // 头插法创建
        DuLNode* p = (DuLNode*) malloc(sizeof(DuLNode));
        p->data = arr[i];
        p->next = head->next;
        p->next->prior = p;
        head->next = p;
        p->prior = head;
    }
    return  OK;
}


// 在带头结点的双循环线性表L中第i个位置之前插入元素e
// i的合法值为 1<<i<<表长+1
Status ListInsert_DuL(DuLinkList &L, int i, ElemType e){
    DuLNode* p;
    if(!( p= GetElemP_DuL(L,i)))    //在L中确定插入位置指针p
        return ERROR;                   // i等于表长+1时， p指向头结点，
    // i大于表长加一时， p=NULL
    DuLNode* s;
    if (!( s = (DuLinkList) malloc(sizeof(DuLNode))))   return ERROR;  // 内存分配失败
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
} // ListInsert_Dul;

// 双向循环链表 删除元素
// 删除带头结点的双联表L的第i个元素, i的合法值 1<=i<=表长
Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e){
    DuLNode * p;
    if(!( p =GetElemP_DuL(L,i)))   //在L中确定第i个元素的位置指针p
        return ERROR;                 // p =NULL, 即第i个元素不存在
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}// ListDelete_Dul





// 打印双向链表数据内容 带头结点
void PrintDuLinkList(DuLinkList &L){
    DuLNode* head = L;
    DuLNode* p = head->next;    // L指向的就是头结点
    int length = 0;          // 双向循环链表长度
    cout<<"双向循环链表    长度：";
    while(p != head){
        p = p->next;
        length ++;
    }
    cout<<length<<"    数据：[";
    p = head->next;
    while(p !=head){
        cout<<p->data;
        p = p->next;
        if(p!=head) cout<<", ";
    }
    cout<<"]"<<endl;
}
