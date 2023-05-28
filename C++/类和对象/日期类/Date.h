#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
// 类里面短小函数，适合做内联的函数，直接在类里面定义。
class Date {
public:
    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);
    Date(int year = 1900, int month = 1, int day = 1);
    void Print();
    int GetMonthDay(int year, int month);
    bool operator==(const Date &d);
    bool operator!=(const Date &d);
    bool operator<(const Date &d);
    bool operator<=(const Date &d);
    bool operator>(const Date &d);
    bool operator>=(const Date &d);
    Date &operator+=(int day);
    Date operator+(int day);
    Date &operator-=(int day);
    //d1-100
    Date operator-(int day);
    //d1-d2
    int operator-(const Date &d);
    //前置++
    Date &operator++();
    //后置++
    Date operator++(int);
    //前置--    --d -> d.operator--()
    Date &operator--();
    //后置--    d--  -> d.operator--(int)
    Date operator--(int);

private:
    int _year = 1900;
    int _month = 1;
    int _day = 1;
};

ostream &operator<<(ostream &out, const Date &d);
istream &operator>>(istream &in, Date &d);