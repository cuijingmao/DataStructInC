//
// Created by Carey on 2020/5/18.
//  链式循环队列

#ifndef C_SQQUEUE_H
#define C_SQQUEUE_H
#include "../Common.h"
#define MAXQSIZE 100    //最大队列长度

typedef int QElemType;
typedef struct {
    QElemType *base;     // 初始化的动态分配的存储空间
    int front;           // 头指针，若队列不空 指向队列头元素
    int  rear;           // 尾指针， 指向队列尾元素的下一个位置
}SqQueue;

// 构建一个空队列Q
Status InitQueue(SqQueue &Q);

// 返回Q的元素个数，即队列的长度
int QueueLength(SqQueue Q);

// 插入元素e为Q的新的队尾元素
Status EnQueue(SqQueue &Q, QElemType e);

// 若队列不空，则删除Q的队头元素 ，用e返回其值， 并返回OK
// 否则返回ERROR
Status DeQueue(SqQueue &Q, QElemType &e);





#endif //C_SQQUEUE_H
