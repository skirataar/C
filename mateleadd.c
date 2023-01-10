#include<stdio.h>
void accept(int a[10][10],int *r,int *c){
	printf("Rows: ");
	scanf("%d",r);
	printf("Column: ");
	scanf("%d",c);
	for(int i=0;i<*r;i++){
		for(int j=0;j<*c;j++){
			scanf("%d",&a[i][j]);
			}
		}
	}

int add(int a[10][10],int r,int c){
	int count=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==j)
				count+=a[i][j];
			}
		}
	return count;
	}

void main(){
	int a[10][10],r,c;
	accept(a,&r,&c);
	printf("Sum=%d",add(a,r,c));
	}
