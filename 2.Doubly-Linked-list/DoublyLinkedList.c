#include "stdio.h"
#include "stdlib.h"
//Doubly Linked List
struct Node
{
	struct Node* prev;
	int data;
	struct Node* next;
		
};
struct Node* head;

void insertatend(int x)
{
	struct Node *temp,*p;
	temp = (struct Node*)malloc(sizeof(struct Node));
	p = (struct Node*)malloc(sizeof(struct Node));

	temp->data = x;
	p=head;

	temp->next = NULL;

	while(p->next!=NULL)
		p = p->next;

	p->next = temp;
	temp->prev = p;
}

void insertatbeg(int x)
{
	struct Node* temp;
	temp  = malloc(sizeof(struct Node));

	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;

	if(head==NULL)
	{
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;

}
void printlist(struct Node* temp)
{
	if(temp==NULL)
		return;

	printf("%d ",temp->data);
	printlist(temp->next);
}

void reverseprint()
{
	struct Node* temp;
	temp = (struct Node*) malloc(sizeof(struct Node));

	temp = head;

	while(temp->next!=NULL)
		temp = temp->next;

	while(temp!=NULL)
	{	printf("%d ",temp->data);
		temp = temp->prev;
	}
}

int main()
{
	int x,n,i;
	head = NULL;

	printf("How many numbers? ");
	scanf("%d",&n);

	scanf("%d",&x);

	insertatbeg(x);

	for(i=0;i<n-1;i++)
	{
		scanf("%d",&x);
		insertatbeg(x);
	}

	printlist(head);

	printf("\nREVERSE PRINT :");
	reverseprint();

}