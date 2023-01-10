#include<stdio.h>
#include<string.h>
struct emp{
	int e_id;
	char e_name[20];
	float e_sal;
	};

typedef struct emp E;
	
void accept(E *e1){
	printf("Enter the employee details: ");
	scanf("%d%s%f",&(*e1).e_id,(*e1).e_name,&(*e1).e_sal);
	}

void compare(E e1, E e2){
	int l1=strlen(e1.e_name),l2=strlen(e2.e_name);
	if(l1==l2){
	    int count=0;
	    for(int i=0;i<l1;i++){
	        
	        if(e1.e_name[i]==e2.e_name[i])
	            count++;
	    }
	    if(count==l1)
	        printf("Same");
	    else
	        printf("Not Equal");
	    
	}
	else
	    printf("Not Equal");
	}
	
void swap(E *e1, E *e2){
	char t[20];
	int temp=(*e1).e_id;
	(*e1).e_id=(*e2).e_id;
	(*e2).e_id=temp;
	
	
	strcpy((*e1).e_name,t);
	strcpy((*e2).e_name,(*e1).e_name);
	strcpy(t,(*e2).e_name);
	
	float tem=(*e1).e_sal;
	(*e1).e_sal=(*e2).e_sal;
	(*e2).e_sal=tem;
	}
	
void display(E e2){
	printf("\nName: %s\nID: %d\nSalary: %f",e2.e_name,e2.e_id,e2.e_sal);
	}
	
void main(){
	E e1,e2;
	accept(&e1);
	accept(&e2);
	swap(&e1,&e2);
	display(e1);
	display(e2);
	}
