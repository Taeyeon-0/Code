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


//class HeapOnly {
//public:
//    //提供一个公有的，获取对象的方式,对象控制是new出来的，保证在堆上
//    static HeapOnly *CreateObj() {
//        return new HeapOnly();
//    }
//
//    HeapOnly(const HeapOnly &hp) = delete;
//    HeapOnly &operator=(const HeapOnly &hp) = delete;
//private:
//
//    //方式二、构造函数私有
//    HeapOnly()
//        : _a(0) {}
//
//private:
//    int _a;
//};
//
//int main() {
//    HeapOnly *sp4 = HeapOnly::CreateObj();
//    delete sp4;
//    return 0;
//}


// 只能在栈上创建对象
//class StackOnly {
//public:
//    static StackOnly CreateObj() {
//        StackOnly st;
//        return st;
//    }
//
//    //不能防拷贝
//    //StackOnly(const StackOnly& st) = delete;    //不能修改此处，这样CreateObj()返回会调用拷贝构造，禁用后就无法返回
//    //StackOnly& operator = (const StackOnly& st) = delete;
//    void *operator new(size_t n) = delete;
//
//private:
//    //构造函数私有
//    StackOnly()
//        : _a(0) {}
//
//private:
//    int _a;
//};
//
//int main() {
//    StackOnly st1 = StackOnly::CreateObj();
//    //构造函数私有了，但还是可以调用拷贝构造
//    StackOnly st2(st1);
//    //auto* st3 = new StackOnly(st1);
//    return 0;
//}


// 饿汉模式  -- main函数之前就创建出对象
// 优势：简单、没有线程安全问题
// 缺点：1、一个程序中，多个单列，并且有先后创建初始化顺序要求是，饿汉无法控制。
//       比如程序两个单列类A和B，假设要求A先创建初始化，B再创建初始化。
//      2、饿汉单例类，初始化时任务多，会影响程序的启动时间
class MemoryPool {
public:
    static MemoryPool *GetInstance() {
        return _inst;
    }

    void *Alloc(size_t n) {
        void *ptr = nullptr;

        return _ptr;
    }


private:
    //构造函数私有
    MemoryPool() {}

    char *_ptr = nullptr;

    static MemoryPool *_inst;//声明
};

int main() {
    void *ptr1 = MemoryPool::GetInstance()->Alloc(10);
}
