#include "string.h"
void test1()
{
	phw::string s1;
	phw::string s2("Hello World\n");
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl; // Hello World
}

void test2()
{
	phw::string s1;
	phw::string s2("hello world");
	phw::string s3(s2);			// 编译器默认的构造函数，浅拷贝,s2和s3的str指向了同一个空间，析构会出问题
	cout << s2.c_str() << endl; // hello world
	cout << s3.c_str() << endl; // hello world

	// 不自己写拷贝构造结果是s2变，s3跟着变，因为s2和s3指向同一个空间
	// s2[0]++;
	// cout << s2.c_str() << endl;   //iello world
	// cout << s3.c_str() << endl;   //iello world

	s2[0]++;
	cout << s2.c_str() << endl; // iello world
	cout << s3.c_str() << endl; // hello world

	s1 = s3;					// 自己不写还是会报错，因为还是浅拷贝
	cout << s1.c_str() << endl; // hello world
	cout << s3.c_str() << endl; // hello world
	s1 = s1;
}

void test3()
{
	phw::string s1("Hello World");
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " "; // I f m m p ! X p s m e
	}
	cout << endl;

	s1.Print(s1); // I f m m p ! X p s m e

	phw::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		(*it)--;
		it++;
	}

	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " "; // H e l l o   W o r l d
		it++;
	}
	cout << endl;

	for (auto ch : s1) // 底层就是将*it替换成ch
	{
		cout << ch << " "; // H e l l o   W o r l d
	}
	cout << endl;
}

// string比较大小
void test4()
{
	phw::string s1("hello world");
	phw::string s2("hello world");
	phw::string s3("xx");

	cout << (s1 < s2) << endl;	// 0
	cout << (s1 == s2) << endl; // 1
	cout << (s1 > s2) << endl;	// 0
}

void test5()
{
	phw::string s1("Hello World");
	s1.push_back('a');
	s1.append("xxxxxxxxxx");
	s1 += 'W';
	s1 += "!!!!!!!!!!!!";
	cout << s1.c_str() << endl; // Hello WorldaxxxxxxxxxxW!!!!!!!!!!!!

	phw::string s2 = "Hello World";
	s2.insert(5, 'X');
	cout << s2.c_str() << endl; // HelloX World
	s2.insert(0, 'A');
	cout << s2.c_str() << endl; // AHelloX World
	s2.insert(0, "PHW");
	cout << s2.c_str() << endl; // PHWAHelloX World
	s2.erase(0, 3);
	cout << s2.c_str() << endl; // AHelloX World
	s2.erase(5, 10);
	cout << s2.c_str() << endl; // AHell
}

// 流插入重载必须实现成友元函数？  不对
void test6()
{
	std::string s1("0123456789");
	phw::string s2("0123456789");
	s1 += '\0';
	s2 += '\0';
	s1 += "xxxx";
	s2 += "xxxx";
	cout << s1 << endl;			// 0123456789xxxx
	cout << s2.c_str() << endl; // 0123456789  遇到\0终止
	cout << s2 << endl;			// 0123456789xxxx

	phw::string s3;
	cin >> s3;
	cout << s3 << endl;
}

void test7()
{
	phw::string s1;
	std::string s2;
	cout << sizeof(s1) << endl; // 12
	cout << sizeof(s2) << endl; // 28

	s1 = "hello";
	s2 = "hello";
	cout << sizeof(s1) << endl; // 12
	cout << sizeof(s2) << endl; // 28

	// g++ 中x86  4字节   x64  8字节
	// g++中存的是指针
}

void test8()
{
	string s1 = "Hello World";
	int pos = s1.find("Wor", 3);
	s1[pos] = 'A'; // Hello Aorld
	cout << s1;
}

int main()
{
	// test8();
	return 0;
}