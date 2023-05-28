#pragma once

#include "HashTable.h"

namespace phw {
    template<class K, class V>
    class unordered_map {
    public:
        struct MapKeyOft {
            const K &operator()(const pair(K, V) & kv) { return; }
        };

        bool Insert(const K &key) { return _ht.Insert(key); }

    private:
        HashTable<K, K, MapKeyOft> _ht;
    };
};// namespace phw
