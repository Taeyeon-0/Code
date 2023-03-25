#include <iostream>
using namespace std;

int day_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main()
{
    int year, day_of_year;
    while (cin >> year >> day_of_year)
    {
        // 判断是否为闰年，从而决定2月的天数
        if (is_leap_year(year))
        {
            day_in_month[2] = 29;
        }
        else
        {
            day_in_month[2] = 28;
        }

        int month = 1;
        int sum = 0;
        sum += day_in_month[1];
        
        while (day_of_year > sum)
        {
            month++;
            sum += day_in_month[month];
        }

        int day = day_of_year - (sum - day_in_month[month]);
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
//https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking