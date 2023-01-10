#include<stdio.h>
void accept(int a[10], int *n){
	printf("Enter the size of array: ");
	scanf("%d",n);
	printf("Enter the array elements: ");
	for(int i=0;i<*n;i++){
		scanf("%d",&a[i]);
		}
	}
	
int sum(int a[10],int n){
	int count=0;
	for(int i=0;i<n;i++){
		count += a[i];
		}
		return count;
	}

void main(){
	int a[10],n;
	accept(a,&n);
	printf("Sum = %d",sum(a,n));
	}		
