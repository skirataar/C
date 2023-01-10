#include<stdio.h>
void accept(int a[10], int *n){
	printf("Enter the size of array: ");
	scanf("%d",n);
	printf("Enter the array elements: ");
	for(int i=0;i<*n;i++){
		scanf("%d",&a[i]);
		}
	}

void sort(int a[10],int n){
	for(int j=0;j<n;j++){
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				}
			}
		}
	}
	
	
void display(int a[10], int n){
	printf("Sorted elements are: ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
		}
	}

void main(){
	int a[10],n;
	accept(a,&n);
	sort(a,n);
	display(a,n);
	}
	
