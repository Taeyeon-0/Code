#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct unordered_setTest
{
    static void unordered_setTest1()
    {
        unordered_set<int> s{};
        s.insert(1);
        s.insert(3);
        s.insert(2);
        s.insert(7);
        s.insert(2);

        unordered_set<int>::iterator it = s.begin();
        while (it != s.end())
        {
            cout << *it << " "; // vs输出1 3 2 7  g++ 7 2 1 3
            it++;
        }
        cout << endl;
    }
};

struct unordered_mapTest
{
    static void unordered_mapTest1()
    {
        string arr[] = {"西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉", "梨"};
        unordered_map<string, int> countMap;

        for (auto &e : arr)
        {
            countMap[e]++;
        }

        for (auto &kv : countMap)
        {
            cout << kv.first << ":" << kv.second << endl;
        }
        // 这里vs和g++输出结果是反着的
    }
};

void testop()
{
    const size_t N = 1000000;

    unordered_set<int> us;
    set<int> s;

    vector<int> v;
    v.reserve(N);
    srand(time(0));
    for (size_t i = 0; i < N; ++i)
    {
        v.push_back(rand());
        // v.push_back(rand()+i);
        // v.push_back(i);
    }

    size_t begin1 = clock();
    for (auto e : v)
    {
        s.insert(e);
    }
    size_t end1 = clock();
    cout << "set insert:" << end1 - begin1 << endl;

    size_t begin2 = clock();
    for (auto e : v)
    {
        us.insert(e);
    }
    size_t end2 = clock();
    cout << "unordered_set insert:" << end2 - begin2 << endl;

    size_t begin3 = clock();
    for (auto e : v)
    {
        s.find(e);
    }
    size_t end3 = clock();
    cout << "set find:" << end3 - begin3 << endl;

    size_t begin4 = clock();
    for (auto e : v)
    {
        us.find(e);
    }
    size_t end4 = clock();
    cout << "unordered_set find:" << end4 - begin4 << endl
         << endl;

    cout << s.size() << endl;
    cout << us.size() << endl
         << endl;
    ;

    size_t begin5 = clock();
    for (auto e : v)
    {
        s.erase(e);
    }
    size_t end5 = clock();
    cout << "set erase:" << end5 - begin5 << endl;

    size_t begin6 = clock();
    for (auto e : v)
    {
        us.erase(e);
    }
    size_t end6 = clock();
    cout << "unordered_set erase:" << end6 - begin6 << endl
         << endl;
}

int main()
{
    //unordered_setTest::unordered_setTest1();
    //unordered_mapTest::unordered_mapTest1();
    testop();
    return 0;
}