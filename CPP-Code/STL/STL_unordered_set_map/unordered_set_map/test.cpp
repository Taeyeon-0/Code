#include "unordered_map.h"
#include "unordered_set.h"
#include <iostream>
class Date {
    friend struct HashDate;

public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year), _month(month), _day(day) {}

    bool operator<(const Date &d) const {
        return (_year < d._year) ||
               (_year == d._year && _month < d._month) ||
               (_year == d._year && _month == d._month && _day < d._day);
    }

    bool operator>(const Date &d) const {
        return (_year > d._year) ||
               (_year == d._year && _month > d._month) ||
               (_year == d._year && _month == d._month && _day > d._day);
    }

    bool operator==(const Date &d) const {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    friend ostream &operator<<(ostream &_cout, const Date &d);

private:
    int _year;
    int _month;
    int _day;
};

ostream &operator<<(ostream &_cout, const Date &d) {
    _cout << d._year << "-" << d._month << "-" << d._day;
    return _cout;
}

//自定义Hash，模板最后一个参数，传自定义类型的话，需要自己写
struct HashDate {
    size_t operator()(const Date &d) {
        size_t hash = 0;
        hash += d._year;
        hash *= 31;

        hash += d._month;
        hash *= 31;

        hash += d._day;
        hash *= 31;

        return hash;
    }
};

struct unordered_map_Test {
    static void unordered_map_Test1() {
        unordered_map<int, int> mp;
        mp.insert(make_pair(1, 1));
        mp.insert(make_pair(2, 2));
        mp.insert(make_pair(3, 3));

        unordered_map<int, int>::iterator it = mp.begin();
        while (it != mp.end()) {
            cout << it->first << " " << it->second << endl;
            ++it;
        }
        cout << endl;
    }

    static void unordered_map_Test2() {
        string arr[] = {"西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉", "梨"};
        unordered_map<string, int> countMap;
        for (auto &e: arr) {
            countMap[e]++;
        }

        for (auto &kv: countMap) {
            cout << kv.first << "" << kv.second << endl;
        }
    }

    static void unordered_map_Test3() {
        Date d1(2023, 3, 13);
        Date d2(2023, 3, 13);
        Date d3(2023, 3, 12);
        Date d4(2023, 3, 11);
        Date d5(2023, 3, 12);
        Date d6(2023, 3, 13);

        Date a[] = {d1, d2, d3, d4, d5, d6};

        unordered_map<Date, int, HashDate> countMap;
        for (auto e: a) {
            countMap[e]++;
        }

        for (auto &kv: countMap) {
            cout << kv.first << ":" << kv.second << endl;
        }
    }
};

struct unordered_set_Test {
    static void unordered_set_Test1() {
        unordered_set<int> s;
        s.insert(1);
        s.insert(3);
        s.insert(2);
        s.insert(7);
        s.insert(8);

        unordered_set<int>::iterator it = s.begin();
        while (it != s.end()) {
            cout << *it << " ";
            //(*it) = 1;
            ++it;
        }
        cout << endl;
    }
};

int main() {
    unordered_set_Test::unordered_set_Test1();
    unordered_map_Test::unordered_map_Test1();
    unordered_map_Test::unordered_map_Test2();
    unordered_map_Test::unordered_map_Test3();
    return 0;
}