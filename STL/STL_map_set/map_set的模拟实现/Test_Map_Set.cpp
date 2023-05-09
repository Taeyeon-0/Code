#include"map.h"
#include"set.h"

struct mapTest
{
	void mapTest1()
	{
		phw::map<int,int> m{};
		m.insert(make_pair(1,1));
		m.insert(make_pair(2,2));
		m.insert(make_pair(3,3));

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
	phw::map<int,int> map{};
	phw::set<int> set{};
	return 0;
}
