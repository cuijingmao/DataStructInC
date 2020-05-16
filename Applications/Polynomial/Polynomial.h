//
// Created by Carey on 2020/5/14.
//

#ifndef C_POLYNOMIAL_H
#define C_POLYNOMIAL_H


#include "LinkListPoly.h"
using  namespace Polynomial;
using namespace LinkListPoly;
typedef LinkList polynomial;    // 用带头结点的有序链表表示多项式

// ---------------- 基本操作的函数原型说明              --------------------
// 输入m项的系数和指数，建立表示一元多项式的有序链表P
void CreatePolyn(polynomial &P, int m);

// 销毁一元多项式
void DestroyPolyn( polynomial &P);

// 打印输出一元多项式P
void PrintPolyn(polynomial P);

// 返回一元多项式P中的项数
int PolynLength(polynomial P);

// 多项式相加 Pa = Pa + Pb,并销毁Pb
void  AddPolyn(polynomial &Pa, polynomial &Pb);

// 完成多项式想减运算， 即 Pa = Pa - Pb, 并销毁一元多项式 Pb
void SubtractPolyn( polynomial &Pa, polynomial &Pb);

// 完成多项式相乘运算， 即 Pa = Pa * Pb， 并销毁一元多项式Pb
void MultiplyPolyn( polynomial &Pa, polynomial &Pb);

//Status  LocateElem(polynomial P, ElemType e, )

// 使用系数和指数数组初始化多项式
void InitPolyn(polynomial &P, const float * coef, const int * expn, int n);


#endif //C_POLYNOMIAL_H
