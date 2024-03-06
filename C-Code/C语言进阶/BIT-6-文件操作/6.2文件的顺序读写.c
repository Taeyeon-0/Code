#include <stdio.h>
//读写文件：
// 1.顺序读写
// 2.随机读写

// 1. fputc - 文件字符输出函数
/*
int main()
{
    //打开文件
    FILE *pf = fopen("text.text", "w");

    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    //写文件
    int i = 0;
    for (i = 0; i < 26; i++)
    {
        fputc('a' + i, pf);
    }

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
} */

// 2.fgetc - int fgetc(FILE* stream)   文件字符输入函数  如果返回的不是int  而是EOF 则会结束
/*
int main()
{
    //打开文件
    FILE *pf = fopen("text.text", "r");

    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    //读文件
    int ch = 0;
    while ((ch = fgetc(pf)) != EOF)
    {
        printf("%c", ch);
    }
    //每次读取后 pf指针会自动加1

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
} */

// 3.fputs - 文本行输出函数  int fputs(const char* str,FILE* stream)
//按照顺序写文本行
/*
int main()
{
    //打开文件
    FILE *pf = fopen("text.text", "w");

    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    //写文件
    fputs("hello", pf);
    fputs("bitejiuteke", pf);
    //如果文件本身有内容 就会清楚原来文件的所有内容  在写入

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}
 */

// 4.fgets - char *fgets(char *str, int num, FILE *stream)   num设置最多读多少个字符 但是num只能读num-1个字符 还有一个\0
/*
int main()
{
    //打开文件
    FILE *pf = fopen("text.text", "r");

    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }

    //读文件一行一行读   只读一行
    char arr[20] = "#########";
    fgets(arr, 20, pf);
    printf("%s", arr);

    fgets(arr, 20, pf);
    printf("%s", arr);

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
} */

// 5.fprintf
//写一个结构体的数据  写到文件里
/*
struct S
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct S s = {"zhangsan", 20, 95.5f};
    //把s中的结构体数据写到文件中
    FILE *pf = fopen("test.text", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //写文件
    fprintf(pf, "%s %d %f", s.name, s.age, s.score);
    return 0;
} */

// 6.fscanf
/*
struct S
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct S s = {0};
    //把s中的结构体数据写到文件中
    FILE *pf = fopen("test.text", "r");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //写文件
    fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
    printf("%s %d %f",s.name,s.age,s.score);
    return 0;
} */

/*
对任何一个C程序，只要运行起来就默认打开三个流，
stdin - 标准输入流 - 键盘
stdout - 标准输出流 - 屏幕
stderr - 标准错误流 - 屏幕 D
他们的类型都是FILE*
 */

/*
int main()
{
    int ch = fgetc(stdin);  //键盘输入d
    fputc(ch,stdout);  //d键盘输出d
    return 0;
} */

// printf ==  fprintf( ,stdout)

// 7. fwrite - 二进制的写入 size_t fwrite(const void* ptr,size_T size,size_t count,FILE* stream)  size是大小  count为个数
/*
struct S
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct S s = {"zhangsan", 20, 95.5f};
    //把s中的结构体数据写到文件中
    FILE *pf = fopen("test.text", "wb");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //写文件
    fwrite(&s, sizeof(s), 1, pf);
    return 0;
} */

// 8.fread - 二进制读文件 size_t fread(const void* ptr,size_T size,size_t count,FILE* stream)  从流里读取count个大小为size的数据放到s里
/* 
struct S
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct S s = {0};
    //把s中的结构体数据写到文件中
    FILE *pf = fopen("test.text", "rb");
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //写文件
    fread(&s, sizeof(s), 1, pf);
    printf("%s %d %f\n", s.name, s.age, s.score);
    return 0;
} */


//9.对比一组函数：
/*
scanf：按照一定的格式从键盘输入数据
printf：按照一定的格式把数据打印（输出）到屏幕上
适用于标准输入/输出流的格式化的输入/输出语句

fscanf：按照一定的格式从输入流（文件/stdin）输入数据
fprintf：按照一定的格式向输出流（文件/stdout）输出数据
适用于所有的输入/输出流的格式化输入输出语句
 */

//10.
// sscanf  - int sscanf（const char *s，const char* format,...）
//从字符串中按照一定的格式读取出格式化的数据

// sprintf - int sprintf(char * str,const char* format,...)
//将格式化的数据按照一定的格式转换成字符串
/* 
struct S
{
    char name[10];
    int age;
    float score;
};

int main()
{
    char buf[100] = {0};
    struct S tmp = {0};

    struct S s = {"zhangsan", 20, 95.5f};
    //能否把这个结构体的数据转换成字符串
    //转换成 - zhangsan 20 95.5
    sprintf(buf, "%s %d %f", s.name, s.age, s.score);
    printf("%s\n", buf); 

    //能否将buf中的字符串还原成一个结构体数据
    sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.score));
    printf("%s %d %f\n", tmp.name, tmp.age, tmp.score); //以结构体的形式打印
    return 0;
} */