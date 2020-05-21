#include <iostream>
#include <ctime>
using namespace  std;

#include "Array/TSMatrix.h"

void hh()
{

    int a[10] ={0};
    cout<<a[0]<< " "<<a[1];
    cout<<sizeof(a)<<endl;

}
int main() {
//    freopen("./input.txt","r",stdin);
//    freopen("./output.txt", "w",stdout);





    //程序运行计时
    int64_t time_elapsed = clock();
    cout<<endl<<"程序共运行： "<<(double)time_elapsed/CLOCKS_PER_SEC<<"秒"<<endl;
    return 0;
}
