#include<stdio.h>
//公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），
//去掉一个最高分和一个最低分，输出每组的平均成绩。
int main() {
    int score = 0;
    int sum = 0.0;
    int min = 100;
    int max = 0;
    int count = 0;
    while (scanf_s("%d", &score) != EOF) {
        if (score < min)
            min = score;
        if (score > max)
            max = score;
        sum += score;
        count++;
        if (count == 7) {
            printf("%.2f\n", (sum - min - max) / 5.0);
            count = 0;
            min = 100;
            max = 0;
            sum = 0;
        }

    }

    return 0;
}