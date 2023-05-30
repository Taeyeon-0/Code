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

    typedef typename HashTable<K, pair<const K, V>, MapKeyOft>::iterator iterator;

    bool insert(const pair<K, V> kv) {
        return _ht.Insert(kv);
    }

    iterator begin() {
        return _ht.begin();
    }

    iterator end() {
        return _ht.end();
    }

private:
    HashTable<K, pair<const K, V>, MapKeyOft> _ht;
};