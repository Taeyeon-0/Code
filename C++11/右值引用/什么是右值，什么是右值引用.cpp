#include <iostream>
#include <utility>
using namespace std;

// int main() {
//     double x = 1.1, y = 2.2;
//     // 以下几个都是常见的右值
//     10;
//     x + y;
//     fmin(x, y);
//     // 以下几个都是对右值的右值引用
//     int &&rr1 = 10;
//     double &&rr2 = x + y;
//     double &&rr3 = fmin(x, y);
//     // 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//     10 = 1;
//     x + y = 1;
//     fmin(x, y) = 1;
//     return 0;
// }

int main() {
    double x = 1.1, y = 2.2;
    int &&rr1 = 10;
    const double &&rr2 = x + y;
    rr1 = 20;
    rr2 = 5.5;// 报错
    return 0;
}

void test() {
    // 左值引用只能引用左值，不能引用右值。
    int a = 10;
    int &ra1 = a; // ra为a的别名
    int &ra2 = 10;// 编译失败，因为10是右值
    // const左值引用既可引用左值，也可引用右值。
    // 编译器会生成一个临时的常量对象，并将const左值引用绑定到该临时对象上。
    const int &ra3 = 10;
    const int &ra4 = a;
}

void test() {
    // 右值引用只能右值，不能引用左值。
    int &&r1 = 10;

    // error C2440: “初始化”: 无法从“int”转换为“int &&”
    // message : 无法将左值绑定到右值引用
    int a = 10;
    //int &&r2 = a;
    // 右值引用可以引用move以后的左值
    int &&r3 = std::move(a);
}

void test() {
    int x = 10;
    cout << x << endl;   // 正确，x 是左值
    cout << 20 << endl;  // 正确，20 是右值
    const int &ref = x;  // 正确，将左值绑定到 const 左值引用
    const int &temp = 30;// 正确，将右值绑定到 const 左值引用，创建一个临时对象
}