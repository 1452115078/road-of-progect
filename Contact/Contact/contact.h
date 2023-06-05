#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define INT_CAPACITY 3
#define INT_SZ 2
#define MAX_DATA 100

#define MAX_NAME 20
#define MAX_TELEPHONE 20
#define MAX_ADDRESS 20

struct Peopinfo 
{
	char name[MAX_NAME];
	int age;
	char tele[MAX_TELEPHONE];
	char address[MAX_ADDRESS];
};
//静态版本
//struct Contact
//{
//	struct Peopinfo data[MAX_DATA];
//	int sz;
//};
//动态版本
struct Contact
{
	struct Peopinfo* data;
	int sz;//现有联系人数量
	int capacity;//容量
};
void init_contact(struct Contact* pc);
void add_contact(struct Contact* pc);
void show_contact(const struct Contact* pc);
void deleate_contact(struct Contact* pc);
void search_contact(const struct Contact* pc);
void modify_contact(struct Contact* pc);
void sort_contact(struct Contact* pc);
void destory_contact(struct Contact* pc);

void savecontact(struct Contact* pc);
