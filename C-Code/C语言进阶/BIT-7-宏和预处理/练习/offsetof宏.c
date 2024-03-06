//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//考察：offsetof宏的实现
#include <stdio.h>
#define OFFSETOF(s_type,m_name)
struct S
{
    char a;
    int b;
    char c;
};

#define OFFSETOF(s_type,m_name) (int)&(((s_type*)0)->m_name)
int main()
{
    printf("%d\n", OFFSETOF(struct S, a));  //0
    printf("%d\n", OFFSETOF(struct S, b));  //4
    printf("%d\n", OFFSETOF(struct S, c));  //8
    return 0;
}