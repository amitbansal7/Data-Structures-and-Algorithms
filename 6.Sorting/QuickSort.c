#include "stdio.h"
//Quick Sort
void swap(int *p,int *q)
{
	int temp;

	temp = *p;
	*p =  *q;
	*q = temp;
}

int partition(int A[],int s,int e)
{
	int i,pivot,pindex,temp;
	pivot = A[e];
	pindex = s;

	for(i=s;i<e;i++)
	{
		if(A[i] <=pivot)
		{
			swap(A+i,A+pindex);;
			pindex++;
		}
	}
	swap(A+pindex,A+e);
	
	return pindex;
}

void sort(int A[],int s,int e)
{
	int pindex;

	if(s<e)
	{

	 pindex = partition(A,s,e);
	 sort(A,s,pindex-1);
	 sort(A,pindex+1,e);

	}
}

int main()
{
	int A[10000] ;
	int n,i;

	n = sizeof(A) / sizeof(A[0]);

	for(i=0;i<10000;i++)
		A[i] = 10000-i;

	sort(A,0,n);

	for(i=0;i<n;i++)
		printf("%d\n",A[i]);
}