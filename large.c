#include<stdio.h>
int largest(int ,int ,int);
int main()
	{
		int num1,num2,num3;
		printf("Enter three numbers: ");
		scanf("%d%d%d",&num1,&num2,&num3);
		largest(num1,num2,num3);
		return 0;
	}
int largest(int num1,int num2,int num3)
	{
		if((num1==num2)&&(num2==num3)&&(num1==num3))
			printf("All the three numbers are equal");
	      else if((num1==num2)||(num2==num3)||(num1==num3))
	      	{
	      		if(num1==num2)
	      			{
	      				if(num1>num3)
	      					{
	      						printf("%d is the largest",num1);
	      						printf("%d is the second largest",num3);
	      					}
	      				else
	      					{
	      						printf("%d is the largest",num3);
	      						printf("%d is the second largest",num1);
	      					}
	      			}
	      		if(num2==num3)
	      			{
	      				if(num1>num2)
	      					{
	      						printf("%d is the largest",num1);
	      						printf("%d is the second largest",num2);
	      					}
	      				else
	      					{
	      						printf("%d is the largest",num2);
	      						printf("%d is the second largest",num1);
	      					}
	      			}
	      		if(num1==num3) 
	      			{
	      				if(num1>num2)
	      					{
	      						printf("%d is the largest",num1);
	      						printf("%d is the second largest",num2);
	      					}
	      				else
	      					{
	      						printf("%d is the largest",num2);
	      						printf("%d is the second largest",num1);
	      					}
	      			}
	      		}
	      	else
	      		{
	      			if((num1>num2)&&(num1>num3))
	      				{
	      					printf("%d is the largest",num1);
	      					if(num2>num3)
	      						{
	      							printf("%d is the second largest",num2);
	      							printf("%d is the smallest",num3);
	      						}
	      					else
	      						{
	      							printf("%d is the second largest",num3);
	      							printf("%d is the smallest",num2);
	      						}
	      				}
	      			else if((num2>num3)&&(num2>num1))
	      				{
	      					printf("%d is the largest",num2);
	      					if(num1>num3)
	      						{
	      							printf("%d is the second largest",num2);
	      							printf("%d is the smallest",num3);
	      						}
	      					else
	      						{
	      							printf("%d is the second largest",num3);
	      							printf("%d is the smallest",num2);	
	      						}
	      				}
	      			else 
	      				{
	      					printf("%d is the largest",num3);
	      					if(num1>num2)
	      						{
	      							printf("%d is the second largest",num1);
	      							printf("%d is the smallest",num2);
	      						}
	      					else
	      						{
	      							printf("%d is the second largest",num2);
	      							printf("%d is the smallest",num1);	
	      						}
	      				}
	      		}	
	      	}
