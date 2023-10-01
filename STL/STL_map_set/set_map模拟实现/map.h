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
        typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::reverse_iterator reverse_iterator;//反向迭代器

        iterator begin() {
            return _t.begin();
        }

        iterator end() {
            return _t.end();
        }

        reverse_iterator rbegin() {
            return _t.rbegin();
        }

        reverse_iterator rend() {
            return _t.rend();
        }

        V &operator[](const K &key) {
            pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
            return ret.first->second;//first是迭代器
        }

        pair<iterator, bool> Insert(const pair<const K, V> &kv) {

            return _t.Insert(kv);
        }
        //删除函数
        void erase(const K &key) {
            _t.Erase(key);
        }
        //查找函数
        iterator find(const K &key) {
            return _t.Find(key);
        }

        void InOrder() {
            _t.InOrder();
        }

    private:
        RBTree<K, pair<const K, V>, MapKeyOfT> _t;//const K 控制k不可修改 传给模板T
    };
}// namespace phw
