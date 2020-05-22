//
// Created by Carey on 2020/5/21.
//

#include "RLSMatrix.h"

// 求矩阵乘积 Q = M*N ， 采用行逻辑联接存储 表示
Status MultiSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)
{
    if(M.nu != N.mu) return  ERROR;
    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;   //Q初始化
    if(M.tu * N.tu != 0)   // Q为非零矩阵
    {
        int ctemp[100];
        for(int arow=1; arow<= M.mu; ++arow)   // 处理M的每一行
        {
//            for(int i =0 ; i<100;i++){
//                ctemp[i] =0;       // 当前行各元素累加器清零
//            }
            for(int & i : ctemp){  // 等效于上面的语句
                i =0;       // 当前行各元素累加器清零
            }
            Q.rpos[arow] = Q.tu +1;
            int tp;
            if( arow < M.mu){
                tp = M.rpos[arow +1];
            }
            else{
                tp = M.tu +1;
            }
            for( int p = M.rpos[arow]; p <tp; ++p)
            {
                int brow = M.data[p].j;     //找到对应元在N中的行号
                int t;
                if(brow < N.mu) t = N.rpos[brow + 1];
                else t = N.tu +1;
                for( int q = N.rpos[brow]; q <t; ++q)
                {
//                    int ccol = N.data[q] .j
                }
            }
        }
    }

}
