//
// Created by Carey on 2020/5/18.
//

#ifndef C_LINKQUEUE_H
#define C_LINKQUEUE_H

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
typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front ;  // 队头指针
    QueuePtr rear ;   // 队尾指针
}LinkQueue;

// 构建一个空队列
Status  InitQueue(LinkQueue &Q);

// 销毁队列Q，Q不再存在
Status DestroyQueue(LinkQueue &Q);

// 将Q清为空队列
Status ClearQueue(LinkQueue &Q);

// 空队列返回TRUE 否则返回FALSE
Status QueueEmpty(LinkQueue Q);

// 若队列不空，则用e返回Q的头元素，并返回OK,否则返回ERROR
Status GetHead(LinkQueue Q, QElemType &e);

// 插入元素e作为Q的新的队尾元素
Status EnQueue(LinkQueue &Q, QElemType e);

// 若队列不空， 则删除Q的队头元素， 用e返回其值， 并返回OK;
// 否则返回ERROR
Status DeQueue(LinkQueue &Q, QElemType &e);

// 从队头到队尾依次对队列Q中每个元素调用函数 visit(). 一旦visit()失败， 则操作失败

#endif //C_LINKQUEUE_H
