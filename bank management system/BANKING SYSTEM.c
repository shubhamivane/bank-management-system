#include<stdio.h>
#include<string.h>
/*******************************************************************************************************************************/

struct user{
	char uname[50];
	char pass[50];
};
/*******************************************************************************************************************************/

struct account{
	char name[50];
	int age;
	long int accno;
	float amt;
	struct user ur;
};
/*******************************************************************************************************************************/

void intro()
{
	printf("\n\n\n\n");
	printf("\n\t\t --------------------------------------------------------------------");
	printf("\n\t\t       __  __         _ _      __      __      __ _ _  __");
	printf("\n\t\t      | _||__||\\ ||_/  |  |\\ ||  _    |__ \\_/ |__  |  |__ |\\/|");
	printf("\n\t\t      |__||  || \\|| \\ _|_ | \\||__|     __| |   __| |  |__ |  |");
	printf("\n\n\t\t --------------------------------------------------------------------");
	printf("\n\n\t\t                      COMPUTER MINI PROJECT ");
	printf("\n\n\t\t                      DATE - 21/03/2016 ");
	printf("\n\n\t\t                  SUBMITTED BY : SHUBHAM IVANE ");
	printf("\n\n\t\t                  ROLL NUMBER  : 10018");
	printf("\n\n\t\t                  SECTION      : A ");
	printf("\n\n\t\t                  SUBMITTED TO : MISS PREETI MISHRA MAM");
	printf("\n\n\n\n\t\t --------------------------------------------------------------------");
	printf("\n\n\t\t   ");
	system("pause");
	system("cls");
}
/*******************************************************************************************************************************/

void login()
{
	printf("\n\t\t\t   -------------------------------------------------------------\n");
	printf("\n\t\t\t                            LOGIN \n");
	printf("\n\t\t\t   -------------------------------------------------------------");
}
/*******************************************************************************************************************************/

void admin_ui()
{
	printf("\n\t\t\t   -------------------------------------------------------------\n");
	printf("\n\t\t\t                            ADMIN  \n");
	printf("\n\t\t\t   -------------------------------------------------------------");
}
/*******************************************************************************************************************************/

void customer_ui()
{
	printf("\n\t\t\t   -------------------------------------------------------------\n");
	printf("\n\t\t\t                            CUSTOMER\n");
	printf("\n\t\t\t   -------------------------------------------------------------");
}
/*******************************************************************************************************************************/

void add()
{
	FILE *fp;
	struct user u , a;
	int i;
	char ch,ch2;
	fp = fopen("userdata.txt","a+");
	start:
	system("cls");
	admin_ui();
	rewind(fp);
	char pass[50];
	printf("\n\t\t\t\t Enter the Username : ");
	scanf("%s",u.uname);
	getc(stdin);
	printf("\n\t\t\t\t Password Should contain alphabets and digits only . ");
	printf("\n\n\t\t\t\t Enter the Password : ");
	for(i= 0;i< 100; )
  	{
  		a:
     	ch2= getch();
     	if(ch2 == '\b')
     	{
     		printf("\b");
     		goto a;
		}
     	if( ch2== '\r' )
     	{
     		u.pass[i]='\0';
     		break;
		 }
     	if(isalpha(ch2)||isdigit(ch2))
     	{
     		u.pass[i]=ch2;
       		printf("*");
     	}
    	i++;
   	}

	while(fscanf(fp," %s %s",a.uname,a.pass)!=EOF)
	{
		if(!(strcmp(a.uname,u.uname)))
		{
			printf("\n\n\t\t\t\t Already exist in database \n\n\t\t\t\t ");
			system("pause");
			goto start;
		}
	}
	fprintf(fp," %s %s\n",u.uname,u.pass);
	fclose(fp);
	printf("\n\n\t\t\t\t Regitered Successfully \n\n\t\t\t\t ");
	system("pause");
}
/*******************************************************************************************************************************/

void del()
{
	FILE *fp,*fc;
	struct user u;
	char ch = 'n',ch2;
	int i;
	struct account a;
	char name[50],pass[50];
	fp = fopen("userdata.txt","r");
	fc = fopen("temp.txt","w");
	system("cls");
	admin_ui();
	printf("\n\t\t\t\t Enter the username : ");
	scanf("%s",&name);
	getc(stdin);
	while(fscanf(fp," %s %s",u.uname,u.pass)!=EOF)
	{
		if(!(strcmp(u.uname,name)))
		{
				ch = 'y';
			    continue;
		}
		else
		fprintf(fc," %s %s\n",u.uname,u.pass);
	}
	fclose(fp);
	fclose(fc);
	remove("userdata.txt");
	rename("temp.txt","userdata.txt");
	if(ch!='y')
	{
		printf("\n\t\t\t\t Wrong username .\n\t\t\t\t\n ");
		system("pause");
		system("cls");
		return ;
	}
	else
	{
	fp = fopen("account.txt","r");
	fc = fopen("temp.txt","w");
	while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
	{
		if(!(strcmp(a.ur.uname,name)))
		{
			continue;
		}
		else
		fprintf(fc," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
	}
	fclose(fp);
	fclose(fc);
	remove("account.txt");
	rename("temp.txt","account.txt");
	printf("\n\t\t\t\t Data deleted Successfully \n\n\t\t\t\t ");
	system("pause");
	system("cls");
	}
}
/*******************************************************************************************************************************/

void edit()
{
	FILE *fp,*fc;
	struct user u;
	struct account a;
	int i , j;
	char ch2,ch3='n';
	fp = fopen("userdata.txt","r");
	fc = fopen("temp.txt","w");
	char name[50],pass[50],newname[50],newpass[50],ch='n';
	system("cls");
	admin_ui();
	printf("\n\t\t\t\t Enter Current Username : ");
	getc(stdin);
	scanf("%s",&name);
	while((fscanf(fp," %s %s",u.uname,u.pass)!=EOF))
	{
		if(!(strcmp(u.uname,name)))
		{
			j = ftell(fp);
			start:
			rewind(fp);
			system("cls");
			customer_ui();
			printf("\n\n\t\t\t\t Enter New Username : ");
			scanf("%s",newname);
			getc(stdin);
			while(fscanf(fp," %s %s\n",u.uname,u.pass)!=EOF)
			{
				if(!(strcmp(newname,u.uname)))
				{
					printf("\n\t\t\t\t Already Exist in database \n\t\t\t\t ");
					system("pause");
					goto start;
				}
			}
			printf("\n\t\t\t\t Enter New Password : ");
			scanf("%s",&newpass);
			getc(stdin);
	        fprintf(fc," %s %s\n",newname,newpass);
	        ch3='y';
	        fseek(fp,j,SEEK_SET);
		}
		else
		{
			fprintf(fc," %s %s\n",u.uname,u.pass);
		}
	}
	if(ch3!='y')
	{
	printf("\n\t\t\t\t Entered username and password does not found in database . \n\t\t\t\t ");
	system("pause");
	}
	else
	{
		printf("\n\n\t\t\t\t");
		system("pause");
	}
	fclose(fp);
	fclose(fc);
	remove("userdata.txt");
	rename("temp.txt","userdata.txt");
	if(ch3!='y')
	return ;
	fp = fopen("account.txt","r");
	fc = fopen("temp.txt","w");
	while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
	{

		if(!(strcmp(a.ur.uname,name)))
		{
			fprintf(fc," %s %s %s %d %d %f\n",newname,newpass,a.name,a.age,a.accno,a.amt);
		}
		else
		    fprintf(fc," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
	}
	fclose(fp);
	fclose(fc);
	remove("account.txt");
	rename("temp.txt","account.txt");
	printf("\n\t\t\t\t Data Edited Successfully \n\t\t\t\t");
	system("pause");
	system("cls");
}
/*******************************************************************************************************************************/

void show()
{
	struct user u;
	FILE *fp;
	int i=0;
	fp = fopen("userdata.txt","r");
	system("cls");
	admin_ui();
	printf("\n\t\t\t\t| Username     ");
	while(fscanf(fp," %s %s",u.uname,u.pass)!=EOF)
	{
		printf("\n\t\t\t\t| %d. %s  ",++i,u.uname);
	}
	printf("\n\t\t\t\t Total Number of User : %d",i);
	fclose(fp);
	printf("\n\t\t\t\t");
	system("pause");
}
/*******************************************************************************************************************************/

void create(char *ab,char *b)
{
	FILE *fp,*fc;
	char ch='y';
	fp = fopen("account.txt","a");
	fc = fopen("account.txt","r");
	struct account a,ac;
	strcpy(a.ur.uname,ab);
	strcpy(a.ur.pass,b);
	printf("\n\t\t\t\t Enter Name : ");
	scanf("%s",&a.name);
	getc(stdin);
	printf("\n\t\t\t\t Enter age  : ");
	scanf("%d",&a.age);
	start:
	printf("\n\t\t\t\t Enter Account number   : ");
	scanf("%d",&a.accno);
	while(fscanf(fc," %s %s %s %d %d %f",ac.ur.uname,ac.ur.pass,ac.name,&ac.age,&ac.accno,&ac.amt)!=EOF)
	{
		if(ac.accno == a.accno)
	    {
		 	printf("\n\t\t\t\t Already Exist in database choose another . ");
		 	goto start;
		}
	}
	l:
	printf("\n\t\t\t\t Enter starting amount : ");
	scanf("%f",&a.amt);
	if(a.amt<500)goto l;
	fseek(fp,0,SEEK_END);
	fprintf(fp," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
	fclose(fp);
	fclose(fc);
}
/*******************************************************************************************************************************/

void deposit()
{
	FILE *fp,*fc;
	struct account a;
	int accno;
	char ch='y';
	float amount;
	fp = fopen("account.txt","r");
	fc = fopen("temp.txt","w");
	printf("\n\t\t\t\t Enter the account number : ");
	scanf("%d",&accno);
	while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
	{
		if(a.accno==accno)
		{
			printf("\n\t\t\t\t Account Detail ");
			printf("\n\t\t\t\t Name  : %s",a.name);
			printf("\n\t\t\t\t Age   : %d",a.age);
			printf("\n\t\t\t\t Do you want to deposite money or not ? ");
			ch = getch();
			putch(ch);
			if(ch=='n')
			{
				printf("\n\t\t\t\t ");
				system("pause");
				system("cls");
				fclose(fp);
				fclose(fc);
				return ;
			}
			printf("\n\t\t\t\t Enter amount you want to deposit : ");
			scanf("%f",&amount);
			a.amt = a.amt + amount ;
			fprintf(fc," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
		}
		else
		fprintf(fc," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
	}
	fclose(fp);
	fclose(fc);
	remove("account.txt");
	rename("temp.txt","account.txt");
	printf("\n\t\t\t\t Money deposited successfully . \n\t\t\t\t ");
	system("pause");
	system("cls");
}
/*******************************************************************************************************************************/
void withdraw(char *b)
{
	FILE *fp,*fc;
	struct account a ;
	int accno;
	float amount;
	char ch = 'n';
	fp = fopen("account.txt","r");
	fc = fopen("temp.txt","w");
	printf("\n\t\t\t\t Enter the account number : ");
	scanf("%d",&accno);
	while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
	{
		if(a.accno==accno&&(!(strcmp(a.ur.uname,b))))
		{
			printf("\n\t\t\t\t Account Detail ");
			printf("\n\t\t\t\t Name    : %s",a.name);
			printf("\n\t\t\t\t Age     : %d",a.age);
			printf("\n\t\t\t\t Balance : %f",a.amt);
			printf("\n\t\t\t\t Do you want to Withdraw money or not ? ");
			ch = getch();
			putch(ch);
			if(ch=='n')
			{
				printf("\n\t\t\t\t ");
				system("pause");
				system("cls");
				fclose(fp);
				fclose(fc);
				return ;
			}
			printf("\n\t\t\t\t Enter amount you want to withdraw : ");
			scanf("%f",&amount);
			if(amount>a.amt)
			{
				printf("\n\t\t\t\t Insufficient Balance \n\t\t\t\t ");
				system("pause");
				system("cls");
				return ;
			}
			a.amt = a.amt - amount ;
			fprintf(fc," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
			printf("\n\t\t\t\t Money Withdraw successfully . \n\t\t\t\t ");
			goto a;
		}
		else
		fprintf(fc," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
	}
	printf("\n\t\t\t\t The account number you entered is not exist in \n\t\t\t\t database or  You don\'t have permission to access it . \n\t\t\t\t ");
	a:
	system("pause");
	system("cls");
	fclose(fp);
	fclose(fc);
	remove("account.txt");
	rename("temp.txt","account.txt");
}
/*******************************************************************************************************************************/
void transfer(char *e)
{
   int acc , acc2 , acc3;
   float amount;
   char ch = 'n',ch2 = 'n',ch3 = 'n';
   FILE *fp ,*fp1 ,*fp2 , *fp3;
   struct account a , b , c , d;
   printf("\n\t\t\t\t Enter your account number : ");
   scanf("%d",&acc);
   fp = fopen("account.txt","r");
   while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
   {
   		if((acc==a.accno)&&(!(strcmp(e,a.ur.uname))))
   		{
   			ch = 'y';
   			acc3 = a.accno;
   			fseek(fp,0,SEEK_SET);
   			printf("\n\t\t\t\t Enter account number in which you want to transfer money : ");
   			scanf("%d",&acc2);
   			while(fscanf(fp," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
   			{
   				if(acc2==a.accno)
   				{
   					ch2='y';
					   break;
			    }
			}
			if(ch2=='n')
			{
				printf("\n\t\t\t\t Account in which you want to tranfer money does not exist . \n\t\t\t\t ");
				system("pause");
				system("cls");
				fclose(fp);
				return ;
			}
			else
			{
				printf("\n\t\t\t\t Enter the amount you want to transfer : ");
				scanf("%f",&amount);
				rewind(fp);
				fp1 = fopen("temp.txt","w");
				while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
				{
					if(acc==a.accno)
					{
						if(amount>a.amt)
						{
							printf("\n\t\t\t\t Insufficient balance ");
							system("pause");
							fclose(fp);
							fclose(fp1);
							remove("temp.txt");
							return ;
						}
						else
						{
							a.amt = a.amt - amount;
							fprintf(fp1," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
							ch3 = 'y';
						}
					}
					else
					fprintf(fp1," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
				}
				fclose(fp1);
				fclose(fp);
				remove("account.txt");
				rename("temp.txt","account.txt");
				if(ch3=='y')
				{
						fp = fopen("account.txt","r");
						fp1 = fopen("temp.txt","w");
						while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
						{
							if(acc2==a.accno)
							{
								a.amt = a.amt + amount;
								fprintf(fp1," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
							}
							else
								fprintf(fp1," %s %s %s %d %d %f\n",a.ur.uname,a.ur.pass,a.name,a.age,a.accno,a.amt);
						}
						fclose(fp);
						fclose(fp1);
						remove("account.txt");
						rename("temp.txt","account.txt");
						printf("\n\t\t\t\t Money transfered successfully \n\t\t\t\t ");
						system("pause");
						system("cls");
						return ;
				}
			}
   		}
   	}
   	if(ch!='y')
   	{
   		printf("\n\t\t\t\t Account number you entered does not exist or you do not have permission to access it ");
   		system("pause");
   		system("cls");
   		fclose(fp);
	   }
}
/*******************************************************************************************************************************/
void balance(char *u)
{
	FILE *fp;
	struct account a;
	fp = fopen("account.txt","r");
	int accno;
	fseek(fp,0,SEEK_SET);
	printf("\n\t\t\t\t Enter the account number : ");
	scanf("%d",&accno);
	while(fscanf(fp," %s %s %s %d %d %f",a.ur.uname,a.ur.pass,a.name,&a.age,&a.accno,&a.amt)!=EOF)
	{
		if((accno == a.accno)&&(!(strcmp(u,a.ur.uname))))
		{
			printf("\n\t\t\t\t Name     : %s",a.name);
			printf("\n\t\t\t\t Acc No.  : %d",a.accno);
			printf("\n\t\t\t\t Balance  : %f \n\t\t\t\t ",a.amt);
			system("pause");
			system("cls");
			fclose(fp);
			return ;
		}
	}
	printf("\n\t\t\t\t The account number you entered is does not exist or you don\'t have permission to access it . ");
	system("pause");
	system("cls");
	fclose(fp);
}
/*******************************************************************************************************************************/
int log_in_admin()
{
	char pass[50],cpass[50];
	FILE *fp;
	system("cls");
	admin_ui();
	char ch;
	int i;
	fp = fopen("admin.txt","r");
	printf("\n\t\t\t\t\t     Username : ADMIN ");
	printf("\n\n\t\t\t\t\t     Password : ");
	for(i= 0;i< 100; )
  	{
  		a:
     	ch = getch();
     	if(ch == '\b')
     	{
     		i--;
     		printf("\b");
     		goto a;
		}
     	if( ch == '\r' ) break;
     	if( isalpha(ch)||isdigit(ch))
     	{
       		pass[i] = ch;
       		printf( "*");
     	}
     	i++;
   	}
	while(fscanf(fp,"%s",&cpass)!=EOF)
	{
		if(!(strcmp(cpass,pass)))
		{
			return 1;
		}
	}
	return -1;
}
/*******************************************************************************************************************************/
int main()
{
	int choice,choice2,ans,ans2=1,i;
	struct user us;
	char u[50],p[50],ch;
	system("title BANKING SYSTEM");
	start:
	system("color 09");
	intro();
	login();
	printf("\n\t\t\t\t 1. Login as admin ");
	printf("\n\t\t\t\t 2. Login as Customer ");
	printf("\n\t\t\t\t 3. Exit ");
	printf("\n\t\t\t\t    Enter your choice : ");
	fflush(stdin);
	scanf("%d",&choice);
	//getc(stdin);
	switch(choice)
	{
		case 1 : l:ans = log_in_admin();
				 if(ans != 1)
				 {
				 	goto l;
				 }
				 start2:
				 system("cls");
				 admin_ui();
				 printf("\n\t\t\t\t Select Your Choice . ");
				 printf("\n\t\t\t\t 1. Add User ");
				 printf("\n\t\t\t\t 2. Delete User ");
				 printf("\n\t\t\t\t 3. Edit Username or Password ");
				 printf("\n\t\t\t\t 4. View all User ");
				 printf("\n\t\t\t\t 5. Go to Main Menu : ");
				 printf("\n\t\t\t\t Enter your choice  : ");
				 scanf("%d",&choice2);
				 switch(choice2)
				 {
				 	case 1 : add();
				 	break;
				 	case 2 : del();
				 	break;
				 	case 3 : edit();
				 	break;
				 	case 4 : show();
				 	break;
				 	case 5 : system("cls");
					         goto start;
				  }
				  goto start2;
		break;
		case 2 : z:
				 system("cls");
				 customer_ui();
				 printf("\n\t\t\t\t\t    Username : ");
				 scanf("%s",u);
				 printf("\n\t\t\t\t\t    Password : ");
				 for(i= 0;i< 100; )
  				 {
  				 		a:
     					ch = getch();
     					if(ch == '\b')
     					{
     						i--;
     						printf("\b");
     						goto a;
						 }
     					if( ch == '\r' )
     					{
     						p[i]='\0';
     						break;
						 }
     					if( isalpha(ch)||isdigit(ch) )
     					{
       						p[i] = ch;
       						printf( "*");
     					}
     					i++;
   				}
				 FILE *a;
				 struct user usr;
				 a = fopen("userdata.txt","r");
				 while(fscanf(a,"%s %s",usr.uname,usr.pass)!=EOF)
				 {
				 	if((!(strcmp(usr.uname,u)))&&(!(strcmp(usr.pass,p))))
				 	{
				 		ans2 = 0;
					 }
				 }
				 fclose(a);
				 if(ans2)
				 {
				 	 printf("\n\t\t\t\t Wrong username or password \n\t\t\t\t ");
				 	 system("pause");
				     goto z;
				 }
				 start3:
				 system("cls");
				 customer_ui();
				 printf("\n\t\t\t\t Select Your Choice ");
				 printf("\n\t\t\t\t 1. Create Account ");
				 printf("\n\t\t\t\t 2. Cash Deposit ");
				 printf("\n\t\t\t\t 3. Cash Withdraw ");
				 printf("\n\t\t\t\t 4. Fund Transfer ");
				 printf("\n\t\t\t\t 5. View Balance ");
				 printf("\n\t\t\t\t 6. Go to Main Menu ");
				 printf("\n\t\t\t\t Enter your choice : ");
				 scanf("%d",&choice2);
				 system("cls");
				 switch(choice2)
				 {
				 	case 1 : customer_ui();
					 		 create(&u[0],&p[0]);
				 			 break;
				 	case 2 : customer_ui();
					 		 deposit();
				 			 break;
				 	case 3 : customer_ui();
					 		 withdraw(&u[0]);
				 			 break;
				 	case 4 : customer_ui();
					 		 transfer(&u[0]);
				 			 break;
				 	case 5 : customer_ui();
					 		 balance(&u[0]);
				 			 break;
				 	case 6 : goto start;
				  }
				  goto start3;
		break;
		case 3 : return 0;
		break;
		default : printf("\n\t\t\t\t Wrong input ..... \n\t\t\t\t ");
		          system("pause");
		          system("cls");
		          goto start;
	}
	return 0;
}
/*******************************************************************************************************************************/
