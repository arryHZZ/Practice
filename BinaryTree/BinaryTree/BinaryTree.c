#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"BinaryTree.h"
#include<malloc.h>
#include<assert.h>

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (n == 0)
		return NULL;
	if (a[*pi]!= '#')
	{
		BTNode* Node = (BTNode*)malloc(sizeof(BTNode));
		Node->_data = a[*pi];
		++(*pi);
		Node->_left = BinaryTreeCreate(a, n, pi);
		++(*pi);
		Node->_right = BinaryTreeCreate(a, n, pi);
		return Node;
	}
	else
	{
		return NULL;
	}
		
}

//���ٶ�����
void BinaryTreeDestory(BTNode** root)
{
	if ((*root)->_left)
	{
		BinaryTreeDestory(&(*root)->_left);
		free(*root);
		*root = NULL;
	}
	else if ((*root)->_right)
	{
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
	else
		return;
}

//���ض������Ĵ�С
int BinaryTreeSize(BTNode* root)
{
	if (root)
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
	}
	else
	{
		return 0;
	}
}
//
int BinaryTreeLeafSize(BTNode* root)
{
	int max = 0;
	int left = 0;
	int right = 0;
	if (root->_left)
	{
		left++;
		return BinaryTreeLeafSize(root->_left) + 1;
	}
	if (root->_right)
	{
		right++;
		return BinaryTreeLeafSize(root->_right) + 1;
	}
	max = left > right ? left : right;
	return max;

}
int BinaryTreeLevelKSize(BTNode* root, int k);

//����
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root && root->_data == x)
	{
		return root;
	}
	if (root->_left)
	{
		BinaryTreeFind(root->_left, x);
	}
	if (root->_right)
	{
		BinaryTreeFind(root->_right, x);
	}
	return NULL;
}

// ����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
		//printf("\n");
	}
	else
	{
		printf("# ");
	}
	
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	else
	{
		printf("# ");
	}
	
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	else
	{
		printf("# ");
	}
}
void BinaryTreePostOrderNor(BTNode* root)
{
	BTNode* arr[10] = { 0 };
	int i = 0;
	arr[i++] = root;
	while (root)
	{
		while (root)
		{
			arr[i++] = root;
			root = root->_left;
			
		}
		if (!root)
		{
			root = arr[--i];
			printf("%c ", root->_data);
			root = arr[i]->_right;
		}

	}
}

//��ֵ������
int isUnivalTree(BTNode* root){
	if (root->_left)
	{
		if (root->_data != root->_left->_data || !isUnivalTree(root->_left))
			return 0;
	}
	if (root->_right)
	{
		if (root->_data != root->_right->_data || isUnivalTree(root->_right))
			return 0;
	}
	return 1;
}

//������Ƿ�Գ�
int isSymmetric(BTNode* left, BTNode* right)
{
	if (right == NULL && left == NULL)
		return 1;
	if (right == NULL || left == NULL)
		return 0;
	if ((right->_data == left->_data)
		&& isMetic(right->_right, left->_left)
		&& isMetic(right->_left, left->_right))
		return 1;
	else
		return 0;
}

void test()
{
	int count = 0;
	BTDataType arr[] = "111##1##1#1##";
	BTNode*head =  BinaryTreeCreate(arr, sizeof(arr)/sizeof(arr[0]), &count);
	int num = BinaryTreeSize(head);
	BinaryTreePrevOrder(head);
	printf("\n");
	BinaryTreeInOrder(head);
	printf("\n");
	BinaryTreePostOrder(head);
	printf("%d\n", BinaryTreeLeafSize(head));
	BinaryTreePostOrderNor(head);
	printf("%d", isUnivalTree(head));
	//����
	//BinaryTreeDestory(&head);
}

int main()
{
	test();
	return 0;
}