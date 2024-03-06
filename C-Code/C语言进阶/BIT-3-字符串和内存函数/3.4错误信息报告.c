#include <stdio.h>
#include <string.h>
#include <errno.h>
// strerror
// char * strerror ( int errnum );
//把错误码转换成错误信息
/*
int main()
{
    //strerror的错误码
    //c语言中库函数报错的时候的错误码
    printf("%s\n",strerror(0));  //No error
    printf("%s\n",strerror(1));  //Operation not permitted
    printf("%s\n",strerror(2));  //No such file or directory
    printf("%s\n",strerror(3));  //No such process
    printf("%s\n",strerror(4));  //Interrupted function call
    return 0;
}
*/

/*
int main()
{
    //错误码记录到错误码的变量中
    //errno -  #include<errno.h>  C语言提供的全局的错误变量
    FILE* pf = fopen("test.txt","r");
    if(pf==NULL)
    {
        perror("fopen");   //perror = printf+strerror    打印fopen: No such file or directory
        //打印的依然是error变量中错误码对应的错误信息
        printf("%s\n",strerror(errno)); //返回了2错误码
        return 1;
    }
    //读文件
    fclose(pf);
    pf=NULL;
    return 0;
}
*/
