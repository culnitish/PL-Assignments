#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;

}*head;
typedef struct node node;
void insert(int val,int n)
{
    int i;
    node *temp = (node*)malloc(sizeof(node));
    temp->data=val;
    temp->link=NULL;
    if(n==1)
    {
        temp->link=head;
        head=temp;
        return;
    }
    node *temp1=head;
    for(i=0;i<n-2;i++)
    {
        temp1=temp1->link;
    }
    temp->link=temp1->link;
    temp1->link=temp;


}

void display()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

void print(node *p)
{
    if(p==NULL)
    {
        return;
    }

   print(p->link) ;
    printf("%d ",p->data);
}

void reverse()
{
    node *prev,*next,*current;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

void del(int d)
{
    int i;
    node *temp3;
    temp3=head;
if(d==1)
{
    head=head->link;
    free(temp3);
    return;
}
for(i=0;i<d-2;i++)
{
   temp3= temp3->link;
}
node *temp4;
temp4=temp3->link;
temp3->link=temp4->link;
free(temp4);
}
int main()
{
   int ch,pos,val;
    head=NULL;
    static int count=1;
    do{
  printf("\nLINKED LIST MENU");
  printf("\n1.INSERT AT ANY POSTION");
  printf("\n2.DELETE FROM ANY POSITION");
  printf("\n3.DISPLAY A LIST");
  printf("\n4.DISPLAY IN REVERSE");
  printf("\n5.REVERSE THE LIST");
  printf("\n Enter your Choice(1-5)");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
        printf("\n Enter position to insert Element");
        scanf("%d",&pos);
        if(pos>0&&pos<=count)
        {
            printf("\n Enter value to insert");
            scanf("%d",&val);
              insert(val,pos);
             count++;
        }

        else
            printf("\nWrong Position can't Insert");
            break;
    case 2:
        printf("\n enter position to delete(1...n)");
        scanf("%d",&pos);
        if(pos<=count)
        del(pos);
        else
          printf("\nWrong Position can't Delete");
        break;
    case 3:
        display();
        break;
    case 4:
        print(head);
        break;
    case 5:
        reverse();
        display();

        break;
   default:printf("Wrong Choice");

  }
    }while(ch<=5);


    return 0;
}
