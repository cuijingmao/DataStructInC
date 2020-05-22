//
// Created by Carey on 2020/5/21.
// 二叉树的 二叉链表存储表示

#ifndef C_BITREE_H
#define C_BITREE_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace  std;

// *************************************************************
// 以上是 辅助性的代码 非重点
// *************************************************************

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define UNDERFLOW -3

typedef short Status;

// *************************************************************
// 以上是 辅助性的代码 非重点
// *************************************************************
#include "../Stack//SqStack.h"
typedef int TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;   //
}BiTNode, *BiTree;


// 按先序次序输入 二叉树中节点的值(一个字符), 空格字符表示空树
// 构造二叉链表表示的二叉树T
Status CreateBiTree(BiTree &T);

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 先序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e) );

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 后序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));


// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 层序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e));



#endif //C_BITREE_H
