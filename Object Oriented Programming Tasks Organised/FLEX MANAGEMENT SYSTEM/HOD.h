//RELEVANT HEADER FILES AND LIBRARIES ATTACHED 
#include<string>
#include <iostream>
#include<iomanip>
#define STUDENT_H
using namespace std;

class HOD : public Teacher, public Student
{
public:

	string firstName;
	string lastName;
	string department;
	string username;
	string password;
	static int totalHODS;
	Teacher* obj;

	HOD()
	{
		firstName = "";
		lastName = "";
		department = "";
		username = "";
		password = "";
		obj = NULL;
	}

	void setHOD(string a, string b, string c)
	{
		firstName = a;
		lastName = b;
		department = c;
	}


	void addTeachersFunctionality(Teacher*& a)
	{
		obj = &a[totalTeachers];
	}

	void signIn()
	{
		system("cls");
		cout << "*************************HEAD OF DEPARTMENT (HOD) SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\t ENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\t ENTER YOUR PASSWORD: ";
		cin >> password;
	}

	void viewTeacherActivity(Teacher obj)
	{
		//views that teacher details

	}

	void viewStudentModule(Student obj)
	{
		//views and manipulates the contents of the student obj passed
	}

	void viewAllStudents(Student* a)
	{

		cout << "\n\n\t\t\t     TOTAL NUMBER OF PRESENT ENROLLED STUDENTS: " << totalStudents << endl << endl;


		for (int i = 0; i < totalStudents; i++)
		{
			cout << "------------------------------------------------------------------------------------------------------\n";
			a[i].getStudentData();
			cout << "------------------------------------------------------------------------------------------------------\n";

		}

	}

	void viewAllTeachers(Teacher* a)
	{
		cout << "\n\n\t\t\t     TOTAL NUMBER OF CURRENT FACULTY: " << totalTeachers << endl << endl;


		for (int i = 0; i < totalTeachers; i++)
		{
			cout << "------------------------------------------------------------------------------------------------------\n";
			a[i].getTeacherData();
			cout << "------------------------------------------------------------------------------------------------------\n";

		}

	}


};
