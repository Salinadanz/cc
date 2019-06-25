#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<dos.h>
#include<ctype.h>
#include<math.h>

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

HANDLE wHnd;    // Handle to write to the console.

HANDLE rHnd;    // Handle to read from the console.

COORD coord={0,0};

int rin(int ,int);

void encrypt(char[],int,int);

int decrypt(char[],int);

int numlen(int);

int check(int);

void blank(int,int,int,int);

int readi(int,int,int);

int reads(char[],int);

void gt(int,int);//goto coordinate.

void cap();//caption

void aboutus();

void bor(int ,int ,int ,int,int);//creates a border.

void cursor(int ,int);

int customerdata(struct customer []);

int lookacc(struct customer);

int countrequests();

void statuscheck(int);

int customerequests();

int blockacc();

int cmpdata(struct customer[]);

void color(int);

int main()
{
	int d1,d2,k=18;
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
	// Change the window title:
    SetConsoleTitle("STAFF APP");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0,160, 40};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {169, 43};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button	
	o1:
	system("cls");
	system("color f0");
	color(240);
	cap();
	cursor(0,1);
	gt(70,20);printf("   Requests");
	gt(70,25);printf("Block Account");
	gt(70,30);printf("   About us");
	gt(70,35);printf("     Exit");
	gt(130,40);printf("Press ESC to exit");
	o2:
	color(251);	
	bor(60,18,33,4,1);
	bor(60,23,33,4,1);
	bor(60,28,33,4,1);
	bor(60,33,33,4,1);
	color(245);
	bor(60,k,33,4,5);
	color(240);
	d1=_getch();
	if(d1==224)
	{
		d2=_getch();
		if(d2==80)
		{
			if(k==33)
			k-=15;
			else
			k+=5;
		}
		else if(d2==72)
		{
			if(k==18)
			k+=15;
			else
			k-=5;
		}
		goto o2;
	}
	else if(d1==13)
	{
		if(k==18)
		{
			customerequests();
		}
		else if(k==23)
		{
			blockacc();
		}
		else if(k==28)
		aboutus();
		else if(k==33)
		exit(1);
	else if(d1==27)
	exit(-1);
	goto o1;
	}
	else if(d1==8)
	return 0;
	else if(d1==27)
	exit(2);
    goto o1;
}
int rin(int a,int b)
{
	srand(GetTickCount64());
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
int check(int a)
{
	FILE *fp;
	struct customer1 c1;
	fp=fopen("customer.bin","rb");
	while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		if(decrypt(c1.an,2)==a)
		return 1;
	}
	return 0;
}
void blank(int x,int y,int x1,int y1)
{
	int i,j;
	for(i=x;i<=x+x1;i++)
	{
		for(j=y;j<=y+y1;j++)
		{
			gt(i,j);printf(" ");
		}
	}
}
int readi(int a,int b,int c)
{
	int n,i,n3=0,n2[10];
	float j=0;
	if(c==0)
	{
	for(i=0;i<a;i++)
	{
	if(i>a-2)
	cursor(1,100);
	else 
	cursor(1,3);	
	n=getch();
	if(n==b&&i!=0)
	{
		n3=a-i;
		break;
	}
	else if(isdigit(n)!=0)
	{
		printf("%c",n);
		n2[i]=n;
		j+=(n-48)*pow(10,(a-i-1));
	}
	else if(n==8)
	{
		if(i>0)
		{
			i-=2;
			printf("\b \b");
			j-=(n2[i+1]-48)*pow(10,a-i-2);
		}
		else
		return -1;
	}
    else if(n==27)
    return -2;
    else 
	{
	i--;
	continue;	
	} 
    }
    }
    else if(c==1)
    {
    i=-1;	
    while(1)
    {
    if(i>a-2)
	cursor(1,100);
	else 
	cursor(1,3);	
    i++;	
	n=getch();
	if(n==b&&i!=0)
	{
		n3=a-i;
		break;
	}
	else if(i>a-1&&n!=8)
	{
		i--;
		continue;
	}
	else if(isdigit(n)!=0)
	{
		printf("%c",n);
		n2[i]=n;
		j+=(n-48)*pow(10,(a-i-1));
	}
	else if(n==8)
	{
		if(i>0)
		{
			i-=2;
			printf("\b \b");
			j-=(n2[i+1]-48)*pow(10,a-i-2);
		}
		else
		return -1;
	}
    else if(n==27)
    return -2;
    else 
	{
	i--;
	continue;	
	} 
    }
	}
	cursor(1,3);
    j/=pow(10,n3);
    return j;
}
int reads(char c[],int a)
{
	char g;
	int l,i=-1;
	while(1)
	{
	i++;	
	g=getch();
	l=g;
	printf("%c",g);
	c[i]=g;
	if(l==8)
	{
		if(i==0)
		return -1;
		else if(i!=0)
		{
			printf(" \b \b");
			i-=2;
		}
	}
	else if(l==27)
	exit(8);
	else if(l==13)
	{
		c[i]='\0';
		break;
	}
	else if(i>a-1)
	{
		i--;
		printf("\b \b");
		continue;
	}
    }
    return 1;
}
void gt(int x,int y)
{
    coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void cap()
{
	bor(8,4,153,9,5);
	gt(45,6);printf(" __  __     _     ____   ____      ____     _     _   _  _  _     _    _____  ____");
	gt(45,7);printf("|  \\/  |   / \\   / ___) / ___)    | __ )   / \\   | \\ | || |/ )   | |  (_   _)|  _ \\");
	gt(45,8);printf("| |\\/| |  / _ \\  \\___ \\ \\___ \\    |  _ \\  / _ \\  |  \\| || ' /    | |    | |  | | | |");
	gt(45,9);printf("| |  | | / ___ \\  ___) ) ___) )   | |_) )/ ___ \\ | |\\  || . \\    | |___ | |  | |_| |");
	gt(45,10);printf("|_|  |_|(_/   \\_)(____/ (____/    |____/(_/   \\_)|_| \\_||_|\\_)   |_____)|_|  |____/");
	gt(45,10);
}
void aboutus()
{
	system("cls");
	color(240 );
	cap();
	color(242 );
	gt(67,16);printf("Designed By:");
	color(244);
	Sleep(200);printf(" M");
	color(241);
	printf("anoj Khatri");
	gt(80,18);Sleep(200);color(244);printf("A");
	color(241);printf("bhishek Karkee");
	gt(80,20);Sleep(200);color(244);printf("S");
	color(241);printf("anjay");
	gt(80,22);Sleep(200);color(244);printf("S");
	color(241);printf("afal");
	gt(75,25);
	Sleep(200);
	color(240);
	printf("Press any key");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	getch();	
}
void cursor(int a,int b)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = b;
   info.bVisible = a;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void bor(int x,int y,int x1, int y1,int type)
{
	int i;
	if(type==1)
	{
		gt(x,y);
		printf("%c",218);
		gt(x+x1,y);
		printf("%c",191);
		gt(x,y+y1);
		printf("%c",192);
		gt(x+x1,y+y1);
		printf("%c",217);
		for(i=1;i<x1;i++)
		{
			gt(x+i,y);
			printf("%c",196);
			gt(x+i,y+y1);
			printf("%c",196);
		}
		for(i=1;i<y1;i++)
		{
			gt(x,y+i);
			printf("%c",179);
			gt(x+x1,y+i);
			printf("%c",179);
		}
	}
	else if(type==2)
	{
		gt(x,y);
		printf("%c",214);
		gt(x+x1,y);
		printf("%c",183);
		gt(x,y+y1);
		printf("%c",211);
		gt(x+x1,y+y1);
		printf("%c",189);
		for(i=1;i<x1;i++)
		{
			gt(x+i,y);
			printf("%c",196);
			gt(x+i,y+y1);
			printf("%c",196);
		}
		for(i=1;i<y1;i++)
		{
			gt(x,y+i);
			printf("%c",186);
			gt(x+x1,y+i);
			printf("%c",186);
		}
	}
	else if(type==3)
	{
		gt(x,y);
		printf("%c",213);
		gt(x+x1,y);
		printf("%c",184);
		gt(x,y+y1);
		printf("%c",212);
		gt(x+x1,y+y1);
		printf("%c",190);
		for(i=1;i<x1;i++)
		{
			gt(x+i,y);
			printf("%c",205);
			gt(x+i,y+y1);
			printf("%c",205);
		}
		for(i=1;i<y1;i++)
		{
			gt(x,y+i);
			printf("%c",179);
			gt(x+x1,y+i);
			printf("%c",179);
		}
	}
	else if(type==4)
	{
		gt(x,y);
		printf("%c",201);
		gt(x+x1,y);
		printf("%c",187);
		gt(x,y+y1);
		printf("%c",200);
		gt(x+x1,y+y1);
		printf("%c",188);
		for(i=1;i<x1;i++)
		{
			gt(x+i,y);
			printf("%c",205);
			gt(x+i,y+y1);
			printf("%c",205);
		}
		for(i=1;i<y1;i++)
		{
			gt(x,y+i);
			printf("%c",186);
			gt(x+x1,y+i);
			printf("%c",186);
		}
    }
	else if(type==5)
	{
		gt(x,y);
		printf("%c",220);
		gt(x+x1,y);
		printf("%c",220);
		gt(x,y+y1);
		printf("%c",223);
		gt(x+x1,y+y1);
		printf("%c",223);
		for(i=1;i<x1;i++)
		{
			gt(x+i,y);
			printf("%c",220);
			gt(x+i,y+y1);
			printf("%c",223);
		}
		for(i=1;i<y1;i++)
		{
			gt(x,y+i);
			printf("%c",221);
			gt(x+x1,y+i);
			printf("%c",222);
		}
	}
	printf("\n");
}
int customerdata (struct customer c[])
{
	FILE *fp;
	int n=0;
	struct customer1 c1;
	fp=fopen("customer.bin","rb+");
	while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		strcpy(c[n].name,c1.name);
		c[n].balance=c1.balance;
		c[n].an=decrypt(c1.an,2);
		c[n].pin=decrypt(c1.pin,3);
		c[n].status[0]=c1.status[0];
		c[n].status[1]=c1.status[1];
		c[n].status[2]=c1.status[2];
		c[n].status[3]=c1.status[3];
		n++;
	}
	fclose(fp);
	return(n);
}
int lookcustomer(struct customer a)
{
	FILE *fp;
	struct customer1 c[100],c1;
	int k=25,d1,d2,f,g;
	blank(40,14,80,25);
	blank(8,40,20,0);
	color(250);
	bor(8,20,42,14,5);
	color(240);
	gt(18,18);printf(         "Customer profile");
	gt(10,22);printf("         Name: %s",a.name);
	gt(10,24);printf("  Account no.: %d",a.an);
	gt(10,26);printf("      Balance: %.2f",a.balance);
	gt(10,28);printf("          PIN: %d",a.pin);
	gt(10,30);printf("   Status now: ");statuscheck(a.status[0]);
	gt(10,32);printf("Status before: ");statuscheck(a.status[1]);
	if(a.status[2]==0)
	{
	gt(80-strlen(a.name)/2,24);
	color(242);printf("%s ",a.name);
	color(240);printf("has no requests");
	gt(85,27);printf("Press any key");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	getch();
	}
	else if(a.status[2]==3||a.status[2]==2)
	{
	gt(80-strlen(a.name)/2,24);
	color(242);printf("%s",a.name);
	color(240);printf("'s request is processed");
	gt(85,27);printf("Press any key");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	getch();
    }
	else if(a.status[2]==1)
	{
		o1:
		gt(80-strlen(a.name),20);printf("%s has requested to ",a.name);
		if(a.status[3]==1)
		{
		color(244);printf("Block");
	    }
		if(a.status[3]==3)
		{
			if(a.status[0]==0)
			{
			color(244);printf("Process");
		    }
			else
			{
			color(244);printf("Unblock");
		    }
		}
		color(240);
		printf(" his account.");
		gt(79,23);printf("Do you want to accept his request?");
		gt(94,26);printf("Yes");
		gt(94,29);printf("No");
		o2:
		color(251);	
		bor(90,25,10,2,1);
		bor(90,28,10,2,1);
		color(245);
		bor(90,k,10,2,5);
		color(240);
		d1=_getch();
		if(d1==224)
		{
			d2=_getch();
			if(d2==80)
			{
				if(k==28)
				k-=3;
				else 
				k+=3;
			}
			else if(d2==72)
			{
				if(k==25)
				k+=3;
				else
				k-=3;
			}
			goto o2;
		}
		if(d1==13)
		{
			if(k==25)
			{
				a.status[2]=3;
				fp=fopen("customer.bin","rb+");
				f=0;
	            while(fread(&c1,sizeof(c1),1,fp)!=0)
	            {
		        if(a.an==decrypt(c1.an,2))
		        {
		        	strcpy(c[f].name,a.name);
		        	c[f].balance=a.balance;
		        	encrypt(c[f].an,a.an,2);
		        	encrypt(c[f].pin,a.pin,3);
		        	c[f].status[0]=a.status[0];
		        	c[f].status[1]=a.status[1];
		        	c[f].status[2]=a.status[2];
		        	c[f].status[3]=a.status[3];
		        	f++;
		        	continue;
				}
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
			}
			else if(k==28)
			{
		    blank(8,14,140,20);
			return 0;
			}
		}	
	}
	blank(8,14,140,24);
	return 1;
}
int countrequests()
{
	FILE *fp;
	int n=0;
	struct customer1 c1;
	fp=fopen("customer.bin","rb+");
	while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		if(c1.status[2]==1)
		n++;
	}
	fclose(fp);
	return n;
}
void statuscheck(int a)
{
	if(a==0)
	printf("Processing");
	else if(a==1)
	printf("Blocked");
	else if(a==3)
	printf("Running");
}
int customerequests()
{
	int i,r,r1,n,m,m1=0,k=17,n1=0,d1,d2;
	struct customer c[100],c1[100];
	o1:
	system("cls");	
	m=customerdata(c);
	if(m==1)
	m1=1;
	else if(m==2)
	m1=2;
	else if(m>=3)
	m1=3;
	n=0;
	cursor(0,1);
	color(240);	
	cap();
	color(242);
	gt(75,15);printf("Customers");
	gt(130,38);color(240);printf("Press BACKSPACE to go back");
	gt(130,40);printf("Press ESC to exit");
	if(m==0)
	{
		gt(65,17);color(244);printf("You dont have any customers");
		gt(73,20);color(240);printf("Press any key");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		getch();
		return -1;
	}
	r=countrequests();
	gt(8,40);printf("Requests: %d",r);
	for(i=0;i<m1;i++)
	{	
	    gt(60,18+n*8);printf("       Name: ");
	    gt(60,19+n*8);printf("Account no.: ");
	    gt(60,20+n*8);printf("    Balance: ");
	    gt(60,21+n*8);printf("        PIN: ");
	    gt(60,22+n*8);printf("     Status: ");
        n++;
	}
	o2:
	m=customerdata(c);	
	if(m==0)
	{
		blank(40,16,80,20);
		gt(65,17);color(244);printf("You dont have any customers");
		gt(73,20);color(240);printf("Press any key");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		getch();
		return -1;
	}
	if(m==1)
	m1=1;
	else if(m==2)
	m1=2;
	else if(m>=3)
	m1=3;
	for(n=0;n<m1;n++)
	{
	gt(73,18+n*8);printf("%s",c[n+n1].name);
	gt(73,19+n*8);printf("%d",c[n+n1].an);
	gt(73,20+n*8);printf("%.2f",c[n+n1].balance);
	gt(73,21+n*8);printf("%d",c[n+n1].pin);
	gt(73,22+n*8);statuscheck(c[n+n1].status[0]);
    }	
	color(251);
	if(m1==1)
	bor(55,17,50,6,1);
	else if(m1==2)
	{
		bor(55,17,50,6,1);
		bor(55,25,50,6,1);
	}
	else if(m1==3)
	{
		bor(55,17,50,6,1);
		bor(55,25,50,6,1);
		bor(55,33,50,6,1);
	}
	r1=c[(k-17)/8+n1].status[2];
	
	if(r1==0||r1==3||r1==2)
	{
	color(245);
	bor(55,k,50,6,5);
    }
	else if(r1==1)
	{
	color(244);	
	bor(55,k,50,6,5);
    }
	color(240);
	d1=_getch();
	if(cmpdata(c)==0)
	{
		m=customerdata(c);
		blank(40,16,80,25);
		k=17;
		n1=0;
		goto o1;
	}
	if(d1==224)
	{
		d2=_getch();
		Sleep(100);
		if(d2==80)
		{
			if(k==(17+8*(m1-1)))
			{
				if(n1<m-3)
				{
					blank(73,18,26,4);
					blank(73,26,26,4);
					blank(73,34,26,4);
					n1++;
					goto o2;
				}
			}
			else
			k+=8;
		}
		else if(d2==72)
		{
			if(k==17)
			{
				if(n1>0)
				{
					blank(73,18,26,4);
					blank(73,26,26,4);
					blank(73,34,26,4);
					n1--;
					goto o2;
				}
			}
			else
			k-=8;
		}
		goto o2;
	}
	else if(d1==13)
	{
		lookcustomer(c[(k-17)/8+n1]);
		goto o1;
	}
	else if(d1==8)
	return -1;
	else if(d1==27)
	exit(11);
	goto o2;
}
int blockacc()
{
	int i,r,r1,n,m,m1=0,k=17,k2=23,n1=0,d1,d2,e1,e2,f=0,g;
	struct customer c2[100];
	struct customer1 c1,c[100];
	FILE *fp;
	system("cls");
	color(240);
	cap();
	color(242);
	gt(75,15);printf("Customers");
	gt(130,38);printf("Press BACKSPACE to go back");
	gt(130,40);printf("Press ESC to exit");
	o1:	
	m=customerdata(c2);
	if(m==0)
	{
		gt(65,17);color(244);printf("You dont have any customers");color(240);
		gt(73,20);printf("Press any key");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		getch();
		return -1;
	}
	if(m==1)
	m1=1;
	else if(m==2)
	m1=2;
	else if(m>=3)
	m1=3;
	n=0;
	color(240);
	cursor(0,1);	
	for(i=0;i<m1;i++)
	{	
	    gt(60,18+n*8);printf("       Name: ");
	    gt(60,19+n*8);printf("Account no.: ");
	    gt(60,20+n*8);printf("    Balance: ");
	    gt(60,21+n*8);printf("        PIN: ");
	    gt(60,22+n*8);printf("     Status: ");
        n++;
	}
	o2:	
	m=customerdata(c2);
	if(m==0)
	{
		blank(40,16,80,20);
		gt(65,17);color(244);printf("You dont have any customers");
		gt(73,20);color(240);printf("Press any key");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		printf(".");
		Sleep(300);
		getch();
		return -1;
	}
	if(m==1)
	m1=1;
	else if(m==2)
	m1=2;
	else if(m>=3)
	m1=3;	
	for(n=0;n<m1;n++)
	{
	gt(73,18+n*8);printf("%s",c2[n+n1].name);
	gt(73,19+n*8);printf("%d",c2[n+n1].an);
	gt(73,20+n*8);printf("%.2f",c2[n+n1].balance);
	gt(73,21+n*8);printf("%d",c2[n+n1].pin);
	gt(73,22+n*8);statuscheck(c2[n+n1].status[0]);
    }
	color(251);
	if(m1==1)
	bor(55,17,50,6,1);
	else if(m1==2)
	{
		bor(55,17,50,6,1);
		bor(55,25,50,6,1);
	}
	else if(m1>=3)
	{
	bor(55,17,50,6,1);
	bor(55,25,50,6,1);	
	bor(55,33,50,6,1);
    }
	r1=c2[(k-17)/8+n1].status[0];
	if(r1==0||r1==1)
	{
	color(245);
	bor(55,k,50,6,5);
    }
	else if(r1==3)
	{
	color(244);	
	bor(55,k,50,6,5);
    }
	color(240);
	d1=_getch();
	if(cmpdata(c2)==0)
	{
		m=customerdata(c2);
		n1=0;
		k=17;
		blank(40,16,80,25);
		goto o1;
	}
	if(d1==224)
	{
		d2=_getch();
		Sleep(100);
		if(d2==80)
		{
			if(k==17+8*(m1-1))
			{
				if(n1<m-3)
				{
					blank(73,18,26,4);
					blank(73,26,26,4);
					blank(73,34,26,4);
					n1++;
					goto o2;
				}
			}
			else
			k+=8;
		}
		else if(d2==72)
		{
			if(k==17)
			{
				if(n1>0)
				{
					blank(73,18,26,4);
					blank(73,26,26,4);
					blank(73,34,26,4);
					n1--;
					goto o2;
				}
			}
			else
			k-=8;
		}
		goto o2;
	}
	else if(d1==13)
	{
		if(c2[(k-17)/8+n1].status[0]==0||c2[(k-17)/8+n1].status[0]==1)
		{
			system("ECHO ");
			goto o2;
		}
		o3:
		blank(8,16,110,25);
		blank(119,16,20,20);
		gt(70-strlen(c2[(k-17)/8+n1].name)/2,20);
		printf("Do you want to block ");color(244);printf("%s",c2[(k-17)/8+n1].name);
		color(240);gt(76,24);printf("Yes");
		gt(76,27);printf("No");
		o4:
		color(251);
		bor(73,23,8,2,1);
		bor(73,26,8,2,1);
		color(245);
		bor(73,k2,8,2,5);
		color(240);
		e1=_getch();
		if(e1==224)
		{
			e2=_getch();
			if(e2==80)
			{
				if(k2==26)
				k2-=3;
				else
				k2+=3;
			}
			else if(e2==72)
			{
				if(k2==23)
				k2+=3;
				else
				k2-=3;
			}
			goto o4;
		}
		else if(e1==13)
		{
			if(k2==26)
			{
		    blank(40,16,70,20);
			goto o1;
		    }
		}
		else if(e1==8)
		goto o1;
		else if(e1==27)
		exit(9);
		else
		goto o4;
		c2[(k-17)/8+n1].status[1]=c2[(k-17)/8+n1].status[0];
		c2[(k-17)/8+n1].status[0]=1;
		c2[(k-17)/8+n1].status[3]=1;
		c2[(k-17)/8+n1].status[2]=0;
		fp=fopen("customer.bin","rb+");
		f=0;
	    while(fread(&c1,sizeof(c1),1,fp)!=0)
	    {
		    if(c2[(k-17)/8+n1].an==decrypt(c1.an,2))
		    {
		       	strcpy(c[f].name,c2[(k-17)/8+n1].name);
		       	c[f].balance=c2[(k-17)/8+n1].balance;
		       	encrypt(c[f].an,c2[(k-17)/8+n1].an,2);
		       	encrypt(c[f].pin,c2[(k-17)/8+n1].pin,3);
		       	c[f].status[0]=c2[(k-17)/8+n1].status[0];
		       	c[f].status[1]=c2[(k-17)/8+n1].status[1];
		       	c[f].status[2]=c2[(k-17)/8+n1].status[2];
		       	c[f].status[3]=c2[(k-17)/8+n1].status[3];
		       	f++;
		       	continue;
			}
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
	}
	else if(d1==27)
	exit(10);
	else if(d1==8)
	return 0;
	goto o1;
}
int cmpdata(struct customer a[])
{
	FILE *fp;
	int n=0;
	struct customer c[100];
	struct customer1 c1;
	fp=fopen("customer.bin","rb+");
	while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		strcpy(c[n].name,c1.name);
		if(strcmp(a[n].name,c[n].name)!=0)
		return 0;
		c[n].balance=c1.balance;
		if(a[n].balance!=c[n].balance)
		return 0;
		c[n].an=decrypt(c1.an,2);
		if(a[n].an!=c[n].an)
		return 0;
		c[n].pin=decrypt(c1.pin,3);
		if(a[n].pin!=c[n].pin)
		return 0;
		c[n].status[0]=c1.status[0];
		if(a[n].status[0]!=c[n].status[0])
		return 0;
		c[n].status[1]=c1.status[1];
		if(a[n].status[1]!=c[n].status[1])
		return 0;
		c[n].status[2]=c1.status[2];
		if(a[n].status[2]!=c[n].status[2])
		return 0;
		c[n].status[3]=c1.status[3];
		if(a[n].status[3]!=c[n].status[3])
		return 0;
		n++;
	}
	if(numlen(a[n].pin)==3&&numlen(a[n].an)==6)
	return 0;
	fclose(fp);
	return(1);
}
void color(int a)
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),a );
}
