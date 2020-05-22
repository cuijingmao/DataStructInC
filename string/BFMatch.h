//
// Created by Carey on 2020/5/19.
//  串 模式匹配的 暴力算法

#ifndef C_BFMATCH_H
#define C_BFMATCH_H

#include "SString.h"

// 返回子串T中第 pos个字符之后的位置， 若不存在， 则函数值 为0
// 其中，T非空， 1<= pos <= StrLength(S)
int Index(SString S, SString T, int pos);

#endif //C_BFMATCH_H


//    cout<<YELLOW<<"暴力算法进行字符串的子串模式匹配(BF算法)："<<endl;
//    cout<<WHITE;
//    SString S,S1;
//    char a[20] = "ababcabcacbab";
//    char b[5]  = "abc";
//    InitSString(S,a);
//    cout<<"主串："<<S<<endl;
//    InitSString(S1,b);
//    cout<<"模式串："<<S1<<endl;
//    int ind = Index(S,S1, 1);
//    cout<<"主串中模式串的第一个位置是: "<<ind<<endl;