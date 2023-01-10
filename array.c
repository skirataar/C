#include<stdio.h>
void accept(int a[10], int *n){
	printf("Enter the size of array: ");
	scanf("%d",n);
	printf("Enter the array elements: ");
	for(int i=0;i<*n;i++){
		scanf("%d",&a[i]);
		}
	}
	
void display(int a[10],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
		}
		
	}

void main(){
	int a[10],n;
	accept(a,&n);
	display(a,n);
	}
