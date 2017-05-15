/*****************************************************************************************************************************/
/*
Calender Program 
For finding what is a day ? or what was a day at given date ?
For printing calender of whole month . 

PROGRAM CODED BY - SHUBHAM IVANE 
DATE - 01-01-2016
*/
/*****************************************************************************************************************************/
#include<stdio.h>
#include<string.h>
void intro();
int check_date(int d,int m,int y);//FOR CHECKING WEATHER ENTERED DATE IS VALID OR NOT .
void find_day(int df,int mf,int yf);//FOR FINDING WHAT WAS THE DAY AT A GIVEN DATE .
	int leap_year(int y2);//FOR CHECKING WEATHER THE GIVEN YEAR IS LEAP YEAR OR NOT . 
	int no_of_days(int dn,int mn,int yn);//FOR CALCULATING NO.OF DAYS.
int check_month(int mc);
void print_calender(int mp,int yp);
	void print_month(int mm,int ym);
	int find_month(int mf,int yf);
main()
{
	system("title Calender");
	char ch='y';
	loop:
	while(ch=='y')
	{
	system("cls");
	intro();
	int m,y,d,choice,check=0,ch2;
	printf("\n\n Select your choice . ");
	printf("\n\n 1. Find the day at given date . ");
	printf("\n\n 2. Print the calender of given month and year .");
	printf("\n\n 3. Exit .\n\n    Enter your choice   : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 : case1:
		         printf("\n\n    Enter date (dd mm yyyy) : ");
		         scanf("%d %d %d",&d,&m,&y);
		         check=check_date(d,m,y);
		         if(check==1)
				 find_day(d,m,y);
				 else
				 {
				 	printf("\n\n     Enter a valid date . ");
				 	system("pause");
				 	goto case1;
				 }
		        break;
		case 2 :case2:
				printf("\n\n    Enter the month and year (mm yyyy) : ");
		        scanf("%d %d",&m ,&y);
		        print_calender(m,y);
				con:
				printf("\n\n Press '6' for next month , '4' for previous month , '2' for next month , '8' for next year '0' for exit : ");
			    scanf("%d",&ch2);
				if(ch2==6)
				{
					m=m+1;
					if(m>12)
					{
						m=1;
						y=y+1;
						print_calender(m,y);
						goto con;
					}
					else
					{
						print_calender(m,y);
						goto con;
					}
				}
				else if(ch2==4)
				{
					m=m-1;
					if(m<1)
					{
						m=12;
						y=y-1;
						print_calender(m,y);
						goto con;
						
					}
					else
					{
						print_calender(m,y);
						goto con;
					}
				}
				else if(ch2==8)
				{ 
				    y=y+1;
					print_calender(m,y);
					goto con;
				}
				else if(ch2==2)
				{
					y=y-1;
					print_calender(m,y);
					goto con;
				}
			    break;
		case 3 :ch='n';
		       goto end;
		default:printf("\n\n  Error .....! again enter your choice . ");
				system("pause");
				goto loop;
	}
	printf("\n\n     ");
	system("pause");
  }
  end:
  	printf("\n\n    Good Bye , Have a good day . ");system("pause");
  	
}
/**********************************************************************************************************************/
int check_date(int d,int m,int y)
{
	int check=-1;
	check=leap_year(y);
	if(d>31||m>12||y<1900||d<0||m<0)return -1;
	else if(d<=28&&check==-1&&m==2)return 1;
	else if(d<=29&&check==1&&m==2)return 1;
	else if(d<=31&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12))return 1;
	else if(d<=30&&(m==4||m==6||m==9||m==11))return 1;
	else
	return -1;
}		
void find_day(int df,int mf,int yf)
{
	int nod,d;
	char day[10];
	nod=no_of_days(df,mf,yf);
	d=nod%7;
	switch(d)
	{
		case 1: strcpy(day,"Monday");break;
		case 2: strcpy(day,"Tuesday");break;
		case 3: strcpy(day,"Wednesday");break;
		case 4: strcpy(day,"Thrusday");break;
		case 5: strcpy(day,"Friday");break;
		case 6: strcpy(day,"Saturday");break;
		case 0: strcpy(day,"Sunday");break;
	}
	printf("\n\n    Day at %d - %d - %d is %s", df , mf , yf ,day);
}
	int leap_year(int y2)
	{
		if(y2%400==0)return 1;
		else if(y2%4==0&&y2%100!=0)return 1;
		else return -1;
	}
	int no_of_days(int dn,int mn,int yn)
	{
	    int nod=0,leap=1;
	    register i;
	    for(i=1900;i<yn;i++)
	    {
	    	if(leap==leap_year(i))
	    	nod=nod+366;
	    	else
	    	nod=nod+365;
		}
		for(i=1;i<mn;i++)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)nod=nod+31;
			else if(leap==leap_year(yn)&&i==2)nod=nod+29;
			else if(leap!=leap_year(yn)&&i==2)nod=nod+28;
			else
			nod=nod+30;
		}
		nod=nod+dn;
		return nod;
	}
void print_calender(int mp,int yp)
{
    int m, d=find_month(mp,yp);
    register int i; 
    if(mp==4||mp==6||mp==9||mp==11)m=30;
    else if(1==leap_year(yp)&&mp==2)m=29;
    else if(1!=leap_year(yp)&&mp==2)m=28;
    else m=31;
    printf("\n\n\n");
	printf("              ----------------------------------------------------------------------------------------\n");	
	printf("\t\t\t\t\t\t");
	print_month(mp,yp);
	printf("\n              ----------------------------------------------------------------------------------------");
	printf("\n\t\t\t\tSu\tMo\tTu\tWe\tTh\tFr\tSa\n");
	printf("\t\t\t");
	for(i=0;i<d;i++)printf("\t");
	i=1;
	for(i=1;i<=m;i++)
	{
		if((d+i-1)%7==6)
	    	printf("\t%d\n\t\t\t",i);
	    	
		else
		printf("\t%d",i);
	}
	printf("\n              ----------------------------------------------------------------------------------------");
	return;	
}
	void print_month(int mm,int ym)
	{
		switch(mm)
		{
			case 1 : printf("January , %d",ym);break;
			case 2 : printf("Feburary, %d",ym);break;
			case 3 : printf("March, %d",ym);break;
			case 4 : printf("April, %d",ym);break;
			case 5 : printf("May, %d",ym);break;
			case 6 : printf("June, %d",ym);break;
			case 7 : printf("July, %d",ym);break;
			case 8 : printf("August, %d",ym);break;
			case 9 : printf("September, %d",ym);break;
			case 10 : printf("October, %d",ym);break;
			case 11 : printf("November, %d",ym);break;
			case 12 : printf("December, %d",ym);break;
		}
		return;
	}
	int find_month(int mf,int yf)
	{   int d;
		int df=1,nod;
		nod=no_of_days(df,mf,yf);
	    d=nod%7;
	    return d;
	}
void intro()
{
 printf("\n--------------------------------------------------------------------------------------");
 printf("\n\t\t\t\t   __  __      __      _   __  __      "); 
 printf("\n\t\t\t\t  |   |__||   |_  |\\ || \\ |_  |__|            ");
 printf("\n\t\t\t\t  |__ |  ||__ |__ | \\||_/ |__ |  \\                    ");
 printf("\n\n\n\t\t\t\t THIS PROGRAM IS CODED BY - SHUBHAM IVANE  ");
 printf("\n--------------------------------------------------------------------------------------"); 
}

