#include "stdio.h"
#include "math.h"

// Adding two numbers represented by linked lists and storing 
// result in a linked list
struct Node
{
	int data;
	struct Node* next;
};

void traverse(struct Node* head)
{	//Printing list in backward order
	if(head==NULL)
		return;
	traverse(head->next);
	printf("%d ",head->data);
	
}

struct Node* insertatbeg(struct Node* head,int n)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = n;
	temp->next = head;
	head =temp;

	return head;
}

struct Node* insertatend(struct Node* head,int n)
{
	struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
	struct Node* p = head;

	temp->data = n;
	temp->next  =NULL;

	while(p->next!=NULL)
		p = p->next;

	p->next = temp;

	return head;
}

struct Node* NewNode(int n)
{
	struct Node* temp;

	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = n;
	temp->next = NULL;

	return temp;
}

struct Node* AddTwoLists(struct Node* first,struct Node* second)
{
	struct Node* res = NULL;

	int sum=0,carry = 0;

	while(first!=NULL || second!=NULL)
	{
		sum = carry + (first?first->data:0) + (second?second->data:0);

		carry = (sum >=10)?1:0;

		sum = sum % 10;

		if(res==NULL)
			res = insertatbeg(res,sum);

		else
			res = insertatend(res,sum);

		if(first) first = first->next;

		if(second) second = second->next;

	}

	if(carry>0)
		res = insertatend(res,carry);

	return res;
}

int main()
{	
	struct Node* ahead = NULL;
	struct Node* bhead = NULL;
	struct Node* result = NULL;

	ahead = insertatbeg(ahead,8);
	insertatend(ahead,4);
	insertatend(ahead,9);

	bhead = insertatbeg(bhead,6);
	insertatend(bhead,4);
	insertatend(bhead,9);
	insertatend(bhead,5);
	insertatend(bhead,7);

	result = AddTwoLists(ahead,bhead);

	printf("First number is= ");traverse(ahead);
	printf("\nSecond number is= ");traverse(bhead);
	printf("\nSum is :  ");traverse(result);

	return 0;
}