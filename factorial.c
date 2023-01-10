#include<stdio.h>
int factorial(int num)
	{
		int i,fact=1;
		if(num==0)
			fact=1;
		else
			{
				for(i=1;i<=num;i++)
					fact=fact*i;
			}
		return fact;	
	}
int main()
	{
		int num;
		printf("Enter the number : ");
		scanf("%d",&num);
		printf("Factorial of %d = %d",num,factorial(num));
		return 0;
	}
