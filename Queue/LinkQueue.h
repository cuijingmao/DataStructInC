//
// Created by Carey on 2020/5/18.
//

#ifndef C_LINKQUEUE_H
#define C_LINKQUEUE_H
#include  "../Common.h"

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
