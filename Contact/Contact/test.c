#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void menu()
{
	printf("***0.exit      1.add    **********\n");
	printf("***2.dele      3.search **********\n");
	printf("***4.modify    5.show   **********\n");
	printf("***6.sort      0.exit   **********\n");
}
enum option
{
	EXIT,
	ADD,
	DELEATE,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	int input = 0;
	struct Contact con;//创建
	init_contact(&con);
	do
	{
		menu();
		printf("please enter options>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DELEATE:
			deleate_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case EXIT:
			savecontact(&con);
			printf("保存文件成功\n");
			destory_contact(&con);
			printf("exit programe\n");
			break;
		default:
			printf("enter fault\n");
			break;
		}
	} while (input);
	return 0;
}