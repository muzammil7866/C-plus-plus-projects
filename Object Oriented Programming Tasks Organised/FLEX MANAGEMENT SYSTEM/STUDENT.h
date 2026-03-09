//RELEVANT HEADER FILES AND LIBRARIES ATTACHED 
#include<string>
#include <iostream>
#include<iomanip>
#define STUDENT_H

using namespace std;

class Student
{
public:
	//CLASS ATTENDANCE PART OF THE STUDENT CLASS
	class Attendance
	{
	public:
		//FOR 5 WORKING DAYS ATTENDANCE OF THE STUDENT
		bool day[5];

		//CONSTRUCTOR TO INITIALISE
		Attendance()
		{
			for (int i = 0; i < 5; i++)
				day[i] = 0;
		}

		//ATTENDANCE SETTER
		void setAttendance(bool a, bool b, bool c, bool d, bool e)
		{
			day[0] = a;
			day[1] = b;
			day[2] = c;
			day[3] = d;
			day[4] = e;
		}

		//SET ATTENDANCE BY INPUT
		void setAttendance(Student& a)
		{
			string days[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

			for (int i = 0; i < 5; i++)
			{
				cout << "\tEnter (1) if the " << a.firstName << " " << a.lastName << " was present on " << days[i] << ", otherwise enter (0): ";
				cin >> a.attendance.day[i];
			}
			cout <<"\n"<< endl;
		}

		//DISPLAY ATTENDANCE
		void displayAttendance(Student& a)
		{
			string week[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
			cout << "\n\t\t-------------------------------------------";
			cout << "\n\t\t"<<a.firstName<<" "<<a.lastName<<"'s ATTENDANCE RECORD FOR LAST WEEK";
			cout << "\n\t\t-------------------------------------------\n\n";
			for (int i = 0; i < 5; i++)
			{
				cout << "\t" << setw(10) << left << week[i] << ": ";
				if (day[i] == 0)
					cout << setw(10) << "ABSENT";
				else
					cout << setw(10) << "PRESENT";
				cout << endl;
			}
		}
	};

	//	//CLASS OF STUDENT ID
	class StudentID
	{
	public:
		//22
		int year;
		//F
		char city;
		//3110
		int rollNo;

		//CONSTURCTOR
		StudentID()
		{
			year = 00;
			city = '\0';
			rollNo = 0000;
		}

		//SETTER OF STUDENT ID
		void setID(int a, char b, int c)
		{
			year = a;
			city = b;
			rollNo = c;
			totalStudents++;
		}

		//DISPLAY STUDENT ID
		void displayStudentID()
		{
			cout << "YOUR STUDENT ID IS: ";
			cout << year << city << "-" << rollNo << "\n";
		}
	};


	//CLASS OF REGISTERED COURSES
	class registeredCourses
	{
	public:
		int noOfcourses = 3;
		string* courseArr = new string[noOfcourses];

		registeredCourses()
		{
			for (int i = 0; i < noOfcourses; i++)
			{
				courseArr[i] = '\0';
			}
		}

		void editCourses()
		{
			for (int i = 0; i < noOfcourses; i++)
			{
				cout << "ENTER THE NAME OF THE COURSE " << i + 1 << ": ";
				cin >> courseArr[i];
			}
		}
		void viewCourse()
		{
			for (int i = 0; i < noOfcourses; i++)
			{
				cout << "NAME OF THE COURSE " << i + 1 << ": " << courseArr[i] << endl;
			}
		}
		void assignGrades(char temp)
		{
			for (int i = 0; i < noOfcourses; i++)
			{
				cout << "ENTER THE GRADE OF THE " << i + 1 << " COURSE: "; courseArr[i] = temp;
			}
		}
		void showGrades()
		{
			for (int i = 0; i < noOfcourses; i++)
			{
				cout << "GRADE OF THE " << i + 1 << " COURSE IS: " << courseArr[i] << endl;
			}
		}
		friend void viewGrades(registeredCourses& rc);
		friend void viewRegisteredcourses(registeredCourses& rc);
	};


	//STUDENT CLASS MEMBERS
	string firstName;
	string lastName;
	string department;
	bool gender;
	string contactNo;
	string bloodGroup;
	string address;
	bool feeStatus;
	string qualification;
	int marks;
	char grade;
	string username;
	string password;
	StudentID obj;
	static int totalStudents;
	Attendance attendance;
	registeredCourses regCourses;

	//STUDENT CONSTRUCTOR TO INITIALISE
	Student()
	{
		firstName = "";
		lastName = "";
		department = "";
		gender = 0;
		contactNo = "";
		bloodGroup = "";
		address = "";
		feeStatus = 0;
		qualification = "";
		marks = 0;
		username = "";
		grade = '\0';
		password = "";
	}

	//SETTER OF STUDENT
	void setStudent(string a, string b, string c, bool d, string e, string f, string g, bool h, string i, int j, string k, string l)
	{
		firstName = a;
		lastName = b;
		department = c;
		gender = d;
		contactNo = e;
		bloodGroup = f;
		address = g;
		feeStatus = h;
		qualification = i;
		marks = j;
		username = k;
		password = l;
		obj.setID((17 + rand() % 5), 'F', (1000 + rand() % 4000 + 1));

	}

	//DISPLAYS STUDENT
	void getStudentData()
	{
		cout << "\n\t\t\t     STUDENT USERNAME: " << username << "\n\t\t\t     STUDENT PASSWORD: " << password;
		cout << "\n\n\tNAME: " << firstName << " " << lastName << "\n\tDEPARTMENT: " << department << "\n\tGENDER: ";
		if (gender == 0)
			cout << "Female";
		else
			cout << "Male";
		cout << "\n\tCONTACT NO: " << contactNo << "\n\tBLOOD GROUP: " << bloodGroup << "\n\tADDRESS: " << address << "\n\tFEE STATUS: ";
		if (feeStatus == 0)
			cout << "NOT PAID YET";
		else
			cout << "PAID";
		cout << "\n\tQUALIFICATION: " << qualification << "\n\tMARKS: " << marks << "\n";
	}

	//DISPLAYS SIGN IN MENU
	void signIn()
	{
		system("cls");
		cout << "*************************STUDENTS SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\t ENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\t ENTER YOUR PASSWORD: ";
		cin >> password;
	}

	//VIEWS ATTENDANCE OF STUDENT
	void viewAttendance()
	{

	}

	//VIEWS MARKS OF STUDENT
	void viewMarks()
	{

	}

	//VIEWS GRADES OF STUDENT
	void viewGrades()
	{

	}

	//VIEWS REGISTERED COURSES OF STUDENT
	void viewRegisteredCourses()
	{
		system("cls");
		regCourses.editCourses();
		regCourses.viewCourse();
	}

	//VIEWS FEE STATUS OF STUDENT
	void viewFeeStatus()
	{

	}
};
