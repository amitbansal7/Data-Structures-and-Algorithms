#include "stdio.h"

struct Node
{
	int data;
	struct Node* next;
};
//Sort a linked list using merge sort

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

struct Node* SortedMerge(struct Node* a,struct Node* b)
{
	struct Node* result;
	result = NULL;

	if(a==NULL)
		return(b);

	else if(b==NULL)
		return(a);

	if(a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next,b);
	}

	else
	{
		result = b;
		result->next = SortedMerge(a,b->next);
	}

	return(result);
}

void split(struct Node* source , struct Node** front,struct Node** back)
{
	struct Node* slow;
	struct Node* fast;

	if(source==NULL || source->next==NULL)
	{
		*front = source;
		*back = NULL;
	}

	else
	{
		slow = source;
		fast = source->next;

		while(fast!=NULL)
		{
			fast  = fast->next;
			if(fast!=NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		*front  = source;
		*back = slow->next;
		slow->next=NULL;
	}
}

void MergeSort(struct Node** head)
{
	struct Node* temphead = *head;
	struct Node* a;
	struct Node* b;

	if((temphead==NULL) || (temphead->next==NULL))
		return;

	split(temphead,&a,&b);

	MergeSort(&a);
	MergeSort(&b);

	*head = SortedMerge(a,b);
}

int main()
{
	struct Node* head = NULL;
	
	head = insertatbeg(head,1);
	head = insertatend(head,3);
	head = insertatend(head,5);
	head = insertatend(head,7);

	head = insertatbeg(head,2);
	head = insertatend(head,4);
	head = insertatend(head,9);

	printf("\nLIST IS :");traverse(head);

	MergeSort(&head);

	printf("\nSORTED LIST IS :");traverse(head);


}