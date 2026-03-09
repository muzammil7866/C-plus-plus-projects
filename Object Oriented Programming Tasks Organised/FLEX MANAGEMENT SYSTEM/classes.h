#include<string>
#include <iostream>
#include<fstream>
#include<iomanip>

#define ADMINISTRATION_H

using namespace std;

class Student
{

	class Attendance
	{

	protected:
		bool day[5]; //5 WORKING DAYS

	public:

		//CONSTRUCTOR
		Attendance();


		void setAttendance(bool a, bool b, bool c, bool d, bool e);

		void setAttendance(Student& a);


		void displayAttendance(Student& a);

		//GRANTING ACCESS
		friend class Student;

		friend class Teacher;

		friend class HOD;

		friend class Administrator;
	};


	class StudentID
	{
	protected:
		int year;

		char city;

		int rollNo;

	public:


		StudentID();

		void setID(int a, char b, int c);

		void displayStudentID();

		friend class Student;

		friend class Teacher;

		friend class HOD;

		friend class Administrator;
	};


	class RegisteredCourses
	{
	protected:
		int noOfcourses;
		string* courseArr; //RESPECTIVE COURSES
		string* gradeArr;  //RESPECTIVE GRADES

	public:

		RegisteredCourses();

		void addCourse();

		void viewCourse();

		void assignGrades();

		void showGrades();

		friend class Student;

		friend class Teacher;

		friend class HOD;

		friend class Administrator;

	};

protected:

	string firstName;
	string lastName;
	string department;
	string regDate;
	int gender;
	string contactNo;
	string bloodGroup;
	string address;
	int feeStatus;
	string qualification;
	int marks;
	string grade;
	string username;
	string password;
	static int totalStudents; //SHARED BETWEEN EACH INSTANCE OF STUDENT
	Attendance attendance;
	RegisteredCourses regCourses;
	StudentID obj;

public:

	Student();

	//CONSTRUCTOR PARAMETERISED
	Student(string a, string b, string c, bool d, string e, string f, string g, bool h, string i, int j, string k, string l);

	void printStudent();

	void getStudentData();

	//SAVE TO FILE
	void writeToFile(string a);

	string signIn();

	//CURRENT COUNT
	static int getCount();

	void incCount();

	Attendance getAttendance();

	void saveLogin(string fName);

	//GETS INDEX OF STUDENT OBJECT 
	int getStudentInd(Student students[], string uN);


	void viewAttendance(Student* students);


	void viewMarks(Student* students);


	void viewGrades(Student* students);


	void viewRegisteredCourses();


	void viewFeeStatus(Student* students);



	friend class Teacher;

	friend class HOD;

	friend class Administrator;

};

class Teacher
{


	class TimeTable
	{
	protected:
		string courseTitle;

		int timeTable[5][3]; //5 DAYS, 3 TIME SLOTS

	public:

		TimeTable();

		void setTimeTable(string a, bool each[][3]);

		void setTimeTable(Teacher& newTeacher); //OVERLOADING

		void displayTimeTable();

		friend class Teacher;

		friend class HOD;

		friend class Administrator;
	};

	class TeacherID
	{
	protected:
		string department;

		int teacherNo;

	public:

		TeacherID();

		void setteacherID(string a);

		void getTeacherID();

		friend class Teacher;

		friend class HOD;

		friend class Administrator;
	};

protected:

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
	static int totalTeachers;
	TimeTable timeTable;
	TeacherID obj;


public:

	Teacher();

	Teacher(string a, string b, string c, string d, string e, string f, char g, string h, string i, string j, int k);

	static int getCount();

	void incCount();

	void setTeacher(string a, string b, string c);

	void writeToFile(string a);

	void saveLogin(string fName);

	int getTeacherInd(Teacher teachers[], string tempUser);

	//TIME TABLE GETTER
	TimeTable getTT();

	//TO ASSIGN
	int selectStudent(Student students[]);

	//DISPLAY TEACHER INFO
	void getTeacherData();

	void getTeacherData2();

	string signIn();

	void markAttendance(Student& obj);

	void assignMarks(Student& obj);

	void assignGrades(Student& obj);

	void assignGrade(Student& a);

	friend class HOD;

	friend class Administrator;


};

class HOD
{

protected:
	string firstName;
	string lastName;
	string department;
	string username;
	string password;
	static int totalHODS;
	Teacher* obj; //IS TEACHER ALSO?

public:
	HOD();

	HOD(string a, string b, string c, string u, string p);

	bool isTeacher();

	static int getCount();

	void incCount();

	void writeToFile(string a);

	void saveLogin(string fName);

	int getHodIndex(HOD hods[], string tempUser3);

	//REGISTER IN FACULTY
	void addTeachersFunctionality(Teacher*& a);

	string signIn();

	void viewTeacherActivity(Teacher* a);

	void viewStudentModule(Student* a);

	void viewAllStudents(Student* a);

	void viewAllTeachers(Teacher* a);

	friend class Administrator;


};

class Administrator
{

protected:
	string firstName;
	string lastName;
	string username;
	string password;
	static int totalAdmins;

public:

	Administrator();

	Administrator(string a, string b, string u, string p);

	string signIn();

	Administrator addNewAdmin();

	static int getCount();

	void incCount();

	void writeToFile(string a);

	int selectStudent(Student students[]);

	int selectTeacher(Teacher teachers[]);

	void saveLogin(string fName);

	Teacher addNewTeacher();

	Student addNewStudent();

	void editStudent(Student& student);

	void editTeacher(Teacher& teacher);

	void viewAllStudents(Student* students, HOD* hods);

	void viewAllTeachers(Teacher* teachers, HOD* hods);

};

