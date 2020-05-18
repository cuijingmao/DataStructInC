//
// Created by Carey on 2020/5/17.
//

#include "MazePath.h"

int diradd[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};  // 东西南北向的 行增量和列增量

// 初始化空栈
int InitStack(PLStack &S){
    S = nullptr;
    return 1;
}

// 判断栈是否为空
int StackEmpty(PLStack S){
    if(S == nullptr)  return 1;
    else return 0;
}

// 压入新元素数据
int Push(PLStack &S, Element e)
{
    PLStack p;
    p = (PLStack) malloc(sizeof(LStack));
    p->elem =e;
    p->next =S;
    S = p;
    return 1;
}

// 栈顶元素初栈
int Pop(PLStack &S,Element &e)
{
    PLStack p;
    if(!StackEmpty(S))
    {
        e = S->elem;
        p =S;
        S=S->next;
        free(p);
        return 1;
    }
    else return 0;
}

//  求迷宫路径函数
void MazePath(struct mark start, struct mark end, int  maze[M][N])
{
    int i,j,d; int a,b;
    Element elem, e;
    PLStack S1,S2;
    InitStack(S1);   // 使用两个栈， 两次逆序即保持路径输出为正序
    InitStack(S2);
    maze[start.x][ start.y] = 2;  //入口点做上标记
    elem.x = start.x;
    elem.y = start.y;
    elem.d =-1;  //开始为-1
    Push(S1, elem);
    while(!StackEmpty(S1)) //栈不为空 有路径可走
    {
        Pop(S1, elem);
        i =elem.x;
        j = elem.y;
        d = elem.d + 1;
        while(d < 4)   // 试探东西南北各个方向
        {
            a = i + diradd[d][0];
            b = j + diradd[d][1];

            if( a == end.x && b == end.y && maze[a][b] == 0) // 如果到了出口
            {
                elem.x = i;
                elem.y = j;
                elem.d = d;
                Push(S1, elem);
                elem.x = a;
                elem.y = b;
                elem.d = 886;  //方向输出为-1 判断是否到了出口
                Push(S1, elem);

                cout<<YELLOW<<"通路为:({行坐标，咧坐标，方向} 0=东 1=南 2=西 3=北 886则走出迷宫) ："<<endl;
                cout<<WHITE;

                while (S1) // 逆置序列 并输出迷宫路径序列
                {
                    Pop(S1, e);
                    Push(S2, e);
                }
                while (S2) {
                    Pop(S2, e);
                    printf("--->(%d,%d，%d)", e.x, e.y, e.d);
                }
                return;    // 跳出两层循环
            }
            if(maze[a][b] == 0) //找到可以前进的非出口的点
            {
                maze[a][b] = 2;   //标记走过此点
                elem.x =i;
                elem.y =j;
                elem.d =d;

                Push(S1, elem);  // 当前位置入栈
                i = a;   // 下一点转化为当前点
                j = b;
                d =-1;   //  设为-1是为了进入下个结点后，经d++后 仍能从方向0开始搜索
            }
            d++;
        }
    }
    printf("没有找到可以走出此迷宫的路径\n");
}


//  建立迷宫
//void initmaze(int maze[M][N])
//{
//    int i,j;
//    int m,n ;
//    printf("请输入迷宫的行数 m=");
//    scanf("%d",&m);
//    printf("请输入迷宫的列数 n=" );
//    scanf("%d", &n);
//    printf("\n请输入迷宫的各行各列：\n用空格隔开，0代表路，1代表墙\n",m,n);
//    for(i =1; i<=m; i++)
//    {
//        for(j =1; j<=n; j++)
//        {
//            scanf("%d", &maze[i][j]);
//        }
//    }
//    printf("你建立的迷宫为(最外圈为墙)...\n");
//    for(i = 0; i<= m+1; i++)   //加一圈围墙
//    {
//        maze[i][0] =1;         // 西墙
//        maze[i][n+1] =1;       // 东墙
//    }
//    for(j = 0; j<=n+1; j++)   //加一圈围墙
//    {
//        maze[0][j] =1;         // 南墙
//        maze[m+1][j] =1;       // 北墙
//    }
//
//    for( i =0; j <= m+1; i++)
//    {
//        for( j =0; j<n+1; j++)
//        {
//            printf("%d", maze[i][j]);
//        }
//        printf("\n");
//    }
//}

//  从文件中读取迷宫矩阵
void  GetMazeFromFile(int maze[M][N])
{
    ifstream infile;
    infile.open("input.txt");
    for(int i = 0; i<M; i++)   //加一圈围墙
    {
        maze[i][0] =1;         // 西墙
        maze[i][N-1] =1;       // 东墙
    }
    for(int j = 0; j<N; j++)   //加一圈围墙
    {
        maze[0][j] =1;         // 南墙
        maze[M-1][j] =1;       // 北墙
    }

    for(int i = 1; i<M-1; i++)
    {
        for(int j =1; j < N -1; j++)
        {

            infile>>maze[i][j];
        }
    }

    cout<<YELLOW<<"读取迷宫矩阵(0-路，1-墙)："<<endl;
    cout<<WHITE;
    for(int i =0; i<M; i++)
    {

        for(int j =0; j<N; j++)
        {

           if(j > 0 && j<N-1 && i>0 && i< M-1){    //迷宫主体 变色突出显示
               cout<<BOLDMAGENTA<<maze[i][j]<<" ";
               cout<<WHITE;
           }
           else{
               cout<<maze[i][j]<<" ";
           }

            if(j ==N-1){
                cout<<"\n";
            }

        }
    }

}
