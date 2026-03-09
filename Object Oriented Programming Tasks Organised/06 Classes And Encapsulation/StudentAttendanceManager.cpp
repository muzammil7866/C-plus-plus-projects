#include <iostream>
#include<string>
#include<string.h>
#include<cstring>
#include<iomanip>
using namespace std;
class student
{
public:
	string name;
	int rollno;
	int attendance;

	student()
	{
		name = "\0";
		rollno = 0;
		attendance = 0;
	}

	student(string a, int b)
	{
		name = a;
		rollno = b;
	}

	~student()
	{
		name = "\0";
		rollno = 0;
	}

	void display()
	{
		cout<<endl<< "THIS STUDENT DETAILS: " << endl<<endl;
		cout << "NAME: " << name << endl;
		cout << "ROLL NUMBER: " << rollno << endl;
		system("pause");
	}

	static void getAverageAttendance(student students[], int numStudents)
	{
		int avgAttendance = 0;
		for (int i = 0; i < numStudents; i++)
		{
			avgAttendance = avgAttendance + (*(students + i)).getAttendance();
		}

		avgAttendance = avgAttendance / numStudents;
		cout << "AVERAGE ATTENDANCE OF THE CLASS: " << avgAttendance<<endl;
	}
	int getAttendance()
	{
		return (*this).attendance;
	}
	void markAttendance()
	{
		(*this).attendance++;
	}

	
	void printReport(int total)
	{
		cout << "STUDENT NAME: " << (*this).name<<endl;
		cout << "STUDENT ROLL NUMBER: " << (*this).rollno<< endl;
		int attendance_per = ((*this).getAttendance() *100)/total;
		cout <<"STUDENT'S ATTENDANCE : " << setprecision(4)<<(attendance_per)<<" %"<< endl;
	}
	void initialise()
	{
		cout << "ENTER THE STUDENT'S NAME: ";
		cin >> name;
		cout << "ENTER THE STUDENT'S ROLL NUMBER: ";
		cin >> rollno;
	}
	void validity(student& a)
	{
		int count = 0;
		bool incorrect = false;
		bool incorrect2 = false;
		while (count < name.length())
		{
			if ((name[count] >= 'A' && name[count] <= 'Z') || (name[count] >= 'a' && name[count] <= 'z') || (name[count] == 32))
			{
				incorrect = false;
			}
			else 
			{
				incorrect = true;
				cout << "INVALID NAME. ENTER AGAIN!"<<endl;
				break;
			}
			count++;
		}

		if (rollno > 0)
		{
			incorrect2 = false;
		}
		else
		{
			incorrect2 = true;
			cout << "INVALID ROLL NUMBER. ENTER AGAIN!"<<endl;
		}

		if (incorrect || incorrect2)
		{
			a.~student();
		}
		else
		{
			cout << "NAME AND ROLL NUMBER VALIDITY CHECKED! :)"<<endl;
		}
		

	}
};

int main()
{
	system("Color B0");
	
	/*student obj1;
	do
	{
		obj1.initialise();
		obj1.validity(obj1);
		cin.ignore();
	
	} while (obj1.rollno == 0);
	
	obj1.display();
	int num;
	cout << "ENTER THE NUMBER OF PRESENT DAYS OF THIS STUDENT: ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		obj1.markAttendance();
	}
	int total = 0;
	cout << "ENTER THE TOTAL CLASS DAYS: ";
	cin >> total;
	obj1.printReport(total);
	
	int size = 0;
	cout << "ENTER THE SIZE OF YOUR CLASS: ";
	cin >> size;
	student* ptr = new student[size];
	(*ptr).getAverageAttendance(ptr, size);

	cout << student::attendance;
	*/

	int size;
	cout << "ENTER THE NUMBER OF STUDENTS IN YOUR CLASS: ";
	cin >> size;

	student* ptr = new student[size];

	for (int i = 0; i < size; i++)
	{
		
		ptr[i].initialise();
		ptr[i].validity(ptr[i]);
		ptr[i].display();
		system("cls");
	}

	for (int i = 0; i < size; i++)
	{
		int markoption;
		for (int j = 0; j < 5; j++)
		{
			cout <<endl<< "ENTER (1) IF '"<<ptr[i].name<<"' WAS PRESENT ON DAY " << j + 1 << " OF THE WEEK, ";
			cout << "OTHERWISE PRESS (0)" << endl;
			cout << "\tYOUR ENTRY HERE: ";
			cin >> markoption;

			if (markoption == 1)
			{
				ptr[i].markAttendance();
			}
		}

		cout <<endl<< "ATTENDANCE OF " << ptr[i].name << " IS " << ptr[i].getAttendance()<<" OUT OF 5 DAYS." << endl;
	}
	cout << endl;
	ptr[0].getAverageAttendance(ptr, size);


	return 0;
}
