#pragma once
template <class T>
struct list_node;   //声明外部类，
// list迭代器
template <class T, class Ref, class Ptr>
struct list_iterator
{
	typedef list_node<T> node;					 // 链表
	typedef list_iterator<T, Ref, Ptr> iterator; // 迭代器
	node* _node;								 // 迭代器里唯一的成员变量:链表指针
	// 迭代器默认构造函数，传的是迭代器链表指针
	list_iterator(node* n)
		: _node(n)
	{
	}

	// 解引用 - 返回的是链表的值  Ref通过传参，T和const T 用来控制const类型和非const类型
	Ref operator*()
	{
		return _node->data;
	}

	//-> 返回的是链表data的地址   Ptr通过传参，T和const T 用来控制const类型和非const类型
	Ptr operator->()
	{
		return &_node->data;
	}

	// 前置++ 先++，在返回自己
	iterator& operator++()
	{
		_node = _node->next;
		return *this;
	}

	// 后置++  先返回 在++
	iterator operator++(int)
	{
		iterator tmp = *this; // 注意：临时变量，不能引用返回
		_node = _node->next;
		return tmp; // tmp是一个类，不是引用返回，返回的时候会创建一个临时类
	}

	// 前置-- 先--，在返回自己
	iterator& operator--()
	{
		_node = _node->prev;
		return *this;
	}

	// 后-- 在返回，在--
	iterator operator--(int)
	{
		iterator tmp = *this;
		_node = _node->prev;
		return tmp;
	}

	// pos地址++
	iterator& operator+(int x)
	{
		while (x--)
		{
			//*this表示迭代器里的指针，++复用前面的重载，表示指针++
			*this = ++ * this;
		}
		return *this;
	}

	iterator& operator-(int x)
	{
		while (x--)
		{
			*this = -- * this;
		}
		return *this;
	}

	// this->_node 不等于参数_node
	bool operator!=(const iterator& it)
	{
		return _node != it._node;
	}
};

//反向迭代器
template<class iterator,class Ref,class Ptr>
struct STL_reverse_iterator
{	
	iterator cur;  //正向迭代器
	typedef STL_reverse_iterator<iterator, Ref, Ptr> reverse_iterator;
	STL_reverse_iterator(iterator it)
		:cur(it)
	{}

	Ref operator*()
	{
		return *cur;  //对正向迭代器解引用，就是返回node->data 
	}

	reverse_iterator operator++()
	{
		--cur;
		return *this;  
	}

	reverse_iterator operator--()
	{
		++cur;
		return *this;
	}

	bool operator!=(const reverse_iterator& s)
	{
		return cur != s.cur;
	}
};

// 反向迭代器  - 不推荐
//template <class T, class Ref, class Ptr>
//struct list_reverse_iterator
//{
//	typedef list_node<T> node;					 // 链表
//	typedef list_reverse_iterator<T, Ref, Ptr> reverse_iterator; // 迭代器
//	node* _node;								 // 迭代器里唯一的成员变量:链表指针
//	// 迭代器默认构造函数，传的是迭代器链表指针
//	list_reverse_iterator(node* n)
//		: _node(n)
//	{
//	}
//
//	// 解引用 - 返回的是链表的值  Ref通过传参，T和const T 用来控制const类型和非const类型
//	Ref operator*()
//	{
//		return _node->data;
//	}
//
//	//-> 返回的是链表data的地址   Ptr通过传参，T和const T 用来控制const类型和非const类型
//	Ptr operator->()
//	{
//		return &_node->data;
//	}
//
//	// 前置++ 先++，在返回自己
//	reverse_iterator& operator++()
//	{
//		_node = _node->prev;
//		return *this;
//	}
//
//	// 后置++  先返回 在++
//	reverse_iterator operator++(int)
//	{
//		reverse_iterator tmp = *this; // 注意：临时变量，不能引用返回
//		_node = _node->prev;
//		return tmp; // tmp是一个类，不是引用返回，返回的时候会创建一个临时类
//	}
//
//	// 前置-- 先--，在返回自己
//	reverse_iterator& operator--()
//	{
//		_node = _node->next;
//		return *this;
//	}
//
//	// 后-- 在返回，在--
//	reverse_iterator operator--(int)
//	{
//		reverse_iterator tmp = *this;
//		_node = _node->next;
//		return tmp;
//	}
//
//	// pos地址++
//	reverse_iterator& operator+(int x)
//	{
//		while (x--)
//		{
//			//*this表示迭代器里的指针，++复用前面的重载，表示指针++
//			*this = -- * this;
//		}
//		return *this;
//	}
//
//	reverse_iterator& operator-(int x)
//	{
//		while (x--)
//		{
//			*this = ++ * this;
//		}
//		return *this;
//	}
//
//	// this->_node 不等于参数_node
//	bool operator!=(const reverse_iterator& it)
//	{
//		return _node != it._node;
//	}
//};