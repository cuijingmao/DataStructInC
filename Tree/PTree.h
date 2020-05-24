//
// Created by Carey on 2020/5/24.
// 树的双亲表存储表示

#ifndef C_PTREE_H
#define C_PTREE_H

#define MAX_TREE_SZIE 100
typedef int TElemType ;
typedef struct PTNode { // 结点结构
    TElemType data;
    int parent;     // 双亲位置域
}PTNode;

typedef struct {  // 树结构
    PTNode nodes[MAX_TREE_SZIE];
    int r,n;    //根的位置和结点数
}PTree;



#endif //C_PTREE_H
