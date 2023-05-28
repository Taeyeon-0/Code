// 给你一个整数数组nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按任意顺序返回答案。
// 你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
/*
示例 1：
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。

示例 2：
输入：nums = [-1,0]
输出：[-1,0]

示例 3：
输入：nums = [0,1]
输出：[1,0]
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        vector<int> ret;
        // 1.排序
        sort(nums.begin(), nums.end());
        // 2.循环判断找相邻两个不相等的值，然后尾插到临时的vector中
        for (int i = 0; i < nums.size(); i++) {
            if ((i + 1) < nums.size() && nums[i] == nums[i + 1]) {
                i++;
                continue;
            } else {
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};