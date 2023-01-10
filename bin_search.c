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

void bin_search(int a[10],int n){
	int key,left=0,right=(n-1),mid;
	printf("Enter the search element: \n");
	scanf("%d",&key);
	while(left<=right){
		mid=(left+right)/2;
		if(a[mid]==key){
			printf("%d found at location %d\n",key,mid);
			break;}
		else if(a[mid]>key)
			right=mid-1;
		else
			left=mid+1;
			}
	if(left>right)
		printf("Element not found!");
	}	
	
void main(){
	int a[10],n;
	accept(a,&n);
	sort(a,n);
	bin_search(a,n);

	}
	
