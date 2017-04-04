#include "stdio.h"
#include "stdlib.h"
#define MAXS 101

//reverse a string using stack & linked list
struct Node{
	char data;
	struct Node* next;
};

struct Node* top;

void push(char c)
{ 
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = c;
	temp->next = top;
	top = temp;
}

char pop()
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = top->data;
	top = top->next;

	return(temp->data);

}

void printstack()
{
	struct Node* temp;
	temp = top;

	while(temp!=NULL)
	{
		printf("%c",temp->data);
		temp = temp->next;
	}
}

int main()
{
	char c[50];
	int i=0;
	top = NULL;
	int  n= strlen(c);

	printf("Enter a string : ");
	gets(c);

	while(c[i]!='\0')
	{
		push(c[i++]);
	}

	for(int i=0;i<n;i++)
		c[i] = pop();

	printf("%s",c);
}