#include<iostream>
#include<vector>
using namespace std;

void test_vector1()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> copy(v);
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector2()
{
	vector<int> v1(10, 1);   //10个1
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>v2(v1.begin(), v1.end());  //迭代器区间构造
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	//迭代器区间底层是模板，也可以传别的类型
	string s1("hello world");
	vector<int> v3(s1.begin(), s1.end());
	//vector<int> v3(++s1.begin(), --s1.end());   //传一部分迭代器
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

//迭代器
void test_vector3()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//反向迭代器
	vector<int>::reverse_iterator rit = v.rbegin();
	//auto rit = v.rbegin();   //自动识别迭代器类型
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	cout << v.max_size() << endl;    //max_size 没有价值
}


void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	const size_t n = 1000000;

	size_t begin = clock();
	v.reserve(n);  //测试提前扩容和不扩容的速度
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			//cout << "capacity changed: " << sz << '\n';
		}
	}
	size_t end = clock();
	cout << "测试结果：" << end - begin << endl;
}


void test_vector5()
{
	vector<int> v1;
	v1.resize(10, 0);  //开空间+初始化,C++开空间非常方便，推荐使用这种方式

	vector<int> v2(10, 0);  //这也可以 ，构造开空间，不推荐，有些情况不适用
}

void test_vector6()
{
	//vector没有find，find使用std::里的，std::的find出了string适用任何类型
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//使用find找值为2的位置，vector插入删除，使用的是迭代器，pos为迭代器类型

	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.insert(pos, 20);
	}

	for (auto e : v)
	{
		cout << e << " ";   //1 20 2 3 4 5
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 20);  //调用erase之前必须再次定位pos，否则会报错，迭代器pos之前插入后，就失效了，需要重新定位
	if (pos != v.end())
	{
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;
	//vector不建议用insert和erase，顺序表插入删除效率很低
}

//vector<char> 可以代替string吗？
//vector<char> 没有\0，不兼容C语言的字符串，vector比较大小和string也不一样。string字符串的需求和vector不同，所以必须分开设计

int main()
{
	test_vector6();
	return 0;
}