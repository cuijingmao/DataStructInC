#include <iostream>
#include <ctime>
using namespace  std;

#include "Stack/SqStack.h"
#include "Applications/NumeratiionConvert/conversion.h"
# include "Applications/LineEdit/LineEdit.h"
# include "Applications/Maze/MazePath.h"


int main() {
//    freopen("./input.txt","r",stdin);
//    freopen("./output.txt", "w",stdout);

    int sto[M][N];
    struct  mark  start, end;   // start, end 为入口和出口的坐标
    GetMazeFromFile(sto);   //建立迷宫
    start.x = 1;
    start.y =1;
    end.x = 8;
    end.y = 8;
    MazePath(start,end,sto);  //  寻找路径




    //程序运行计时
    int64_t time_elapsed = clock();
    cout<<endl<<"程序共运行： "<<(double)time_elapsed/CLOCKS_PER_SEC<<"秒"<<endl;
    return 0;
}
