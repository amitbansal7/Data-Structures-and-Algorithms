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

// Check if a tree is binary search tree or not
struct Node* Newnode(int n)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->right = temp->left = NULL;

	return temp;
}
int BstUtil(struct Node* root,int minv,int maxv)
{
	if(root==NULL)
		return true;

	if(root->data<=minv && root->data>maxv && 
		BstUtil(root->left,minv,root->data)
		&& BstUtil(root->right,root->data,maxv))

		return true;
	else
		return false;

}
int isBinarySearchTree(struct Node* root)
{
	int INT_MIN = 0;
	int INT_MAX = 100000;
	if(root==NULL)
		return true;
	return BstUtil(root,INT_MIN,INT_MAX);

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