#include<stdio.h>
int main()
	{
		int num[100],n,i,max=0;
		printf("Enter the number of elements in the array : ");
		scanf("%d",n);
		printf("Enter the array elements : ");
		for(i=0;i<n;i++)
			{
				scanf("%d",&num[i]);
			}
		max=num[0];
		for(i=0;i<n;i++)
			{
				if(num[0]<num[i])
					max=num[i];
			}
		printf("%d",max);
	}
