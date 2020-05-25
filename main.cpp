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

    HuffmanTree HT;    // 赫夫曼树
    HuffmanCode HC;    // 赫夫曼编码
    char ch[] ="ABACCDAFDSEAABABCCDDBBCCCDEFABCDCCD";  //原始字符数组
    char UniqueChars[20];       // 不同的字符的集合
    unsigned int counts[20];    // 各个不同的字符的频次
    char binCode[500] ;         // 原始字符数组经赫夫曼编码后的二进制字符串
    char  chs[100];             // 二进制字符数组反解后的原字符串

    counting(ch,UniqueChars,counts);  //对原字符串进行必要统计

    cout<<YELLOW;
    cout<<"待编码字符序列中不同字符集合："<<endl;
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


    HuffmanCoding(HT,HC,counts,strlen(UniqueChars));  // 进行赫夫曼编码的计算与分配

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

    cout<<YELLOW;
    cout<<"对原字符数组进行赫夫曼(Huffman)编码："<<endl;
    cout<<WHITE;
    cout<<"原始字符数组: [";
    for(int i =0; i<strlen(ch)-1; i++)
    {
        cout<<ch[i]<<", ";
    }
    cout<<ch[strlen(ch)-1]<<"]"<<endl;

    encode(binCode,ch,UniqueChars,HC); // 使用赫夫曼编码对原始字符数组进行编码

    cout<<"编码后二进制数组: ";
    for(int i =0; i<strlen(binCode); i++)
    {
        cout<<binCode[i];
    }
    cout<<endl;

    cout<<YELLOW;
    cout<<"对编码后数组进行赫夫曼(Huffman)解码："<<endl;
    cout<<WHITE;

    decode(chs,binCode,UniqueChars,HC); // 对经赫夫曼编码的二进制串反解原字符串

    cout<<"[";
    for(int i =0; i<strlen(chs)-1; i++)
    {
        cout<<chs[i]<<", ";
    }
    cout<<chs[strlen(chs)-1]<<"]"<<endl;


    //程序运行计时
    int64_t time_elapsed = clock();
    cout<<endl<<"程序共运行： "<<(double)time_elapsed/CLOCKS_PER_SEC<<"秒"<<endl;


    return 0;
}
