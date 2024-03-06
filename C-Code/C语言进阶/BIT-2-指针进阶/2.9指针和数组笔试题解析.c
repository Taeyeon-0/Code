#include<stdio.h>
#include<string.h>
//关于数组名
//数组名是数组首元素的地址
//但是有两个例外：
//1.sizeof(数组名) - 数组名表示整个数组，计算的是整个数组的大小，单位是字节
//2.&数组名 - 数组名也表示整个数组，取出的是整个数组的地址
//除了这2个例外，你见到的所有的数组名都表示首元素的地址

//1.一维数组
/*
int main()
{
	int a[] = { 1,2,3,4 };
	//a - int*
	//&a - int (*)[4]
	printf("%d\n", sizeof(a));    //16，a作为数组名单独放在sizeof内部，计算的是数组的总大小，单位是字节
	printf("%d\n", sizeof(a + 0)); //4 并非单独放在sizeof内部，也没有&，所以数组名a就是数组首元素的地址
	printf("%d\n", sizeof(*a));    //4  a是首元素的地址，*a就是首元素1
	printf("%d\n", sizeof(a + 1)); //4  a是首元素的地址，a+1 跳过一个int 第二个元素的地址
	printf("%d\n", sizeof(a[1]));  //4  a[1]就是数组的第二个元素
	printf("%d\n", sizeof(&a));    //4  取出的是数组的地址，数组的地址，也是地址
	printf("%d\n", sizeof(*&a));   //★ 16 - &a是数组的地址，是数组指针类型。*&a是对一个数组指针解引用，访问的是整个数组
	printf("%d\n", sizeof(&a + 1)); //4 &a数组的地址，&a+1跳过了整个数组，还是个地址
	printf("%d\n", sizeof(&a[0]));   //4  a[0]是数组的第一个元素，&a[0]就是第一个元素的地址
	printf("%d\n", sizeof(&a[0] + 1));  //4  a[0]+1是数组的第二个元素，&a[0]+1就是第二个元素的地址
	return 0;
}
*/


//2.字符数组
//sizeof是计算对象或者类型创建的对象所占用内存空间的大小，单位为字节
//sizeof是操作符，不是函数

//strlen求字符串长度的，计算的是字符串\0之前出现的字符的个数
//统计到\0为止，如果没有看到\0,会继续往后找
//srtlen是库函数
/*2.1
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };

	printf("%d\n", sizeof(arr));  //6 arr是数组名，并且是单独放在sizeof内部，计算的是数组的大小
	printf("%d\n", sizeof(arr + 0)); //4 arr是数组名，并非单独放在sizeof内部，arr数组名表示首元素的地址，arr+0还是首元素的地址
	printf("%d\n", sizeof(*arr)); //1 arr是首元素地址，对首元素地址解引用，*arr就是首元素的大小
	printf("%d\n", sizeof(arr[1])); //1 arr[1]是数组的第二个元素，就是第二个元素的大小
	printf("%d\n", sizeof(&arr));  //4 &arr - 取出的是数组的地址，计算的数组的地址的大小
	printf("%d\n", sizeof(&arr + 1)); //4 跳过整个数组的地址，本质上还是地址
	printf("%d\n", sizeof(&arr[0] + 1)); //4 arr[0]是a的地址，&arr[0]+1是b的地址

	printf("%d\n", strlen(arr)); //随机值 arr是数组名，但是没有放在sizeof内部，也没有&，arr就是首元素的地址
	//strlen得到arr后，从arr数组首元素的地址，开始计算字符的长度，直到找到\0，但是arr数组内存中没有\0,arr内存后有没有\0，是不确定的，所以是随机的
	printf("%d\n", strlen(arr + 0)); //随机值 arr是数组首元素地址，arr+0还是首元素的地址
	printf("%d\n", strlen(*arr)); //err 会非法访问内存 arr是数组首元素地址 *arr是首元素，就是字符'a' - 97
	//strlen就把'a'的ASCLL码值97当成了地址 内存中没有97地址，所以非法访问内存
	printf("%d\n", strlen(arr[1])); //err  这个arr[1]是第二个元素 跟上面一样
	printf("%d\n", strlen(&arr)); //随机值 &arr是数组的地址，数组的地址也是指向数组起始位置，和第一个一样
	printf("%d\n", strlen(&arr + 1)); //随机值 从arr数组最后开始数
	printf("%d\n", strlen(&arr[0] + 1)); //随机值 从arr数组第一个元素开始数
	return 0;
}
*/

/*2.2
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr)); //7
	printf("%d\n", sizeof(arr + 0)); //7
	printf("%d\n", sizeof(*arr)); //1  拿到了第一个地址的元素
	printf("%d\n", sizeof(arr[1])); //1  拿到了数组第二个元素
	printf("%d\n", sizeof(&arr)); //4
	printf("%d\n", sizeof(&arr + 1)); //4
	printf("%d\n", sizeof(&arr[0] + 1));  //4

	printf("%d\n", strlen(arr));  //6
	printf("%d\n", strlen(arr + 0)); //6
	printf("%d\n", strlen(*arr)); //err  元素当地址
	printf("%d\n", strlen(arr[1])); //err  元素当地址
	printf("%d\n", strlen(&arr));  //6
	printf("%d\n", strlen(&arr + 1));  //随机值
	printf("%d\n", strlen(&arr[0] + 1)); //5

	return 0;
}
*/

/*2.3
int main()
{
	char* p = "abcdef";
	printf("%d\n", sizeof(p));  //4 - 一个指针变量的大小
	printf("%d\n", sizeof(p + 1));  //4
	printf("%d\n", sizeof(*p)); //1
	printf("%d\n", sizeof(p[0]));  //1
	printf("%d\n", sizeof(&p)); //4
	printf("%d\n", sizeof(&p + 1));  //4
	printf("%d\n", sizeof(&p[0] + 1)); //4

	printf("%d\n", strlen(p));  //6 - p指向首地址
	printf("%d\n", strlen(p + 1)); //5
	printf("%d\n", strlen(*p)); //err  strlen需要地址
	printf("%d\n", strlen(p[0])); //err
	printf("%d\n", strlen(&p)); //随机值  p的地址不知道
	printf("%d\n", strlen(&p + 1)); //随机值
	printf("%d\n", strlen(&p[0] + 1)); //5  取第一个地址在加上一个地址 此时首地址为b
	return 0;
}
*/


//3.二维数组
/*
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));  //48 计算的是数组的总大小
	printf("%d\n", sizeof(a[0][0])); //4  第一行第一列的元素
	printf("%d\n", sizeof(a[0])); //16  计算的一行的数组名总大小
	printf("%d\n", sizeof(a[0] + 1)); //4  a[0]虽然是第一行的数组吗，但并非单独放在sizeof内部，
	//a[0]并非表示整个第一行数组，a[0]就是第一行首元素地址，+1就是第二个地址
	printf("%d\n", sizeof(*(a[0] + 1))); //4 a[0]+1就是第二个元素的地址，*就是第二个元素，
	printf("%d\n", sizeof(a + 1)); //4 a是二维数组的数组名，没有单独放在sizeof内部，也没有&，所以a是首元素地址，
	//二维数组把它想象成1维数组，它的第一个元素就是二维数组的第一行
	//a就是第一行的地址，a的类型 - int(*)[4]  +1就会跳过一行数组，就变成了第二行的地址
	printf("%d\n", sizeof(*(a + 1))); //16  a+1是第二行的地址，*(a+1) 找到的就是第二行，就是计算的第二行的大小 *(a+1) 等价于a[1]
	printf("%d\n", sizeof(&a[0] + 1)); //4 &a[0]+1是第二行的地址，计算的是第二行地址大小
	printf("%d\n", sizeof(*(&a[0] + 1))); //16 对第二行地址解引用，拿到的就是第二行的数据
	printf("%d\n", sizeof(*a)); //16 a表示首元素地址，就是第一行的地址，*a就是拿第一行的数据
	printf("%d\n", sizeof(a[3])); //16 a[3]是二维数组的第4行，虽然没有第四行，但是类型能确定，大小就是确定的，一行的大小
	//能够分析出a[3]的类型是：int[][4]
	//任何一个表达式有2个属性
	//3+5 值属性：8  类型属性：int
	return 0;
}
*/



int main()
{
	short num = 20;
	int a = 1;
	printf("%d\n", sizeof(num = a + 5)); //sizeof内部的表达式不参与运算
	printf("%d\n", num);
	return 0;
}