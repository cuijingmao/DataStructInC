//
// Created by Carey on 2020/5/19.
//  串的 定长 顺序存储表示

#ifndef C_SSTRING_H
#define C_SSTRING_H

#include "../Common.h"

#define  MAXSTRLEN 255     // 用户可在255以内定义最大串长

typedef unsigned char SString[MAXSTRLEN+1];
//typedef unsigned char {
//
//}SString[MAXSTRLEN+1];

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


//cout<<"定长顺序存储串的表示  "<<endl;
//SString S;
//S[0] = 2;
//S[1] = 'C';
//S[2] = 'H';
//cout<<"S 的内容： "<<S<<endl;
//
//cout<<"请输入S2的内容:  ";
//SString S2;
//cin>>S2;
//cout<<"S2 的内容： "<<S2<<endl;
//
//SString T;
//Concat(T,S,S2);
//cout<<"S 和 S2拼接后为："<<T<<"  长度为：" <<(int)T[0] <<endl;
//
//SString S3, S4;
//char a[30] = "I love you";
//InitSString(S3,a);
//SubString(S4, S3, 3, 4);
//cout<<"字符串："<<S3<<" 的一个子串为： "<<S4<<endl;