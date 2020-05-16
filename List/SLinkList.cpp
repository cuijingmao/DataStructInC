//
// Created by Carey on 2020/5/13.
//

#include "SLinkList.h"

// 静态单链线性表L中查找第一个值为e的元素
// 若找到，返回它在L中的位序， 否则返回0
int LocateElemL_SL(SLinkList S, ElemType e){
    auto i = S[0].cur; //i指示表中第一个结点
    while(i && S[i].data!= e)
        i = S[i].cur;        // 在表中顺链查找

    return i;     // 查找最终  i为0

}//  LocateElem_Sl

// 初始化 静态链表
// 将一位数组 space 中 各个份量链成一个备用链表， space[0].cur为头指针
// "0" 表示空指针
void InitSpace_SL(SLinkList &space){
    for( int i =0; i< MAXSIZE -1; ++i)
        space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;
}// InitSpace_SL;

// 若备用空间链表非空， 则返回分配的结点下标， 否则返回0
int Malloc_SL(SLinkList &space){
    auto i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}// Malloc_SL

// 将下标为k的空闲结点回收到备用链表
void Free_SL(SLinkList &space, int k){
    space[k].cur =space[0].cur;
    space[0].cur =k;
}


// 求两集合的差集
// 依次输入集合A和B的元素, 在一位数组space中建立表示集合 (A-B) U (B-A)
// 的静态链表, S为其头指针. 假设备用空间足够大， space[0].cur为其头指针
void difference(SLinkList &space, int &S){
    InitSpace_SL(space);         //初始化备用空间
    S = Malloc_SL(space);        //生成S的头结点
    auto r = S;                      // r指向S的当前最后结点
    int m,n;
    cin>>m>>n;                       // 输入A和B的元素个数
    for(int j =1; j <= m; ++j){      // 建立集合A的链表
        int i = Malloc_SL(space);        //分配结点
        cin>>space[i].data;                  //输入A 的元素值
        space[r].cur = i; r=i;               //插入到表尾
    }
    space[r].cur =0;                         //尾结点的指针为空
    for(int j =1; j<= n; ++j){  //依次输入B的元素，若不在当前表里，则插入，否则删除
        ElemType b;
        cin>>b;
        auto p =S;  auto k = space[S].cur;    // k 指向集合A中的第一个结点
        while( k != space[r].cur && space[k].data != b){ //在当前表中查找
            p =k; k=space[k].cur;
        }

        if( k == space[r].cur){   //在当前表中不存在该元素，插入在r缩指结点之后
                                  //且r的位置不变
            int i = Malloc_SL(space);
            space[i].data =b;
            space[i].cur = space[r].cur;
            if( r==k) r= p;       //若删除的是r所指结点， 则需修改尾指针


        }


    }

}






// 用数组 初始化 静态链表
// 用数组arr的n个值为 slist赋值
// 第0个为 头结点 不存数据 需单独处理 ，切记
// 共需 n+1个结点
void InitSLinkList(SLinkList & slist,const ElemType *arr, int n){
    if (n>=MAXSIZE) exit(OVERFLOW);
    slist[0].cur = 1;
    slist[0].data = -1;
    for(int i =1; i<n; i++){
        slist[i].data = arr[i-1];
        slist[i].cur = i+1;
    }
    slist[n].data = arr[n-1];
    slist[n].cur = 0;
}

// 向静态链表插入数据
// 在静态链表的第i个位置 插入元素e
void InsertSLinkList(SLinkList &L, int i, ElemType e){
}



// 打印静态链表信息
//  切记 0号 为头  不存储数据！ 需单独处理
void PrintSLinkList(SLinkList L)
{
    int i = L[0].cur;
    if(i == 0){
        cout<<"静态链表为空！"<<endl;  return ;
    }

    int length = 0;
    while(i){
        length++;
        i = L[i].cur;   //在表中顺链查找
    }
    cout<<"静态链表    数据长度: "<<length<<"   内容： [ ";
    cout<<"("<<"NULL"<<","<<L[0].cur<<"), ";
    for(int j =1; j<length; j++){
        cout<<"("<<L[j].data<<","<<L[j].cur<<"), ";
    }
    cout<<"("<<L[length].data<<","<<L[length].cur<<")";

    cout<<" ]  数据链： [";

    int k = L[0].cur;
    while(k){
        cout<<L[k].data;
        k = L[k].cur;
        if(k)
            cout<<", ";
    }
    cout<< "]"<< endl;
}
