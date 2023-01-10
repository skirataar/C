#include<stdio.h>
int addreal(int real1,int real2)
	{
		int sum=real1+real2;
		return sum;
	}
int addimg(int img1,int img2)
	{
		int sumi=img1+img2;
		return sumi;
	}
int main()
	{
		int real1,real2,img1,img2;
		printf("Enter the real and imaginary part of first number : ");
		scanf("%d%d",&real1,&img1);
		printf("Enter the real and imaginary part of second number : ");
		scanf("%d%d",&real2,&img2);
		int sum=addreal(real1,real2);
		int sumi=addimg(img1,img2);
		printf("Sum=%d+%di",sum,sumi);
		return 0;
	}
