#include <iostream>
#include <ctime>
using namespace  std;

#include "Applications/HuffmanCoding/HuffmanCoding.h"

int main() {
//    freopen("./input.txt","r",stdin);
//    freopen("./output.txt", "w",stdout);


    cout<<YELLOW;
    cout<<"对字符串序列进行赫夫曼(Huffman)编码"<<endl;
    cout<<WHITE;

    char ch[] ="ABACCDADDDFFAAARRRBBCC";
    unsigned int *counts;
    char *UniqueChars;

    counting(ch,UniqueChars,counts);
    cout<<YELLOW;
    cout<<"待编码字符序列："<<endl;
    cout<<WHITE;
    cout<<"[";
    for(int i =0; i<strlen(ch)-1; i++)
    {
        cout<<ch[i]<<", ";
    }
    cout<<ch[strlen(ch)-1]<<"]"<<endl;

    cout<<YELLOW;
    cout<<"待编码字符序列："<<endl;
    cout<<WHITE;
    cout<<"[";
    for(int i =0; i<strlen(UniqueChars)-1; i++)
    {
        cout<<UniqueChars[i]<<", ";
    }
    cout<<UniqueChars[strlen(UniqueChars)-1]<<"]"<<endl;

    cout<<YELLOW;
    cout<<"待编码字符频次统计："<<endl;
    cout<<WHITE;
    cout<<"[";
    for(int i =0; i<strlen(UniqueChars)-1; i++)
    {
        cout<<counts[i]<<", ";
    }
    cout<<counts[strlen(UniqueChars)-1]<<"]"<<endl;

    HuffmanTree HT;    // 赫夫曼树
    HuffmanCode HC;    // 赫夫曼编码
    HuffmanCoding(HT,HC,counts,strlen(UniqueChars));
    cout<<YELLOW;
    cout<<"分配给各字符的赫夫曼编码："<<endl;
    cout<<WHITE;
    for(int i =0; i<strlen(UniqueChars); i++)
    {
        cout<<UniqueChars[i]<< " :   ";
        char *tem = HC[i+1];
        for(int j =0; j<strlen(tem);j++)
        {
            cout<<tem[j];
        }
        cout<<endl;
    }


    //程序运行计时
    int64_t time_elapsed = clock();
    cout<<endl<<"程序共运行： "<<(double)time_elapsed/CLOCKS_PER_SEC<<"秒"<<endl;


    return 0;
}
