#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct emp{
    int eid,esal;
    char ename[20];
}E;

struct node {
    E info;
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

NODE insert_front(NODE first, E ele){
    NODE temp=getnode(),cur=first;
    temp->info=ele;
    // (temp->info).eid=ele.eid;
    // strcpy((temp->info).ename,ele.ename);
    // (temp->info).esal=ele.esal;
    temp->rlink=temp->llink=NULL;
    if(first==NULL){
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

NODE insert_rear(NODE first, E ele){
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

void display(NODE first){
    NODE cur=first;
    if(first==NULL){
        printf("No elements");
        return;
    }
    printf("\nElements of DLL are: \n");
    while(cur!=NULL){
        printf("\nName: %s\nEmployee ID: %d \nEmployee Salary: %d ",(cur->info).ename,(cur->info).eid,(cur->info).esal);
        cur=cur->rlink;
    }
}

int highest_sal(NODE first){
    int sal=0;
    NODE cur=first;
    while(cur!=NULL){
        // printf("%d",(cur->info).esal);
        if((cur->info).esal>sal){
            sal=(cur->info).esal;
        }
        cur=cur->rlink;
    }
    return sal;
}

void get_emp(NODE first, char l){
    NODE cur=first;
    if(first==NULL){
        printf("No Elements.");
        return;
    }
    printf("Employee details with letter-%c",l);
    while(cur!=NULL){
        if((cur->info).ename[0]==l){
            printf("Name: %s\nEmployee ID: %d \nEmployee Salary: %d \n",(cur->info).ename,(cur->info).eid,(cur->info).esal);
        }
        cur=cur->rlink;
    }
}

void update_name(NODE first,char old_name[20],char new_name[20]){
    NODE cur=first;
    while(strcmp((cur->info).ename,old_name)!=0){
        cur=cur->rlink;
    }
    strcpy((cur->info).ename,new_name);
}

void main(){
    NODE first=NULL;
    char new_name[20], old_name[20];
    int ch;
    E ele;
    while(1){
        printf("\n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter Name, Employee ID, Employee Salary: ");
                    scanf("%s%d%d",ele.ename,&ele.eid,&ele.esal);
                    first=insert_front(first,ele);
                    break;
            case 2: printf("Enter Name, Employee ID, Employee Salary: ");
                    scanf("%s%d%d",ele.ename,&ele.eid,&ele.esal);
                    first=insert_rear(first,ele);
                    break;
            case 3: first=delete_front(first);
                    break;
            case 4: first=delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            case 6: printf("Highest Salary=%d",highest_sal(first));
                    break;
            case 7: get_emp(first,'A');
                    break;
            case 8: printf("Enter the old name to be replaced: ");
                    scanf("%s",old_name);
                    printf("Enter the new name: ");
                    scanf("%s",new_name);
                    update_name(first,old_name,new_name);
                    break;
            default: exit(0);

        }
    }
}