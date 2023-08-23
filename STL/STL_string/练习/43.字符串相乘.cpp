// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        // 如果有一个数字为0，则直接返回"0"
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        // 初始化结果字符串为"0"
        string ans = "0";
        // 分别获取num1和num2的长度
        int m = num1.size(), n = num2.size();
        // 从num2的个位数开始，逐位乘以num1
        for (int i = n - 1; i >= 0; i--) {
            // curr存储当前乘积
            string curr;
            // add存储进位值
            int add = 0;
            // 在curr中填充0，填充的个数为n-1-i个
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            // 获取num2的第i位数字
            int y = num2.at(i) - '0';
            // 遍历num1的每一位数字，计算当前乘积
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            // 将进位值加入curr中
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            // 反转curr，将其变为正确的乘积形式
            reverse(curr.begin(), curr.end());
            // 将curr中的数字转换为字符
            for (auto &c: curr) {
                c += '0';
            }
            // 将当前乘积与结果相加
            ans = addStrings(ans, curr);
        }
        // 返回最终结果
        return ans;
    }

    string addStrings(string &num1, string &num2) {
        // i和j分别为num1和num2的下标，add为进位值
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        // ans存储结果字符串
        string ans;
        // 从后往前遍历num1和num2，逐位相加
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        // 反转结果字符串
        reverse(ans.begin(), ans.end());
        // 将ans中的数字转换为字符
        for (auto &c: ans) {
            c += '0';
        }
        // 返回结果
        return ans;
    }
};
