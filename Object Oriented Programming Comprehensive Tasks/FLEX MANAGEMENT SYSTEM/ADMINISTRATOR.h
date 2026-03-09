//RELEVANT HEADER FILES AND LIBRARIES ATTACHED 
#include<string>
#include <iostream>
#include<iomanip>
#define ADMINISTRATION_H
using namespace std;

class Administrator : public HOD, public Student, public Teacher
{
public:
	string username;
	string password;
	static int totalAdmins;

	Administrator()
	{
		username = "";
		password = "";

	}

	void signIn()
	{
		system("cls");
		cout << "*************************ADMINISTRATION OFFICE SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\t ENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\t ENTER YOUR PASSWORD: ";
		cin >> password;
	}

	Teacher addNewTeacher()
	{
		Teacher newTeacher;
		newTeacher.setTeacher("Jamshed", "Bhatti", "Software Engineering");
		newTeacher.timeTable.setTimeTable(newTeacher);
		return newTeacher;

	}


	/*void inputTeacherDetails(Teacher& newTeacher)
	{
		cout << endl << endl << "***************ENTER TEACHER DETAILS***************" << endl << endl;

		cout << "ENTER THE FIRST NAME OF THE TEACHER: ";
		cin >> newTeacher.firstName;
		cout << "ENTER THE LAST NAME OF THE TEACHER: ";
		cin >> newTeacher.lastName;
		cout << "ENTER THE DEPARTMENT OF THE TEACHER: ";
		cin >> newTeacher.department;
		cout << "ENTER THE CONTACT NUMBER OF THE TEACHER: ";
		cin >> newTeacher.contactNo;
		cout << "ENTER THE RESIDENTIAL ADDRESS OF THE TEACHER: ";
		cin >> newTeacher.address;
		newTeacher.timeTable.setTimeTable(newTeacher);
	}*/

	void signUp()
	{
		cout << "ENTER THE TEACHER ID OF THE NEW TEACHER: ";
		cin >> username;
		cout << "ENTER THE PASSWORD FOR THE NEW TEACHER";
		cin >> password;
	}

	void addNewStudent()
	{

	}

	void editStudent(Student& student)
	{

	}

	void editTeacher(Teacher& teacher)
	{

	}

	void viewAllStudents()
	{

	}

	void viewAllTeachers()
	{

	}
};
