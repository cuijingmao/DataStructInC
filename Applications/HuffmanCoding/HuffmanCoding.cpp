//
// Created by Carey on 2020/5/24.
//

#include "HuffmanCoding.h"


// 求赫夫曼编码的算法
// w存放n个字符的权值(均>0)，构造赫夫曼树HT,并求出n个字符的赫夫曼编码HC
// n为叶子结点个数DDDDDS
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, unsigned int n)
{
    if(n <=1) return;
    int m = 2 * n -1;
    HT = (HuffmanTree) malloc((m+1)* sizeof(HTNode));  // 0号单元未用
    HuffmanTree p= HT +1;

    // n个叶子结点 赋值相应的权值，
    // 由于自底而上建树，未知父子关系，因此初始化为0
    for(   int i=1; i<=n;++i,++p,++w)
        *p = {*w, 0, 0,0};
    // n-1个非叶子结点
    // 由于自底而上建树，未知父子关系，因此初始化为0 权值初始化为0
    for(int i = n+1; i<= m; ++i,++p)
        *p = {0,0,0,0};

    // 建 赫夫曼树
    // 建树过程 是 确定 n-1个非叶子结点的父子关系和权值 的过程
    for(int i = n+1; i<= m; ++i) {
        // 在 HT[1..i-1] 选择parent 为0且weight最小的两个结点， 其序号分别为s1和s2.
        unsigned int s1, s2;
        Select(HT, i-1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        // 以下两句 体现了 高级技巧
        // 没这两句，则每次s1和s2都是一样的！
        // 每次合并子树后， 被合并的子树以后就不再参与比较！
        // 通过UINT_MAX/2作差， 可以将s1、s2变为最大，从而退出以后的比较！
        // 还方便还原原来的权重！
        HT[s1].weight = UINT_MAX/2 - HT[s1].weight;
        HT[s2].weight = UINT_MAX/2 - HT[s2].weight;
    }

    cout<<YELLOW;
    cout<<"各结点在赫夫曼树中的权重(前"<<n<<"个为叶子结点，最后一个为根结点):"<<endl;
    cout<<WHITE;
    cout<<"[";
    for(int j =1 ; j< m; j++)
    {
        cout<<UINT_MAX/2-HT[j].weight<<", ";
    }
    cout<<HT[m].weight<<"]"<<endl;    // 最后一个不用 反减

    cout<<YELLOW;
    cout<<"各结点在赫夫曼树中的父结点(前"<<n<<"个为叶子结点，最后一个为根结点)："<<endl;
    cout<<WHITE;
    cout<<"[";
    for(int i =1; i<m; i++)
    {
        cout<<HT[i].parent<<", ";
    }
    cout<<HT[m].parent<<"]"<<endl;
    //  从叶子到根 逆向 求每个字符的 赫夫曼编码
    HC = (HuffmanCode) malloc((n+1)*sizeof(HuffmanCode));  // 分配n个字符编码的头指针向量
    char *cd = (char*) malloc(n * sizeof(char));     // 分配求编码的工作空间
    cd[n-1] = '\0';
    for(int i =1; i<= n; ++i)     // 逐个字符求赫夫曼编码
    {
        unsigned int start =  n-1;   // 编码结束符位置
        unsigned int c= i;
        unsigned int f = HT[i].parent;
        for(; f!=0; c =f, f = HT[f].parent )
        {
            if(HT[f].lchild == c)
            {
                cd[--start] = '0';
            }
            else {
                cd[--start] = '1';
            }
        }
        HC[i] = (char *) malloc((n-start)* sizeof(char)); // 为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);   //从cd复制编码(串)到HC
    }
    free(cd);   // 释放工作空间
}// HuffmanCoding



// 从赫夫曼(Huffman)树 中选择权值 最小的两个 结点 并返回其 位序
// 即 Ht[1..n] 中选出 权值最小的两个 将其位序 通过s1 和 s2返回
Status Select(HuffmanTree HT, unsigned int n,unsigned int &min1_ind, unsigned int &min2_ind)
{
    unsigned int w[n+1], min1,min2;
    for(int i =1; i <= n; i++)
    {
        w[i] = HT[i].weight;
    }

    if(w[2] < w[1])
    {
        min1 = w[2];
        min1_ind = 2;
        min2 = w[1];
        min2_ind = 1;
    }
    else {
        min1 = w[1];
        min1_ind = 1;
        min2 = w[2];
        min2_ind = 2;
    }

    for(int i =3; i<=n; i++)
    {
        if( w[i] >= min2)  // 不是最小的两个权值之一  min1<min2<w[2]
        {
            continue;
        }
        else if( w[i] < min1)  // w[i]<min1<min2
        {
            unsigned int  tmp = min1;
            unsigned int tmp_ind  = min1_ind;
            min1 = w[i];
            min1_ind = i;
            min2 = tmp;
            min2_ind = tmp_ind;
        }else{                 // min[1]<w[i]<min2
            min2 = w[i];
            min2_ind = i;
        }
    }
//    HT[min1_ind].weight = UINT_MAX/2 - HT[min1_ind].weight;
//    HT[min2_ind].weight = UINT_MAX/2 - HT[min2_ind].weight;
    return OK;
}


// 统计一字符数组 各字符出现的频次 作为  赫夫曼编码的 权重数据
// ch为待统计字符数组，uniqueChars为各个无重复的字符 组成的字符数组
// counts数组各元素对应 uniqueChars中各元素的 频次
Status counting(char ch[], char* &UniqueChars,  unsigned int* &counts)
{
    if(! ch)  return ERROR;
    int len = strlen(ch);


    // 统计子串不同字符个数
    UniqueChars = (char *) malloc(sizeof(char)* len);  // 设得足够大，以备字符各不相同的情况
    UniqueChars[0] = ch[0];
    int uniqueCounts =1;
    for(int i = 1; i<len ; i++)
    {
        bool  isUnique = true;
        for(int j =0; j<uniqueCounts; j++)
        {
            if( ch[i] == UniqueChars[j])
                isUnique = false;
        }
        if(isUnique){
            UniqueChars[uniqueCounts] = ch[i];
            uniqueCounts++;
        }
    }

    // 统计不同字符的频次
//    free(counts);
//    counts = nullptr;
    counts = (unsigned int*) malloc(sizeof(unsigned int)* uniqueCounts);
    for(int i =0; i<uniqueCounts;i++)
    {
        int repeats =0;
        for(int j =0 ; j<len ; j++)
        {
            if(ch[j] == UniqueChars[i])
                repeats++;
        }
        counts[i] = repeats;
    }
    return OK;
}
