#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"
BTNode* BuyTreeNode(BTDataType x)
{
	BTNode* TreeNode = (BTNode*)malloc(sizeof(BTNode));
	if (TreeNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	TreeNode->_data = x;
	TreeNode->_left = TreeNode->_right = NULL;
	return TreeNode;
}
//ǰ����� �� + ������ + ������
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%d ", root->_data);
	InOrder(root->_right);
}
//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%d ", root->_data);
}
// �������ڵ���� ������+������+��
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) ;
	
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right)
		return right;
	return NULL;
} 