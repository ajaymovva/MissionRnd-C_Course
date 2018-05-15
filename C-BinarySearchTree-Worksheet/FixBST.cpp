/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void fixbstdata(struct node *root, struct node **f1, struct node **f2, struct node **f3, struct node **pre);
void fix_bst(struct node *root){
	if (root != NULL)
	{
		struct node *f1, *f2, *f3, *pre;
		int i;
		f1 = f2 = f3 = pre = NULL;
		fixbstdata(root, &f1, &f2, &f3, &pre);
		if (f1&&f3)
		{
			i = f1->data;
			f1->data = f3->data;
			f3->data = i;
		}
		else if (f1&&f2)
		{
			i = f1->data;
			f1->data = f2->data;
			f2->data = i;
		}
	}
}
void fixbstdata(struct node *root, struct node **f1, struct node **f2, struct node **f3, struct node **pre)
{
	if (root != NULL)
	{
		fixbstdata(root->left, f1, f2, f3, pre);
		if (*pre != NULL && (*pre)->data > root->data)
		{
			if (*f1 == NULL){ *f1 = *pre; *f2 = root; }
			else{ *f3 = root; }
		}
		*pre = root;
		fixbstdata(root->right, f1, f2, f3, pre);
	}
}
