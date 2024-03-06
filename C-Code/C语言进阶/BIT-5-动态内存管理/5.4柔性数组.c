#include <stdio.h>
#include <stdlib.h>
//也许你从来没有听说过柔性数组（flexible array）这个概念，但是它确实是存在的
// C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。
/*
struct S
{
    int n;
    float s;
    int arr[];  //柔性数组成员 第二种写法int arr[0]
};

int main()
{
    return 0;
} */

// 1.柔性数组的特点：
/*
·结构中的柔性数组成员前面必须至少一个其他成员。
·sizeof 返回的这种结构大小不包括柔性数组的内存。
·包含柔性数组成员的结构用malloc ()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。 */

/*
typedef struct st_type
{
    int i;
    int a[0]; //柔性数组成员
} type_a;
printf("%d\n", sizeof(type_a)); //输出的是4 */

/* 代码1
struct S
{
    int n;
    float s;
    int arr[]; //柔性数组成员
};

int main()
{
    struct S *ps = (struct S *)malloc(sizeof(struct S) + sizeof(int) * 4); //创建结构体的空间 加上自定义柔性数组的空间
    if (ps == NULL)
    {
        return 1;
    }

    ps->n = 100;
    ps->s = 5.5f;
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &(ps->arr[i]));
    }

    for (i = 0; i < 4; i++)
    {
        printf("%d ", *(ps->arr + i));
    }
    //调整
    struct S *ptr = realloc(ps, sizeof(struct S) + 10 * sizeof(int)); //扩展柔性数组的容量
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        ps = ptr;
    }

    free(ps);
    ps = NULL;
    return 0;
}
 */



/* 代码2
struct S
{
    int n;
    float s;
    int *arr;
};

int main()
{
        struct S *ps = (struct S*)malloc(sizeof(struct S));
    if (ps == NULL)
        return 1;

    ps->n = 100;
    ps->s = 5.5f;
    int *ptr = (int *)malloc(4 * sizeof(int));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        ps->arr = ptr;
    }
    //使用
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &(ps->arr[i]));
    }
    //调整
    realloc(ps->arr,10*sizeof(int));
    //打印
    printf("%d\n", ps->n);
    printf("%f\n", ps->s);
    for (i = 0; i < 4; i++)
    {
        printf("%d ", ps->arr[i]);
    }
    //释放
    free(ps->arr);
    ps->arr = NULL;
    free(ps);
    ps = NULL;
    return 0;
} */

/* 
上述 代码1 和 代码2 可以完成同样的功能，但是 方法1 的实现有两个好处：
第一个好处是：方便内存释放
如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给
用户。用户调用free可以释放结构体，但是用户并不知道这个101结构体内的成员也需要free，所以你
不能指望用户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好
了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。
第二个好处是：这样有利于访问速度.
连续的内存有益于提高访问速度，也有益于减少内存碎片。（其实，我个人觉得也没多高了，反正
你跑不了要用做偏移量的加法来寻址） */