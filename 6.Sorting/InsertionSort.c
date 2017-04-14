#include "stdio.h"
//Insertion Sort
void sort(int A[],int n)
{
	int i,value,h;

	for(i=1;i<n;i++)
	{
		value = A[i];
		h = i;

		while(h>0 && A[h-1] > value)
		{
			A[h] = A[h-1];
			h = h-1;
		}

		A[h] = value;
	}

}

int main()
{
	int A[] = {7,4,8,5,6,9,3,2,1};
	int n,i;

	n = sizeof(A) / sizeof(A[0]);

	sort(A,n);

	for(i=0;i<n;i++)
		printf("%d ",A[i]);
}