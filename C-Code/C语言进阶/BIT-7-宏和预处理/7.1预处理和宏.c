#include <stdio.h>
/* 1.预定义符号
__FILE__      //进行编译的源文件
__LINE__     //文件当前的行号
__DATE__    //文件被编译的日期
__TIME__    //文件被编译的时间
__STDC__    //如果编译器遵循ANSI C，其值为1，否则未定义
这些预定义符号都是语言内置的。
举个例子：
int main()
{
    printf("%s\n", __FILE__); //如：1.c
    printf("%d\n", __LINE__); // 16
    printf("%s\n", __DATE__); // Oct 15 2022
    printf("%s\n", __TIME__); // 17:26:06  记录的时间是编译的时间
    //printf("%d\n", __STDC__);   //未定义  不遵循ANSI C
    return 0;
}

*/

// 2.#define

// 2.1 #define 定义标识符

/*
#define MAX 100
#define STR "bitejiujiuyeke"
#define do_forever for(;;)
int main()
{
    printf("%d\n",MAX);   //100
    printf(STR);   //bitejiujiuyeke
    do_forever;   //死循环
    return 0;
}
 */

/* //#define后面不要加分号
#define MAX 1000;
int main()
{
    int max = 0;
    if (3 > 5)
        //max = MAX;   //报错  因为MAX ==1000; 出现了两个分号
        max = MAX    //正确
    else
        max = 0;
    return 0;
}
 */

// 2.2 #define定义宏 - #define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏（macro）或定义宏（define macro）。

/*
//函数解决
int Max_hanshu(int x, int y)
{
    return x > y ? x : y;
}
//宏解决
#define MAX(x, y) (x > y ? x : y)
int main()
{
    int a = 10;
    int b = 20;
    int max = Max_hanshu(a, b);
    int m = MAX(a, b);
    printf("%d\n", max);
    printf("%d\n", m);
    return 0;
} */

// define的一些问题
/*
#define SQUARE(X) X *X
#define SQUARE1(X) (X) * (X)
#define DOUBLE(X) (X) + (X)
#define DOUBLE1(X) ((X) + (X))
int main()
{
    printf("%d\n", SQUARE(5));      // 25
    printf("%d\n", SQUARE(5 + 1));  // 5+1*5+1 == 11
    printf("%d\n", SQUARE1(5 + 1)); // 36

    printf("%d\n", DOUBLE(6));      // 12
    printf("%d\n", DOUBLE(6 + 1));  // 14
    printf("%d\n", 10 * DOUBLE(6)); // 66  10*(6)+(6) ==66
    printf("%d\n", 10 * DOUBLE1(6));   //120
    return 0;
} */

// 2.3#define的替换规则
//在程序中扩展 #define定义符号和宏时，需要涉及几个步骤。
// 1. 在调用宏时，首先对参数进行检查，看看是否包含任何由 #define定义的符号。如果是，它们首先被替换。
/*
#define M 10
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int main()
{
    int m = MAX(2 + 3, M); //这里的M直接替换成10
    return 0;
} */
// 2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值所替换。
// 3. 最后，再次对结果文件进行扫描，看看它是否包含任何由 #define定义的符号。如果是，就重复上 述处理过程。

/* 注意：
1. 宏参数和#define 定义中可以出现其他#define定义的符号。但是对于宏，不能出现递归。
2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。 */

// 2.4#和##
//如何把参数插入到字符串中？
/*
int main()
{
    printf("Hello World\n");
    printf("Hello " "World\n");
    return 0;
} */

//使用 # ，把一个宏参数变成对应的字符串。
/*
#define PRINT(val,format) printf("the value of "#val" is "format"\n",val)
int main()
{
    //以下代码比较冗余
    int a = 10;
    PRINT(a,"%d");


    int b = 20;
    PRINT(b,"%d");

    float f = 3.5f;
    PRINT(f,"%f");
    return 0;
} */

//## - ##可以把位于它两边的符号合成一个符号。 它允许宏定义从分离的文本片段创建标识符。
/*
#define CAT(A,B) A##B
int main()
{
    int Class107 = 100;
    printf("%d\n",CAT(Class,107));   //100   Class107
    return 0;
} */

// 2.5有副作用的宏参数
//例子：有副作用的代码
/*
int main()
{
    int a = 1;
    int b = a + 1; // b=2,a=1

    a = 1;
    b = ++a; // b=2,a=2  带有副作用的代码

    int ch = getchar();  //读一个字符，缓冲区少一个字符

    return 0;
} */

//有副作用的宏参数
/*
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int main()
{
    int a = 3;
    int b = 4;
    int m = MAX(++a, ++b);
    //int m = ((++a) > (++b) ? (++a) : (++b));   4>5   a=4  b =6
    printf("m=%d a=%d b=%d\n", m, a, b); // 6 4 6
    return 0;
} */

// 2.6宏和函数对比
/*
int Max(int x, int y)
{
    return x > y ? x : y;
}

#define MAX(x, y) ((x) > (y) ? (x) : (y))
int main()
{
    int a = 10;
    int b = 20;
    //函数的方式
    int m1 = Max(a, b);
    printf("%d\n", m1);

    //宏的方式
    int m2 = MAX(a, b);
    printf("%d\n", m2);
    return 0;
} */

//宏通常被应用于执行简单的运算。比如在两个数中找出较大的一个。
/* 那为什么不用函数来完成这个任务？
原因有二：
1. 用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。
所以宏比函数在程序的规模和速度方面更胜一筹。
2. 更为重要的是函数的参数必须声明为特定的类型。
所以函数只能在类型合适的表达式上使用。反之这个宏怎可以适用于整形、长整型、浮点型等可以用于>来比较的类型。
宏是类型无关的。

宏的缺点：当然和函数相比宏也有劣势的地方：
1. 每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
2. 宏是没法调试的。
3. 宏由于类型无关，也就不够严谨。
4. 宏可能会带来运算符优先级的问题，导致程容易出现错。

 */

//宏有时候可以做函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到。
/* 
#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
int main()
{
    int *p = malloc(10, sizeof(int));
    MALLOC(10, int);  //类型作为参数
    return 0;
} */


//#undef - 这条指令用于移除一个宏定义。
/* 
#define M 100
int main()
{
    printf("%d\n");
    #undef M
    printf("%d\n",M);  //报错
    return 0;
} */
