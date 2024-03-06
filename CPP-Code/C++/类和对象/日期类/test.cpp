#include "Date.h"
void Test() {
    Date d1(2023, 2, 4);
    Date d2 = d1 + 100;//
    d1.Print();
    d2.Print();

    Date d3 = d1 += 100;
    d1.Print();
    d3.Print();
}

void Test1() {
    Date d1(2023, 2, 4);
    d1.Print();
    ++d1;//d1.opeartor++();
    d1.Print();

    d1++;//d1.operator++(int);  int参数 仅仅是为了占位，跟前置重载区分
    d1.Print();
}

void Test2() {
    Date d1(2023, 2, 4);
    d1.Print();
    Date d2 = d1 - 100;
    d2.Print();

    Date d3(2023, 2, 7);
    d3 += -100;
    d3.Print();

    Date d4(2023, 2, 7);
    d4 -= -100;//-=就变成了+=
    d4.Print();
}

void Test3() {
    Date d1(2023, 2, 4);
    d1.Print();
    Date ret1 = ++d1;
    d1.Print();
    ret1.Print();

    Date ret2 = d1++;
    d1.Print();
    ret2.Print();
}

void Test4() {
    Date d1(2023, 2, 4);

    Date d2(2023, 2, 5);
    cout << d1 - d2 << endl;
}

//输出流重载
void Test5() {
    Date d1(2023, 2, 4);

    int i = 1;
    double d = 1.11;
    //运算符重载+函数重载
    //cout << i << endl;  //cout.operator<<(int i)
    //cout << d << endl;  //cout.opeartor<<(double val)
    //自定义能用<<吗，可以需要自己重载

    //cout << d1;  /err
    //d1.operator<<(cout);
    //d1<<cout

    //operator<<(cout, d1);
    //cout << d1;
    Date d2(2023, 1, 1);
    cout << d1 << d2 << endl;
}
//输入流重载
void Test6() {
    Date d1;
    cin >> d1;
    cout << d1;
}

int main() {
    Test6();
    return 0;
}