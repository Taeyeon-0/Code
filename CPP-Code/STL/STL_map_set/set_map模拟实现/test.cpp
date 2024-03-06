#include "map.h"
#include "set.h"
int main() {
    phw::set<int> s;
    s.Insert(1);
    s.Insert(5);
    s.Insert(3);
    s.Insert(8);
    s.Insert(8);
    s.InOrder();//1 3 5 8


    phw::map<string, int> map;
    map["a"] = 1;
    map["b"] = 2;
    map["c"] = 3;
    map["d"] = 4;
    map["e"] = 5;
    map.InOrder();// a b c d e
    return 0;
}