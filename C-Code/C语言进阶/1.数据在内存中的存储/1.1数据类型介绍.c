#include<stdio.h>
/*
char        //字符数据类型
short       //短整型
int         //整形
long        //长整型
long long   //更长的整形
float       //单精度浮点数
double      //双精度浮点数
//C语言有没有字符串类型？  没有
类型的意义：
1. 使用这个类型开辟内存空间的大小（大小决定了使用范围）。
2. 如何看待内存空间的视角。
*/


//1.类型的归类

//整形家族：
char
 //char有些编译器没有规定是unsigned还是signed
 unsigned char
 signed char
short
 unusigned short [int]
 signed short [int]
int
 unsigned int
 signed int
long
 unsigned long [int]
 signed long [int]


 //浮点数家族：
 float
 double


//构造类型：
/*
> 数组类型
> 结构体类型 struct
> 枚举类型 enum
> 联合类型 union
*/

//指针类型：
/*
int *pi;
char *pc;
float* pf;
void* pv;
*/

//空类型
/*
void 表示空类型（无类型）
通常应用于函数的返回类型、函数的参数、指针类型。
*/