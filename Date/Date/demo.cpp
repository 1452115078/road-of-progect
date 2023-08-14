#define _CRT_SECURE_NO_WARNINGS
#include "date.h"
void TestDate1()
{
	Date d1(2023, 2, 4);
	d1.print();
	//d1 -= 100;
	//d1.print();
	Date d2 = d1 - 100;
	d2.print();
	d1.print();
}
int main()
{
	TestDate1();
	return 0;
}