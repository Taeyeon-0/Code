#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> st; // 辅助栈
        int j = 0;
        // 遍历push栈
        for (int i = 0; i < pushV.size(); i++)
        {
            // pop栈
            st.push(pushV[i]);
            if (st.top() != popV[j])
            {
                continue;
            }
            else
            {
                while (!st.empty() && j < popV.size() && st.top() == popV[j])
                {
                    st.pop();
                    j++;
                }
            }
        }
        return st.empty();
    }
};