#include<stdio.h>
void accept(int a[10],int *n,int *k){
	printf("Enter the size of array: ");
	scanf("%d",n);
	printf("Enter array values: ");
	for(int i=0;i<*n;i++){
		scanf("%d",&a[i]);
		}
	printf("Enter key: ");
	scanf("%d",k);
	}
void search(int a[10],int n,int k){
	int p=-1;
	for(int i=0;i<n;i++){
		if(k==a[i]){
			printf("Element found at %d",i);
			p+=1;
			break;}
		}
	if(p<0){
		printf("Element not found.");
		}
	}
void main(){
	int n,a[10],k;
	accept(a,&n,&k);
	search(a,n,k);
	}
