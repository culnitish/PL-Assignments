#include<stdio.h>
int add_array(int arr[],int a,int k)
	{
	    int f=0,j;
        for( j=0;j<k;j++)
        {
           if(arr[j]==a)
           {
               f=1;
               break;
           }
        }
        return f;
	}
void union_set(int arr[],int arr2[],int l,int k)
{
    int i,f,a,j;
    for(i=0;i<k;i++)
   {
    printf("%d ",arr[i]);
   }
for(i=0;i<l;i++)
 {  f=0;
   a=arr2[i];
    for(j=0;j<k;j++)
    {
       if(arr[j]==a)
       {
           f=1;
           break;
       }
    }
    if(f==0)
    printf("%d ",a);
 }
}

void intersection_set(int arr[],int arr2[],int l,int k)
{
    int i,j,a;
    for(i=0;i<l;i++)
  {
   a=arr2[i];
    for(j=0;j<k;j++)
    {
       if(arr[j]==a)
       printf("%d ",a);
    }
  }
}
void diffA_B(int arr[],int arr2[],int ar[],int *z,int k,int l)
{  int check,i,a;
    for(i=0;i<k;i++)
   {
   a=arr[i];
   check=add_array(arr2,a,l);
   if(check==0)
    ar[(*z)++]=a;
   }
}

void diffB_A(int arr[],int arr2[],int ar[],int *z,int k,int l)
{
    int check,a,i;
    for(i=0;i<l;i++)
  {  // f=0;
   a=arr2[i];
   check=add_array(arr,a,k);

   if(check==0)
    ar[(*z)++]=a;
  }
}
int main() {
	int  n,a,arr[10],i,j,k=0,f,arr2[10],m,ch,ar[50],z=0,check,l=0,temp;

	do
	{
	printf("\nSET MENU");
	printf("\n1.INPUT SET: ");
	printf("\n2.UNION ");
	printf("\n3.INTERSECTION ");
	printf("\n4.A-B AND B-A ");
	printf("\n5.SYMMETRY DIFFERNCE(A-B U B-A) ");
	printf("\n Enter your choice(1-5): ");
	scanf("%d",&ch);
	switch(ch)
	{

	case 1:
	    l=0;
	    k=0;
	printf("\n enter how many elements in SET A: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        scanf("%d",&a);
       check=add_array(arr,a,k);
       if(check==0)
       {
          arr[k]=a;
            k++;
       }

    }
    	printf("\n enter how many elements in SET B: ");
    	scanf("%d",&m);
	for(i=0;i<m;i++)
    {
        scanf("%d",&a);
       check=add_array(arr2,a,l);
       if(check==0)
       {
          arr2[l]=a;
            l++;
       }
    }
	break;
case 2:
///// for UNION
printf("\n UNION\t ");
union_set(arr,arr2,l,k);
break;
case 3:
       ////// for INTERSECTION
        printf("\n INTERSECTION\t");
 intersection_set(arr,arr2,l,k);
break;
case 4:
// A-B
z=0;
diffA_B(arr,arr2,ar,&z,k,l);
temp=z;
printf("\n A-B: ");
for(i=0;i<z;i++)
    printf("%d ",ar[i]);
// B-A
printf("\n B-A: ");
diffB_A(arr,arr2,ar,&z,k,l);
for(i=temp;i<z;i++)
    printf("%d ",ar[i]);
break;
//SYMMETRY DIFFERNCE(A-B U B-A)
case 5:
printf("\n SYMMETRY DIFFERENCE(A-B U B-A)");
z=0;
diffA_B(arr,arr2,ar,&z,k,l);
diffB_A(arr,arr2,ar,&z,k,l);
for(i=0;i<z;i++)
printf("%d ",ar[i]);
break;
default:
    printf("\n WRONG CHOICE!!!");

	}
}while(ch>=1&&ch<=5);

	return 0;
}

