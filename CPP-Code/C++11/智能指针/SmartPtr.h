#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace phw {
    template<class T>
    class auto_ptr {
    public:
        explicit auto_ptr(T* ptr = nullptr)
            : _ptr(ptr) {}

        auto_ptr(auto_ptr& ap)
            : _ptr(ap._ptr) {
            ap._ptr = nullptr;
        }

        auto_ptr<T>& operator=(auto_ptr<T>&ap) {
            if (this != &ap) {
                delete _ptr;

                _ptr = ap._ptr;
                ap._ptr = nullptr;
            }
            return *this;
        }

        T& operator*() {
            return *_ptr;
        }

        T* operator->() {
            return _ptr;
        }

        ~auto_ptr() {
            if (_ptr) {
                cout << "Delete:" << _ptr << endl;
                delete _ptr;
            }
        }

    private:
        T* _ptr;
    };

    template<class T>
    class unique_ptr {
    public:
        explicit unique_ptr(T* ptr = nullptr)
            : _ptr(ptr) {}

        //C++11 防拷贝
        unique_ptr(unique_ptr& ap) = delete;
        unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;

        //C++98
        //只声明不实现 ，加private
        /*private:
        unique_ptr(unique_ptr& ap);
        unique_ptr<T>& operator=(unique_ptr<T>& ap);*/

        T& operator*() {
            return *_ptr;
        }

        T* operator->() {
            return _ptr;
        }

        ~unique_ptr() {
            if (_ptr) {
                cout << "Delete:" << _ptr << endl;
                delete _ptr;
            }
        }

    private:
        T* _ptr;
    };

    template<class T>
    class shared_ptr {
    public:
        explicit shared_ptr(T* ptr = nullptr)
            : _ptr(ptr), _pCount(new int(1)) {}

        //C++11 防拷贝
        shared_ptr(shared_ptr& sp)
            : _ptr(sp._ptr), _pCount(sp._pCount) {
            (*_pCount)++;
        }

        //sp2 = sp1
        //sp1 = sp1
        shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
            //如果管理同一份资源,就直接返回
            if (this == &sp) {
                return *this;
            }


            //减减被赋值对象的计数，如果是最后一个对象，要释放资源
            if (--*_pCount == 0) {
                cout << "Delete:" << _ptr << endl;
                delete _ptr;
                delete _pCount;
            }

            _ptr = sp._ptr;
            _pCount = sp._pCount;
            (*_pCount)++;
            return *this;
        }


        T& operator*() {
            return *_ptr;
        }

        T* operator->() {
            return _ptr;
        }

        T* get() const{
            return _ptr;
        }

        int use_count(){
            return *_pCount;
        }

        ~shared_ptr() {
            if (--(*_pCount) == 0) {
                cout << "Delete:" << _ptr << endl;
                delete _ptr;
                delete _pCount;
            }
        }

    private:
        T* _ptr;
        int* _pCount;//引用计数
    };

    // 辅助型智能指针，使命配合解决shared_ptr的循环引用问题
    template<class T>
    class weak_ptr {
    public:
        weak_ptr()
            : _ptr(nullptr) {}

        explicit weak_ptr(const phw::shared_ptr<T>& sp)
            : _ptr(sp._ptr) {}

        weak_ptr(const phw::weak_ptr<T>& sp)
            : _ptr(sp._ptr) {}

        weak_ptr<T>& operator=(const shared_ptr<T>& sp) {
            _ptr = sp.get();
            return *this;
        }

        T& operator*() {
            return *_ptr;
        }

        T* operator->() {
            return _ptr;
        }

    private:
        T* _ptr;
    };

    //定制删除器
    template<class T>
    struct DeleteArray{
        void operator()(T* ptr) {
            delete[] ptr;
        }
    };

    template<class T>
    struct Free{
        void operator()(T* ptr) {
            free(ptr);
        }
    };
}// namespace phw