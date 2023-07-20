#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
BTNode* BuyTreeNode(BTDataType x);//������
//ǰ����� 
void PrevOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
