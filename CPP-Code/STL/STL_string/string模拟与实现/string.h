#pragma once
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
namespace phw {
    class string {
    private:
        friend ostream &operator<<(ostream &out, const phw::string &s);
        friend istream &operator>>(istream &in, phw::string &s);

    public:
        // 带参构造函数
        // string(const char* str = nullptr)  //不可以 给空指针，strlen会报错
        // string(const char* str = '\0')  //\0 char转换成指针，也是空指针
        // string(const char* str = "\0")   //可以,给常量字符串，strlen不会报错
        string(const char *str = "")// 空字符串默认是\0
            : _size(strlen(str)) {
            _capacity = _size == 0 ? 3 : _size;// 最少给3个字节空间
            _str = new char[_capacity + 1];    // new _capacity+1  capacity是字符串容量，存放的有效字符大小，不是空间，空间还有一个\0
            strcpy(_str, str);
        }

        // 拷贝构造
        string(const string &s)
            : _size(s._size),
              _capacity(s._capacity) {
            //_str自己开空间
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
        }

        // 赋值是对已经定义的对象进行赋值
        // 有一种情况是，原对象的空间远大于要赋值的对象，那么就会出现空间浪费
        // 所以首先应该delete掉原空间的内存，在进行赋值
        string &operator=(const string &s) {
            if (this != &s) {
                // delete[]_str;  //赋值提前把旧空间释放，防止浪费空间
                //_str = new char[s._capacity + 1];
                // strcpy(_str, s._str);
                //_size = s._size;
                //_capacity = s._capacity;
                // 下面的写法更加安全
                char *tmp = new char[s._capacity + 1];
                strcpy(tmp, s._str);
                delete[] _str;
                _str = tmp;
                _size = s._size;
                _capacity = s._capacity;
            }
            return *this;
        }

        // 迭代器相关
        typedef char *iterator;
        typedef const char *const_iterator;
        iterator begin() {
            return _str;
        }

        const_iterator begin() const {
            return _str;
        }

        iterator end() {
            return _str + _size;
        }

        const_iterator end() const {
            return _str + _size;
        }

        // 获取字符串
        const char *c_str() {
            return _str;
        }

        //[]通过下标来访问字符
        char &operator[](size_t pos) {
            return _str[pos];
        }

        // 访问const类型的数组
        const char &operator[](size_t pos) const {
            return _str[pos];
        }

        size_t size() const {
            return _size;
        }

        size_t capacity() const {
            return _capacity;
        }

        ~string() {
            delete[] _str;
            _size = 0;
            _capacity = 0;
        }

        void Print(const string &s) {
            for (size_t i = 0; i < s.size(); i++) {
                cout << s._str[i] << " ";
            }
            cout << endl;
            // 这里不支持范围for了，为什么？  因为这里s是const对象，只能调用const迭代器
            string::const_iterator it = s.begin();
            while (it != s.end()) {
                //(*it)++;  //err. const迭代器指向的内容不能修改
                it++;
            }
            // 这里没有定义const迭代器，就会报错，范围for的底层就是迭代器
            for (auto ch: s) {
                cout << ch << " ";
            }
            cout << endl;
        }

        // 不修改成员变量数据的函数，最好加上const
        bool operator==(const string &s) const {
            return strcmp(_str, s._str) == 0;
        }

        bool operator!=(const string &s) const {
            return !(_str == s._str);
        }

        bool operator>(const string &s) const {
            return strcmp(_str, s._str) > 0;
        }

        bool operator>=(const string &s) const {
            return *this > s || *this == s;
        }

        bool operator<(const string &s) const {
            return !(*this >= s);
        }

        bool operator<=(const string &s) const {
            return !(*this > s);
        }

        // 开空间，另外开辟空间
        void reserve(size_t n) {
            if (n > _capacity) {
                char *tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }

        // 扩容+初始化
        void resize(size_t n, char ch = '\0') {
            // 当n小于_size的时候，不需要扩容，也不需要缩容
            // n大于_size的时候，并且当n>capacit的时候需要扩容，就直接调用reserve
            if (n < _size) {
                // 保留前n个
                _size = n;
                _str[_size] = '\0';
            } else {
                if (n > _capacity) {
                    reserve(n);
                }
                // 不大于则不需要设置_capacity
                // 从_size开始 到需要扩容n开始，初始化\0
                size_t i = _size;
                while (i < n) {
                    _str[i] = ch;
                    i++;
                }
                _size = n;
                // 将最后的下一个位置也设置为\0
                _str[_size] = '\0';
            }
        }

        void push_back(char ch) {
            if (_size + 1 > _capacity) {
                reserve(_capacity * 2);
            }
            _str[_size] = ch;
            _size++;
            _str[_size] = '\0';
        }

        // 尾插字符串
        void append(const char *str) {
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            strcpy(_str + _size, str);// 从_str+_size开始拷贝
            // strcat(_str, str);     //strcat会找\0，效率低下
            _size += len;
            _str[_size] = '\0';
        }

        string &operator+=(const char *str) {
            append(str);
            return *this;
        }

        string &operator+=(const char ch) {
            push_back(ch);
            return *this;
        }

        string &insert(size_t pos, char ch) {
            assert(pos <= _size);
            if (_size + 1 > _capacity) {
                reserve(_capacity * 2);
            }

            int end = _size;
            // 这里的pos需要改成int pos是无符号类型，和end对比，end会转换成无符号类型
            // 当pos的位置是0时，end为无符号类型将永远不会小于0，程序无限循环。
            // 需要将pos转换成int，那么end就为int类型
            while (end >= (int) pos) {
                _str[end + 1] = _str[end];
                end--;
            }
            _str[pos] = ch;
            _size++;

            return *this;
        }

        string &insert(size_t pos, const char *str) {
            assert(pos <= _size);
            int len = strlen(str);
            int end = _size + len;
            if (_size + len > _capacity) {
                reserve(_size + len);
            }

            while (end > pos + len - 1) {
                _str[end] = _str[end - len];
                end--;
            }
            strncpy(_str + pos, str, len);
            _size += len;
            return *this;
        }

        string &erase(size_t pos, size_t len = npos) {
            // 如果要删的个数远超于剩余的个数，就是pos位置后面全部删除，直接在pos位置后面置\0即可
            //  len == npos必须加上，npos是最大值
            if (len == npos || pos + len >= _size) {
                _str[pos] = '\0';
                _size = pos;
            } else {
                strcpy(_str + pos, _str + pos + len);// 删除pos+len位置的字符串
                _size -= len;
            }
            return *this;
        }

        void swap(string &s) {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }

        size_t find(char ch, size_t pos = 0) {
            assert(pos < _size);
            for (size_t i = 0; i < _size; i++) {
                if (_str[i] == ch) {
                    return i;
                }
            }
        }
        // 返回子串str在string中第一次出现的位置
        size_t find(const char *str, size_t pos = 0) {
            assert(pos < _size);
            // p是str出现在_str+pos出现的位置，返回的是指针
            char *p = strstr(_str + pos, str);
            if (p == nullptr) {
                return npos;
            } else {
                return p - _str;
            }
        }

        void clear() {
            _str[0] = '\0';
            _size = 0;
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity;// 真实容量要比_size多1，多一个\0
        // 静态成员变量不能给缺省值，但是加上const就可以了，只针对整型
        static const size_t npos = -1;

        // static const size_t N = 10;
        // int _a[N];
    };
    ostream &operator<<(ostream &out, const phw::string &s) {
        for (size_t i = 0; i < s.size(); i++) {
            out << s[i];
        }
        return out;
    }

    istream &operator>>(istream &in, phw::string &s) {
        s.clear();// 一开始就清理缓冲区
        char ch = in.get();
        char buff[128];
        size_t i = 0;
        while (ch != ' ' && ch != '\n') {
            // s += ch;  //字符串太长可能会容量不够,用reserve如何控制扩容？ 扩容会频繁调用
            buff[i++] = ch;
            if (i == 127) {
                buff[127] = '\0';
                s += buff;
                i = 0;
            }
            ch = in.get();
        }

        if (i != 0) {
            buff[i] = '\0';
            s += buff;
        }
        // getline实现
        /*while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}*/

        return in;
    }
}// namespace phw
