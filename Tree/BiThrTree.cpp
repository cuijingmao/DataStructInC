//
// Created by Carey on 2020/5/24.
//

#include "BiThrTree.h"

// T指向头结点， 头结点的左链lchild指向根结点， 可参见 线索化算法
// 中序遍历二叉线索树T的非递归算法， 对每个数据元素调用函数Visit
Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
{
    BiThrTree p = T->lchild;      // p指向根结点
    while(p != T)        // 空树或遍历结束时， p==T
    {
        while( p->LTag == Link)  p = p->lchild;
        if(!Visit(p->data)) return ERROR;   // 访问其左子树为空的结点
        while(p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            Visit(p->data);    //访问后继结点
        }
        p = p->rchild;
    }
    return OK;
}// InOrderTraverse_Thr




// 中序遍历二叉树T， 并将其中序线索化 Thrt指向头结点
Status InorderThreading(BiThrTree & Thrt, BiThrTree T)
{
    if(!(Thrt = (BiThrTree) malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    Thrt->LTag = Link;
    Thrt->RTag = Thread;      // 建头结点
    Thrt->rchild = Thrt;      //  右指针回指
    if(!T) Thrt->lchild = Thrt;   // 若二叉树为空， 则左指针回指
    else{
        BiThrTree pre;
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T);      // 中序遍历进行中序线索化
        pre->rchild = Thrt;
        pre->RTag = Thread;     // 最后一结点线索化
        Thrt->rchild = pre;
    }
    return OK;
} // InOrderThreading


// 中序遍历进行中序线索化
void InThreading(BiThrTree p)
{
    BiThrTree pre;// 前驱线索，需要调用的地方提供
    if(p)
    {
        InThreading(p->lchild); // 左子树线索化
        if(!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;   // 前驱线索
        }

        if(!pre -> rchild)
        {
            pre->RTag = Thread;
            pre->rchild = p;   //后继线索
        }
        pre = p;     // 保持怕热指向p的前驱
    }
}// InThreading
