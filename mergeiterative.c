#include<stdio.h>
int main()
{
    int i,j,k,l1,l2,n,m,h1,h2,f1,f2,z;
    printf("enter the size of the matrix\n");
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i=i*2)
    {
        l1=0;
        k=0;
        while(l1+i<n)
        {
            h1=l1+i-1;
            l2=h1+1;
            h2=l2+i-1;
            if(h2>=n)
                h2=n-1;
            f1=l1;
            f2=l2;
            while(f1<=h1&&f2<=h2)
            {
                if(a[f1]<=a[f2])
                {
                    b[k++]=a[f1++];
                }
                else
                    b[k++]=a[f2++];
            }
            while(f1<=h1)
            {
                b[k++]=a[f1++];
            }
            while(f2<=h2)
            {
                b[k++]=a[f2++];
            }
        l1=h2+1;
        }
        for(z=l1; k<n; z++) /*any pair h1 */
        b[k++]=a[z];
           for(z=0;z<n;z++)
            a[z]=b[z];

    }
          for(z=0;z<n;z++)
            printf("%d ",a[z]);
            return 0;
}
