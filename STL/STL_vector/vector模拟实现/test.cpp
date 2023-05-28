#include "vector.h"

void test_vector1() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    for (size_t i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";// 1 2 3 4 5
    }
    cout << endl;

    vector<int>::iterator it = v1.begin();
    while (it != v1.end()) {
        cout << *it << " ";// 1 2 3 4 5
        it++;
    }
    cout << endl;

    for (auto e: v1) {
        cout << e << " ";// 1 2 3 4 5
    }
    cout << endl;

    v1.pop_back();
    v1.pop_back();
    for (auto e: v1) {
        cout << e << " ";// 1 2 3
    }
    cout << endl;

    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    for (auto e: v1) {
        cout << e << " ";// 删完了，什么都没有打印
    }
    cout << endl;
}

// 针对const对象访问
void test_vector2() {
    // vector<int> v;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        (*it) *= 2;
        cout << *it << " ";// 2 4 6
        it++;
    }
    cout << endl;

    vector<int>::const_iterator cit = v.begin();
    while (cit != v.end()) {
        (*it) = 2;          // 没有效果，const迭代器不允许修改值
        cout << *cit << " ";// 2 4 6
        cit++;
    }
}

template<class T>
void f() {
    T x = T();
    cout << x << endl;
}

// 内置类型有没有构造函数，因为模板需要
void test_vector3() {
    int i = int();// 默认有初始化为0
    i = int(1);   // 初始化1
    // int* pi = int* ();
    f<int>();   // 0
    f<int *>(); // 000000000
    f<double>();// 0
}

void test_vector4() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    cout << v1.size() << endl;    // 5
    cout << v1.capacity() << endl;// 8
    v1.resize(10);

    cout << v1.size() << endl;    // 10
    cout << v1.capacity() << endl;// 10

    for (auto e: v1) {
        cout << e << " ";// 1 2 3 4 5 0 0 0 0 0
    }
    cout << endl;
    // 只保留3个
    v1.resize(3);
    for (auto e: v1) {
        cout << e << " ";// 1 2 3
    }
    cout << endl;
}

// insert
void test_vector5() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    for (auto e: v1) {
        cout << e << " ";// 1 2 3 4 5
    }
    cout << endl;

    v1.insert(v1.begin(), 666);
    v1.insert(v1.end(), 666);
    for (auto e: v1) {
        cout << e << " ";// 666 1 2 3 4 5 666
    }
    cout << endl;

    auto pos = find(v1.begin(), v1.end(), 3);
    v1.insert(pos, 30);
    for (auto e: v1) {
        cout << e << " ";// 666 1 2 30 3 4 5 666
    }
    cout << endl;

    pos = find(v1.begin(), v1.end(), 3);// pos必须更新,因为pos在之前插入，已经改变了值
    (*pos) = 666;                       // 这里如果没有更新pos，那么就是改变30的值，更新后改变3的值s
    for (auto e: v1) {
        cout << e << " ";// 666 1 2 30 666 4 5 666
    }
    cout << endl;

    while (pos != v1.end()) {
        pos = find(v1.begin(), v1.end(), 666);
        v1.erase(pos);
    }

    for (auto e: v1) {
        cout << e << " ";// 1 2 30 4 5
    }
    cout << endl;
}

// erase
void test_vector6() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    for (auto e: v1) {
        cout << e << " ";// 1 2 3 4
    }
    cout << endl;

    // 要求删除所有的偶数
    vector<int>::iterator it = v1.begin();
    while (it != v1.end()) {
        if (*it % 2 == 0) {
            // 删除后，结果返回it，erase的返回值是原先下一个地址的，这样迭代器不会失效，更新迭代器
            it = v1.erase(it);
        } else {
            it++;
        }
    }

    for (auto e: v1) {
        cout << e << " ";// 1 3
    }
    cout << endl;
}

class A {
public:
    A() {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

void test_vector7() {
    A a1;
    const A &xx = A();// const 引用会让匿名对象声明周期延长，延长到xx销
}

void test_vector8() {
    vector<int> v(10, 5);
    // vector(size_t n, const T& val = T())和vector(InputIterator first, InputIterator last)，
    // 会调用后者，因为10和5是int类型，会调用后面的模板,所以需要重载vector(int n, const T& val = T())
    for (auto e: v) {
        cout << e << " ";// 5 5 5 5 5 5 5 5 5 5
    }
    cout << endl;

    // 迭代器构造函数
    vector<int> v2(v.begin() + 1, v.end());
    for (auto e: v2) {
        cout << e << " ";// 5 5 5 5 5 5 5 5 5
    }
    cout << endl;

    string s1("Hello");
    vector<int> v3(s1.begin(), s1.end());
    for (auto e: v3) {
        cout << e << " ";// 72 101 108 108 111
    }
    cout << endl;

    int a[] = {10, 20, 30};
    vector<int> v4(a, a + 3);// 原生指针就是天然迭代器
    for (auto e: v4) {
        cout << e << " ";// 10 20 30
    }
    cout << endl;
}

// sort - 依赖头文件#include<algorithm> - 默认升序
// greater降序 - 依赖头文件#include<functional>
void test_vector9() {
    vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    for (auto e: v) {
        cout << e << " ";// 5 1 3 4 2
    }
    cout << endl;

    sort(v.begin(), v.end());
    for (auto e: v) {
        cout << e << " ";// 1 2 3 4 5
    }
    cout << endl;

    int a[] = {3, 7, 2, 4, 5, 6, 8, 1};
    sort(a, a + sizeof(a) / sizeof(int));
    for (auto e: a) {
        cout << e << " ";// 1 2 3 4 5 6 7 8
    }
    cout << endl;

    // 改为降序
    greater<int> g;
    sort(a, a + sizeof(a) / sizeof(int), g);
    // sort(a, a + sizeof(a) / sizeof(int), greater<int>());  //传匿名对象
    for (auto e: a) {
        cout << e << " ";// 8 7 6 5 4 3 2 1
    }
    cout << endl;
}

// 深浅拷贝
void test_vector10() {
    vector<int> v1(10, 5);
    for (auto e: v1) {
        cout << e << " ";// 5 5 5 5 5 5 5 5 5 5
    }
    cout << endl;

    vector<int> v2(v1);// 没有写深拷贝，编译器调用默认构造函数，浅拷贝
    for (auto e: v2) {
        cout << e << " ";// 5 5 5 5 5 5 5 5 5 5
    }
    cout << endl;

    vector<string> v3(5, "11111111111111111");
    for (string e: v3) {
        cout << e << " ";
    }
    cout << endl;

    vector<string> v4(v3);
    for (string e: v4) {
        cout << e << " ";
    }
    cout << endl;

    v4.push_back("22222222222222\n");
    v4.push_back("22222222222222\n");
    v4.push_back("22222222222222");
    v4.push_back("22222222222222");
    v4.push_back("22222222222222");
    v4.push_back("22222222222222");
    v4.push_back("22222222222222");
    v4.push_back("22222222222222");
    v4.push_back("2");
    for (string e: v4) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    test_vector10();
    return 0;
}