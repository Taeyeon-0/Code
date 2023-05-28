#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void test_vector1() {
    // 1.vector()   无参构造
    vector<int> v1;
    // 2.vector（size_type n, const value_type& val = value_type())   构造并初始化n个val
    vector<int> v2(4, 100);
    // 3.vector (const vector& x)   拷贝构造
    vector<int> v3(v2);
    // 4.vector (InputIterator first, InputIterator last)   使用迭代器进行初始化构造
    vector<int> v4(v3.begin(), v3.end());
}

void PrintVector(const vector<int> &v) {
    // const对象使用const迭代器进行遍历打印
    // vector<int>::iterator it = v.begin();   //err 必须const_迭代器
    vector<int>::const_iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

// vector的迭代器遍历
void test_vector2() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";// 1 2 3 4 5
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";// 1 2 3 4 5
        it++;
    }
    cout << endl;
    // C++11 范围for，底层是由迭代器实现的
    for (auto e: v) {
        cout << e << " ";// 1 2 3 4 5
    }
    cout << endl;

    // 使用迭代器进行修改
    it = v.begin();
    while (it != v.end()) {
        (*it) *= 2;
        it++;
    }

    for (auto e: v) {
        cout << e << " ";// 2 4 6 8 10
    }
    cout << endl;

    // 使用反向迭代器进行遍历打印
    vector<int>::reverse_iterator rit = v.rbegin();
    while (rit != v.rend()) {
        cout << *rit << " ";// 10 8 6 4 2
        rit++;
    }
    cout << endl;

    PrintVector(v);// 2 4 6 8 10
}

void TestVectorExpand() {
    size_t sz;
    vector<int> v;
    sz = v.capacity();
    v.reserve(100);// 提前将容量设置好，可以避免一遍插入一遍扩容
    cout << "making v grow:\n";
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        if (sz != v.capacity()) {
            sz = v.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }
}

// vector的resize和reserve
//  reisze(size_t n, const T& data = T())
//  将有效元素个数设置为n个，如果时增多时，增多的元素使用data进行填充
//  注意：resize在增多元素个数时可能会扩容

void test_vector3() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    v.resize(5);
    v.resize(8, 100);
    v.resize(12);
    // vector<int> v2(10,0);  //这也可以 ，构造开空间，不推荐，有些情况不适用
    cout << "v contains:";
    for (size_t i = 0; i < v.size(); i++) {
        cout << ' ' << v[i];// 0 1 2 3 4 100 100 100 0 0 0 0
    }
    cout << endl;

    cout << v.size() << endl;    // 12
    cout << v.capacity() << endl;// 16
    cout << v.empty() << endl;   // 0
}

// vector Element access
void test_vector4() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << v[1] << endl;// 2
    // cout<<v[7]<<endl;  //越界不报错,打印0
    cout << v.at(1) << endl;// 2
    // cout<<v.at(7)<<endl;   // 越界报错
    cout << v.data() << endl; // 返回C格式地址，0xec1740
    cout << v.front() << endl;// 1
    cout << v.back() << endl; // 5
}

// vector增删查改
void test_vector5() {
    vector<int> v;
    // vector<int> v{1,2,3,4};  //C++11支持
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.pop_back();
    auto it = v.begin();
    while (it != v.end()) {
        cout << *it << " ";// 1 2 3
        it++;
    }
    cout << endl;

    // 在指定位置前插入值为val的元素，比如：3之前插入30,如果没有则不插入
    // 1. 先使用find查找3所在位置
    // 注意：vector没有提供find方法，如果要查找只能使用STL提供的全局find
    auto pos = find(v.begin(), v.end(), 3);
    if (pos != v.end()) {
        v.insert(pos, 30);
    }

    for (auto e: v) {
        cout << e << " ";// 1 2 30 3
    }
    cout << endl;

    // 删除pos位置的数据 ,我们删除30
    pos = find(v.begin(), v.end(), 30);
    v.erase(pos);
    for (auto e: v) {
        cout << e << " ";// 1 2 3
    }
    cout << endl;
}

// assign/clear/swap接口测试
void test_vector6() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v2 = {11, 12, 13, 14, 15};
    v1.assign(v2.begin(), v2.end());
    for (auto e: v1) {
        cout << e << " ";// 11 12 13 14 15
    }
    cout << endl;

    vector<int> v3 = {1, 2, 3, 4, 5};
    v3.assign(5, 0);
    for (auto e: v3) {
        cout << e << " ";// 0 0 0 0 0
    }
    cout << endl;

    // clear清理
    v1.clear();
    for (auto e: v1) {
        cout << e << " ";// 什么都没有打印
    }
    cout << endl;
    cout << v1.capacity() << endl;// 10;
    cout << v1.size() << endl;    // 0

    // 交换v2和v3  v2为11 12 13 14 15  v3为0 0 0 0 0
    v2.swap(v3);
    for (auto e: v3) {
        cout << e << " ";// 11 12 13 14 15
    }
    cout << endl;
}

int main() {
    test_vector6();
    return 0;
}