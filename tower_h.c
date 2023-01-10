#include<stdio.h>
void tower_h(int n, char S, char D, char T){
	if(n==0){
		return;
	}
	tower_h(n-1,S,T,D);
	printf("Move disk %d from rod %c to rod %c\n",n,S,D);
	tower_h(n-1,T,D,S);
}
int main(){
	int n;
	printf("Enter the number of discs: ");
	scanf("%d",&n);
	tower_h(n,'A','C','B');
}

