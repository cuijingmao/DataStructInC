//
// Created by Carey on 2020/5/19.
// 定长顺序存储结构 串模式匹配的KMP算法

#ifndef C_KMPMATCH_H
#define C_KMPMATCH_H

#include "SString.h"

// next[j] 表示 当模式中第j个 字符与主串 中相应字符"适配"时，
// 在模式中需重新 和主串 中 该字符进行比较的字符的位置


// 利用模式串 T的next 函数求 T在 主中第pos个字符之后的位置 的  KMP算法
// 其中， T非空， 1<= pos <<StrLength(S);
int Index_KMP(SString S,SString T, int pos);

// 求模式串T的next函数值 并存入数组 next
void get_next(SString T, int next[]);

// 求模式串T的 next函数修正值并存入数组nextval
void get_nextval(SString T, int nextval[]);

#endif //C_KMPMATCH_H

//    cout<<YELLOW<<"KMP算法进行字符串的子串模式匹配："<<endl;
//    cout<<WHITE;
//    SString S,S1;
//    char a[30] = "acabaabaabcacaabc";
//    char b[5] = "abc";
//    InitSString(S,a);
//    cout<<"主串："<<S<<endl;
//    InitSString(S1,b);
//    cout<<"模式串："<<S1<<endl;
//
//    int ind = Index_KMP(S,S1, 1);
//    cout<<"主串中模式串的第一个位置是: "<<ind<<endl;
