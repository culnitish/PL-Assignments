#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int a[],int l,int r)
{
    int partIndex=l,i;
    int pivot=a[r];
    for(i=l;i<r;i++)
    {
        if(a[i]<=pivot)
        {
            swap(&a[partIndex],&a[i]);
            partIndex++;
        }
    }
    swap(&a[partIndex],&a[r]);
    return partIndex;

}
void Quicksort(int a[],int l,int r)
{
    int Pindex;
    if(l<r)
    {
       Pindex=Partition(a,l,r);
       Quicksort(a,l,Pindex-1);
       Quicksort(a,Pindex+1,r);
    }
}


int main()
{
    int n,a[100],i;
    printf("\n Enter No of elemets");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    Quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
