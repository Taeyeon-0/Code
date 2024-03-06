#include <stdio.h>
#include<string.h>
//请实现一个函数，将一个字符串中的每个空格替换成%20
void replaceSpace(char *str, int length)
{
    //统计空格的个数
    int space_count = 0;
    char *cur = str;
    while (*cur)
    {
        if (*cur == ' ')
        {
            space_count++;
        }
        cur++;
    }
    //计算end1,end2
    char *end1 = str + length - 1; //这里也可以不-1  就是把\0也拷贝到end2
    char *end2 = str + length - 1 + 2 * space_count;
    while ((end1 != end2))
    {
        if (*end1 != ' ')
        {
            *end2 = *end1;
        }
        else
        {
            *end2 = '0';
            end2--;
            *end2 = '2';
            end2--;
            *end2 = '%';
            end2--;
            end1--;
        }
    }
}

int main()
{
    char arr[40]="we are happy";
    int len = strlen(arr);
    replaceSpace(arr,len);
    printf("%s\n",arr);
    return 0;
}