//
// Created by Carey on 2020/5/14.
//

#include "Polynomial.h"
// 输入m项的系数和指数，建立表示一元多项式的有序链表P
//void CreatePolyn(polynomial &P, int m){
//    InitList (P);
//    auto h = GetHead(P);
//    ElemType e;
//    e.coef =0.0;
//    e.expn = 0;
//    SetCurElem(h,e);
//    for( int i=1; i<= m; ++i ){   // 依次输入m个非零项
//        // scanf(e.coef, e.expn);
//        cin>>e.coef>>e.expn;
//        if(!LocateElem(P,e,q,(*compare)())){
//            if(MakeNode(s,e)) InsFirst(q,s);
//        }
//
//    }
//
//}


// 销毁一元多项式
void DestroyPolyn( polynomial &P);

// 打印输出一元多项式P
void PrintPolyn(polynomial P){
    cout<<"多项式  共"<< P.len <<"项" << " 依次是：[";
    Link q = P.head;
    while(q->next){
        q = q->next;
        cout<<"("<<q->data.coef<<", "<<q->data.expn<<")";
        if(q->next)
            cout<<", ";
        else
            cout<<"]"<<endl;
    }
//    cout<<""
//    cout<<""
//    Link q = P.head->next;
//    while(q){
//
//        cout<<"("<<q->data.coef<<", "<<q->data.expn<<"), ";
//        q = q->next;
//    }
//    cout<<q->next->data.coef<<"hhh";
//    cout<<"("<<P.tail->data.coef<<", "<<P.tail->data.expn<<")"<<endl;
//    cout<<"("<<q->data.coef<<", "<<q->data.expn<<")]"<<endl; // 尾结点单独处理
}

// 返回一元多项式P中的项数
int PolynLength(polynomial P);

// 多项式相加 Pa = Pa + Pb,并销毁Pb
void  AddPolyn(polynomial &Pa, polynomial &Pb){
    auto ha = GetHead(Pa);
    auto hb = GetHead(Pb);    //ha、hb分别指向Pa和Pb的头结点
    auto qa = NextPos(Pa,ha);
    auto qb = NextPos(Pb, hb);  // qa和qb分别指向Pa和Pb的当前结点
    while(qa && qb){  //qa和qb 均非空
        auto a = GetCurElem(qa);
        auto b =GetCurElem(qb);    // a b 为两表中 当前比较元素
        switch( (compare)(a,b)){    // 多项式Pa中当前结点的 指数值小
            case -1:{
                ha = qa;
                qa = NextPos(Pa,qa);
                break;
            }
            case 0:  { // 两者指数值相同
                auto sum = a.coef + b.coef;
                if( sum != 0.0){       // 修改多项式Pa当前结点的系数值
                    qa->data.coef = sum;
                    ha =qa;
                    //SetCurElem(qa,sum);
                }
                else{                  // 删除多项式PA中当前结点
                    DelFirst(ha, qa);
                    FreeNode(qa);
                }
                DelFirst(hb,qb);
                FreeNode(qb);
                qb = NextPos(Pb, hb);
                qa = NextPos(Pa, ha);
                break;
            }
            case 1:{
                DelFirst(hb,hb);
                InsFirst(ha, qb);
                qb = NextPos(Pb,hb);
                ha = NextPos(Pa, ha);
                break;
            }
        }//switch

    }// while
    if(!ListEmpty(Pb)) Append(Pa,qb);  // 链接Pb中剩余结点
    FreeNode(hb);                      // 释放OB中的头结点
}// AddPolyn

// 完成多项式想减运算， 即 Pa = Pa - Pb, 并销毁一元多项式 Pb
void SubtractPolyn( polynomial &Pa, polynomial &Pb);

// 完成多项式相乘运算， 即 Pa = Pa * Pb， 并销毁一元多项式Pb
void MultiplyPolyn( polynomial &Pa, polynomial &Pb);

// 使用系数和指数数组初始化多项式
void InitPolyn(polynomial &P, const float * coef, const int * expn, int n){
    // 刚初始化时，head未分配空间， head->next 无定义  访问时会产生  退出代码11
    P.head = (LNode*) malloc(sizeof(LNode));
    P.head->next = nullptr;
    P.len=0;
    Link s;
    for (int i =n-1; i>=0; i--){     // 头插法
        s = (Link) malloc(sizeof(LNode));
        s->data.coef = coef[i];
        s->data.expn = expn[i];

        s->next = P.head->next;  //头插法
        P.head->next = s;
        // 第一次插入结点时， 一定要在s插入后， 再让尾指针指向它，否则会陷入无限循环中
        if( P.len == 0){   // 添加第一个结点时，需要将尾指针指向它， 因为它是最后一个节点！
            P.tail = s;    // 之后不需要改动尾指针， 因为是头插法
            P.tail->next = nullptr;
        }
        P.len ++;
    }
}
