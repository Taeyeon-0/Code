#pragma once
#include<assert.h>
//list  带头双向循环链表
template<class T>
struct list_node
{
	list_node<T>* _next;
	list_node<T>* _prev;
	T _data;
	//构造函数初始化列表
	list_node(const T& x = T())  //T()默认构造函数用来初始化x
		:_next(nullptr)
		, _prev(nullptr)
		, _data(x)
	{}
};

//list迭代器
template<class T, class Ref, class Ptr >
struct _list_iterator
{
	typedef list_node<T> node;
	typedef _list_iterator<T, Ref, Ptr> iterator;
	node* _node;   //迭代器里唯一的成员变量
	//迭代器构造函数
	_list_iterator(node* n)
		:_node(n)
	{}

	//重载解引用
	Ref operator*()
	{
		return _node->_data;
	}

	//重载->
	Ptr operator->()
	{
		return &_node->_data;  //->  是取地址
	}

	//前置++  返回自己
	iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//后置++  返回自己
	iterator& operator++(int)
	{
		iterator tmp = *this;
		_node = _node->_next;
		return tmp;
	}

	iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	iterator& operator--(int)
	{
		iterator tmp = *this;
		_node = _node->_prev;
		return tmp;
	}

	bool operator != (const iterator& s)
	{
		return _node != s._node;
	}
};

//const_list迭代器
//template<class T>
//struct _list_const_iterator
//{
//	typedef list_node<T> node;
//	typedef _list_const_iterator<T> iterator;
//	node* _node;   //迭代器里唯一的成员变量
//	//迭代器构造函数
//	_list_const_iterator(node* n)
//		:_node(n)
//	{}
//
//	//重载解引用- 返回const就不能修改了
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//
//	//前置++  返回自己
//	iterator& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//
//	//后置++  返回自己
//	iterator& operator++(int)
//	{
//		iterator tmp = *this;
//		_node = _node->_next;
//		return tmp;
//	}
//
//	bool operator != (const iterator& s)
//	{
//		return _node != s._node;
//	}
//};

template<class T>
class list
{
	typedef list_node<T> node;
public:
	//重命名迭代器
	typedef _list_iterator<T, T&, T*> iterator;
	typedef _list_iterator<T, const T&, const T*> const_iterator;
	//typedef _list_const_iterator<T> const_iterator;
	list()
	{
		_head = new node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	iterator begin()
	{
		//iterator it(_head->_next);
		//return it;
		//返回迭代器类，然后迭代器里的node 用_head->_next初始化
		return iterator(_head->_next);
	}

	const_iterator begin() const  //const修饰的函数，无法改变成员变量
	{
		return const_iterator(_head->_next);   //指针不能改变，但可以赋值给别人
	}

	iterator end()
	{
		//双向带头循环判尾是头节点head
		return iterator(_head);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}


	void push_back(const T& x)
	{
		/*node* tail = _head->_prev;
		node* new_node = new node(x);

		tail->_next = new_node;
		new_node->_prev = tail;
		new_node->_next = _head;
		_head->_prev = new_node;*/
		//复用
		insert(end(), x);
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}

	//pos迭代器不会失效，插入后，pos位置永远不会变，地址不变
	void insert(iterator pos, const T& x)
	{
		//pos是一个类
		node* cur = pos._node;
		node* prev = cur->_prev;

		node* new_node = new node(x);
		prev->_next = new_node;
		new_node->_prev = prev;
		new_node->_next = cur;
		cur->_prev = new_node;
	}
	
	void pop_back()
	{
		erase(--end());
	}

	void pop_front()
	{
		erase(begin());
	}

	void erase(iterator pos)
	{
		assert(pos != end());
		node* prev = pos._node->_prev;
		node* next = pos._node->_next;

		prev->_next = next;
		next->_prev = prev;
		delete pos._node;
	}
private:
	node* _head;  //头节点
};

