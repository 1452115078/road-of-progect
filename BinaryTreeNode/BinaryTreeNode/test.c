#define _CRT_SECURE_NO_WARNINGS
#include "Binary.h"
#include "Queue.h"

void BinaryTest1()
{
	BTNode* node1 = CreateNode(1);
	BTNode* node2 = CreateNode(2);
	BTNode* node3 = CreateNode(3);
	BTNode* node4 = CreateNode(4);
	BTNode* node5 = CreateNode(5);
	BTNode* node6 = CreateNode(6);
	BTNode* tmp;

	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;
	PreOrder(node1);
	printf("\n");
	InOrder(node1);
	printf("\n");
	PostOrder(node1);
	printf("\n");
	LevelOrder(node1);
	printf("\n");
	printf("%d\n", BinaryTreeSize(node1));
	printf("%d\n", BinaryTreeLeafSize(node1));
	printf("%d\n", BinaryTreeLevelKSize(node1, 3));
	tmp = BinaryTreeFind(node1, 3);
	if (tmp == NULL)
		printf("no\n");
	else
		printf("%d\n", tmp->_data);
}
void BinaryTest2()
{
	char a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int sz = sizeof(a) / sizeof(a[0]);
	int pi = 0;
	BTNode* node = BinaryTreeCreate(a, sz, &pi);
	PreOrder(node);
	printf("\n");
	BinaryTreeDestory(&node);
}
void BinaryTest3()
{
	BTNode* node1 = CreateNode(1);
	BTNode* node2 = CreateNode(2);
	BTNode* node3 = CreateNode(3);
	BTNode* node4 = CreateNode(4);
	BTNode* node5 = CreateNode(5);
	BTNode* node6 = CreateNode(6);
	BTNode* node7 = CreateNode(7);

	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node2->_right = node7;
	node4->_left = node5;
	node4->_right = node6;
	
	printf("%d\n", BinaryTreeComplete(node1));
}
int main()
{
	//BinaryTest1();
	//BinaryTest2();
	BinaryTest3();

	return 0;
}

