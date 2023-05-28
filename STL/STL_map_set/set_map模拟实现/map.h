#pragma once
#include "RBTree.h"


namespace phw {
    template<class K, class V>
    class map {
        //用于比较方式
        struct MapKeyOfT {
            const K &operator()(const pair<const K, V> &key) {
                return key.first;
            }
        };

    public:
        typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;

        iterator begin() {
            return _t.begin();
        }

        iterator end() {
            return _t.end();
        }

        V &operator[](const K &key) {
            pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
            return ret.first->second;//first是迭代器
        }

        pair<iterator, bool> Insert(const pair<const K, V> &kv) {

            return _t.Insert(kv);
        }

        void InOrder() {
            //_t.InOrder();
        }

    private:
        RBTree<K, pair<const K, V>, MapKeyOfT> _t;//const K 控制k不可修改 传给模板T
    };
}// namespace phw
