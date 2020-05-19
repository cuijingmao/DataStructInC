//
// Created by Carey on 2020/5/19.
//

#include "BFMatch.h"

// 返回子串T中第 pos个字符之后的位置， 若不存在， 则函数值 为0
// 其中，T非空， 1<= pos <= StrLength(S)
int Index(SString S, SString T, int pos){
    int i = pos;  int j =1;
    while( i <= S[0] && j <= T[0]){
        if(S[i] == T[j])
        {
            ++i;
            ++j;   // 继续比较后继字符
        }
        else {
            i = i - j + 2;
            j = 1;      //指针后退 重新开始匹配
        }
    }
    if(j >T[0]) return i-T[0];
    else return 0;
}