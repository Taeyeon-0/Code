#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
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
		empty_init();
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

	iterator erase(iterator pos)
	{
		assert(pos != end());
		node* prev = pos._node->_prev;
		node* next = pos._node->_next;

		prev->_next = next;
		next->_prev = prev;
		delete pos._node;
		//返回下一个地址
		return iterator(next);
	}

	void empty_init()
	{
		_head = new node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	//利用迭代器构造函数
	template<class iterator>
	list(iterator first, iterator last)
	{
		empty_init();
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

	//拷贝构造  lt2(lt1)  老方法
	/*
	list(const list<T>& lt)
	{
		empty_init();
		for (auto e : lt)
		{
			push_back(e);
		}
	}
	*/

	void swap(list<T>& tmp)
	{
		std::swap(_head, tmp._head);
	}

	//拷贝构造-现代方法
	list(const list<T>& lt)
	{
		empty_init();  //必须有，不然)_head就是空指针
		list<T> tmp(lt.begin(), lt.end());
		swap(tmp);
	}

	//赋值 lt1 = lt3                这里lt就是lt3的拷贝，lt1是this
	list<T>& operator=(list<T> lt)
	{
		swap(lt);    //交换
		return *this;  //返回自己就是返回lt3
	}

	~list()
	{
		clear();
		delete _head;
		_head = nullptr;
	}

	void clear()
	{
		//清理内存 - 不清理头节点
		iterator it = begin();
		while (it != end())
		{
			it = erase(it);  //erase返回下一个地址迭代器
			//erase(it++);  //也可以
		}
	}
private:
	node* _head;  //头节点
};

