//
// Created by Carey on 2020/5/19.
//

#include "SString.h"

// 用T返回由S1 和 S2 链接而成的新串， 若未截断 ，则返回TRUE, 否则返回FALSE
Status Concat(SString &T, SString S1, SString S2)
{
    bool uncut;
    if( S1[0] + S2[0] <= MAXSTRLEN) {   //未截断
        for (int i = 1; i<= S1[0]; i++)
        {
            T[i] = S1[i];
        }
        for(int i = 1; i<= S2[0]; i++)
        {
            T[S1[0]+i] = S2[i];
        }
        T[0] = S1[0] + S2[0];
        uncut = TRUE;
    }
    else if(S1[0] < MAXSTRLEN){  // 截断
        for (int i = 1; i<= S1[0]; i++)
        {
            T[i] = S1[i];
        }
        for(int i = 1; i<= MAXSTRLEN -S1[0]; i++)
        {
            T[S1[0]+i] = S2[i];
        }
        T[0] = MAXSTRLEN;
        uncut = FALSE;
    }
    else{          //截断(仅取S1)
        for (int i=0; i<MAXSTRLEN; i++)
        {
            T[i] = S1[i];
            uncut = false;
        }

    }
    return uncut;
}

// 用Sub返回串S的第pos个字符起长度为len的子串
Status SubString(SString &Sub, SString S, int pos, int len)
{
    if(pos <1 || pos >S[0] || len <0 || len > S[0] -pos +1)
        return ERROR;
    for (int i =1; i<=len; i++)
    {
        Sub[i] = S[pos-1 +i];
    }
    Sub[0] = len;
    return OK;
}


// 重载输出远算符
ostream & operator<<( ostream & os,SString S)
{
    for(int i =1; i<=S[0]; i++)
    {
        os<<S[i];
    }
    return os;

}

// 重载输入运算符
istream & operator>>( istream & is,SString &S)
{
    char tem[20] ;
    cin >> tem;
    for(int i =0; i<= strlen(tem)-1; i++){
        S[i+1] = tem[i];
    }
    S[0] =strlen(tem);
    return is;
}


// 用字符数组初始化
void InitSString(SString &S, char *arr)
{
    S[0] = strlen(arr);
    for(int i = 1; i<= strlen(arr); i++)
    {
        S[i] = arr[i-1];
    }
}


