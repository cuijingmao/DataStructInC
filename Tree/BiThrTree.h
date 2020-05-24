//
// Created by Carey on 2020/5/24.
// 二叉树的二叉线索存储表示

#ifndef C_BITHRTREE_H
#define C_BITHRTREE_H


// *************************************************************
// 以下是 辅助性的代码 非重点
// *************************************************************
#ifndef  MY_COMMON_BLOCK
#define  MY_COMMON_BLOCK

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace  std;

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
#endif //MY_COMMON_BLOCK
// *************************************************************
// 以上是 辅助性的代码 非重点
// *************************************************************

typedef int TElemType;

typedef  enum {
    Link,           //   Link ==0 ： 指针
    Thread          //   Thread =1 : 线索
}PointerTag ;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;  // 左右孩子指针
    PointerTag  LTag,RTag;              // 左右标志
}BiThrNode, *BiThrTree;


// T指向头结点， 头结点的左链lchild指向根结点， 可参见 线索化算法
// 中序遍历二叉线索树T的非递归算法， 对每个数据元素调用函数Visit
Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e));

// 中序遍历进行中序线索化
void InThreading(BiThrTree p);

// 中序遍历二叉树T， 并将其中序线索化 Thrt指向头结点
Status InorderThreading(BiThrTree & Thrt, BiThrTree T);



#endif //C_BITHRTREE_H
