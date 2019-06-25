#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
struct customer
{
	char name[25];
	int an;
	float balance;
	int pin;
	int status[4];
};

struct customer1
{
	char name[25];
	char an[10];
	float balance;
	char pin[5];
	int status[4];
};

int rin(int ,int);

void encrypt(char[],int,int);

int decrypt(char[],int);

int numlen(int);

int del(int);

int main()
{
	FILE *fp;
	char a,b;
	int i;
	struct customer1 c1;
	struct customer c;
	u:	
	printf("\n1.Add\n2.Read\n3.Delete\n4.Exit");
	b=getch();
	system("cls");
	if(b=='1')
	{
	fp=fopen("customer.bin","ab+");
	do
	{
		system("cls");
		printf("Enter name, account no. ,balance, pin ,status??");
		scanf("%s%d%f%d%d%d%d%d",c.name,&c.an,&c.balance,&c.pin,&c.status[0],&c.status[1],&c.status[2],&c.status[3]);
		strcpy(c1.name,c.name);
		c1.balance=c.balance;
		encrypt(c1.an,c.an,2);
		encrypt(c1.pin,c.pin,3);
		c1.status[0]=c.status[0];
		c1.status[1]=c.status[1];
		c1.status[2]=c.status[2];
		c1.status[3]=c.status[3];
		fwrite(&c1,sizeof(c1),1,fp);
		printf("Another??");
		a=getch();
	}while(a=='y');
	fclose(fp);
    }
    else if (b=='2')
    {
	fp=fopen("customer.bin","rb+");
	while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		strcpy(c.name,c1.name);
		c.balance=c1.balance;
		c.an=decrypt(c1.an,2);
		c.pin=decrypt(c1.pin,3);
		c.status[0]=c1.status[0];
		c.status[1]=c1.status[1];
		c.status[2]=c1.status[2];
		c.status[3]=c1.status[3];
		printf("\nName: %s\nAcc. no.: %d\nBalance: %.2f\nPin: %d\nStatus: %d %d %d %d\n\n"
		,c.name,c.an,c.balance,c.pin,c.status[0],c.status[1],c.status[2],c.status[3]);
	}
	fclose(fp);
    }
    else if(b=='3')
    {
	    printf("Account to delete?? ");
		scanf("%d",&i);
		del(i);	
		system("cls");
		goto u;
	}
    else if(b=='4')
    return 1;
    goto u;
}
int rin(int a,int b)
{
	srand(time(0));
	int d=0,i;
	for(i=0;i<b;i++)
	{
		if(i==0)
		{
		d=d*10+rand()%a+1;
		continue;
	    }
		d=d*10+rand()%(a+1);
	}
	return d;
}
void encrypt(char a[],int b,int x)
{
	int i,j=0,y,n;
	char c;
	n=numlen(b);
	for(i=n-1;i>=0;i--)
	{
		y=b%10;
		y+=(101-((i+x)*(i+x)));
		a[i]=y;
		b/=10;
	}
	a[n]='\0';
}
int decrypt(char a[],int x)
{
	int i,j=0,y,n;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		y=a[i];
		y-=(101-((i+x)*(i+x)));
		j=j*10+y;
	}
	return j;
}
int numlen(int a)
{
	int i=0;
	while(a!=0)
	{
		i++;
		a/=10;
	}
	return i;
}
int del(int a)
{
	FILE *fp;
	int f=0,g;
	struct customer1 c1,c[100];
	fp=fopen("customer.bin","rb+");
	f=0;
	            while(fread(&c1,sizeof(c1),1,fp)!=0)
	            {
		        if(a==decrypt(c1.an,2))
		        continue;
				strcpy(c[f].name,c1.name);
		        c[f].balance=c1.balance;
		        strcpy(c[f].an,c1.an);
		        strcpy(c[f].pin,c1.pin);
		        c[f].status[0]=c1.status[0];
		        c[f].status[1]=c1.status[1];
		        c[f].status[2]=c1.status[2];
		        c[f].status[3]=c1.status[3];
	            f++;
				}
	            fclose(fp);
	            fp=fopen("customer.bin","wb+");
	            for(g=0;g<f;g++)
	            {
	            fwrite(&c[g],sizeof(c[g]),1,fp);
	            }
	            fclose(fp);
	            return 1;
}
