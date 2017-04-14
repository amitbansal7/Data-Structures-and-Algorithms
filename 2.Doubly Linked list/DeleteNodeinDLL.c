#include <stdio.h>

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

// Delete a Node in doubly linked list

struct Node* push(struct Node* head,int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->prev = NULL;

	if(head==NULL)
	{
		head = temp;
		temp->next = NULL;
		return head;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;

	return head;
}

struct Node* insertafter(struct Node* head,int n)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;

	temp->prev = head;
	temp->next = head->next;
	head->next = temp;

	if(temp->next!=NULL)
		temp->next->prev = temp;

	return head;
}

struct Node* append(struct Node* head,int data)
{
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;
	struct Node* temp = head;
	new->next = NULL;

	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	temp->next = new;
	new->prev = temp;

}

void deletenodeutil(struct Node** head,struct Node* del)
{
	if(*head==NULL || del==NULL)
		return;

	if(*head==del)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
	}

	if(del->next!=NULL)
		del->next->prev = del->prev;

	if(del->prev!=NULL)
		del->prev->next = del->next;


	free(del);
}
void deletenode(struct Node** head , int n)
{
	struct Node* temp = *head;

	while(temp!=NULL)
	{
		if(temp->data==n)
		{
			deletenodeutil(head,temp);
			return;
		}
		temp = temp->next;
		
	}

	printf("Not found!!");	
	return;
}

void traverse(struct Node* head)
{
	struct Node* last;

	printf("\nForward : ");

	while(head!=NULL)
	{
		printf("%d ",head->data);
		last = head;
		head = head->next;
	}
	printf("\nBackward :");

	while(last!=NULL)
	{
		printf("%d ",last->data);
		last = last->prev;
	}
}

int main()
{
	struct Node* head = NULL;

	int del;

	head = push(head,12);
	head = push(head,1);
	head = push(head,2);
	head = append(head,8);
	insertafter(head->next,5);

	traverse(head);
	printf("\nEnter value to be deleted : ");
	scanf("%d",&del);
	deletenode(&head,del);
	traverse(head);
}