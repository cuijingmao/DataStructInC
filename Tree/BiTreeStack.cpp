//
// Created by Carey on 2020/5/23.
//

#include "BiTreeStack.h"


namespace BiTreeStack{
// 构造一个空栈
    Status InitStack(SqStack &S){
        S.base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
        if(!(S.base)) exit(OVERFLOW);    //存数分配失败
        S.top = S.base;
        S.stacksize = STACK_INIT_SIZE;
        return OK;
    }// InitStack;

// 销毁栈S，S不再存在
    Status DestroyStack(SqStack &S){
        if( S.base ){
            free(S.base);
            S.base = nullptr;
            S.top = nullptr;
            S.stacksize = 0;
            return OK;
        }
        return FALSE;
    }

// 把S置为空栈
    Status ClearStack(SqStack &S){
        if(S.base){
            S.top = S.base;
        }
        return OK;
    }

// 若S为空栈,则返回TRUE，否则返回FALSE
    Status StackEmpty(SqStack S){
        if(S.base == S.top)  return TRUE;
        else return FALSE;
    }

// 返回S的元素个数，即栈的长度
    int StackLength(SqStack S);

// 若栈不空，则用e返回S的栈顶元素，并返回OK,否则返回ERROR
    Status GetTop(SqStack S, SElemType &e){
        if(S.top == S.base) return ERROR;
        e = *(S.top - 1);
        return OK;
    }

// 插入元素e为新的栈顶元素
    Status Push(SqStack &S, SElemType e){
        if(S.top - S.base >= S.stacksize){  // 栈慢，追加存储空间
            S.base = (SElemType *) realloc(S.base, (S.stacksize + STACKINCREMENT)* sizeof(SElemType));
            if(! S.base) exit(OVERFLOW);  // 存储分配失败
            S.top = S.base+ S.stacksize;
            S.stacksize += STACKINCREMENT;
        }
        *S.top ++ =e;
        return OK;
    }

// 若栈不空，则删除S的栈顶元素， 用e返回其值， 并返回OK；否则返回ERROR
    Status Pop(SqStack &S, SElemType &e){
        if(S.top ==S.base) return ERROR;
        S.top --;
        e = *S.top;
        return OK;
    }

// 从栈顶到栈底依次对栈中每个元素调用函数visit(), 一旦visit()失败，则操作失败
    Status SqStackTraverse(SqStack S,Status(*visit)());

// 使用数组初始化栈
    Status InitStackWisthArr(SqStack &S ,const SElemType *arr, int n){
        if(n<1) exit(ERROR);
        S.base = (SElemType*) malloc(sizeof(SElemType) *(n+5)); //多分配5个空间
        S.top = S.base;

        for(int i =0 ; i<n ;i++){
            *S.top = arr[i];
            S.top ++;
        }
        S.stacksize = n+5;
        return OK;
    }

//  打印栈内容
    void PrintStack(SqStack S){
        SElemType arr[S.top - S.base];
        int i =0;
        SElemType *tem = S.top;
        while(tem != S.base){
            tem --;
            arr[i++] = *tem;
        }
        arr[i] = *S.base;
        cout<<"线性栈  长度： "<<S.top - S.base<<"  内容： [";
        for(int j = S.top - S.base-1; j>=0; j--){
            cout<<arr[j];
            if(j !=0){
                cout<<", ";
            }
            else{
                cout<<")"<<endl;
            }
        }
    }
}