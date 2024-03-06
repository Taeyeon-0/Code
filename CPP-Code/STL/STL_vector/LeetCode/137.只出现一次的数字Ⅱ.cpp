// 给你一个整数数组nums,除某个元素仅出现一次外，其余每个元素都恰出现三次 。请你找出并返回那个只出现了一次的元素。

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        // 1.先排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i + 2 < nums.size() && nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
                i += 2;
                continue;
            } else {
                return nums[i];
            }
        }
        return 0;
    }
};