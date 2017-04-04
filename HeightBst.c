#include <stdio.h>
#include "math.h"

struct bstnode{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
//Find Height of a binary Search Tree.
struct bstnode* newnode(int n)
{
	struct bstnode* temp;
	temp = (struct bstnode*)malloc(sizeof(struct bstnode));
	temp->data = n;
	temp->left = temp->right = NULL;

	return temp;
}

struct bstnode* insert(struct bstnode* root ,int data)
{
	if(root==NULL)
		root = newnode(data);

	else if(data <= root->data)
		root->left  = insert(root->left , data);

	else
		root->right = insert(root->right , data);

	return root;
}
int max(int x,int y)
{
	return(x>y?x:y);
}

int findheight(struct bstnode* root)
{
	if(root==NULL)
		return -1;

	return((max(findheight(root->left),findheight(root->right)))+1);
}

int main()
{
	struct bstnode* root;
	root = NULL;
	root = insert(root,6);
	root = insert(root,12);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,34);
	root = insert(root,56);
	root = insert(root,2);
	printf("Height = %d \n",findheight(root));
	return 0;
}
