#include<stdio.h>
void main()
	{
		int num1,num2,n;
		printf("Enter two numbers : ");
		scanf("%d%d",&num1,&num2);
		printf("1:add\n2:subtract\n3:multiply\n4:divide\n5:remainder");
		printf("Enter the operation to be perfoemed ;");
		scanf("%d",&n);
		switch(n)
			{	
				case 1:printf("Sum = %d",num1+num2);
					 break;
				case 2:printf("Difference = %d",num1-num2);
					 break;
				case 3:printf("Product = %d",num1*num2);
					 break;
				case 4:printf("Quotient = %d",num1/num2);
					 break;
				case 5:printf("Remainder = %d",num1%num2);
					 break;
				default:printf("Invalid input");
			}
	}
