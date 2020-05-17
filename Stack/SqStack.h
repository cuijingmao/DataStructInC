//
// Created by Carey on 2020/5/16.
//

#ifndef C_SQSTACK_H
#define C_SQSTACK_H

#include  "../Common.h"
using namespace  Common;


#define STACK_INIT_SIZE 100  //存储空间初始分配量
#define STACKINCREMENT 10   //存储空间分配增量

typedef struct {
    SElemType  *base;        // 在栈构造之前和销毁之后， base的值为NULL
    SElemType  *top;         // 栈顶指针
    int        stacksize;    // 当前已分配的存储空间， 以元素为单位
}SqStack;

// 构造一个空栈
Status InitStack(SqStack &S);

// 销毁栈S，S不再存在
Status DestroyStack(SqStack &S);

// 把S置为空栈
Status ClearStack(SqStack &S);

// 若S为空栈,则返回TRUE，否则返回FALSE
Status StackEmpty(SqStack S);

// 返回S的元素个数，即栈的长度
int StackLength(SqStack S);

// 若栈不空，则用e返回S的栈顶元素，并返回OK,否则返回ERROR
Status GetTop(SqStack S, SElemType &e);

// 插入元素e为新的栈顶元素
Status Push(SqStack &S, SElemType e);

// 若栈不空，则删除S的栈顶元素， 用e返回其值， 并返回OK；否则返回ERROR
Status Pop(SqStack &S, SElemType &e);

// 从栈顶到栈底依次对栈中每个元素调用函数visit(), 一旦visit()失败，则操作失败
Status SqStackTraverse(SqStack S,Status(*visit)());

// 使用数组初始化栈
Status InitStackWisthArr(SqStack &S ,const ElemType *arr, int n);

//  打印栈内容
void PrintStack(SqStack S);


#endif //C_SQSTACK_H


//    cout<<YELLOW<<"使用数组初始化线性栈："<<endl;
//    cout<<WHITE;
//    SqStack S;
//    ElemType a[] {2,3,4,5,6,7};
//    InitStackWisthArr(S,a,6);
//    PrintStack(S);
//
//    cout<<YELLOW<<"Pop栈顶元素："<<endl;
//    cout<<WHITE;
//    ElemType e ;
//    Pop(S,e);
//    cout<<e<<endl;
//    PrintStack(S);
//
//    cout<<YELLOW<<"Push新元素进栈："<<endl;
//    cout<<WHITE;
//    ElemType ee =4;
//    Push(S,ee);
//    PrintStack(S);

