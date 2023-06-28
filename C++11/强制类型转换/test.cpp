#include <iostream>
using namespace std;

void Insert(size_t pos, char ch) {
    int size = 5;

    size_t end = size - 1;
    //while (end >= pos) {
    while ((int) end >= (int) pos) {
        // str[end + 1] = sttr[end];
        --end;
    }
}

void Test() {
    int i = 1;
    // 隐式类型转换 (意义相近的类型)
    double d = i;
    printf("%d,%.2f\n", i, d);

    int *p = &i;
    // 显示的强制类型转换
    //int address = (int) p;
    size_t address = reinterpret_cast<size_t>(p);;
    printf("%p,%x\n", p, address);

    Insert(5, 'a');
    Insert(0, 'a');
}


void test1() {
    double d = 12.34;
    int a = static_cast<int>(d);//相关类型用static_cast
    cout << a << endl;

    int *p = &a;
    //int address = static_cast<int>(p);   //不支持
    size_t address = reinterpret_cast<size_t>(p);//不相关类型用reinterpret_cast
}

void test2() {
    const int a = 2;
    //volatile const int a = 2;
    //int* p = (int*)&a;  //C语言老方法，C++兼容
    int *p = const_cast<int *>(&a);
    *p = 3;

    cout << a << endl; //2
    cout << *p << endl;//3
}

void test3() {
    int i = 0;
    double d = i;

    //double& rd = i;  //err， 因为i是一个临时对象
    const double &rd = i;//临时对象具有常性可以用const引用
    const double &rd2 = static_cast<double>(i);

    cout << rd << endl;
}

class A {
public:
    virtual void f() {}

    int _a = 0;
};

class B : public A {
public:
    int _b = 0;
};

void test4(A *pa) {
    //子类对象天然支持转给父类
    B bb;
    A aa = bb;
    A &ra = bb;

    //父类对象是不能转子类的
    /*B bb2 = aa1;
	bb2 = dynamic_cast<B>(aa1);
	bb3 = (B)aa;*/
}


//A*指针pa有可能指向父类，有可能指向子类
void fun(A *pa) {
    //B* pb = (B*)pa;
    //pb->_a++;
    //pb->_b++;  //程序崩溃
    //如果pa是指向子类，那么可以转换，转换表达式返回正确的地址
    //如果pa是指向父类，那么不能转换，转换表达式返回nullptr

    B *pb = dynamic_cast<B *>(pa);
    if (pb) {
        cout << "转换成功" << endl;
        pb->_a++;
        pb->_b++;
        cout << pb->_a << ":" << pb->_b << endl;
    } else {
        cout << "转换失败" << endl;//转换失败只可能是父亲，父亲无法调用子类的成员变量
        //pb->_a++;
        //cout << pb->_a << endl;  //空指针解引用
    }
}

void test5() {
    A aa;
    B bb;
    fun(&aa);
    fun(&bb);
    fun(nullptr);//转换失败
}

class A1 {
public:
    virtual void f() {}

public:
    int _a1 = 0;
};

class A2 {
public:
    virtual void f() {}

public:
    int _a2 = 0;
};

class B1 : public A1, public A2 {
public:
    int _b = 1;
};

void test6() {
    B1 bb;
    A1 *ptr1 = &bb;
    A2 *ptr2 = &bb;
    cout << ptr1 << endl;//009CF908
    cout << ptr2 << endl;//009CF910

    B1 *pb1 = (B1 *) ptr1;
    B1 *pb2 = (B1 *) ptr2;
    cout << pb1 << endl;//009CF908
    cout << pb2 << endl;//009CF908

    B1 *pb3 = dynamic_cast<B1 *>(ptr1);//009CF908
    B1 *pb4 = dynamic_cast<B1 *>(ptr2);//009CF908
    cout << pb3 << endl;
    cout << pb4 << endl;
}

int main() {
    //Test();
    //test4();
    test6();
    return 0;
}