#include <iostream>
#include <ctime>
using namespace  std;

#include "Stack/SqStack.h"
#include "Applications/NumeratiionConvert/conversion.h"
# include "Applications/LineEdit/LineEdit.h"
# include "Applications/Maze/MazePath.h"
#include "string/SString.h"

int main() {
//    freopen("./input.txt","r",stdin);
//    freopen("./output.txt", "w",stdout);


    cout<<"定长顺序存储串的表示  "<<endl;
    SString S;
    S[0] = 2;
    S[1] = 'C';
    S[2] = 'H';
    cout<<"S 的内容： "<<S<<endl;

    cout<<"请输入S2的内容:  ";
    SString S2;
    cin>>S2;
    cout<<"S2 的内容： "<<S2<<endl;

    SString T;
    Concat(T,S,S2);
    cout<<"S 和 S2拼接后为："<<T<<"  长度为：" <<(int)T[0] <<endl;

    SString S3, S4;
    char a[30] = "I love you";
    InitSString(S3,a);
    SubString(S4, S3, 3, 4);
    cout<<"字符串："<<S3<<" 的一个子串为： "<<S4<<endl;




    //程序运行计时
    int64_t time_elapsed = clock();
    cout<<endl<<"程序共运行： "<<(double)time_elapsed/CLOCKS_PER_SEC<<"秒"<<endl;
    return 0;
}
