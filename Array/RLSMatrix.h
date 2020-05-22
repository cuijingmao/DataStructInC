//
// Created by Carey on 2020/5/21.
// 行逻辑联接的顺序表 表示的稀疏矩阵

#ifndef C_RLSMATRIX_H
#define C_RLSMATRIX_H

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

typedef int ElemType;

#define MAXSIZE 12500     // 假设非零元的最大个数为12500
#define MAXRC 100


typedef struct{
    int i,j;
    ElemType e;
} Triple;

typedef struct {
    Triple  data[MAXSIZE+1];   //非零元三元组表
    int rpos[MAXRC+1];
    int mu, nu,tu;      // 矩阵的行数、列数、非零元个数
}RLSMatrix;


// 求矩阵乘积 Q = M*N ， 采用行逻辑联接存储 表示
Status MultiSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q);



#endif //C_RLSMATRIX_H
