#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include "Queue.h"

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	//BTNode* node7 = BuyNode(7);
	//BTNode* node8 = BuyNode(8);

	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	//node2->_right = node7;
	//node3->_left = node7;
	//node3->_right = node8;
	node4->_left = node5;
	node4->_right = node6;
	return node1;
}
void BinaryTreeTest1()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("%d\n", BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root, 15));
	BTNode* tmp = BinaryTreeFind(root, 6);
	if (tmp)
		printf("%d\n", tmp->_data);
	else
		printf("NULL");
	printf("%d\n", BinaryTreeComplete(root));
	BinaryTreeDestory(&root);
}
void BinaryTreeTest2()
{
	char a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int sz = sizeof(a) / sizeof(a[0]);
	int i = 0;
	BTNode* tmp = BinaryTreeCreate(a, sz, &i);
	PreOrder(tmp);
}
int main()
{
	BinaryTreeTest1();
	//BinaryTreeTest2();
	return 0;
}