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
			const K& operator()(const pair<const K, V>& key)
			{
				return key.first;
			}
		};

	public:
		bool Insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

		void InOrder()
		{
			_t.InOrder();
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}

