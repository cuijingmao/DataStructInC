//
// Created by Carey on 2020/5/17.
//

#include "LineEdit.h"

void LineEdit(){
    // 利用字符栈S, 从终端接收一行并传送至 调用过程的数据区
    SqStack S;
    InitStack(S);      //构造空栈S
    char ch = getchar();     //从终端接收第一个字符
    SElemType c;
    while( ch!= EOF){     //EOF为全文结束符
        while( ch != EOF && ch != '\n') {
            switch (ch) {
                case '#':
                    Pop(S, c);
                    break;   //仅当栈非空时退栈
                case '@':
                    ClearStack(S);
                    break; //重置为空栈
                default:
                    Push(S, ch);
                    break;     // 有效字符进栈，未考虑栈满情形
            }
            ch = getchar();  // 从终端接收下一个字符
        }
        PrintStackInChar(S);
        ClearStack(S);
        if( ch != EOF)  ch = getchar();
    }
    DestroyStack(S);

} // LineEdit

//  打印栈内容
void PrintStackInChar(SqStack S){
    SElemType arr[S.top - S.base];
    int i =0;
    SElemType *tem = S.top;
    while(tem != S.base){
        tem --;
        arr[i++] = *tem;
    }
    arr[i] = *S.base;
    cout<<"线性栈  长度： "<<S.top - S.base<<"  内容： [";
    for(int j = S.top - S.base-1; j>=0; j--){
        cout<<(char)arr[j];
        if(j !=0){
            cout<<", ";
        }
        else{
            cout<<")"<<endl;
        }
    }
}