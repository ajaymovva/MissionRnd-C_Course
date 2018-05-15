/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorderwrap(struct node *root, int *arr, int *p)
{
	if (root != NULL)
	{
		inorderwrap(root->left, arr, p);
		arr[*p] = root->data;
		(*p)++;
		inorderwrap(root->right, arr, p);
	}
}
void preorderwrap(struct node *root, int *arr, int *p)
{
	if (root != NULL)
	{
		arr[*p] = root->data;
		(*p)++;
		preorderwrap(root->left, arr, p);
		preorderwrap(root->right, arr, p);
	}
}
void postorderwrap(struct node *root, int *arr, int *p)
{
	if (root != NULL)
	{
		postorderwrap(root->left, arr, p);
		postorderwrap(root->right, arr, p);
		arr[*p] = root->data;
		(*p)++;
	}
}
void inorder(struct node *root, int *arr){
	if (root != NULL&&arr != NULL)
	{
		int i = 0;
		inorderwrap(root, arr, &i);
	}
}
void preorder(struct node *root, int *arr){
	if (root != NULL&&arr != NULL)
	{
		int i = 0;
		preorderwrap(root, arr, &i);
	}
	
}
void postorder(struct node *root, int *arr){
	if (root != NULL&&arr != NULL)
	{
		int i = 0;
		postorderwrap(root, arr, &i);
	}
}

