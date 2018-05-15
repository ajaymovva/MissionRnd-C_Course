/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
void leastheight(struct node *root, int j, int *i);
int search(struct node *root, struct node *temp, int i);
int search1(struct node *root, struct node *temp);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL){ return -1; }
	else
	{
		int i, j,l1,l2,l3,l4; i = 1, j = 1;
		/*leastheight(root->left,j, &i);
		l1 = i;
		i = 1, j = 1;
		leastheight(root->right, j, &i);
		l2 = i; */
		i = 0; j = 0;
		leastheight(temp, j, &i);
		l3 = i;
		i = 0;
		l4 = search1(root, temp);
		/*if (root->data > temp->data){ i = l2; }
		else{ i = l1; }
		if ((i+l4) < l3){ return i+l4; }
		else{ return l3; }*/
		if (l4 < l3){ return l4; }
		else{ return l3; }
	}
}
void leastheight(struct node *root, int j, int *i)
{
	if (root != NULL)
	{
		if (root->left == NULL&&root->right == NULL)
		{
			if (j < *i || *i == 0){ *i = j; }
		}
		else
		{
			leastheight(root->left, j + 1, i);
			leastheight(root->right, j + 1, i);
		}
	}
}
int search(struct node *root, struct node *temp,int i)
{
	while (root != temp)
	{
		if (root->data > temp->data)
		{
			root = root->left; 
		}
		else
		{
			root = root->right;
		}
		i++;
	}
	return i;
}
int search1(struct node *root, struct node *temp)
{
	int k, j,p;
	struct node *temp1=NULL;
	while (root != temp)
	{
		if (root->data > temp->data)
		{
			 k = 0, j = 0;
			leastheight(root, j, &k);
			if (p == 0 || k < p){ p = k; temp1 = root; }
			root = root->left;
		}
		else
		{
			k = 0, j = 0;
			leastheight(root, j, &k);
			if (p == 0 || k < p){ p = k; temp1 = root; }
			root = root->right;
		}
	}
	j = 0;
	k=search(temp1, temp, j);
	return (p + k);
}