#include<stdio.h>
int main()
{
	const int num = 10;
	// num = 20;    //不能更改被const修饰的变量
	
	int* p = &num;
	*p = 20;      ////可以更改const修饰的变量
	
	const int* p1 = &num;
	// *p1 = 20;      //err 
	
	int ret = 0;
	p1 = &ret;   //p1可以更改

	int* const p2 = &num;
	//p2 = &ret;   //p2被const修饰  不能更改      

	int const* const p3 = &num;   //都改不了
	//*num = 10;
	//pe = &ret;
	printf("%d\n", num);   //20
	return 0;
}

//const修饰指针，放在*的左边，表示的指针指向的内容不能通过指针来修改，但是指针变量本身可修改
//*p=20  err 

//const修饰指针时，放在*的右边，表示指针变量本身不能修改，但是指针指向的内容可以通过指针来修改

