#include<stdio.h>
#include<stdlib.h>
int max=3;
int *insert(int *q,int *rear,int *front,int *count,int elem)
{
    if(*count == max)
    {
        int i,j;
        max = max*2;
        q=(int *)realloc(q,sizeof(int)*max);
        if(*front != 0)
        {
            for(i=(max/2)-1,j=max-1; i>=(*front); i--,j--)
            q[j]=q[i];
            (*front)=j+1;
        }
        (*rear)=((*rear)+1)%max;
        q[*rear]=elem;
        (*count)++;
        return q;
    }
    (*rear)=((*rear)+1)%max;
    q[*rear]=elem;
    (*count)++;
    return q;
}
void delete(int *q,int *front,int *count)
{
    if(*count == 0)
    {
        printf("nothing to return \n");
        return;
    }
    printf("the deleted element is %d\n",q[*front]);
    (*front)=((*front)+1)%max;
    (*count)--;
}
void display(int *q,int front,int count)
{
    if(count == 0)
    {
        printf("nothing to display\n");
        return;
    }
    printf("displaying elements in queue\n");
    for( ;count>0;front=(front+1)%max,count--)
    printf("%d\t",q[front]);
    printf("\n");
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
