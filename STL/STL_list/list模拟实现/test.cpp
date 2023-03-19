#include"list.h"

void test1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	list<int>::iterator it = lt.begin();  //调用拷贝构造，默认的浅拷贝，这里浅拷贝没有问题,因为没有迭代器没有析构
	while (it != lt.end())
	{
		cout << *it << " ";  //1 2 3 4
		it++;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";  //1 2 3 4
	}
	cout << endl;
}


void test2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);  //#include<algorithm>
	lt.insert(pos, 666);

	for (auto e : lt)
	{
		cout << e << " ";  // 1 2 666 3 4
	}
	cout << endl;
}

int main()
{
	test2();
	return 0;
}