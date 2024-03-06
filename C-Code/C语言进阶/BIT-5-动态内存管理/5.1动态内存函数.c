#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/*
int main()
{
    int num = 10;  //向内存申请4个字节
    int arr[10];   //向内存申请了40个字节
    return 0;
}
但是上述的开辟空间的方式有两个特点：
1. 空间开辟大小是固定的。
2. 数组在申明的时候，必须指定数组的长度，它所需要的内存在编译时分配。
但是对于空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，
那数组的编译时开辟空间的方式就不能满足了。
这时候就只能试试动态存开辟了。
*/

// 1.malloc和free
// malloc - void* malloc (size_t size);
// free - void free(void* ptr);

/* malloc
如果开辟成功，则返回一个指向开辟好空间的指针。
如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。
返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己
来决定。
如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器。
*/

/*free函数用来释放动态开辟的内存。
如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。
如果参数 ptr 是NULL指针，则函数什么事都不做。
*/

/*
int main()
{
    int* p = (int*)malloc(40);  //malloc默认返回void* 强制类型转换成int*
    int* ptr =p;  //用来下面释放一开始创建的p地址
    if (p == NULL)
    {
        printf("%s\n",strerror(errno));
        return 1;
    }
    //使用
    int i=0;
    for(i=0;i<10;i++)
    {
        *p=i;
        p++;
    }
    //释放
    //动态内存分配在堆区上完成的  不释放或者程序结束 会一直分配在堆区上
    free(ptr);  //此时的p 是++后的p  释放的话不对  所以改成ptr
    ptr = NULL;
    return 0;
} */

// 2.calloc - void* calloc(size_t num,size_t size)
//函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。
//与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0。
/*
int main()
{
    int *p = (int *)calloc(10, sizeof(int));
    if (p == NULL)
    {
        perror("calloc");
        return 1;
    }
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }
    //释放
    free(p); //这里的p没有++ 用的是p+i 所以可以用p
    p = NULL;
    return 0;
} */
// calloc = malloc+memset 初始化为0

// 3.realloc - void* realloc(void* ptr,size_t size)
/* realloc函数的出现让动态内存管理更加灵活。
有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，那为了合理的时
候内存，我们一定会对内存的大小做灵活的调整。那realloc函数就可以做到对动态开辟内存大小
的调整。 */

/* ptr 是要调整的内存地址
size 调整之后新大小
返回值为调整之后的内存起始位置。
这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到 新 的空间。
realloc在调整内存空间的是存在两种情况：
情况1：原有空间之后有足够大的空间
情况1
当是情况1 的时候，要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发生变化。
情况2
当是情况2 的时候，原有空间之后没有足够多的空间时，扩展的方法是：在堆空间上另找一个合适大小
的连续空间来使用。这样函数返回的是一个新的内存地址。
由于上述的两种情况，realloc函数的使用就要注意一些。 */

/*
int main()
{
    int *p = (int *)malloc(40);
    if (p == NULL)
        return 1;
    //使用
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        *(p + i) = i;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", *(p + i));
    }
    //增加空间
    // p = (int *)realloc(p, 80); //如果开辟失败的话，p变成了空指针，不能这么写
    int *ptr = (int *)realloc(p, 80);
    if (ptr != NULL)
    {
        p = ptr;
        ptr = NULL;
    }
    //当realloc开辟失败的时候，返回的也是空指针
    //使用
    for (i = 10; i < 20; i++)
    {
        *(p + i) = i;
    }

    for (i = 10; i < 20; i++)
    {
        printf("%d ", *(p + i));
    }
    //释放
    free(p);
    p = NULL;
    return 0;
} */

/* 
int main()
{
    //传空指针
    int *P = (int *)realloc(NULL, 40);              //相当于malloc(40)
    return 0;
} */