#include "stdio.h"
//Bubble Sort
void sort(int A[],int n)
{
	int i,j,temp;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
			if(A[j]>A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
	}
}

int main()
{
	int A[] = {9,8,7,6,5,4,3,2,1};
	int n,i;

	n = sizeof(A) / sizeof(A[0]);

	sort(A,n);

	for(i=0;i<n;i++)
		printf("%d ",A[i]);
}