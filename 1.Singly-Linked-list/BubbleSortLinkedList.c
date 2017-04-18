#include "stdio.h"


struct Node
{
	int data;
	struct Node* next;
};
//Sort a linked list using bubble sort
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

void swap(struct Node* a, struct Node* b)
{
	struct Node * temp;
	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void BubbleSort(struct Node* head)
{
	struct Node* ptr,lptr = NULL;
	int swapped;

	if(head==NULL)
		return;

	ptr = head;

	do
	{
		swapped = 0;
		ptr = head;

		while(ptr->next!=lptr)
		{
			if(ptr->data > ptr->next->data)
			{
				swap(ptr,ptr->next);
				swapped = 1;
			}

			ptr = ptr->next;
		}
		lptr = ptr;
	}

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

	BubbleSort(&head);

	printf("\nSORTED LIST IS :");traverse(head);


}