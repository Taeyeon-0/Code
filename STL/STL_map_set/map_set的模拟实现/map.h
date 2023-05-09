#pragma once

#include"BSTree.h"

namespace phw
{
	template<class K, class V>
	class map
	{
		//用于比较方式
		struct MapKeyOfT
		{
			const pair<const K, V>& operator()(const pair<const K, V>& key)
			{
				return key;
			}
		};

	public:
		bool insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}


	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}

