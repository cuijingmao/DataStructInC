//
// Created by Carey on 2020/5/19.
// 串的堆分配存储表示

#ifndef C_HSTRING_H
#define C_HSTRING_H

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
typedef struct {
    char *ch;     // 若是非空串， 则按串长分配存储区， 否则为 NULL
    int length;    // 串长度
} HString;

// 生成一个其值等于串常量 chars 的串T
Status StrAssigbn(HString &T, char *chars);

// 返回S的元素个数，称为 串的长度
int StrLength(HString S);

// 若S>T ,则返回值> 0; 若 S=T，则返回值=0； 若 S<T, 则返回值 <0
int StrCompare(HString S, HString T);

// 将S清为空串，并释放S所占的空间
Status ClearString(HString &S);

// 用T返回由S1和S2联接而成的新串
Status Concat(HString &T, HString S1, HString S2);

// 返回串S的第pos个字符起长度为len的子串
// 1<= pos <= StrLength(S)  且 0<= len <= StrLength(S)- pos +1
Status SubString(HString &Sub,HString S, int pos, int len);

// 打印字符串
ostream & operator<< (ostream &, HString S);
#endif //C_HSTRING_H


//    HString  S,S1,S2,S3,S4;
//    char a[20] = "I love China";
//    StrAssigbn(S, a);
//    cout<<S<<endl;
//
//    char b[30] = "Happy Learning";
//    StrAssigbn(S1,b);
//    cout<<S1<<endl;
//    cout<<StrCompare(S,S1)<<endl;
//
//    Concat(S2,S,S1);
//    cout<<S2<<endl;
//
//
//    ClearString(S);
//    cout<<S<<endl;
//    cout<<S.length;
//    if(S.ch) cout<<"hhhh"<<endl;
//
//
//    cout<<S4.length<<endl;
//
//    int sw,t;
//    cout<<sw<<"  "<<t<<endl;
//    printf("%d\n",t);
//    S3.ch = nullptr;    // 此处必须处理未初始化的 S3
//    SubString(S3,S2,5,6);
//    cout<< S3<<endl;