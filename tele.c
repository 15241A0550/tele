#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
struct Postpaid
{
char phonenumber[20];
char name[50];
float amount;
}s;
void addplans();
void subplans();

char get;
int main()
{	
int password;
int phonenumber;
char choice;
system("cls");
getch();
system("cls");
while (1)
{
system("cls");
printf("\n Enter\n A : for adding data plans.\n L : for submitting a data plan");
choice=getche();
choice=toupper(choice);
switch(choice)
{
case 'A':
	addplans();break;
case 'L':
	subplans();break;			
default:
	system("cls");
	printf("Incorrect Input");
	printf("\nAny key to continue");
	getch();
	}
}
}
void addplans()
{
	FILE *f;
	char test;
	f=fopen("c:/file.sql","ab+");
	if(f==0)
	{   f=fopen("c:/file.sql","wb+");
		system("cls");
		
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter phone number:");
		scanf("%s",&s.phonenumber);
		printf("\n Enter name:");
		fflush(stdin);
		scanf("%[^\n]",&s.name);
		printf("\n Enter amount:");
		scanf("%f",&s.amount);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("1 record successfully added");
		printf("\n Press esc key to exit, any other key to add other record:");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}
void subplans()
{
	FILE *f;
	int i;
	if((f=fopen("c:/file.sql","rb"))==NULL)
		exit(0);
	system("cls");
	printf("Phone Number\t\tUser Name\t\t\tAmount\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%-10s\t\t%-20s\t\tRs. %.2f /-",s.phonenumber,s.name,s.amount);
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}
