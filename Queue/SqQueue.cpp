//
// Created by Carey on 2020/5/18.
//

#include "SqQueue.h"

// 构建一个空队列Q
Status InitQueue(SqQueue &Q)
{
    Q.base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
    if(!Q.base)   exit(ERROR);       //存储分配失败
    Q.front = Q.rear = 0;
    return OK;
}


// 返回Q的元素个数，即队列的长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front +MAXQSIZE) % MAXQSIZE;
}

// 插入元素e为Q的新的队尾元素
Status EnQueue(SqQueue &Q, QElemType e)
{
    if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;  //队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear +1) %MAXQSIZE;
    return OK;
}

// 若队列不空，则删除Q的队头元素 ，用e返回其值， 并返回OK
// 否则返回ERROR
Status DeQueue(SqQueue &Q, QElemType &e)
{
    if(Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front +1) %MAXQSIZE;
    return OK;
}