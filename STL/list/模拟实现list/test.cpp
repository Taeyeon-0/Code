#include"list.h"
#include<iostream>
using namespace std;
void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();  //需要在类中重载一个const函数
	while (it != lt.end())
	{
		//(*it) *= 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();  //调用拷贝构造，默认的浅拷贝，这里浅拷贝没有问题
	//浅拷贝，为什么没报错，因为迭代器没有写析构函数
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	print_list(lt);
}

struct AA
{
	int _a1;
	int _a2;

	AA(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{}
};

void test2()
{
	list<AA> lt;
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 2));
	lt.push_back(AA(3, 3));

	list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//cout << (*it)._a1 << " " << (*it)._a2 << " ";
		//模拟箭头->
		cout << it->_a1 << " " << it->_a2 << " ";

		++it;
	}
}

void test3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator pos = lt.begin();
	++pos;
	lt.insert(pos, 20);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.push_back(100);
	lt.push_front(1000);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();
	lt.pop_front();
	for (auto e : lt)
	{
		cout << e << " ";
	}
}

void test4()
{
	//const在定义的时候是没有const的属性的，不然在定义的时候就无法初始化了
	const list<int> lt1;

	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_back(100);
	lt.push_front(1000);
	//lt.clear();
	for (auto e : lt)
	{
		cout << e << " ";
	}
}

//拷贝构造
void test5()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt2(lt);

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>lt3;
	lt3 = lt;
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test5();
	return 0;
}