#include <stdio.h>
#include <ctype.h>
/*  如果他的参数符合下列条件就返回真
iscntrl 任何控制字符
isspace 空白字符：空格‘ ’，换页‘\f’，换行'\n'，回车‘\r’，制表符'\t'或者垂直制表符'\v'
isdigit 十进制数字 0~9
isxdigit 十六进制数字，包括所有十进制数字，小写字母a~f，大写字母A~F
islower 小写字母a~z
isupper 大写字母A~Z
isalpha 字母a~z或A~Z
isalnum 字母或者数字，a~z,A~Z,0~9
ispunct 标点符号，任何不属于数字或者字母的图形字符（可打印）
isgraph 任何图形字符
isprint 任何可打印字符，包括图形字符和空白字符 */

/* 转换字母大小写函数toupper tolower
int main()
{
    char ch = 'w';
    printf("%c\n", toupper(ch)); // toupeer 转换成大写字母 - W
    char ch2 = 'A';
    printf("%c\n", tolower(ch2)); // tolower 转换成小写字母 - a
    return 0;
}
*/


/* 
int main()
{
    char arr[] = "Are you ok?";
    char *p = arr;
    while (*p)
    {
        if (islower(*p))   //islower 判断是否是小写字母
        {
            *p = toupper(*p);
        }
        p++;
    }
    printf("%s\n", arr); // ARE YOU OK?
    return 0;
} 
*/