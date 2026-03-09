#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

class Vehicle
{
public:

	string make;
	string model;
	int year;
	double rentalFee;
	

	Vehicle()
	{
		make = "";
		model = "";
		year = 0000;
		rentalFee = 0;
	}

	Vehicle(string a, string b, int c, double d)
	{
		make = a;
		model = b;
		year = c;
		rentalFee = d; 
	}

	void displayVehicleDetails()
	{
		
		cout <<setw(10)<< "\nMAKE OF THE VEHICLE: "<< make<<endl;
		cout << setw(10) << "MODEL OF THE VEHICLE: " << model << endl;
		cout << setw(10) << "YEAR OF THE VEHICLE: " << year << endl;
		cout << setw(10) << "PER DAY COST OF THE VEHICLE: " << rentalFee << endl;
	

	}

	void calculateRentalFee() //overridden later
	{

	}

	~Vehicle() //destructor
	{
		make = "";
		model = "";
		year = 0000;
		rentalFee = 0;
	}
};

class Sedan: public Vehicle
{
	public:

	int numDoors;

	Sedan()
	{
		numDoors = 0;
	}

	Sedan(string a, string b, int c, double d, int e)
	{
		make = a;
		model = b;
		year = c;
		rentalFee = d;
		numDoors = e;
	}

	void displaySedanDetails()
	{
		displayVehicleDetails();
		cout << "NUMBER OF DOORS: " << numDoors << endl;
	}

	double calculateRentalFee() //overridden here
	{
		rentalFee = 30000;
		return rentalFee;
	}

	~Sedan()
	{
		numDoors = 0;
	}


};

class SUV : public Vehicle
{
public:

	SUV()
	{
		numDoors = 0;
	}

	SUV(string a, string b, int c, double d, int e)
	{
		make = a;
		model = b;
		year = c;
		rentalFee = d;
		numDoors = e;
	}

	int numDoors;

	void displaySUVDetails()
	{
		displayVehicleDetails();
		cout << "NUMBER OF DOORS: " << numDoors<<endl;
	}

	double calculateRentalFee() //overridden here
	{
		
		rentalFee = 53000;
		return rentalFee;
	}

	~SUV()
	{
		numDoors = 0;
	}
};

class SportsCar : public Vehicle
{
public:

	int numDoors;

	SportsCar()
	{
		numDoors = 0;
	}

	SportsCar(string a, string b, int c, double d, int e)
	{
		make = a;
		model = b;
		year = c;
		rentalFee = d;
		numDoors = e;
	}

	void displaySportsCarDetails()
	{
		displayVehicleDetails();
		cout << "NUMBER OF DOORS: " << numDoors << endl;
	}

	double calculateRentalFee() //overridden here
	{
		
		rentalFee = 61000;
		return rentalFee;
	}

	~SportsCar()
	{
		numDoors = 0;
	}
};

class RentalSystem
{
public:

	string customerName;
	int rentalDays;
	int additionalCharges;
	int totalFee;
	Vehicle* vehicle; 

	RentalSystem()
	{
		customerName = "";
		rentalDays = 0;
		additionalCharges = 0;
		totalFee = 0;
		vehicle = NULL;
	}

	RentalSystem(string a, int b, int c, int d, Vehicle& e)
	{
		customerName = a;
		rentalDays = b;
		additionalCharges = c;
		totalFee = d;
		vehicle = &e;
	}


	void bookVehicle(Vehicle* vehicle)
	{
		this->vehicle = vehicle;

		cout << "\tENTER THE NUMBER OF DAYS YOU WANT TO RENT THE CAR: ";
		cin >> rentalDays;



	}

	void returnVehicle(Vehicle* b, int a)
	{
		additionalCharges = a;
		totalFee = (b->rentalFee * rentalDays) + additionalCharges; 
	}

	void displayRentalDetails(Vehicle* vehicle)
	{
		cout << "CUSTOMER NAME: " << customerName;
		cout << "\nRENTAL DAYS: " << rentalDays;
		vehicle->displayVehicleDetails();
		cout << "TOTAL FEE: " << (vehicle->rentalFee * rentalDays) + additionalCharges <<" PKR"<< endl;
	}

	~RentalSystem()
	{
		customerName = "";
		rentalDays = 0;
		additionalCharges = 0;
		totalFee = 0;
		vehicle = NULL;
	}



};
int main()
{
	Sedan sedan("Toyota", "Avalon", 2021, 30000, 4);

	SUV suv("Hyundai", "Tuckson", 2022, 53000, 4);

	SportsCar sportsCar("Volkswagen", "GTI", 2023, 61000, 2);

	//for returning of the car as assuming that a person has already rented a car
	Vehicle vehicle("Toyota", "Avalon", 2019, 26000);

	RentalSystem rentalSystem("Kashif Jafar", 9, 3200, 67000, vehicle);
	bool endProgram = false;

	while (endProgram != true)
	{
		system("cls");
	cout << "\n\tCAR RENTAL MANAGEMENT SYSTEM\n\n\n";

	cout << "CHOOSE FROM THE FOLLOWING OPTIONS: \n\n";
	cout << "\tENTER (1) FOR BOOKING THE CAR\n";
	cout << "\tENTER (2) FOR RETURNING THE CAR\n";
	cout << "\tENTER (3) TO EXIT THE PROGRAM\n";
	int option;
	cout << "\n\n\t\tENTER HERE: ";
	cin >> option;

	
		if (option == 1)
		{
			int subOption = 0;

			system("cls");
			cout << "CHOOSE FROM THE FOLLOWING OPTIONS: \n\n";
			cout << "\tENTER (1) FOR BOOKING A SEDAN\n";
			cout << "\tENTER (2) FOR BOOKING A SUV\n";
			cout << "\tENTER (3) FOR BOOKING A SPORTS CAR\n";
			cout << "\n\n\t\tENTER HERE: ";

			cin >> subOption;

			

			if (subOption == 1)
			{
				system("cls");
				cout << "------------------------------------------------------\n";
				cout << "\t\tVEHICLE DETAILS\n";
				cout << "------------------------------------------------------";
				sedan.displaySedanDetails();

				int booking;
				cout << "\n\tSHALL THE BOOKING BE CONFIRMED (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
				cin >> booking;

				if (booking == 0)
				{
					system("cls");
					int endSystem;
					cout << "DO YOU WISH TO END THE SYSTEM (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
					cin >> endSystem;

					if (endSystem == 1)
					{
						endProgram = true;
					}

					else
					{
						endProgram = false;
					}


				}

				else if (booking == 1)
				{
					RentalSystem rentalSystem2;
					system("cls");
					cout << "\n\tENTER YOUR FULL NAME: ";
					cin.ignore();
					getline(cin, rentalSystem2.customerName);

					rentalSystem2.bookVehicle(&sedan);

					system("cls");
					cout << "\nCONGRATULATIONS YOUR BOOKING HAS BEEN MADE! :)\n\n";


					rentalSystem2.displayRentalDetails(rentalSystem2.vehicle);
					cout << endl;
					system("pause");
					
					system("cls");
					int endSystem;
					cout << "DO YOU WISH TO END THE SYSTEM (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
					cin >> endSystem;

					if (endSystem == 1)
					{
						endProgram = true;
					}

					else
					{
						endProgram = false;
					}
				}


			}

			else if (subOption == 2)
			{
				system("cls");
				cout << "------------------------------------------------------\n";
				cout << "\t\tVEHICLE DETAILS\n";
				cout << "------------------------------------------------------";
				suv.displaySUVDetails();

				int booking;
				cout << "\n\tSHALL THE BOOKING BE CONFIRMED (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
				cin >> booking;

				if (booking == 0)
				{
					system("cls");
					int endSystem;
					cout << "DO YOU WISH TO END THE SYSTEM (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
					cin >> endSystem;

					if (endSystem == 1)
					{
						endProgram = true;
					}

					else
					{
						endProgram = false;
					}

				}

				else if (booking == 1)
				{
					RentalSystem rentalSystem2;
					system("cls");
					cout << "\n\tENTER YOUR FULL NAME: ";
					cin.ignore();
					getline(cin, rentalSystem2.customerName);

					rentalSystem2.bookVehicle(&suv);

					system("cls");
					cout << "\nCONGRATULATIONS YOUR BOOKING HAS BEEN MADE! :)\n\n";

					rentalSystem2.displayRentalDetails(rentalSystem2.vehicle);
					cout << endl;
					system("pause");

					system("cls");
					int endSystem;
					cout << "DO YOU WISH TO END THE SYSTEM (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
					cin >> endSystem;

					if (endSystem == 1)
					{
						endProgram = true;
					}

					else
					{
						endProgram = false;
					}
				}

			}

			else if (subOption == 3)
			{
				system("cls");
				cout << "------------------------------------------------------\n";
				cout << "\t\tVEHICLE DETAILS\n";
				cout << "------------------------------------------------------";
				sportsCar.displaySportsCarDetails();

				int booking;
				cout << "\n\tSHALL THE BOOKING BE CONFIRMED (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
				cin >> booking;

				if (booking == 0)
				{
					system("cls");
					int endSystem;
					cout << "DO YOU WISH TO END THE SYSTEM (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
					cin >> endSystem;

					if (endSystem == 1)
					{
						endProgram = true;
					}

					else
					{
						endProgram = false;
					}


				}

				else if (booking == 1)
				{
					RentalSystem rentalSystem2;
					system("cls");
					cout << "\n\tENTER YOUR FULL NAME: ";
					cin.ignore();
					getline(cin, rentalSystem2.customerName);

					rentalSystem2.bookVehicle(&sportsCar);

					system("cls");
					cout << "\nCONGRATULATIONS YOUR BOOKING HAS BEEN MADE! :)\n\n";

					rentalSystem2.displayRentalDetails(rentalSystem2.vehicle);
					cout << endl;
					system("pause");

					system("cls");
					int endSystem;
					cout << "DO YOU WISH TO END THE SYSTEM (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
					cin >> endSystem;

					if (endSystem == 1)
					{
						endProgram = true;
					}

					else
					{
						endProgram = false;
					}



				}

			}

			else
			{

			}
		}

		else if (option == 2)
		{
			system("cls");
			cout << "THANK YOU FOR USING THE RENTAL SERVICE!\n\n";
			cout << "\t\tHERE ARE YOUR DETAILS:\n\n";

			rentalSystem.returnVehicle(&vehicle, 15000);

			rentalSystem.displayRentalDetails(rentalSystem.vehicle);
			cout << endl;
			system("pause");

			system("cls");
			int endSystem;
			cout << "DO YOU WISH TO END THE SYSTEM (ENTER 1 FOR YES/ ENTER 0 FOR NO): ";
			cin >> endSystem;

			if (endSystem == 1)
			{
				endProgram = true;
			}

			else
			{
				endProgram = false;
			}
		}

		else if (option == 3)
		{
			cout<<"INVALID ENTRY, ENTER AGAIN! " << endl;
			system("pause");
			endProgram = true;
		}

		else 
		{
			cout << "\nINVALID ENTRY, ENTER AGAIN! " << endl;
			system("pause");
		}
	}



	return 0;	
}
