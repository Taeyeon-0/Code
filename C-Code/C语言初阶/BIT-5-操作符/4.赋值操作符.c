#include<stdio.h>
/*
int main()
{
	int weight = 120;//体重
	weight = 89;//不满意就赋值
	double salary = 10000.0;
	salary = 20000.0;//使用赋值操作符赋值。
	return 0;
}
*/


//连续赋值
/*
int main()
{
	int a = 10;
	int b = 0;
	b = a = a + 3;
	printf("%d %d", a, b);
	return 0;
}
*/

/*
int a = 10;
int x = 0;
int y = 20;
a = x = y+1;//连续赋值
这样的代码感觉怎么样？
那同样的语义，你看看：
x = y+1;
a = x;
这样的写法是不是更加清晰爽朗而且易于调试。
*/


//复合赋值符
/*
+=
-=
*=
/=
%=
>>=
<<=
&=
|=
^=
*/

/*
int x = 10;
x = x + 10;
x += 10;//复合赋值
//其他运算符一样的道理。这样写更加简洁。
*/


/*
int main()
{
	int a = 10;
	//a = a >> 1;   //向右移位 缩小一倍 5
	a >>= 1;
	return 0;
}
*/


