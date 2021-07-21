//C++ PROJECT

//START OF THE PROGRAM FOR HOTEL MANAGEMENT

#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

//START OF CLASS
class date{
	public:
	int d;
	int m;
	int y;
	
	
	int getDifference(date, date);
	
	friend ostream &operator<<( ostream &output, const date &dt ) { 
         output << " " << dt.d << " / " << dt.m <<" / "<< dt.y;
         return output;            
      }

      friend istream &operator>>( istream  &input, date &dt ) { 
         input >> dt.d >> dt.m >> dt.y;
         return input;            
      }
};
const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
int countLeapYears(date d)
{
    int years = d.y;
 
    if (d.m <= 2)
        years--;

    return years / 4
           - years / 100
           + years / 400;
}
int date::getDifference(date dt1, date dt2)
{
	int i;
    long int n1 = dt1.y * 365 + dt1.d;
 
    for (i=0; i<dt1.m-1; i++)
    {
		n1 += monthDays[i];
    }
    n1 += countLeapYears(dt1);
    
	long int n2 = dt2.y * 365 + dt2.d;
    
	for (i=0; i<dt2.m-1; i++)
    {
	    n2 += monthDays[i];
	}
    n2 += countLeapYears(dt2);
 
    return (n2 - n1);
}



class hotel : public date
{
	int room_no;
	char name[30];
	char address[50];
	char phone[10];
	date checkin_date;
	date checkout_date;
	public:
		
		void add();			//to book a room
		void display(); 		//to display the customer record
		void rooms();			//to display alloted rooms
		void edit();			//to edit the customer record
		int check(int);			//to check room status
		void modify(int);		//to modify the record
		void delete_rec(int);		//to delete the record
		void bill(int);                 //for the bill of a record	
};
class staff: public hotel{
	char sname[40];
	int sid;
	char sphone[10];
	float salary;
	date joining;
	public:
		void main_menu();
		void staffAdd();
		void staffDisplay();
};
    //END OF CLASS



//FOR DISPLAYING MAIN MENU



void staff::main_menu()
{
	int x,y,choice;
	while(x!=3)
	{	
		system("cls");
		int x,y;
		cout<<"1.  Admin"<<endl;
		cout<<"2.  Staff"<<endl;
		cout<<"3.  Exit"<<endl<<endl;
		cout<<"Enter choice"<<endl;
		cin>>x;
		switch(x){
		case 1:
			{
				system("cls");
				const string USERNAME = "manager";
				const string PASSWORD = "password";
				string username, password;
				bool user_validated = false;

				do 
				{
		
					cout << "Insert ID:";
					cin >> username;

					if (username.length() < 4)
					{
						cout << "Username length must be atleast 4 characters long.";
					}
					else  
					{
						cout << "Insert ID password:";
						cin >> password;
			
					if (password.length() < 6)
					{
						cout << "Password length must be atleast 6 characters long." << endl;
					}
					else 
					{
			
						if (username == USERNAME && password == PASSWORD)
						{
							cout << "User credentials are correct, Granting access" << endl;
							user_validated = true;
						}
						else
						{
							cout << "Wrong Serial number" << endl;
						}
					}
					}
				} while (user_validated == false);
				
				while(choice!=5){
				system("cls");
				cout<<"HOTEL MANAGEMENT"<<endl<<endl;
				cout<<"MAIN MENU"<<endl<<endl;
				cout<<"1.Book A Room"<<endl;
				cout<<"2.Customer Records"<<endl;
				cout<<"3.Rooms Allotted"<<endl;
				cout<<"4.Edit Record"<<endl;
				cout<<"5.Bill Of Customer"<<endl;
				cout<<"6.Staff's details"<<endl;
				cout<<"7.Exit"<<endl<<endl;
				cout<<"Enter Your Choice: "<<endl;
				cin>>choice;

				switch(choice)
				{

				case 1:	add();
				break;

				case 2: display();
				break;

				case 3: rooms();
				break;

				case 4:	edit();
				break;
				
				case 5: 
				{
					int ro;
					cout<<"enter room number:"<<endl;
					cin>>ro;
					bill(ro);
					break;
				}
				
				case 6:
					{
						int m;
						cout<<"1. Add record"<<endl;
						cout<<"2. Display staff record"<<endl;
						cout<<"3. Return"<<endl;
						cin>>m;
						switch(m)
						{
							case 1:staffAdd();
							break;
							case 2:staffDisplay();
							break;
							case 3:break;
							default:cout<<"invalid"<<endl;
						}
					}
				case 7: break;
				default:
				{

				cout<<"\n\n\t\t\tWrong choice.....!!!";
				cout<<"\n\t\t\tPress any key to   continue....!!";
				getch();

				}	

			}
 
			}}
			break;
		case 2:
			{
				cout<<"\n\t\t\t1.Customer Records";
				cout<<"\n\t\t\t2.Exit";
				cout<<"\n\n\t\t\tEnter Your Choice: ";
				cin>>y;

  				switch(y)
				{
					case 1: display();
					break;

					case 2: exit(0);

				default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to   continue....!!";
					getch();
				}
			}
		}
		break;
		case 3:exit(0);
		default:
			{
				cout<<"wrong input"<<endl;
				cout<<"press any key to contimue"<<endl;
				getch();
			}
	
}
	




}}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF ROOM


void hotel::add()
{

  system("cls");
	int r,flag;
	ofstream fout("Record.dat",ios::app);

	cout<<"Enter Customer Detalis"<<endl;
	cout<<"----------------------"<<endl<<endl;
	cout<<"Room no: "<<endl;
	cout<<"Total no. of Rooms - 200"<<endl;
	cout<<"Ordinary Rooms from 1 - 130"<<endl;
	cout<<"Luxuary Rooms from 131 - 170"<<endl;
	cout<<"Royal Rooms from 171 - 200"<<endl<<endl;
	cout<<"Enter The Room no. you want to stay in: "<<endl;
	cin>>r;

	flag=check(r);

	if(flag)
		cout<<"Sorry.....Room is already booked"<<endl;
	else if(r>200)
	{
			cout<<"invalid"<<endl;
	}
	else
	{
		room_no=r;
		cout<<" Name: "<<endl;
		cin>>name;
		cout<<" Address: "<<endl;
		cin>>address;
		cout<<" Phone No: "<<endl;
		cin>>phone;
		cout<<"check in date: "<<endl;
		cin>>checkin_date;
		cout<<"check out date: "<<endl;
		cin>>checkout_date;		
		
	
		fout.write((char*)this,sizeof(hotel));
		cout<<"\n\n Room is booked"<<endl;
	}

	cout<<"Press any key to continue.....!!"<<endl;

	getch();
	fout.close();
}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PARTICULAR CUSTOMER`S RECORD





void hotel::display()
{
    system("cls");

	ifstream fin("Record.dat",ios::in);
	int r,flag;
	
	cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
	cin>>r;
	
	int username1, password1;
				username1=password1=r;
				bool user_validated = false;

				do 
				{
		
					cout << "Insert ID:";
					cin >> username1;

					cout << "Insert ID password:";
					cin >> password1;
			
			
					if (username1 == r && password1 == r)
					{
						cout << "User credentials are correct, Granting access" << endl;
						user_validated = true;
					}
					else
					{
						cout << "Wrong Serial number" << endl;
					}
				
				} while (user_validated == false);
	
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
		  system("cls");
		cout<<"\n Customer Details"<<endl;
		cout<<"-------------------"<<endl<<endl;
		cout<<"Room no: "<<room_no<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Address: "<<address<<endl;
		cout<<"Phone no: "<<phone<<endl;
		
	

		flag=1;
		break;
		}
	}

	if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant....!!";
	cout<<"\n\n Press any key to continue....!!";

	getch();
	fin.close();
}


//END OF DISPLAY FUNCTION

//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void hotel::rooms()
{

  system("cls");

	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t\tList Of Rooms Allotted"<<endl;
	cout<<"\t\t\t\t----------------------"<<endl<<endl;
	cout<<"Room No.\tName\t\tPhone No.\tcheck in date\t\tcheck out date\t\tAddress"<<endl;

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		cout<<endl<<room_no<<"\t\t"<<name;
		cout<<"\t\t"<<phone;
		cout<<"\t"<<checkin_date<<"\t\t"<<checkout_date<<"\t\t"<<address<<endl;
	}

	cout<<"\t\t\tPress any key to continue"<<endl;
	getch();
	fin.close();
}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void hotel::edit()
{

  system("cls");

	int choice,r;	
	cout<<"EDIT MENU"<<endl;
	cout<<"---------"<<endl<<endl;
	cout<<"1.Modify Customer Record"<<endl;
	cout<<"2.Delete Customer Record"<<endl;
	
	cout<<"Enter your choice: "<<endl;

	cin>>choice;
	  system("cls");

	cout<<"Enter room no: "<<endl;
	cin>>r;

	switch(choice)
	{
		case 1:	modify(r);
		break;

		case 2:	delete_rec(r);
		break;

		default: cout<<"\n Wrong Choice.....";

	}
	cout<<"\n Press any key to continue";

	getch();
}


int hotel::check(int r)
{

	int flag=0;

	ifstream fin("Record.dat",ios::in);

	while(!fin.eof())
	{

		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			flag=1;
			break;
		}

	}

	fin.close();
	return(flag);
}


//FUNCTION TO MODIFY CUSTOMERS RECORD


void hotel::modify(int r)
{

	long pos,flag=0;

	fstream file("Record.dat",ios::in|ios::out|ios::binary);

	while(!file.eof())
	{	
		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));

		if(room_no==r)
		{		
			cout<<"\n Enter New Details";
			cout<<"--------------------"<<endl<<endl;
			cout<<"Name: "<<endl;
			cin>>name;
			cout<<"Address: "<<endl;
			cin>>address;
			cout<<"Phone no: "<<endl;
			cin>>phone;

			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n Record is modified....!!";
			flag=1;
			break;
		}
	}

	if(flag==0)
	cout<<"\n Sorry Room no. not found or vacant...!!";
	file.close();
}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void hotel::delete_rec(int r)
{

	int flag=0;
	char ch;
	/*
	ifstream fin;
	fin.open("Record.dat", ios::in|ios::binary);
	ofstream fout;
	fout.open("temp.dat", ios::in|ios::binary);

	while(!fin.eof())
	{
		fin.read((char*)this, sizeof(hotel));
		if(fin)
		{
			if(room_no==r)
			{
				flag=1;
				cout<<"the deleted record is "<<endl;
				cout<<"\n Name: "<<name;
				cout<<"\n Address: "<<address;
				cout<<"\n Phone No: "<<phone;
			}
			else
			{
				fout.write((char*)this, sizeof(hotel));
			}
		}
	}
	fout.close();
	fin.close();

	remove("Record.dat");
	
	rename("temp.dat","Record.dat");
	if (flag == 1)
        cout << "\nrecord successfully deleted \n";
    else
        cout << "\nrecord not found \n";
}*/


	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone No: "<<phone;
			cout<<"\n Check in date: "<<checkin_date;
			cout<<"\n Chech out date: "<<checkout_date;
			cout<<"\n\n Do you want to delete this record(y/n): ";
			cin>>ch;

			if(ch=='n')
			fout.write((char*)this,sizeof(hotel));
		
			flag=1;
		}

		else
		fout.write((char*)this,sizeof(hotel));
	}

	fin.close();
	fout.close();

	if(flag==0)
	cout<<"\n Sorry room no. not found or vacant...!!";

	else
	{
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}

}


//END OF DELETE FUNCTION


//FUNCTION FOR CUSTOMER`S BILL

void hotel::bill(int r)
{
	system("cls");
	hotel h1;
	int gap=getDifference(checkin_date,checkout_date);
	cout<<"Check in date: "<<checkin_date<<endl;
	cout<<"Check out date: "<<checkout_date<<endl;
	cout<<gap<<endl;
	ifstream f1;
	f1.open("record.dat", ios::in);

	if(!f1)
		cout<<"cannot open";

	else
	{
		f1.read((char*)&h1,sizeof (hotel));
		while(f1)
  		
		{
  		
		  	f1.read((char*)&h1,sizeof(hotel));
		
		}

	    if (h1.room_no == r)
	    {
	
	  		if(h1.room_no>=1&&h1.room_no<=130)
	  		cout<<"your bill = "<<2000*gap<<endl;
	
	  		else if (h1.room_no>=130&&h1.room_no<=170)
  			cout<<"your bill = "<<5000*gap<<endl ;

	  		else
	  		cout<<"your bill = "<<7000*gap<<endl;
  	}

   else
   { cout<<"room no. not found";}

   }

   f1.close();
   getch();
}

//END OF BILLING FUNCTION

void staff::staffAdd()
{
  system("cls");
	int r,flag;
	ofstream f("Record.dat",ios::out);

	cout<<"Enter staff member's Details"<<endl;
	cout<<"----------------------"<<endl<<endl;
	cout<<"employee id "<<endl;
	
	cin>>r;

	flag=check(r);

	if(flag)
		cout<<"record already exists"<<endl;
	else
	{
		sid=r;
		cout<<"Name: "<<endl;
		cin>>sname;
		cout<<"Phone No: "<<endl;
		cin>>sphone;
		cout <<"Salary: "<<endl;
 		cin >> salary;
 		cout <<"Date of joining: "<<endl;
 		cin >> joining;
	
		f.write((char*)this,sizeof(hotel));
		cout<<"\n\n record is added"<<endl;
	}

	cout<<"Press any key to continue.....!!"<<endl;

	getch();
	f.close();
}
void staff::staffDisplay()
{
    system("cls");

	ifstream f1("Record.dat",ios::in);
	cout<<"employee id\tName \t\tPhone No.\t salary\t\t Date of joining "<<endl;

	while(!f1.eof())
	{
		f1.read((char*)this,sizeof(hotel));
		cout<<endl<<sid<<"\t\t"<<sname;
		cout<<"\t\t"<<sphone<<"\t\t"<<salary<<"\t\t"<<joining<<endl;
	}

	cout<<"\t\t\tPress any key to continue"<<endl;
	getch();
	f1.close();
}
//START OF MAIN PROGARM


int main()
{
	staff s;
	system("cls");

	cout<<"\t\t\t\t\t      HOTEL MANAGEMENT PROJECT"<<endl<<endl<<endl;
	cout<<"\t----------------------------------------------------------------------------------------------------------"<<endl<<endl;

	cout<<"\t\t\t\t\t\t\t\t\t\t\tproject submitted by"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAashi     UE203001"<<endl; 
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAnanya    UE203014"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAngel     UE203015"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAnshika   UE203018"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tproject submitted to"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tDr. Mamta Juneja"<<endl<<endl<<endl;

	cout<<"\t\t\t\t\tPress any key to continue"<<endl;
	getch();

	s.main_menu();
	return 0;
}

//END OF MAIN PROGRAM
