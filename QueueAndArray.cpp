#include "stdio.h"
#include "stdlib.h"

int A[10];
int front=-1;
int rear = -1;

//Queue implementation using Arrays.

bool isEmpty()
{
return (front == -1 && rear == -1) ? true : false;
}

void enqueue(int x)
{
	if((rear+1)%10==front)
		return;

	else if(isEmpty())
	{
		front =0;
		rear = 0;
	}

	else
		rear = (rear+1)%10;

	A[rear] = x;

}

void dequeue(int x)
{
	if(isEmpty())
		return;

	else if (front==rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front = (front+1)%10;
}

int main()
{
	enqueue(2);
	enqueue(3);
	enqueue(6);
	
	return 0;
}