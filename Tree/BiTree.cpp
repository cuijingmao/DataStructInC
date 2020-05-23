//
// Created by Carey on 2020/5/21.
//

#include "BiTree.h"

// 按先序次序输入 二叉树中节点的值(一个字符), 空格字符表示空树
// 构造二叉链表表示的二叉树T
Status CreateBiTree(BiTree &T);

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 先序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType e) )
{
    if( T)
    {
        if(Visit(T->data))
            if(PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit)) return OK;
        return ERROR;
    }
    else return OK;
} // PreOrderTravese



// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
    SqStack  S;
    SElemType p;
    InitStack(S);
    Push(S,T);   // 根指针进栈
    while( !StackEmpty(S)) {
        while(GetTop(S,p) && p)
            Push(S, p->lchild);     // 向左走到尽头
        Pop(S,p);  // 空指针退栈
        if(!StackEmpty(S))
        {
            Pop(S,p);
            if(!Visit(p->data))
                return ERROR;
            Push(S, p->rchild);
        } //if
    }//while
    return  OK;
}// InOrderTraverse

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse1(BiTree T, Status(*Visit)(TElemType e))
{
    SqStack S;
    SElemType  p;
    InitStack(S);
    p = T;
    while(p || !StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p = p ->lchild;    // 根指针进栈， 遍历左子树
        }
        else { // 根指针退栈， 访问根节点， 遍历右子树
            Pop(S, p);
            if(!Visit(p->data)) return ERROR;
            p = p ->rchild;
        }//else
    }//while
}// InOrderTraverse1

// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 中序遍历二叉树T,对每个结点调用Visit依次且仅一次   递归法
// 一旦Visit（）失败，则操作失败
Status  InOrderTraverse2(BiTree T, Status(*Visit)(TElemType e))
{
    if(T){
        if(InOrderTraverse2(T->lchild,Visit))
            if(Visit(T->data))
                if(InOrderTraverse2(T->rchild,Visit))
                    return OK;
        return ERROR;
    }
    else return OK;
}


// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 后序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
    if(T)
    {
        if(PostOrderTraverse(T->lchild,Visit))
            if(PostOrderTraverse(T->rchild,Visit))
                if(Visit(T->data)) return OK;
        return ERROR;
    } else  return OK;
}


// 采用二叉链表存储结构， Visit是对结点操作的应用函数
// 层序遍历二叉树T,对每个结点调用Visit依次且仅一次
// 一旦Visit（）失败，则操作失败
Status  LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e));


// 从 字符数组 创建 用二叉链 表示的二叉表
// n表示 字符数目 空格表示  null;
// mode 0 : 先序， mode 1: 中序， mode 2: 后序
// 由于 仅仅从 先序序列、中序序列、后序序列 任意一个都无法唯一确定整棵树，
// 这里选用 左右子树各一半的构造方法
Status CreateBiTreeFromArr(BiTree &T, char ch[],int n, int mode )
{
    if(mode ==0)  //先序遍历
    {
        if(n > 2 )
        {
            if(ch[0] == ' ')
                T = nullptr;
            else {
                if(!(T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
                T->data = ch[0];
                int mid = (n-1)/2;
                char pre[mid], aft[n-mid-1];

                for(int i=0; i<mid; i++)
                {
                    pre[i] = ch[i+1];   // ch第一个已经用了
                }
                for(int i = 0 ; i< n-mid -1; i++)
                {
                    aft[i] = ch[i+1+mid];
                }
                CreateBiTreeFromArr(T->lchild, pre, mid, mode);
                CreateBiTreeFromArr(T->rchild, aft, n-mid-1, mode);
                return OK;
            }
        }
        else  if( n ==2) // 判n==2 是防止因为二分区间时 出现对空区间的处理
        {
            if(!( T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->data = ch[0];
            if(!( T->lchild = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->lchild->data = ch[1];
            T->lchild->lchild = nullptr;
            T->lchild->rchild = nullptr;
            T->rchild = nullptr;
            return OK;
        }
        else {   // 最后一个结点
            if(!(T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->data = ch[0];
            T->lchild = nullptr;
            T->rchild = nullptr;
            return OK;
        }
        return FALSE;
    }// mode = 0  先序遍历

    if(mode ==1)  //中序遍历
    {
        int mid = n/2;
        if(n >2)
        {
            if(ch[mid] == ' ')
            {
                T = nullptr;
            }
            else{
                if(!(T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);

                T->data = ch[mid];
                char pre[mid], aft[n-mid-1];

                for(int i=0; i<mid; i++)
                {
                    pre[i] = ch[i];
                }
                for(int i = 0 ; i< n-mid-1; i++)
                {
                    aft[i] = ch[i+mid+1];
                }
                CreateBiTreeFromArr(T->lchild, pre, mid, mode);
                CreateBiTreeFromArr(T->rchild, aft, n-mid-1, mode);
                return OK;
            }
        }
        else if(n==2){  // 判n==2 是防止因为二分区间时 出现对空区间的处理
            if(!( T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->data = ch[1];
            if(!( T->lchild = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->lchild->data = ch[0];
            T->lchild->lchild = nullptr;
            T->lchild->rchild = nullptr;
            T->rchild = nullptr;
            return OK;
        }
        else {   // 最后一个结点
            if(!(T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->data = ch[0];
            T->lchild = nullptr;
            T->rchild = nullptr;
            return OK;
        }
        return FALSE;
    }// mode = 1 中序遍历

    if(mode ==2)  //后序遍历
    {
        if(n >1 )
        {
            if(ch[n-1] == ' ')
                T = nullptr;
            else {
                if(!(T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
                T->data = ch[n-1];

                int mid = (n-1)/2;
                char pre[mid], aft[n-mid-1];

                for(int i=0; i<mid; i++)
                {
                    pre[i] = ch[i];
                }
                for(int i = 0 ; i< n-mid-1; i++)
                {
                    aft[i] = ch[i+mid];
                }
                CreateBiTreeFromArr(T->lchild, pre, mid, mode);
                CreateBiTreeFromArr(T->rchild, aft, n-mid-1, mode);
                return OK;
            }
        }
        else if(n ==2) // 判n==2 是防止因为二分区间时 出现对空区间的处理
        {
            if(!( T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->data = ch[1];
            if(!( T->lchild = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->lchild->data = ch[0];
            T->lchild->lchild = nullptr;
            T->lchild->rchild = nullptr;
            T->rchild = nullptr;
            return OK;
        }
        else {   // 最后一个结点
            if(!(T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
            T->data = ch[0];
            T->lchild = nullptr;
            T->rchild = nullptr;
            return OK;
        }
        return FALSE;
    }// mode = 2 后序遍历

}



// 从 整数数组 创建 用二叉链 表示的二叉表
// n 表示 字符数目 -1表示  null;
// mode 0 : 先序， mode 1: 中序， mode 2: 后序
Status CreateBiTreeFromArr(BiTree &T, int arr[],int n, int mode )
{

}



// 节点值打印
Status PrintNodeValue(TElemType value){
    if((char) value == ' ')
        cout<<"_";
    else
        cout<<(char)value;
    return OK;
}