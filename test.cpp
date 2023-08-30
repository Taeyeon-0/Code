#include <iostream>
using namespace std;

class A {
public:
    virtual void f() {
        cout << "A::f()" << endl;
    }
};

class B : public A {
private:
    virtual void f() {
        cout << "B::f()" << endl;
    }
};

int main() {
    A *pa = (A *) new B;// 创建B类的实例并赋值给A类指针

    pa->f();  // 调用虚函数f()，输出结果会根据实际对象类型动态决定
    delete pa;// 释放内存

    return 0;
}
