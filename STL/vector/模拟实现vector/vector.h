#pragma once
#include<string.h>
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class vector
{
public:
	typedef	T* iterator;   //iterator为T类型的指针
	typedef	const T* const_iterator;   //iterator为T类型的指针
	vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _end_of_storage(nullptr)
	{}


	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	//这里必须加上const，两个begin函数，只是参数返回类型不同
	//编译器无法根据函数返回类型来区分函数，
	//因为函数重载不允许仅仅因为返回类型不同而进行区分。这将导致编译错误。
	//加入const修饰符，以便编译器可以正确地区分这两个函数
	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	void reserve(size_t n)
	{
		//n>capacity才需要扩容,否则n<capacity可能会缩容
		if (n > capacity())
		{
			size_t sz = size();  //提前记录sz大小
			T* tmp = new T[n];

			if (_start)
			{
				//将_start的内存，复制到tmp中
				memcpy(tmp, _start, sizeof(T) * size());
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + sz;   //size() _finish - _start  
			//这里start更新了，而finish没有更新 start就是tmp   _start + _finish - _start  还是原来的_finish，finish为0，就会造成空指针解引用
			//所以需要提前记录sz的大小,并且这里也处理了_finish一开始等于空的情况
			_end_of_storage = _start + n;   //这里不能光写n  _end_of_storage是指针
		}

	}

	void resize(size_t n,T val = T())  //T()默认构造，匿名对象，对于自定义类型，和内置类型比如int都会初始化
	{
		if (n < size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > capacity())
			{
				reserve(n);
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
		}
	}

	void push_back(const T& x)
	{

		if (_finish == _end_of_storage)
		{
			//扩容  一种是一开始都为NULL，另一种是需要扩容
			reserve(capacity() == 0 ? 4 : capacity() * 2);
		}

		*_finish = x; //可能发生空指针解引用
		_finish++;

	}

	void pop_back()
	{
		//当不为空才-- _finish
		if (!empty())
			_finish--;
	}

	void insert(iterator pos, const T& val)
	{
		assert(pos >= _start);
		assert(pos <= _finish);
		
		if (_finish == _end_of_storage)
		{
			//迭代器失效问题！
			//reserve扩容，会释放掉旧空间，那么pos位置也会被释放，需要更新pos，解决pos失效的问题
			//那么pos的位置怎么算呢，相对位置！ 算出pos之前的相对_start的相对位置
			size_t len = pos - _start;
			reserve(capacity() == 0 ? 4 : capacity() * 2);
			//更新pos,_start + len( 没被释放前的相对位置)
			pos = _start + len;
		}

		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end+1) = *end;
			end--;
		}
		*pos = val;
		_finish++;
	}

	void erase(iterator pos)
	{
		assert(pos >= _start);
		assert(pos < _finish);
		iterator start = pos + 1;
		while (start != _finish)
		{
			*(start - 1) = *(start);
			++start;
		}
		_finish--;
	}
	

	bool empty()
	{
		return _start == _finish;
	}

	size_t capacity()  const
	{
		return _end_of_storage - _start;
	}

	size_t size() const
	{
		return _finish - _start;
	}

	T& operator[](size_t pos) const
	{
		return _start[pos];
	}

	const T& operator[](size_t pos)
	{
		return _start[pos];
	}

private:
	iterator _start;
	iterator _finish;
	iterator _end_of_storage;

};