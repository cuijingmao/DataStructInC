#include <iostream>
#include <ctime>
using namespace  std;

#include "Applications/Polynomial/Polynomial.h"




int main() {
//    freopen("input.txt","r",stdin);
//    freopen("./output.txt", "w",stdout);

    cout<<YELLOW<<"初始化多项式："<<endl;
    cout<<WHITE;
    polynomial Polyn;
    float coef[] {1,2,4,5};
    int expn[] {2,3,4,5};
    InitPolyn(Polyn, coef,expn,4);
    PrintPolyn(Polyn);

    float coef1[] {1,-2.0, 3.0,5};
    int   expn1[] {2,3,4,8};
    polynomial Polyn1;
    InitPolyn(Polyn1, coef1,expn1,4);
    PrintPolyn(Polyn1);

    cout<<YELLOW<<"两多项式求和："<<endl;
    cout<<WHITE;
    AddPolyn(Polyn,Polyn1);
    PrintPolyn(Polyn);




//    AddPolyn(Polyn, Polyn2);
//    PrintPolyn(Polyn);


    //程序运行计时
    int64_t time_elapsed = clock();
    cout<<endl<<"程序共运行： "<<(double)time_elapsed/CLOCKS_PER_SEC<<"秒"<<endl;
    return 0;
}
