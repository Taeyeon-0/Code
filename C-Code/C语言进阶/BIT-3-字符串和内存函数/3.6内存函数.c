#include <stdio.h>
#include <assert.h>
#include<string.h>
/* 内存函数
memcpy - 内存拷贝
memmove
memcmp
memset -
*/

// 1.memcpy - 内存拷贝
// void * memcpy ( void * destination, const void * source, size_t num );
// 函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
// 这个函数在遇到 '\0' 的时候并不会停下来。
// 如果source和destination有任何的重叠，复制的结果都是未定义的。

/*
int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0};
    memcpy(arr2, arr1, 20); // 20表示字节 拷贝5个整型数据

    float arr3[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float arr4[] = {0.0};
    memcpy(arr4, arr3, 8); // 8表示拷贝2个浮点型数据
    return 0;
}
*/

//模拟实现my_memcpy
//小端：
/*
void *my_memcpy(void *dest, void *src, size_t num) //需要传void* 的地址   num的单位是字节
{
    assert(dest && src);
    void *ret = dest;
    while (num--) //交换num次字节的内容 一次交换一次字节
    {
        *(char *)dest = *(char *)src;
        dest = (char *)dest + 1;
        src = (char *)src + 1;
    }
    return ret;
}



int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0};
    my_memcpy(arr2, arr1, 20);
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr2[i]);
    }

    printf("\n");

    float arr3[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float arr4[] = {0.0};
    my_memcpy(arr4, arr3, 8);
    for (i = 0; i < 10; i++)
    {
        printf("%f ", arr4[i]);
    }
    return 0;
} */


//2.这是mommove函数的模拟实现   C语言中重叠内存的函数由mommove来实现
/*
void *my_memmove(void *dest, void *src, size_t num) //需要传void* 的地址   num的单位是字节
{
    assert(dest && src);
    void* ret =dest;
    if (dest < src)
    {
        while (num--) //交换num次字节的内容 一次交换一次字节
        {
            *(char *)dest = *(char *)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    }
    else
    {
        while (num--)
        {
            *((char *)dest + num) = ((char *)src + num);   //后面的数据 换到前面的数
        }
    }

    return ret;
} */
//和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
//如果源空间和目标空间出现重叠，就得使用memmove函数处理。
// 
//memcpy只需要实现不重叠的拷贝就可以了    VS中的memcpy和mommove实现方式差不多 可以替代
//memmove是需要实现重叠内存的拷贝



//3.memcmp
//void * memcpy ( void * destination, const void * source, size_t num );
/*
函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
这个函数在遇到 '\0' 的时候并不会停下来。
如果source和destination有任何的重叠，复制的结果都是未定义的。
*/

/*
int main()
{
    int arr1[] = { 1,2,3,4,5 }; //01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
    int arr2[] = { 1,2,3,0,0 }; //01 00 00 00 02 00 00 00 03 00 00 00 00 00 00 00
    int ret = memcmp(arr1, arr2, 12);
    printf("%d\n", ret); //0

    ret = memcmp(arr1, arr2, 13);
    printf("%d\n", ret);  //1
    return 0;
}
*/


//4.memset
/*
int main()
{
    int arr[] = { 1,2,3,4,5 };
    memset(arr, 0, 8);  //8个字节
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);  // 0 0 3 4 5
    }
    return 0;
}
*/

