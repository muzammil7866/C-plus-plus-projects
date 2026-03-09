#include <iostream>
#include<string>
using namespace std;

class academics
{
public:
int warningCount;

academics()
{
	warningCount = 0;
}

void setWarning() //setter 
{
	cout << "ENTER THE ACADEMIC WARNING COUNT OF THE STUDENT: ";
	cin >> warningCount;
}

int getWarning() //getter
{
	return warningCount;
}
};

class DC_COMMITTEE 
{
public:
string name;
int rollNo;
int batch;
string degree;
string imposedBy;
bool guilty;
academics* obj1; //object of academics to portray aggregation
string matter;

DC_COMMITTEE()
{
	name = "\0";
	rollNo = 0;
	batch = 0;
	degree = "\0";
	imposedBy = "\0";
	guilty = false; //initially the student is not guilty
	obj1 = NULL; //initially the pointer is kept NULL
	matter = "\0";
}

void accessAcademicRecord() //gives the memory address from heap to the pointer
{
	obj1 = new academics; //dma initialising
	obj1->setWarning(); //sets the warning
	cout<<"ACADEMIC WARNING COUNT OF THE STUDENT: " << obj1->getWarning()<<endl; //prints the warning count
}

//
void removeAcademicRecord()
{
	delete obj1; //deallocates the memory from heap
	obj1 = NULL; //makes the pointer point to NULL

}
void generateReport() //prints out the values of members
{
	cout << endl << endl << endl;
	cout << "***************FINAL REPORT***************" << endl;
	cout<<"NAME: "<<name<<endl;
	cout<<"ROLL NO: "<<rollNo << endl;
	cout<<"BATCH: "<<batch << endl;
	cout<<"DEGREE: "<<degree << endl;
	cout<<"IMPOSER NAME: "<<imposedBy << endl;
	if (guilty == 0) //if guilty is false
	{
		cout << "DC IMPOSED WAS INVALID AND THE STUDENT IS NOT GUILTY OF ANY MISCONVENIENCE.";
	}
//
	else //if guilty is true
	{
		cout << "DC IMPOSED WAS VALID AND THE STUDENT IS GUILTY. DUE TO THIS HE WOULD BE TEMPORARILY STUCK OFF FOR 3 MONTHS. ";
	}
//	
}
void setStudent() //sets the values of members
{
	cout << "\tENTER THE NAME OF THE STUDENT : ";
	cin >> name;
	cout << "\tENTER THE ROLL NO. OF THE STUDENT: ";
	cin >> rollNo;
	cout << "\tENTER THE BATCH OF THE STUDENT: ";
	cin >> batch;
	cout << "\tENTER THE DEGREE OF THE STUDENT: BS - ";
	cin >> degree;
	cout << "\tENTER THE NAME OF THE TEACHER/SUPERVISOR IMPOSING THE DC: ";
	cin>>imposedBy;
	cout << "\tENTER BRIEF REASON FOR THE DC: ";
	cin >> matter;
}

bool dcSupervisionbyHOD() //finalises the decision of DC
{
	int temp; //temporary varaible
	cout << "DO YOU WANT TO ADD THE ACADEMIC RECORD OF THE STUDENT IN DETERMINING THE DC " << endl << "\t(ENTER 0 FOR IGNORING)" << endl << "\t(ENTER 1 FOR CONSIDERING) : ";
	cin >> temp; //inputs temp
	if (temp == 1) //if the user wants to access the academic record then its corresponding function is called
	{
		accessAcademicRecord();
	}

	bool dcvalid;
	cout << "ENTER THE DECISION OF THE HOD "<<endl<<"\t(ENTER 0 FOR INVALID DC)"<<endl<<"\t(ENTER 1 FOR VALID DC) : ";
	cin >> dcvalid;

	if (dcvalid == true)
		guilty = true;

	else
		guilty = false;

	return guilty; //returns the value of guilty to determine the decison
}

~DC_COMMITTEE()
{
	if (obj1 != NULL)
	{
		delete obj1;
		obj1 = NULL;
	}
}
};

int main()
{
DC_COMMITTEE student1; //object declaration

cout << "*********************DISCIPLINARY COMMITTEE*********************" << endl << endl;
cout << "ENTER THE DETAILS OF THE STUDENT TO IMPOSE A DC REGARDING SOME MATTER: "<<endl<<endl;
student1.setStudent(); //setter
student1.dcSupervisionbyHOD(); //processes the DC decision
student1.generateReport(); //generates the report

return 0;
}
