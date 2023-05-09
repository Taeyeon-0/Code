#pragma once

#include"BSTree.h"
namespace phw
{
	template<class K>
	class set
	{
		//用于比较方式
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}
