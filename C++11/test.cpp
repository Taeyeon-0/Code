#include <iostream>
using namespace std;

struct Point {
    int _x;
    int _y;
};

int main() {
    int x1 = 1;
    int x2 = {2};


    //省略赋值符号
    int x3{3};
    int array1[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[5]{0};
    Point p{1, 2};

    //C++11中列表初始化也可以适用于new表达式中
    int *pa = new int[4]{0};
    return 0;
}