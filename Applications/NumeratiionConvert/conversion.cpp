//
// Created by Carey on 2020/5/17.
//

#include "conversion.h"
void conversion(){
    int N;
    SqStack S;
    InitStack(S);
    scanf("%d", &N);
    while(N){
        Push(S,N%8);
        N = N/8;
    }
    while( !StackEmpty(S)){
        ElemType e;
        Pop(S,e);
        printf("%d",e);
    }


}