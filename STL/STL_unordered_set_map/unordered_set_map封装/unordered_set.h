#pragma once
#include "HashTable.h"

namespace phw {
    template<class K>
    class unordered_set {
    public:
        struct SetKeyOft {
            const K &operator()(const K &key) { return key; }
        };

        bool Insert(const K &key) { return _ht.Insert(key); }

    private:
        HashTable<K, K, SetKeyOft> _ht;
    };
};// namespace phw
