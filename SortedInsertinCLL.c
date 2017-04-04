#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

//	Sorted insert in circular linked list

void traverse(struct Node* head)
{
	
	struct Node* temp =head;

	do{
		printf("%d ",temp->data);
		temp = temp->next;
	}while(temp!=head);
}

struct Node* sortedinsert(struct Node* head,int x)
{
	struct Node* current = head;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;

	if(head==NULL)
	{
		temp->next = temp;
		return temp;
	}

	else if(temp->data <= current->data)
	{
		while(current->next!=head)
			current = current->next;

		current->next = temp;
		temp->next = head;


		return temp;
	}

	else
	{
		while(current->next!=head && current->next->data < temp->data)
			current = current->next;

		temp->next = current->next;
		current->next = temp;
		return head;
	}
}

int main()
{
	struct Node* head = NULL;
	
	head = sortedinsert(head,1);
	head = sortedinsert(head,11);
	head = sortedinsert(head,6);
	head = sortedinsert(head,3);
	head = sortedinsert(head,9);

	printf("LIST is: "); traverse(head);

	return 0;
}