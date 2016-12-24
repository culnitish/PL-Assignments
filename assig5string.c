#include<stdio.h>
void bsort()
{
    int n,i,j;
    printf("Enter the number of string : ");
    scanf("%d",&n);
    char a[n][100];
    printf("Enter the strings : \n");
    for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
    printf("Before Sorting : \n");
    for(i=0;i<n;i++)
        printf("%s \n",a[i]);
    printf("\n");
    char *t;
    t=(char*)malloc(1);
    printf("After Bubble Sort : \n");
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(a[i],a[j])>0)
            {
                strcpy(t,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],t);
            }
        }
    }
    for(i=0;i<n;i++)
            printf("%s  \n",a[i]);
        printf("\n");
}
void ssort()
{
    int n,i,pos,j;
    printf("Enter the number of strings : ");
    scanf("%d",&n);
    char b[n][100];
    printf("Enter the strings : \n");
    for(i=0;i<n;i++)
        {
            scanf("%s",&b[i]);
        }
    printf("Before Sorting : \n");
    for(i=0;i<n;i++)
        printf("%s  \n",b[i]);
        printf("\n");
    char *t,*max;
    t=(char*)malloc(1);
    max=(char*)malloc(1);
    printf("After Selection Sort : \n");
    for(i=0;i<n-1;i++)
    {
        strcpy(max,b[i]);
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(max,b[j])<0)
            {
                strcpy(max,b[j]);
                pos=j;
            }
        }
        strcpy(t,b[i]);
        strcpy(b[i],b[pos]);
        strcpy(b[pos],t);

    }
    for(i=0;i<n;i++)
            printf("%s  \n",b[i]);
        printf("\n");
}
int main()
{
    int n,x,z;
    do
    {
    printf("\nEnter your choice \n1.Ascending \n2.Descending : ");
    scanf("%d",&n);
    switch(n)
    {
        case 1 :bsort() ;
                break;
        case 2 : ssort();
                break;
        default : printf("\nWrong Choice\n");

    }
    printf("\n Want to enter more Press 1 \n");
    scanf("%d",&z);
    }while(z==1);
    return 0;
}
