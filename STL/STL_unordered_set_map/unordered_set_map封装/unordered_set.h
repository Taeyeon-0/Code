#pragma once
#include "HashTable.h"


template<class K>
class unordered_set {
public:
    struct SetKeyOft {
        const K& operator()(const K& key) {
            return key;
        }
    };
public:
    typedef typename HashTable<K, K, SetKeyOft>::iterator iterator;

    bool insert(const K& key) {
        return _ht.Insert(key);
    }

    iterator begin() {
        return _ht.begin();
    }

    iterator end() {
        return _ht.end();
    }

private:
    HashTable<K, K, SetKeyOft> _ht;
};
