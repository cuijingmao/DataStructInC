//
// Created by Carey on 2020/5/20.
//

#include "TSMatrix.h"

// 采用三元组表存储表示, 求稀疏矩阵M的转置矩阵T
Status TransposeSMatrix(TSMatrix M, TSMatrix &T){
    T.mu = M.mu ;
    T.nu = M.mu;
    T.tu = M.tu;

    if(T.tu){
        int q =1;
        for(int col =1; col<=M.tu; ++col)
        {
            for(int p =1; p<= M.tu; ++p)
            {
                if(M.data[p].j == col){
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q;
                }
            }
        }
    }
    return OK;
}


// 采用三元组表存储表示, 求稀疏矩阵M的转置矩阵T(快速方法）
Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int num[M.nu];
    if(T.tu)
    {
        for(int col =1; col <= M.nu; ++col)  num[col] =0;
        for(int t =1; t <= M.tu; ++t) ++num[M.data[t].j];     // 求M中每一列含非零元的个数
        int cpot[M.nu];
        cpot[1] = 1;
        // 求 M 第col列中第一个非零元在 T中的序号
        for( int col =2; col <= M.nu; col++)
        {
            cpot[col] = cpot[col-1] + num[col-1];
        }
        for( int p =1; p <= M.tu; ++p)
        {
            int col = M.data[p].j;
            int q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        }//for
    }//if
    return OK;
}



// *******************************************************************
//  以下为在 教材 基础上补充的辅助性函数  使其实用化
// *******************************************************************


// 使用 n *3  数组创建 TSMatrix
Status CreateTSMatrix(TSMatrix &M, ElemType  A[][3], int n)
{
    if(M.data[1].e)   free(M.data);
    M.mu = 0;
    M.nu = 0;
    M.tu = 0;

    int maxsize = 100;
    int rowMaxInd =0;

    int colMaxInd=0;

    for(int i =0; i<n;i++)
    {
        auto * triple = (Triple*) malloc(sizeof(Triple));
        rowMaxInd = max(rowMaxInd,A[i][0]);
        colMaxInd = max(colMaxInd,A[i][1]);
        triple->i = A[i][0];
        triple->j = A[i][1];
        triple->e = A[i][2];
        M.data[i+1] = *triple ;
    }
    M.tu = n;
    M.mu = rowMaxInd;
    M.nu = colMaxInd;
    return OK;
}


// 打印
ostream & operator<<(ostream &os, TSMatrix M)
{
    Triple  triple;
    for(int i =0; i<M.tu; i++)
    {
        triple = M.data[i+1];
        os<<triple.i<<"  "<<triple.j<<"  "<<triple.e<<endl;
    }
    return os;
}