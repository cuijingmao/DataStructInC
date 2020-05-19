//
// Created by Carey on 2020/5/19.
//  串的块链存储表示

#ifndef C_LSTRING_H
#define C_LSTRING_H

#define CHUNKSIZE  80   // 可由用户定义的块大小

typedef  struct Chunk {
    char ch[CHUNKSIZE];
    struct Chunk *next;
} Chunk;


typedef struct {
    Chunk *head, *tail ;   //串的头和尾指针
    int curlen;   // 串的当前长度
} LString;

#endif //C_LSTRING_H
