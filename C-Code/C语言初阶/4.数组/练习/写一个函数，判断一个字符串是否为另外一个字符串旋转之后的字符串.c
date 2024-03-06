#include <stdio.h>
#include <string.h>
/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
 */
/*  思路1 效率不高
int is_left_move(char *arr1, char *arr2)
{
    int len = strlen(arr1);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        char tmp = arr1[0];
        int j = 0;
        for (j = 0; j < len - 1; j++)
        {
            arr1[j] = arr1[j + 1];
        }
        arr1[len - 1] = tmp;
        if (strcmp(arr1, arr2) == 0)
        {
            return 1;
        }
    }
}
*/

//给arr1后面再追加一个arr1  ABCDEFABCDEF 再用strstr
int is_left_move(char *arr1, char *arr2)
{
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    if (len1 != len2) //如果长度不同 不可能是
        return 0;
    strncat(arr1, arr2, len1); // arr1的空间足够大
    char *ret = strstr(arr1, arr2);
    if (ret == NULL)
        return 0;
    else
        return 1;
}

int main()
{
    char arr1[20] = "ABCDEF";
    char arr2[] = "CDEFAB";
    int ret = is_left_move(arr1, arr2); //判断arr2是否是arr1旋转得来的
    if (ret == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}