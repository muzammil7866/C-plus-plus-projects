//RELEVANT HEADER FILES AND LIBRARIES ATTACHED 
#include<string>
#include <iostream>
#include<iomanip>
#define TEACHER_H
using namespace std;

CLASS OF TEACHER INHERITTING STUDENT CLASS
class Teacher : public Student
{
public:

	CLASS OF TEACHERS TIMETABLE
	class TimeTable
	{
	public:
		string courseTitle;
		//5 DAYS IN A WEEK AND 3 SLOTS TO CHOOSE FROM
		bool timeTable[5][3];

		//CONSTRUCTOR TO INITIALISE
		TimeTable()
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

		//SETTER OF TIMETABLE
		void setTimeTable(string a, bool each[][3])
		{
			courseTitle = a;

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 3; j++)
					timeTable[i][j] = each[i][j];
		}

		//SETTER OF TIMETABLE BY INPUTTING
		void setTimeTable(Teacher& newTeacher)
		{
			cout << "\n\tENTER THE COURSE TITLE OFFERED TO THE TEACHER: ";
			cin >> newTeacher.timeTable.courseTitle;

			system("cls");

			cout << "\n\t\tSELECT THE WORKING DAYS FOR THE TEACHER: " << endl;
			for (int i = 0; i < 5; i++)
			{
				int thisOption = 0;
				string week[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

				cout << "\n\tENTER (1) IF YOU WANT TO APPOINT LECTURE FOR THE TEACHER ON " << week[i] << ", OTHERWISE ENTER (0) : ";
				cin >> thisOption;

				if (thisOption == 1)
				{
					for (int j = 0; j < 3; j++)
					{

						system("cls");
						cout << "\n\t\tSELECT THE TIME SLOTS FOR THE TEACHER ON : " << week[i] << endl;

						string times[3] = { "8 am - 9:30 am", "10 am - 11:30 am", "12 pm - 1:30 pm" };

						cout << "\n\tENTER (1) IF YOU WANT TO APPOINT TIME SLOT TO THE TEACHER ON " << times[i] << ", OTHERWISE ENTER (0) : ";
						cin >> newTeacher.timeTable.timeTable[i][j];

					}
				}
			}
		}


		//DISPLAYS TIMETABLE
		void displayTimeTable()
		{
			system("cls");

			cout << "\n\t\t------------------------------------------------------------" << endl;
			cout << "\t\t                   TEACHER TIME TABLE                       " << endl;
			cout << "\t\t------------------------------------------------------------" << endl << endl;
			cout << "\n\t\tCOURSE ASSIGNED: " << courseTitle << "\n\n\n";

			string week[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
			string time[3] = { "8 am - 9:30 am", "10 am - 11:30 am", "12 pm - 1:30 pm" };

			for (int i = 0; i < 5; i++)
			{
				cout << setw(12) << week[i]<<"\t";
				for (int j = 0; j < 3; j++)
				{
			
					if (timeTable[i][j] == 1)
						cout << setw(7) << time[j]<<"  \t";
				}
				cout << endl << "------------------------------------------------------------";
				cout << "\n\n";
			}

		}
	};

	CLASS OF TEACHER ID
	class teacherID
	{
	public:
		//CS
		char department;
		//001
		int teacherNo;

		//CONSTRUCTOR TO INITIALISE
		teacherID()
		{
			department = '\0';
			teacherNo = 0000;
		}

		//SETTER OF TEACHER ID
		void setteacherID(string a, int& b)
		{
			department = toupper(a[0]);
			teacherNo = b + 1;
			b++;
		}

		//DISPLAY TEACHER ID
		void getTeacherID()
		{
			cout << "YOUR TEACHER ID IS: ";
			cout << department << "-" << teacherNo << "\n";
		}


	};

	//MEMBERS OF TEACHER
	string firstName;
	string lastName;
	string department;
	string username;
	string password;
	string regDate;
	bool gender;
	string contactNo;
	string qualification;
	string address;
	int salary;
	teacherID obj;
	static int totalTeachers;
	TimeTable timeTable;

	//CONSTRUCTOR OF TEACHER TO INITIALISE
	Teacher()
	{
		firstName = "";
		lastName = "";
		department = "";
		username = "";
		password = ""; //pw check?
		regDate = ""; //date datatype? i think no need
		gender = 0;
		contactNo = "";
		qualification = "";
		address = "";
		salary = 0;
	}

	//SETTER OF TEACHER FOR HOD
	void setTeacher(string a, string b, string c)
	{
		firstName = a;
		lastName = b;
		department = c;
		obj.setteacherID(c, totalTeachers);
	}

	//SETTER OF TEACHER
	void setTeacher(string a, string b, string c, string d, string e, string f, char g, string h, string i, string j, int k)
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
		obj.setteacherID(c, totalTeachers);
	}

	//DISPLAYS TEACHER
	void getTeacherData() //passwords visible?
	{
		cout << "\n\t\t\t     TEACHER USERNAME: " << username << "\n\t\t\t     TEACHER PASSWORD: " << password;
		cout << "\n\n\tNAME: " << firstName << " " << lastName << "\n\tDEPARTMENT: " << department << "\n\tREGISTRATION DATE: " << regDate << "\n\tGENDER: ";
		if (gender == 0)
			cout << "Female";
		else
			cout << "Male";
		cout << "\n\tCONTACT NO: " << contactNo << "\n\tQUALIFICATION: " << qualification;
		cout << "\n\tADDRESS: " << address << "\n\tSALARY: " << salary << "\n";
	}

	
	//DISPLAYS SIGN IN MENU FOR TEACHER
	void signIn()
	{
		system("cls");
		cout << "*************************TEACHERS SIGN IN PORTAL*************************";
		cout << endl << endl << endl;
		cout << "\t ENTER YOUR USERNAME: ";
		cin >> username;
		cout << "\t ENTER YOUR PASSWORD: ";
		cin >> password;

	}

	//MARKS ATTENDANCE
	void markAttendance(Student& obj)
	{
		system("cls");
		obj.attendance.setAttendance(obj);
	}


	//ASSGNS MARKS
	void assignMarks(Student& obj)
	{
		cout << "\n\tENTER THE MARKS (OUT OF 50) OF " << obj.firstName << " " << obj.lastName << ": ";
		cin >> obj.marks;
	}

	//ASSIGNS GRADES
	void assignGrades(Student& obj)
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

	void assignGrade(Student& a)
	{
		cout << "ENTER THE GRADE YOU WANT TO ASSIGN TO "<<a.firstName<<" "<<a.lastName<<": ";
		cin >> a.grade;
	}



};
