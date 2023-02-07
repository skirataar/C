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

void insert_rear(NODE head, int ele){
    NODE temp,cur=head;
    temp=getnode();
    temp->info=ele;
    if(head==head->link)
        head->link=temp;
    else {
    	while(cur->link!=head)  	
    		cur=cur->link;
    	cur->link=temp;
    }
    temp->link=head;  
		  	        
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

void delete_front(NODE head){
    NODE first;
    
    if(head==head->link){
        printf("No elements");
    }
    else{
        first=head->link;
        printf("\nDeleted element: %d\n",first->info);
        head->link=first->link;
        free(first);
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

int count_nodes(NODE head){
    int count = 0;
    NODE cur = head->link;
    if(head == head->link){
        return count;
    }
    while(cur != head){
        count++;
        cur = cur->link;
    }
    return count;
}

void insert_at_pos(NODE head, int ele, int pos){
    NODE cur = head->link, temp = getnode();
    int i = 1, n = count_nodes(head);
    temp->info = ele;
    if(pos < 1 || pos > n+1){
        printf("Invalid position.");
        return;
    }
    if(pos == 1){
        insert_front(head, ele);
        return;
    }
    while(i < pos-1 && cur != head){
        cur = cur->link;
        i++;
    }
    temp->link = cur->link;
    cur->link = temp;
}

NODE search(NODE head, int ele){
    NODE cur = head->link;
    while(cur != head){
        if(cur->info == ele)
            return cur;
        cur = cur->link;
    }
    return NULL;
}


void main(){
    NODE head=getnode(),res;
    head->link=head;
    int ele,ch,pos;
    while(1){
        printf("\n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Display\n6:Count Nodes\n7:Insert At Specific position\n8:Search an element\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element: ");
                    scanf("%d",&ele);
                    insert_front(head,ele);
                    break;
            case 2: printf("Enter element: ");
                    scanf("%d",&ele);
                    insert_rear(head,ele);
                    break;
            case 3: delete_front(head);
                    break;
            case 4: delete_rear(head);
                    break;
            case 5: display(head);
                    break;
            case 6: printf("Number of nodes is: %d",count_nodes(head));
            	  break;
           	case 7: printf("Enter position: ");
			  scanf("%d", &pos);
			  printf("Enter element: ");
			  scanf("%d", &ele);
			  insert_at_pos(head, ele, pos);
			  break;
		case 8: printf("Enter the element to be searched: ");
			  scanf("%d", &ele);
			  res = search(head, ele);
			  if(res == NULL)
    			  	printf("Element not found.");
			  else
    				printf("Element found.");
    			  break;   
                  
            default: exit(0);

        }
    }
}
