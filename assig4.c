#include<stdio.h>
#include<string.h>
typedef struct employee
{
    int code;
    char name[20];
    int salary;
}employee;

void insert(employee st[],int position,int n);
void delete(employee st[],int position,int n);
int search(employee st[],int code,int in);
void print(employee s[],int n);
void read(employee s[],int n);
void sort(employee s[],int n);
void modify(employee s[],int n);

int main()
{
    employee st[30];
    int n,i,op,position,code;
    do
    {
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Search\n5.Print\n6.Sort\n7.Modify\n8.Exit\nEnter your choice::");
        scanf("%d",&op);
        switch(op)
        {
            case 1 :printf("Enter the number of employees::");
                    scanf("%d",&n);
                    read(st,n);
                    break;
            case 2 :printf("Enter the position of record::");
                    scanf("%d",&position);
                    if(position<=n+1)
                    {
                        insert(st,position,n);
                        n++;
                        print(st,n);
                    }
                    else
                        printf("\nCannot be inserted!!!");
                    break;
            case 3 :printf("Enter the code::");
                    scanf("%d",&code);
                    position=search(st,code,n);
                    if(position!=-1)
                    {
                        delete(st,position,n);
                        n--;
                        print(st,n);
                    }
                    else
                        printf("\nCannot be deleted!!!");
                    break;
            case 4 :printf("Enter the code::");
                    scanf("%d",&code);
                    position=search(st,code,n);
                    if(position==-1)
                        printf("\nRecord not found!!!");
                    else
                    {
                        printf("Record found at location %d",position+1);
                        printf("\n%s\t%d\t%d",st[position].name,st[position].code,st[position].salary);
                    }
                    break;
            case 5 :print(st,n);
                    break;
            case 6 :sort(st,n);
                    print(st,n);
                    break;
            case 7 :modify(st,n);
                    print(st,n);
                    break;
    }
    }while(op!=8);
    return 0;
}

void insert(employee st[],int position,int n)
{
    int i;
    printf("Enter the data->\nName\nCode\nSalary\n");
    for(i=n-1;i>=position-1;i--)
    	st[i+1]=st[i];
    scanf("%s%d%d",st[position-1].name,&st[position-1].code,&st[position-1].salary);
}

void delete(employee st[],int position,int n)
{
    int i;
    for(i=position+1;i<n;i++)
        st[i-1]=st[i];
}

int search(employee st[],int code,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(code==st[i].code)
        return(i);
    return(-1);
}

void print(employee st[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("\n%s %d %d ",st[i].name,st[i].code,st[i].salary);
}

void read(employee st[],int n)
{
    int i;
    printf("Enter the data->\nName\nCode\nSalary\n");
    for(i=0;i<n;i++)
    scanf("%s%d%d",st[i].name,&st[i].code,&st[i].salary);
}

void modify(employee st[],int n)
{
    int code,i;
    printf("Enter the code::");
    scanf("%d",&code);
    i=search(st,code,n);
    if(i==-1)
        printf("\nRecord not found!!!");
    else
    {
       printf("Enter the data->\nName\nCode\nSalary\n");
       scanf("%s%d%d",st[i].name,&st[i].code,&st[i].salary);
    }
}

void sort(employee st[],int n)
{
    int i,j;
    employee temp;
    for(i=1;i<n;i++)
        for(j=0;j<n-i;j++)
	    if(st[j].code>st[j+1].code)
	    {
		temp=st[j];
		st[j]=st[j+1];
		st[j+1]=temp;
	    }
}
