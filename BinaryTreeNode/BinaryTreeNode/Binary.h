#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int BTDataType;
//typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* CreateNode(BTDataType x);
// ������ǰ�����
void PreOrder(BTNode* root);
// �������������
void InOrder(BTNode* root);
// �������������
void PostOrder(BTNode* root);
//�������
void LevelOrder(BTNode* root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// ����������
void BinaryTreeDestory(BTNode** root);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);