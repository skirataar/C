#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    char info;
    struct node *llink, *rlink;
};
typedef struct node * NODE;

void display(NODE root, int level){
    int i;
    if(root==NULL){
        return;
    }
    display(root->rlink,level+1);
    for(i=0;i<level;i++)
        printf("%c",root->info);
    display(root->llink,level+1);
}

NODE createExp(char postfix[]){
    NODE temp,S[20];
    int i,k;
    char symbol;
    for(i=k=0;(symbol=postfix[i])!='\0';i++){
        temp=(NODE)malloc(sizeof(struct node));
        temp->info=symbol;
        temp->llink=temp->rlink=NULL;
        if(isalnum(symbol))
            S[k++]=temp;
        else{
            temp->rlink=S[--k];
            temp->llink=S[--k];
            S[k++]=temp;
        }
    }
    return S[--k];
}

float Eval(NODE root){
    float num;
    switch(root->info){
        case '+':return Eval(root->llink)+Eval(root->rlink);
        case '-':return Eval(root->llink)-Eval(root->rlink);
        case '*':return Eval(root->llink)*Eval(root->rlink);
        case '/':return Eval(root->llink)/Eval(root->rlink);
        case '$':
        case '^':return pow(Eval(root->llink),Eval(root->rlink));
        defualt: 
                if(isalpha(root->info)){
                    printf("%c",root->info);
                    scanf("%f",&num);
                    return num;
                }
                else
                    return root->info = '0';
    }
}

int main(){
    char postfix[40];
    float res;
    NODE root=NULL;
    printf("Enter the postfix Exp: ");
    scanf("%s",postfix);
    root=createExp(postfix);
    printf("The exp tree is: ");
    display(root,1);
    res=Eval(root);
    printf("Result=%f",res);
    
}
