#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

template<class T>
class vector {
public:
    typedef T *iterator;
    typedef const T *const_iterator;
    vector()
        : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
    }

    vector(size_t n, const T &val = T())
        : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
        reserve(n);
        for (size_t i = 0; i < n; i++) {
            push_back(val);
        }
    }
    // 重载构造函数
    vector(int n, const T &val = T())
        : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
        reserve(n);
        for (int i = 0; i < n; i++) {
            push_back(val);
        }
    }

    // 迭代器构造函数
    template<class InputIterator>
    vector(InputIterator first, InputIterator last) {
        while (first != last) {
            push_back(*first);
            first++;
        }
    }

    vector(const vector<T> &v) {
        _start = new T[v.capacity()];
        // memcpy(_start, v._start, sizeof(T) * v.size());
        // memcpy会还会导致深拷贝里的深拷贝问题。
        // 对于自定义类型，自定义类型里的内存，会被复制，那么拷贝构造的会指向同一块空间，会因调用析构函数出现报错。
        // 在进行深拷贝时，应该确保源vector的元素数量小于或等于目标vector的容量，否则会发生缓冲区溢出。
        if (v.size() <= capacity())// 确保源向量的大小小于或等于目标向量的容量
        {
            for (size_t i = 0; i < v.size(); i++) {
                // new (_start + i) T(v._start[i]);
                //  调用拷贝构造函数进行深拷贝
                _start[i] = v._start[i];
                // 进行_start[i]赋值。赋值对于自定义类型，会额外开空间，进行深拷贝。这样就解决了深拷贝里的深拷贝
            }
            _finish = _start + v.size();
        } else// 如果源向量的大小大于目标向量的容量，只拷贝目标向量能容纳的部分
        {
            for (size_t i = 0; i < capacity(); i++) {
                _start[i] = v._start[i];
            }
            _finish = _start + capacity();
        }
        _end_of_storage = _start + v.capacity();
    }

    iterator begin() {
        return _start;
    }

    iterator end() {
        return _finish;
    }

    // 这里必须加上const，两个begin函数，只是参数返回类型不同
    // 编译器无法根据函数返回类型来区分函数，
    // 因为函数重载不允许仅仅因为返回类型不同而进行区分。这将导致编译错误。
    // 加入const修饰符，以便编译器可以正确地区分这两个函数
    const_iterator begin() const {
        return _start;
    }

    const_iterator end() const {
        return _finish;
    }

    void reserve(size_t n) {
        int sz = size();
        // n>capacity才需要扩容，否则n<capacity可能会缩容
        if (n > capacity()) {
            T *tmp = new T[n];
            // 将_start的内存，拷贝到tmp中
            if (_start) {
                // memcpy是一种浅拷贝函数，这里会引起内存问题 ，因为后面_start要释放，调用析构函数
                // memcpy(tmp, _start, sizeof(T*) * size());
                for (size_t i = 0; i < size(); i++) {
                    // 手动深拷贝
                    tmp[i] = _start[i];
                }
                delete[] _start;
            }
            _start = tmp;
            _finish = _start + sz;
            // 这里_start内存发生了变化，所以_finish需要重新初始化，加上原来的sz即可
            // 不可以加上现在的size()，因为_start发生了变化，size()得不到想要的结果
            _end_of_storage = _start + n;
        }
    }

    void resize(size_t n, T val = T())// //T()默认构造，匿名对象，对于自定义类型，和内置类型比如int都会初始化
    {
        if (n < size()) {
            // 缩容
            _finish = _start + n;
        } else {
            if (n > capacity()) {
                reserve(n);
            }
            while (_finish != _start + n) {
                *_finish = val;
                _finish++;
            }
        }
    }

    void push_back(const T &x) {
        if (_finish == _end_of_storage) {
            // 扩容  一种是一开始都为NULL，另一种是需要扩容
            reserve(capacity() == 0 ? 4 : capacity() * 2);
        }

        *_finish = x;// 可能发生空指针解引用
        _finish++;
    }

    void pop_back() {
        if (!empty())
            _finish--;
    }

    void insert(iterator pos, const T &val = T()) {
        assert(pos >= _start);
        assert(pos <= _finish);
        if (_finish == _end_of_storage) {
            // 迭代器失效问题!
            // reserve扩容，会释放掉旧空间，那么pos位置也会被释放，需要更新pos，解决pos失效的问题
            // 那么pos的位置怎么算呢，相对位置！ 算出pos之前的相对_start的相对位置
            int len = pos - _start;
            reserve(capacity() == 0 ? 4 : capacity() * 2);
            // 更新pos
            pos = _start + len;
        }

        iterator end = _finish - 1;
        while (end >= pos) {
            *(end + 1) = *end;
            end--;
        }
        *pos = val;
        _finish++;
    }

    // erase后迭代器需要更新，因为迭代器指向的在删除后，会改变指向
    iterator erase(iterator pos) {
        assert(pos >= _start);
        assert(pos < _finish);
        iterator start = pos + 1;
        while (start != _finish) {
            *(start - 1) = *(start);
            ++start;
        }
        _finish--;

        // 返回pos的下一个地址，pos的下一个地址的值被赋值给上一个，所以还是返回pos。
        return pos;
    }

    bool empty() const {
        return _start == _finish;
    }

    size_t capacity() const {
        return _end_of_storage - _start;
    }

    size_t size() const {
        return _finish - _start;
    }

    T &operator[](size_t pos) {
        return _start[pos];
    }

    const T &operator[](size_t pos) const {
        return _start[pos];
    }

    ~vector() {
        delete[] _start;
        _start = nullptr;
        _finish = nullptr;
        _end_of_storage = nullptr;
    }

private:
    // vector的成员变量为3个迭代器
    iterator _start = nullptr;
    iterator _finish = nullptr;
    iterator _end_of_storage = nullptr;
    //_start 为开始下标0
    //_finish 为数值的下一个位置
    //_end_of_storage 为容量
};