#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// 1.对NULL指针的解引用操作
/*
int main()
{
    int *p = (int *)malloc(20);
    //为了不对空指针解引用  需要进行判断
    if (p == NULL)
    {
        perror("malloc");
        return 1;
    }
    else
    {
        *p = 5;
    }
    free(p);
    p = NULL;
    return 0;
} */


// 2.对动态开辟空间的越界访问
/*
int main()
{
    int *p = (int *)malloc(20);
    if (p == NULL)
        return 1;
    int i = 0;
    for (i = 0; i < 20; i++) //越界访问    20个字节 只能访问5个整型
    {
        *(p + i) = i;
    }

    free(p);
    p = NULL;
    return 0;
}
*/


// 3.对非动态开辟内存使用free释放
/*
void test()
{
    int a = 10;
    int *p = &a;
    free(p); // ok?
}
*/


// 4.使用free释放一块动态开辟内存的一部分
/*
int main()
{
    int *p = (int *)malloc(40);
    if (p = NULL)
        return 1;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        *p = i;
        p++;
    }
    //释放
    //在释放的时候，p指向的不再是动态内存空间的起始位置
    free(p); // p不再指向动态内存的起始位置
    p++;
    return 0;
}
*/


// 5.对同一块动态内存多次释放
/*
int main()
{
    int *p = (int *)malloc(40);
    if (p = NULL)
        return 1;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        *(p + i) = i;
    }
    //重复free
    free(p);
    p = NULL //如果将p赋值为NULL  就可以在free
        free(p);

    return 0;
}
*/


// 6.动态开辟内存忘记释放（内存泄漏）
//函数会返回动态开辟空间的地址，记得在使用之后返回
/*
int* get_memory()
{
    int*p=(int*)malloc(40);

    return p;
}

int main()
{
    int *ptr=get_memory();
    //使用

    //释放  如果不释放 就会导致内存泄漏
    free(ptr);
    return 0;
} */
//忘记释放不再使用的动态开辟的空间会造成内存泄漏。
//切记：
//动态开辟的空间一定要释放，并且正确释放 。
