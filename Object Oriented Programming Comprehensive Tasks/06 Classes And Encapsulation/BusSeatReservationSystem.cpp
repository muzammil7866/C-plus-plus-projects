#include <iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
//
class bus
{
public:
int BusNumber;
bool* seats = new bool[20];
static int buscount;
static int seatscapacity;
//
//	bus()
{
//		buscount++;
	BusNumber = 1000 + rand() % 8999;
	for (int i = 0; i < 20; i++)
	{
		seats[i] = true;
//		
	}
}
//
int getbuscount()const
{
	return buscount;
}
//
int getBusNumber()const
{
	return BusNumber;
}
void display()
{
	cout << "BUS DETAILS: " << endl;
	cout << "BUS NUMBER: " << BusNumber << endl;
//		
	for (int i = 0; i < 20; i++)
	{
		cout << "STATUS FOR THE SEAT NUMBER " <<setw(2)<<i + 1<< " :";
		if (seats[i] == 0)
			cout << "\t\tALREADY RESERVED"<<endl;
		else
			cout << "\t\t--AVAILABLE--" << endl;
	}
}
//	/*~bus()
{
	BusNumber = 0;
//		delete[] seats;
	for (int i = 0; i < 20; i++)
		seats[i] = NULL;
//
}*/
//
bool reserveSeat(int seatno)
{
	if (seats[seatno - 1] == true)
	{
		cout << "YOUR SEAT NUMBER "<<seatno<<" HAS BEEN SUCCESSFULLY BOOKED! :)"<<endl;
//			seats[seatno - 1] = false;
		return true;
	}
//
	else
	{
		cout << "SEAT NUMBER " << seatno << " IS ALREADY RESERVED. "<< endl;
		cout << "KINDLY CHOOSE SOME OTHER SEAT! ";
		return false;
	}
}
//
bool cancelSeat(int seatno)
{
	if (seats[seatno - 1] == false)
	{
		cout << "YOUR SEAT NUMBER " << seatno << " HAS BEEN SUCCESSFULLY CANCELLED! :)" << endl;
//			seats[seatno - 1] = true;
		return true;
	}
//
	else
	{
		cout << "SEAT NUMBER " << seatno << " IS NOT BOOKED AT ANY NAME. " << endl;
		cout << "KINDLY ENTER THE SEAT BOOKED AT YOUR NAME IN ORDER TO CANCEL IT! ";
		return false;
	}
}
};
//
//int bus::buscount = 0;
//int bus::seatscapacity = 20;
//
///*class ReservationSystem : public bus
{
public:
bus* busVector;
//
//	ReservationSystem()
{
	busVector = new bus[15];
	buscount = 15;
	for (int i = 0; i < 15; i++)
	{
		busVector[i].BusNumber = rand() % 100 + 1;
	}
//
	for (int i = 0; i < 15; i++)
	{
		for(int j=0; j<20; j++)
		{
			busVector[i].seats[j] = true;
		}
	}
}
//
//	~ReservationSystem()
{
	BusNumber = 0;
	for (int i = 0; i < 15; i++)
//			delete[] busVector[i].seats;
//
//		delete[] busVector;
	busVector = NULL;
//
}
//
//
void ReserveBusSeat(int busno, int seatno)
{
	for (int i = 0; i < 15; i++)
	{
		if(busVector[i].BusNumber == busno)
//				busVector[i].reserveSeat(seatno);
	}
}
};
//*/
//
class ReservationSystem
{
public:
bus* busVector;
//
//	ReservationSystem()
{
	busVector = new bus[15];
//		bus::buscount = 15;
}
//
//	~ReservationSystem()
{
//		delete[] busVector;
}
//
bool ReserveBusSeat(int busno, int seatno)
{
	for (int i = 0; i < 15; i++)
	{
		if (busVector[i].BusNumber == busno)
			return (busVector[i].reserveSeat(seatno));
	}
}
//
bool CancelBusSeat(int busno, int seatno)
{
	for (int i = 0; i < 15; i++)
	{
		if (busVector[i].BusNumber == busno)
			return (busVector[i].cancelSeat(seatno));
	}
}
//
int gettotalseats()const
{
	return bus::buscount * bus::seatscapacity;
}
//
int getbusno()const
{
	return bus::buscount;
}
//
int totalavailableseats()
{
	int availableSeatCount = 0;
		for (int i = 0; i < bus::buscount; i++)
		{
			for (int j = 0; j < bus::seatscapacity; j++)
			{
				if (busVector[i].seats[j] == true)
				{
//						availableSeatCount++;
				}
			}
		}
		return availableSeatCount;
}
//
int totalReservedSeats()
{
	int ReserveSeatCount = 0;
	for (int i = 0; i < bus::buscount; i++)
	{
		for (int j = 0; j < bus::seatscapacity; j++)
		{
			if (busVector[i].seats[j] == false)
			{
//					ReserveSeatCount++;
			}
		}
	}
	return ReserveSeatCount;
}
};
//
//
int main()
{
//	srand(time(0));
//
//	/*bus obj1;
//	obj1.display();
//	obj1.reserveSeat(15);
//	obj1.display();
//	obj1.cancelSeat(15);
//	obj1.display();
cout<<obj1.getbuscount();
//	
ReservationSystem obj2;
cout << endl;
//	obj2.ReserveBusSeat(obj2.busVector[12].BusNumber, 9);
//	obj2.busVector[12].display();
//	//obj2.CancelBusSeat(obj2.busVector[12].BusNumber, 9);
//	obj2.busVector[12].display();
cout<<obj2.getbusno()<<endl;
cout<<obj2.gettotalseats()<<endl;
cout << obj2.totalavailableseats()<<endl;
cout << obj2.totalReservedSeats()<< endl;
//	*/
//
//	system("Color B0");
ReservationSystem obj2;
//
bool endprogram = false;
while (endprogram != true)
{
//		system("cls");
	int option;
	cout << "CHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: " << endl;
	cout << endl;
	cout << "\tRESERVING A SEAT (1)" << endl;
	cout << "\tCANCELLING A RESERVATION (2)" << endl;
	cout << "\tVIEWING THE AVAILABILITY OF SEATS (3)" << endl;
	cout << "ENTER YOUR OPTION: ";
	cin >> option;
//
	if (option == 1)
	{
		bool error = true;
//
		while (error != false)
		{
//				system("cls");
			cout << "CHOOSE YOUR BUS NUMBER FROM AMONG THE FOLLOWING BUSES: " << endl << endl;
			for (int i = 0; i < 15; i++)
			{
				cout << "BUS NUMBER: " << obj2.busVector[i].BusNumber << endl;
//
			}
//
			int busno;
			cout << "Enter your bus number: ";
			cin >> busno;
//
			bool busfound = false;
//
			bool error2 = true;
			for (int i = 0; i < bus::buscount; i++)
			{
//
				if (busno == obj2.busVector[i].BusNumber)
				{
					while (error2 != false)
					{
//							system("cls");
						busfound = true;
						int seatno;
						cout << "PLEASE ENTER YOUR SEAT NUMBER: " << endl;
						cout << "CHOOSE AMONG THE AVAILABLE SEATS FROM THE BUS: ";
//
						cout << endl;
//							obj2.busVector[i].display();
//
						cout << "ENTER YOUR SEAT : ";
						cin >> seatno;
//
						if (seatno < 1 || seatno >20)
						{
//							
							error = true;
							error2 = true;
							cout << "YOU ENTERED AN INVALID SEAT NUMBER" << endl;
							cout << "PLEASE CHOOSE A VALID SEAT NUMBER"<<endl;
//								system("pause");
						}
//
						else
						{
							error = false;
							error2 = false;
//								system("cls");
//								obj2.busVector[i].reserveSeat(seatno);
//								obj2.busVector[i].display();
						}
					}
				}
			}
//
			if (busfound == false)
			{
				cout << "BUS WITH SUCH NUMBER DOES NOT EXISTS. PLEASE CHOOSE A VALID BUS!" << endl;
//					
			}
//				system("pause");
		}
//
//			system("cls");
		int mainoption;
		cout << "DO YOU WANT TO EXIT THE PROGRAM? "<<endl;
		cout << "\tENTER (0) TO CONTINUE"<<endl;
		cout << "\tENTER (1) TO EXIT"<<endl;
		cout << "ENTER YOUR OPTION: ";
//
		cin >> mainoption;
//		
		if (mainoption == 1)
			endprogram = true;
//				
	}
//
	else if (option == 2)
	{
		bool error = true;
//
		while (error != false)
		{
//				system("cls");
			cout << "CHOOSE YOUR BUS NUMBER FROM AMONG THE FOLLOWING BUSES: " << endl << endl;
			for (int i = 0; i < 15; i++)
			{
				cout << "BUS NUMBER: " << obj2.busVector[i].BusNumber << endl;
//
			}
//
			int busno;
			cout << "Enter your bus number: ";
			cin >> busno;
//
			bool busfound = false;
//
			bool error2 = true;
			for (int i = 0; i < bus::buscount; i++)
			{
//
				if (busno == obj2.busVector[i].BusNumber)
				{
					while (error2 != false)
					{
//							system("cls");
						busfound = true;
						int seatno;
						cout << "PLEASE ENTER YOUR SEAT NUMBER: " << endl;
						cout << "CHOOSE AMONG THE AVAILABLE SEATS FROM THE BUS: ";
//
						cout << endl;
//							obj2.busVector[i].display();
//
						cout << "ENTER YOUR SEAT : ";
						cin >> seatno;
//
						if (seatno < 1 || seatno >20)
						{
							error = true;
							error2 = true;
							cout << "YOU ENTERED AN INVALID SEAT NUMBER" << endl;
							cout << "PLEASE CHOOSE A VALID SEAT NUMBER";
//								system("pause");
						}
//
						else
						{
							error = false;
							error2 = false;
//								system("cls");
//								obj2.busVector[i].cancelSeat(seatno);
//								obj2.busVector[i].display();
//								system("pause");
						}
					}
				}
			}
//
			if (busfound == false)
			{
				cout << "BUS WITH SUCH NUMBER DOES NOT EXISTS. PLEASE CHOOSE A VALID BUS!" << endl;
//					system("pause");
			}
//
		}
//
//			system("cls");
//			
		int mainoption;
		cout << "DO YOU WANT TO EXIT THE PROGRAM? " << endl;
		cout << "\tENTER (0) TO CONTINUE" << endl;
		cout << "\tENTER (1) TO EXIT"<<endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> mainoption;
//
		if (mainoption == 1)
			endprogram = true;
//
//			system("pause");
	}
//
	else if(option == 3)
	{
		bool error = true;
//
		while (error != false)
		{
//				system("cls");
			cout << "CHOOSE YOUR BUS NUMBER FROM AMONG THE FOLLOWING BUSES TO CHECK THE CORRESPONDING SEAT AVAILABLITY: " << endl << endl;
			for (int i = 0; i < 15; i++)
			{
				cout << "BUS NUMBER: " << obj2.busVector[i].BusNumber << endl;
//
			}
//
			int busno;
			cout << "Enter the bus number: ";
			cin >> busno;
//
			bool busfound = false;
//
			bool error2 = true;
			for (int i = 0; i < bus::buscount; i++)
			{
				if (busno == obj2.busVector[i].BusNumber)
				{
					busfound = true;
					int seatno;
					cout << "FOLLOWING ARE THE AVAILABLE SEATS FROM THE BUS : ";
//
					cout << endl;
//						obj2.busVector[i].display();
//						system("pause");
					error = false;
				}
			}
//
			if (busfound == false)
			{
				cout << "BUS WITH SUCH NUMBER DOES NOT EXISTS. PLEASE CHOOSE A VALID BUS!" << endl;
//					system("pause");
			}
//
		}
//
//			system("cls");
		int mainoption;
		cout << "DO YOU WANT TO EXIT THE PROGRAM? " << endl;
		cout << "\tENTER (0) TO CONTINUE" << endl;
		cout << "\tENTER (1) TO EXIT"<<endl;
		cout << "ENTER YOUR OPTION: ";
//
		cin >> mainoption;
//
		if (mainoption == 1)
			endprogram = true;
//			system("pause");
	}
//
	else
	{
	cout << "YOU ENTERED AN INVALID OPTION. CHOOSE AGAIN! "<<endl;
//		system("pause");
	}
//
}
return 0;
}
