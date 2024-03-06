#include <stdio.h>
// 1.文件指针
/*
缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”。
每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。
这些信息是保存在一个结构体变量中的。该结构体类型是有系统声明的，取名FILE. */
//例如，VS2013编译环境提供的 stdio.h 头文件中有以下的文件类型申明：
/*
struct _iobuf
{
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};
typedef struct _iobuf FILE;

不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。
每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中的信息，使用者不必关心细节。
一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来更加方便。


下面我们可以创建一个FILE*的指针变量:
FILE* pf;   //文件指针变量

定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。
通过该文件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联
的文件。
 */

// 2.文件的打开和关闭
/* 文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
在编写程序的时候，在打开文件的同时，都会返回一个FILE*的指针变量指向该文件，也相当于建立了指针和文件的关系。
ANSIC 规定使用fopen函数来打开文件，fclose来关闭文件。 */

//打开文件
FILE *fopen(const char *filename, const char *mode);
//关闭文件
int fclose(FILE *stream);

//文件操作
/* struct _iobuf
{
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};
typedef struct _iobuf FILE;

int main()
{
    FILE *pf = fopen("6.1.text", "w");           //打开失败返回空指针   在工程下创建文件(相对路径)
    //FILE *pf = fopen("c:\\code\\6.1.text", "w"); //打开失败返回空指针   在C盘创建文件(绝对路径)

    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //写文件

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
} */