#include <stdio.h>
// 1.命令行定义
/*
许多C 的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。
例如：当我们根据同一个源文件要编译出一个程序的不同版本的时候，这个特性有点用处。（假定某个
程序中声明了一个某个长度的数组，如果机器内存有限，我们需要一个很小的数组，但是另外一个机器
内存大些，我们需要一个数组能够大些。）
编译指令：
gcc -D ARRAY_SIZE=10 programe.c */

//条件编译
//：在编译一个程序的时候我们如果要将一条语句（一组语句）编译或者放弃是很方便的。因为我们有条件编译指令。
/*
#define __DEBUG__
#include <stdio.h>
#define __DEBUG__
int main()
{
    int i = 0;
    int arr[10] = {0};
    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
#ifdef __DEBUG__
        printf("%d\n", arr[i]); //为了观察数组是否赋值成功。
#endif                          //__DEBUG__
    }
    return 0;
} */

//常见的条件编译指令：

// 1.

/*
int main()
{
    #if 1
    printf("hehe\n");   //如果不满足条件  在预处理的时候就会删除代码
    #endif
}*/

// 2.多个分支的条件编译
/*
int main()
{
#if 1 > 2
    printf("hehe\n");
#elif 2 > 3
    printf("haha\n");
#else
    printf("heihei\n");
#endif
    return 0;
} */

// 3.判断是否被定义
/*
#define MAX
int main()
{
#if defined(MAX)  //也可以写成 #ifdef MAX
    printf("hehe\n");
#endif

#if !defined(MAX)  //也可以写成#ifndef MAX
    printf("haha\n");
#endif
    return 0;
} */

// 4.嵌套条件编译
/* 
#if defined(OS_UNIX)
#ifdef OPTION1
unix_version_option1();
#endif
#ifdef OPTION2
unix_version_option2();
#endif
#elif defined(OS_MSDOS)
#ifdef OPTION2
msdos_version_option2();
#endif
#endif */
