//
// Created by Carey on 2020/5/19.
//  串的 定长 顺序存储表示

#ifndef C_SSTRING_H
#define C_SSTRING_H

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

#define  MAXSTRLEN 255     // 用户可在255以内定义最大串长

typedef unsigned char SString[MAXSTRLEN+1];


// 用T返回由S1 和 S2 链接而成的新串， 若未截断 ，则返回TRUE, 否则返回FALSE
Status Concat(SString &T, SString S1, SString S2);

// 用Sub返回串S的第pos个字符起长度为len的子串
Status SubString(SString &Sub, SString S, int pos, int len);

// 重载输出远算符
ostream & operator<<( ostream & os,SString S);

// 重载输入运算符
istream & operator>>( istream & is,SString &S);

// 用字符数组初始化
void InitSString(SString &S, char *arr);
#endif //C_SSTRING_H


//    cout<<YELLOW<<"定长顺序存储串的表示："<<endl;
//    cout<<WHITE;
//    SString S;
//    S[0] = 2;
//    S[1] = 'C';
//    S[2] = 'H';
//    cout<<"S 的内容： "<<S<<endl;
//
//    cout<<YELLOW<<"请输入S2的内容:"<<endl;
//    cout<<WHITE;
//    SString S2;
//    cin>>S2;
//    cout<<"S2 的内容： "<<S2<<endl;
//
//    cout<<YELLOW<<"S和S2拼接后为："<<endl;
//    cout<<WHITE;
//    SString T;
//    Concat(T,S,S2);
//    cout<<T<<"  长度为：" <<(int)T[0] <<endl;
//
//    cout<<YELLOW<<"求字符串子串："<<endl;
//    cout<<WHITE;
//    SString S3, S4;
//    char a[30] = "I love you";
//    InitSString(S3,a);
//    SubString(S4, S3, 3, 4);
//    cout<<"字符串："<<S3<<" 的一个子串为： "<<S4<<endl;
