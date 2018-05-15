/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
}*head;

void arraypass(int *arr, int low, int high);
void arraytotree(int data);
struct node * convert_array_to_bst(int *arr, int len){
	if (arr==NULL||len<=0)
	return NULL;
	else
	{

		head = NULL;
		arraypass(arr, 0, len - 1);
		return head;
	}
}
void arraypass(int *arr, int low, int high)
{
	int i;
	if (low <= high)
	{
		i = (low + high) / 2;
		arraytotree(arr[i]);
		arraypass(arr, low, i - 1);
		arraypass(arr, i + 1, high);
	}
}
void arraytotree(int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	struct node *temp;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	if (head == NULL)
	{
		head = n;
	}
	else
	{
		temp = head;
		while (1)
		{
			if (temp->data > data)
			{
				if (temp->left == NULL){ temp->left = n; break; }
				else{ temp = temp->left; }
			}
			else
			{
				
					if (temp->right == NULL){ temp->right = n; break; }
					else{ temp = temp->right; }
			}
		}
	}
}


