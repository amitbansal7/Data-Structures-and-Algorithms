#include "stdio.h"
//Heap Sort
void swap(int *a,int *b)
{
	int *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Maxheapify(int A[],int n,int i)
{
	int l = (2*i)+1;
	int r = (2*i)+2;
	int largest = i;

	if(l<n && A[l] > A[largest])
		largest = l;

	if(r<n && A[r] > A[largest])
		largest = r;

	if(largest!=i)
	{
		swap(&A[i],&A[largest]);
		Maxheapify(A,n,largest);
	}
}
void Heapsort(int A[],int n)
{
	int i;

	for(i=n/2-1;i>=0;i--)
		Maxheapify(A,n,i);

	for(i=n-1;i>=0;i--)
	{
		swap(&A[0],&A[i]);
		Maxheapify(A,i,0);
	}
}
int main()
{
	int A[] = {7,4,1,5,6,3,2};
	int n = sizeof(A)/sizeof(A[0]);
	int i;

	Heapsort(A,n);

	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	
	return 0;
}