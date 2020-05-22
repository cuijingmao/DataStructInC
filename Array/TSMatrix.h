//
// Created by Carey on 2020/5/20.
// 稀疏矩阵的压缩存储方式之一： 三元组顺序表

#ifndef C_TSMATRIX_H
#define C_TSMATRIX_H

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

#define MAXSIZE 12500  //假设非零元个数的最大值未 12500
typedef int ElemType;
typedef struct {
    int i,j;  // 该元素的行下标和列下标
    ElemType e;
} Triple;

typedef struct {
    Triple data[MAXSIZE+1];    // 非零元素三元组，data[0] 未用
    int mu,nu,tu;   // 矩阵的行数、列数，非零元个数
} TSMatrix;

// 采用三元组表存储表示, 求稀疏矩阵M的转置矩阵T
Status TransposeSMatrix(TSMatrix M, TSMatrix &T);

// 采用三元组表存储表示, 求稀疏矩阵M的转置矩阵T(快速方法）
Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T);


// *******************************************************************
//  以下为在 教材 基础上补充的辅助性函数  使其实用化
// *******************************************************************

// 使用 n *3  数组创建 TSMatrix
Status CreateTSMatrix(TSMatrix &M, ElemType A[][3], int n);

// 打印
ostream & operator<<(ostream &os, TSMatrix M);

#endif //C_TSMATRIX_H


//    cout<<YELLOW<<"使用二维数组创建基于三元组顺序表的稀疏矩阵："<<endl;
//    cout<<WHITE;
//    TSMatrix M;
//    ElemType arr[8][3] = {{1,2,12},{1,3,9},{3,1,-3},
//                        {3,6,14},{4,3,24},{5,2,18},
//                        {6,1,15},{6,4,-7}};
//
//    CreateTSMatrix(M,arr,8);
//    cout<<M<<endl;
//
//    cout<<YELLOW<<"基于三元组顺序表的稀疏矩阵的转置："<<endl;
//    cout<<WHITE;
//    TSMatrix N;
//    TransposeSMatrix(M,N);
//    cout<<N<<endl;
//
//    cout<<YELLOW<<"基于三元组顺序表的稀疏矩阵的转置(快速方法)："<<endl;
//    cout<<WHITE;
//    TSMatrix T;
//    FastTransposeSMatrix(N,T);
//    cout<<T<<endl;