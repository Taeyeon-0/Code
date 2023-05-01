#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    for (auto e : v)
    {
        cout << e << " "; // 1 2 3 4 5
    }
    
    cout << endl;
    // 定义一个int类型的栈，默认底层容器是deque(双端队列)
    stack<int> st;
    // 定义一个int类型的栈，底层容器使用vector<int>
    stack<int, vector<int>> st2;
    // 定义一个int类型的栈，底层容器使用list<int>
    stack<int, list<int>> st3;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.size() << endl; // 4

    while (!st.empty())
    {
        cout << st.top() << " "; // 4 3 2 1
        st.pop();
    }
    cout << endl;
    return 0;
}