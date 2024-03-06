#include <stdio.h>
/* 
scanf 是C语言标准库中的一个函数，用于从标准输入（通常是键盘）读取输入数据。
函数原型：
int scanf(const char *format, ...);
返回值：
scanf 函数返回成功读取的数据项数，如果发生错误或到达输入结束，则返回一个负数。
scanf 函数根据格式化字符串中的占位符，从标准输入读取相应的数据，并将其存储到指定的变量中。

常见的格式化占位符及其用法如下：
%d：读取带符号的十进制整数。
%u：读取无符号的十进制整数。
%f：读取浮点数。
%c：读取单个字符。
%s：读取字符串。
%p：读取指针地址。
%x 或 %X：读取十六进制整数。

scanf 函数会根据格式化字符串和相应的参数进行输入，如果输入数据与格式化字符串中的占位符不匹配，可能会导致输入错误或出现运行时错误。因此，在使用 scanf 函数时需要确保格式化字符串和参数的正确匹配，避免潜在的问题。
*/

void test1() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);               //输入3
    printf("You entered: %d\n", num);//打印： You entered 3
}

//多组输入
int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF)//EOF等于-1  文件结束标志 用于多组输入
    {
        if (n >= 140)
            printf("Genius");
    }
    
    return 0;
}