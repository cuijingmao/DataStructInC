//
// Created by Carey on 2020/5/19.
//

#include "HString.h"

// 生成一个其值等于串常量 chars 的串T
Status StrAssigbn(HString &T, char *chars)
{
    if(T.ch)  free(T.ch);        // 释放T原有空间
    int i;
    auto c = chars;
    for(i =0; *c; ++i, ++c);  // 求chars 的长度
    if(!i) {
        T.ch = NULL;
        T.length =0;
    }
    else {
        if( !(T.ch = (char *) malloc(i * sizeof(char))))
            exit(OVERFLOW);
        for(int j = 0; j<i; j++)
        {
            T.ch[j] = chars[j];
        }
        T.length =i;
    }
    return OK;
}

// 返回S的元素个数，称为 串的长度
int StrLength(HString S){
    return S.length;
}

// 若S>T ,则返回值> 0; 若 S=T，则返回值=0； 若 S<T, 则返回值 <0
int StrCompare(HString S, HString T){
    for(int i =0;  i <S.length && i <T.length; i++)
        if( S.ch[i] != T.ch[i] ) return S.ch[i] - T.ch[i];
    return S.length -T.length;
}

// 将S清为空串，并释放S所占的空间
Status ClearString(HString &S)
{
    if(S.ch) {
        free(S.ch);
        S.ch =nullptr;
    }
    S.length =0;
    return OK;
}

// 用T返回由S1和S2联接而成的新串
Status Concat(HString &T, HString S1, HString S2)
{
    if( T.ch) free(T.ch);   //释放旧空间
    if(!(T.ch = (char*) malloc((S1.length + S2.length) *sizeof(char))))
        exit(OVERFLOW);
    for(int i =0; i<S1.length; i++)
        T.ch[i] = S1.ch[i];
    T.length = S1.length + S2.length;
    for(int j =S1.length; j<T.length; j++)
         T.ch[j] = S2.ch[j - S1.length];
    return OK;
}


// 返回串S的第pos个字符起长度为len的子串
// 1<= pos <= StrLength(S)  且 0<= len <= StrLength(S)- pos +1
Status SubString(HString  &Sub, HString S, int pos, int len)
{
    if(pos <1 || pos > S.length || len <0 || len > S.length -pos +1)
        return ERROR;
    if(Sub.length >0)  free(Sub.ch);
//    if( Sub.ch)   free(Sub.ch);   // 释放旧空间  有问题！！！
    if(!len) {
        Sub.ch =nullptr;
        Sub.length = 0;  // 空子串
    }
    else {
        Sub.ch = (char*) malloc(len * sizeof(char));
        for(int i =0; i <len ; i++)
        {
            Sub.ch[i] =  S.ch[pos+ i -1];
        }
        Sub.length =len;
    }
    return OK;
}

// 打印字符串
ostream & operator<< (ostream & os, HString S)
{
    for(int i=0; i <S.length; i++)
    {
        os<<S.ch[i];
    }
    return os;
}
