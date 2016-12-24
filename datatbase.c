#include<stdio.h>
struct student{
	char n[20],dob[20];
	char rno[20],regno[20];

};

void print(struct student s)
{
	printf("\n\n Name          : %s",s.n);
	printf("\n Date of Birth : %s",s.dob);
	printf("\n Roll no       : %s",s.rno);
	printf("\n Reg. no       : %s",s.regno);
}

void insert()
{
	int x;
	//scanf("%d",&x);
	struct student s; int ch;  FILE *f;
	f=fopen("G://stud.txt","a+");
	l1:
	printf("\nEnter name          : ");
	scanf("%s",s.n);
	printf("Enter Date of birth : ");
	scanf("%s",s.dob);
	printf("Enter Roll no       : ");
	scanf("%s",&s.rno);
	printf("Enter Reg. no       : ");
	scanf("%s",&s.regno);

	if(f==NULL)
	{
		printf("\nError file not created.");
		fclose(f);
		return;
	}
	fprintf(f," %s %s %s %s ",s.n,s.dob,s.rno,s.regno);
	l2:
	printf("\nAdd more records.(0/1)");
	scanf("%d",&ch);
	if(ch==1)
	goto l1;
	else if(ch==0)
	{fclose(f);
	 getch();
	 return;
	}
	else
	{
	 printf("\nWrong choice!!! Enter again.");
	 goto l2;
	}

}

void display()
{
	struct student s;   long long int i; FILE *f;

	f=fopen("G://stud.txt","r");
	if(f==NULL)
	{
		printf("\nError file not created.");
		fclose(f);
		return;
	}

	while(fscanf(f," %s %s %s %s ",s.n,s.dob,s.rno,s.regno)!=EOF)
	{
		print(s);
	}
	fclose(f);
	getch();
}

void search()
{
	struct student s;   long long int i; char name[20]; FILE *f;
	printf("\nEnter Search Name : ");
	scanf("%s",name);

	f=fopen("G://stud.txt","r");
	if(f==NULL)
	{
		printf("\nError file not created.");
		fclose(f);
		return;

	}

	while(fscanf(f," %s %s %s %s ",s.n,s.dob,s.rno,s.regno)!=EOF)
	{
		if(strcmp(s.n,name)==0)
		{
			printf("\nRecord Found.");
			print(s);
			fclose(f);
			return;
		}
	}

	printf("\nRecord not found.");
	fclose(f);
	getch();
}

void modify()
{
	char name[20]; long long int size; int flag=0;
	struct student s,t; FILE *f;
	printf("\nEnter modify Name : ");
	scanf("%s",name);
	f=fopen("G://stud.txt","r");
	FILE *f2;
	f2=fopen("G://tempa.txt","w");


	if(f2==NULL)
	{
		printf("\nError file not created.");
		return;
	}
	while(fscanf(f," %s %s %s %s ",s.n,s.dob,s.rno,s.regno)!=EOF)
	{
		if(strcmp(s.n,name)==0)
		{   flag=1;
			printf("\nEnter name          : ");
	        scanf("%s",t.n);
	        printf("Enter Date of birth : ");
	        scanf("%s",t.dob);
	        printf("Enter Roll no       : ");
	        scanf("%s",t.rno);
	        printf("Enter Reg. no       : ");
	        scanf("%s",t.regno);

	        fprintf(f2," %s %s %s %s ",t.n,t.dob,t.rno,t.regno);
	        printf("\nRecord Modified");

		}
		else fprintf(f2," %s %s %s %s ",s.n,s.dob,s.rno,s.regno);


	}
	if(flag==0)
	{printf("\nRecord not found.");
	}
	fclose(f);
	fclose(f2);
	remove("G://stud.txt");
	rename("G://tempa.txt","G://stud.txt");
	getch();
	return;
}

void del()
{   char a[20]; struct student s; int flag=0;
	printf("\nEnter the name to delete : ");
	scanf("%s",a);
	FILE *f,*f2;
	f=fopen("G://stud.txt","r");
	f2=fopen("G://tempa.txt","w");
	while(fscanf(f," %s %s %s %s ",s.n,s.dob,s.rno,s.regno)!=EOF)
	{
		if(strcmp(s.n,a)!=0)
		{
			fprintf(f2," %s %s %s %s ",s.n,s.dob,s.rno,s.regno);
		}
		else{
          flag=1;
          printf("\nRecord Deleted");
		}

	}
	if(flag==0)
	{
		printf("\nRecord not found.");
	}
	int x;
		fclose(f);
	fclose(f2);
	remove("G://stud.txt");

	rename("G://tempa.txt","G://stud.txt");
	getch();
}
void main()
{ int ch;
  FILE *f;
  do
  {
  printf("\n        DATA FILE HANDLING         ");
  printf("\n Enter : 1 : Insert Records        ");
  printf("\n         2 : Display Records       ");
  printf("\n         3 : Search                ");
  printf("\n         4 : Modify                ");
  printf("\n         5 : Delete                ");
  printf("\n         6 : Exit                  ");
  printf("\n-----------------------------------");
  printf("\n Choice : ");
  scanf("%d",&ch);

  switch(ch)
  {
  	case 1 : insert();
  	         break;
  	case 2 : display();
  	         break;
  	case 3 : search();
  	         getch();
	         break;
	case 4 : modify();
	         break;
	case 5 : del();
	         break;
	case 6 : return;

	default: printf("\nWrong choice entered!!! Enter again.");

  }

  }while(ch!=6);

	return;
}
