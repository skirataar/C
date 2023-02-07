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

void insert_front(NODE head,int ele){
    NODE temp=getnode();
    temp->info=ele;
    temp->link=head->link;  
    head->link=temp;  
}

void display(NODE head){
    NODE cur=head->link;
    if(head==head->link){
        printf("No Elements");
        return;
    }
    while(cur!=head){
        printf("%d ",cur->info);
        cur=cur->link;
    }
}

void delete_rear(NODE head){
    NODE prev,cur;
    if(head->link==head){
        printf("Empty circular linked list");
        return;
    }
    prev=NULL;
    cur=head;
    while(cur->link!=head){
        prev=cur;
        cur=cur->link;
    }
    prev->link=cur->link;
    printf("Deleted element is %d",cur->info);
    free(cur);
}

void main(){
    NODE head = getnode();
    head->link = head;
    insert_front(head,22);
    insert_front(head,33);
    insert_front(head,44);
    display(head);
}
