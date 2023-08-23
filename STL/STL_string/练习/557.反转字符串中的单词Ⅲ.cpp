// 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};

//https://leetcode.cn/problems/reverse-words-in-a-string-iii/submissions/