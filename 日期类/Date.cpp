#include"Date.h"
int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);

	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	if (_month > 0 && _month < 13
		&& (_day > 0 && _day <= GetMonthDay(_year, _month)))
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	else
	{
		cout << "日期非法" << endl;
	}
}

bool Date::operator ==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator !=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator <(const Date& d)
{
	return _year < d._year
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}

bool Date::operator <=(const Date& d)
{
	return *this < d || *this == d;
}

bool Date::operator >(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator >=(const Date& d)
{
	return !(*this < d);
}

//d1 = d2+=100
Date& Date::operator+=(int day)
{
	//如果day为负数呢，那就是-=day的逻辑了
	if (day < 0)
	{
		*this -= -day;   //day为负数，-=day  要将day转换成-day
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;  //出了作用域还在可以使用引用返回
}

//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//	tmp._day += day;
//	//这里用while因为可能出现比月份大好几倍，要进行好几次进位
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month == 13)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//	}
//	return tmp; //出了作用域就销毁了,不能用引用返回
//}

//可以简化，可以调用+的重载来实现+=
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;

	return tmp;
} 
//-=  需要借位
Date& Date::operator-=(int day)
{
	//-=如果day如果是负数，那就变了+=
	if (day < 0)
	{
		*this += -day;  //day是负数，-day就变成了正数
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		//day为负的，加的正数为止，借位就结束了
		_day += GetMonthDay(_year, _month);
	}
	return *this;
} 

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

//d1-d2
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}

//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;  //对象已经加了1
	return tmp;  //返回的是tmp
}
//前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)  //流提取
{
	in >> d._year >> d._month >> d._day;
	return in;
}