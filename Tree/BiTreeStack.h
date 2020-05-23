//
// Created by Carey on 2020/5/23.
// 为链式二叉树定义的栈 与 SqStack 的不同在于 SElemType

#ifndef C_BITREESTACK_H
#define C_BITREESTACK_H


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
namespace BiTreeStack{
    typedef int TElemType;

    typedef struct BiTNode
    {
        TElemType data;
        struct BiTNode *lchild, *rchild;   //
    }BiTNode, *BiTree,*SElemType;

//    typedef BiTree SElemType;

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
    Status InitStackWisthArr(SqStack &S ,const SElemType *arr, int n);

//  打印栈内容
    void PrintStack(SqStack S);

}

#endif //C_BITREESTACK_H
