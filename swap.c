#include<stdio.h>
void accept(int *x, int *y){
	printf("Enter 2 numbers: ");
	scanf("%d%d",x,y);
	}
void swap(int x,int y){
	x=x+y;
	y=x-y;
	x=x-y;
	printf("%d %d",x,y);
	}
void main(){
	int x,y;
	accept(&x,&y);
	swap(x,y);
	}
