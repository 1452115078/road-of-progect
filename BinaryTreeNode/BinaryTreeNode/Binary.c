#define _CRT_SECURE_NO_WARNINGS
#include "Binary.h"
#include "Queue.h"
BTNode* CreateNode(BTDataType x)
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
		return;
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
//�������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->_data);
 		QueuePop(&q);

		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
	QueueDestroy(&q);
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
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (left)
		return left;
	if (right)
		return right;
}
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* perordercreatetree(BTDataType* a, int* pi)
{
	if (a[(*pi)] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->_data = a[(*pi)++];
	newnode->_left = perordercreatetree(a, pi);
	newnode->_right = perordercreatetree(a, pi);
	return newnode;
}
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{	
	BTNode* root = perordercreatetree(a, pi);
	return root;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
}
// �ж϶������Ƿ�����ȫ������
bool isLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		//printf("%d ", front->_data);
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
bool BinaryTreeComplete(BTNode* root)
{
	return isLevelOrder(root);
}