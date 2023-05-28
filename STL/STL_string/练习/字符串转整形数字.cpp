// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为 0 或者字符串不是一个合法的数值则返回 0

/* 实例1
输入：
"+2147483647"
复制
返回值：
2147483647

示例2 输入：
"1a33"
复制
返回值：0
*/
#include <string>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        long long sum = 0;// 用来存储值
        int sign = 1;     // sign默认值为正数
        // 遍历字符串找数字
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                continue;
            }
            if (str[i] == '-') {
                // 字符串为负数，将sign设置为-1
                sign = -1;
            } else if (str[i] == '+') {
                // 正数也要处理，因为要判断是否为合法数字,如果不判断，进else，return 0了
                sign = 1;
            } else if (str[i] >= '0' && str[i] <= '9') {
                // 每次遇到一个数字就×10，在加上当前数字，第一次sum为0，直接加str[i];
                sum = sum * 10 + (str[i] - '0');
            } else {
                return 0;
            }
        }
        return sign * sum;
    }
};
// https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking