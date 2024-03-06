#include <stdio.h>
// 1.fseek - 根据文件指针的位置和偏移量来定位文件指针
// int fseek(FILE* ,long int offset,int origin)
/* 解释
FILE* stream ：指向已打开文件的指针。
long offset ：偏移量，正负都可。正向后面偏移；负向前面偏移。
int origin ：参数值有三个。
SEEK_SET — 指向文件首端；
SEEK_CUR — 指向当前位置；
SEEK_END — 指向
文件尾端。 */

/*
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        perror("fopen()");
        return 1;
    }
    //读文件 - 文件中存放abcdef
    int ch = fgetc(pf);
    printf("%c\n", ch);       // a  读完后文件指针往后+1 指向b

    fseek(pf, 2, SEEK_CUR); //从当前文件指针往后偏移2个  (当前是b)
    ch = fgetc(pf);
    printf("%c\n", ch); // d


    fseek(pf, 3, SEEK_SET); //文件首部向后偏移三个
    ch = fgetc(pf);
    printf("%c\n", ch); // d

    fseek(pf, -3, SEEK_END); //文件首部向前偏移三个  末尾的指针是f的后面
    ch = fgetc(pf);
    printf("%c\n", ch); // d

    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
} */

// 2. ftell函数 - 功能：返回文件指针相对于起始位置的偏移量
//  语法：long ftell(FILE *stream);
/*
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        perror("fopen()");
        return 1;
    }
    //读文件 - 文件中存放abcdef
    int ch = fgetc(pf);
    printf("%c\n", ch);       // a  读完后文件指针往后+1 指向b

    fseek(pf, 2, SEEK_CUR); //从当前文件指针往后偏移2个  (当前是b)
    ch = fgetc(pf);
    printf("%c\n", ch); // d

    int pos = ftell(pf);    //当文件指向d的时候 文件指针往后偏移1个 指向了e
    printf("%d\n",pos);  //4
    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}  */

// 3.rewind - 功能：让文件指针的位置回到文件的起始位置
//语法：void rewind(FILE *stream);
/* 
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        perror("fopen()");
        return 1;
    }
    //读文件 - 文件中存放abcdef
    int ch = fgetc(pf);
    printf("%c\n", ch); // a  读完后文件指针往后+1 指向b

    fseek(pf, 2, SEEK_CUR); //从当前文件指针往后偏移2个  (当前是b)
    ch = fgetc(pf);
    printf("%c\n", ch); // d
    
    //记录当前偏移量
    int pos = ftell(pf); //当文件指向d的时候 文件指针往后偏移1个 指向了e
    printf("%d\n", pos); // 4
  
    //偏移量回到初始位置
    rewind(pf);
    ch = fgetc(pf);
    printf("%c\n", ch); // a
    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}*/