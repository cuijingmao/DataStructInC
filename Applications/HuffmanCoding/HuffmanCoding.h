//
// Created by Carey on 2020/5/24.
// 赫夫曼(Huffman)编码实现

#ifndef C_HUFFMANCODING_H
#define C_HUFFMANCODING_H

// *************************************************************
// 以下是 辅助性的代码 非重点
// *************************************************************
#ifndef  MY_COMMON_BLOCK
#define  MY_COMMON_BLOCK

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace  std;

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define UNDERFLOW -3

typedef short Status;
#endif //MY_COMMON_BLOCK
// *************************************************************
// 以上是 辅助性的代码 非重点
// *************************************************************

//----------赫夫曼树和赫夫曼编码的存储表示----------------
typedef struct {
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;        // 动态分配数组存储赫夫曼树

typedef char* *HuffmanCode;    //动态分配数组存储赫夫曼编码树

// 求赫夫曼编码的算法
// w存放n个字符的权值(均>0)，构造赫夫曼树HT,并求出n个字符的赫夫曼编码HC
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, unsigned int n);

// 从赫夫曼(Huffman)树 中选择权值 最小的两个 结点 并返回其 位序
// 即 Ht[1..n] 中选出 权值最小的两个 将其位序 通过s1 和 s2返回
// HT的前n个分量表示叶子结点，最后一个分量表示根节点
Status Select(HuffmanTree HT, unsigned int n,unsigned int &min1_ind, unsigned int &min2_ind);

// 统计一字符数组 各字符出现的频次 作为  赫夫曼编码的 权重数据
// ch为待统计字符数组，uniqueChars为各个无重复的字符 组成的字符数组
// counts数组各元素对应 uniqueChars中各元素的 频次
Status counting(char ch[], char* &UniqueChars,  unsigned int* &counts);

#endif //C_HUFFMANCODING_H


//    cout<<YELLOW;
//    cout<<"对字符串序列进行赫夫曼(Huffman)编码"<<endl;
//    cout<<WHITE;
//
//    char ch[] ="ABACCDADDDFFAAARRRBBCC";
//    unsigned int *counts;
//    char *UniqueChars;
//
//    counting(ch,UniqueChars,counts);
//    cout<<YELLOW;
//    cout<<"待编码字符序列："<<endl;
//    cout<<WHITE;
//    cout<<"[";
//    for(int i =0; i<strlen(ch)-1; i++)
//    {
//        cout<<ch[i]<<", ";
//    }
//    cout<<ch[strlen(ch)-1]<<"]"<<endl;
//
//    cout<<YELLOW;
//    cout<<"待编码字符序列："<<endl;
//    cout<<WHITE;
//    cout<<"[";
//    for(int i =0; i<strlen(UniqueChars)-1; i++)
//    {
//        cout<<UniqueChars[i]<<", ";
//    }
//    cout<<UniqueChars[strlen(UniqueChars)-1]<<"]"<<endl;
//
//    cout<<YELLOW;
//    cout<<"待编码字符频次统计："<<endl;
//    cout<<WHITE;
//    cout<<"[";
//    for(int i =0; i<strlen(UniqueChars)-1; i++)
//    {
//        cout<<counts[i]<<", ";
//    }
//    cout<<counts[strlen(UniqueChars)-1]<<"]"<<endl;
//
//    HuffmanTree HT;    // 赫夫曼树
//    HuffmanCode HC;    // 赫夫曼编码
//    HuffmanCoding(HT,HC,counts,strlen(UniqueChars));
//    cout<<YELLOW;
//    cout<<"分配给各字符的赫夫曼编码："<<endl;
//    cout<<WHITE;
//    for(int i =0; i<strlen(UniqueChars); i++)
//    {
//        cout<<UniqueChars[i]<< " :   ";
//        char *tem = HC[i+1];
//        for(int j =0; j<strlen(tem);j++)
//        {
//            cout<<tem[j];
//        }
//        cout<<endl;
//    }