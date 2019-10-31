#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[10][20],count[10]={0};
	int i,n,ele,x,y;
	printf("enter the elements between 0 and 99\n");
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&ele);
		int tplace=ele/10;
		a[tplace][count[tplace]]=ele;
		count[tplace]++;
	}
	for(i=0;i<10;i++)
	{
		if(count[i]==0)
		{
			continue;
		}
		else
		{
			int noe=count[i];
			for(x=0;x<noe-1;x++)
			{
				for(y=0;y<noe-x-1;y++)
				{
					if(a[i][y]>a[i][y+1])
					{
						int z;
						z=a[i][y];
						a[i][y]=a[i][y+1];
						a[i][y+1]=z;
					}
				}
			}
		}
	}
	printf("elements afetr sorting\n");
	for(i=0;i<10;i++)
	{
		if(count[i]==0)
		{
			continue;
		}
		else
		{
			int w;
			for(w=0;w<count[i];w++)
			{
				printf("%d ",a[i][w]);
			}
		}
	}
}
