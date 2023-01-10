#include<stdio.h>
#define MAX_SIZE 20

void push(char S[],int *top,char symbol){
	S[++(*top)]=symbol;
	}

char pop(char S[],int *top){
	return S[(*top)--];
	}

int F(char c){
	switch(c){
		case'+':
		case'-':return 2;
		case'*':
		case'/':
		case'%':return 4;
		case'$':
		case'^':return 5;
		case'(':return 0;
		case'#':return -1;
		default:return 8;
	}
}

int G(char c){
	switch(c){
		case'+':
		case'-':return 1;
		case'*':
		case'/':
		case'%':return 3;
		case'$':
		case'^':return 6;
		case'(':return 9;
		case')':return 0;
		default:return 7;
	}
}

void conv_inf_post(char infix[20], char postfix[20]){
	int top=-1,i=0,j=0;
	char S[MAX_SIZE],symbol;
	push(S,&top,'#');
	while(infix[i]!='\0'){
		symbol=infix[i++];
		while(F(S[top])>G(symbol))
			postfix[j++]=pop(S,&top);
		if(F(S[top]) != G(symbol))
			push(S,&top,symbol);
		else
			pop(S,&top);
		}
	while(top!=0)
		postfix[j++]=pop(S,&top);
}

void main(){
	char infix[20],postfix[20];
	printf("Enter infix expression: ");
	scanf("%s",infix);
	conv_inf_post(infix,postfix);
	printf("%s",postfix);
	}
//(a+b^(c/d)/(e+f)^g)
