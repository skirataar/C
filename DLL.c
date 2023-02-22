#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node * llink, *rlink;
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

NODE insert_front(NODE first, int ele){
    NODE temp;
    temp=getnode();
    temp->info=ele;
    temp->rlink=temp->llink=NULL;
    if(first==NULL){
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

NODE insert_rear(NODE first, int ele){
    NODE temp, cur=first;
    temp=getnode();
    temp->info=ele;
    temp->rlink=temp->llink=NULL;
    if(first==NULL){
        return temp;
    }
    while(cur->rlink!=NULL){
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    return first;

}

void display(NODE first){
    NODE cur=first;
    if(first==NULL){
        printf("No elements");
        return;
    }
    printf("\nElements of DLL are: \n");
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->rlink;
    }
}

NODE delete_front(NODE first){
    if(first==NULL){
        printf("No elements");
        return NULL;
    }
    else if(first->rlink==NULL){
        printf("\nDeleted element is: %d",first->info);
        free(first);
        return NULL;
    }
    NODE cur=first->rlink;
    printf("\nDeleted element is: %d",first->info);
    cur->llink=NULL;
    free(first);
    return cur;

}

NODE delete_rear(NODE first){
    NODE cur=first,prev=NULL;
    if(first==NULL){
        printf("No elements");
        return NULL;
    }
    else if(first->rlink==NULL){
        printf("\nDeleted element is: %d",first->info);
        free(first);
        return NULL;
    }
    while(cur->rlink!=NULL){
        prev=cur;
        cur=cur->rlink;
    }
    printf("\nDeleted element is: %d",cur->info);
    prev->rlink=NULL;
    free(cur);
    return first;

}
void main(){
    NODE first=NULL;
    int ele,ch;
    while(1){
        printf("\n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element: ");
                    scanf("%d",&ele);
                    first=insert_front(first,ele);
                    break;
            case 2: printf("Enter element: ");
                    scanf("%d",&ele);
                    first=insert_rear(first,ele);
                    break;
            case 3: first=delete_front(first);
                    break;
            case 4: first=delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            // case 6: printf("The number of nodes: %d",count(last));
            //         break;
            // case 7: last=sort(last);
            //         break;
            default: exit(0);

        }
    }
}