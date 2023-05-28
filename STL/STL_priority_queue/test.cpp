#include "priority_queue.h"
#include <iostream>

void test() {
    phw::priority_queue<int> p;
    p.push(81);
    p.push(12);
    p.push(32);
    p.push(85);
    p.push(80);
    p.push(19);

    while (!p.empty()) {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}