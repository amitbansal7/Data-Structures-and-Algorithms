#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0

struct bstNode
{
	int data;
	struct BstNode* left;
	struct BstNode* right;
};

// Find Max and Min in a BST

struct bstNode* Newnode(int n)
{
	struct bstNode* temp;

	temp = (struct bstNode*)malloc(sizeof(struct bstNode));

	temp->data = n;
	temp->right = temp->left = NULL;

	return temp;
}

int search(struct bstNode* root , int data)
{
	if(root==NULL)  
		return false;
	
	else if(root->data == data)  
		return true;

	else if(data <= root->data)
		return search(root->left,data);

	else
		return search(root->right,data);
}

struct bstNode* insert(struct bstNode* temp ,int n)
{
	if(temp==NULL){
		temp = Newnode(n);
	}

	else if(n <= temp->data)
		temp->left = insert(temp->left,n);

	else 
		temp->right = insert(temp->right,n);

	return temp;
}

int min(struct bstNode* temp )
{
	if(temp==NULL)
	{
		printf("Tree is empty!!");
		return -1;
	}

	while(temp->left!=NULL)
		temp = temp->left;

	return (temp->data);
}


int max(struct bstNode* temp)
{
	if(temp==NULL)
	{
		printf("Tree is empty!!");
		return -1;
	}
	while(temp->right!=NULL)
		temp = temp->right;

	return(temp->data);
}

int main()
{
 	struct bstNode* root;

 	int i;

 	root = NULL;
 	root = insert(root , 123);
 	root = insert(root , 20);
 	root = insert(root , 5);
 	root = insert(root , 300);
 	root = insert(root , 12);
 	root = insert(root , 100);

 	printf("Max = %d\nMax = %d\n",max(root),min(root));
 	return 0;
}