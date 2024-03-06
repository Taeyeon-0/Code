#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
/*
int main()
{
    int ret = atoi("-123");
    printf("%d\n",ret);
    return 0;
} */

//模拟实现atoi
/*
my_atoi(NULL)  //异常
my_atoi("")   //异常
my_atoi("   123")   //正常情况
my_atoi("123abc")   //异常
my_atoi("11111111111")  //异常 */

enum Status
{
    VALTD,  //0
    INVALTD  //1 
};

enum Status status = INVALTD;
int my_atoi(const char *str)
{
    if (str == NULL)
        return 0;
    if (*str == '\0')
        return 0;
    //空白字符
    while (isspace(*str)) // isspace判断是否为空白字符
    {
        str++;
    }
    int flag = 1;
    if (*str == '+')
    {
        flag = 1;
        str++;
    }
    else if (*str == '-')
    {
        flag = -1;
        str++;
    }
    //处理数字字符
    long long ret = 0;
    while (isdigit(*str)) // isdigit判断数字字符
    {
        ret = ret * 10 + flag * (*str - '0'); // flag是正负
        if (ret < INT_MIN || ret > INT_MAX)   //最小值
        {
            return 0;
        }
        str++;
    }
    if (*str == '\0')
    {
        status = VALTD;
        return (int)ret;
    }
    else
    {
        return (int)ret;
    }
}

int main()
{
    int ret = my_atoi("-1231111");
    if (status == VALTD)
        printf("合法的数据转换：%d\n", (int)ret);
    else
        printf("非法的数据转换：%d\n", (int)ret);
    return 0;
}