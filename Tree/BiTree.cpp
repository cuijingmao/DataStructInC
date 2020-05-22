//
// Created by Carey on 2020/5/21.
//

#include "BiTree.h"

// 按先序次序输入 二叉树中节点的值(一个字符), 空格字符表示空树
// 构造二叉链表表示的二叉树T
Status CreateBiTree(BiTree &T);

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 先序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e) )
{
    if( T)
    {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit)) return OK;
         return ERROR;
    }
    else return OK;
} // PreOrderTravese



// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
    SqStack  S;
    InitStack(S);
    Push(S,T);   // 根指针进栈

}

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 后序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));


// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 层序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e));