#include <stdio.h>
/* 
变量用于存储和操作可变数据，其值可以在程序执行过程中发生变化。
常量用于表示不可更改的固定值，其值在定义时确定，并且不能再进行修改。
*/

//3.1 定义变量的方法
int age = 150;
float weight = 45.5f;
char ch = 'w';


//3.2 变量的分类
//·局部变量
//·全局变量
int global = 2019;//全局变量
void test1() {
    int local = 2018;//局部变量
    //下面定义的global会不会有问题？
    int global = 2020;              //局部变量
    printf("global = %d\n", global);//global = 2020
}
//★当局部变量和全局变量同名时，局部变量优先使用

//3.3 变量的使用
void test2() {
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    printf("请输入两个操作数：>");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    printf("sum = %d\n", sum);
}

//3.4 变量的作用域和生命周期
//作用域：限定这个名字的可用性的代码范围就是这个名字的作用域
//1.局部变量的作用域是变量实在的局部范围
//2.全局变量的作用域是整个工程

//块作用域
void test3() {
    int x = 10;
    {
        int y = 20;
        printf("%d\n", x);// 可以访问外部块中的变量
        printf("%d\n", y);// 可以访问内部块中的变量
    }
    printf("%d\n", x);// 可以继续访问外部块中的变量
    // printf("%d\n", y);  // 错误！超出了变量 y 的作用域
}


//函数作用域
int sum(int a, int b) {
    int result = a + b;
    return result;
}

void test4() {
    int x = 10;
    int y = 20;
    int total = sum(x, y);
    printf("%d\n", total);
    // printf("%d\n", result);  // 错误！超出了变量 result 的作用域
}


//文件作用域：
int globalVar = 10;

void function1() {
    printf("%d\n", globalVar);// 可以访问文件作用域的变量
}

void function2() {
    printf("%d\n", globalVar);// 可以访问文件作用域的变量
}

void test5() {
    printf("%d\n", globalVar);// 可以访问文件作用域的变量
    function1();
    function2();
}


//生命周期：变量的生命周期指的是变量的创建到变量的烧毁之间的一个时间段
//1.局部变量的生命周期是：进入作用域生命周期开始，出作用域生命周期结束。
//2.全局变量的生命周期是：整个程序的生命周期。

//自动变量
void function3() {
    int x = 10;  // 自动变量，生命周期与函数调用关联
    printf("%d\n", x);
}

void test6() {
    function3();  // 调用函数
    // printf("%d\n", x);  // 错误！变量 x 不在作用域内
}

//静态变量
void function4() {
    static int count = 0;  // 静态变量，生命周期与程序运行关联
    count++;
    printf("%d\n", count);
}

void test7() {
    function4();  // 调用函数，输出：1
    function4();  // 调用函数，输出：2
    function4();  // 调用函数，输出：
}

//全局变量
int globalVar2;  // 全局变量

void function5() {
    globalVar2 = 10;
}

void test8() {
    function5();  // 调用函数
    printf("%d\n", globalVar2);  // 输出：10
}


//3.5 常量
//C语言的常量分为以下几种：
//·字面常量
//·const修饰的常变量
//·#define定义的标识符常量
//·枚举常量

void test9() {

    3.14;//字面常量
    1000;//字面常量

    //const修饰的常变量
    const float pai = 3.14f;//pai是const修饰的常变量
                            //pai = 5.14;  //err ★因为pai被const修饰，所以pai不能被修改
                            //const修饰的常变量在C语言中只是在语法层面限制了变量pai不能被改变，但是pai本质上死一个变量，所以叫常变量

    //#define的标识符常量
#define MAX 100
    printf("max = %d\n", MAX);//100

    //枚举常量
    enum Sex {
        Male,
        Female,
        Secret
    };
    //括号中的Male，Female，Secret是枚举常量
    printf("%d\n", Male);  //0
    printf("%d\n", Female);//1
    printf("%d\n", Secret);//2
    //★枚举常量的默认是0开始，以此向下递增1
}

int main() {
    test1();
    return 0;
}