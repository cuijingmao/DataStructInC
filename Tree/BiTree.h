//
// Created by Carey on 2020/5/21.
// 二叉树的 二叉链表存储表示

#ifndef C_BITREE_H
#define C_BITREE_H

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


#include "BiTreeStack.h"
using namespace  BiTreeStack_Space;

typedef int TElemType;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;   //
}BiTNode, *BiTree;


// 从 字符数组 创建 用二叉链 表示的二叉表
// n表示 字符数目 空格表示  null;
// mode 0 : 先序， mode 1: 中序， mode 2: 后序
Status CreateBiTreeFromArr(BiTree &T, char ch[],int n, int mode =0);

// 从 整数数组 创建 用二叉链 表示的二叉表
// n 表示 字符数目 -1表示  null;
// mode 0 : 先序， mode 1: 中序， mode 2: 后序
Status CreateBiTreeFromArr(BiTree &T, int arr[],int n, int mode =0);

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 先序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e) );

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse1(BiTree T, Status(*Visit)(TElemType e));

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次   递归法
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse2(BiTree T, Status(*Visit)(TElemType e));

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 后序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));


// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 层序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

// 按先序顺序出入二叉树中节点的值(一个字符),空格字符表示空树
// 构造二叉链表表示的二叉树
Status CreateBitree(BiTree &T);

// 节点值打印
Status PrintNodeValue(TElemType node);


#endif //C_BITREE_H



//    cout<<YELLOW;
//    cout<<"从字符数组构建 基于二叉链表的二叉树"<<endl;
//    cout<<"由于先、中、后序列无法单独唯一确定唯一序列，故折半法构建二叉树"<<endl;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<WHITE;
//    BiTree T;
//    char c[20] = {'A','B','C','D','E','F','G','H','I'};
//    cout<<YELLOW;
//    cout<<"从字符数组构建 基于二叉链表的二叉树："<<endl;
//    cout<<"[";
//    for(int i = 0; i< strlen(c)-1; i++)
//    {
//        cout<<c[i]<<", ";
//    }
//    cout<<c[strlen(c)-1]<<"]"<<endl;
//    cout<<WHITE;
//
//    cout<<MAGENTA;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"先序创建二叉树"<<endl;
//    cout<<WHITE;
//    CreateBiTreeFromArr(T,c,strlen(c),0);
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"先序遍历先序创建的二叉树："<<endl;
//    cout<<WHITE;
//    PreOrderTraverse(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"中序遍历先序创建的二叉树："<<endl;
//    cout<<WHITE;
//    InOrderTraverse(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"后序遍历先序创建的二叉树："<<endl;
//    cout<<WHITE;
//    PostOrderTraverse(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<MAGENTA;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"中序创建二叉树"<<endl;
//    cout<<WHITE;
//    CreateBiTreeFromArr(T,c,strlen(c),1);
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"先序遍历中序创建的二叉树："<<endl;
//    cout<<WHITE;
//    PreOrderTraverse(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"中序遍历中序创建的二叉树："<<endl;
//    cout<<WHITE;
//    InOrderTraverse2(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"后序遍历中序创建的二叉树："<<endl;
//    cout<<WHITE;
//    PostOrderTraverse(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<MAGENTA;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"后序创建二叉树"<<endl;
//    cout<<WHITE;
//    CreateBiTreeFromArr(T,c,strlen(c),2);
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"先序遍历后序创建的二叉树："<<endl;
//    cout<<WHITE;
//    PreOrderTraverse(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"中序遍历后序创建的二叉树："<<endl;
//    cout<<WHITE;
//    InOrderTraverse2(T,PrintNodeValue);
//    cout<<endl;
//
//    cout<<YELLOW;
//    cout<<"-------------------------------------------------------"<<endl;
//    cout<<"后序遍历后序创建的二叉树："<<endl;
//    cout<<WHITE;
//    PostOrderTraverse(T,PrintNodeValue);
//    cout<<endl;
//    //程序运行计时
//    int64_t time_elapsed = clock();
//    cout<<endl<<"程序共运行： "<<(double)time_elapsed/CLOCKS_PER_SEC<<"秒"<<endl;
