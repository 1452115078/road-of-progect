#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"
void BinaryTreeTest1()
{
	BTNode* n1 = BuyTreeNode(1);
	BTNode* n2 = BuyTreeNode(2);
	BTNode* n3 = BuyTreeNode(3);
	BTNode* n4 = BuyTreeNode(4);
	BTNode* n5 = BuyTreeNode(5);
	BTNode* n6 = BuyTreeNode(6);
	//BTNode* n7 = BuyTreeNode(7);
	//BTNode* n8 = BuyTreeNode(8);
	n1->_left = n2;
	n1->_right = n4;
	n2->_left = n3;
	n4->_left = n5;
	n4->_right = n6;
	//n3->_left = n7;
	//n3->_right = n8;

	PrevOrder(n1);
	printf("\n");
	InOrder(n1);
	printf("\n");
	PostOrder(n1);
	printf("\n");
	printf("%d\n", BinaryTreeSize(n1));
	printf("%d\n", BinaryTreeSize(n1));
	printf("%d\n", BinaryTreeSize(n1));

	printf("%d\n", BinaryTreeLeafSize(n1));
	printf("%d\n", BinaryTreeLevelKSize(n1, 3));
	BTNode* tmp = BinaryTreeFind(n1, 52);
	if (tmp == NULL)
		printf("no\n");
	else
		printf("%d\n", tmp->_data);
}
int main()
{
	BinaryTreeTest1();
}