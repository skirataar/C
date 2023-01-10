#include<stdio.h>
void fibonacci(int num)
	{
		int fib0,fib1,fib2,sum,i;
		fib0=0;
		fib1=1;
		fib2=fib0+fib1;
		if(num==0)
			{
				printf("0");
			}
		else
			{
				printf("0	1");
				while(fib2<=num)
					{
						printf("\t%d",fib2);
						for(i=2;i<=num;i++)
							{
								fib0=fib1;
								fib1=fib2;
								fib2=fib0+fib1;
								printf("\t%d",fib2);	
							}	
					}	
			}
	}
int main()
	{
		int num,c=0,key;
		printf("Enter a number:");
		scanf("%d",&num);
		printf("Enter the element to be searched : ");
		scanf("%d",&key);
		fibonacci(num);
		
	}
