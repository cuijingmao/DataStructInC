//
// Created by Carey on 2020/5/14.
//

#include "LinkListH.h"

int compare(ElemType a, ElemType b){
    if(a<b){
        return -1;
    }
    else if(a==b){
        return 0;
    }
    else  return 1;
}

// 分配由p指向的值为e的结点， 并返回OK; 若分配失败,则返回ERROR
Status MakeNode( Link &p, ElemType e){
    p = (Link) malloc(sizeof(LNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    return OK;
}



// 释放p所指结点
void FreeNode(Link &p){
    p->next = nullptr;
    delete [] p;
}

// 构造一个空的线性链表L
Status InitList(LinkList & L){
    L.head =  (LNode *) malloc(sizeof(LNode));
//    L.head->data =NULL;
    L.head->next = nullptr;
    L.tail = L.head;
    L.len =0;
    return OK;
}

// 销毁线性链表L,L不再存在
// 逐个依次销毁各元素
Status DestroyList(LinkList &L){
    Link head = L.head;
    Link p = head->next;
    while(p!=L.tail){
        head->next = head->next->next;
        free(p);
        p = head->next;
    }

    p = nullptr;
    free(L.head);
    L.head =nullptr;
    free(L.tail);
    L.tail =nullptr;
    L.len =-1;     //长度为-1表示已被销毁
//    L = NULL;
    return OK;
}


// 将线性表L重置为空表, 并释放原链表的结点空间
Status ClearList(LinkList &L){
    Link head = L.head;
    Link p = head->next;
    while(p!=L.tail){
        head->next = head->next->next;
        free(p);

        p = head->next;
    }
    p = nullptr;

    free(L.tail);
    L.tail = head;
    L.len = 0;
    return OK;
}

// 已知h指向线性链表的头结点， 将s所指结点插入在第一个结点之前
Status InsFirst(Link h, Link s){
    s->next = h->next;
    h->next = s;
    return OK;
}

// 已知h指向线性链表的头结点， 删除链表中的第一个结点并以q返回
Status DelFirst(Link h, Link &q){
    q  = h->next;
    h->next = h->next->next;
    q->next =nullptr;    // 很重要， 否则 将该结点插入或者Append到新的列表时绘出问题
    return OK;
}

// 将指针s所指的一串结点链接在线性表L的最后一个结点之后，
//并改变链表L的尾指针指向新的尾结点
Status Append(LinkList & L, Link s){
    L.tail->next = s;
    L.tail =s;
    L.len ++;
    while(s->next){
        s = s->next;
        L.tail->next = s;
        L.tail =s;
        L.len ++;
    }
    return OK;
}

// 删除线性链表L中的尾结点并以q返回，
// 改变链表L的尾指针指向新的尾结点
Status Remove(LinkList& L,Link &q){
    q = L.tail;
    Link  p = L.head;
    while(p->next!= L.tail){
        p = p->next;
    }
    L.tail = p;
    L.len--;
    return OK;
}

// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前
// 并修改指针p指向新插入的结点
Status InsBefore(LinkList &L, Link& p,Link s){
    Link q = L.head;
    while(q->next != p){
        q = q->next;
    }
    s->next = q->next;
    q->next = s;
    p = s;
    L.len ++;
    return OK;
}

// 已知p指向线性链表L中的一个节点，将s所指结点插入在p所指结点之后,
// 并修改指针p指向新插入的结点
Status InsAfter(LinkList &L, Link &p, Link s){
    s->next = p->next;
    p->next =s;
    p=s;
    L.len ++;
    return OK;
}

// 已知p指向线性表中的一个结点， 用e更新p所指结点中数据元素的值
Status SetCurElem(Link & p, ElemType e){
    p->data = e;
    return OK;
}

// 已知p指向线性链表中的一个结点， 返回p所指结点中数据元素的值
ElemType GetCurElem(Link p){
    return p->data;
}

// 若线性链表L为空表，则返回TRUE，否则返回FALSE
Status ListEmpty(LinkList L){
    if(L.len == 0 || L.tail == L.head)
        return OK;
    return FALSE;
}

// 返回线性链表中L中元素个数
int ListLength(LinkList L){
    return L.len;
}

// 返回线性链表的头结点的位置
Position  GetHead(LinkList L){
    return L.head;
}

// 返回线性链表L中最后一个节点的位置
Position GetLast(LinkList L){
    return L.tail;
}

// 已知p指向线性链表L中的一个节点， 返回p所指结点的直接前驱的位置
// 若无前驱， 则返回NULL
Position PriorPos(LinkList L, Link p){
    Link q = L.head;
    while(q->next != p && q!=L.tail){
        q = q->next;
    }
    if(q == L.tail)
        return nullptr;
    else
        return q;
}

// 已知p指向线性链表L中的一个节点， 返回p所指结点的直接后继的位置
// 若无后继，则返回NULL
Position NextPos(LinkList L, Link &p){
    return p->next;
}

// 返回p 指示线性链表L中第i个结点的位置并返回ok, i不合法时返回ERROR;
Status LocatePos(LinkList L,int i,Link & p ){
    if(i>L.len) return ERROR;
    p = L.head;
    int j =0;
    for (j=0; j<i;j++){
        p =p->next;
    }
    return OK;
}

// 返回线性链表L中第1个与e满足函数ompare()判定关系的元素的位置
// 若不存在这样的元素，则返回NULL
Position LocateElem(LinkList L, ElemType e, Status (*compare) (ElemType, ElemType)){
    Link p = L.head->next;   //第一个结点
    while( p != L.tail && !(*compare)(p->data, e)) p = p->next;
    if((*compare)(p->data, e))  return p;
    else
        return nullptr;

}

//依次对L的每个元素调用函数 visit(). 一旦Visit()失败，则操作失败
Status ListTraverse(LinkList L, Status (*visit)(Link)){
    Link p = L.head->next;
    while(p!= L.tail){
        visit(p);
    }
    visit(p);
    return OK;
}


// 使用数组 初始化线性链表
Status InitLinkListH(LinkList &L, ElemType * arr, int n){
    L.head =  (LNode *) malloc(sizeof(LNode));      // 虽然L已声明、定义， 并不意味着已经分配空间，
    // 这里只分配了头结点， 有数据时才需分配尾指针空间
    L.len = 0;   // 初始时链表长度为0
//    L.head->data =-1;
    L.head->next = nullptr;
    L.tail = L.head;    // 空链表时，头尾指向相同

    for (int i = n-1; i>=0; i--){  //头插法
        auto *p= (LNode*)malloc(sizeof(LNode));
        p->data = arr[i];
        p ->next = L.head->next;
        L.head->next = p;
        L.len++;
        if(L.head == L.tail){    // 加入第一个元素时， 必须指定尾指针的位置
            L.tail = p;          // 此后头插法 插入新结点时， 才能保证尾指针指向最先加入的结点
        }
    }
    return OK;
}

// 在带头结点的单链线性表L的第i个元素之前插入元素e
Status ListInsert_L(LinkList  &L, int i, ElemType e){
    Link h,s;
    if(!LocatePos(L, i-1,h))  return ERROR;
    if(!MakeNode(s,e)) return ERROR;
    InsFirst(h,s);   // 对于从第i个接待你开始的链表，第i-1个结点是它的头结点
    L.len++;
    return OK;
}

// 已知单链表La和Lb的元素 按值非递减排列
// 归并La和Lb得到新的单链表Lc, Lc的元素也按值非递减
Status MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc, int(*compare)(ElemType, ElemType)){
    if(!(InitList(Lc)))  return ERROR;          // 存储空间分配失败
    auto ha = GetHead(La); auto hb =GetHead(Lb);   // 头结点
    auto pa = NextPos(La,ha);   auto pb = NextPos(Lb,hb);    //当前结点
    while(pa && pb){        // La 与 Lb 均非空
        auto  a = GetCurElem(pa);
        auto  b = GetCurElem(pb);    // 获取元素数据
        Link q;
        if((*compare)(a,b) <=0){
            DelFirst(ha,q);
            Append(Lc,q);
            pa = NextPos(La,ha);

        } else {
            DelFirst(hb, q);
            Append(Lc,q);
            pb = NextPos(La,hb);
        }
    }// while

    if(pa)   Append(Lc,pa);   //链接La中剩余结点
    else Append(Lc, pb);         //链接La中剩余结点
    FreeNode(ha);
    FreeNode(hb);     //释放La Lb头结点
    return OK;
}// MergeList_L



// 打印 带头结点的线性链表
void PrintLinkListH(LinkList L) {
    if(L.len <= 0){
        cout<<"链表为空或不存在！"<<endl;
        exit(OVERFLOW);
    }
    LNode *p = L.head->next;
    cout<<"线性链表   长度："<<L.len<<"   数据： [";
    while(p != L.tail){
        cout<<p->data<<", ";
        p = p->next;
    }
    cout<<p->data<<"]"<<endl;
}
