//
// Created by Carey on 2020/5/19.
// 数组的顺序存储表示  假定为行主序

#ifndef C_ARRAY_H
#define C_ARRAY_H

#include <cstdarg>

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

#define MAX_ARRAY_DIM 8   // 假设数组维数的最大值为8

typedef struct {
    ElemType *base;      // 数据元素基址
    int      dim;        // 数据维数
    int      *bounds;    // 数组维界基址， 由InitArray分配
    int      *constants;  // 数组影像函数常量基址， 由InitArray分配
} Array;


// 若维数dim 和随后的各纬长度合法， 则构造相应的数组A，并返回OK
Status InitArray(Array &A, int dim, ...);

// 销毁数组A
Status DestroyArray(Array &A);

// 若ap指示的各下标值合法， 则求出该元素在A中相对地址off
Status Locate(Array A, va_list ap, int &off);

// A 是 n 纬数组， e为元素变量，随后是n个下标值。
// 若下标不超界， 则将e的值赋给指定的A的元素，并返回OK
Status Value(Array A,ElemType &e, ...);

// A 是n维数组，e为元素变量， 随后是n个下标值，
// 若下标不越界， 则将e的值赋给指定的A的元素,并返回OK
Status Assign(Array &A, ElemType e, ...);


// *******************************************************************
//  以下为在 教材 基础上补充的辅助性函数  使其实用化
// *******************************************************************

//  获取数组长度：
int ArrayLength(Array A);

// 使用数组初始化 Array
Status AssignArray(Array & A, ElemType *arr, int n);

// 重载 流输出运算符
ostream & operator<<(ostream &os, Array A);



#endif //C_ARRAY_H


//    Array A;
//    InitArray(A,2, 10,10);
//    cout<<A.constants[0]<<endl;
//    cout<<A.dim<<endl;
//    cout<<ArrayLength(A)<<endl;
//    cout<<A<<endl;
//
//    Array B;
//    int arr[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//    InitArray(B,2,4,5);
//    AssignArray(B,arr,20);
//    cout<<B<<endl;
//
//    DestroyArray(A);
//    cout<<A<<endl;
//
//    int b =0;
//    Value(B,b,2,2);
//    cout<<B.base[12]<<endl;
//    cout<<B.constants[0]<<" "<<B.constants[1]<<endl;
//    cout<<b<<endl;