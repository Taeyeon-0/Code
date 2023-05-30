#pragma once

#include "HashTable.h"
template<class K, class V>
class unordered_map {
public:
    struct MapKeyOft {
        const K& operator()(const pair<K, V>& kv) {
            return kv.first;
        }
    };

    bool insert(const pair<K, V> kv) {
        return _ht.Insert(kv);
    }

private:
    HashTable<K, pair<const K, V>, MapKeyOft> _ht;
};
