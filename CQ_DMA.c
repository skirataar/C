#include<stdlib.h>
#include <stdio.h>
int MAX=3;

int* insert_CQ(int *Q,int *rear,int *front, int *count,int ele){
    int *p;
    if(*count==MAX){
        printf("Memory Full! Reallocating...");
        MAX*=2;
        p=(int*)malloc(sizeof(int)*MAX);
        if(*front==0){
            for(int i=0;i<(MAX/2)-1;i++){
                p[i]=Q[i];
            }
        }
        else if(*front>*rear){
            int j=0;
            for(int i=*front;i<MAX/2;i++,j++){
                p[j]=Q[i];
            }
            for(int i=0;i<=*rear;i++){
                p[j]=Q[i];
                }
                *front=0;
                *rear=(MAX/2)-1;
            }
        else{
            (*count)++;
            (*rear)=((*rear)+1)%MAX;
            p[*rear]=ele;
            free(Q);
            return p;
        }
    }
    else{
        *rear=((*rear)+1)%MAX;
        Q[*rear]=ele;
        (*count)++;
        return Q;
    }
}

void delete_CQ(int *Q,int *front,int *count){
    printf("Element to be deleted %d\n",Q[*front]);
    (*front)=((*front)+1)%MAX;
    (*count)--;
}
void display(int *Q,int front,int count,int rear){
    printf("Elements of the Queue are: ");
    for(int i=front;i<=rear;){
        printf("\n%d",Q[i]);
        i=(i+1)%MAX;
        
    }
}
void main(){
    int n, *Q, rear=MAX - 1, count=0, front=0, ele, ch;
    Q=(int*)malloc(sizeof(int)*MAX);
    while(1){
            printf("\n1:Insert\n2:Delete\n3:Display\n");
            scanf("%d",&ch);
            switch(ch){
                case 1: printf("Enter the element: ");
                        scanf("%d",&ele);
                        Q=insert_CQ(Q,&rear,&front,&count,ele);
                        break;
                case 2: delete_CQ(Q,&front,&count);
                        break;
                case 3: display(Q,front,count,rear);
                        break;
                default: exit(0);
            }
    }
}
