//
// Created by Carey on 2020/5/19.
// 串的堆分配存储表示

#ifndef C_HSTRING_H
#define C_HSTRING_H
#include "../Common.h"

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