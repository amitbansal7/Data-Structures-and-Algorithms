#include "stdio.h"
#include "stdlib.h"
#define true 1
#define false 0

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
//Check if a tree is binary search tree or not

struct Node* Newnode(int n)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->right = temp->left = NULL;

	return temp;
}
void inorder(struct Node* root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int isSubTreeLesser(struct Node* root,int data)
{
	if(root==NULL)
		return  true;

	if(root->data<=data && 
		isSubTreeLesser(root->left,data) && 
		isSubTreeLesser(root->right,data))

		return true;

	else
		return false;
}

int isSubTreeGreater(struct Node* root,int data)
{
	if(root==NULL)
		return  true;

	if(root->data<=data && 
		isSubTreeGreater(root->left,data) && 
		isSubTreeGreater(root->right,data))

		return true;

	else
		return false;
}

int isBinarySearchTree(struct Node* root)
{
	if(root==NULL)
		return true;

	if(isSubTreeLesser(root->left,root->data)
		&& isSubTreeGreater(root->right,root->data)
		&& isBinarySearchTree(root->left
		&& isBinarySearchTree(root->right)))
		return true;

	else
		return false;
}
struct Node* insert(struct Node* temp ,int n)
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


int main()
{
 	struct bstNode* root;
 	root = NULL;
 	root = insert(root , 123);
 	root = insert(root , 20);
 	root = insert(root , 5);
 	root = insert(root , 300);
 	root = insert(root , 12);
 	root = insert(root , 100);


 	if(isBinarySearchTree)
 		printf("TRUE");
 	else
 		printf("FALSE");
}