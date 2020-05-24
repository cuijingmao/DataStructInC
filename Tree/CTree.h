//
// Created by Carey on 2020/5/24.
// 树的孩子链表存储表示

#ifndef C_CTREE_H
#define C_CTREE_H

#define MAX_TREE_SIZE 100;
typedef int TElemType;
typedef struct CTNode {  // 孩子结点
    int child;
    struct CTNode *next;
} *ChildPtr;


typedef struct{
    TElemType data;
    ChildPtr firstchild;    //孩子链表头指针
}CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n,r;   //结点数和根的位置
}CTree;

#endif //C_CTREE_H
