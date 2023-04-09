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
	vector<int> v1(10, 1);   //10��1
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>v2(v1.begin(), v1.end());  //���������乹��
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	//����������ײ���ģ�壬Ҳ���Դ��������
	string s1("hello world");
	vector<int> v3(s1.begin(), s1.end());
	//vector<int> v3(++s1.begin(), --s1.end());   //��һ���ֵ�����
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

//������
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
	//���������
	vector<int>::reverse_iterator rit = v.rbegin();
	//auto rit = v.rbegin();   //�Զ�ʶ�����������
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	cout << v.max_size() << endl;    //max_size û�м�ֵ
}


void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	const size_t n = 1000000;

	size_t begin = clock();
	v.reserve(n);  //������ǰ���ݺͲ����ݵ��ٶ�
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
	cout << "���Խ����" << end - begin << endl;
}


void test_vector5()
{
	vector<int> v1;
	v1.resize(10, 0);  //���ռ�+��ʼ��,C++���ռ�ǳ����㣬�Ƽ�ʹ�����ַ�ʽ

	vector<int> v2(10, 0);  //��Ҳ���� �����쿪�ռ䣬���Ƽ�����Щ���������
}

void test_vector6()
{
	//vectorû��find��findʹ��std::��ģ�std::��find����string�����κ�����
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	//ʹ��find��ֵΪ2��λ�ã�vector����ɾ����ʹ�õ��ǵ�������posΪ����������

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

	pos = find(v.begin(), v.end(), 20);  //����erase֮ǰ�����ٴζ�λpos������ᱨ����������pos֮ǰ����󣬾�ʧЧ�ˣ���Ҫ���¶�λ
	if (pos != v.end())
	{
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << " ";  //1 2 3 4 5
	}
	cout << endl;
	//vector��������insert��erase��˳�������ɾ��Ч�ʺܵ�
}

//vector<char> ���Դ���string��
//vector<char> û��\0��������C���Ե��ַ�����vector�Ƚϴ�С��stringҲ��һ����string�ַ����������vector��ͬ�����Ա���ֿ����

int main()
{
	test_vector6();
	return 0;
}