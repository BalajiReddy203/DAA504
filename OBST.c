#include<stdio.h>
#include<conio.h>
#define MAX 10
void main()
{
	int w[MAX][MAX],c[MAX][MAX],r[MAX][MAX],p[MAX],q[MAX],i,j,k,b,min,min1,temp=0,root,n;
	printf("\nEnter no. of elements:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the element of %d:",i);
		scanf("%d",&p[i]);
	}
	for(i=0;i<=n;i++)
	{
		printf("\nEnter the probability of element %d:",i);
		scanf("%d",&q[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==j)
			{
				w[i][j]=q[i];
				c[i][j]=0;
				r[i][j]=0;
				printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
			}
		}
	}
	printf("\n");
	for(b=0;b<n;b++)
	{
		for(i=0,j=b+1;i<n+1&&j<n+1;i++,j++)
		{
			if(i!=j&&i<j)
			{
				w[i][j]=p[j]+q[j]+w[i][j-1];
				min=30000;
				for(k=i+1;k<=j;k++)
				{
					min1=c[i][k-1]+c[k][j]+w[i][j];
					if(min>min1)
					{
						min=min1;
						temp=k;
					}
				}
				c[i][j]=min;
				r[i][j]=temp;
			}
			printf("W[%d][%d]: %d\tC[%d][%d]: %d\tR[%d][%d]: %d\n",i,j,w[i][j],i,j,c[i][j],i,j,r[i][j]);
		}
		printf("\n");
	}
	printf("Minimum cost=%d\n",c[0][n]);
	root=r[0][n];
	printf("root=%d",root);
	getch();
}
