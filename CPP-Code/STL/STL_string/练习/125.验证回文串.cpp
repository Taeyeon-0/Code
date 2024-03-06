/* 
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个回文串 。
字母和数字都属于字母数字字符。
给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。 */


#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            //先将所有的大小字母变成小写字母
            if (s[left] >= 'A' && s[left] <= 'Z') {
                s[left] += 32;
            }
            if (s[right] >= 'A' && s[right] <= 'Z') {
                s[right] += 32;
            }


            //排除所有非字母和数字字符的，如果不是字母和数字字符就继续下一个
            if (!(s[left] >= 'a' && s[left] <= 'z' || s[left] >= '0' && s[left] <= '9')) {
                left++;
                continue;
            }
            if (!(s[right] >= 'a' && s[right] <= 'z' || s[right] >= '0' && s[right] <= '9')) {
                right--;
                continue;
            }

            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};

//https://leetcode.cn/problems/valid-palindrome/submissions/