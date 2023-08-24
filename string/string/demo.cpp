#define _CRT_SECURE_NO_WARNINGS
#include "string.h"

int main()
{
	try 
	{
		CC::test_string10();
	}
	catch(const exception& e1)
	{
		cout << e1.what() << endl;
	}
	return 0;
}
//int main()
//{
//	std::string s1;
//	CC::string s2;
//	cout << sizeof(s1) << endl;
//	cout << sizeof(s2) << endl;
//	std::string s3("hello world");
//	CC::string s4("hello world");
//	cout << sizeof(s3) << endl;
//	cout << sizeof(s4) << endl;
//	return 0;
//}