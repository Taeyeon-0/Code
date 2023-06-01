#pragma once

#include "HashTable.h"
template<class K, class V, class Hash = HashFunc<K>>
class unordered_map {
public:
	struct MapKeyOft {
		const K& operator()(const pair<K, V>& kv) {
			return kv.first;
		}
	};

	//typename 告诉编译器引入的是一个类型，而不是成员
	typedef typename HashTable<K, pair<const K, V>, MapKeyOft, Hash>::iterator iterator;
	typedef typename HashTable<K, pair<const K, V>, MapKeyOft, Hash>::const_iterator const_iterator;

	iterator begin() {
		return _ht.begin();
	}

	iterator end() {
		return _ht.end();
	}

	const_iterator begin() const {
		return _ht.begin();
	}

	const_iterator end() const {
		return _ht.end();
	}

	pair<iterator, bool> insert(const pair<K, V> kv) {
		return _ht.Insert(kv);
	}

	V& operator[](const K& key) {
		pair<iterator, bool> ret = insert(make_pair(key, V()));
		return ret.first->second;
	}

	iterator find(const K& key)
	{
		return _ht.Find(key);
	}

	bool erase(const K& key)
	{
		return _ht.Erase(key);
	}
private:
	HashTable<K, pair<const K, V>, MapKeyOft, Hash> _ht;
};
