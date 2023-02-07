#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct poly
{
    int cf,px,py,pz;
    struct poly * link;
};

typedef struct poly* P;

P getnode(){
    P temp;
    temp=(P)malloc(sizeof(struct poly));
    return temp;
}

void read_poly(P p1,int n){
    P temp,next;
    for(int i=0;i<n;i++){
        temp=getnode();
        printf("\n%d. enter the cf, px, py, pz: ",i+1);
        scanf("%d%d%d%d",&(temp->cf),&(temp->px),&(temp->py),&(temp->pz));
        next=p1->link;
        temp->link=next;
        p1->link=temp;
    }
}

void display(P head){
    P cur;
    printf("\nelements of polynomial: ");
    cur=head->link;
    if(head->link==head)
        printf("empthy");
    while(cur!=head){
 
        //printf("1");
        if(cur->cf>0){
            printf("+%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
        }
        else{
            printf("%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
        }
        cur=cur->link;
    }
}

P compare(P term, P p2){
    P cur;
    cur=p2->link;
    while(cur!=p2){
        if(term->px==cur->px&&term->py==cur->py&&term->pz==cur->pz){
            return cur;
        }
        cur=cur->link;
    }
    return NULL;
}

void insert(P p3, int cf, int px, int py, int pz){
    P temp,next;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    next=p3->link;
    p3->link=temp;
    temp->link=next;
}

void add_poly(P p1,P p2,P p3){
    P cur,res_pos;
    cur=p1->link;
    while(cur!=p1){
        res_pos=compare(cur,p2);
        if(res_pos==NULL){
            insert(p3,cur->cf,cur->px,cur->py,cur->pz);
        }
        else{
            insert(p3,cur->cf+res_pos->cf,cur->px,cur->py,cur->pz);
            // res_pos->cf=-999;
            // printf("%d",res_pos->cf);
        }
        cur=cur->link;
    }
    cur=p2->link;
    while(cur!=p2){
        if(compare(cur,p1)==NULL){
            insert(p3,cur->cf,cur->px,cur->py,cur->pz);
        }
        cur=cur->link;
    }

}

P delete(P p1){
    P cur=p1->link;
    
}

int eval(P p3){
    P cur=p3->link;
    int x,y,z,sum=0;
    printf("\nEnter the values of x, y and z: ");
    scanf("%d%d%d",&x,&y,&z);
    while(cur!=p3){
        sum=sum+cur->cf*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
        cur=cur->link;
    }
    return sum;   

}
int main(){
    int n,m;
    P p1,p2,p3;
    p1=getnode();
    p2=getnode();
    p3=getnode();
    p1->link=p1;
    p2->link=p2;
    p3->link=p3;
    printf("enter the number of terms of p1: ");
    scanf("%d",&n);
    printf("enter the number of terms of p2: ");
    scanf("%d",&m);
    read_poly(p1,n);
    // display(p1);
    read_poly(p2,m);
    // display(p2);
    // if(compare(p2->link,p1)!=NULL)
    //     insert(p3,(p2->link)->cf,(p2->link)->px,(p2->link)->py,(p2->link)->pz);
    // insert(p1,1,2,3,4);
    add_poly(p1,p2,p3);
    display(p3);
    printf("%d",eval(p3));
    display(p1);
    display(p2);
}
