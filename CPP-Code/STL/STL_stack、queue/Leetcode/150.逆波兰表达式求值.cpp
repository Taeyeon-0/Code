#include <stack>
#include <string>
#include <vector>
using namespace std;
//1、操作数入栈
//2、操作符，取栈顶的两个操作数进行运算，运算结果重新入栈
class Solution {
public:
    bool isNumber(string &token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            string &token = tokens[i];
            if (isNumber(token)) {
                //atoi函数用于将字符串转换成数字
                st.push(atoi(token.c_str()));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                switch (token[0]) {
                    case '+':
                        st.push(num1 + num2);
                        break;
                    case '-':
                        st.push(num1 - num2);
                        break;
                    case '*':
                        st.push(num1 * num2);
                        break;
                    case '/':
                        st.push(num1 / num2);
                        break;
                }
            }
        }
        return st.top();
    }
};
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/