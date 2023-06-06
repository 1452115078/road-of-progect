#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define OFFSETOF(type,m_name) (int)(&(((type*)0)->m_name))
struct stu
{
	char c[4];
	int n;
	char b;
};
int main()
{
	//printf("%d\n", offsetof(struct stu, n));
	//printf("%d\n", offsetof(struct stu, c));
	//printf("%d\n", offsetof(struct stu, b));
	printf("%d\n", OFFSETOF(struct stu, n));
	printf("%d\n", OFFSETOF(struct stu, c));
	printf("%d\n", OFFSETOF(struct stu, b));
	return 0;
}
//#include <limits.h>
//#include <ctype.h>

//enum Station
//{
//	VAILD,    //0
//	INVAILD   //1
//};
//enum Station station = INVAILD;
//int my_atoi(char* pc)
//{
//	//"    123"
//	//"123abc"
//	//"-123"
//	//"+123"
//	//""
//	//"超出范围"
//	int flag = 0;//正数
//	if (pc == NULL)
//	{
//		return 0;
//	}
//	if (*pc == '\0')
//	{
//		return 0;
//	}
//	while (isspace(*pc))
//	{
//		pc++;
//	}
//	if (*pc == '+')
//	{
//		pc++;
//		flag = 1;
//	}
//	else if (*pc == '-')
//	{
//		pc++;
//		flag = -1;
//	}
//	long long ret = 0;
//	while (isdigit(*pc))
//	{
//		ret = ret * 10 + flag * (*pc - '0');
//		if (ret<INT_MIN || ret>INT_MAX)
//		{
//			return 0;
//		}
//		pc++;
//	}
//	if (*pc == '\0')
//	{
//		station = VAILD;
//		return (int)ret;
//	}
//	else
//	{
//		return (int)ret;
//	}
//}
//
//int main()
//{
//	int ret = my_atoi("    -123");
//	if ( station == VAILD)
//		printf("合法打印：%d\n", ret);
//	else
//		printf("非法打印：%d\n", ret);
//	return 0;
//}
//#include <string.h>
//void swap(char* str, int j , int* sz1)
//{
//	int sz = *sz1 - j;
//	for (int i = 0; i < sz - 1; i++)
//	{
//		*(str + j + i) = *(str + j + i + 1);
//	}
//	(*sz1)--;
//}
//
//int main()
//{
//	char str1[] = { "They are students." };
//	char str2[] = { "aeiou" };
//	int sz1 = strlen(str1);
//	int sz2 = strlen(str2);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz2; i++)
//	{
//		for (j = 0; j < sz1; j++)
//		{
//			if (*(str2 + i) == *(str1 + j))
//			{
//				swap(str1 , j, &sz1);
//			}
//		}
//	}
//	for (j = 0; j < sz1; j++)
//	{
//		printf("%c", *(str1 + j));
//	}
//	return 0;
//}