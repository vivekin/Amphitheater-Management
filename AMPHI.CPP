
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<process.h>
 int ticketcount =0;
 void textcolor(int no);    //for setting text colour
class exp
{
 protected:
 float maintanace,payroll,misc,totalexp;
 public:
 exp()
 {
  maintanace=0;
  payroll=0;
  misc=0;
  totalexp=0;
 }
 void getexp()
 {
  cout<<"\nEnter Maintanace: ";
  cin>>maintanace;
  cout<<"\nEnter Other: ";
  cin>>misc;
  payroll=calcpayroll();
 }

 float calcpayroll();

 void totexp()
 {
  totalexp=maintanace+payroll+misc;
  }

 void putexp()
 {
  cout<<"\nMaintance: "<<maintanace;
  cout<<"\nPayroll: "<<payroll;
  cout<<"\nMisc: "<<misc;

 }
 };

class fin:public exp
{
 float donations,totin;
 public:
 void getdona()
 {
  cout<<"\nDonation Amount: ";
  cin>>donations;
  }

 void total()
 {
   totin= (ticketcount*5000) + donations ;
 }

 void putfin()
 {
  cout<<"\n***Expense***"<<endl;
  putexp();
  cout<<"\n***Income***"<<endl;
  cout<<"\nTickets: "<<ticketcount*5000<<endl;
  cout<<"\nDonations: "<<donations<<endl;
  cout<<"\nOverall\n"<<endl;
  cout<<"\nTotalExpense: "<<totalexp<<endl;
  cout<<"\nTotal Income: "<<totin<<endl;
  cout<<"Profit: "<<totin-totalexp;
  }
};  //end of finance

struct ticket
{
 int Prcode;               //Unique ID for each show assigned by admin
 int qty;
 int Tcode;                   //randomly generated after entry of ticket details
};

struct date
{
 int day,month,year;
};

class shows
{
 int Pcode;             //Unique ID of the show assigned by the administrator
 char title[25],time;
 date dtofshow;

public:

void getshows()            //only for entry by admin
{
 cout<<"\nEnter The Code Of The Show : ";
 cin>>Pcode;
 cout<<"\nEnter The Title : ";
 gets(title);
 cout<<"\nEnter The Time Of The Show ( m-Morning , n-Noon , e-Evening ) : ";
 cin>>time;
 cout<<"\nEnter The Date Of The Show : \nDate : ";
 cin>>dtofshow.day;
 cout<<"Month : ";
 cin>>dtofshow.month;
 cout<<"Year : ";
 cin>>dtofshow.year;

}

void putshows();  //output function defined outside


int retpcode()
{
 return Pcode;
}

}; //end of class shows

void shows::putshows()
{
cout<<"\n"<<Pcode<<"\t\t"<<title<<"\t"<<dtofshow.day<<"/"<<dtofshow.month<<"/"<<dtofshow.year<<"\t\t";
    switch(time)
     {case 'm': cout<<"Morning";
       break;
       case 'n' : cout<<"Noon";
       break;
       case 'e': cout<<"Evening";
     default:  ;
     }

cout<<"\n";

}  //output function of class shows ends





class employee     //class declaration
{
 char name[15];
 int empno;
 float sal;
 char dept[15];
 public:
 void getdata();
 void putdata();
 int retempno()     //returns employee number for checking
 {
  return empno;
 }
 float retsal()
 {
  return sal;
 }
};

void employee::getdata()
{
 cout<<"\nEnter Employee no : ";
 cin>>empno;
 cout<<"Enter Name : ";
 gets(name);
 cout<<"Enter Salary : ";
 cin>>sal;
 cout<<"Enter Department : ";
 gets(dept);
}

void employee::putdata()
{
 cout<<"\n"<<empno<<"\t\t"<<name<<"\t\t"<<sal<<"\t\t"<<dept<<endl;
}
 float exp::calcpayroll()
 {
  float tp=0;
  employee ep;

  ifstream pfile("EMP.DAT",ios::binary);
  if(!pfile)
  cout<<"\nCannot Open File For Reading\n";

  pfile.read((char*)&ep,sizeof(ep));
  while(pfile)
  {
    tp+=ep.retsal();
    pfile.read((char*)&ep,sizeof(ep));
  }
  return tp;
 } //calcpayroll ends






void main()
{

 clrscr();
 randomize();
 employee obj;
 int i,opt,f,op;
 char ch;
 shows shw;
 ticket tikt;
 fin fin1;

 textcolor(2);


cout<<".........................................................."<<endl;
cout<<". \ o /  _ o        __|    \ /     |__         o _  \ o /   ."<<endl;
cout<<".   |     /\   __\o   \o    |    o/     o/__   /\     |      ."<<endl;
cout<<".  / \   | \  /) |    ( \  /o\  / )    |   (\  / |   / \       ."<<endl;
cout<<".       ..........................................       ."<<endl;
cout<<".  _ o  .                                        .  _ o  ."<<endl;
cout<<".   /\   .                                        .   /\   ."<<endl;
cout<<".  | \   .                                        .  | \   ."<<endl;
cout<<".       .                                        .       ."<<endl;
cout<<".  __\o  .                                        .  __\o  ."<<endl;
cout<<". /) |  .                                        . /) |  ."<<endl;
cout<<".       .                                        .       ."<<endl;
cout<<". __|   .                                        . __|   ."<<endl;
cout<<".   \o   .                                        .    \o  ."<<endl;
cout<<".   ( \  .                                        .   ( \  ."<<endl;
cout<<".       .                                        .       ."<<endl;
cout<<".  \ /   .         AMPHITHEATRE MANAGEMENT        .  \ /   ."<<endl;
cout<<".   |   .                                        .   |   ."<<endl;
cout<<".  /o\   .                                        .  /o\   ."<<endl;
cout<<".       .                                        .       ."<<endl;
cout<<".   |__ .                                        .   |__ ."<<endl;
cout<<". o/    .                                        . o/    ."<<endl;
cout<<"./ )    .                                        ./ )    ."<<endl;
cout<<".       .                                        .       ."<<endl;
cout<<". o/__  .                                        . o/__  ."<<endl;
cout<<".  | (\  .                                        . |  (\  ."<<endl;
cout<<".       .                                        .       ."<<endl;
cout<<".  o _  .                                        .  o _  ."<<endl;
cout<<".  /\    .                                        .  /\    ."<<endl;
cout<<".  / |  .                                        .  / |  ."<<endl;
cout<<".       ..........................................       ."<<endl;
cout<<". \ o /  _ o        __|    \ /     |__         o _  \ o /   ."<<endl;
cout<<".   |     /\   __\o   \o    |    o/     o/__   /\     |      ."<<endl;
cout<<".  / \   | \  /) |    ( \  /o\  / )    |   (\  / |   / \       ."<<endl;
cout<<".........................................................."<<endl;

 do
 {
  cout<<"\nAMPHITHEATRE MANAGEMENT"<<endl;
  cout<<"\n****MENU****\n";
  cout<<"1.Ticket\n2.Staff\n3.Administrator\n4.Exit\n";
  cout<<"\nEnter Your Option : ";
  cin>>opt;
  clrscr();
  switch(opt)

  {


    case 1:do
	   {
	    cout<<"\n****TICKET MENU****\n";
	    cout<<"1.Ticket Booking\n2.Ticket Canceling\n3.Ticket Status\n4.Back\n";
	    cout<<"\nEnter Your Option : ";
	    cin>>opt;
	    switch(opt)
	    {
	     case 1 :ifstream sfile("SHOW.DAT",ios::binary);
		     if(!sfile)
		      cout<<"\n\nCannot Open File For Reading";
		     ofstream tfile("TICKET.DAT",ios::binary|ios::app);
		     if (!tfile)
		      cout<<"\n\nCannot Open File For Writing";

		     cout<<"Show Code\tTitle \t\tShow Date\t\tShow Timing\n";
		     sfile.read((char*)&shw,sizeof(shw));
		     while(sfile)
		     {
		      shw.putshows();
		      sfile.read((char*)&shw,sizeof(shw));
		     }

		     cout<<"\nEnter The Show Code Of The Required Show To Book Tickets : ";
		     cin>>tikt.Prcode;

		     ifstream chekscode("SHOW.DAT",ios::binary);
		     if(!chekscode)
		      cout<<"\nCannot Open File For Reading\n";

		     f=0;
		     chekscode.read((char*)&shw,sizeof(shw));
		     while(chekscode)
		     {
		      if(shw.retpcode()==tikt.Prcode)
		      {
		       f=1;
		       cout<<"Enter The Quantity Of Tickets To Be Purchased : ";
		       cin>>tikt.qty;

		       for(i=1;i<=tikt.qty;++i) /*each ticket with a
						  unique Tcode is stored
						  in a file*/
		       { /*the Tcode is shown to the
			  user in case of ticket status viewing
			  and ticket cancellation*/
			tikt.Tcode=random(9000)+1000;

			cout<<"\nTicket Code Of Ticket no."<<i
			    <<" Is : "<<tikt.Tcode<<endl;

			ticketcount++; /*ticket count is incremented as
					 ticket is booked*/
			tfile.write((char*)&tikt,sizeof(tikt));

		       } //FOR LOOP ENDS
		      } //THAT IF HAS THE AUTHORITY TO RESERVE A TICKET

		       chekscode.read((char*)&shw,sizeof(shw));
		      } //THAT WHILE LOOOP ENDS

		      if(f==1)
		       cout<<"\nTicket(s) Reserved\n";
		      else
		       cout<<"\n\t\t\t***INVALID SHOW CODE***\nPLEASE RETRY BOOKING!!\n";

		     break;   //END OF TICKET BOOKING


	     case 2: //TICKET CANCELLING
		    ofstream tempfile("TEMP.DAT",ios::binary|ios::app);
		    if (!tempfile)
		     cout<<"\n\nCannot Open File For Writing";
		    ifstream tfile1("TICKET.DAT",ios::binary);
		    if (!tfile1)
		     cout<<"\n\nCannot Open File For Reading";

		    do
		    {
		     f=0;
		     cout<<"\n\nEnter The Ticket Code Of The Ticket To Be Cancelled : ";
		     cin>>op;

		     tfile1.read((char*)&tikt,sizeof(tikt));
		     while(tfile1)
		     {
		      if(tikt.Tcode==op)
		      {
		       f=1;
		       break;
		      }
		      else
		      tempfile.write((char*)&tikt,sizeof(tikt));
		     }   //while loop ends

		     if (f==1)
		     {
		      cout<<"\n\nTicket Cancelled\n\n";
		      ticketcount--;                                //ticket count is decremented as ticket is cancelled
		     }
		     else
		      cout<<"\nUnable To Cancel Ticket";

		     cout<<"Do You Want To Cancel Another Ticket? (y/n)"<<endl;
		     cin>>ch;
		     toupper(ch);
		    }while(ch=='Y');
		    tempfile.close();
		    tfile1.close();
		    break;


	     case 3:  //TICKET VIEWING
		    ifstream sflop("SHOW.DAT",ios::binary);
		    if(!sflop)      //error statement
		     cout<<"Cannot Open File For Reading";
		    ifstream tfile2("TICKET.DAT",ios::binary);
		    if (!tfile2)
		     cout<<"\n\nCannot Open File For Reading";
		    else
		    {
		    cout<<"Enter The Ticket Code : ";
		    cin>>op;
		    f=0;

		    tfile2.read((char*)&tikt,sizeof(tikt));
		    while(tfile2)
		    {
		     if(tikt.Tcode==op)
		     {
		      sflop.read((char*)&shw,sizeof(shw));   //reading the file
		      while(sflop)
		      {
		       if(shw.retpcode()==tikt.Prcode)
			{
			 f=1;
			 cout<<"Show Code\t Title \t\t Show Date\t\t Show Timing\n";
			 shw.putshows();
			  }      //output function
			sflop.read((char*)&shw,sizeof(shw));
		       }
		      } //if statement block ends
		     tfile2.read((char*)&tikt,sizeof(tikt));
		    }
		    if (f!=1)
		    cout<<"\nTicket Not Found\n";
		    }

		    break;

	     case 4:   //back option

		    break;
		default:cout<<"\nInvalid Entry\n";

	    }    //SWITCH CASE INSIDE TICKET DO WHILE
	    cout<<"\nDo You Want To Continue Ticket Menu??(y/n) : ";
	    cin>>ch;
	    cout<<endl;
	    clrscr();
	   }while(ch=='y');    //TICKET CASE DO WHILE ENDS

	 break;        //TICKET OPTION ENDS


    case 2: do
	{
	cout<<"\n****STAFF MENU****\n";
	cout<<"1.New Staff\n2.Display\n3.Delete\n4.Modify Details\n5.Back\n";
	cout<<"\nEnter Your Option : ";
	cin>>opt;

	switch(opt)
	{
	 case 1:fstream ofl("EMP.DAT",ios::app|ios::binary);
		if(!ofl)                    //error statement
		cout<<"Cannot Open File For Writing";
		do
		{
		 obj.getdata();        //input function
		 ofl.write((char*)&obj,sizeof(obj));  //writing into the file
		 cout<<"Do You Want To Enter More Details? (y/n)"<<endl;
		 cin>>ch;
		}while(ch=='y');   //EMPLOYEE INPUT DO WHILE
		ofl.close();
		break;

	 case 2:ifstream ifl("EMP.DAT",ios::binary);
		if(!ifl)      //error statement
		 cout<<"Cannot Open File For Reading";
		cout<<"Emp No.\t\tName\t\tSalary\t\tDepartment\n";
		ifl.read((char*)&obj,sizeof(obj));   //reading the file
		while(ifl)
		{
		 obj.putdata();      //output function
		 ifl.read((char*)&obj,sizeof(obj));
		}
		ifl.close();
		break;

	 case 3:ifstream ifl2("EMP.DAT",ios::binary);
		ofstream ofl2("TEMP.DAT",ios::binary);
		if(!ifl2)
		 cout<<"Cannot Open File For Reading";
		if(!ofl2)
		 cout<<"Cannot Open File For Writing";
		cout<<"Enter Employee no To Be Deleted : ";
		cin>>op;

		ifl2.read((char*)&obj,sizeof(obj));
		while(ifl2)
		{
		 if(obj.retempno()==op)
		 {
		  cout<<"Present Record : \n";
		  cout<<"Emp No.\t\tName\t\tSalary\t\tDepartment\n";
		  obj.putdata();
		  f=1;
		 }
		 else
		  ofl2.write((char*)&obj,sizeof(obj));
		 ifl2.read((char*)&obj,sizeof(obj));
		}
		ofl2.close();
		ifl2.close();
		if (f==1)
		 cout<<"Record Deleted";
		else
		 cout<<"Record Not Found";
		remove("EMP.DAT");
		rename("TEMP.DAT","EMP.DAT");
		break;

	 case 4:ifstream ifl3("EMP.DAT",ios::binary);
		ofstream ofl3("TEMP.DAT",ios::binary|ios::app);
		if(!ifl3)
		 cout<<"Cannot Open File For Reading";
		if(!ofl3)
		 cout<<"Cannot Open File For Writing";
		cout<<"Enter Employee no To Be Modified : ";
		cin>>op;
		f=op;
		ifl3.read((char*)&obj,sizeof(obj));
		while(ifl3)
		{
		 if(obj.retempno()==op)
		 {
		  cout<<"Present Record : \n";
		  cout<<"Emp No.\t\tName\t\tSalary\t\tDepartment\n";
		  obj.putdata();   //outputs the record about to be modified
		  cout<<"Do You Want To Modify?(y/n)";
		  cin>>ch;
		  if(ch=='y')
		  {
		   cout<<"\nEnter New Data : \n";
		   obj.getdata();  //recieves modified data
		   f=1;
		  }
		  ofl3.write((char*)&obj,sizeof(obj));
		 }
		 else
		  ofl3.write((char*)&obj,sizeof(obj));
		 ifl3.read((char*)&obj,sizeof(obj));
		}
		ofl3.close();
		ifl3.close();
		if (f==1)
		 cout<<"Record Modified\n";
		else
		 cout<<"Record Not Found\n";
		remove("EMP.DAT");
		rename("TEMP.DAT","EMP.DAT");
		break;

	 case 5: //back option
		break;

	 default :cout<<"\nInvalid Entry\n";
	}                //switchcase ends

	cout<<"\nDo You Want To Continue Staff Menu??(y/n) : ";
	cin>>ch;
	cout<<endl;
	clrscr();
       }while(ch=='y');    //CASE 2 DO WHILE ENDS
       break;             //STAFF OPTION ENDS


    case 3:do
       {
	clrscr();
	cout<<"\n****ADMINISTRATOR MENU****\n";
	cout<<"1.Finance\n2.Show Listing\n3.Back \n";
	cout<<"\nEnter Your Option : ";
	cin>>opt;

	switch(opt)
	{
	  case 1:
	     do
	     {
	     cout<<"\n***FINANCE***"<<endl;
	     cout<<"1.Input Expenses And Income\n2.Show Overall\n3.Back\n"<<endl;
	     cout<<"Enter Your Option : ";
	     cin>>opt;
	     switch(opt)
	     {
	      case 1:cout<<"\nEXPENSES\n"<<endl;
		 fin1.getexp();
		 fin1.totexp();
		 cout<<"\nINCOME"<<endl;
		 fin1.getdona();
		 fin1.total();
		 break;
	      case 2:cout<<endl<<"\nOVERALL"<<endl;
		     fin1.putfin();
		     break;
	      case 3:break;
	      default:cout<<"\nInvalid Entry\n"<<endl;
	      }
	     cout<<"\n\nDo You Want to Continue Finance Menu??(y/n) : ";
	     cin>>ch;
	     clrscr();
	     }while(ch=='y');

	     break;

	     case 2:do
		    {
		     clrscr();
		     cout<<"\n****SHOW LISTING MENU****\n";
		     cout<<"1.Create\n2.Delete\n3.Output All Shows\n4.Back \n";
		     cout<<"\nEnter Your Option : ";
		     cin>>opt;
		     switch(opt)
		     {
		      case 1:ofstream sfl("SHOW.DAT",ios::binary|ios::app);
			     if(!sfl)
			     cout<<"\nCannot Open File For Writing\n";

			     do
			     {
			      cout<<" \nEnter The Details Of The Show : ";
			      shw.getshows();

			      sfl.write((char*)&shw,sizeof(shw));
			      cout<<"Do You Want To Enter More Show Details? (y/n) : ";
			      cin>>ch;

			     }while(ch=='y');
			     break;

		      case 2:    //delete the show from the file

			     ifstream sfl1("SHOW.DAT",ios::binary);
			     ofstream sfl2("TEMP.DAT",ios::binary|ios::app);
			     if(!sfl1)
			      cout<<"Cannot Open File For Reading";
			     if(!sfl2)
			      cout<<"Cannot Open File For Writing";

			     cout<<"Enter Show Code To Be Deleted : ";
			     cin>>op;
			     sfl1.read((char*)&shw,sizeof(shw));
			     while(sfl1)
			     {
			      if(shw.retpcode()==op)
			      {
			       cout<<"Present Record : \n";
			       shw.putshows();
			       f=1;
			      }
			      else
			      sfl2.write((char*)&shw,sizeof(shw));
			      sfl1.read((char*)&shw,sizeof(shw));
			     }
			     sfl2.close();
			     sfl1.close();
			     if (f==1)
			      cout<<"Record Deleted";
			     else
			      cout<<"Record Not Found";
			     remove("SHOW.DAT");
			     rename("TEMP.DAT","SHOW.DAT");
			     break;                   //end of delete

		      case 3: //output all shows
			     ifstream sfile1("SHOW.DAT",ios::binary);
			     if(!sfile1)
			      cout<<"\nCannot Open File For Reading\n";

			     cout<<"Show Code\tTitle \t\tShow Date\t\tShow Timing\n";
			     sfile1.read((char*)&shw,sizeof(shw));
			     while(sfile1)
			     {
			      shw.putshows();
			      sfile1.read((char*)&shw,sizeof(shw));
			     }
			     sfile1.close();
			     break;

		      case 4:break;
		      default:cout<<"\nInvalid Entry\n";
		     }
		     cout<<"\nDo You Want To Continue Show Menu??(y/n) : ";
		     cin>>ch;
		     cout<<endl;
		     clrscr();
		    }while(ch=='y'); //SHOW DO WHILE ENDS
		    break;




	     case 3: break;
	     default: cout<<"\nInvalid Entry\n";

	    }  //ADMIN SWITCH CASE
	    cout<<"\nDo You Want To Continue Administrator Menu??(y/n) : ";
	    cin>>ch;
	    cout<<endl;
	    clrscr();
	   }while(ch=='y');    //ADMINISTRATOR DO WHILE ENDS

	   break;    //ADMINISTRATOR OPTION ENDS

  case 4: cout<<"THANK YOU";
	  exit(1);
	  break;
  default: cout<<"\nInvalid Entry\n";

  }  // HOME PAGE SWITCH CASE  ENDS
  cout<<"\nDo You Want To Continue MAIN MENU ??(y/n) : ";
  cin>>ch;
  cout<<endl;
  clrscr();
 }while(ch=='y');    //DO WHILE ENDS
 getch();

}
