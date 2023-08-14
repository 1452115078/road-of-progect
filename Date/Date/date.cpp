#define _CRT_SECURE_NO_WARNINGS
#include "date.h"
void Date::print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
	
}
//构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
//拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date Date::operator=(const Date d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
int Date::getmonthday(int year, int month)
{
	int getmonthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return getmonthday[month];
}
//运算符重载+=
Date& Date::operator+=(int x)
{
	_day += x;
	while (_day > getmonthday(_year, _month))
	{
		_day -= getmonthday(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}
//+
Date Date::operator+(int x)
{
	Date tmp = *this;
	tmp._day += x;
	while (tmp._day > getmonthday(tmp._year, tmp._month))
	{
		tmp._day -= getmonthday(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			++tmp._year;
			tmp._month = 1;
		}
	}
	return tmp;
}
Date Date::operator-=(int x)
{
	_day -= x;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += getmonthday(_year, _month);
	}
	return *this;
}
Date Date::operator-(int x)
{
	Date tmp(*this);
	tmp._day -= x;
	while (tmp._day <= 0)
	{
		--tmp._month;
		if (tmp._month == 0)
		{
			--tmp._year;
			tmp._month = 12;
		}
		tmp._day += getmonthday(tmp._year, tmp._month);
	}
	return tmp;
}