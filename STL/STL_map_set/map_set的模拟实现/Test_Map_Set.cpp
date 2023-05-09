#include"map.h"
#include"set.h"
#include<cstdlib>

struct mapTest
{
	void mapTest1()
	{
		phw::map<int, int> m{};
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(2, 2));
		m.Insert(make_pair(3, 3));
		m.InOrder();
	}

	void mapTest2()
	{
		phw::map<int, int> t;
		srand(time(nullptr));
		const size_t n = 1000000;
		for (size_t i = 0; i < n; i++)
		{
			size_t x = rand();
			t.Insert(make_pair(x, x));
		}
		t.InOrder();
	}
};

struct setTest
{
	void setTest1()
	{
		phw::set<int> s{};
		s.insert(1);
		s.insert(2);
		s.insert(3);
	}
};

int main()
{
	mapTest map_test;
	map_test.mapTest2();

	setTest set_test;
	set_test.setTest1();
	return 0;
}
