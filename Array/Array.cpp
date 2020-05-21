//
// Created by Carey on 2020/5/19.
//

#include "Array.h"
// 若维数dim 和随后的各维长度合法， 则构造相应的数组A，并返回OK
Status InitArray(Array &A, int dim, ...){
    if(dim <1 || dim > MAX_ARRAY_DIM) return ERROR;
    A.dim =dim;
    A.bounds = (int *) malloc(dim * sizeof(int));
    if(!A.bounds) exit(OVERFLOW);
    // 若各维长度合法， 则存入A.bounds, 并求出A的元素总数 elemtotal
    int elemtotal =1;
    va_list ap;
    va_start( ap,dim);    // ap为va_list类型， 是存放变长参数表信息的数组
    for(int i =0; i< dim; ++i)
    {
        A.bounds[i] = va_arg(ap,int);
        if(A.bounds[i] < 0) return UNDERFLOW;
        elemtotal *= A.bounds[i];

    }
    va_end(ap);
    A.base = (ElemType *) malloc(elemtotal * sizeof(ElemType));

    if(!A.base) exit(OVERFLOW);

    A.constants = (int *) malloc(dim * sizeof(int));    // 必须先 分配内存
//     求映像函数的常数c, 并存入A.constants[i-1] , i=1,...,dim
    A.constants[dim-1] = 1;   //L=1, 指针的增减 以元素的大小为单位
    for(int i = dim -2; i>=0; --i)
    {
        A.constants[i] = A.bounds[i+1] * A.constants[i+1];
    }
    return OK;
}

// 销毁数组A
Status DestroyArray(Array &A){
    if(!A.base) return ERROR;
    free(A.base);
    A.base = nullptr;
    if (!A.bounds) return ERROR;
    free(A.bounds); A.bounds =nullptr;
    if(!A.constants) return ERROR;
    free(A.constants);
    A.constants = nullptr;
    return OK;
}

// 若ap指示的各下标值合法， 则求出该元素在A中相对地址off
Status Locate(Array A, va_list ap, int &off){
    off =0;
    for( int i =0; i<A.dim; ++i)
    {
        int ind = va_arg(ap, int);
        if(ind < 0 || ind >= A.bounds[i]) return OVERFLOW;
        off += A.constants[i] *ind;
    }
    return OK;
}

// A 是 n 纬数组， e为元素变量，随后是n个下标值。
// 若下标不超界， 则将e的值赋给指定的A的元素，并返回OK
Status Value(Array A,ElemType &e, ...){
    va_list ap;
    va_start(ap,e);
    int result, off;
    if((result = Locate(A,ap,off))<= 0 ) return result;
    cout<<off<<endl;
    e = *(A.base + off);
    return OK;
}

// A 是n维数组，e为元素变量， 随后是n个下标值，
// 若下标不越界， 则将e的值赋给指定的A的元素,并返回OK
Status Assign(Array &A, ElemType e, ...){
    va_list ap;
    int result,off;
    if( (result = Locate(A,ap,off) <=0)) return result;
    *(A.base + off) =e;
    return OK;
}

// 获取数组长度：
int ArrayLength(Array A)
{
    if(! A.bounds || !A.dim) exit(FALSE);
    int length =1;
    for(int i =0 ; i< A.dim ; i++)
    {
        length *= A.bounds[i];

    }
    return length;
}

// 使用数组初始化 Array
Status AssignArray(Array & A, ElemType *arr, int n)
{
    int len =ArrayLength(A);
    if(n >= len)
    {
        for(int i =0; i<len ; i++)
        {
            A.base[i] = arr[i];
        }
    }
    else {
        for (int i =0; i<n; i++)
        {
            A.base[i] = arr[n];
        }
    }
    return OK;
}



// 重载 流输出运算符
// 将多维矩阵  按最后一维 "拉平"成二维显示
// 对二维来讲  就是 矩阵每行打印成一行
ostream & operator<<(ostream &os, Array A){
    if(!A.bounds ||!A.dim ||!A.base ||!A.constants)
        return os;
    int ElemsPerLine = ArrayLength(A)/A.bounds[A.dim-1];
    for(int i =0; i<ArrayLength(A); i++)
    {
        cout<<A.base[i]<<" ";
        if( (i+1)% ElemsPerLine ==0)
            cout<<endl;               // 每行单独显示维一行

    }

    return os;
}


