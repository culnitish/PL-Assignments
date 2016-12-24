#include<stdio.h>
#include<string.h>

int string_len(char *s)
{
    int i=0;
    while(*(s+i)!='\0')
    {
      i++;
    }
   return i;
}
int string_compare(char *s,char *s1)
{
    int i=0;
    while(*s!='\0')
    {
        if(*s>*s1)
            return 1;
        else if(*s<*s1)
            return -1;

        s++;
        s1++;
    }
    return 0;
}
int string_ispalindrome(char *s)
{
    char *p,*q;
    p=q=s;
    while(*p!='\0')
    {
        p++;
    }
    p--;
    while(q<p)
    {
        if(*q!=*p)
          return 0;
        q++;
        p--;
    }
    return 1;

}

void string_reverse(char *s)
{
    int i=0;
    char *p,*q,t;
    p=q=s;
    while(*p!='\0')
    {
        p++;
    }
    p--;
    while(q<p)
    {
         t=*q;
        *q=*p;
        *p= t;
         q++;
         p--;
    }
}
void string_copy(char *s1,char *s)
{
   while(*s!='\0')
   {
       *s1=*s;
       s1++;
       s++;
   }
   *s1='\0';

}

void string_concate(char *s,char *s1)
{
    int i=0;
    while(*s!='\0')
    {
        s++;
    }
    while(*s1!='\0')
    {
        *s=*s1;
        s++;
        s1++;

    }
    *s='\0';
}

int string_substr(char *s,char *s1)
{

int len=0,flag=0,i=0,j=0;
while(*(s+i)!='\0')
{
  if(*(s+i)==*(s1+j))
  {
j++;
len++;
 if(len==strlen(s1))
 {
  flag=1;
  break;
 }
  }
  else
  {
   len=0;
    j=0;
   }
i++;
}
return flag;
}

int main()
{
    int ch,i,j,s[100],s1[100],res,len1,len2;
 do
 {
printf("\nSTRING MENU");
printf("\n1.LENGTH OF STRING: ");
printf("\n2.SRTING COMPARISON: ");
printf("\n3.PALINDROME: ");
printf("\n4.REVERSE: ");
printf("\n5.COPY: ");
printf("\n6.CONCATE ");
printf("\n7.SUBSTRING: ");
printf("\n ENTER YOUR CHOICE(1-7): ");
scanf("%d",&ch);
 switch(ch)
  {
   case 1:
        printf("\nEnter String: ");
        fflush(stdin);
        gets(s);
       res= string_len(s);
       printf("\nLength of String %s is %d",s,res);

    break;
   case 2:
    printf("\nEnter 1st String: ");
    fflush(stdin);
    gets(s);
    printf("\nEnter 2nd String: ");
    gets(s1);
    len1=string_len(s);
    len2=string_len(s1);
    if(len1==len2)
    {
     res= string_compare(s,s1);
      if(res==0)
        printf("\nString %s and %s are Equal",s,s1);
      else if(res==1)
        printf("\nString %s >(greater) than  %s",s,s1);
      else
        printf("\nString %s <(less) than %s",s,s1);
    }
    else if(len1>len2)
    {
        printf("\nString %s >(greater) than  %s",s,s1);
    }
    else
        printf("\nString %s <(less) than %s",s,s1);

     break;
     case 3:
    printf("Enter String: ");
    fflush(stdin);
    gets(s);
    res=string_ispalindrome(s);
    if(res==0)
        printf("\nString %s is Not Palindrome.",s);
    else
       printf("\nString %s is Palindrome.",s);
    break;
     case 4:
     printf("\nEnter a String: ");
     fflush(stdin);
     gets(s);
     string_reverse(s);
     printf("\nReverse String is %s",s);
    break;
     case 5:
     printf("\nEnter a String: ");
     fflush(stdin);
     gets(s);
     string_copy(s1,s);
     printf("\nCopy String is %s",s1);

    break;
     case 6:
      printf("\nEnter 1st String: ");
      fflush(stdin);
      gets(s);
      printf("\nEnter 2nd String: ");
      gets(s1);
      string_concate(s,s1);
      printf("\nConcated String is %s",s);
    break;
     case 7:
         printf("\nEnter a String: ");
         fflush(stdin);
         gets(s);
         printf("\nEnter a Substring: ");
         gets(s1);
       res= string_substr(s,s1);
         if(res==1)
        printf("\n Substring Found");
         else
        printf("\n Not found!!");
        break;
    default: printf("\nWrong Choice!!!");
  }
 }while(ch>=1&&ch<=7);


    return 0;
}
