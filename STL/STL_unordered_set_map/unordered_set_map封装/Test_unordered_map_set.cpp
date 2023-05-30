#include<iostream>
#include"unordered_map.h"
#include"unordered_set.h"
struct unordered_map_Test {
    static void unordered_map_Test1() {
        unordered_map<int, int> mp;
        mp.insert(make_pair(1, 1));
        mp.insert(make_pair(2, 2));
        mp.insert(make_pair(3, 3));

        unordered_map<int,int>::iterator it = mp.begin();
        while (it != mp.end()) {
            cout << it->first << " " << it->second << endl;
            ++it;
        }
        cout << endl;

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
            ++it;
        }
        cout << endl;

    }
};

int main() {
    unordered_set_Test::unordered_set_Test1();
    unordered_map_Test::unordered_map_Test1();
    return 0;
}