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

int n;

COORD coord={0,0};//gives origin coordinate

void bor(int ,int ,int ,int,int);//creates a border.

void gt(int,int);//goto coordinate.

void cap();//caption

int signin();

int cracc();//create account

void encrypt(char[],int,int);

int decrypt(char[],int);

void aboutus();

int service(int);

void cursor(int ,int);

int rin(int ,int);

int numlen(int);

int check(int);

float withdraw(struct customer);

void blank(int,int,int,int);//to remove everything in that are and show the clicked area only 

int fast(struct customer);

float deposit(struct customer);

float transfer(struct customer);

int readi(int,int,int);//read integer and move the curser to the next without entering enter

int transferyn(int,float);

float emoney();

int reads(char[],int);//read string

int customerdata(struct customer []);//puts customer data in array of structure and returns no. of data

int replaceinfile(struct customer);

void color(int);

int main()
{
	struct customer1 c11;
	FILE *fp;
    char name[50],q1[5],q2[5];
    float balance=0;
    int s,pin,i;
    int b,h=64,k=16,c1,c2;
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    // Change the window title:
    SetConsoleTitle("MASS APP STORE");
    // Set up the required window size:
    SMALL_RECT windowSize = {0, 0,160, 40};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    // Change the console window size:
    // Create a COORD to hold the buffer size:
    COORD bufferSize = {169, 43};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
    l:		
    system("cls");
	system("color f0");//used for giving color to screen	
	color(240 );
	cap();
    gt(76,18);printf("Sign In");
    gt(70,23);printf("Create an account");
    gt(75,28);printf("About us");
    gt(77,33);printf("Exit");
    gt(130,40);printf("Press ESC to exit");
    cursor(0,1);
	u:	
	color(251 );
	bor(h,16,30,4,1);
	bor(h,21,30,4,1);
	bor(h,26,30,4,1);
	bor(h,31,30,4,1);
	color(245 );
	bor(h,k,30,4,5);
    Sleep(100);
    color(240);
	fflush(stdin);
    c1=_getch();
	if(c1==224)
	{
		c2=_getch();
		if(c2==80)
		{
			if(k==31)
			k-=15;
			else
			k+=5;
		}
		else if(c2==72)
		{
			if(k==16)
			k+=15;
			else
			k-=5;
		}
		goto u;
	}
	else if(c1==13)
	{
		if(k==16)
		{
		s=signin();	
		if(s==0||s==-1)
		goto l;
		else
		{
			service(s);
		}
	    }
		else if(k==21)
		cracc();
		else if(k==26)
		aboutus();
		else if(k==31)
		exit(2);
		goto l;	
	}
	else if(c1==27)
	exit (1);
	else
	goto u;
	return 1;			
}
void gt(int x,int y)
{
    coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
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
int cracc()
{
	float balance;
	struct customer c;
	struct customer1 c1;
	int e=0,f=0,r[5],i,k,l;
	char a[5],b[5],name[50];
	FILE *f1;
	f1=fopen("customer.bin","ab");
	system("cls");
	color(240);
	cap();
	cursor(3,1);
	gt(75,14);color(245);printf("CREATE A ACCOUNT");
	gt(130,38);color(240);printf("Press BACKSPACE to go back");
	gt(130,40);printf("Press ESC to exit");
	color(251);
	bor(50,15,60,13,3);
	o1:
	gt(63,16);color(240);printf("  Name of customer:                    ");
	gt(83,16);l=reads(name,25);
	if(l==-1)
	return 0;
	strcpy(c1.name,name);
	gt(64,16);printf("Amount to deposit:              ");
	gt(83,16);
	balance=emoney();
	if(balance==-1)
	{
		blank(55,17,40,8);
		goto o1;
	}
	c1.balance=balance;
	blank(60,16,30,10);
	gt(71,17);
	printf("Processing");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	jk:
	e=rin(9,6);
	if(check(e)==1)
	goto jk;
	gt(71,17);printf("Account no: %d",e);
	encrypt(c1.an,e,2);
	gt(75,19);
	Sleep(400);
	f=rin(9,4);
	printf("Pin no: %d",f);
	encrypt(c1.pin,f,3);
	gt(60,22);color(242);printf("Your account is being processed");color(240);
	Sleep(2000);
	c1.status[0]=0;
	c1.status[1]=0;
	c1.status[2]=1;
	c1.status[3]=3;
	fwrite(&c1,sizeof(c1),1,f1);
	fclose(f1);
	gt(68,25);
	printf("Press any key");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	getch();
	return 1;
}
int signin()
{
	FILE *fp;
	struct customer c[100],d;
	struct customer1 c1;
	char q1[5],q2[5],pw[5];
	int n=0,i,m,o,z,pw1=0,pw2,pwi;
	fp=fopen("customer.bin","rb");
    while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		strcpy(c[n].name,c1.name);
		c[n].balance=c1.balance;
		c[n].an=decrypt(c1.an,2);
		c[n].pin=decrypt(c1.pin,3);
		n++;
	}
	fclose(fp);
	system("cls");
	color(240);
	cap();
	gt(130,38);printf("Press BACKSPACE to go back");
	gt(130,40);printf("Press ESC to exit");
	color(245);
	gt(81,17);printf("SIGN IN");
	cursor(3,1);
	color(251);
	bor(60,18,50,8,4);
	color(240);	
	gt(68,20);printf("Account no:");
	gt(75,22);printf("Pin:     \b\b\b\b");
	color(242);
	gt(80,21);printf("%c%c%c%c%c%c",223,223,223,223,223,223);
	gt(80,23);printf("%c%c%c%c",223,223,223,223);
	o5:
	blank(79,20,10,0);	
	gt(80,20);
	color(240);
	m=readi(6,0,0);
	if(m==(-1))
	return (-1);
	else if(m==(-2))
	exit(-2);
	for(i=0;i<=n;i++)
	{
		if(c[i].an==m)
		{
			d=c[i];
			o=1;
			break;
		}
	}
	if(check(m)==0)
	{
		gt(65,24);color(244);printf("\a!!!!Account not found!!!!");color(240);
		Sleep(500);
		blank(65,24,30,0);
		goto o5;
	}
	z:
	gt(70,24);printf("                               ");
	for(i=0;i<4;i++)
	{
		h:	
		gt(80+i,22);
		pw[i]=getch();
		pwi=pw[i];
		if(pwi==8)
		{
			if(i>0)
			{
			printf("\b \b");
		    i-=2;
		    }
		    else
		    {
		    	blank(80,20,10,0);
		    	goto o5;
		    }
			continue;
	    }
	    else if(pwi>=48&&pwi<60)
	    {
		printf("%c",pw[i]);
		Sleep(300);
		printf("\b*");
	    }
	    else
	    {
	    	system("ECHO ");
	    	goto h;
		}
	}
	pw[4]='\0';
	pw1=0;
	for(i=0;i<4;i++)
	{
		pw2=pw[i]-'0';
		pw1=pw1*10+pw2;
	}										
	if(pw1==d.pin)
		return (d.an);
	else
	{
		system("ECHO ");
		gt(70,24);color(244);printf("!!!!Incorrect!!!!");color(240);
		blank(80,22,10,0);
		Sleep(250);
		if(++z<3)
		goto z;
		else
		return 0;
	}
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
int service(int a)
{
	FILE *fp;
	struct customer1 c1,c2,c[100];
	struct customer cu;
	int h=70,k=20,d,b,g,f,q=0,d1,d2,k1=20;
	float fl;
	o1:
	cursor(0,1);
	fp=fopen("customer.bin","rb+");
	while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		if(a==decrypt(c1.an,2))
		{
			strcpy(cu.name,c1.name);
			cu.balance=c1.balance;
			cu.an=decrypt(c1.an,2);
			cu.pin=decrypt(c1.pin,3);
			cu.status[0]=c1.status[0];
			cu.status[1]=c1.status[1];
			cu.status[2]=c1.status[2];
			cu.status[3]=c1.status[3];
		}
	}
	fclose(fp);	
	system("cls");
	color(240);
	cap();
	if(q++==0)
	{
		if(cu.status[0]==0&&cu.status[2]==1&&cu.status[3])
	    {
		    gt(67,16);color(244);printf("Your account is being processed");color(240);
		    system("ECHO ");
			Sleep(2000);
			return 0;
	    }
	    else if (cu.status[0]==3)
	    {
	        if(cu.status[1]==3)
			{
			    gt(72,16);color(242);printf("Welcome back %s",cu.name);color(240);
			}	
	    }
	    else if(cu.status[0]==1&&cu.status[2]==0)
	    {
	    	o10:
	    	system("ECHO ");	
	    	gt(67,16);color(244);printf("Your account is blocked");
	    	gt(60,18);color(241);printf("Do you want to unblock your account??");
	    	gt(76,21);color(240);printf("Yes");
	    	gt(76,24);printf("No");
	    	o9:
			color(251);bor(73,20,8,2,1);
	    	bor(73,23,8,2,1);
	    	color(245);bor(73,k1,8,2,5);
	    	d1=_getch();
	    	if(d1==224)
	    	{
	    		d2=_getch();
	    		if(d2==80)
	    		{
	    			if(k1==23)
	    			k1-=3;
	    			else 
	    			k1+=3;
				}
				else if(d2==72)
				{
					if(k1==20)
					k1+=3;
					else 
					k1-=3;
				}
				goto o9;
			}
			else if(d1==13)
			{
				if(k1==20)
				{
					blank(60,16,50,10);
					gt(68,20);color(241);printf("Given to unblock");
					cu.status[2]=1;
					cu.status[3]=3;
					Sleep(1500);
					replaceinfile(cu);
					return 1;
				}
				else if(k1==23)
				return 0;
			}
			else
			goto o9;
	    }
	    else if(cu.status[0]==1&&cu.status[2]==1&&cu.status[3]==3)
	    {
	    	system("ECHO ");
	    	gt(63,16);color(244);printf("Your account is being unblocked");
			Sleep(2000);
			return 1;
		}
		else if(cu.status[0]==1&&cu.status[2]==3)
		{
			gt(63,16);color(242);printf("Your account is successfully unblocked");
			cu.status[2]=0;
		}
		else if(cu.status[0]==0&&cu.status[2]==3)
		{
			gt(63,16);color(242);printf("Your account is successfully processed");
			cu.status[2]=0;
		}
    }
	Sleep(2000);
	cu.status[1]=cu.status[0];
	cu.status[0]=3;
	replaceinfile(cu);
	blank(60,16,60,0);
	gt(130,38);color(240);printf("Press BACKSPACE to go back");
	gt(130,40);printf("Press ESC to exit");
	gt(75,16);printf("                                                        ");
	gt(70,16);color(244);printf("          SERVICES");
	color(254);bor(40,14,90,4,3);
	gt(77,21);color(240);printf("Cash Withdraw");
	gt(80,24);printf("Deposit");
	gt(80,27);printf("Transfer");
	gt(80,30);printf("Log out");color(250);bor(8,35,40,6,5);
	gt(10,37);color(240);printf("   NAME: %s",cu.name);
	gt(10,39);printf("BALANCE: %.2f",cu.balance);
	o2:
	fp=fopen("customer.bin","rb+");
	while(fread(&c1,sizeof(c1),1,fp)!=0)
	{
		if(a==decrypt(c1.an,2))
		{
			strcpy(cu.name,c1.name);
			cu.balance=c1.balance;
			cu.an=decrypt(c1.an,2);
			cu.pin=decrypt(c1.pin,3);
			cu.status[0]=c1.status[0];
			cu.status[1]=c1.status[1];
			cu.status[2]=c1.status[2];
			cu.status[3]=c1.status[3];
		}
	}
	fclose(fp);	
	color(251);
	bor(70,20,27,2,1);
	bor(70,23,27,2,1);
	bor(70,26,27,2,1);
	bor(70,29,27,2,1);	
	color(245);	
	bor(h,k,27,2,5);
	color(240);
	if(cu.status[0]==1&&cu.status[2]!=3)
	{
		q=0;
		blank(40,14,90,20);
		goto o10;
	}
	d=_getch();
	if(d==224)
	{
		b=_getch();
		if(b==80)
		{
			if(k==29)
			k-=9;
			else
			k+=3;
		}
		if(b==72)
		{
			if(k==20)
			k+=9;
			else
			k-=3;
		}
		Sleep(100);
		goto o2;
	}
	else if(d==13)
	{
		blank(40,14,90,17);
		if(k==20)
		{
			fl=withdraw(cu);
			cu.balance-=fl;    
		}
		else if(k==23)
		{
			fl=deposit(cu);
			cu.balance+=fl;
		}
		else if(k==26)
		{
			fl=transfer(cu);
			cu.balance-=fl;
		}
		else if(k==29)
		return 0;
	}
	else if(d==27)
	exit (1);
	else if(d==8)
	{
		return -1;
	}
	replaceinfile(cu);
	goto o1;
}
void cursor(int a,int b)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = b;
   info.bVisible = a;
   SetConsoleCursorInfo(consoleHandle, &info);
}
int rin(int a,int b)
{
	
	time_t time2;
	srand(GetTickCount64());
	int d=0,i;
	for(i=0;i<b;i++)
	{
		if(i==0)
		{
		d=d*10+((rand()+i)*(rand()+d))%a+1;
		continue;
	    }
		d=d*10+((rand()+i)*(rand()+d))%(a+1);
	}
	return d;
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
float withdraw(struct customer a)
{
	int h=70,k=16,d,e;
	float f;
	o1:
	color(240);
	gt(75,16);printf("             ");
	gt(75,18);printf("Fast Withdraw");
	gt(73,23);printf("Entered Withdraw");
	o2:
	cursor(0,1);	
	color(251);	
	bor(70,16,21,4,1);
	bor(70,21,21,4,1);
	color(245);
	bor(h,k,21,4,5);
	color(240);
	d=_getch();
	if(d==224)
	{
		e=_getch();
		if(e==80)
		{
			if(k==21)
			k-=5;
			else
			k+=5;
		}
		else if(e==72)
		{
			if(k==16)
			k+=5;
			else
			k-=5;
		}
		Sleep(100);
		goto o2;
	}
	else if(d==13)
	{
		blank(70,16,25,10);
		if(k==16)
		{
			o12:
			f=fast(a);
			blank(50,14,70,20);
		    if(f==-1)
		    goto o1;
		    if(f>a.balance)
			{
				cursor(0,1);
				blank(50,14,70,10);
				gt(70,19);color(244);printf("!!!!Insufficient fund!!!!");color(240);
				system("ECHO ");
				Sleep(400);
				blank(50,14,70,10);
				blank(50,16,20,0);
				goto o12;
			}
			cursor(3,1);
		    return f;
	    }
		else if(k==21)
		{
			o5:
			cursor(3,1);	
			gt(70,16);printf("Amount to withdraw");
			f=emoney();
			if(f==-1)
			{
				blank(60,16,40,10);
				goto o1;
			}
			cursor(0,1);
			if(f<0)
			f=-f;
			if(f>a.balance)
			{
				cursor(0,1);
				blank(50,14,70,10);
				gt(70,19);color(244);printf("!!!!Insufficient fund!!!!");color(240);
				system("ECHO ");
				Sleep(400);
				blank(50,14,70,10);
				blank(50,16,20,0);
				cursor(3,1);
				goto o5;
			}
			blank(50,15,50,10);
			cursor(0,1);
			return f;
		}
	}
	else if(d==8)
	{
		return 0;
	}
	else if(d==27)
		exit(2);
	else
	goto o2;
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
int fast(struct customer a)
{
	int h=50,k=14,d,e;
	gt(55,16);printf("Rs. 500");
	gt(55,21);printf("Rs. 1000");
	gt(55,26);printf("Rs. 2000");
	gt(95,16);printf("Rs. 4000");
	gt(95,21);printf("Rs. 6000");
	gt(95,26);printf("Rs. 10000");
	o2:
	color(251);	
	bor(50,14,20,4,1);
	bor(50,19,20,4,1);
	bor(50,24,20,4,1);
	bor(90,14,20,4,1);
	bor(90,19,20,4,1);
	bor(90,24,20,4,1);
	color(245);
	bor(h,k,20,4,5);
	color(240);
	d=_getch();
	if(d==224)
	{
		e=_getch();
		if(e==80)
		{
			if(k==24)
			k-=10;
			else
			k+=5;
		}
		else if(e==72)
		{
			if(k==14)
			k+=10;
			else
			k-=5;
		}
		else if(e==77)
		{
			if(h==90)
			h-=40;
			else
			h+=40;
		}
		else if(e==75)
		{
			if(h==50)
			h+=40;
			else
			h-=40;
		}
		Sleep(100);
		goto o2;
	}
	else if(d==13)
	{
		if(h==50)
		{
			if(k==14)
			return 500;
			else if(k==19)
			return 1000;
			else if(k==24)
			return 2000;
		}
		else if(h==90)
		{
			if(k==14)
			return 4000;
			else if(k==19)
			return 6000;
			else if(k==24)
			return 10000;
		}
	}
	else if(d==8)
		return -1;
	else if(d==27)
		exit(9);
	else
		goto o2;
}
float deposit(struct customer a)
{
	int h=70,k=16,d,e;
	float f;
	o1:
	cursor(0,1);	
	blank(50,14,70,15);	
	gt(75,16);printf("             ");
	gt(76,18);printf("Fast Deposit");
	gt(74,23);printf("Entered Deposit");
	o2:
	color(251);	
	bor(70,16,21,4,1);
	bor(70,21,21,4,1);
	color(245);
	bor(h,k,21,4,5);
	color(240);
	d=_getch();
	if(d==224)
	{
		e=_getch();
		if(e==80)
		{
			if(k==21)
			k-=5;
			else
			k+=5;
		}
		else if(e==72)
		{
			if(k==16)
			k+=5;
			else
			k-=5;
		}
		Sleep(100);
		goto o2;
	}
	else if(d==13)
	{
		blank(70,16,25,10);
		if(k==16)
		{
			f=fast(a);
			if(f==-1)
			goto o1;
			return f;
		}
		else if(k==21)
		{
			cursor(3,1);	
			gt(70,16);printf("Amount to deposit");
			f=emoney();
			if(f==-1)
			{
				blank(60,16,40,10);
				goto o1;
			}
			cursor(0,1);
			if(f<0)
			f=-f;
			cursor(1,0);
			return f;
		}
	}
	else if(d==8)
	return 0;
	else if(d==27)
	exit(4);
	else
	goto o2;
}
float transfer(struct customer a)
{
	FILE *fp;
	char p[25];
	int l;
	int h=70,k=16,d,e,t,g,r=20,z1,z2,che;
	struct customer1 c1,c[100];
	struct customer cu;
	float f;
	o1:
	cursor(0,1);
	gt(75,16);printf("             ");
	gt(74,18);printf(" Fast Transfer");
	gt(73,23);printf("Entered Transfer");
	o2:
	color(251);	
	bor(70,16,21,4,1);
	bor(70,21,21,4,1);
	color(245);
	bor(h,k,21,4,5);
	color(240);
	d=_getch();
	if(d==224)
	{
		e=_getch();
		if(e==80)
		{
			if(k==21)
			k-=5;
			else
			k+=5;
		}
		else if(e==72)
		{
			if(k==16)
			k+=5;
			else
			k-=5;
		}
		Sleep(100);
		goto o2;
	}
	else if(d==13)
	{
		if(k==16)
		{
		blank(70,16,25,10);		
		o4:
		gt(65,18);printf("         Target account:      ");
			cursor(3,1);
		    gt(90,18);l=readi(6,0,0);
		    if(l==-1)
		    goto o1;
		    else if(l==-2)
		    exit(7);
		    cursor(0,1);
			if(check(l)==0)
			{
				system("ECHO ");
				blank(90,18,40,0);
				gt(65,21);color(244);printf("!!!!Account doesnot exist!!!!");color(240);
				Sleep(400);
				blank(65,21,30,0);
				goto o4;
		    }
		    else if(l==a.an)
		    {
		    	system("ECHO ");
				blank(90,18,40,0);
				gt(62,21);color(244);printf("!!!!Cant transfer to same account!!!!");color(240);
				Sleep(400);
				blank(60,21,40,0);
				goto o4;
			}
		    else
		    {
				blank(70,18,30,0);	
				o8:
		        f=(fast(a));
		        if(f==-1)
		        {
		        	blank(50,14,70,15);
		        	goto o4;
				}
		        blank(40,14,100,15);
		        che=transferyn(l,f);
		        blank(40,14,80,15);
				if(che==-1)
				goto o4;
			    if(f>a.balance)
			    {
				    cursor(0,1);
				    gt(70,19);color(244);printf("!!!!Insufficient fund!!!!");color(240);
				    system("ECHO ");
				    Sleep(400);
				    blank(70,19,40,0);
				    blank(90,16,20,0);
				    cursor(0,1);
				    goto o8;
			    }
			    cursor(0,1);
		    }
	    }
		else if(k==21)
		{
			cursor(3,1);
			blank(70,16,25,10);		
			o3:
			gt(70,16);printf("    Target account: ");
			gt(90,16);printf("                             ");	
			gt(90,16);l=readi(6,0,0);
			if(l==-1)
			goto o1;
			if(check(l)==0)
			{
				system("ECHO ");
				gt(65,19);color(244);printf("!!!!Account doesnot exist!!!!");color(240);
				Sleep(400);
				blank(65,19,30,0);
				goto o3;
			}
			else if(l==a.an)
			{
				system("ECHO ");
				gt(62,19);color(244);printf("!!!!Cant transfer to same account!!!!");color(240);
				Sleep(400);
				blank(60,19,40,0);
				goto o3;
			}
			else
			{
				blank(90,16,30,0);
			    o5:
			    gt(70,16);printf("Amount to transfer: ");	
			    f=emoney();
			    if(f==-1)
			    {
				blank(60,16,40,10);
				goto o3;
			    }
			    if(f<0)
			    f=-f;
			    blank(50,16,60,10);	
		        che=transferyn(l,f);
		        blank(40,14,80,15);
				if(che==-1)
				goto o3;
			    if(f>a.balance)
			    {
				    cursor(0,1);
				    gt(70,19);color(244);printf("!!!!Insufficient fund!!!!");color(240);
				    system("ECHO ");
				    Sleep(400);
				    blank(70,19,40,0);
				    blank(90,16,20,0);
				    cursor(0,1);
				    goto o5;
			    }
			    cursor(0,1);
			}
			if(f>a.balance)
			{
				cursor(0,1);
				gt(70,19);color(244);printf("!!!!Insufficient fund!!!!");color(240);
				system("ECHO ");
				Sleep(400);
				blank(70,19,40,0);
				blank(90,16,20,0);
				cursor(3,1);
				goto o5;
			}
			cursor(0,1);
		    }
		    t=0;
		    fp=fopen("customer.bin","rb+");
	        while(fread(&c1,sizeof(c1),1,fp)!=0)
	        {
		    if(l==decrypt(c1.an,2))
		    {
		    	strcpy(c[t].name,c1.name);
		       	c[t].balance=c1.balance+f;
		      	strcpy(c[t].an,c1.an);
		       	strcpy(c[t].pin,c1.pin);
		       	c[t].status[0]=c1.status[0];
		       	c[t].status[1]=c1.status[1];
		       	c[t].status[2]=c1.status[2];
		       	c[t++].status[3]=c1.status[3];
		       	continue;
			}
			strcpy(c[t].name,c1.name);
		    c[t].balance=c1.balance;
		    strcpy(c[t].an,c1.an);
		    strcpy(c[t].pin,c1.pin);
		    c[t].status[0]=c1.status[0];
		    c[t].status[1]=c1.status[1];
		    c[t].status[2]=c1.status[2];
		    c[t++].status[3]=c1.status[3];
	        }
	        fclose(fp);
	        fp=fopen("customer.bin","wb+");
	        for(g=0;g<t;g++)
	        {
	        fwrite(&c[g],sizeof(c[g]),1,fp);
	        }
	        fclose(fp);
	        return f;
	    }
	    else if(d==27)
	    exit(5);
	    else if(d==8)
	    return 0;
	    else
	    goto o2;
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
int transferyn( int l,float y)
{
	FILE *fp;
	char p[25];
	int r=20,z1,z2;
	struct customer1 c1;
	fp=fopen("customer.bin","rb+");
	            while(fread(&c1,sizeof(c1),1,fp)!=0)
	            {
		        if(l==decrypt(c1.an,2))
		        strcpy(p,c1.name);
			    }
			    fclose(fp);
		    	gt(60,18);printf("Do you want to send Rs. ");color(242);printf("%.2f",y);
				color(240);printf(" to ");
				color(242);printf("%s            ",p);
				color(240);
		    	gt(77,21);printf("Yes");
		    	gt(77,24);printf("No");
		    	o6:
		    	cursor(0,1);	
		    	color(251);
		    	bor(70,20,15,2,1);
		    	bor(70,23,15,2,1);
		    	color(245);
		    	bor(70,r,15,2,5);
		    	color(240);
		    	z1=_getch();
		    	if(z1==224)
		    	{
		    		z2=_getch();
		    		if(z2==80)
		    		{
		    			if(r==23)
		    			r-=3;
		    			else
		    			r+=3;
					}
				    else if(z2==72)
					{
						if(r==20)
						r+=3;
						else
						r-=3;
					}
					goto o6;
				}
				else if(z1==13)
				{
					if(r==23)
					return -1;
				}
				else if(z1==8)
				return -1;
				else if(z1==27)
				exit(1);
				else
				return 1;
}
float emoney()
{
	int r,p,r1;
	float f,f1,p2;
	gt(65,19);printf("Rupees: ");
	gt(66,21);printf("Paisa:");
	o1:
	gt(73,19);r=(readi(6,13,1));
	if(r==-1)
	return -1;
	gt(73,21);p=(readi(2,13,1));
	if(p==-1)
	{
		blank(73,19,12,0);
		goto o1;
	}
	f=r+p/100;
	return f;
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
int replaceinfile(struct customer cu)
{
	FILE *fp;
	struct customer1 c1,c[100];
	int f,g;
	f=0;
		fp=fopen("customer.bin","rb+");
	        while(fread(&c1,sizeof(c1),1,fp)!=0)
	        {
		        if(cu.an==decrypt(c1.an,2))
		        {
		        	strcpy(c[f].name,cu.name);
		        	c[f].balance=cu.balance;
		        	encrypt(c[f].an,cu.an,2);
		        	encrypt(c[f].pin,cu.pin,3);
		        	c[f].status[0]=cu.status[0];
		        	c[f].status[1]=cu.status[1];
		        	c[f].status[2]=cu.status[2];
		        	c[f++].status[3]=cu.status[3];
		        	continue;
				}
				strcpy(c[f].name,c1.name);
		        c[f].balance=c1.balance;
		        strcpy(c[f].an,c1.an);
		        strcpy(c[f].pin,c1.pin);
		        c[f].status[0]=c1.status[0];
		        c[f].status[1]=c1.status[1];
		        c[f].status[2]=c1.status[2];
		        c[f++].status[3]=c1.status[3];
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
void color(int a)
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),a );
}
