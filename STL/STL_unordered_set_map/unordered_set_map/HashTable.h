#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template<class K>
struct HashFunc {
    size_t operator()(const K &key) {
        return key;
    }
};

// 特化模板，传string的话，就走这个
template<>
struct HashFunc<string> {
    size_t operator()(const string &s) {
        size_t hash = 0;
        for (auto ch: s) {
            hash += ch;
            hash *= 31;
        }
        return hash;
    }
};

template<class T>
struct HashNode {
    HashNode<T> *_next;
    T _data;

    HashNode(const T &data)
        : _data(data), _next(nullptr) {}
};


//前置声明
template<class K, class T, class KeyOft, class Hash = HashFunc<K>>
class HashTable;

template<class K, class T, class Ref, class Ptr, class KeyOft, class Hash>
struct HashIterator {
    typedef HashNode<T> Node;
    typedef HashTable<K, T, KeyOft, Hash> HT;
    //Ref和Ptr可能是T&和T*，也可能是const T&/const T*，需要创建一个支持普通转换为const的迭代器
    typedef HashIterator<K, T, Ref, Ptr, KeyOft, Hash> Self;
    typedef HashIterator<K, T, T &, T *, KeyOft, Hash> iterator;//增加一个支持const的迭代器

    HashIterator(Node *node, HT *ht)
        : _node(node), _ht(ht) {}

    //支持迭代器
    HashIterator(const iterator &it)
        : _node(it._node), _ht(it._ht) {}

    Ref operator*() {
        return _node->_data;
    }

    Ptr operator->() {
        return &_node->_data;
    }

    bool operator!=(const Self &s) {
        return _node != s._node;
    }

    bool operator==(const Self &s) {
        return _node == s._node;
    }

    Self &operator++() {
        if (_node->_next != nullptr) {
            _node = _node->_next;
        } else {
            //找下一个不为空的桶
            KeyOft kot;
            Hash hash;
            // 算出我当前的桶位置
            size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
            ++hashi;
            while (hashi < _ht->_tables.size()) {
                if (_ht->_tables[hashi] != nullptr) {
                    _node = _ht->_tables[hashi];
                    break;
                } else {
                    ++hashi;
                }
            }

            //没有找到的话，返回_node为空
            if (hashi == _ht->_tables.size()) {
                _node = nullptr;
            }
            return *this;
        }
        return *this;
    }
    Node *_node;//迭代器指针
    HT *_ht;    //哈希表，用于定位下一个桶
};

template<class K, class T, class KeyOft, class Hash>// Hash用于将key转换成可以取模的类型
class HashTable {
public:
    typedef HashNode<T> Node;
    typedef HashIterator<K, T, T &, T *, KeyOft, Hash> iterator;
    typedef HashIterator<K, T, const T &, const T *, KeyOft, Hash> const_iterator;

    template<class K1, class T1, class Ref1, class Ptr1, class KeyOft1, class Hash1>
    friend struct HashIterator;//用于迭代器访问HashTable中的private成员变量，即_tables


public:
    ~HashTable() {
        for (auto &cur: this->_tables) {
            while (cur) {
                Node *next = cur->_next;
                delete cur;
                cur = next;
            }
            cur = nullptr;
        }
    }

    iterator begin() {
        Node *cur = nullptr;
        for (size_t i = 0; i < _tables.size(); i++) {
            cur = _tables[i];
            if (cur != nullptr) {
                break;
            }
        }
        return iterator(cur, this);
    }

    iterator end() {
        return iterator(nullptr, this);
    }

    const_iterator begin() const {
        Node *cur = nullptr;
        for (size_t i = 0; i < _tables.size(); i++) {
            cur = _tables[i];
            if (cur != nullptr) {
                break;
            }
        }
        return const_iterator(cur, this);
    }

    const_iterator end() const {
        return const_iterator(nullptr, this);
    }

    //查找Key也是K类型
    iterator Find(const K &key) {
        if (this->_tables.size() == 0) {
            return iterator(nullptr, this);
        }

        KeyOft kot;//模板参数，用来区分是kv，还是v由上层map、set传模板参数过来(通过仿函数实现)
        Hash hash;
        size_t hashi = hash(key) % this->_tables.size();
        Node *cur = this->_tables[hashi];
        while (cur) {
            if (kot(cur->_data) == key) {
                return iterator(cur, this);
            }
            cur = cur->_next;
        }
        return iterator(nullptr, this);
    }

    //删除的值key为K类型
    bool Erase(const K &key) {
        Hash hash;
        KeyOft kot;
        size_t hashi = hash(key) % this->_tables.size();
        Node *prev = nullptr;
        Node *cur = this->_tables[hashi];
        while (cur) {
            if (kot(cur->_data) == key) {
                if (prev == nullptr) {
                    this->_tables[hashi] = cur->_next;
                } else {
                    prev->_next = cur->_next;
                }
                delete cur;
                return true;
            } else {
                prev = cur;
                cur = cur->_next;
            }
        }
        return false;
    }

    // 扩容优化，使用素数扩容
    size_t GetNextPrime(size_t prime) {
        // SGI
        static const int _stl_num_primes = 28;
        static const uint64_t _stl_prime_list[_stl_num_primes] = {
                53, 97, 193, 389, 769, 1543,
                3079, 6151, 12289, 24593, 49157, 98317,
                196613, 393241, 786433, 1572869, 3145739, 6291469,
                12582917, 25165843, 50331653, 100663319, 201326611, 402653189,
                805306457, 1610612741, 3221225473, 4294967291};

        size_t i = 0;
        for (; i < _stl_num_primes; ++i) {
            if (_stl_prime_list[i] > prime)
                return _stl_prime_list[i];
        }

        return _stl_prime_list[_stl_num_primes - 1];
    }

    //插入的类型是T类型，可能是K可能是pair<K,V> 通过模板参数传过来
    pair<iterator, bool> Insert(const T &data) {
        Hash hash;// 仿函数用于不能取模的值
        KeyOft kot;
        // 已经有这个数，就不用插入了
        iterator it = Find(kot(data));
        //如果it不是end()，说明找到了数，就不用插入，返回迭代器和false
        if (it != end()) {
            return make_pair(it, false);
        }


        // 负载因子 == 1时扩容
        if (this->n == this->_tables.size()) {
            // size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
            size_t newsize = this->GetNextPrime(_tables.size());
            vector<Node *> newtables(newsize, nullptr);
            for (auto &cur: this->_tables) {// cur是Node*
                while (cur) {
                    // 保存下一个
                    Node *next = cur->_next;
                    // 头插到新表
                    size_t hashi = hash(kot(cur->_data)) % newtables.size();
                    cur->_next = newtables[hashi];
                    newtables[hashi] = cur;

                    cur = next;
                }
            }
            _tables.swap(newtables);
        }

        size_t hashi = hash(kot(data)) % this->_tables.size();
        // 头插
        Node *newnode = new Node(data);
        newnode->_next = _tables[hashi];
        _tables[hashi] = newnode;
        this->n++;

        //插入成功返回，通过newnode，和this构造迭代器，返回true。
        return make_pair(iterator(newnode, this), true);
    }

    // 获取哈希表索引最大长度(哈希桶长度)
    size_t MaxBucketSize() {
        size_t max = 0;
        for (int i = 0; i < _tables.size(); ++i) {
            auto cur = _tables[i];
            size_t size = 0;
            while (cur) {
                ++size;
                cur = cur->_next;
            }

            printf("[%d]->%d\n", i, size);

            if (size > max) {
                max = size;
            }
            if (max == 5121) {
                printf("%d", i);
                break;
            }
        }

        return max;
    }

private:
    vector<Node *> _tables;
    size_t n = 0;// 存储有效数据的个数
};