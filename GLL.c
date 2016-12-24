#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* sub;
    struct node* next;

};

void add(struct node** head,int x)
{
    struct node* a=(struct node*)malloc(sizeof(struct node));
    a->data=x;
    a->next=NULL;
    a->sub=NULL;
    struct node *last=*head;
    if (*head == NULL)
    {*head = a;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next=a;
}

void sub(struct node** head)
{
    struct node *last=*head;
    struct node* a=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter the Subtopic \n");
    scanf("%d",&x);
    a->data=x;
    a->next=NULL;
    a->sub=NULL;
    if(last->sub==NULL)
            last->sub=a;
}

void printList(struct node *node)
{int i=0;
  while (node != NULL)
  {i=1;
     printf("Chapter no.%d \n", node->data);

     struct node *temp;
             temp=node;

            while(temp->sub!=NULL)
            {
                temp=temp->sub;
                printf("   Subtopic  %d.%d\n",temp->data,i);
                i++;
            }
       node = node->next;
  }
}

int main()
{
    struct node *head=NULL;
    struct node *temp=NULL;
    printf("Enter the no. of chapters\n");
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {   printf("Enter the data");
        int b;
        scanf("%d",&b);
        add(&head,b);

        int a;
        check:
        printf("Do you want to enter a sub topic 1.Yes 2.No\n");
        scanf("%d",&a);
        if(a==1)
        {  struct node *last=head;
           while (last->next != NULL)
                  last = last->next;
            if(last->sub==NULL)
               sub(&last);
            else
            {
             struct node *temp;
             temp=last;

            while(temp->sub!=NULL)
            {
                temp=temp->sub;
            }
            sub(&temp);
            }

            goto check;

        }
    }
    printList(head);

}
