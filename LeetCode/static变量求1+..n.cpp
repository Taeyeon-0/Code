//JZ64 求1+2+3+...+n
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//思路：利用C++静态成员变量来解决
#include <iostream>
using namespace std;
class Solution {
public:
    class Sum {
    public:
        Sum() {
            sum += i;
            i++;
        }
    };
    int Sum_Solution(int n) {
        Sum *a = new Sum[n];//new 10个Sum对象，Sum自动调用构造函数，进行sum+=i，i++， 然后return sum即可
        return sum;
    }

private:
    static int i;
    static int sum;
};

int Solution::i = 1;
int Solution::sum = 0;
