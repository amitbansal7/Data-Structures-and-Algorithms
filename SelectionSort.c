#include "stdio.h"

//Selection Sort
void sort(int A[],int n)
{
	int k,l,j,temp;

	for(k=0;k<n;k++)
	{
		l=k;
		for(j=k;j<n;j++)
		{
			if(A[j] < A[l])
				l = j;

		}

		temp = A[l];
		A[l] = A[k];
		A[k] = temp;
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