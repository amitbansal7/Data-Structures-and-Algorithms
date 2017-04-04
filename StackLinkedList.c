#include "stdio.h"
#include "stdlib.h"
#define MAXS 101

//Stack-linked list implementation

struct Node{

	int data;
	struct Node* next;
};

struct Node* top;

void push(int x)
{
	struct Node* temp;
	temp = (struct node*)malloc(sizeof(struct Node));

	temp->data = x;
	temp->next = top;
	top = temp;
}

void pop()
{
	if(top==NULL){
		printf("Error: Stack is empty");
		return;
	}

	struct Node* temp;
	temp = top;
	temp = temp->next;
	top = temp;
}

void printstack()
{
	struct Node* temp;
	
	temp = top;

	printf("Satck: ");

	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}

	printf("\n");
}

void reverse()
{

}
int main()
{
	top = NULL;

	push(6);
	printstack();
	push(3);
	printstack();
	push(4);
	printstack();
	pop();
	printstack();

}