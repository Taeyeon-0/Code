#include"vector.h"
#include<vector>
using namespace phw;
void test_vector1()
{
	phw::vector<int> v1;
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

	phw::vector<int>::iterator it = v1.begin();
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
	const phw::vector<int> v;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";  //1 2 3 4 5
	}
	cout << endl;

	phw::vector<int>::const_iterator it = v.begin();
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
	phw::vector<int> v1;
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
	phw::vector<int> v1;
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

//erase
void test_vector6()
{
	phw::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	//要求删除所有的偶数
	phw::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			//删除后，结果返回it，erase的返回值是原先下一个地址的，这样迭代器不会失效，更新迭代器
			//
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}

	for (auto e : v1)
	{
		cout << e << " ";  // 1 2 3 4 5
	}
	cout << endl;
}

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
};

void test_vector7()
{
	A a1;
	const A& xx = A();  //const 引用会让匿名对象声明周期延长，延长到xx销
}

void test_vector8()
{
	phw::vector<int> v(10, 5);  //调用有问题，
	//vector(size_t n, const T& val = T())和vector(InputIterator first, InputIterator last)，会调用后者，因为10和5是int类型，会调用后面的模板
	for (auto e : v)
	{
		cout << e << " ";  //5 5 5 5 5 5 5 5 5 5
	}
	cout << endl;
	//迭代器构造函数
	phw::vector<int> v2(v.begin() + 1, v.end());
	for (auto e : v2)
	{
		cout << e << " ";   //5 5 5 5 5 5 5 5 5
	}
	cout << endl;

	std::string s1("Hello");
	std::vector<int> v3(s1.begin(), s1.end());
	for (auto e : v3)
	{
		cout << e << " ";  //72 101 108 108 111
	}
	cout << endl;

	int a[] = { 10,20,30 };
	std::vector<int> v4(a, a + 3);  //原生指针就是天然迭代器
	for (auto e : v4)
	{
		cout << e << " ";   // 10 20 30
	}
	cout << endl;
}

//sort  - 依赖头文件#include<algorithm> - 默认升序
//greater降序 - 依赖头文件#include<functional>
void test_vector9()
{
	phw::vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);
	for (auto e : v)
	{
		cout << e << " ";  // 5 4 1 3
	}
	cout << endl;

	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << " ";   //1 3 4 5
	}
	cout << endl;

	int a[] = { 3,7,2,4,5,6,7 };
	sort(a, a + 7);
	for (auto e : a)
	{
		cout << e << " ";  //2 3 4 5 6 7 7
	}
	cout << endl;
	//改为降序
	greater<int> g;
	sort(a, a + sizeof(a) / sizeof(int), g);   //7 7 6 5 4 3 2
	//sort(a, a + sizeof(a) / sizeof(int), greater<int>());  //传匿名对象
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

//深浅拷贝
void test_vector10()
{
	phw::vector<int> v1(10, 5);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	
	phw::vector<int> v2(v1);  //没有写深拷贝，编译器调用默认构造函数，浅拷贝
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	phw::vector<std::string> v3(5, "11111111111111111");
	for (std::string e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	phw::vector<std::string> v4(v3);
	for (std::string e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
	v4.push_back("22222222222222\n");
	v4.push_back("22222222222222\n");
	v4.push_back("22222222222222");
	v4.push_back("22222222222222");
	v4.push_back("22222222222222");
	v4.push_back("22222222222222");
	v4.push_back("22222222222222");
	v4.push_back("22222222222222");
	v4.push_back("2");
	for (std::string e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//vector<int>::iterator it;
	//cout << typeid(it).name() << endl;
	test_vector10();

	return 0;
}