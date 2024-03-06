#include <stdio.h>
// feof - 牢记：在文件读取过程中，不能用feof函数的返回值直接用来判断文件的是否结束。
//而是应用于当文件读取结束的时候，判断是读取失败结束（返回值为假），还是遇到文件尾结束（返回值为真）。

/*
1. 文本文件读取是否结束，判断返回值是否为 EOF （ fgetc ），或者 NULL （ fgets ）
例如：
fgetc 判断是否为EOF
fgets 判断返回值是否为NULL */

// fgetc - 如果读取正常，会返回读取到的字符的ascll码值，如果读取失败会返回EOF

// fgets - 如果读取正常，返回的是读取到的数据的地址，如果读取失败，返回的是NULL

// fscanf - 如果读取正常，返回的是格式串中指定的数据的个数，如果读取失败，返回的是小于格式串中指定的数据的个数

/*
2. 二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
例如：
fread判断返回值是否小于实际要读的个数。 */

/* 文本文件的例子：
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int c; // 注意：int，非char，要求处理EOF
    FILE *fp = fopen("test.txt", "r");
    if (!fp)
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    // fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
    while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
    {
        putchar(c);
    }
    //判断是什么原因结束的
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");
    fclose(fp);
} */

//二进制文件
/*
#include <stdio.h>
enum
{
    SIZE = 5
};

int main(void)
{
    double a[SIZE] = {1., 2., 3., 4., 5.};
    FILE *fp = fopen("test.bin", "wb"); // 必须用二进制模式
    fwrite(a, sizeof *a, SIZE, fp);     // 写 double 的数组
    fclose(fp);
    double b[SIZE];
    fp = fopen("test.bin", "rb");
    size_t ret_code = fread(b, sizeof *b, SIZE, fp); // 读 double 的数组
    if (ret_code == SIZE)
    {
        puts("Array read successfully, contents: ");
        for (int n = 0; n < SIZE; ++n)
            printf("%f ", b[n]);
        putchar('\n');
    }
    else
    { // error handling
        if (feof(fp))
            printf("Error reading test.bin: unexpected end of file\n");
        else if (ferror(fp))
        {
            perror("Error reading test.bin");
        }
    }
    fclose(fp);
} */

//缓冲区
/* 
#include <stdio.h>
#include <windows.h>
// VS2013 WIN10环境测试
int main()
{
    FILE *pf = fopen("test.txt", "w");
    fputs("abcdef", pf); //先将代码放在输出缓冲区
    printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
    Sleep(10000);
    printf("刷新缓冲区\n");
    fflush(pf); //刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
    //注：fflush 在高版本的VS上不能使用了
    printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
    Sleep(10000);
    fclose(pf);
    //注：fclose在关闭文件的时候，也会刷新缓冲区
    pf = NULL;
    return 0;
} */

/* 这里可以得出一个结论：
因为有缓冲区的存在，C语言在操作文件的时候，需要做刷新缓冲区或者在文件操作结束的时候关闭文
件。
如果不做，可能导致读写文件的问题。 */