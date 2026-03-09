//RELEVANT HEADER FILES AND LIBRARIES 
#include<iostream> //INPUT OUTPUT
#include<string> //STRING FUNCTIONS
#include<cstdlib> //RANDOM GENERATION
#include<iomanip> //PRESENTATION
#include<fstream> //FILE HANDLING
#include<ctime> //RANDOM RESET
#include"classes.h" //CUSTOM HEADER 

using namespace std;

const int maxStudents = 500;

const int maxTeachers = 500;

const int maxHODS = 500;

const int maxAdmins = 500;

int Student::totalStudents = 0;

int Teacher::totalTeachers = 0;

int HOD::totalHODS = 0;

int Administrator::totalAdmins = 0;

//DRIVER FUNCTION
int main()
{
	system("color F0");

	srand(time(0));

	//DYNAMIC ALLOCATIONS
	Teacher* teachers = new Teacher[maxTeachers];

	Student* students = new Student[maxStudents];

	Administrator* admins = new Administrator[maxAdmins];

	HOD* hods = new HOD[maxHODS];

	//TEST HOD
	HOD testHOD("Test", "HOD", "none", "testhod", "test123");

	hods[0] = testHOD;

	hods->incCount(); //INCREMENT COUNTER

	bool end = false;

	//MAIN LOOP
	while (end != true)
	{

		cout << "\t  FFFFFFFFFFFFFFFFFFFFFFLLLLLLLLLLL             EEEEEEEEEEEEEEEEEEEEEEXXXXXXX       XXXXXXX" << endl;
		cout << "\t  F::::::::::::::::::::FL:::::::::L             E::::::::::::::::::::EX:::::X       X:::::X" << endl;
		cout << "\t  F::::::::::::::::::::FL:::::::::L             E::::::::::::::::::::EX:::::X       X:::::X" << endl;
		cout << "\t  FF::::::FFFFFFFFF::::FLL:::::::LL             EE::::::EEEEEEEEE::::EX::::::X     X::::::X" << endl;
		cout << "\t    F:::::F       FFFFFF  L:::::L                 E:::::E       EEEEEEXXX:::::X   X:::::XXX" << endl;
		cout << "\t    F:::::F               L:::::L                 E:::::E                X:::::X X:::::X   " << endl;
		cout << "\t    F::::::FFFFFFFFFF     L:::::L                 E::::::EEEEEEEEEE       X:::::X:::::X    " << endl;
		cout << "\t    F:::::::::::::::F     L:::::L                 E:::::::::::::::E        X:::::::::X     " << endl;
		cout << "\t    F:::::::::::::::F     L:::::L                 E:::::::::::::::E        X:::::::::X     " << endl;
		cout << "\t    F::::::FFFFFFFFFF     L:::::L                 E::::::EEEEEEEEEE       X:::::X:::::X    " << endl;
		cout << "\t    F:::::F               L:::::L                 E:::::E                X:::::X X:::::X   " << endl;
		cout << "\t    F:::::F               L:::::L         LLLLLL  E:::::E       EEEEEEXXX:::::X   X:::::XXX" << endl;
		cout << "\t  FF:::::::FF           LL:::::::LLLLLLLLL:::::LEE::::::EEEEEEEE:::::EX::::::X     X::::::X" << endl;
		cout << "\t  F::::::::FF           L::::::::::::::::::::::LE::::::::::::::::::::EX:::::X       X:::::X" << endl;
		cout << "\t  F::::::::FF           L::::::::::::::::::::::LE::::::::::::::::::::EX:::::X       X:::::X" << endl;
		cout << "\t  FFFFFFFFFFF           LLLLLLLLLLLLLLLLLLLLLLLLEEEEEEEEEEEEEEEEEEEEEEXXXXXXX       XXXXXXX" << endl;


		cout << endl << endl;

		int option;
		//TRACK USERNAME
		string user = "", tempUser = "", tempUser2 = "", tempUser3 = "";

		cout << "   KINDLY CHOOSE ONE OF THE FOLLOWING: ";
		cout << endl << endl;
		cout << "\t\tENTER (1) TO SIGN IN AS ADMINISTRATOR" << endl << endl;
		cout << "\t\tENTER (2) TO SIGN IN AS STUDENT" << endl << endl;
		cout << "\t\tENTER (3) TO SIGN IN AS TEACHER" << endl << endl;
		cout << "\t\tENTER (4) TO SIGN IN AS HEAD OF DEPARTMENT (HOD)" << endl << endl;
		cout << endl;
		cout << "\tENTER YOUR OPTION: ";
		cin >> option;
		cout << endl;

		if (option > 4 || option <= 0)
		{
			cout << "\tINVALID INPUT!\n\n";
			system("pause");

		}

		else
		{


			if (option == 1)
			{

				user = admins->signIn();

				system("cls");

				int subOption = 0;
				bool logOut = false;

				if (user == "null")
				{
					logOut = true;
				}

				while (logOut != true)
				{
					cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO ADD A NEW ADMIN\n\n\t\tPRESS (2) TO ADD A NEW TEACHER\n\n\t\tPRESS (3) TO ADD A NEW STUDENT\n\n\t\tPRESS (4) TO EDIT STUDENT DETAILS\n\n\t\tPRESS (5) TO EDIT TEACHER DETAILS\n\n\t\tPRESS (6) TO VIEW ALL OF THE ENROLLED STUDENTS\n\n\t\tPRESS (7) TO VIEW ALL OF THE CURRENT TEACHERS\n\n\t\tPRESS (8) TO LOG OUT\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
					cin >> subOption;


					if (subOption == 1)
					{
						system("cls");
						admins[Administrator::getCount()] = admins->addNewAdmin();

						admins->incCount();

						cout << "\nADMINISTRATOR ADDED SUCCESSFULLY!" << endl << endl;
						system("pause");
						system("cls");
					}


					else if (subOption == 2)
					{
						system("cls");
						teachers[Teacher::getCount()] = admins->addNewTeacher();

						teachers->incCount();

						cout << "\nTEACHER ADDED SUCCESSFULLY!" << endl << endl;
						system("pause");
						system("cls");
					}


					else if (subOption == 3)
					{
						system("cls");

						students[Student::getCount()] = admins->addNewStudent();

						students->incCount();

						cout << "\nSTUDENT ADDED SUCCESSFULLY!" << endl << endl;
						system("pause");
						system("cls");
					}


					else if (subOption == 4)
					{

						system("cls");

						if (students->getCount() == 0)
						{
							cout << "\nNO STUDENT RECORD FOUND!";

							cout << endl << endl;

							system("pause");

							system("cls");
						}

						else
						{
							admins->editStudent(students[admins->selectStudent(students) - 1]);
						}
					}




					else if (subOption == 5)
					{

						system("cls");

						if (students->getCount() == 0)
						{
							cout << "\nNO TEACHER RECORD FOUND!";

							cout << endl << endl;

							system("pause");

							system("cls");
						}

						else
						{
							admins->editTeacher(teachers[admins->selectTeacher(teachers) - 1]);
						}
					}


					else if (subOption == 6)
					{
						system("cls");
						hods->viewStudentModule(students);
						system("pause");
						system("cls");
					}


					else if (subOption == 7)
					{
						system("cls");

						hods->viewTeacherActivity(teachers);

						system("pause");

						system("cls");
					}


					else if (subOption == 8)
					{
						logOut = true;
						cout << "\n'" << user << "' LOGGED OUT SUCCESSFULLY!" << endl << endl;
						system("pause");
					}

					else
					{
						cout << "\n\tINVALID INPUT!\n\n";
						system("pause");
						system("cls");
					}
				}
			}


			else if (option == 2)
			{

				int thisStuInd;


				tempUser = students->signIn();


				thisStuInd = students->getStudentInd(students, tempUser);

				system("cls");

				int subOption2 = 0;
				bool logOut = false;

				if (tempUser == "null")
				{
					logOut = true;
				}

				while (logOut != true)
				{

					cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO VIEW YOUR ATTENDANCE\n\n\t\tPRESS (2) TO VIEW YOUR MARKS\n\n\t\tPRESS (3) TO VIEW YOUR GRADES\n\n\t\tPRESS (4) TO VIEW YOUR REGISTERED COURSES\n\n\t\tPRESS (5) TO VIEW YOUR FEE STATUS\n\n\t\tPRESS (6) TO LOG OUT\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
					cin >> subOption2;


					if (subOption2 == 1)
					{
						system("cls");
						students->viewAttendance(&students[thisStuInd]);
						system("pause");
						system("cls");

					}


					else if (subOption2 == 2)
					{
						system("cls");
						students->viewMarks(&students[thisStuInd]);
						system("pause");
						system("cls");
					}


					else if (subOption2 == 3)
					{
						system("cls");
						students->viewGrades(&students[thisStuInd]);
						system("pause");
						system("cls");
					}


					else if (subOption2 == 4)
					{
						system("cls");
						students[thisStuInd].viewRegisteredCourses();
						system("pause");
						system("cls");


					}


					else if (subOption2 == 5)
					{
						system("cls");
						students[thisStuInd].viewFeeStatus(&students[thisStuInd]);
						system("pause");
						system("cls");
					}


					else if (subOption2 == 6)
					{
						logOut = true;
						cout << "\n'" << tempUser << "' LOGGED OUT SUCCESSFULLY!" << endl << endl;
						system("pause");
					}

					else
					{
						cout << "\n\tINVALID INPUT!\n\n";
						system("pause");
						system("cls");
					}
				}
			}


			else if (option == 3)
			{


				int thisTeaInd;

				tempUser2 = teachers->signIn();


				thisTeaInd = teachers->getTeacherInd(teachers, tempUser2);

				system("cls");

				int subOption3 = 0;

				bool logOut = false;

				if (tempUser2 == "null")
				{
					logOut = true;
				}

				while (logOut != true)
				{

					cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO VIEW TEACHER TIMETABLE\n\n\t\tPRESS (2) TO ASSIGN MARKS TO STUDENTS\n\n\t\tPRESS (3) TO MARK ATTENDANCE OF STUDENTS\n\n\t\tPRESS (4) TO ASSIGN GRADES TO STUDENTS\n\n\t\tPRESS (5) TO LOG OUT\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
					cin >> subOption3;



					if (subOption3 == 1)
					{
						system("cls");
						teachers[thisTeaInd].getTT().displayTimeTable();
						system("pause");
						system("cls");
					}



					else if (subOption3 == 2)
					{

						system("cls");

						if (students->getCount() == 0)
						{
							cout << "\nNO STUDENT RECORD FOUND!";


						}

						else
						{
							int s = teachers->selectStudent(students);


							system("cls");
							teachers->assignMarks(students[s]);

						}
#
						cout << endl << endl;

						system("pause");

						system("cls");


					}


					else if (subOption3 == 3)
					{
						system("cls");

						if (students->getCount() == 0)
						{
							cout << "\nNO STUDENT RECORD FOUND!";


						}

						else
						{
							int s = teachers->selectStudent(students);


							teachers->markAttendance(students[s]);
							system("cls");


							students[s].getAttendance().displayAttendance(students[s]);

						}

						cout << endl << endl;

						system("pause");

						system("cls");

					}


					else if (subOption3 == 4)
					{

						system("cls");

						if (students->getCount() == 0)
						{
							cout << "\nNO STUDENT RECORD FOUND!";


						}

						else
						{
							int s = teachers->selectStudent(students);

							system("cls");
							teachers->assignGrade(students[s]);

						}

						cout << endl << endl;

						system("pause");

						system("cls");


					}


					else if (subOption3 == 5)
					{
						logOut = true;
						cout << "\n'" << tempUser2 << "' LOGGED OUT SUCCESSFULLY!" << endl << endl;
						system("pause");
					}

					else
					{
						cout << "\n\tINVALID INPUT!\n\n";
						system("pause");
						system("cls");
					}
				}
			}


			else if (option == 4)
			{

				int thishodInd = 0;

				tempUser3 = hods->signIn();

				thishodInd = hods->getHodIndex(hods, tempUser3);

				system("cls");

				int subOption4 = 0;
				bool logOut = false;

				if (tempUser3 == "null")
				{
					logOut = true;
				}

				while (logOut != true)
				{

					cout << "\tCHOOSE YOUR INTEREST FROM AMONG THE FOLLOWING: \n\n\t\tPRESS (1) TO REGISTER YOURSELF AS A TEACHER\n\n\t\tPRESS (2) TO VIEW ALL ACTIVITIES OF TEACHER MODULE\n\n\t\tPRESS (3) TO VIEW THE STUDENTS MODULE\n\n\t\tPRESS (4) TO VIEW ALL OF THE ENROLLED STUDENTS\n\n\t\tPRESS (5) TO VIEW ALL OF THE CURRENT FACULTY\n\n\t\tPRESS (6) TO LOG OUT\n\n\tENTER YOUR DESIRED OPTION NUMBER: ";
					cin >> subOption4;



					if (subOption4 == 1)
					{
						if (!hods[thishodInd].isTeacher())
						{
							hods[thishodInd].addTeachersFunctionality(teachers);

							cout << "\n\tTEACHER PROFILE HAS BEEN SET UP! \n\n\t";

						}

						else
						{
							system("cls");
							cout << "\n\tALREADY A FACULTY MEMBER! \n\n\t";
						}

						system("pause");
						system("cls");

					}


					else if (subOption4 == 2)
					{
						system("cls");
						hods->viewTeacherActivity(teachers);
						system("pause");
						system("cls");
					}


					else if (subOption4 == 3)
					{
						system("cls");
						hods->viewStudentModule(students);
						system("pause");
						system("cls");
					}


					else if (subOption4 == 4)
					{
						system("cls");
						admins->viewAllStudents(students, hods);
						cout << endl;
						system("pause");
						system("cls");

					}


					else if (subOption4 == 5)
					{
						system("cls");
						admins->viewAllTeachers(teachers, hods);
						cout << endl;
						system("pause");
						system("cls");
					}


					else if (subOption4 == 6)
					{
						logOut = true;
						cout << "\n'" << tempUser3 << "' LOGGED OUT SUCCESSFULLY!" << endl << endl;
						system("pause");
					}

					else
					{
						cout << "\n\tINVALID INPUT!\n\n";
						system("pause");
						system("cls");
					}
				}
			}

			if (user != "null" && tempUser != "null" && tempUser2 != "null" && tempUser3 != "null")
			{
				system("cls");
				cout << "DO YOU WANT TO END THE FLEX SYSTEM: " << endl << endl;
				cout << "\tENTER (1) TO END" << endl;
				cout << "\n\tENTER (0) TO CONTINUE";
				cout << endl << endl;
				cout << "ENTER YOUR OPTION: ";
				cin >> end;

			}

			system("cls");

			if (end == true)
			{
				cout << "\n\tTHANK YOU FOR USING FLEX 1.0!\n\n";
				system("pause");

			}
		}


	}

	return 0;
}
