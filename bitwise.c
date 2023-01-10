#include<stdio.h>
int bit(int a,int b){
	while(b!=0){
		int carry= a&b;
		a= a^b;
		b= carry<<1;
		}
	return a;
}
	
void main(){
	int a=8,b=9;
	printf("%d",bit(a,b));
}

