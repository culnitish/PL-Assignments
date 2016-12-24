#include<stdio.h>
#define SIZE 10
struct Sparse
{
    int row;
    int col;
    int val;
};
typedef struct Sparse Sparse;

int arrayinput(Sparse A[],int m,int n)
{
       int i,j,k=1,a;
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
          scanf("%d",&a);
          if(a!=0)
          {
              A[k].row=i;
              A[k].col=j;
              A[k].val=a;
              k++;
          }
       }
   }

   A[0].row=m;
   A[0].col=n;
   A[0].val=k-1;
   return k;
}

void Transpose(Sparse S1[],Sparse S2[])
{
	int i,j,k=1,l;
	S2[0].row=S1[0].col;
	S2[0].col=S1[0].row;
	S2[0].val=S1[0].val;
	for(i=0;i<S1[0].col;i++)
	{
		for(j=1;j<=S1[0].val;j++)
		{
			if(S1[j].col==i)
			{
				S2[k].row=S1[j].col;
				S2[k].col=S1[j].row;
				S2[k].val=S1[j].val;
				k++;
			}
		}
	}
}

FastTranspose(Sparse S1[],Sparse S2[])
  {
     int S[SIZE]={0},T[SIZE],i,j;
     S2[0].row=S1[0].row;
     S2[0].col=S1[0].col;
     S2[0].val=S1[0].val;
     T[0]=1;
     for(i=1;i<=S1[0].val;i++)
     {
         S[S1[i].col]++;
     }
     for(i=1;i<S1[0].col;i++)
     {
         T[i]=T[i-1]+S[i-1];
     }
     for(i=1;i<=S1[0].val;i++)
     {
         j=T[S1[i].col];
         S2[j].row=S1[i].col;
         S2[j].col=S1[i].row;
         S2[j].val=S1[i].val;
         T[S1[i].col]=j+1;
     }
  }
void Addition(Sparse A[],Sparse B[],Sparse C[])
{
    int i,j,k;
  if(A[0].row!=B[0].row||A[0].col!=B[0].col)
{
    printf("\n Addition Not Possible");
}
	 i=1,j=1,k=1;
	while(i<=A[0].val && j<=B[0].val)
	{
	if(A[i].row==B[j].row && A[i].col==B[j].col)
	{
	C[k].row=A[i].row;
	C[k].col=A[i].col;
	C[k].val=A[i].val + B[j].val;
	i++;j++;k++;
	}
	else
	{
	if(A[i].row==B[j].row)
	{
	if(A[i].col<B[j].col)
	{
	C[k].row=A[i].row  ;
	C[k].col=A[i].col ;
	C[k].val=A[i].val;
	i++;k++;
	}
	else
	{
    C[k].row=B[j].row;
	C[k].col=B[j].col ;
	C[k].val=B[j].val  ;
	j++;k++;
	}
	}
	else
	{
	if(A[i].row<B[j].row)
	{
	C[k].row=A[i].row;
    C[k].col=A[i].col;
	C[k].val=A[i].val;
	i++;k++ ;
	}
	else
	{
	C[k].row=B[j].row;
	C[k].col=B[j].col ;
	C[k].val=B[j].val  ;
	j++;k++;
	}
	}
	}
  }
	while(i<=A[0].val)
	{
	C[k].row=A[i].row;
	C[k].col=A[i].col ;
	C[k].val=A[i].val  ;
	i++;k++;
	}

	while(j<=B[0].val)
	{
	C[k].row=B[j].row ;
	C[k].col=B[j]. col ;
	C[k].val=B[j]. val;
	j++; k++;
	}

  C[0].row=A[0].row;
	C[0].col=A[0].col;
   C[0].val=k-1;
}

void print(Sparse S[])
{
    int i;
    for(i=0;i<=S[0].val;i++)
    {
        printf("%d %d %d",S[i].row,S[i].col,S[i].val);
        printf("\n");
    }
}
int main()
{
   Sparse A[SIZE],B[SIZE],C[SIZE];
   int m,n,i,j,a,k=1,p,q,l=1,x,y,ch;
   do
   {
      printf("SPARSE MENU");
      printf("\n1.Addition");
      printf("\n2.FasT Transpose");
      printf("\n3.Simple Transpose");
      printf("\nEnter Choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        printf("\nEnter row and column of 1st matrix ");
        scanf("%d%d",&m,&n);
        x=arrayinput(A,m,n);
        printf("\nEnter row and column of 2nd matrix ");
        scanf("%d%d",&p,&q);
        y=arrayinput(B,p,q);
        Addition(A,B,C);
        printf("\nArray A :\n");
        print(A);
	    printf("\nArray B :\n");
	    print(B);
	    printf("Addition of the two matrices is: \n");
	    printf("\nArray C :\n");
	    print(C);
         break;
        case 2:
        printf("\nEnter row and column of  matrix ");
        scanf("%d%d",&m,&n);
        x=arrayinput(A,m,n);
        printf("\nArray A :\n");
        print(A);
        printf("\n\nFAST TRANSPOSE:-\n");
        FastTranspose(A,C);
        print(C);
        break;
        case 3:
        printf("\nEnter row and column of  matrix ");
        scanf("%d%d",&m,&n);
        x=arrayinput(A,m,n);
        printf("\nArray A :\n");
        print(A);
        printf("\n\nSIMPLE TRANSPOSE:-\n");
        Transpose(A,C);
        print(C);
        break;
        default:
        printf("Wrong Choice");
      }
   }while(ch>0&&ch<=3);
	return 0;
}
