#include<stdio.h>
struct node{
int pow,coe;
struct node* next;
};
struct node* first=NULL;

struct node* second=NULL;

struct node* ans=NULL;
struct node* getnode(int p,int c)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->pow=p;
    temp->coe=c;
    temp->next=NULL;
};
main()
{
    int i,j,k,l,n,sw;
    struct node *a,*b,*c,*p;
    while(1)
    {
        printf("\n1.Addition\n2.Multiplication\n3Exit");
scanf("%d",&sw);
if(sw==1){
 printf("Enter the number of elements in first equation\n");
    scanf("%d",&n);
    printf("Enter power and coefficient respectively\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        if(first==NULL){   first=getnode(j,k); p=first; }
        else {
    p->next=getnode(j,k);
    p=p->next;

        }
    }p->next=first;
    printf("\n");

printf("Enter the number of elements in second equation\n");
    scanf("%d",&n);
    printf("Enter power and coeffient \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        if(second==NULL){   second=getnode(j,k); p=second; }
        else {
    p->next=getnode(j,k);
    p=p->next;

        }
    } p->next=second;

    a=first;
    b=second;
    c=ans;
int temp=-1; int br=0,cr=0,flag;
    while(1)
    {
        if(a->pow>b->pow)temp=1;
        else if (b->pow>a->pow)temp=2;
        else temp=0; printf("*");
        switch(temp)
        {
            case 1: if(ans==NULL){ans=getnode(a->pow,a->coe);c=ans;}
                    else {
                    c->next=getnode(a->pow,a->coe); c=c->next;
                    } a=a->next; br=1; break;
            case 2:  if(ans==NULL){ans=getnode(b->pow,b->coe);c=ans;}
                    else {
                    c->next=getnode(b->pow,b->coe); c=c->next;
                    } b=b->next; cr=1; break;
            case 0: if(ans==NULL){ans=getnode(a->pow,a->coe+b->coe);c=ans;}
                    else {
                    c->next=getnode(a->pow,a->coe+b->coe); c=c->next;
                    } a=a->next; b=b->next; br=1; cr=1; break;
        }
        if(a==first&&b==second)temp=2;
if(a==first&&br==1) {flag=1; break;}
else if(b==second&&cr==1){flag=2;break;}

    }
  if(flag==2&&temp!=2)
    while(1)
    {
        if(ans==NULL){ans=getnode(a->pow,a->coe);c=ans;}
                    else {
                    c->next=getnode(a->pow,a->coe); c=c->next;
                    }
                    a=a->next;
                    if(a==first)break;
    }

else if(flag==1&&temp!=2)
while(1)
{
   if(ans==NULL){ans=getnode(b->pow,b->coe);c=ans;}
                    else {
                    c->next=getnode(b->pow,b->coe); c=c->next;
                    }
                    b=b->next;
                    if(b==second)break;
}


 p=ans;
 printf("power coeficcient\n");
 while(p!=NULL)
{
    printf("%d    %d\n",p->pow,p->coe);
    p=p->next;
}

}
else if(sw==2){
first=NULL;
second=NULL;
ans=NULL;
 printf("enter the number of elements in first equation\n");
    scanf("%d",&n);
    printf("enter power_____coeffient \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        if(first==NULL){   first=getnode(j,k); p=first; }
        else {
    p->next=getnode(j,k);
    p=p->next;

        }
    } p->next=first;
    printf("\n");

printf("enter the number of elements in second equation\n");
    scanf("%d",&n);
    printf("enter power_____coeffient \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        if(second==NULL){   second=getnode(j,k); p=second; }
        else {
    p->next=getnode(j,k);
    p=p->next;

        }
    }
p->next=second;
//multiplication

a=first;
    b=second;


while(1)
{
    a=first;

while(1)
{
    struct node* temp=getnode(b->pow+a->pow, b->coe*a->coe);
    printf("%d  %d\n",temp->pow,temp->coe);

    if (ans==NULL){  ans=getnode(b->pow+a->pow, b->coe*a->coe);c=ans;  }
    else { c=ans; int tem=5;
        while(c!=NULL)
        {
            if(c->pow==temp->pow){  c->coe=c->coe+temp->coe;   tem=0;  break;  } c=c->next;
        }
        if(tem!=0)
       {
           c=ans;
           while(c->next!=NULL)c=c->next;
           c->next=temp;
       }

    }

a=a->next;
if(a==first)break;
}
b=b->next;
if(b==second)break;


}c=c->next;
c->next=ans;
p=ans;
 printf("\npower coeficcient\n");
 while(1)
{
    printf("%d    %d\n",p->pow,p->coe);
    p=p->next;
    if(p==ans)break;
}


}
else break;
    }

}
