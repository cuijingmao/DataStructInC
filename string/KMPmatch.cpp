//
// Created by Carey on 2020/5/19.
//

#include "KMPmatch.h"

// 利用模式串 T的next 函数求 T在 主中第pos个字符之后的位置 的  KMP算法
// 其中， T非空， 1<= pos <<StrLength(S);
int Index_KMP(SString S,SString T, int pos){
    int next[30] ;
    get_nextval(T, next);
    int i = pos;
    int j = 1;
    while( i <= S[0] && j <= T[0]) {
        if( j ==0 || S[i] == T[j])
        {
            ++i;
            ++j;    // 继续比较后继字符
        }
        else{
            j = next[j];    // 模式串向右移动
        }
    }

    if( j > T[0])  return i - T[0];   // 匹配成功
    else return 0;
} // Index_KMP

// 求模式串T的next函数值 并存入数组 next
void get_next(SString T, int next[])
{
    int i = 1;
    next[1] =0;
    int j = 0;
    while(i < T[0]){
        if( j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else j = next[j];
    }

}// get_next


// 求模式串T的 next函数修正值并存入数组nextval
void get_nextval(SString T, int nextval[])
{
    int i = 1;
    nextval[1] =0;
    int j =0;
    while(i <T[0])
    {
        if( j ==0 || T[i] == T[j]){
            ++i; ++j;
            if(T[i] != T[j])  nextval[i] = j;
            else nextval[i] = nextval[j];
        }
        else  j = nextval[j];
    }
} // get_nextval