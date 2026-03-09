#include<iostream>
#include"classes.h"
#include<string>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

Student::Student()
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
	regDate = "";
	grade = '\0';
	password = "";
}

Student::Student(string a, string b, string c, bool d, string e, string f, string g, bool h, string i, int j, string k, string l)
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
	obj.setID(23, 'F', totalStudents + 3000);

}

void Student::getStudentData()
{
	cout << endl;
	cout << setw(11) << obj.year << obj.city << "-" << obj.rollNo;
	cout << setw(18) << firstName;
	cout << setw(18) << lastName;
	cout << setw(18) << username;
	cout << setw(18) << password;
	cout << setw(18) << department;
	cout << setw(18) << contactNo;

	if (feeStatus == 0)
	{
		cout << setw(18) << "NOT PAID";
	}

	else
	{
		cout << setw(18) << "PAID";
	}

	cout << endl;

}

void Student::printStudent()
{
	cout << "\n\t\t\t     STUDENT USERNAME: " << username << "\n\n\t\t\t     STUDENT PASSWORD: " << password;

	cout << "\n\n\tROLL NO: " << obj.year << obj.city << "-" << obj.rollNo;

	cout << "\n\n\tNAME: " << firstName << " " << lastName << "\n\n\tDEPARTMENT: " << department << "\n\n\tGENDER: ";

	if (gender == 0)
		cout << "Female";
	else
		cout << "Male";

	cout << "\n\n\tCONTACT NO: " << contactNo << "\n\n\tBLOOD GROUP: " << bloodGroup << "\n\n\tADDRESS: " << address << "\n\n\tFEE STATUS: ";

	if (feeStatus == 0)
		cout << "NOT PAID YET";
	else
		cout << "PAID";

	cout << "\n\n\tQUALIFICATION: " << qualification << "\n\n\tMARKS: " << marks << "\n";
}

void Student::writeToFile(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);
	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << firstName << endl;
		myOutput << lastName << endl;
		myOutput << department << endl;
		myOutput << gender << endl;
		myOutput << contactNo << endl;
		myOutput << bloodGroup << endl;
		myOutput << address << endl;
		myOutput << feeStatus << endl;
		myOutput << qualification << endl;
		myOutput << marks << endl;
		myOutput << username << endl;
		myOutput << password << endl;

	}

	myOutput.close();
}

string Student::signIn()
{
	system("cls");
	fstream myInput;

	string uCheck, pCheck;
	bool repeat = true;

	while (repeat != false)
	{
		system("cls");
		myInput.open("studentsUP.txt");

		cout << "*************************STUDENTS SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\tENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\n\tENTER YOUR PASSWORD: ";
		cin >> password;

		if (!(myInput.is_open()))
			cout << "FILE CANNOT BE OPENED! ";
		else
		{

			while (!myInput.eof())
			{
				getline(myInput, uCheck);
				getline(myInput, pCheck);

				if (username == uCheck && password == pCheck)
				{
					repeat = false;
					cout << "\nLOGGED IN SUCCESSFULLY! '" << uCheck << "' WELCOME! :)" << endl << endl;
					system("pause");
					return username;
				}
			}

			myInput.close();
			cout << endl;
			cout << "\tINVALID CREDENTIALS! " << endl << endl;

			int temp;
			cout << "\tGO BACK TO MAIN LOGIN PAGE? (0 FOR YES/1 FOR NO): ";
			cin >> temp;

			if (temp == 0)
			{
				return "null";
			}

			cout << endl;
		}
	}


}

int Student::getStudentInd(Student students[], string uN)
{
	for (int i = 0;i < totalStudents;i++)
	{
		if (students[i].username == uN)
		{
			return i;
		}
	}
}

void Student::viewAttendance(Student* student)
{
	student->attendance.displayAttendance(*student);
	cout << endl;

}

void Student::viewMarks(Student* student)
{
	cout << "\nMARKS: ";
	cout << student->marks << endl << endl;
}

void Student::viewGrades(Student* student)
{
	cout << "\nGRADE: ";
	cout << student->grade << endl << endl;
}

void Student::viewRegisteredCourses()
{
	system("cls");
	cout << endl;
	regCourses.viewCourse();
}

void Student::viewFeeStatus(Student* students)
{
	cout << "\nFEE STATUS: ";
	if (students[0].feeStatus == 1)
		cout << "PAID";
	else
		cout << "NOT PAID";
	cout << endl << endl;
}

void Student::RegisteredCourses::addCourse()
{
	cin.ignore();

	for (int i = 0; i < noOfcourses; i++)
	{
		cout << "\n\tNAME OF COURSE " << i + 1 << ": ";
		getline(cin, courseArr[i]);
	}
}

void Student::RegisteredCourses::viewCourse()
{
	for (int i = 0; i < noOfcourses; i++)
	{
		cout << "COURSE " << i + 1 << ": " << courseArr[i] << endl << endl;
	}
}

void Student::RegisteredCourses::assignGrades()
{

	for (int i = 0; i < noOfcourses; i++)
	{
		cout << "GRADE FOR " << courseArr[i] << ": ";
		cin >> gradeArr[i];
	}
}

void Student::RegisteredCourses::showGrades()
{
	for (int i = 0; i < noOfcourses; i++)
	{
		cout << "GRADE FOR " << courseArr[i] << ": " << gradeArr[i];
	}
}

void Student::StudentID::setID(int y, char c, int r)
{
	year = y;
	city = c;
	rollNo = r;
}

void Student::StudentID::displayStudentID()
{
	cout << "YOUR STUDENT ID IS: ";
	cout << year << city << "-" << rollNo << "\n";
}

void Student::Attendance::setAttendance(bool a, bool b, bool c, bool d, bool e)
{
	day[0] = a;
	day[1] = b;
	day[2] = c;
	day[3] = d;
	day[4] = e;
}

void Student::Attendance::setAttendance(Student& a)
{
	string days[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

	for (int i = 0; i < 5; i++)
	{

		bool valid = false;

		cout << endl;

		while (valid != true)
		{
			system("cls");
			int temp;

			cout << "\tEnter (1) if the " << a.firstName << " " << a.lastName << " was present on " << days[i] << ", otherwise enter (0): ";

			cin >> temp;


			cout << endl;

			if (temp < 0 || temp > 1)
			{
				valid = false;
				cout << "\n\tINVALID INPUT! \n\n";
				system("pause");
			}

			else
			{
				valid = true;
				a.attendance.day[i] = temp;
			}
		}
	}
	cout << "\n" << endl;
}

void Student::Attendance::displayAttendance(Student& a)
{
	string week[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	cout << "\n\t\t-------------------------------------------";
	cout << "\n\t\t" << a.firstName << " " << a.lastName << "'s ATTENDANCE RECORD FOR LAST WEEK";
	cout << "\n\t\t-------------------------------------------\n\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "\t" << setw(10) << left << week[i] << ": ";
		if (day[i] == 0)
			cout << setw(10) << "ABSENT\n";
		else
			cout << setw(10) << "PRESENT\n";
		cout << endl;
	}
}

Teacher::Teacher()
{
	firstName = "";
	lastName = "";
	department = "";
	username = "";
	password = "";
	regDate = "";
	gender = 0;
	contactNo = "";
	qualification = "";
	address = "";
	salary = 0;
}

void Teacher::TimeTable::setTimeTable(string a, bool each[][3])
{

	courseTitle = a;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++)
			timeTable[i][j] = each[i][j];
}

void Teacher::TimeTable::setTimeTable(Teacher& newTeacher)
{
	cout << "\n\tENTER THE COURSE TITLE OFFERED TO THE TEACHER: ";
	cin >> newTeacher.timeTable.courseTitle;

	system("cls");
	cout << "\n\t\tSELECT THE WORKING DAYS FOR THE TEACHER!" << endl << endl;
	system("pause");

	for (int i = 0; i < 5; i++)
	{

		int thisOption = 0;
		string week[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

		bool valid = false;

		while (valid != true)
		{
			system("cls");
			cout << "\n\tENTER (1) IF YOU WANT TO APPOINT LECTURE FOR THE TEACHER ON " << week[i] << ", OTHERWISE ENTER (0) : ";
			cin >> thisOption;


			if (thisOption == 1)
			{
				valid = true;
				for (int j = 0; j < 3; j++)
				{
					bool valid2 = false;
					while (valid2 != true)
					{

						system("cls");

						cout << "\n\t\tSELECT THE TIME SLOTS FOR THE TEACHER ON : " << week[i] << endl;

						string times[3] = { "8 am - 9:30 am", "10 am - 11:30 am", "12 pm - 1:30 pm" };

						cout << "\n\tENTER (1) IF YOU WANT TO APPOINT TIME SLOT TO THE TEACHER ON " << times[j] << ", OTHERWISE ENTER (0) : ";
						cin >> newTeacher.timeTable.timeTable[i][j];

						if (newTeacher.timeTable.timeTable[i][j] < 0 || newTeacher.timeTable.timeTable[i][j]>1)
						{
							cout << "\n\tINVALID INPUT! \n\n";
							system("pause");
							valid2 = false;
						}
						else
						{

							valid2 = true;

						}
					}
				}
			}

			else if (thisOption == 0)
			{
				valid = true;
			}

			else if (thisOption < 0 || thisOption >1)
			{
				cout << "\n\tINVALID ENTRY!\n\n";
				system("pause");
				valid = false;
			}
		}
	}
}

void Teacher::TimeTable::displayTimeTable()
{
	system("cls");

	cout << "\n\t\t------------------------------------------------------------" << endl;
	cout << "\t\t                   TEACHER TIME TABLE                       " << endl;
	cout << "\t\t------------------------------------------------------------" << endl << endl;
	cout << "\n\tCOURSE ASSIGNED: " << courseTitle << "\n\n\n";

	string week[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	string time[3] = { "8 am - 9:30 am", "10 am - 11:30 am", "12 pm - 1:30 pm" };

	for (int i = 0; i < 5; i++)
	{
		cout << setw(12) << week[i] << "\t";
		for (int j = 0; j < 3; j++)
		{

			if (timeTable[i][j] == 1)
				cout << setw(7) << time[j] << "  \t";
		}
		cout << endl << "------------------------------------------------------------";
		cout << "\n\n";
	}

}

void Teacher::TeacherID::setteacherID(string a)
{
	string temp;
	temp = toupper(a[0]);
	department = department + temp;


	int index = 0;

	for (int i = 0;i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			index = i + 1;
			string temp;
			temp = toupper(a[index]);
			department = department + temp;

		}
	}

	teacherNo = getCount() + 1;
}

void Teacher::TeacherID::getTeacherID()
{
	cout << "YOUR TEACHER ID IS: ";
	cout << department << "-" << teacherNo << "\n";
}

void Teacher::setTeacher(string a, string b, string c)
{
	firstName = a;
	lastName = b;
	department = c;
	obj.setteacherID(c);
}

Teacher::TimeTable Teacher::getTT()
{
	return timeTable;
}

int Teacher::getTeacherInd(Teacher teachers[], string tempUser2)
{
	for (int i = 0;i < Teacher::getCount();i++)
	{
		if (teachers[i].username == tempUser2)
		{
			return i;
		}
	}
}

Teacher::Teacher(string a, string b, string c, string d, string e, string f, char g, string h, string i, string j, int k)
{
	firstName = a;
	lastName = b;
	department = c;
	username = d;
	password = e;
	regDate = f;
	gender = g;
	contactNo = h;
	qualification = i;
	address = j;
	salary = k;

	obj.setteacherID(c);
}

void Teacher::writeToFile(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);

	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << firstName << endl;
		myOutput << lastName << endl;
		myOutput << department << endl;
		myOutput << username << endl;
		myOutput << password << endl;
		myOutput << regDate << endl;
		myOutput << gender << endl;
		myOutput << contactNo << endl;
		myOutput << qualification << endl;
		myOutput << address << endl;
		myOutput << salary << endl;

	}
	myOutput.close();
}

void Teacher::getTeacherData() //passwords visible?
{
	cout << "\n\t\t\t     TEACHER USERNAME: " << username << "\n\n\t\t\t     TEACHER PASSWORD: " << password;
	cout << "\n\n\tNAME: " << firstName << " " << lastName << "\n\n\tDEPARTMENT: " << department << "\n\n\tREGISTRATION DATE: " << regDate << "\n\n\tGENDER: ";
	if (gender == 0)
		cout << "Female";
	else
		cout << "Male";
	cout << "\n\n\tCONTACT NO: " << contactNo << "\n\n\tQUALIFICATION: " << qualification;
	cout << "\n\n\tADDRESS: " << address << "\n\n\tSALARY: " << salary << "\n";
}

void Teacher::getTeacherData2()
{
	cout << endl;
	cout << setw(16) << obj.department << "-" << obj.teacherNo;
	cout << setw(18) << firstName;
	cout << setw(18) << lastName;
	cout << setw(18) << username;
	cout << setw(18) << password;
	cout << setw(18) << department;
	cout << setw(18) << contactNo;
	cout << setw(18) << salary;
	cout << endl;
}

string Teacher::signIn()
{
	system("cls");
	fstream myInput;

	string uCheck, pCheck;
	bool repeat = true;

	while (repeat != false)
	{
		system("cls");
		myInput.open("teachersUP.txt");

		cout << "*************************TEACHERS SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\tENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\n\tENTER YOUR PASSWORD: ";
		cin >> password;

		if (!(myInput.is_open()))
			cout << "FILE CANNOT BE OPENED! ";
		else
		{

			while (!myInput.eof())
			{
				getline(myInput, uCheck);
				getline(myInput, pCheck);

				if (username == uCheck && password == pCheck)
				{
					repeat = false;
					cout << "\nLOGGED IN SUCCESSFULLY! '" << uCheck << "' WELCOME! :)" << endl << endl;
					system("pause");
					return username;
				}
			}

			myInput.close();
			cout << endl;
			cout << "\tINVALID CREDENTIALS! " << endl << endl;
			int temp;
			cout << "\tGO BACK TO MAIN LOGIN PAGE? (0 FOR YES/1 FOR NO): ";
			cin >> temp;

			if (temp == 0)
			{
				return "null";
			}

			cout << endl;


		}
	}

}

void Teacher::markAttendance(Student& obj)
{
	system("cls");
	obj.attendance.setAttendance(obj);
}

void Teacher::assignMarks(Student& obj)
{
	bool valid = false;

	while (valid != true)
	{
		system("cls");

		cout << "\n\tENTER THE MARKS (OUT OF 100) OF " << obj.firstName << " " << obj.lastName << ": ";
		cin >> obj.marks;

		if (obj.marks < 0 || obj.marks > 100)
		{
			valid = false;
			cout << "\n\tINVALID INPUT\n\n";
			system("pause");
		}

		else
		{
			valid = true;
		}

		cout << endl;
	}
}

void Teacher::assignGrades(Student& obj)
{
	int perc = (obj.marks * 100) / 100;

	if (perc < 50)
		obj.grade = 'F';
	else if (perc >= 50 && perc <= 60)
		obj.grade = 'D';
	else if (perc >= 60 && perc <= 70)
		obj.grade = 'C';
	else if (perc >= 70 && perc <= 80)
		obj.grade = 'B';
	else if (perc >= 80 && perc <= 100)
		obj.grade = 'A';
}

void Teacher::assignGrade(Student& a)
{
	cout << "\nENTER THE GRADE YOU WANT TO ASSIGN TO " << a.firstName << " " << a.lastName << ": ";
	cin >> a.grade;

	cout << endl;
}

Administrator::Administrator(string a, string b, string u, string p)
{
	firstName = a;
	lastName = b;
	username = u;
	password = p;

}

Administrator::Administrator()
{
	username = "";
	password = "";
}

string Administrator::signIn()
{
	system("cls");
	fstream myInput;

	string uCheck, pCheck;
	bool repeat = true;

	while (repeat != false)
	{
		system("cls");
		myInput.open("adminsUP.txt");

		cout << "*************************ADMIN SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\tENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\n\tENTER YOUR PASSWORD: ";
		cin >> password;

		if (!(myInput.is_open()))
			cout << "FILE CANNOT BE OPENED! ";
		else
		{

			while (!myInput.eof())
			{
				getline(myInput, uCheck);
				getline(myInput, pCheck);

				if (username == uCheck && password == pCheck)
				{
					repeat = false;
					cout << "\nLOGGED IN SUCCESSFULLY! '" << uCheck << "' WELCOME! :)" << endl << endl;
					system("pause");
					return username;
				}
			}

			myInput.close();
			cout << endl;
			cout << "\tINVALID CREDENTIALS! " << endl << endl;

			int temp;
			cout << "\tGO BACK TO MAIN LOGIN PAGE? (0 FOR YES/1 FOR NO): ";
			cin >> temp;

			if (temp == 0)
			{
				return "null";
			}

			cout << endl;

		}
	}


}

Teacher Administrator::addNewTeacher()
{
	string fN, lN, d, uN, pW, rD, q, cN, a;
	char g;
	int s;

	cout << "\n\tENTER FIRST NAME: ";
	cin >> fN;

	cout << "\n\tENTER LAST NAME: ";
	cin >> lN;

	cout << "\n\tENTER DEPARTMENT (e.g. SE): ";
	cin >> d;

	cout << "\n\tENTER REGISTRATION DATE (e.g. 19.02.2018): ";
	cin >> rD;

	cout << "\n\tENTER GENDER (M/F) ";
	cin >> g;

	cin.ignore();
	cout << "\n\tENTER QUAILIFICATION: ";
	getline(cin, q);

	cout << "\n\tENTER CONTACT NUMBER: ";
	getline(cin, cN);

	cout << "\n\tENTER TEACHER USERNAME: ";
	cin >> uN;

	cout << "\n\tENTER TEACHER PASSWORD: ";
	cin >> pW;

	cin.ignore();
	cout << "\n\tENTER ADDRESS: ";
	getline(cin, a);

	cout << "\n\tENTER SALARY: ";
	cin >> s;


	Teacher newTeacher(fN, lN, d, uN, pW, rD, g, cN, q, a, s);
	newTeacher.timeTable.setTimeTable(newTeacher);

	newTeacher.writeToFile("teachers.txt");

	newTeacher.saveLogin("teachersUP.txt");
	system("cls");

	return newTeacher;

}

Administrator Administrator::addNewAdmin()
{
	string fN, lN, uN, pW;


	cout << "\nENTER YOUR FIRST NAME: ";
	cin >> fN;

	cout << "\nENTER YOUR LAST NAME: ";
	cin >> lN;

	cout << "\nENTER YOUR USERNAME: ";
	cin >> uN;

	cout << "\nENTER YOUR PASSWORD: ";
	cin >> pW;


	Administrator newAdmin(fN, lN, uN, pW);
	newAdmin.writeToFile("admins.txt");

	newAdmin.saveLogin("adminsUP.txt");


	return newAdmin;

}

void Administrator::writeToFile(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);

	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << firstName << endl;
		myOutput << lastName << endl;
		myOutput << username << endl;
		myOutput << password << endl;
	}

	myOutput.close();
}

Student Administrator::addNewStudent()
{

	string fN, lN, d, cN, bG, a, uN, pW, q, rD;
	bool fS, g;

	cout << "\n\tENTER FIRST NAME: ";
	cin >> fN;

	cout << "\n\tENTER LAST NAME: ";
	cin >> lN;

	bool correct = false;

	while (correct != true)
	{
		cout << "\n\tENTER FEE STATUS (1 FOR PAID/0 FOR NOT PAID): ";
		cin >> fS;

		if (fS > 1 || fS < 0)
		{
			cout << "\n\tINVALID ENTRY!\n";
			correct = false;
		}

		else
			correct = true;
	}

	cout << "\n\tENTER ADDRESS: ";
	cin.ignore();
	getline(cin, a);

	cout << "\n\tENTER CONTACT NUMBER: ";
	getline(cin, cN);

	cout << "\n\tENTER QUAILIFICATION: ";
	getline(cin, q);

	cout << "\n\tENTER BLOOD GROUP: ";
	getline(cin, bG);

	correct = 0;

	while (correct != true)
	{
		cout << "\n\tENTER GENDER (1 FOR MALE/0 FOR FEMALE): ";
		cin >> g;
		if (g > 1 || g < 0)
		{
			cout << "\n\tINVALID ENTRY!\n";
			correct = false;
		}

		else
			correct = true;
	}
	cout << "\n\tENTER DEPARTMENT (e.g. AI): ";
	cin >> d;

	cout << "\n\tENTER REGISTRATION DATE (e.g. 19.02.2018): ";
	cin.ignore();
	getline(cin, rD);

	cout << "\n\tENTER STUDENT USERNAME: ";
	cin >> uN;

	cout << "\n\tENTER STUDENT PASSWORD: ";
	cin >> pW;



	Student newStudent(fN, lN, d, g, cN, bG, a, fS, q, 0, uN, pW);

	newStudent.regCourses.addCourse();

	newStudent.obj.setID((17 + rand() % 5), 'F', (1000 + rand() % 4000 + 1));

	newStudent.writeToFile("students.txt");

	newStudent.saveLogin("studentsUP.txt");

	system("cls");

	return newStudent;
}

int Administrator::selectStudent(Student students[])
{
	int thisOption;

	bool valid = false;

	while (valid != true)
	{
		system("cls");
		cout << "CHOOSE THE SR NO. OF THE STUDENT TO MODIFY: \n\n";

		for (int i = 0; i < Student::totalStudents; i++)
		{
			cout << "\t\t(" << i + 1 << ") " << students[i].firstName << " " << students[i].lastName << "\n";
		}

		cout << "\n\n\tENTER SR NO. HERE: ";
		cin >> thisOption;

		if (thisOption <= 0 || thisOption > Student::getCount())
		{
			cout << "\n\tINVALID INPUT!\n\n";
			system("pause");
			valid = false;
		}

		else
			valid = true;

	}

	return thisOption;
}

int Administrator::selectTeacher(Teacher teachers[])
{
	int thisOption;
	bool valid = false;
	cout << endl;

	while (valid != true)
	{
		system("cls");

		cout << "CHOOSE THE SR NO. OF THE TEACHER TO MODIFY: \n\n";

		for (int i = 0; i < Teacher::getCount(); i++)
		{
			cout << "\t\t(" << i + 1 << ") " << teachers[i].firstName << " " << teachers[i].lastName << "\n";
		}

		cout << "\n\n\tENTER SR NO. HERE: ";
		cin >> thisOption;

		if (thisOption< 1 || thisOption > Teacher::getCount())
		{
			cout << "\n\tINVALID INPUT! \n\n";
			system("pause");
			valid = false;
		}

		else
			valid = true;

	}

	return thisOption;
}

void Administrator::editStudent(Student& student)
{
	cout << endl;

	system("cls");

	int choice = 0;
	bool valid = false;

	while (valid != true)
	{
		cout << "\n\tPRESS 1 TO EDIT FIRST NAME" << "\n\n\tPRESS 2 TO EDIT LAST NAME";
		cout << "\n\n\tPRESS 3 TO EDIT FEE STATUS" << "\n\n\tPRESS 4 TO EDIT ADDRESS";
		cout << "\n\n\tPRESS 5 TO EDIT CONTACT NUMBER" << "\n\n\tPRESS 6 TO GO BACK" << "\n\n\tENTER YOUR CHOICE: ";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			cout << "\nCURRENT FIRST NAME IS: " << student.firstName << endl;
			cout << "\nENTER NEW FIRST NAME: ";
			cin.ignore();
			getline(cin, student.firstName);

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");
		}
		else if (choice == 2)
		{
			system("cls");
			cout << "\nCURRENT LAST NAME IS: " << student.lastName << endl;
			cout << "\nENTER NEW LAST NAME: ";
			cin.ignore();
			getline(cin, student.lastName);

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");
		}
		else if (choice == 3)
		{
			system("cls");
			cout << "\nCURRENT FEE STATUS IS: " << ((student.feeStatus) ? "PAID" : "NOT PAID");
			cout << endl;

			bool correct = false;
			while (correct != true)
			{
				cout << "\nENTER NEW FEE STATUS (1 FOR PAID/0 FOR NOT PAID): ";
				cin >> student.feeStatus;
				if (student.feeStatus > 1 || student.feeStatus < 0)
				{
					cout << "\n\tINVALID ENTRY!\n\n";
					correct = false;
				}

				else
					correct = true;
			}


			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");

		}
		else if (choice == 4)
		{
			system("cls");
			cout << "\nCURRENT ADDRESS IS: " << student.address << endl;
			cout << "\nENTER NEW ADDRESS: ";
			cin.ignore();
			getline(cin, student.address);

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");

		}
		else if (choice == 5)
		{
			system("cls");
			cout << "\nCURRENT CONTACT NUMBER IS: " << student.contactNo << endl;
			cout << "\nENTER NEW CONTACT NUMBER: ";
			cin.ignore();
			getline(cin, student.contactNo);

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");

		}

		else if (choice == 6)
		{
			valid = true;
		}

		else
		{
			cout << "\n\tINVALID INPUT! \n\n";
			system("pause");
			valid = false;

		}

		system("cls");
	}


}

void Administrator::editTeacher(Teacher& teacher)
{

	cout << endl;
	system("cls");

	int choice;

	bool valid = false;

	while (valid != true)
	{
		cout << "\n\tPRESS 1 TO EDIT QUALIFICATION" << "\n\n\tPRESS 2 TO EDIT SALARY";
		cout << "\n\n\tPRESS 3 TO EDIT ADDRESS" << "\n\n\tPRESS 4 TO EDIT CONTACT NUMBER" << "\n\n\tPRESS 5 TO GO BACK" << "\n\n\tENTER YOUR CHOICE: ";
		cin >> choice;

		if (choice == 1)
		{
			system("cls");
			cout << "\nCURRENT QUALIFICATION IS: " << teacher.qualification << endl;
			cout << "\nENTER NEW QUALIFICATION: ";
			cin.ignore();
			getline(cin, teacher.qualification);

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");

		}
		else if (choice == 2)
		{
			system("cls");
			cout << "\nCURRENT SALARY IS: " << teacher.salary << endl;
			cout << "\nENTER NEW SALARY: ";
			cin >> teacher.salary;

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");

		}
		else if (choice == 3)
		{
			system("cls");
			cout << "\nCURRENT ADDRESS IS: " << teacher.address << endl;
			cout << "\nENTER NEW ADDRESS: ";
			cin.ignore();
			getline(cin, teacher.address);

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");

		}
		else if (choice == 4)
		{
			system("cls");
			cout << "\nCURRENT CONTACT NUMBER IS: " << teacher.contactNo << endl;
			cout << "\nENTER NEW CONTACT NUMBER: ";
			cin.ignore();
			getline(cin, teacher.contactNo);

			cout << endl;
			cout << "UPDATED! :)\n";
			cout << endl;
			system("pause");

		}

		else if (choice == 5)
		{
			valid = true;
		}

		else
		{
			cout << "\n\tINVALID ENTRY! \n\n";
			system("pause");
			valid = false;

		}

		system("cls");

	}

}

void Administrator::viewAllStudents(Student* students, HOD* hods)
{
	hods->viewAllStudents(students);
}

void Administrator::viewAllTeachers(Teacher* teachers, HOD* hods)
{
	hods->viewAllTeachers(teachers);
}

HOD::HOD()
{
	firstName = "";
	lastName = "";
	department = "";
	username = "";
	password = "";
	obj = nullptr;
	totalHODS++;
}

HOD::HOD(string a, string b, string c, string u, string p)
{
	firstName = a;
	lastName = b;
	department = c;
	username = u;
	password = p;
	totalHODS++;
}

bool HOD::isTeacher()
{
	if (obj == nullptr)
	{
		return false;
	}

	return true;
}

void HOD::writeToFile(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);

	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << firstName << endl;
		myOutput << lastName << endl;
		myOutput << department << endl;
		myOutput << username << endl;
		myOutput << password << endl;

	}
	myOutput.close();
}

void HOD::addTeachersFunctionality(Teacher*& a)
{
	a->incCount();

	Teacher newTeacher(firstName, lastName, department, username, password, "", '/0', "", "", "", 0);

	a[Teacher::getCount() - 1] = newTeacher;

	obj = &a[Teacher::getCount() - 1];

	a[Teacher::getCount() - 1].obj.getTeacherID();

	a[Teacher::getCount() - 1].writeToFile("teachers.txt");

	a[Teacher::getCount() - 1].saveLogin("teachersUP.txt");


	system("cls");






	obj = &a[Teacher::totalTeachers];
}

string HOD::signIn()
{
	system("cls");
	fstream myInput;

	string uCheck, pCheck;
	bool repeat = true;

	while (repeat != false)
	{
		system("cls");
		myInput.open("hodsUP.txt");

		cout << "*************************HOD SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\tENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\n\tENTER YOUR PASSWORD: ";
		cin >> password;

		if (!(myInput.is_open()))
			cout << "FILE CANNOT BE OPENED! ";
		else
		{

			while (!myInput.eof())
			{
				getline(myInput, uCheck);
				getline(myInput, pCheck);

				if (username == uCheck && password == pCheck)
				{
					repeat = false;
					cout << "\nLOGGED IN SUCCESSFULLY! '" << uCheck << "' WELCOME! :)" << endl << endl;
					system("pause");
					return username;
				}
			}

			myInput.close();
			cout << endl;
			cout << "\tINVALID CREDENTIALS! " << endl << endl;

			int temp;
			cout << "\tGO BACK TO MAIN LOGIN PAGE? (0 FOR YES/1 FOR NO): ";
			cin >> temp;

			if (temp == 0)
			{
				return "null";
			}

			cout << endl;
		}
	}
}

int HOD::getHodIndex(HOD hods[], string tempUser3)
{
	for (int i = 0;i < getCount();i++)
	{
		if (hods[i].username == tempUser3)
		{
			return i;
		}
	}
}

void HOD::viewTeacherActivity(Teacher* a)
{

	cout << "\n\n\t\t\t     TOTAL NUMBER OF CURRENT FACULTY: " << Teacher::totalTeachers << endl << endl;


	for (int i = 0; i < Teacher::totalTeachers; i++)
	{
		cout << "\n------------------------------------------------------------------------------------------------------\n";
		a[i].getTeacherData();

	}

	cout << "\n------------------------------------------------------------------------------------------------------\n";
}

void HOD::viewStudentModule(Student* a)
{

	cout << "\n\n\t\t\t     TOTAL NUMBER OF PRESENT ENROLLED STUDENTS: " << Student::totalStudents << endl << endl;


	for (int i = 0; i < Student::totalStudents; i++)
	{
		cout << "------------------------------------------------------------------------------------------------------\n";
		a[i].printStudent();
		cout << endl;
	}

	cout << "------------------------------------------------------------------------------------------------------\n";

}

void HOD::viewAllStudents(Student* a)
{
	cout << "\n\n\t\t\t     TOTAL NUMBER OF PRESENT ENROLLED STUDENTS: " << Student::totalStudents << endl << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

	cout << setw(18) << "ROLL NO ";
	cout << setw(18) << "FIRST NAME ";
	cout << setw(18) << "LAST NAME ";
	cout << setw(18) << "USERNAME ";
	cout << setw(18) << "PASSWORD ";
	cout << setw(18) << "DEPARTMENT ";
	cout << setw(18) << "CONTACT NO ";
	cout << setw(18) << "FEE STATUS ";

	cout << endl;

	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < Student::totalStudents; i++)
	{
		a[i].getStudentData();
	}
}

void HOD::viewAllTeachers(Teacher* a)
{
	cout << "\n\n\t\t\t     TOTAL NUMBER OF CURRENT FACULTY: " << Teacher::totalTeachers << endl << endl;


	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << setw(18) << "TEACHER ID ";
	cout << setw(18) << "FIRST NAME ";
	cout << setw(18) << "LAST NAME ";
	cout << setw(18) << "USERNAME ";
	cout << setw(18) << "PASSWORD ";
	cout << setw(18) << "DEPARTMENT ";
	cout << setw(18) << "CONTACT NO ";
	cout << setw(18) << "SALARY ";
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < Teacher::totalTeachers; i++)
	{
		a[i].getTeacherData2();

	}

}

Teacher::TimeTable::TimeTable()
{
	courseTitle = "";

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			timeTable[i][j] = 0;
		}
	}
}

Teacher::TeacherID::TeacherID()
{
	department = '\0';
	teacherNo = 0000;
}

int Student::getCount()
{
	return totalStudents;
}

int Teacher::getCount()
{
	return totalTeachers;
}

int HOD::getCount()
{
	return totalHODS;
}

int Administrator::getCount()
{
	return totalAdmins;
}

void Student::incCount()
{
	totalStudents++;
}

void Teacher::incCount()
{
	totalTeachers++;
}

void HOD::incCount()
{
	totalHODS++;
}

void Administrator::incCount()
{
	totalAdmins++;
}

void Student::saveLogin(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);

	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << username << endl;
		myOutput << password << endl;

	}
	myOutput.close();
}

void Teacher::saveLogin(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);

	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << username << endl;
		myOutput << password << endl;

	}
	myOutput.close();
}

void HOD::saveLogin(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);

	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << username << endl;
		myOutput << password << endl;

	}
	myOutput.close();
}

void Administrator::saveLogin(string fName)
{
	fstream myOutput;

	myOutput.open(fName, ios::app);

	if (!myOutput.is_open())
		cout << "File not found";

	else
	{
		myOutput << username << endl;
		myOutput << password << endl;

	}
	myOutput.close();
}

int Teacher::selectStudent(Student students[])
{
	int thisOption;

	bool valid = false;
	cout << endl;
	while (valid != true)
	{
		system("cls");
		cout << "CHOOSE THE SR NO. OF THE STUDENT TO MODIFY: \n\n";

		for (int i = 0; i < Student::totalStudents; i++)
		{
			cout << "\t\t(" << i + 1 << ") " << students[i].firstName << " " << students[i].lastName << "\n";
		}

		cout << "\n\n\tENTER SR NO. HERE: ";
		cin >> thisOption;

		if (thisOption <= 0 || thisOption > Student::getCount())
		{
			cout << "\n\tINVALID INPUT!\n\n";
			system("pause");
			valid = false;
		}

		else
			valid = true;

	}

	return thisOption - 1;
}

Student::Attendance Student::getAttendance()
{
	return attendance;
}

Student::Attendance::Attendance()
{
	for (int i = 0; i < 5; i++)
		day[i] = 0;
}

Student::StudentID::StudentID()
{
	year = 00;
	city = '\0';
	rollNo = 0000;
}

Student::RegisteredCourses::RegisteredCourses()
{
	int count = 0;
	noOfcourses = 3;

	courseArr = new string[noOfcourses];
	gradeArr = new string[noOfcourses];

	for (int i = 0; i < noOfcourses; i++)
	{
		courseArr[i] = "";
		gradeArr[i] = "";
	}
}

