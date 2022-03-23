#include<stdio.h>		// For use of standard inputs and outputs.
#include<stdlib.h>		// For use of 'system("cls")' command, for clear screen.
#include<windows.h>		// For gotoxy() function.
#include<string.h>		// For function 'strcmp()' .
#include<time.h>		// To Show "Today's time & date" , on HOME Screen.

							  // ==========================================================//
							 /* ----------------  USER-DEFINED FUNCTIONs  ----------------*/
							// ==========================================================//


void welcome();								// For Welcoome Screen window.
void gotoxy(int x,int y);					// To set the position of Console Cursor.
void StaffAccess();							// Function for staff's Authorities.
int TotalPriceCalculation();				// To calclulate total price of Ticket.
void rectangle(int x,int y,int l,int b);	// Function to creat a Rectangular box, for impressive Interface.
void new_rectangle(int x1,int y1,int x2,int y2,int n,int c);
 

void time_date() 			// For today's time & date.
{
time_t t_d;
time(&t_d);
printf("%s",ctime(&t_d));

}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}



							  // =========================================================== //
							 /* -*--*--*--*--*--  USER-DEFINED STRUCTUREs  --*--*--*--*--*- */
							// =========================================================== //

struct Arrivals				// Structure for information of Arrival Flights.
{
	char time[10];
	char from[20];
	char flight_no[10];
	char status[30];
};

struct Departures			// Structure for information of Departure Flights.
{
	char time[10];
	char to[20];
	char flight_no[10];
	char status[30];
};

struct TicketDetail			// Structure for Ticket Reservation variables.
{
	char to[20];
	char company_name[20];
	char booking_date[15];
	char flight_no[10];
	char time_of_departure[7];
	char date_of_departure[15];
	char clss[10];
	char pname[40];
	char cnic[15];
	int adults;
	int children;
	int infants;
	char ticket_status[10];
	int totalPrice;
};

struct flightClassesPrices
{
	char cityname[20];
	int firstclss;
	int businesclss;
	int economyclss;
};

struct priceList
{
	int firstAdult;
	int firstChild;
	int firstInfant;
	int businessAdult;
	int businessChild;
	int businessInfant;
	int economyAdult;
	int economyChild;
	int economyInfant;
};



FILE *fp, *fmodi, *fmodi_s, *ft, *fs;				// Global Variables, of flie and Struct TicketDetail.
struct TicketDetail t;
struct flightClassesPrices cp;
struct priceList pl;


							  // =========================================================== //
							 /* -*--*--*--*--*--		MAIN  FUNCTION	   --*--*--*--*--*- */
							// =========================================================== //


void main()
 {
 	int uname,pass;
	int u=555,p=666;
	
	system("cls");					// Clear The Screen...
	welcome();						// We call 'Welcome'Function here.
	
	system("cls");					// Clear The Screen...
	rectangle(10,8,71,15);			// We call 'rectangle' Function here.

	gotoxy(23,18);
	printf("Created by:");
	gotoxy(23,19);
	int i;
	for(i=0;i<11;i++) printf("%c",196);		// for loop to print ASCII charachters line, (___________________).
	gotoxy(40,18);
	delay(100);
	printf("%c Muhammad Asif %c",3,3);
	gotoxy(40,19);
	delay(100);
	for(i=0;i<17;i++) printf("%c",196);
	
		
	gotoxy(10,5);
	printf("NOTE: Only ONE attempt allowed to enter username and password\n");
	gotoxy(23,10);
	delay(200);
	printf("Enter User Name: ");
	scanf("%d",&uname);
	gotoxy(23,12);
	delay(200);
	printf("Password       : ");
	scanf("%d",&pass);
	
	if((uname == u) && (pass == p))
	{
		system("cls");					// Clear The Screen...
		StaffAccess();					// Fuction Call 'StaffAccess'.
	}
	else
	{
		system("cls");
		printf("\n\n\n\t\t\tIt seems you are not an employee...:\n\t\t\t\t\tGood Bye\n\n\n\n");
		exit(0);
	}

 }
 
 void StaffAccess()
{
	
	
	
	struct Arrivals yesterdayA,todayA,tommorrowA;
	struct Departures yesterdayD,todayD,tommorrowD;
	char choice,arch,dpch,another, f_no[10], cnic_no[15];
	int s;
	
	
	while(1)
	{
		int i;
		system("cls");							// Clear The Screen...
		
		new_rectangle(3,4,32,22,4,2);	
		gotoxy(13,8);
		delay(110);
		printf("Created by:");
		gotoxy(13,9);
		delay(100);
		for(i=0;i<11;i++) printf("%c",196);
		gotoxy(12,10);
		delay(120);
		printf("Muhammad Asif");
		gotoxy(12,11);
		delay(120);
		printf("Faiza  Yaseen");
				
		gotoxy(6,15);
		delay(100);
		time_date(); 							// Fuction Call. 'Current Date & Time'.
		gotoxy(6,16);
		delay(100);
		for(i=0;i<24;i++) printf("%c",205);

		gotoxy(30,2);
		printf(".....HOME.....");
		
		new_rectangle(39,4,69,22,4,5);
		
		gotoxy(42,6);
		delay(100);
		printf("1.  Ticket Reservation");
		gotoxy(42,8);
		delay(100);
		printf("2.  Ticket Status");
		gotoxy(42,10);
		delay(100);
		printf("3.  Ticket Cancellation");
		gotoxy(42,12);
		delay(100);
		printf("4.  Arrivals Schedule");
		gotoxy(42,14);
		delay(100);
		printf("5.  Departures Schedule");
		gotoxy(42,16);
		delay(100);
		printf("6.  Price List");
		gotoxy(42,18);
		delay(100);
		printf("0.  Exit\n");
		gotoxy(42,20);
		delay(100);
		printf("Your choice: ");
		
		
		fflush(stdin);
		choice=getche();
		
		switch(choice)
		{
			case '1':							// Case: to control the Ticket Reservation Section.
				system("cls");					// Clear The Screen...
				
				fp=fopen("booking.dat","ab");
				if(fp==NULL)
				{
					fp=fopen("booking.dat","wb");
					if(fp==NULL)
					{
						puts("cannot open file:");
						exit(1);
					}
				}
				another='y';
				
				while(another=='y')
				{
					system("cls");
					
					puts("\t\t\t\tEnter Booking Detail:\n");
					puts("From: Karachi");
					printf("To: ");
					gets(t.to);
					printf("Company Name");
					gets(t.company_name);
					printf("Booking Date	e.g = DD/MM/YYY: ");
					gets(t.booking_date);
					printf("Flight Number: ");
					gets(t.flight_no);
					printf("Time of Departure	e.g = HH:MM : ");
					gets(t.time_of_departure);
					printf("Date of Departure	e.g = DD/MM/YYY: ");
					gets(t.date_of_departure);
					printf("Class,  e.g = 'First/Business/Economy' : ");
					gets(t.clss);
					puts("\n\n\t\t\t\tEnter Passenger Detail:");
					printf("Name: ");
					gets(t.pname);
					printf("CNIC	*****-*******-* : ");
					gets(t.cnic);
					printf("Adults: ");
					scanf("%d",&t.adults);
					printf("Children: ");
					scanf("%d",&t.children);
					printf("Infants: ");
					scanf("%d",&t.infants);
					printf("Enter Status");
					scanf("%s",&t.ticket_status);
					
					t.totalPrice = TotalPriceCalculation();
					printf("\nTotal Price: %d",t.totalPrice);

					fwrite(&t,sizeof(t),1,fp);				// writing all pessenger's data to file.
					
					printf("\nAnother Booking??? (y/n)");
					fflush(stdin);
					another=getche();
					system("cls");				// Clear The Screen...
				}
				close(fp);
				break;
			case '2':							// Case: to Print the Ticket Status.
				system("cls");
				fs=fopen("booking.dat","rb+");
				another='y';
				while(another=='y')
				{
					printf("\nEnter Passenger's CNIC No. : ");
					gets(cnic_no);
				
					long int recsize;
					recsize=sizeof(t);
					rewind(fs);
					while(fread(&t,recsize,1,fs)==1)
					{
					
						if(strncmp(t.cnic,cnic_no,15) == 0)
						{
							rectangle(1,3,78,50);
							gotoxy(7,5);
							printf("Travel Company: '%s'",strupr(t.company_name));
							gotoxy(53,5);
							printf("Status: '%s'",strupr(t.ticket_status));
							gotoxy(4,6);
							for(i=0;i<71;i++) printf("%c",247);
							
							gotoxy(30,8);
							printf("Booking Detail");
							gotoxy(29,9);
							for(i=0;i<16;i++) printf("%c",22);
							
							gotoxy(5,11);
							printf("%c From: Karachi",16);
							gotoxy(49,11);
							printf("%c To: %s",16,t.to);
							gotoxy(5,13);
							printf("%c Booking Date: %s",16,t.booking_date);
							gotoxy(49,13);
							printf("%c Flight No: %s",16,t.flight_no);
							gotoxy(5,15);
							printf("%c Date of Departure: %s",16,t.date_of_departure);
							gotoxy(49,15);
							printf("%c Time of Departure: %s",16,t.time_of_departure);
							gotoxy(5,17);
							printf("%c Class: %s",16,t.clss);
							
							gotoxy(30,20);
							printf("Pessenger Detail");
							gotoxy(29,21);
							for(i=0;i<18;i++) printf("%c",22);
							
							gotoxy(5,23);
							printf("%c Booked by: %s",16,t.pname);
							gotoxy(46,23);
							printf("%c CNIC NO.: %s",16,t.cnic);
							gotoxy(5,25);
							printf("%c Adults: %d",16,t.adults);
							gotoxy(49,25);
							printf("%c Children: %d",16,t.children);
							gotoxy(5,27);
							printf("%c Infants: %d",16,t.infants);
							gotoxy(49,27);
							printf("%c Total Price: %d",16,t.totalPrice);
							
							
							gotoxy(2,32);
							for(i=0;i<75;i++) printf("%c",236);
							
							gotoxy(25,35);
							printf("DESIGNED and PROGRAMMED by");
							gotoxy(24,36);
							for(i=0;i<28;i++) printf("%c",167);
							
							gotoxy(24,38); printf("Name");
							gotoxy(23,39);
							for(i=0;i<6;i++) printf("%c",196);
							gotoxy(45,38); printf("Roll Number");
							gotoxy(44,39);
							for(i=0;i<13;i++) printf("%c",196);
							
							gotoxy(20,41); printf("MUHAMMAD ASIF");
							gotoxy(49,41); printf("15");
							
							gotoxy(20,43); printf("FAIZA YASEEN");
							gotoxy(49,43); printf("02");
			
							
							gotoxy(4,52);
							printf("\nShow Another Status: (y/n)  ");
							break;
						}
						else
							printf("Ticket not Reserved !!! ");
							printf("\n\nShow Another Status: (y/n)  ");
					}
					
					fflush(stdin);
					another=getche();
				}
				fclose(fs);
				break;
					
			case '3':							// Case: to control the Ticket Cancellation Section.
				system("cls");
				fmodi_s=fopen("booking.dat","rb+");
				another='y';
				while(another=='y')
				{
					printf("\nEnter Passenger's CNIC No. : ");
					gets(cnic_no);
					
					long int recsize;
					recsize=sizeof(t);
					rewind(fmodi_s);
					while(fread(&t,recsize,1,fmodi_s)==1)
					{
						if(strncmp(t.cnic,cnic_no,15)==0)
						{
							puts("Change Tickets Status: ");
							gets(t.ticket_status);
							
							fseek(fmodi_s,-recsize,SEEK_CUR);
							fwrite(&t,recsize,1,fp);
							break;
						}
						
					}
					printf("\nCancel Another Ticket: (y/n)  ");
					fflush(stdin);
					another=getche();
				}
				fclose(fmodi_s);
				break;
			case '4':							// Case: to control the Arrivals Section.
				system("cls");					// Clear The Screen...
				new_rectangle(26,4,55,23,4,1);
				gotoxy(32,8);
				delay(130);
				printf("1.  Yesterday");
				gotoxy(32,10);
				delay(130);
				printf("2.  Today");
				gotoxy(32,12);
				delay(130);
				printf("3.  Tommorrow");
				gotoxy(32,14);
				delay(130);
				printf("4.  Modify status");
				gotoxy(32,18);
				delay(130);
				printf("Your Choice....");
				arch=getch();
				switch(arch)
				{
					case '1':							// Case: to show Yesterday Arrivals.
						system("cls");					// Clear The Screen...
						gotoxy(20,1);
						printf("Arrivals:\t\t%c Yesterday %c",17,16);
						rectangle(1,3,78,150);
						fp=fopen("yesterdayA.dat","rb");
						if(fp==NULL)
						{
							puts("Cannot open file");
							exit(1);
						}
						gotoxy(3,5);
						printf("Time:");
						
						gotoxy(13,5);
						printf("From:");
						
						gotoxy(30,5);
						printf("To:");						
						
						gotoxy(45,5);
						printf("Flight No:");
						
						gotoxy(60,5);
						printf("Status:");
						
						gotoxy(2,6); for(i=0;i<75;i++) printf("%c",205);
						
						s=8;
						while(fread(&yesterdayA,sizeof(yesterdayA),1,fp)==1)
						{
							delay(50);
							gotoxy(3,s);
							printf("%s",yesterdayA.time);
							gotoxy(13,s);
							printf("%s",yesterdayA.from);
							gotoxy(30,s);
							printf("Karachi");
							gotoxy(45,s);
							printf("%s",yesterdayA.flight_no);
							gotoxy(60,s);
							printf("%s",yesterdayA.status);
							s=s+2;
							
							gotoxy(3,(s-1));
							for(i=0;i<73;i++) printf("%c",196);
							
						}
						fclose(fp);
						
						gotoxy(2,153);
						printf("\n\tPress anykey to go back to HOME Window: ");
						getch();						// without this function, data show but not stop on screen.
						break;
					case '2':							// Case: to show Today Arrivals.
						system("cls");					// Clear The Screen...
						gotoxy(20,1);
						printf("Arrivals:\t\t%c Today %c",6,6);
						rectangle(1,3,78,170);
						fp=fopen("todayA.dat","rb");
						if(fp==NULL)
						{
							puts("Cannot open file");
							exit(1);
						}
						gotoxy(3,5);
						printf("Time:");
						
						gotoxy(13,5);
						printf("From:");
						
						gotoxy(30,5);
						printf("To:");						
						
						gotoxy(45,5);
						printf("Flight No:");
						
						gotoxy(60,5);
						printf("Status:");
						
						gotoxy(2,6); for(i=0;i<74;i++) printf("%c",205);
						
						s=8;
						while(fread(&todayA,sizeof(todayA),1,fp)==1)
						{
							delay(50);
							gotoxy(3,s);
							printf("%s",todayA.time);
							gotoxy(13,s);
							printf("%s",todayA.from);
							gotoxy(30,s);
							printf("Karachi");
							gotoxy(45,s);
							printf("%s",todayA.flight_no);
							gotoxy(60,s);
							printf("%s",todayA.status);
							s=s+2;
							
							gotoxy(3,(s-1));
							for(i=0;i<73;i++) printf("%c",196);
						}
						fclose(fp);
						
						gotoxy(2,173);
						printf("\n\tPress anykey to go back to HOME Window: ");
						getch();
						break;
					case '3':							// Case: to show Tommorrow Arrivals.
						system("cls");					// Clear The Screen...
						gotoxy(20,1);
						printf("Arrivals:\t\t%c Tommorrow %c",17,16);
						rectangle(1,3,78,150);
						fp=fopen("tommorrowA.dat","rb");
						if(fp==NULL)
						{
							puts("Cannot open file");
							exit(1);
						}
						gotoxy(3,5);
						printf("Time:");
						
						gotoxy(13,5);
						printf("From:");
						
						gotoxy(30,5);
						printf("To:");						
						
						gotoxy(45,5);
						printf("Flight No:");
						
						gotoxy(60,5);
						printf("Status:");
						
						gotoxy(2,6); for(i=0;i<74;i++) printf("%c",205);
						
						s=8;
						while(fread(&tommorrowA,sizeof(tommorrowA),1,fp)==1)
						{
							delay(50);
							gotoxy(3,s);
							printf("%s",tommorrowA.time);
							gotoxy(13,s);
							printf("%s",tommorrowA.from);
							gotoxy(30,s);
							printf("Karachi");
							gotoxy(45,s);
							printf("%s",tommorrowA.flight_no);
							gotoxy(60,s);
							printf("%s",tommorrowA.status);
							s=s+2;
							
							gotoxy(3,(s-1));
							for(i=0;i<73;i++) printf("%c",196);
						}
						fclose(fp);
						
						gotoxy(2,153);
						printf("\n\tPress anykey to go back to HOME Window: ");
						getch();
						break;
					case '4':							// Case: to Modify the today Arrivals' Status.
						system("cls");
						fp=fopen("todayA.dat","rb+");
						another='y';
						while(another=='y')
						{
							printf("\nEnter Flight Number to modify Status: ");
							gets(f_no);
							
							long int recsize;
							recsize=sizeof(todayA);
							rewind(fp);
							while(fread(&todayA,recsize,1,fp)==1)
							{
								if(strcmp(todayA.flight_no,f_no)==0)
								{
									puts("Enter new Status: ");
									gets(todayA.status);
									
									fseek(fp,-recsize,SEEK_CUR);
									fwrite(&todayA,recsize,1,fp);
									break;
								}
								
							}
							printf("\nModify another Record(y/n)");
							fflush(stdin);
							another=getche();
						}
						fclose(fp);
						break;
				}
				break;
			case '5':							// Case: to control the Departures Section.
				system("cls");					// Clear The Screen...
				new_rectangle(26,4,55,23,4,2);
				gotoxy(32,8);
				delay(130);
				printf("1.  Yesterday");
				gotoxy(32,10);
				delay(130);
				printf("2.  Today");
				gotoxy(32,12);
				delay(130);
				printf("3.  Tommorrow");
				gotoxy(32,14);
				delay(130);
				printf("4.  Modify Status");
				gotoxy(32,18);
				delay(130);
				printf("Your Choice.....");
				
				dpch=getch();
				switch(dpch)
				{
					case '1':							// Case: to show the Yesterday's Arrivals.
						system("cls");					// Clear The Screen...
						gotoxy(20,1);
						printf("Departures:\t\t%c Yesterday %c",17,16);
						rectangle(1,3,78,153);
						fp=fopen("yesterdayD.dat","rb");
						if(fp==NULL)
						{
							puts("Cannot open file");
							exit(1);
						}
						gotoxy(3,5);
						printf("Time:");
						
						gotoxy(13,5);
						printf("From:");
						
						gotoxy(26,5);
						printf("To:");
						
						gotoxy(45,5);
						printf("Flight No:");
						
						gotoxy(60,5);
						printf("Status:");
						
						gotoxy(2,6); for(i=0;i<74;i++) printf("%c",205);
						
						s=8;
						while(fread(&yesterdayD,sizeof(yesterdayD),1,fp)==1)
						{
							delay(50);
							gotoxy(3,s);
							printf("%s",yesterdayD.time);
							gotoxy(13,s);
							printf("Karachi");
							gotoxy(26,s);
							printf("%s",yesterdayD.to);
							gotoxy(45,s);
							printf("%s",yesterdayD.flight_no);
							gotoxy(60,s);
							printf("%s",yesterdayD.status);
							s=s+2;
							
							gotoxy(3,(s-1));
							for(i=0;i<73;i++) printf("%c",196);
						}
						fclose(fp);
						
						gotoxy(2,155);
						printf("\n\tPress anykey to go back to HOME Window: ");
						getch();
						break;
					case '2':							// Case: to show the Today's Arrivals.
						system("cls");					// Clear The Screen...
						gotoxy(20,1);
						printf("Departures:\t\t%c Today %c",17,16);
						rectangle(1,3,78,133);
						fp=fopen("todayD.dat","rb");
						if(fp==NULL)
						{
							puts("Cannot open file");
							exit(1);
						}
						gotoxy(3,5);
						printf("Time:");
						
						gotoxy(13,5);
						printf("From:");
						
						gotoxy(26,5);
						printf("To:");
						
						gotoxy(45,5);
						printf("Flight No:");
						
						gotoxy(60,5);
						printf("Status:");
						
						gotoxy(2,6); for(i=0;i<74;i++) printf("%c",205);
						
						s=8;
						while(fread(&todayD,sizeof(todayD),1,fp)==1)
						{
							delay(50);
							gotoxy(3,s);
							printf("%s",todayD.time);
							gotoxy(13,s);
							printf("Karachi");
							gotoxy(26,s);
							printf("%s",todayD.to);
							gotoxy(45,s);
							printf("%s",todayD.flight_no);
							gotoxy(60,s);
							printf("%s",todayD.status);
							s=s+2;
							
							gotoxy(3,(s-1));
							for(i=0;i<73;i++) printf("%c",196);
						}
						fclose(fp);
						
						gotoxy(2,135);
						printf("\n\tPress anykey to go back to HOME Window: ");
						getch();
						break;
					case '3':							// Case: to show the Tommorrow's Arrivlas.
						system("cls");					// Clear The Screen...
						gotoxy(20,1);
						printf("Departures:\t\t%c Tommorrow %c",17,16);
						rectangle(1,3,78,150);
						fp=fopen("tommorrowD.dat","rb");
						if(fp==NULL)
						{
							puts("Cannot open file");
							exit(1);
						}
						gotoxy(3,5);
						printf("Time:");
						
						gotoxy(13,5);
						printf("From:");
						
						gotoxy(26,5);
						printf("To:");
						
						gotoxy(45,5);
						printf("Flight No:");
						
						gotoxy(60,5);
						printf("Status:");
						
						gotoxy(2,6); for(i=0;i<74;i++) printf("%c",205);
						
						s=8;
						while(fread(&tommorrowD,sizeof(tommorrowD),1,fp)==1)
						{
							delay(50);
							gotoxy(3,s);
							printf("%s",tommorrowD.time);
							gotoxy(13,s);
							printf("Karachi");
							gotoxy(26,s);
							printf("%s",tommorrowD.to);
							gotoxy(45,s);
							printf("%s",tommorrowD.flight_no);
							gotoxy(60,s);
							printf("%s",tommorrowD.status);
							s=s+2;
							
							gotoxy(3,(s-1));
							for(i=0;i<73;i++) printf("%c",196);
						}
						fclose(fp);
						
						gotoxy(2,153);
						printf("\n\tPress anykey to go back to HOME Window: ");
						getch();
						break;
					case '4':							// Case: to modify Today Arrival's Status.
						system("cls");
						fp=fopen("todayD.dat","rb+");
						another='y';
						while(another=='y')
						{
							printf("\nEnter Flight Number to modify Status: ");
							gets(f_no);
							
							long int recsize;
							recsize=sizeof(todayD);
							rewind(fp);
							while(fread(&todayD,recsize,1,fp)==1)
							{
								if(strcmp(todayD.flight_no,f_no)==0)
								{
									puts("Enter new Status: ");
									gets(todayD.status);
									
									fseek(fp,-recsize,SEEK_CUR);
									fwrite(&todayD,recsize,1,fp);
									break;
								}
								
							}
							printf("\nModify another Record(y/n)");
							fflush(stdin);
							another=getche();
						}
						fclose(fp);
						break;
				}
				break;
			case '6':
				system("cls");					// Clear The Screen...
				gotoxy(30,2);
				printf("%c Price List %c",17,16);
				rectangle(1,4,78,100);
				
				fp=fopen("pricelist.dat","rb");
				if(fp==NULL)
				{
					puts("Cannot open file");
					exit(1);
				}
				gotoxy(3,5);
				printf("City Name:");
				
				gotoxy(23,5);
				printf("First Class:");
				
				gotoxy(40,5);
				printf("Business Class:");						
				
				gotoxy(60,5);
				printf("Economy Class:");
						
				gotoxy(2,6); for(i=0;i<75;i++) printf("%c",205);
				
				s=8;
				while(fread(&cp,sizeof(cp),1,fp)==1)
				{
					delay(100);
					gotoxy(3,s);
					printf("%s",cp.cityname);
					gotoxy(27,s);
					printf("%d",cp.firstclss);
					gotoxy(45,s);
					printf("%d",cp.businesclss);
					gotoxy(65,s);
					printf("%d",cp.economyclss);

					s=s+2;
					
					gotoxy(3,(s-1));
					for(i=0;i<73;i++) printf("%c",196);
					
				}
				fclose(fp);
				
				gotoxy(2,103);
				printf("\n\tPress anykey to go back to HOME Window: ");
				getch();						// without this function, data show but not stop on screen.
				break;

			case '0':							// Case: to Exit the Program.
				system("cls");
				gotoxy(23,3);
				delay(150);
				printf("DESIGNED and PROGRAMMED by");
				gotoxy(22,4);
				for(i=0;i<28;i++) printf("%c",167);
				
				gotoxy(18,6);
				delay(150);
				printf("Name\t\t\t\t       Roll No.");
				gotoxy(16,8);
				delay(150);
				printf("1. Muhammad Asif\t\t\t15");
				gotoxy(16,10);
				delay(150);
				printf("2. Faiza Yaseen\t\t\t\t02");
				
				gotoxy(32,14);
				printf("Session: 2014-2018");
				gotoxy(35,16);
				printf("Semester 2nd");
				gotoxy(16,20);
				delay(250);
				printf("With  the Unexplainable Help of Mr. Omer Ajmal Siddiqui");
				gotoxy(10,24);
				printf("Exiting in 3 second...........>");
				
				delay(3000);
				gotoxy(12,26);
				printf("...........Allah Hafiz..........");
				gotoxy(12,28);
				printf("\n\n\n");
				exit(0);
		}
	}
}


int TotalPriceCalculation()					//  We are Defining a function to calculate price of Tickets.
{
	int total;
	long int recsize;
	char first[10]="First", business[10]="Business", economy[10]="Economy";
	
	ft=fopen("pricelist.dat","rb");
	
	recsize=sizeof(cp);
	while(fread(&cp,recsize,1,ft)==1)
	{
		if(strcmp(cp.cityname,t.to)==0)
		{
			if(strcmp(t.clss,first)==0)
			{
				pl.firstAdult=((cp.firstclss)*(t.adults));
				pl.firstChild=((cp.firstclss)*(0.75)*(t.children));
				pl.firstInfant=((cp.firstclss)*(0.6)*(t.infants));
				total = pl.firstAdult + pl.firstChild + pl.firstInfant;
				break;
			}
			else if(strcmp(t.clss,business)==0)
			{
				pl.businessAdult=((cp.businesclss)*(t.adults));
				pl.businessChild=((cp.businesclss)*(0.75)*(t.children));
				pl.businessInfant=((cp.businesclss)*(0.6)*(t.infants));
				total = pl.businessAdult + pl.businessChild + pl.businessInfant;
				break;
			}
			else if(strcmp(t.clss,economy)==0)
			{
				pl.economyAdult=((cp.economyclss)*(t.adults));
				pl.economyChild=((cp.economyclss)*(0.75)*(t.children));
				pl.economyInfant=((cp.economyclss)*(0.6)*(t.infants));
				total = pl.economyAdult + pl.economyChild + pl.economyInfant;
				break;
			}
			break;
		}
	}
	fclose(ft);
	return total;
}





void welcome()						// We are Defining 'Welcome' Function here.
{
    int i;
    system("cls");					// Clear The Screen...
    rectangle(20,2,58,23);
    gotoxy(25,4); printf("JINNAH Int. AIRPORT KARACHI");
    gotoxy(25,5); for(i=0;i<27;i++) printf("%c",196);
    gotoxy(25,9); printf("Designed and Programmed by:");
    gotoxy(25,10);for(i=0;i<27;i++) printf("%c",196);
    gotoxy(33,12); printf("MUHAMMAD ASIF");
    gotoxy(33,14); printf("FAIZA  YASEEN");
    
	gotoxy(24,20);
    printf("Press Any key to continue...");


    getch();

}

void rectangle(int x,int y,int l,int b)			// We Are Defining 'Rectangle'Function here.
{
    int i,m;
    gotoxy(x,y);
	printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y);
	printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m);
				printf("%c",186);
            }
        }
    }

    gotoxy(x,m);
	printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m);
	printf("%c",188);
}

void new_rectangle(int x1,int y1,int x2,int y2,int n,int c)
{
	int i;
	for(i=1;i<=n;i++)
	{
		gotoxy(x1,y1);			// 	x1=10, y1=5
		delay(140);
		printf("%c",c);
		gotoxy(x1,i+y1);
	//	delay(130);
		printf("%c",c);
		gotoxy(i+x1,y1);
		//delay(130);
		printf("%c",c);
		
		gotoxy(x2,y2);			// x2=35, y2=20
		printf("%c",c);
		gotoxy(x2,y2-i);
		printf("%c",c);
		gotoxy(x2-i,y2);
		printf("%c",c);
		
		gotoxy(x1,y2);			// x1, y2
		printf("%c",c);
		gotoxy(x1,y2-i);
		printf("%c",c);
		gotoxy(x1+i,y2);
		printf("%c",c);
		
		gotoxy(x2,y1);			// x2, y1
		printf("%c",c);
		gotoxy(x2,y1+i);
		printf("%c",c);
		gotoxy(x2-i,y1);
		printf("%c",c);
		
		
	}
	
}


COORD coord = {0, 0};				// Structure, Defined in library 'Windows.h'.
void gotoxy (int x, int y)			// Defining gotoxy function here...
{
	coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
