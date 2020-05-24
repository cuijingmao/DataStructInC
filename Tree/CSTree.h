//
// Created by Carey on 2020/5/24.
// 树的孩子兄弟表示法

#ifndef C_CSTREE_H
#define C_CSTREE_H

typedef int ElemType;

typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

#endif //C_CSTREE_H
