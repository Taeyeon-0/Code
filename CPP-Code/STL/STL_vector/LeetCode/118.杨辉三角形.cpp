// 给定一个非负整数numRows生成「杨辉三角」的前numRows行。
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)// 返回值为二维数组，vector<vector<int>>
    {
        vector<vector<int>> vv(numRows);// 创建一个vector由numsRows行初始化

        for (int i = 0; i < numRows; i++) {
            // 将杨辉三角形初始化为1,每行递增1
            vv[i].resize(i + 1, 1);
        }

        // 开始生成杨辉三角形,从第三行开始，第一行第二行都为1

        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
            }
        }
        return vv;
    }
};