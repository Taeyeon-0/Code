// 给你一个非空整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 异或，相同的数异或得0  0异或任何数都为任何数   异或没有顺序条件限制
// 思路：将nums中的数组的数逐次异或，最后得到的数就是只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ret ^= nums[i];
        }
        return ret;
    }
};

// 思路2：先排序，在找出只出现一次的数字
/*
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        //先排序
        sort(nums.begin(), nums.end());
        //如果size为1，则直接返回
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == nums[i + 1])
            {
                i += 2;
                continue;
            }
            else
            {
                return nums[i];
            }
        }
        return 99999;   //Leetcode必须返回一个值，任意值即可
    }
}; */