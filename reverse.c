#include<stdio.h>
void accept(int *n){
	printf("Enter the number: ");
	scanf("%d",n);
	}
void reverse(int n){
	int rem,rev=0;
	while(n!=0){
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
		}
	printf("Reversed Number: %d",rev);
	}
void main(){
	int n;
	accept(&n);
	reverse(n);
	
	}
	
