#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

//namespace phw
//{
//	class string
//	{
//	public:
//		//无参构造函数
//		string()
//			:_str(nullptr),
//			_size(0),
//			_capacity(0)
//		{}
//
//		//带参构造函数
//		string(const char* str)
//			:_str(str)
//			, _size(strlen(str))
//			, _capacity(strlen(str))
//		{}
//
//		//获取字符串
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		size_t size()
//		{
//			return _size;
//		}
//	private:
//		const char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//
//	void test_string1()
//	{
//		string s1;
//		string s2("Hello World\n");
//		cout << s1.c_str() << endl;  //s1为空指针，cout对空指针解引用，崩溃
//		cout << s2.c_str() << endl;
//	}
//}

//2
//namespace phw
//{
//	class string
//	{
//	public:
//		//无参构造函数
//		string()
//			:_str(new char[1]),  //new一个char
//			_size(0),
//			_capacity(0)
//		{
//			_str[0] = '\0';
//		}
//
//		//带参构造函数
//		string(const char* str)
//			:_size(strlen(str))
//		{
//			_capacity = _size;
//			_str = new char[_capacity + 1];   //new _capacity+1  capacity是字符串容量，存放的有效字符大小，不是空间，空间还有一个|0
//			strcpy(_str, str);
//		}
//
//		//获取字符串
//		const char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		size_t size()
//		{
//			return _size;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_size = 0;
//			_capacity = 0;
//		}
//
//		void test_string1()
//		{
//			string s1;
//			string s2("Hello World\n");
//			cout << s1.c_str() << endl;
//			cout << s2.c_str() << endl;  // Hello World
//
//			s2[0]++;
//			cout << s2.c_str() << endl;   //Iello World
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}


//3   2的优化
namespace phw
{
	class string
	{
	public:
		friend ostream& operator<<(ostream& out, const phw::string& s);
		friend istream& operator>>(istream& in, phw::string& s);
		//带参构造函数
		//string(const char* str = nullptr)  //不可以 给空指针，strlen会报错
		//string(const char* str = '\0')  //\0 char转换成指针，也是空指针
		//string(const char* str = "\0")   //可以,给常量字符串，strlen不会报错
		string(const char* str = "")    //空字符串默认是\0
			:_size(strlen(str))
		{
			_capacity = _size == 0 ? 3 : _size;  //最少给3个字节空间
			_str = new char[_capacity + 1];   //new _capacity+1  capacity是字符串容量，存放的有效字符大小，不是空间，空间还有一个|0
			strcpy(_str, str);
		}
		//拷贝构造 
		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			//_str自己开空间
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
		}
		//赋值是对已经定义的对象进行赋值
		//有一种情况是，原对象的空间远大于要赋值的对象，那么就会出现空间浪费
		//所以首先应该delete掉原空间的内存，在进行赋值
		string& operator =(const string& s)
		{
			if (this != &s)
			{
				//delete[]_str;  //赋值提前把旧空间释放，防止浪费空间
				//_str = new char[s._capacity + 1];
				//strcpy(_str, s._str);
				//_size = s._size;
				//_capacity = s._capacity;
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}

		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//获取字符串
		const char* c_str()
		{
			return _str;
		}
		//[]通过下标来访问字符
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		//访问const类型的数组
		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}

		void Print(const string& s)
		{
			for (size_t i = 0; i < s.size(); i++)
			{
				cout << s._str[i] << " ";
			}
			cout << endl;
			//这里不支持范围for了，为什么？  因为这里s是const对象，只能调用const迭代器
			string::const_iterator it = s.begin();
			while (it != s.end())
			{
				//(*it)++;  //err. const迭代器指向的内容不能修改
				it++;
			}
			//这里没有定义const迭代器，就会报错，范围for的底层就是迭代器
			for (auto ch : s)
			{
				cout << ch << " ";
			}
			cout << endl;
		}
		// 不修改成员变量数据的函数，最好加上const
		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}

		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		bool operator <= (const string& s) const
		{
			return !(*this > s);
		}

		//扩容的时候，并且初始化 
		void resize(size_t n, char ch = '\0')
		{
			//当n小于_size的时候，不需要扩容，也不需要缩容
			//n大于_size的时候，并且当n>capacit的时候需要扩容，就直接调用reserve
			if (n < _size)
			{
				//保留前n个
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				//从_size开始 到需要扩容n开始，初始化\0
				size_t i = _size;
				while (i < n)
				{
					_str[i] = ch;
					++i;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		//扩容n
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		//尾插字符串
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);  //从_str+_size开始拷贝
			//strcat(_str, str);     //strcat会找\0，效率低下
			_size += len;
			_str[_size] = '\0';
		}

		string& operator +=(const char* str)
		{
			append(str);
			return *this;
		}

		string& operator +=(const char ch)
		{
			push_back(ch);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			int end = _size;
			//这里的pos需要改成int pos是无符号类型，和end对比，end会转换成无符号类型
			//当pos的位置是0时，end为无符号类型将永远不会小于0，程序无限循环。
			//需要将pos转换成int，那么end就为int类型
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			int len = strlen(str);
			int end = _size + len;
			if (_size + len > _capacity)
			{
				reserve(2 * _capacity);
			}

			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			//如果要删的个数远超于剩余的个数，就是pos位置后面全部删除，直接在pos位置后面置\0即可
			// len == npos必须加上，npos是最大值
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);

		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
		}


		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);

			char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - str;
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;  //静态成员变量不能给缺省值，
		//static const size_t npos = -1;  //加上const可以，只针对整型

		//static const size_t N = 10;
		//int _a[N];
	};
}

const size_t phw::string::npos = -1;

ostream& phw::operator<<(ostream& out, const phw::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		out << s[i];
	}
	return out;
}

istream& phw::operator>>(istream& in, phw::string& s)
{
	s.clear();  //一开始就清理缓冲区
	char ch = in.get();
	char buff[128];
	size_t i = 0;
	while (ch != ' ' && ch != '\n')
	{
		//s += ch;  //字符串太长可能会容量不够,用reserve如何控制扩容？ 扩容会频繁调用
		buff[i++] = ch;
		if (i == 127)
		{
			buff[127] = '\0';
			s += buff;
			i = 0;
		}
		ch = in.get();
	}

	if (i != 0)
	{
		buff[i] = '\0';
		s += buff;
	}
	//getline实现
	/*while (ch != '\n')
	{
		s += ch;
		ch = in.get();
	}*/

	return in;
}

void test_string1()
{
	phw::string s1;
	phw::string s2("Hello World\n");
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;  // Hello World
}

void test_string2()
{
	phw::string s1;
	phw::string s2("hello world");
	phw::string s3(s2);   //编译器默认的构造函数，浅拷贝,s2和s3的str指向了同一个空间，析构会出问题
	cout << s2.c_str() << endl;   //hello world
	cout << s3.c_str() << endl;   //hello world

	//不自己写拷贝构造结果是s2变，s3跟着变，因为s2和s3指向同一个空间
	//s2[0]++;
	//cout << s2.c_str() << endl;   //iello world
	//cout << s3.c_str() << endl;   //iello world

	s2[0]++;
	cout << s2.c_str() << endl;   //iello world
	cout << s3.c_str() << endl;   //hello world

	s1 = s3;  //自己不写还是会报错，因为还是浅拷贝
	cout << s1.c_str() << endl;   //hello world
	cout << s3.c_str() << endl;   //hello world
	s1 = s1;
}

//遍历字符串
void test_string3()
{
	phw::string s1("Hello World");
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	s1.Print(s1);

	phw::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		(*it)--;
		it++;
	}

	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto ch : s1)  //底层就是将*it替换成ch
	{
		cout << ch << " ";
	}
	cout << endl;
}

//string比较大小
void test_string4()
{
	phw::string s1("hello world");
	phw::string s2("hello world");
	phw::string s3("xx");

	cout << (s1 < s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 > s2) << endl;
}

void test_string5()
{
	phw::string s1("Hello World");
	s1.push_back('a');
	s1.append("xxxxxxxxxx");
	s1 += 'W';
	s1 += "!!!!!!!!!!!!";
	cout << s1.c_str() << endl;

	phw::string s2 = "Hello World";
	s2.insert(5,'X');
	cout << s2.c_str() << endl;
	s2.insert(0,'A');
	cout << s2.c_str() << endl;
	s2.insert(0, "PHW");
	cout << s2.c_str() << endl;
	s2.erase(0, 3);
	cout << s2.c_str() << endl;
	s2.erase(5, 10);
	cout << s2.c_str() << endl;
}

//流插入重载必须实现成友元函数？  不对
void test_string6()
{
	std::string s1("0123456789");
	phw::string s2("0123456789");
	s1 += '\0';
	s2 += '\0';
	s1 += "xxxx";
	s2 += "xxxx";
	cout << s1 << endl;   //0123456789xxxx
	cout << s2.c_str() << endl;  //0123456789  遇到\0终止
	cout << s2 << endl;   //0123456789xxxxs
	
	phw::string s3;
	cin >> s3;
	cout << s3 << endl;
	
}

void test_string7()
{
	phw::string s1;
	std::string s2;
	cout << sizeof(s1) << endl;  //12
	cout << sizeof(s2) << endl;  //28

	s1 = "hello";
	s2 = "hello";
	cout << sizeof(s1) << endl;  //12
	cout << sizeof(s2) << endl;  //28

	//g++ 中x86  4字节   x64  8字节
	//g++中存的是指针
}