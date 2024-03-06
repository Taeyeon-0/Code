#include<stdio.h>
//笔试题1
/*
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int* ptr = (int*)(&a + 1);  //&a  是数组的地址，数组的地址加1就是跳过整个数组地址
    printf("%d,%d", *(a + 1), *(ptr - 1)); //2，5 a是首元素地址 +1表示数组的第二个地址为2
    //ptr是&a+1的地址，也就是数组后面的一个地址
    return 0;
}
*/


//笔试题2
//由于还没学习结构体，这里告知结构体的大小是20个字节
/*
struct Test
{
    int Num;
    char* pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节
int main()
{
    p = (struct Test*)0x100000;
    printf("%p\n", p + 0x1);   //0x100014 p是一个结构体指针变量，p+1就是跳过一个结构体，结构体大小为20字节，20的十六进制为14，0x100014
    printf("%p\n", (unsigned long)p + 0x1); //0x100001   强制类型转换为long数据，+1就是+1
    printf("%p\n", (unsigned int*)p + 0x1); //0x100004   int* +1 跳过4个字节
    return 0;
}

*/


//面试题3
/*
int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int* ptr1 = (int*)(&a + 1);  //数组a的地址+1 就是数组a[4]的地址
    int* ptr2 = (int*)((int)a + 1); //将a的地址强制类型转换成int类型的数据在+1  就是数据中的地址加了1个字节
    //01000000 02000000 03000000 04000000  加一个字节后
    //01 00000002 00000003 00000004 000000   读入了00000002的数据 小端存储  拿出来反着都就是20000000
    printf("%x,%x", ptr1[-1], *ptr2); //ptr1[-1] == *(ptr1-1) 就是a[3]的地址 4   ptr2 就是20000000
    return 0;
}
*/


//面试题4
/*
int main()
{
    int a[3][2] = { (0, 1), (2, 3), (4, 5) }; //（）代表逗号表达式 ，存放的其实是{1，3，5}
    //数组中就是1 3 5 0 0 0
    int* p;
    p = a[0];  //a[0]是首元素地址 就是1
    printf("%d", p[0]); //p[0]也是第一个地址 也是1
    return 0;
}
*/


//面试题5
//这道题要自己画图理解
/*
int main()
{
    int a[5][5]; //a的类型int(*)[5]
    int(*p)[4];  //p+1 跳过4个元素
    p = a;
    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); //FFFFFFFC,-4
    //FFFFFFFC 为-4的计算机中二进制转换成十六进制表示
    return 0;
}
//p[4][2] ==4*4+2==18
//a[4][2] ==4*5+2=22
*/


//面试题6
/*
int main()
{
    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* ptr1 = (int*)(&aa + 1);  //&aa是数组地址 +1 跳过整个数组
    int* ptr2 = (int*)(*(aa + 1));  //aa是首行地址 +1 就是下一行首地址6的地址
    printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1)); //10，5
    return 0;
}
*/


//面试题7
/*
int main()
{
    char* a[] = { "work","at","alibaba" };  //指针数组  存放三个字符串的地址
    char** pa = a;  //pa是指向a的二级指针  指向指针的指针
    pa++;  //pa++就是pa指向下一个char *a的地址
    printf("%s\n", *pa); //at
    return 0;
}
*/



//笔试题8  C语言第29课
/*
int main()
{
    char* c[] = { "ENTER","NEW","POINT","FIRST" }; //指针数组
    char** cp[] = { c + 3,c + 2,c + 1,c }; //cp==c+3  cp+1==c+2  cp+2==c+1 cp+3==c   c+3==FIRST c+2==POINT c+1==NEW c=ENTER
    char*** cpp = cp; //cpp指向了cp  **(cpp)==c+3
    printf("%s\n", **++cpp); //POINT *(cpp+1)==*(c+2)==POINT    cpp此时指向的是c+2
    printf("%s\n", *-- * ++cpp + 3); //ER +最后算  指向*(cpp+1)==c+2后面的地址 c+1 在-- 为c 在解引用为ENTER ENTER的地址+3 指向E R
    printf("%s\n", *cpp[-2] + 3); //ST  *(*(CPP-2))+3 CPP现在指向c+1的地址 cpp-2指向c+3的地址 解引用拿到c+3 在解引用拿到FIRST的地址 在+3地址指向S 打印为ST
    printf("%s\n", cpp[-1][-1] + 1);// *(*(cpp-1)-1)+1 cpp现在指向c+1的地址(没变) cpp-1指向c+2的地址 解引用拿到了c+2 -1后为c+1 在解引用得到NEW的地址 NEW+1 得到EW的地址 在打印为EW
    return 0;
}
*/
