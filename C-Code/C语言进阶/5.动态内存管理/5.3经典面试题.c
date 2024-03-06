#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 1.题目1
/*
void GetMemory(char *p)
{
    p = (char *)malloc(100);   //这里的p开辟了空间，而str没有开辟  也没有free P
}

void Test(void)
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str, "hello world");
    printf(str);   //这种写法没有问题
}

int main()
{
    Test();
    return 0;
} */

//改写1
/*
void GetMemory(char **p)
{
    *p = (char *)malloc(100); //这里的p开辟了空间，而str没有开辟  也没有free P
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str);
    strcpy(str, "hello world");
    printf(str); //这种写法没有问题
    //释放
    free(str);
    str = NULL;
}

int main()
{
    Test();
    return 0;
} */

//改写2
/*
char *GetMemory()
{
    char *p = (char *)malloc(100); //这里的p开辟了空间，而str没有开辟  也没有free P
    return p;
}

void Test(void)
{
    char *str = NULL;
    str = GetMemory();
    strcpy(str, "hello world");
    printf(str); //这种写法没有问题
}

int main()
{
    Test();
    return 0;
} */


// 2.题目2
//返回栈空间地址的问题！！！
/*
char *GetMemory(void)
{
    char p[] = "hello world";   //函数结束后这个数组就销毁了，但是地址还在，别人访问这个地址的时候，就是访问野指针了
    return p;
}


void Test(void)
{
    char *str = NULL;
    str = GetMemory();  //str找到了p的地址，但是p的地址已经被销毁
    printf(str);    //打印的值是不可预知的
}

int main()
{
    Test();
    return 0;
} */


// 3.题目
/*
void GetMemory(char **p, int num)
{
    *p = (char *)malloc(num);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello");
    printf(str);
    //加上销毁
    free(str);
    str = NULL;
}
//内存泄漏问题
int main()
{
    Test();
    return 0;
}
*/


// 4.题目4
/*
void Test(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);
    if (str != NULL)   //free完后 str不会置为NULL  这边的判断没有意义
    {
        //str是野指针，非法访问
        strcpy(str, "world");
        printf(str);
    }
}

int main()
{
    Test();
    return 0;
} */

//改写
/*
void Test(void)
{
    char *str = (char *)malloc(100);
    strcpy(str, "hello");
    free(str);
    str = NULL;
    if (str != NULL)
    {
        // str是野指针，非法访问
        strcpy(str, "world");
        printf(str);
    }
}

int main()
{
    Test();
    return 0;
} */

int main()
{
    printf("hehe");
    return 0;
}