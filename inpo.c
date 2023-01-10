#include<math.h>
#include<stdio.h>
#define size 10

void push(int S[],int *top,int token){
	S[++(*top)]=token;
	}

int pop(int S[],int *top){
	return S[(*top)--];
	}

int comp(int op1, char symbol, int op2){
	switch(symbol){
		case'+': return op1+op2;
		case'-': return op1-op2;
		case'*': return op1*op2;
		case'/': return op1/op2;
		case'%': return op1%op2;
		case'^': return pow(op1,op2);
		}
	}
	
int eval_post(char postfix[]){
	int i=0,token,top=-1,S[size],op1,op2,res;
	char symbol;
	
	while(postfix[i]!='\0'){
		symbol=postfix[i++];
		if(isdigit(symbol)){
			token=symbol-'0';
			push(S,&top,token);
			}
		else{
			op2=pop(S,&top);
			op1=pop(S,&top);
			res=comp(op1,symbol,op2);
			push(S,&top,res);
			}
		}
	return pop(S,&top);

}
	
int main(){
	char postfix[20];
	printf("Enter the postfix expression: ");
	gets(postfix);
	printf("Result: %d",eval_post(postfix));
	return 0;
	}

