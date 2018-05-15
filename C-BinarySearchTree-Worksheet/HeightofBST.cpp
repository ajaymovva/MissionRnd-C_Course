/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void getheightwrap(struct node *root, int i, int *j);
void getleftsum(struct node *root, int *sum);
void getrightsum(struct node *root, int *sum);
int get_height(struct node *root){
	if (root==NULL)
	return 0;
	else
	{
		int i=0, j=0;
		getheightwrap(root, i, &j);
		return j;
	}
}

int get_left_subtree_sum(struct node *root){
	if (root==NULL)
	return -1;
	else
	{
		int sum = 0;
		getleftsum(root->left, &sum);
		return sum;
	}
}

int get_right_subtree_sum(struct node *root){
	if (root == NULL)
		return -1;
	else
	{
		int sum = 0;
		getrightsum(root->right, &sum);
		return sum;
	}
}
void getheightwrap(struct node *root, int i, int *j)
{
	if (root == NULL)
	{
		if (i > *j){ *j = i; }
	}
	else
	{
		getheightwrap(root->left,i+1 , j);
		getheightwrap(root->right, i + 1, j);
	}
}
void getleftsum(struct node *root, int *sum)
{
	if (root != NULL)
	{
		getleftsum(root->left, sum);
		*sum = *sum + (root->data);
		getleftsum(root->right,sum);
	}
}
void getrightsum(struct node *root, int *sum)
{
	if (root != NULL)
	{
		getrightsum(root->left, sum);
		*sum = *sum + (root->data);
		getrightsum(root->right, sum);
	}
}
