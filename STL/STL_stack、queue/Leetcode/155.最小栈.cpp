#include <stack>
using namespace std;
class MinStack {
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }

private:
    stack<int> x_stack;
    stack<int> min_stack;
};