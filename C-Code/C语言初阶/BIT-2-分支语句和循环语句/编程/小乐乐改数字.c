#include<stdio.h>
#include<math.h>
//小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，想把每位的数变成0或1。
//如果某一位是奇数，就把它变成1，如果是偶数，那么就把它变成0。
//请你回答他最后得到的数是多少。
int main() {
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int sum = 0;
	while (n) {
		int bit = n % 10;
		if (bit % 2 == 1) {
			sum += 1 * pow(10, i);
		}
		i++;
		n /= 10;
	}
	printf("%d\n", sum);
	return 0;
}