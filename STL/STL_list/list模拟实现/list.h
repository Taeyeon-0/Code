#pragma once
// list - 底层是一个双向带头循环链表
template <class T>
struct list_node
{
	list_node* next;
	list_node* prev;
	T data; // 模板T类型，适用任何类型
	// 构造函数初始化列表
	// T()被用来初始化list_node类的data成员变量，以确保每个新创建的list_node对象都有一个合适的T类型的默认值。
	list_node(const T& x = T()) // T()用来给自定义类型调用默认构造函数来初始化x
		: next(nullptr), prev(nullptr), data(x)
	{
	}
};

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

// 反向迭代器
template <class T, class Ref, class Ptr>
struct list_reverse_iterator
{
	typedef list_node<T> node;					 // 链表
	typedef list_reverse_iterator<T, Ref, Ptr> reverse_iterator; // 迭代器
	node* _node;								 // 迭代器里唯一的成员变量:链表指针
	// 迭代器默认构造函数，传的是迭代器链表指针
	list_reverse_iterator(node* n)
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
	reverse_iterator& operator++()
	{
		_node = _node->prev;
		return *this;
	}

	// 后置++  先返回 在++
	reverse_iterator operator++(int)
	{
		reverse_iterator tmp = *this; // 注意：临时变量，不能引用返回
		_node = _node->prev;
		return tmp; // tmp是一个类，不是引用返回，返回的时候会创建一个临时类
	}

	// 前置-- 先--，在返回自己
	reverse_iterator& operator--()
	{
		_node = _node->next;
		return *this;
	}

	// 后-- 在返回，在--
	reverse_iterator operator--(int)
	{
		reverse_iterator tmp = *this;
		_node = _node->next;
		return tmp;
	}

	// pos地址++
	reverse_iterator& operator+(int x)
	{
		while (x--)
		{
			//*this表示迭代器里的指针，++复用前面的重载，表示指针++
			*this = -- * this;
		}
		return *this;
	}

	reverse_iterator& operator-(int x)
	{
		while (x--)
		{
			*this = ++ * this;
		}
		return *this;
	}

	// this->_node 不等于参数_node
	bool operator!=(const reverse_iterator& it)
	{
		return _node != it._node;
	}
};

// list类
template <class T>
class list
{
public:
	typedef list_node<T> node;					 // 链表
	typedef list_iterator<T, T&, T*> iterator; // 迭代器
	// const迭代器 通过const T& 传给Ref ，const T* 传给Ptr
	typedef list_iterator<T, const T&, const T*> const_iterator; // const迭代器 - 通过const迭代器访问的数据无法被修改
	typedef list_reverse_iterator<T, T&, T*> reverse_iterator;
	// 节点初始化
	void empty_init()
	{
		head = new node;
		head->next = head;
		head->prev = head;
	}
	// list默认构造函数
	list()
	{
		empty_init();
	}

	// 利用迭代器构造函数
	template <class iterator>
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
			push_back(e);  //将lt的元素复制到现在的list中
		}
	}
	*/

	void swap(list<T>& tmp)
	{
		std::swap(head, tmp.head);  //交换头指针
	}

	// 拷贝构造-现代方法
	list(const list<T>& lt)
	{
		empty_init(); // 必须有，不然)_head就是空指针
		list<T> tmp(lt.begin(), lt.end());  //由lt的迭代器，构造出一个tmp
		swap(tmp);   //交换tmp和this->head的指针
	}

	// 赋值 lt1 = lt3                这里lt就是lt3的拷贝，lt1是this
	list<T>& operator=(list<T> lt)
	{
		swap(lt);	  // 交换 lt和this交换
		return *this; // 返回自己就是返回lt，赋值给别的对象
	}

	// 迭代器通常建议将迭代器作为值传递，而不是作为引用传递。引用会导致迭代器失效
	iterator begin()
	{
		return iterator(head->next); // 调用默认构造函数给node初始化
	}

	const_iterator begin() const  // const修饰的函数，无法改变成员变量
	{
		return const_iterator(head->next);  // 指针不能改变，但可以赋值给别人
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(head->prev);  //rbegin 是最后一个数
	}

	reverse_iterator rend()
	{
		return reverse_iterator(head); //rend是头指针
	}

	iterator end()
	{
		// 双向带头循环判尾是头节点head
		return iterator(head);
	}

	const_iterator end() const
	{
		return const_iterator(head);
	}

	// pos迭代器不会失效，插入后，pos位置永远不会变，地址不变
	void insert(iterator pos, const T& x)
	{
		// pos是一个类
		node* cur = pos._node;		// 先取pos位置的节点地址
		node* prevnode = cur->prev; // 记录pos位置的前节点

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
			// 先记录前节点 后节点
			node* prevnode = pos._node->prev;
			node* nextnode = pos._node->next;

			prevnode->next = nextnode;
			nextnode->prev = prevnode;
			delete pos._node;
			// 返回下一个地址
			return iterator(nextnode); 
		}
		else
		{
			perror("erase fail");
			exit(-1);
		}
	}

	void push_back(const T& x)
	{
		insert(end(), x); // 复用
	}

	void pop_back()
	{
		erase(end()--); // end()是头指针，头指针的prev是尾节点
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}

	void pop_front()
	{
		erase(begin());
	}

	void clear()
	{
		// 清理内存 - 不清理头节点
		iterator it = begin();
		while (it != end())
		{
			erase(it);
			it++;
		}
	}

	~list()
	{
		clear();
		delete head;
		head = nullptr;
	}

private:
	node* head; // 头节点 - list只有一个数据成员，头节点
};