#include <stdio.h>
#include <stddef.h>
// 1.结构的基础知识
//结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。

// 2.结构体的声明
/*
struct Book
{
    char book_name[20];
    char author[20];
    int price;
    char id[15];
} sb3, sb4; // sb3,sb4也是struct Book类型的结构体变量，也可以不创建

struct Stu
{
    char name[20];
    int age;
    char id[12];
};
int main()
{
    //创建结构体变量
    struct Book sb1;
    struct Book sb2;
    struct Stu s1;
    struct Stu s2;
    return 0;
} */

// 3.特殊的声明 - 在声明结构的时候，可以不完全的声明。
/* 匿名结构体类型
struct
{
    char book_name[20];
    char author[20];
    int price;
    char id[15];
} sb1, sb2;

struct
{
    char book_name[20];
    char author[20];
    int price;
    char id[15];
}*ps;

int main()
{
    //ps=&sb1;  //编译器会把上面的两个声明当成完全不同的两个类型。所以是非法的。
    return 0;
} */

// 4.结构体的自引用
//链表 - 数据结构 - 数据在内存中存储的结构
/*
typedef struct Node //对struct Node重命名为Node,typedef后不能再后面创建变量了Node为类型名了 如果没有Node为变量
{
    int data;
    struct Node *next; //指向下个结点的地址，这里的struct不能省略
} Node;

int main()
{
    Node n;
    return 0;
} */

// 5.结构体变量的定义和初始化
/*
struct Point
{
    int x;
    int y;
} p1;            //声明类型的同时定义变量p1
struct Point p2; //定义结构体变量p2

//初始化：定义变量的同时赋初值。
struct Point p3 = {1, 2};

struct Stu //类型声明
{
    char name[15]; //名字
    int age;       //年龄
};
struct Stu s = {"zhangsan", 20}; //初始化

struct Node
{
    int data;
    struct Point p;   //4，5
    struct Node *next;   //NULL
} n1 = {10, {4, 5}, NULL};           //结构体嵌套初始化
struct Node n2 = {20, {5, 6}, NULL}; //结构体嵌套初始化 */

/* 不按顺序初始化
struct S
{
    char c;
    int a;
    float f;
};

int main()
{
    struct S s = { 'w', 20, 3.14f };
    printf("%c %d %f\n", s.c, s.a, s.f);
    struct S s2 = { s2.f = 3.14f, s2.c = 'w', s2.a = 10 }; //不按顺序初始化,VS可以 GCC不行
    printf("%c %d %f\n", s.c, s.a, s.f);
    return 0;
} */

// 6.结构体内存对齐(热门考点) - 计算结构体的大小
/*
struct S1
{
    char c1;
    int i;
    char c2;
};

struct S2
{
    char c1;
    char c2;
    int i;
};

int main()
{
    //S1的偏移量
    printf("%d\n",offsetof(struct S1,c1)); //0
    printf("%d\n",offsetof(struct S1,i)); //4
    printf("%d\n",offsetof(struct S1,c2)); //8  //0+4+8 +最大对齐数4倍数为12
    //S2的偏移量
    printf("%d\n",offsetof(struct S2,c1)); //0
    printf("%d\n",offsetof(struct S2,c2)); //1
    printf("%d\n",offsetof(struct S2,i)); //4

   // printf("%d\n",sizeof(struct S1)); //12
   // printf("%d\n",sizeof(struct S2)); //8
    return 0;
} */
// offsetof宏-用来计算结构体成员相对于起始位置的偏移量

/* 结构体内存的规则：
1.结构体的第一个成员直接对齐到相对于结构体变量起始位置为0的偏移处。
2.从第二个成员开始，要对齐到（某个对齐数）整数倍的偏移处。
对齐数：结构体成员自身大小和默认对齐数的较小值  VS:8     Linux环境默认不设对齐数(对齐数是结构体成员自身大小)
3.结构体的总大小必须是最大对齐数的整数倍。每个结构体成员都有一个对齐数，其中最大的对齐数就是最大对齐数。
4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。如；结构体中是8 对齐就是8
*/

/* 练习
struct S3
{
    double d; // 0 - 7
    char c;   // 8
    int i;    // 12-15
};

struct S4
{
    char c1;      // 0
    struct S3 s3; // 8-20
    double d;     // 24-31
};

int main()
{
    printf("%d\n", sizeof(struct S3)); // 16
    printf("%d\n", sizeof(struct S4)); // 32
    return 0;
}
 */

/* 为什么存在内存对齐?
1. 平台原因(移植原因)：
不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。
2. 性能原因：
数据结构(尤其是栈)应该尽可能地在自然边界上对齐。
原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问。
总体来说：结构体的内存对齐是拿空间来换取时间的做法。
结构体成员设计的时候让占用空间小的成员尽量集中在一起。
*/

// 7.修改默认对齐数
/*
//设置默认对齐数
#pragma pack(1)
struct S1
{
    char cl; // 0
    int i;   // 1-4
    char c2; // 5
};
//恢复默认对齐数
#pragma pack()
int main()
{
    printf("%d\n", sizeof(struct S1)); // 6
    return 0;
}
//结构在对齐方式不合适的时候，我么可以自己更改默认对齐数。
*/

// 8.结构体传参
/* 
struct S
{
    int data[1000];
    int num;
};

void print1(struct S s)
{
    //传值比较浪费空间，可能会栈溢出
    printf("%d %d %d %d\n", s.data[0], s.data[1], s.data[2], s.num); // 1 2 3 100
}

void print2(struct S *ps)
{
    //两种写法  推荐第二个
    printf("%d %d %d %d\n", (*ps).data[0], (*ps).data[1], (*ps).data[2], (*ps).num); // 1 2 3 100
    printf("%d %d %d %d\n", ps->data[0], ps->data[1], ps->data[2], ps->num);         // 1 2 3 100  
}

int main()
{
    struct S ss = {{1, 2, 3, 4, 5}, 100};
    print1(ss);
    print2(&ss);
    return 0;
} */
/* 
函数传参的时候，参数是需要压栈，会有时间和空间上的系统开销。
如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。
结论：结构体传参的时候，要传结构体的地址。 */