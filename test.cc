#include <iostream>
using namespace std;
// class HeapOnly {
// public:
//     static void Delete(HeapOnly *p) {
//         delete p;
//     }

//     //也可以这样delete
//     void Delete() {
//         delete this;
//     }

// private:
//     //析构函数私有
//     ~HeapOnly() {
//         cout << "~HeapOnly()" << endl;
//     }

// private:
//     int _a;
// };


// int main() {
//     //HeapOnly hp1;
//     //static HeapOnly hp2;
//     HeapOnly *ptr = new HeapOnly;
//     ptr->Delete(ptr);
//     ptr->Delete();

//     //delete ptr;
//     return 0;
// }


class HeapOnly {
public:
    //提供一个公有的，获取对象的方式,对象控制是new出来的，保证在堆上
    static HeapOnly *CreateObj() {
        return new HeapOnly();
    }

    HeapOnly(const HeapOnly &hp) = delete;
    HeapOnly &operator=(const HeapOnly &hp) = delete;
private:

    //方式二、构造函数私有
    HeapOnly()
        : _a(0) {}

private:
    int _a;
};

int main() {
    HeapOnly *sp4 = HeapOnly::CreateObj();
    delete sp4;
    return 0;
}