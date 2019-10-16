#include<stdio.h>
#include<math.h>
void main()
{
    int a[100],b[10][10],c[10]={0},n,i,count=1,rem,k,u=0,h=0,e=0,j=0,p,t,w,m;
    printf("enter the no.of elements");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        rem=a[i]/10;
        while(rem>0)
        {
            count++;
            rem=rem/10;

        }
        if(count==1)
        {

            b[0][h]=a[i];
            h++;
           c[0]++;
        }
        if(count==2)
        {
            k=a[i]/10;
            if(k==m)
            {
                e++;
            }
            else{e=0;}
            b[k][e]=a[i];

           c[k]++;
           m=k;
        }
        count=1;
    }
for(i=0;i<10;i++)
{if(c[i]==0)
{
    continue;
}
else
{
p=i;
 for(w=0;w<c[i];w++)
 {
    for(j=w+1;j<c[i];j++)
    {

       if(b[p][w]>b[p][j])
       {
           t=b[p][w];
           b[p][w]=b[p][j];
           b[p][j]=t;

       }
    }


    }
}

}
     for(j=0;j<10;j++)
    {
        if(c[j]==0)
        {
            continue;
        }
        else{
  for(p=0;p<c[j];p++)
  {

     printf("%d ",b[j][p]);
  }
        }


    }

}
