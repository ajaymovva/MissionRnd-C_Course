/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

void merge(struct BstNode *root1, struct BstNode *root2, struct BstNode **parent1, int i);
void secondtree(struct BstNode **root1, struct BstNode *root2, struct BstNode *parent, struct BstNode **parent1);
void parentfind(int k, struct BstNode *parent, struct BstNode**parent1, int *i);
void merge_two_bst(struct BstNode **root1, struct BstNode *root2) {
	if (*root1 != NULL&&root2 != NULL)
	{
		struct BstNode *parent;
		struct BstNode **parent1;
		parent = root2;
		parent1 = &root2;
		secondtree(root1,root2,parent,parent1);
	}
	else if (*root1 == NULL)
	{
		*root1 = root2;
	}
	
}
void secondtree(struct BstNode **root1, struct BstNode *root2, struct BstNode *parent, struct BstNode **parent1)
{
	if (root2 != NULL)
	{
		secondtree(root1, root2->left,parent,parent1);
		secondtree(root1, root2->right,parent,parent1);
		int i = 0,k=0;
		parentfind(root2->data, parent, parent1,&i);
			if (i == 1)
			{
				(*parent1)->left = NULL;
			}
			else
			{
				(*parent1)->right = NULL;
			}
			merge(*root1, root2, parent1, i);
	}
}
void merge(struct BstNode *root1,struct BstNode *root2,struct BstNode **parent1,int i)
{
	if (root1->left==NULL||root1->right==NULL)
	{
			if (root1->left == NULL&&root1->right == NULL)
			{
				if (root1->data > root2->data){ root1->left = root2; }
				else if (root1->data < root2->data){ root1->right = root2; }
			}
			else  if (root1->left == NULL)
			{
				if (root1->data > root2->data){ root1->left = root2; }
				else if (root1->data < root2->data){ merge(root1->right, root2, parent1, i); }
			}
			 else if (root1->right == NULL)
			{
				if (root1->data < root2->data){ root1->right = root2; }
				else if (root1->data > root2->data){ merge(root1->left, root2, parent1, i); }
			}
		}
	else
	{
		if (root1->data < root2->data){	
				root1 = root1->right;
				merge(root1, root2,parent1,i);
		}
		else if (root1->data > root2->data)
		{
				root1 = root1->left;
				merge(root1, root2,parent1,i);
		}
	}
}
void parentfind(int k, struct BstNode *parent, struct BstNode**parent1,int *i)
{
	while (1)
	{
		if (parent->data!=k)
		{
			if (parent->data > k)
			{
				*parent1 = parent; *i = 1;
				parent = parent->left;
			}
			else if (parent->data < k)
			{
				*parent1 = parent; *i = 2;
				parent = parent->right;
			}
		}
		else
		{
			break;
		}
	}
}