#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include "STUDENT.h"
#include "TEACHER.h"
#include "HOD.h"
#include "ADMINISTRATOR.h"
//RELEVANT HEADER FILES AND LIBRARIES ATTACHED 

using namespace std;

//MAX CAPACITY OF EACH TYPE OF MODULE
const int maxStudents = 500;
const int maxTeachers = 500;
const int maxHODS = 500;
const int maxAdmins = 500;

// STATIC DECLARATION OF CURRENT COUNT OF EACH MODULE
int Student::totalStudents = 0;
int Teacher::totalTeachers = 0;
int HOD::totalHODS = 5;
int Administrator::totalAdmins = 3;

int main()
{
	//FOR GENERATING NEW RANDOM NUMBER EACH TIME
	srand(time(0));
	
	//DYNAMIC ALLOCATION OF EACH TYPE
	Teacher* teachers = new Teacher[maxTeachers];
	Student* students = new Student[maxStudents];
	Administrator* admins = new Administrator[maxAdmins];
	HOD* hods = new HOD[maxHODS];
	
	//TEACHERS INITIALISATION THROUGH PARAMETRISED CONSTUCTOR
	teachers[0].setTeacher("Mustafa", "Kamal", "Computer Science", "mustafakamal18", "abcdef", "17.02.2018", 1, "0300-4428828", "MS - Computer Science", "114 Faisal Block, Iqbal Town, Lahore", 120000);
	teachers[1].setTeacher("Ikram", "Jafar", "Business", "ikramjafar24", "ihjffld", "04.03.2020", 1, "0321-5421138", "M - Business Administration", "3 Mirza Block, Johar Town, Faisalabad", 140000);
	teachers[2].setTeacher("Fatima", "Tameer", "Social Sciences", "fatimatameer22", "dasdssa", "01.11.2017", 0, "0343-3432418", "MS - Physics", "43 Chenab Block, Ilyas Town, Karachi", 95000);

	//STUDENTS INITIALISATION THROUGH PARAMETRISED CONSTUCTOR
	students[0].setStudent("Kamran", "Bilal", "Computer Science", 1, "0300-1643244", "B - Positive", "143 Ravi Block, Rizauddin Town, Lahore", 1, "A - Levels", 976, "kamranbilal12", "kvjmsd");
	students[1].setStudent("Rija", "Faisal", "Business", 1, "0315-5293281", "AB - Positive", "122 Bajnur Block, Liaqat Town, Alipur", 1, "A - Levels", 675, "rijafaisal15", "0dsdaaa");
	students[2].setStudent("Ali", "Hamid", "Software Engineering", 1, "0344-5453121", "O - Negative", "98 Akbar Block, Shifa Town, Jehlum", 0, "FSC", 1011, "alihamid44", "aasfffs");
		
	hods[0].setHOD("Hassan", "Ali", "Software Engineering");
	hods[1].setHOD("Ali", "Ahmed", "Business");
	hods[2].setHOD("Javaid", "Rasheed", "Social Sciences");
	hods[3].setHOD("Aleena", "Bilal", "Electrical Engineering");
	hods[4].setHOD("Iman", "Latif", "Computer Science");


	bool end = true;
	
	//FLOW OF PROGRAM NOT ENDED UNTIL CHOSEN
	while (end != false)
	{
		cout << "--------------------F L E X      M A N A G E M E N T      S Y S T E M--------------------" << endl << endl;
		int option;
		cout << "KINDLY CHOOSE ONE OF THE FOLLOWING MODULES TO ACCESS YOUR RESPECTIVE INTEREST: ";
		cout << endl << endl << endl;
		cout << "\t\tENTER (1) IF YOU ARE FROM THE ADMINISTRATION DOMAIN" << endl;
		cout << "\t\tENTER (2) IF YOU ARE FROM THE STUDENT DOMAIN" << endl;
		cout << "\t\tENTER (3) IF YOU ARE FROM THE TEACHER DOMAIN" << endl;
		cout << "\t\tENTER (4) IF YOU ARE FROM THE HEAD OF DEPARTMENT (HOD) DOMAIN" << endl;
		cout << endl << endl;
		cout << "\tENTER YOUR OPTION: ";
		cin >> option;
		cout << endl;

		//ADMINISTRATION MODULE
		if (option == 1)
		{
			//DISPLAYS THE ADMINISTRATION SIGN IN MENU
			admins[0].signIn();
			system("cls");

			int subOption = 0;

			cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO ADD A NEW TEACHER\n\t\tPRESS (2) TO ADD A NEW STUDENT\n\t\tPRESS (3) TO EDIT STUDENT DETAILS\n\t\tPRESS (4) TO EDIT TEACHER DETAILS\n\t\tPRESS (5) TO VIEW ALL OF THE ENROLLED STUDENTS\n\t\tPRESS (6) TO VIEW ALL OF THE CURRENT FACULTY\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
			cin >> subOption;

			//ADD NEW TEACHER
			if (subOption == 1)
			{
				system("cls");
				admins->addNewTeacher();
			}

			//ADD NEW STUDENT
			else if (subOption == 2)
			{
				system("cls");
			}

			//EDIT STUDENT DETAILS
			else if (subOption == 3)
			{
				system("cls");
			}

			//EDIT TEACHER DETAILS
			else if (subOption == 4)
			{
				system("cls");
			}

			//VIEW ALL STUDENTS
			else if (subOption == 5)
			{
				system("cls");
			}

			//VIEW ALL TEACHERS
			else if (subOption== 6)
			{
				system("cls");
			}

			else
			{
				system("cls");
			}
		}

		//STUDENT MODULE
		else if (option == 2)
		{
			//DISPLAYS THE STUDENT SIGN IN MENU
			students[0].signIn();

			system("cls");

			int subOption2 = 0;

			cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO VIEW YOUR ATTENDANCE\n\t\tPRESS (2) TO VIEW YOUR MARKS\n\t\tPRESS (3) TO VIEW YOUR GRADES\n\t\tPRESS (4) TO VIEW YOUR REGISTERED COURSES\n\t\tPRESS (5) TO VIEW YOUR FEE STATUS\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
			cin >> subOption2;

			//VIEW ATTENDANCE
			if (subOption2 == 1)
			{
				system("cls");
			}

			//VIEW MARKS
			else if (subOption2 == 2)
			{
				system("cls");
			}

			//VIEW GRADES
			else if (subOption2 == 3)
			{
				system("cls");
			}

			//VIEW REGISTERED COURSES
			else if (subOption2 == 4)
			{
				//system("cls");
				students[0].viewRegisteredCourses();
				

			}

			//VIEW FEE STATUS
			else if (subOption2 == 5)
			{
				system("cls");
			}

			else
			{
				system("cls");
			}
		}

		//TEACHER MODULE
		else if (option == 3)
		{
			//DISPLAYS THE TEACHER SIGN IN MENU
			teachers[0].signIn();
			system("cls");

			int subOption3= 0;

			cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO VIEW TEACHER TIMETABLE\n\t\tPRESS (2) TO ASSIGN MARKS TO STUDENTS\n\t\tPRESS (3) TO MARK ATTENDANCE OF STUDENTS\n\t\tPRESS (4) TO ASSIGN GRADES TO STUDENTS\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
			cin >> subOption3;

			//DISPLAYS TEACHER TIMETABLE
			if (subOption3 == 1)
			{
				system("cls");
				//teachers[0].timeTable.setTimeTable(teachers[0]);
				bool a[5][3] = { {1,0,1}, {0,0,1}, {0,0,0}, {1,0,1}, {1,1,0} };
				teachers[0].timeTable.setTimeTable("CALCULUS", a);
				teachers[0].timeTable.displayTimeTable();
			}

			//ASSIGNS MARKS
			else if (subOption3 == 2)
			{

				int thisOption;

				system("cls");
				cout << "CHOOSE THE STUDENT WHOSE MARKS YOU WANT TO ENTER \n";
				cout << "INPUT THE SR NO. OF THE FOLLOWING: \n\n";

				for (int i = 0; i < Student::totalStudents; i++)
				{
					

					cout <<"\t\t("<<i+1<<") "<< students[i].firstName << " " << students[i].lastName<<"\n";
					
				}
				
				cout << "\n\n\tENTER SR NO. HERE: ";
				cin >> thisOption;

				system("cls");
				teachers->assignMarks(students[thisOption-1]);
				
				cout << students[thisOption - 1].marks;

			}

			//MARKING ATTENDANCE
			else if (subOption3 == 3)
			{
				int thisOption;

				system("cls");
				cout << "CHOOSE THE STUDENT WHOSE ATTENDANCE YOU WANT TO MARK \n";
				cout << "INPUT THE SR NO. OF THE FOLLOWING: \n\n";

				for (int i = 0; i < Student::totalStudents; i++)
				{


					cout << "\t\t(" << i + 1 << ") " << students[i].firstName << " " << students[i].lastName << "\n";

				}

				cout << "\n\n\tENTER SR NO. HERE: ";
				cin >> thisOption;

				system("cls");
				teachers->markAttendance(students[thisOption - 1]);

				system("cls");

				
				students[thisOption-1].attendance.displayAttendance(students[thisOption - 1]);
				
			}

			//ASSIGN GRADES
			else if (subOption3 == 4)
			{
				int thisOption;

				system("cls");
				cout << "CHOOSE THE STUDENT WHOM YOU WANT TO ASSSIGN THE GRADE \n";
				cout << "INPUT THE SR NO. OF THE FOLLOWING: \n\n";

				for (int i = 0; i < Student::totalStudents; i++)
				{


					cout << "\t\t(" << i + 1 << ") " << students[i].firstName << " " << students[i].lastName << "\n";

				}

				cout << "\n\n\tENTER SR NO. HERE: ";
				cin >> thisOption;

				system("cls");
				teachers->assignGrade(students[thisOption - 1]);


				cout<<"GRADE: "<<students[thisOption - 1].grade;

			}

			else
			{
				system("cls");
			}
		}

		//HOD MODULE
		else if (option == 4)
		{
			//DISPLAYS THE HOD SIGN IN MENU
			hods[0].signIn();
			
			system("cls");

			int subOption4 = 0;

			cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO REGISTER YOURSELF AS A TEACHER\n\t\tPRESS (2) TO VIEW ALL ACTIVITIES OF TEACHER MODULE\n\t\tPRESS (3) TO VIEW THE STUDENTS MODULE\n\t\tPRESS (4) TO VIEW ALL OF THE ENROLLED STUDENTS\n\t\tPRESS (5) TO VIEW ALL OF THE CURRENT FACULTY\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
			cin >> subOption4;
			
			//HOD AS TEACHER
			if (subOption4 == 1)
			{
				hods->addTeachersFunctionality(teachers);
				teachers[Teacher::totalTeachers].setTeacher(hods->firstName, hods->lastName, hods->department, hods->username, hods->password, "", '/0', "", "", "", 0);
				system("cls");

				cout << "\n\tYOUR TEACHER PROFILE HAS BEEN SET UP \n\n\t";
				teachers[Teacher::totalTeachers - 1].obj.getTeacherID();

				cout << Teacher::totalTeachers;

			}

			//VIEW ALL ACTIVITIES OF TEACHER MODULE
			else if (subOption4 == 2)
			{
				system("cls");
			}

			//ACCESS TO STUDENT MODULE
			else if (subOption4 == 3)
			{
				system("cls");
			}

			//VIEW ALL STUDENTS
			else if (subOption4 == 4)
			{
				system("cls");
				hods->viewAllStudents(students);
			}

			//VIEW ALL TEACHERS
			else if (subOption4 == 5)
			{
				system("cls");
				hods->viewAllTeachers(teachers);
			}

			else
			{
				system("cls");
			}
		}

		else
		{
		system("cls");
		}

		system("pause");
		system("cls");
		cout << "DO YOU WANT TO END THE FLEX SYSTEM: " << endl << endl;
		cout << "\tENTER (0) TO END THE FLEX SYSTEM" << endl;
		cout << "\tENTER (1) TO CONTINUE THE FLEX SYSTEM";
		cout << endl << endl;
		cout << "\t\tENTER YOUR OPTION: ";
		cin >> end;
		system("cls");
	}
	return 0;
}
