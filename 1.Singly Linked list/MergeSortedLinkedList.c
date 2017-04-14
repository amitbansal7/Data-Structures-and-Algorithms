#include "stdio.h"
#include "assert.h"

struct Node
{
	int data;
	struct Node* next;
};
//Merge Two Sorted Linked List

struct Node* mergeSortedlist(struct Node* a,struct Node* b)
{
	struct Node* result = NULL;

	if(a==NULL)
		return b;

	if(b==NULL)
		return a;

	if(a->data <=b->data)
	{
		result = a;
		result->next = mergeSortedlist(a->next,b);
	}

	else
	{
		result = b;
		result->next = mergeSortedlist(a,b->next);
	}

	return(result);
}

struct Node* insertatend(struct Node* head,int n)
{
	struct Node*temp,*p;
	temp  =(struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = NULL;
	p = head;

	while(p->next!=NULL)
		p = p->next;

	p->next = temp;

	return head;
}
void traverse(struct Node* head)
{
	if(head==NULL)
		return;

	printf("%d ",head->data);
	traverse(head->next);
}
struct Node* insertatbeg(struct Node* head,int n)
{
	struct Node* temp;

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = head;
	head = temp;

	return head;
}

int main()
{
	struct Node* ahead = NULL;
	struct Node* bhead = NULL;
	struct Node* chead = NULL;

	ahead = insertatbeg(ahead,1);
	ahead = insertatend(ahead,3);
	ahead = insertatend(ahead,5);
	ahead = insertatend(ahead,7);

	bhead = insertatbeg(bhead,2);
	bhead = insertatend(bhead,4);
	bhead = insertatend(bhead,6);
	bhead = insertatend(bhead,8);

	printf("\nLIST A IS :  ");traverse(ahead);
	printf("\nLIST B IS :  ");traverse(bhead);

	chead = mergeSortedlist(ahead,bhead);

	printf("\nLIST C IS :  ");traverse(chead);

}