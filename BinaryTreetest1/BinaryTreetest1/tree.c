#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include "Queue.h"
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;
	return newnode;
}
// ������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->_data);
	PreOrder(root->_left);
	PreOrder(root->_right);
}
// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->_left);
	printf("%d ", root->_data);
	InOrder(root->_right);
}
// �������������
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%d ", root->_data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->_data);
		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	QueueDestroy(&q);
}
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	BTNode* newnode = BuyNode(a[*pi]);
	if (a[*pi] == '#')
	{
		(*pi)++;
		
		return NULL;
	}
	else
	{
		(*pi)++;
		newnode->_left = BinaryTreeCreate(a, n, pi);
		newnode->_right = BinaryTreeCreate(a, n, pi);
	}
	return newnode;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	//BTNode* del = *root;
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
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
	if (left && left->_data == x)
		return left;
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right && right->_data == x)
		return right;
	return NULL;
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;

}