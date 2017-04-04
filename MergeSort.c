#include "stdio.h"

// Merge Sort
void merge(int A[],int *L,int *R,int nl,int nr)
{
	int i,j,k;

	i=0;j=0;k=0;

	while(i<nl && j<nr)
	{
		if(L[i] < R[j])
			A[k++] = L[i++];

		else
			A[k++] = R[j++];
	}
	while(i<nl)
		A[k++] = L[i++];

	while(j<nr)
		A[k++] = R[j++];

}

void sort(int A[],int n)
{
	int mid,*L,*R,i;

	if(n<2) return ;

	mid = n/2;

	L = (int *)malloc(sizeof(int)*mid);
	R = (int *)malloc(sizeof(int)*(n-mid));

	for(i=0;i<mid;i++)
		L[i] = A[i];

	for(i=mid;i<n;i++)
		R[i-mid] = A[i];

	sort(L,mid);
	sort(R,n-mid);
	merge(A,L,R,mid,n-mid);
	free(L);
	free(R);

}

int main()
{
	int A[1000000] ;
	int n,i;

	n = sizeof(A) / sizeof(A[0]);

	for(i=0;i<1000000;i++)
		A[i] = 1000000-i;

	sort(A,n);

	for(i=0;i<n;i++)
		printf("%d\n",A[i]);
}