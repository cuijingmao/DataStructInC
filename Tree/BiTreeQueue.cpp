//
// Created by Carey on 2020/5/24.
//

#include "BiTreeQueue.h"
namespace BiTreeQueue_Space {
// 构建一个空队列
    Status  InitQueue(LinkQueue &Q){
        Q.front = Q.rear = (QueuePtr) malloc(sizeof(QNode));
        if(!Q.front) exit(OVERFLOW);      //存储分配失败
        Q.front->next = nullptr;
        return OK;
    }

// 销毁队列Q，Q不再存在
    Status DestroyQueue(LinkQueue &Q){
        while(Q.front)
        {
            Q.rear =Q.front->next;
            free(Q.front);
            Q.front = Q.rear;
        }
        return OK;
    }

// 将Q清为空队列
    Status ClearQueue(LinkQueue &Q);

// 空队列返回TRUE 否则返回FALSE
    Status QueueEmpty(LinkQueue Q){
        if(Q.front == Q.rear)  return TRUE;
        return FALSE;
    }

// 若队列不空，则用e返回Q的头元素，并返回OK,否则返回ERROR
    Status GetHead(LinkQueue Q, QElemType &e);

// 插入元素e作为Q的新的队尾元素
    Status EnQueue(LinkQueue &Q, QElemType e){
        auto p = (QueuePtr) malloc(sizeof(QNode));
        if(!p) exit(OVERFLOW);            //存储分配失败
        p->data = e;
        p->next = nullptr;
        Q.rear->next =p;
        Q.rear = p;         // Why?????
        return OK;
    }

// 若队列不空， 则删除Q的队头元素， 用e返回其值， 并返回OK;
// 否则返回ERROR
    Status DeQueue(LinkQueue &Q, QElemType &e){
        if( Q.front == Q.rear) return ERROR;
        auto p = Q.front->next;
        e =p->data;
        Q.front->next = p->next;
        if(Q.rear == p) Q.rear = Q.front;
        free(p);
        return OK;
    }
}