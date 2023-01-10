#include<stdio.h>
typedef struct poly{
	int cx;
	int px;
	}P;

void accept(P p1[10], P p2[10], int *n1, int *n2){
	printf("Enter the size of the two polynomials: ");
	scanf("%d%d",n1,n2);
	for(int i=0;i<*n1;i++){
		printf("Enter the co-eff & power: ");
		scanf("%d%d",&p1[i].cx,&p1[i].px
