#include <stdio.h>
#include <stdlib.h>


struct Activity
{
	int start;
	int finish;
};

int compare(const void *s1, const void *s2)
{
	if(((struct Activity*)s1)->finish >= ((struct Activity*)s2)->finish)
		return 1;

	else
		return 0;
}

void MaxActivities(struct Activity A[],int n)
{
	qsort(A,n,sizeof(struct Activity),compare);
	// Sort activities in descending order according to their finishing time.

	int i=0,j;

	printf("Selected Activities are :\n");
	printf("(%d,%d), ",A[i].start,A[i].finish);

	for(j=1; j<n; j++)
	{
		if(A[j].start >= A[i].finish)
		{
			// Select Activities whose finish time is less than or equal to staring time of next activity.
			printf("(%d,%d), ",A[j].start,A[j].finish);
			i = j;
		}
	}
}

int main()
{
	struct Activity A[] = {{8, 9},{5, 9},{1, 2},{3, 4},{0, 6},{5, 7}};

	int n = sizeof(A)/sizeof(A[0]);

	MaxActivities(A,n);
	return 0;
}