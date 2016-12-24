#include<stdio.h>
void inputArrA(int a[][10],int m,int n) // 1 st array input
{
    int i,j;
    printf("\n enter  array elements \n");
    for(i=0;i<m;i++)
    {
    for(j=0;j<n;j++)
    scanf("%d",&(*(*(a + i) + j)));
    }
}

void inputArrB(int b[][10],int p,int q)  //enter 2nd array
{
    int i,j;
     printf("\n enter array elements \n");
     for(i=0;i<p;i++)
    {
    for(j=0;j<q;j++)
    scanf("%d",&(*(*(b + i) + j)));
    }
}
void print(int c[][10],int m,int n)
{
    int i,j;
            for(i=0;i<m;i++)
            {
            for(j=0;j<n;j++)
            printf("%d ",*(*(c + i) + j));
            printf("\n");
            }
}
void Addition(int a[][10],int b[][10],int c[][10],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
     {
        for(j=0;j<n;j++)
        *(*(c + i) + j)= *(*(a + i) + j)+ *(*(b + i) + j);
    }
}
void Transpose(int a[][10],int m,int n)
{
    int d,i,j;



    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }

}
void Multiplication(int a[][10],int b[][10],int c[][10],int m,int n,int p)
{
    int i,j,k;
          for(i=0;i<m;i++)
            {
                for(j=0;j<m;j++)
                {
                    c[i][j]=0;
                    for(k=0;k<n;k++)
                    {
                        c[i][j]+=a[i][k]*b[k][j];
                    }
                }

            }
}
void saddle_point(int a[][10],int m,int n)
{
         int max=0,i,j,k,f;
    for(i=0;i<m;i++)
   {
    for(j=1;j<n;j++)
     {
          if(a[j][i]>a[max][i])
           max=j;
     }
        f=0;
    for(k=0;k<n;k++)
    {
     if(a[max][i]>a[max][k])
     {
              f=1;
              break;
     }
    }
    if(f==0)
    printf("%d ",a[max][i]);
  }
}
int main()
{
int n,a[10][10],b[10][10],c[10][10],i,j,d,ch,k,f,m,p,q;

    do
    {
    printf("\n ARRAY MENU");
    printf("\n 1.ADDITION");
    printf("\n 2.TRANSPOSE");
    printf("\n 3.MULTIPLICATION");
    printf("\n 4.SADDLE POINT");
    printf("\n enter your choice(1-4)");
    scanf("%d",&ch);
switch(ch)
{
    case 1:
        printf("\n enter 1st Matrix");
        printf("\n Enter Row Size: ");
        scanf("%d",&m);
        printf("\n Enter Column Size: ");
        scanf("%d",&n);
        inputArrA(a,m,n);
        printf("\n enter  2nd Matrix");
        printf("\n Enter Row Size: ");
        scanf("%d",&p);
        printf("\n Enter Column Size: ");
        scanf("%d",&q);
        inputArrB(b,p,q);
        if(m==p&&n==q)
        {
           Addition(a,b,c,m,n);
           printf("\n");
            print(c,m,n);
        }
        else
            printf("\n Addition Not Possible\n");

    break;

    case 2:
        printf("\n enter  Matrix");
        printf("\n Enter Row Size: ");
        scanf("%d",&m);
        printf("\n Enter Column Size: ");
        scanf("%d",&n);
        inputArrA(a,m,n);
        printf("\n");
        Transpose(a,m,n);
        printf("\n");
       // print(a,m,n);
    break;

    case 3:
        printf("\n enter 1st Matrix");
        printf("\n Enter Row Size: ");
        scanf("%d",&m);
        printf("\n Enter Column Size: ");
        scanf("%d",&n);
        inputArrA(a,m,n);
        printf("\n enter  2nd Matrix");
        printf("\n Enter Row Size: ");
        scanf("%d",&p);
        printf("\n Enter Column Size: ");
        scanf("%d",&q);
        inputArrB(b,p,q);
          if(n==p)
          {
            Multiplication(a,b,c,m,n,p);
            printf("\n");
            print(c,n,p);
          }

        else
            printf("\n Multiplication Not Possible");

    break;

    case 4:
        printf("\n");
        printf("\n enter 1st Matrix");
        printf("\n Enter Row Size: ");
        scanf("%d",&m);
        printf("\n Enter Column Size: ");
        scanf("%d",&n);
        inputArrA(a,m,n);
        saddle_point(a,m,m);
        break;
}
}while(ch>=1&&ch<=4);
    return 0;
}
