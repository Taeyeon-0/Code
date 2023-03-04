#include"vector.h"
void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";  //1 2 3 4 5
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";  //1 2 3 4 5
		it++;
	}
	cout << endl;

	for (auto e : v1)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;

	v1.pop_back();
	v1.pop_back();
	for (auto e : v1)
	{
		cout << e << " ";  //1 2 3
	}
	cout << endl;


	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	for (auto e : v1)
	{
		cout << e << " ";  //1 2 3
	}
	cout << endl;
}

//针对const对象访问
//需要
void test_vector2()
{
	const vector<int> v;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";  //1 2 3 4 5
	}
	cout << endl;

	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

template<class T>
void f()
{
	T x = T();
	cout << x << endl;
}

void test_vector3()
{
	//内置类型有没有构造函数，因为模板需要
	int i = int();  //默认有初始化为0
	i = int(1);  //初始化1  
	//int* pi = int* ();
	f<int>();  //0
	f<int*>();  //000000000
	f<double>(); //0
}

void test_vector4()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.resize(10);

	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	for (auto e : v1)
	{
		cout << e << " ";  //1 2 3 4 5 0 0 0 0 0
	}
	cout << endl;
	//只保留3个
	v1.resize(3);
	for (auto e : v1)
	{
		cout << e << " ";  // 1 2 3
	}
	cout << endl;
}

//insert
void test_vector5()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	//v1.push_back(5);
	for (auto e : v1)
	{
		cout << e << " ";  // 1 2 3 4 5
	}
	cout << endl;

	v1.insert(v1.begin(), 666);
	v1.insert(v1.end(), 666);
	for (auto e : v1)
	{
		cout << e << " ";  // 666 1 2 3 4 5 666
	}
	cout << endl;

	auto pos = find(v1.begin(), v1.end(), 3);
	v1.insert(pos, 30);
	for (auto e : v1)
	{
		cout << e << " ";  // 666 1 2 30 3 4 5 666
	}
	cout << endl;

	pos = find(v1.begin(), v1.end(), 3);
	(*pos)++;  //pos必须更新,因为pos在之前插入，已经改变了值
	for (auto e : v1)
	{
		cout << e << " ";  // 666 1 2 30 4 4 666
	}
	cout << endl;

	pos = find(v1.begin(), v1.end(), 666);
	v1.erase(pos);
	for (auto e : v1)
	{
		cout << e << " ";  // 1 2 30 4 4 666
	}
	cout << endl;
}

int main()
{
	//vector<int>::iterator it;
	//cout << typeid(it).name() << endl;
	test_vector5();
	return 0;
}