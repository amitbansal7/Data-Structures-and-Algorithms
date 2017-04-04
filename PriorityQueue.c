#include "stdio.h"
struct Node
{
    int data;
    int priority;
    struct Node* next;
};

//Priority Queues

struct Node* head = NULL;


void traverse()
{
    struct Node* temp = head;
    while(head!=NULL)
    {
        printf("\nitem = %d  priority = %d ",head->data,head->priority);
        head = head->next;
    }
}

int isempty()
{
    if(head==NULL)
        return 1;
    else
        return 0;
}

void insert(int priority,int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    temp->data = data;
    temp->priority = priority;

    if(isempty() || priority < head->priority)
    {
        temp->next = head;
        head = temp;
    }

    else
    {
        while(p->next!=NULL && p->next->priority <= priority)
            p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
}



int del()
{
    struct Node *tmp;
    int item;
    if(isempty())
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        tmp=head;
        item=tmp->data;
        head=head->next;
        free(tmp);
    }
    return item;
}


int main()
{
    insert(6,56);
    insert(2,67);
    insert(7,12);
    insert(5,34);
    insert(4,78);
   
    insert(3,90);

    traverse();
    printf("highest = %d\n",del()); 


    
    return 0;
}