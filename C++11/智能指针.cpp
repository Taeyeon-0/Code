#include <iostream>
#include <memory>
using namespace std;


// 利用RAII思想设计delete资源的类
// 具有像指针一样的行为
template<class T>
class SmartPtr {
public:
    SmartPtr(T *ptr)
        : _ptr(ptr) {}

    ~SmartPtr() {
        cout << "delete:" << _ptr << endl;
        delete _ptr;
    }

    T &operator*() {
        return *_ptr;
    }

    T *operator->() {
        return _ptr;
    }

private:
    T *_ptr;
};
//
//
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//
//
//
//void Func() {
//	// 1、如果p1这里new
//	// 2、如果p2这里new
//	// 3、如果div调用这里
//	int* p1 = new int;
//	int* p2 = new int;
//
//	SmartPtr<int> sp1(p1);
//	SmartPtr<int> sp2(p2);
//	SmartPtr<int> sp3(new int);
//
//	cout << div() << endl;
//
//}
//
//
//int main() {
//	try {
//		Func();
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}


class A {
public:
    ~A() {
        cout << "~A()" << endl;
    }
    //private:
    int _a1 = 0;
    int _a2 = 0;
};

int main() {
	//auto_ptr已在C++17废除
    auto_ptr<A> ap1(new A);
    ap1->_a1++;
    ap1->_a2++;
    //cout << ap1->_a1 << " " << ap1->_a2 << endl;
    auto_ptr<A> ap2(ap1);
    //ap1的资源被转移，报错
    ap1->_a1++;
    ap1->_a2++;

    //自己写的
    SmartPtr<A> sp1(new A);
    sp1->_a1++;
    sp1->_a2++;

    //SmartPtr<A> sp2(sp1);  //报错，浅拷贝问题
    return 0;
}