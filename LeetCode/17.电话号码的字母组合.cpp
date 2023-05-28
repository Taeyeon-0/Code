// 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按任意顺序返回。
// 2 - abc   3 - def  4 - ghi  5 - jkl  6 - mno  7 - pqrs  8 - tuv  9 - wxyz
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    // 将数字对应的电话号码写入数组中
    string _numTostr[10] = {"", "", "abc", "def", "ghi", "jki", "mno", "pqrs", "tuv", "wxyz"};

public:
    //digits是原数字串，di为递归层数，也就是数字串的第几位
    //combineStr是一开始由空串+=递归的串所得，作用是尾插到strV中
    void Combinations(const string &digits, size_t di, string combineStr, vector<string> &strV) {
        //当di等于digits数字字符的大小，说明树已经走到底了，可以尾插字符串到strv中了，然后返回，继续递归
        if (di == digits.size()) {
            strV.push_back(combineStr);
            return;
        }
        // 首先，获取数字，数字存放在digits中，用di-'0'获取字符串digits里的数字字符
        int num = digits[di] - '0';
        // 取当前层的str串,num是几，就取_numTostr对应下标的串
        string str = _numTostr[num];
        //开始循环递归串，第一层有几个字符，就循环几次
        for (auto ch: str) {
            Combinations(digits, di + 1, combineStr + ch, strV);
        }
    }
    vector<string> letterCombinations(string digits) {
        //strV是返回串，用来返回结果
        vector<string> strV;
        //如果digits本身为空，那么就直接返回strV，否则会push_back一个空值
        if (digits == "") {
            return strV;
        }
        //递归函数
        Combinations(digits, 0, "", strV);
        return strV;
    }
};

// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/