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