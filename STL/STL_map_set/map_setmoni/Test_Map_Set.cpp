#include"map.h"
#include"set.h"
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;

struct mapTest
{
	static void mapTest1()
	{
		phw::map<int, int> m{};
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(2, 2));
		m.Insert(make_pair(3, 3));
		m.InOrder();
	}

	static void mapTest2()
	{
		phw::map<int, int> t{};
		srand(time(nullptr));
		const int n = 1000000;
		for (int i = 0; i < n; i++)
		{
			int x = rand();
			t.Insert(make_pair(x, x));
		}
		t.InOrder();
	}

	static void mapTest3()
	{
		phw::map<string, string> dict{};
		dict.Insert(make_pair("sort", "排序"));
		dict.Insert(make_pair("string", "字符串"));
		dict.Insert(make_pair("count", "计数"));
		dict.Insert(make_pair("string", "(字符串)"));  //重复不插入

		phw::map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		//范围for
		for (auto& e : dict)
		{
			cout << e.first << ":" << e.second << endl;
		}
	}

	static void mapTest4()
	{
		string arr[] = { "西瓜","西瓜","苹果","西瓜","苹果","苹果","西瓜","苹果","香蕉","苹果","香蕉","梨" };
		phw::map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << "" << kv.second << endl;
		}
	}
};

struct setTest
{
	static void setTest1()
	{
		phw::set<int> s{};
		s.Insert(1);
		s.Insert(2);
		s.Insert(3);
		s.InOrder();
	}

	static void setTest2()
	{
		phw::set<int> s{};
		s.Insert(3);
		s.Insert(1);
		s.Insert(2);


		phw::set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}


	static void setTest3()
	{
		phw::set<int> t{};
		srand(time(nullptr));
		const size_t n = 1000000;
		for (int i = 0; i < n; i++)
		{
			int x = rand();
			t.Insert(x);
		}
		t.InOrder();
	}

	//迭代器测试
	static void setTest4()
	{
		int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		phw::set<int> t{};
		for (auto e : a)
		{
			t.Insert(e);
		}

		phw::set<int>::iterator it = t.begin();
		while (it != t.end())
		{
			cout << *it << " ";   //3 7 9 11 14 15 16 18 26
			++it;
		}
		cout << endl;

		for (auto e : t)
		{
			cout << e << " ";  //3 7 9 11 14 15 16 18 26
		}
		cout << endl;
	}

	static void setTest5()
	{
		int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		phw::set<int> t{};
		for (auto e : a)
		{
			t.Insert(e);
		}

		phw::set<int>::iterator it = t.begin();  //end为nullptr
		for (int i = 0; i < 4; i++)
		{
			++it;
		}

		while (it != nullptr)
		{
			cout << *it << " ";  //14 11 9 7 3
			--it;
		}
		cout << endl;
	}

};

int main()
{
	mapTest map_test;
	mapTest::mapTest4();

	//setTest set_test;
	//setTest::setTest5();
	return 0;
}
