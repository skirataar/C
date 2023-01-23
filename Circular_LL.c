#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node * link;
};
typedef struct node * NODE;

NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Memory not available.");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE last,int ele){
    NODE temp;
    temp=getnode();
    temp->info=ele;
    if(last==NULL)
        last = temp;
    else
        temp->link=last->link;
    last->link=temp;
    return last;
}

NODE insert_rear(NODE last, int ele){
    NODE temp;
    temp=getnode();
    temp->info=ele;
    if(last==NULL)
        last=temp;
    else
        temp->link=last->link;
    last->link=temp;
    return temp;
}



NODE delete_front(NODE last){
    NODE first;
    if(last==NULL){
        printf("list is empty");
        return NULL;
    }
    else if(last==last->link){
        printf("Deleted element is %d",last->info);
        free(last);
        return NULL;
    }
    else{
        first=last->link;
        printf("Deleted element: %d",first->info);
        free(first);
        last->link=first->link;
        return last;
    }
}

NODE delete_rear(NODE last){
    if(last->link==NULL)
        printf("List is empty");
    else if(last->link==last){
        printf("Deleted element is %d",last->info);
        free(last);
        return NULL;
    }
    else{
        NODE prev=last->link;
        while(prev->link!=last){
            prev=prev->link;
        }
        prev->link=last->link;
        printf("Deleted element is %d",last->info);
        free(last);
        return prev;
    }

}

void display(NODE last){
    if(last==NULL){
        printf("NO ELEMENTS.");
        return;
    }
    NODE first = last -> link;
    printf("Elements of the Linked Lists are: ");
    while(first!=last){
        printf("%d ",first->info);
        first=first->link;
    }
    printf("%d",last->info);
}

int count(NODE last){
    NODE first;
    if(last==NULL)
        return 0;

    else{
            first=last->link;
            int count=0;
            while(first!=last){
                count++;
                first=first->link;
            }
        return count+1;
    }
}

NODE merge(NODE first, NODE second){
    NODE res,cur,opt;
    if(first==NULL)
        cur=second->link;
    else if(second==NULL)
        cur=first->link;
    
}

void main(){
    NODE last=NULL;
    int ele,ch;
    while(1){
        printf("\n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element: ");
                    scanf("%d",&ele);
                    last=insert_front(last,ele);
                    break;
            case 2: printf("Enter element: ");
                    scanf("%d",&ele);
                    last=insert_rear(last,ele);
                    break;
            case 3: last=delete_front(last);
                    break;
            case 4: last=delete_rear(last);
                    break;
            case 5: display(last);
                    break;
            default: exit(0);

        }
    }
}