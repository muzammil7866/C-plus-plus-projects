#include<iostream>
using namespace std;
class Date
{
	int month;
	int day;
	int year;

public:
	void longdate()
	{
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;
		bool display = true;

		

		if (day > 31 || day < 1)
		{
			cout << "Invalid Entry for the day" << endl;
			display = false;
		}
		string month2;

		switch (month)
		{
		case 1:
			month2 = "January";
			break;
		case 2:
			month2 = "February";
			break;
		case 3:
			month2 = "March";
			break;
		case 4:
			month2 = "April";
			break;
		case 5:
			month2 = "May";
			break;
		case 6:
			month2 = "June";
			break;
		case 7:
			month2 = "July";
			break;
		case 8:
			month2 = "August";
			break;
		case 9:
			month2 = "September";
			break;
		case 10:
			month2 = "October";
			break;
		case 11:
			month2 = "November";
			break;
		case 12:
			month2 = "December";
			break;
		default:
			cout << "Entered month is invalid!" << endl;
			display = false;
		}
		if (display == true)
		cout << day << " " << month2 << ", " << year;
	}
	void shortdate()
	{
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;
		bool display = true;
		if (month < 1 || month >12)
		{
			cout << "Invalid Entry for the month" << endl;
			display = false;
		}
		if (day > 31 || day < 1)
		{
			cout << "Invalid Entry for the day" << endl;
			display = false;
		}

		cout << day << "/" << month << "/" << year;
	}
	void longdate2()
	{
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;
		string month2;
		bool display = true;

		if (month < 1 || month >12)
		{
			cout << "Invalid Entry for the month" << endl;
			display = false;
		}
		switch (month)
		{
		case 1:
			month2 = "January";
			break;
		case 2:
			month2 = "February";
			break;
		case 3:
			month2 = "March";
			break;
		case 4:
			month2 = "April";
			break;
		case 5:
			month2 = "May";
			break;
		case 6:
			month2 = "June";
			break;
		case 7:
			month2 = "July";
			break;
		case 8:
			month2 = "August";
			break;
		case 9:
			month2 = "September";
			break;
		case 10:
			month2 = "October";
			break;
		case 11:
			month2 = "November";
			break;
		case 12:
			month2 = "December";
			break;
		default:
			cout << "Entered month is invalid!" << endl;
			display = false;
		}
		if(display == true)
		cout << month2 << " " << day << ", " << year;
	}


};
int main()
{
	Date obj1;
	obj1.longdate();
	cout << endl;
	obj1.shortdate();
	cout << endl;
	obj1.longdate2();
	cout << endl;



	return 0;
}