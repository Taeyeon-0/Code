#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//设计一个程序能计算一个日期加上若干天后是什么日期。
bool is_leap_year(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int month_days(int year, int month)
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year) && month == 2)
    {
        return 29;
    }
    return days[month];
}

void add_days(int &year, int &month, int &day, int days)
{
    // 将当月的天数加上总天数
    day = days + day;
    while (day > month_days(year, month))
    {
        // 减去当前月份的天数，++month
        day -= month_days(year, month);
        month++;
        if (month > 12)
        {
            year++;
            month = 1;
        }
    }
}

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int year, month, day, days;
        cin >> year >> month >> day >> days;
        add_days(year, month, day, days);
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}

//https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d?tpId=40&&tqId=31013&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking