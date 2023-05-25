#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//静态版本
//void init_contact(struct Contact* pc)
//{
//	assert(pc);
//	memset(pc->data, 0, MAX_DATA * sizeof(struct Peopinfo));
//	pc->sz = 0;
//}
//动态版本
void init_contact(struct Contact* pc)
{
	assert(pc);
	pc->data = (struct Peopinfo*)malloc(INT_CAPACITY * sizeof(struct Peopinfo));
	if (pc->data == NULL)
	{
		perror("init_contact fail\n");
	}
	pc->sz = 0;
	pc->capacity = INT_CAPACITY;
}
void destory_contact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}
//void add_contact(struct Contact* pc)
//{
//	assert(pc);
//	if (pc->sz == 100)
//	{
//		printf("contact empty，please deleate\n");
//		return;
//	}
//	else
//	{
//		printf("please enter data>\n");
//		printf("请输入姓名>");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("请输入年龄>");
//		scanf("%d", &(pc->data[pc->sz].age));
//		printf("请输入电话>");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("请输入住址>");
//		scanf("%s", pc->data[pc->sz].address);
//	}
//	pc->sz++;
//}
// 
int check_capacity(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct Peopinfo* ptr = (struct Peopinfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct Peopinfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INT_SZ;
			printf("增容成功\n");
			return 1;
		}
		else
		{
			perror("realloc fail\n");
			return 0;
		}
	}
	else
		return 1;
}

//动态版本
void add_contact(struct Contact* pc)
{
	assert(pc);
	if (check_capacity(pc) == 0)
	{
		printf("增加失败\n");
		return;
	}
	printf("please enter data>\n");
	printf("请输入姓名>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入住址>");
	scanf("%s", pc->data[pc->sz].address);
	pc->sz++;
	printf("增加成功\n");
}
void show_contact(const struct Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-20s\t%-20s\n", "姓名", "年龄", "电话", "住址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-20s\t%-20s\n", pc->data[i].name, 
											pc->data[i].age, 
											pc->data[i].tele, 
											pc->data[i].address);
	}
}
static int Findbyname(const struct Contact* ptr, char* name)
{
	
	assert(ptr);
	int i = 0;
	for (i = 0; i < ptr->sz; i++)
	{
		if (0 == (strcmp(name, ptr->data[i].name)))
		{
			return i;
		}
	}
	return -1;
}
void deleate_contact(struct Contact* pc)
{
	assert(pc);
	int i = 0;
	char name[MAX_NAME];
	printf("please enter deleate name>");
	scanf("%s", name);
	int ret = Findbyname(pc,name);
	if (ret == -1)
	{
		printf("要删除的联系人不存在\n");
	}
	else
	{
		//成功找到并删除
		for (i = ret; i < pc->sz; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}
void search_contact(const struct Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("please enter data>");
	scanf("%s", name);
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("查找失败\n");
	}
	else
	{
		printf("查找成功\n");
		printf("%-20s\t%-5s\t%-20s\t%-20s\n", "姓名", "年龄", "电话", "住址");
		printf("%-20s\t%-5d\t%-20s\t%-20s\n", pc->data[ret].name,
											pc->data[ret].age,
											pc->data[ret].tele,
											pc->data[ret].address);
	}
}
void OPTIONS()
{
	printf("***1.name      2.age    **********\n");
	printf("***3.tele      4.address **********\n");
}

void modify_contact(struct Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要修改人的名字>");
	scanf("%s", name);
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("此人不存在，修改失败\n");
	}
	else
	{
		int input = 0;
		////查找成功修改整体
		//printf("please enter data>\n");
		//printf("请输入姓名>");
		//scanf("%s", pc->data[ret].name);
		//printf("请输入年龄>");
		//scanf("%d", &(pc->data[ret].age));
		//printf("请输入电话>");
		//scanf("%s", pc->data[ret].tele);
		//printf("请输入住址>");
		//scanf("%s", pc->data[ret].address);
		//printf("success\n");
		//查找成功修改部分
		OPTIONS();
		printf("请输入要修改的选项>");
		scanf("%d", &input);
		switch (input)
		{
		case1:
			printf("请输入姓名>");
			scanf("%s", pc->data[ret].name);
			printf("success\n");

			break;
		case 2:
			printf("请输入年龄>");
			scanf("%d", &(pc->data[ret].age));
			printf("success\n");
			break;
		case 3:
			printf("请输入电话>");
			scanf("%s", pc->data[ret].tele);
			printf("success\n");
			break;
		case 4:
			printf("请输入住址>");
			scanf("%s", pc->data[ret].address);
			printf("success\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}
}
int cmpby_age(const void* e1, const void* e2)
{
	return ((struct Peopinfo*)e1)->age - ((struct Peopinfo*)e2)->age;
}
void sort_contact(struct Contact* pc)
{
	assert(pc);
	qsort(pc,pc->sz, sizeof(struct Peopinfo), cmpby_age);
	printf("排序成功");
}
