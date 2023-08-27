#include <vector>
using namespace std;
// 以杨慧三角的前n行为例：假设n为5
void test2vector(size_t n) {
    vector<vector<int>> vv(n);
    for (size_t i = 0; i < n; ++i)
        vv[i].resize(i + 1, 1);
    // 给杨慧三角出第一列和对角线的所有元素赋值
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j < i; ++j) {
            vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
        }
    }
}