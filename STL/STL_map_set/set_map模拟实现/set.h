#include"RBTree.h"
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
		//typename告诉编译器iterator是一个类型，而不是一个成员变量
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator,bool> Insert(const K& key)
		{
			return _t.Insert(key);
		}

		void InOrder()
		{
			//_t.InOrder();
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;   //封装的红黑树 ，第二个K是没用的，为的是匹配map
	};
}
