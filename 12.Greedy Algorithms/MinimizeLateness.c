#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

struct Job
{
	int t;// time taken to complete the job
	int d;//deadline for the job
};

int compare(const void *a, const void *b)
{
	if(((struct Job*)a)->d > ((struct Job*)b)->d)
		return true;

	else
		return false;
}

void SelectJobs(struct Job J[],int n)
{
	int lateness = 0;
	int time = 0;

	qsort(J,n,sizeof(struct Job),compare);
	printf("Order in which jobs are done is :\n");

	for(int i=0;i<n;i++)
	{
		printf("%d - %d\n",J[i].t,J[i].d);
		time = time + J[i].t;
		lateness = lateness + (time - J[i].d < 0? 0 :time - J[i].d);
		// At to total lateness if job is completed after deadline.
	}

	printf("Total lateness is %d \n",lateness);
	printf("Total Time taken to complete Jobs is %d\n",time);
}

int main()
{
	struct Job J[] = {{3, 6},{2, 8},{1, 9},{4, 9},{3, 11},{2, 12}};

	SelectJobs(J,sizeof(J)/sizeof(J[0]));
	return 0;
}