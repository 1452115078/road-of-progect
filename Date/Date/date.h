#pragma once
#include <iostream>
#include <stdbool.h>

using namespace std;

class Date
{
public:
	void print();
	Date(int year = 1, int month = 1, int day = 1);//构造函数
	Date(const Date& d);//拷贝构造函数
	Date operator=(const Date d);
	int getmonthday(int year, int month);//获取一月的天数
	Date& operator+=(int x);
	Date operator+(int x);
	Date operator-=(int x);
	Date operator-(int x);
private:
	int _year;
	int _month;
	int _day;
};