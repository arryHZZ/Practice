#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"BinaryTree.h"
#include<malloc.h>
#include<assert.h>


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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

//销毁二叉树
void BinaryTreeDestory(BTNode** root)
{
	//assert(root);
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

//返回二叉树的大小
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

//查找
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root && root->_data == x)
	{
		return root->_data;
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

// 遍历
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

void test()
{
	int count = 0;
	BTDataType arr[] = "ABD##E#H##CF##G##";
	BTNode*head =  BinaryTreeCreate(arr, sizeof(arr)/sizeof(arr[0]), &count);
	int num = BinaryTreeSize(head);
	BTDataType date = BinaryTreeFind(head, 'Y');
	printf("%d\n", num);
	printf("%c\n", date);
	BinaryTreePrevOrder(head);
	printf("\n");
	BinaryTreeInOrder(head);
	printf("\n");
	BinaryTreePostOrder(head);
	printf("%d", BinaryTreeLeafSize(head));


	
	
	//销毁
	//BinaryTreeDestory(&head);
}

int main()s
{
	test();
	return 0;
}