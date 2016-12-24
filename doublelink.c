#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
    {
    int data;
    char name[25];
    float marks;
    struct Node *prev;
    struct Node *next;
    }*head;

typedef struct Node Node;

Node* getnew_node(int x,char *s,float marks)
{
    Node *newnode =(Node*)malloc(sizeof (Node));
    newnode->data=x;
    strcpy(newnode->name,s);
    newnode->marks=marks;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insertAtHead(int x,char *s,float marks)
{
  Node *Newnode=getnew_node(x,s,marks);
  if(head==NULL)
  {
      head=Newnode;
      return;
  }
  head->prev=Newnode;
  Newnode->next=head;
  head=Newnode;
}

void insertAtTail(int x,char *s,float marks)
{
    Node *Newnode=getnew_node(x,s,marks);
    Node *temp=head;
    if(head==NULL)
    {
        head=Newnode;
        return;
    }
    while(temp->next!=NULL)
    {
       temp=temp->next;
    }
    temp->next=Newnode;
    Newnode->prev=temp;

}
void print()
{
    Node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t%s\t%f\n\n",temp->data,temp->name,temp->marks);
        temp=temp->next;
    }
}
void reverse()
{
    Node *temp;
    temp=head;
    if(temp==NULL)
        return;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d\t%s\t%f\n\n",temp->data,temp->name,temp->marks);
        temp=temp->prev;
    }
}
void modify(int pos,int val,char *s,float marks)
{
    int i=1;
    Node *temp;
    temp=head;
    while(i<pos)
    {
       temp=temp->next;
       i++;
    }
    temp->data=val;
    strcpy(temp->name,s);
    temp->marks=marks;
}
void InsertAt(int pos,int val,char *s,float marks)
{
    int i;
    Node *Newnode=getnew_node(val,s,marks);
    Node *temp=head;
    if(pos==1)
    {
        insertAtHead(val,s,marks);
        return;
    }
    for(i=0;i<pos-2;i++)
    {
     temp=temp->next;
    }
    Newnode->prev=temp;
    Newnode->next=temp->next;
    temp->next=Newnode;
    temp=Newnode->next;
    temp->prev=Newnode;
}
void del(int pos)
{
    int i=0;
    Node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Deletion Not Possible Empty");
    }
    for(i=0;i<pos-1;i++)
    {
     temp=temp->next;
    }
    if(pos==1)
    {
        if(temp->next==NULL)
        {
                printf("Node deleted from list");
                free(temp);
                temp = head = NULL;
                return;
        }

    }
    if(temp->next==NULL)
    {
            temp->prev->next = NULL;
            free(temp);
            printf("Node deleted from list");
            return;
    }
     temp->next->prev = temp->prev;
        if (pos != 1)
            temp->prev->next = temp->next;    /* Might not need this statement if i == 1 check */
        if (pos == 1)
            head = temp->next;
        printf("\n Node deleted");
        free(temp);

}
int main()
{
    head=NULL;
    char s[25];
    float marks;
    int ch,i,j,n=0,num,pos;
    do
    {
   printf("\nDOUBLE LIST MENU");
   printf("\n1.Insert At Head ");
   printf("\n2.Insert At Tail ");
   printf("\n3.Insert At Position ");
   printf("\n4.Delete At position ");
   printf("\n5.Modify At position ");
   printf("\n6.Display ");
   printf("\n7.Reverse Display ");
   printf("\n Enter Your Choice(1-7): ");
   scanf("%d",&ch);
     switch(ch)
      {
            case 1:
            printf("\n Enter Roll No To Insert: ");
            scanf("%d",&num);
            printf("\n Enter Name Of student: ");
            scanf("%s",s);
            printf("\n Enter Marks: ");
            scanf("%f",&marks);
              insertAtHead(num,s,marks);
              n++;
            break;
            case 2:
            printf("\n Enter Roll No To Insert: ");
            scanf("%d",&num);
            printf("\n Enter Name Of student: ");
            scanf("%s",s);
            printf("\n Enter Marks: ");
            scanf("%f",&marks);
              insertAtTail(num,s,marks);
              n++;
            break;
            case 3:
             printf("\n Enter position To Insert: ");
             scanf("%d",&pos);
             printf("\n Enter Roll No To Insert: ");
             scanf("%d",&num);
             printf("\n Enter Name Of student: ");
             scanf("%s",s);
             printf("\n Enter Marks: ");
             scanf("%f",&marks);
             if(pos-1==n)
             {
              insertAtTail(num,s,marks);
              n++;
             }
             else
             {
                if(pos-1>=0&&pos<=n)
                  {
                    InsertAt(pos,num,s,marks);
                    n++;
                  }
                  else
                  printf("\n Insertion Not Possible");
             }

             break;
            case 4:
            printf("\n Enter position To Delete: ");
            scanf("%d",&pos);
            if(pos>0&&pos<=n)
                {
                del(pos);
                n--;
                }
            else
                printf("\nDeletion Not Possible");
            break;
            case 5:
             printf("\n Enter position To Modify: ");
             scanf("%d",&pos);
             printf("\n Enter Roll No To Insert: ");
             scanf("%d",&num);
             printf("\n Enter Name Of student: ");
             scanf("%s",s);
             printf("\n Enter Marks: ");
             scanf("%f",&marks);

                if(pos>0&&pos<=n)
                    modify(pos,num,s,marks);
                else
                    printf("\n Modification Not Possible");
              break;
            case 6:
              printf("\n");
              print();
              break;
            case 7:
                printf("\n");
               reverse();
              break;
           default :
                print("\nWrong Choice");
      }
    }while(ch>0&&ch<=7);

    return 0;
}
