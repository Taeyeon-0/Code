#include"map.h"
#include"set.h"
#include<cstdlib>

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
};

int main()
{
//	mapTest map_test;
//	mapTest::mapTest2();

	setTest set_test;
	setTest::setTest3();
	return 0;
}
