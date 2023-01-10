#include<stdio.h>
typedef struct sparse{
	int row;
	int col;
	int val;
	}S;
	
void accept ( S a[10],int *n, int *m){
	printf("Enter the rows & cols: ");
	scanf("%d%d",n,m);
	int ele,k=0;
	for(int i=0;i<*n;i++){
		for(int j=0;j<*m;j++){
			printf("Row:%d Column:%d\n",i,j);
			scanf("%d",&ele);
			if(ele!=0){
				k++;
				a[k].row=i;
				a[k].col=j;
				a[k].val=ele;
				}
			}
		}
	a[0].row=*n;
	a[0].col=*m;
	a[0].val=k;
	}
		
	
void transpose(S a[10], S aT[10]){
	int k=1;
	for(int i=0;i<a[0].col;i++){
		for(int j=1;j<=a[0].val;j++){
			if(i==a[j].col){
				aT[k].row=a[j].col;
				aT[k].col=a[j].row;
				aT[k].val=a[j].val;
				k++;
				}
			}
		}
	aT[0].row=a[0].col;
	aT[0].col=a[0].row;
	aT[0].val=a[0].val;
	}

void display(S a[10]){
	int k=1;
	for(int i=0;i<a[0].row;i++){
		for(int j=0;j<a[0].col;j++){
			if(a[k].row==i && a[k].col==j){
				printf("%d ",a[k].val);
				k++;
				}
			else
				printf("0 ");
			}
		printf("\n");
		}
	printf("\n");
	}
	
void main(){
	int n,m;
	S a[10],aT[10];
	accept(a,&n,&m);
	display(a);
	transpose(a,aT);
	display(aT);
	}
