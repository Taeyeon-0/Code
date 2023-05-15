#include "list.h"


void print_list(const list<int>& lt)
{
	//打印函数，一般不需要改变值，那么我们就需要使用const迭代器
	list<int>::const_iterator it = lt.begin(); // 需要在类中重载一个const函数
	while (it != lt.end())
	{
		//(*it) *= 2;  //这里const begin函数，无法修改
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
	list<int>::iterator it = lt.begin(); // 调用拷贝构造，默认的浅拷贝，
	//这里浅拷贝没有问题,因为迭代器没有析构
	while (it != lt.end())
	{
		cout << *it << " "; // 1 2 3 4
		it++;
	}
	cout << endl;
	it = lt.begin();
	for (auto e : lt)
	{
		cout << e << " "; // 1 2 3 4
	}
	cout << endl;

	//print_list(lt);  //1 2 3 4
}

void test2()
{
	// const在定义的时候是没有const的属性的，不然在定义的时候就无法初始化了
	const list<int> lt1;
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	// list<int>::iterator pos = find(lt.begin(), lt.end(), 3);  //#include<algorithm>,这里库里的可以实现查找
	list<int>::iterator pos = lt.begin();

	lt.insert(pos + 2 - 2, 666);

	for (auto e : lt)
	{
		cout << e << " "; // 666 1 2 3 4
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

struct AA
{
	int _a1;
	int _a2;

	AA(int a1 = 0, int a2 = 0)
		: _a1(a1), _a2(a2)
	{
	}
};

//自定义类型的list  ->模拟 

void test3()
{
	list<AA> lt;   //list里node的data是自定义类型  T data
	lt.push_back(AA(1, 1));
	lt.push_back(AA(2, 2));
	lt.push_back(AA(3, 3));

	list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		//cout << (*it)._a1 << " " << (*it)._a2 << endl;  //*it = _node->data   ._a1 = AA data.a1
		cout << it->_a1 << " " << it->_a2 << endl;     //it返回的是&_node->data  对data地址-> 就是data.a1	
		it++;
	}

}

//拷贝构造
void test4()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;

	list<int> lt2(lt);

	for (auto e : lt2)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;

	list<int> lt3;
	lt3 = lt;
	for (auto e : lt3)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;
}

//反向迭代器
void test5()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";   //5 4 3 2 1 
		++rit;
	}
	cout << endl;

}
int main()
{
	test5();
	return 0;
}