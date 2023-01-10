#include<stdio.h>
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
	
void display(E e2){
	printf("Name: %s\nID: %d\nSalary: %f",e2.e_name,e2.e_id,e2.e_sal);
	}
	
void main(){
	E e1;
	accept(&e1);
	display(e1);
	}
