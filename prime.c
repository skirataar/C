#include<stdio.h>
int prime(int);
int main()
	{
		int num;
		printf("Enter the number : ");
		scanf("%d",&num);
		prime(num);
		return 0;
	}
int prime(int num)
	{
		int i,count=0;
		for(i=1;i<=num;i++)
			{
				if(num%i==0)
					count++;		
			}
		if(count==2)
			printf("%d is a prime number",num);
		else
			printf("%d is not a prime number",num);
	}

