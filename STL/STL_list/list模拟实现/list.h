#pragma once
#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//list - 底层是一个双向带头循环链表
template<class T>
struct list_node
{
	list_node* next;
	list_node* prev;
	T data;  //模板T类型，适用任何类型
	//构造函数初始化列表
	//T()被用来初始化list_node类的data成员变量，以确保每个新创建的list_node对象都有一个合适的T类型的默认值。
	list_node(const T& x = T())   //T()用来给自定义类型调用默认构造函数来初始化x
		:next(nullptr), prev(nullptr), data(x)
	{}
};

//list迭代器
template<class T, class Ref, class Ptr>
struct list_iterator
{
	typedef list_node<T> node;  //链表
	typedef list_iterator<T, Ref, Ptr> iterator;   //迭代器
	node* _node;  //迭代器里唯一的成员变量:链表指针
	//迭代器默认构造函数，传的是迭代器链表指针
	list_iterator(node* n)
		:_node(n)
	{}

	//解引用 - 返回的是链表的值  Ref通过传参，T和const T 用来控制const类型和非const类型
	Ref& operator*()
	{
		return _node->data;
	}

	//-> 返回的是链表data的地址   Ptr通过传参，T和const T 用来控制const类型和非const类型
	Ptr operator->()
	{
		return &_node->data;
	}

	//前置++ 先++，在返回自己
	iterator& operator++()
	{
		_node = _node->next;
		return *this;
	}

	//后置++  先返回 在++
	iterator operator++(int)
	{
		iterator tmp = *this;  //注意：临时变量，不能引用返回
		_node = _node->next;
		return tmp;   //tmp是一个类，不是引用返回，返回的时候会创建一个临时类
	}

	//前置-- 先--，在返回自己
	iterator& operator--()
	{
		_node = _node->prev;
		return *this;
	}

	//后-- 在返回，在--
	iterator& operator--(int)
	{
		iterator tmp = *this;
		_node = _node->prev;
		return tmp;
	}

	//this->_node 不等于参数_node
	bool operator!=(const iterator& it)
	{
		return _node != it._node;
	}
};

//list类
template<class T>
class list
{
public:
	typedef list_node<T> node;   //链表
	typedef list_iterator<T, T&, T*> iterator;  //迭代器
	//const迭代器 通过const T& 传给Ref ，const T* 传给Ptr 
	typedef list_iterator<T, const T&, const T*> const_iterator;  //const迭代器 - 通过const迭代器访问的数据无法被修改
	//节点初始化
	void empty_init()
	{
		head = new node;
		head->next = head;
		head->prev = head;
	}
	//list默认构造函数
	list()
	{
		empty_init();
	}

	iterator begin()
	{
		return iterator(head->next);   //调用默认构造函数给node初始化
	}

	const_iterator begin() const
	{
		return const_iterator(head->next);
	}

	iterator end()
	{
		return iterator(head);
	}

	const_iterator end() const
	{
		return const_iterator(head);
	}

	void insert(iterator pos, const T& x)
	{
		//pos是一个类
		node* cur = pos._node;  //先取pos位置的节点地址
		node* prevnode = cur->prev;  //记录pos位置的前节点

		node* newnode = new node(x);
		prevnode->next = newnode;
		newnode->prev = prevnode;
		newnode->next = cur;
		cur->prev = newnode;
	}

	iterator erase(iterator pos)
	{
		if (pos != end())
		{
			//先记录前节点 后节点
			node* prevnode = pos._node->prev;
			node* nextnode = pos._node->next;

			prevnode->next = nextnode;
			nextnode->prev = prevnode;
			delete pos._node;
			// 返回下一个地址
			return iterator(next);
		}
		else
		{
			perror("erase fail");
			exit(-1);
		}
	}

	void push_back(const T& x)
	{
		node* tail = head->prev;  //尾结点就是头节点的前结点
		node* newnode = new node(x);
		//进行首尾连接
		tail->next = newnode;
		newnode->prev = tail;
		newnode->next = head;
		head->prev = newnode;
	}

	/*void pop_back()
	{

	}*/
private:
	node* head;  //头节点 - list只有一个数据成员，头节点
};