#include<stdio.h>
#include<conio.h> 
int wt[10],pr[10],result[10][10],n,i,j,size,x[10];
int main()
{
	int profit,count=0;
	printf("Enter the number of units");
	scanf("%d",&n);
	printf("Enter the profit and weight of each item");
	for(i=1;i<=n;i++)
	{
		printf("Item no %d profit,wt",i);
		scanf("%d%d",&pr[i],&wt[i]);
	}
	printf("Enter the capacity of knapsack");
	scanf("%d",&size);
	for(i=0;i<=n;i++)
	for(j=0;j<=size;j++)
	if((i==0)||(j==0))
	result[i][j]=0;
	else
	result[i][j]=-1;
	profit=(n);
	i=n;
	j=size;
	while(j!=0&&i!=0)
	{
		if(result[i][j]!=result[i-1][j])
		{
			x[i]=1;
			j=j-wt[i];
			i--;
		}
		else
		i--;
	}
	printf("Items added in order");
	printf("in\t Weight\tprofit\n");
	for(i=1;i<=n;i++)
	if(x[i])
	printf("%d%d%d",++count,wt[i],pr[i]);
	printf("total profit=%d",profit);
	getch();
}
