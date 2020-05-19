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


//    SString S,S1;
//    char a[20] = "ababcabcacbab";
//    char b[5]  = "abc";
//    InitSString(S,a);
//    InitSString(S1,b);
//    int ind = Index(S,S1, 1);
//    cout<<"在字符串："<<S<<" 中, 子串 "<<S1
//        <<" 的第一个位置是: "<<ind<<endl;