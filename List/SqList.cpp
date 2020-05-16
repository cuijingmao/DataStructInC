//
// Created by Carey on 2020/5/11.
//

#include "SqList.h"


//初始化线性表
Status InitList_Sq(SqList &L){
    //构造一个空的线性表
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE *sizeof(ElemType));
    if(! L.elem) exit(OVERFLOW);
    L.length =0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

//用含n个元素的数组 初始化线性表
Status InitList_Sq(SqList &L,  const ElemType *data, int n){

    if(!n) return FALSE;
    //构造一个空的线性表
    L.elem = (ElemType *) malloc((LIST_INIT_SIZE + n) *sizeof(ElemType));
    if(! L.elem) exit(OVERFLOW);
    for(int i =0; i<n; i++){
        L.elem[i] = data[i];
    }
    L.length =n;
    L.listsize = LIST_INIT_SIZE + n;
    return OK;
}

//线性表插入
Status ListInsert_Sq(SqList &L, int i, ElemType e){
    // 在顺序线性表L中第i个位置之前插入新的元素e
    // i的合法值为 1<=i <=ListLength_Sq(L) +1

    if(i<1 ||i>L.length +1 ) return ERROR;  //i的值不合法
    if(L.length >= L.listsize){   //当前存储空间已满,增加分配
        auto * newbase = (ElemType*) realloc(L.elem, (L.listsize+LISTINCREMEMNT)* sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);   //存储分配失败
        L.elem = newbase;  //新基址
        L.listsize += LISTINCREMEMNT;  //增加存储容量
    }

    auto q = &(L.elem[i-1]);    //q为插入位置
    for(auto p= &(L.elem[L.length -1]); p>=q; --p)
        *(p+1) = *p;   //插入位置及之后的元素右移
    *q = e;   //插入e;
    ++L.length;     //表长增一
    return OK;

}

//线性表元素删除
//在顺序线性表L中删除第i个元素， 并用e返回其值
// 1<= i<= ListLength_Sq(L)
Status ListDelte_Sq(SqList & L, int i, ElemType &e){
    if((i<1) || (i> L.length))  return ERROR;  // i值不合法
    auto p = &(L.elem[i-1]);      // 为被删除元素的位置
    e =* p;                       // 被删除元素的值赋给e
    auto q = L.elem + L.length -1;   // 表尾元素的位置
    for( ++p; p<=q; ++p) *(p-1) = *p;     //被删除元素之后的元素左移
    --L.length;  //表长减一
    return OK;
}//ListDelete_Sq

//顺序线性表查找
//在顺序线性表L中查找第一个值与e满足compare()的元素的位序
int LocateElem_Sq(SqList L, ElemType e, Status (*myCompare)(ElemType,ElemType)){
    int i=1;
    auto p =L.elem;
    while( i<= L.length && !(*myCompare) (*p++, e)) ++i;
    if(i<=L.length) return 1;
    else return 0;
}

//有序顺序表合并
//已知顺序线性表La和Lb的元素按值非递减排列
//归并La和Lb得到新的顺序表Lc,Lc的元素也非递减排列
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc){
    auto pa = La.elem;
    auto pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    auto pc = Lc.elem = (ElemType*) malloc(Lc.listsize *sizeof(ElemType));
    if(!Lc.elem) exit(OVERFLOW);   //存储分配失败
    auto pa_last = La.elem + La.length -1;
    auto pb_last = Lb.elem + Lb.length -1;
    while(pa <= pa_last && pb<=pb_last){     //归并
        if(*pa <= *pb) *pc ++ = *pa++;
        else *pc ++= *pb++;
    }
    while(pa <pa_last) *pc++= *pa++;   //插入La剩余元素
    while(pb <= pb_last) *pc++ = *pb++;   // 插入Lb的剩余元素
}//  MergeList_Sq








//打印线性表信息
void PrintSqList(SqList &L){
    cout<<"线性表      容量："<<L.listsize<<"   数据量: "<<L.length <<"   数据： [";
    for(int i =0; i<L.length-1; i++){
        cout<<L.elem[i]<<" ";
    }
    cout<<L.elem[L.length-1]<<"]"<<endl;
}