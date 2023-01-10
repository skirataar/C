#include<stdio.h>
typedef enum{lparen,rparen,plus,minus,mult,divi,mod,power,eos,opnd} precedence;
void infix_to_postfix(char []);
void push(int ,int *,int []);
int pop(int *,int []);
void print_token(precedence);
precedence get_token(char *,int *,char []);
int main()
{
	char infix[50];
	printf("enter a valid infix expression\n");
	scanf("%s",infix);
	infix_to_postfix(infix);
	return 0;
}
void infix_to_postfix(char infix[])
{
	int top=-1,n=0,stack[50];
	precedence token;
	char symb;

	int isp[]={0,4,1,1,2,2,2,3,0};
	int icp[]={5,4,1,1,2,2,2,3,0};
	stack[++top]=eos;
	
	for(token=get_token(&symb,&n,infix);token!=eos;token=get_token(&symb,&n,infix))
	{
	    if(token==opnd)
	    {
	    printf("%c",symb);
	    }
	    else if(token==rparen)
	    {
	    	while(stack[top]!=lparen)
	    	{
	   	 print_token(pop(&top,stack));
	    	}
	    pop(&top,stack);
	    
	    }
	
	else
	{
		while(isp[stack[top]]>=icp[token])
		{
			print_token(pop(&top,stack));
		}
	push(token,&top,stack);	
	}
	}
	while((token=pop(&top,stack))!=eos)
	{
	print_token(token);
	}
	
		
}
void push(int tok,int *top,int stack[])
{
	stack[++(*top)]=tok;
}
int pop(int *top,int stack[])
{
return(stack[(*top)--]);	
}
precedence get_token(char *symbol,int *n,char infix[])
{
	*symbol=infix[(*n)++];
	switch(*symbol)
	{
	case '(':return lparen;
	
	case ')':return rparen;
	
	case '+':return plus;
	
	case '-':return minus;
	
	case '*':return mult;
	
	case '/':return divi;
	
	case '%':return mod;

	case '^':return power;
	
	case '\0':return eos;
	
	default:return opnd;
	
	}
}
void print_token(precedence token)
{
	switch(token)
	{
	
	
	case plus:printf("+");
	break;
	case minus:printf("-");
	break;
	case mult:printf("*");
	break;
	case divi:printf("/");
	break;
	case mod:printf("%%");
	break;
	case power:printf("^");
	break;
	}
}
