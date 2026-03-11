#include <iostream>
#include <fstream>
using namespace std;
class Node
{
public:
	int hours;
	string name;
	double wage;
	Node* next;

	Node()
	{
		hours = 0;
		name = "";
		wage = 0.0;
		next = nullptr;
	}

	double calculateWage()
	{
		return 50.0 * this->hours;
	}
};
class Employee
{
public:

	Node* head;

	Employee()
	{
		head = nullptr;

	}

	void append(Node* obj)
	{
		if (head == nullptr)
		{
			head = obj;
		}

		else
		{
			Node* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = obj;
		}
	}

	void printDetails()
	{
		if (head == nullptr)
		{
			cout << "HEAD -> NULLPTR";
		}

		else
		{
			Node* temp = head;
			cout << "HEAD -> ";
			while (temp != nullptr)
			{
				cout << temp->name << " " << temp->hours<<" "<<temp->wage<<" ->";
				temp = temp->next;
			}

			cout << " NULLPTR";
			
		}
	}
	



};
int main()
{
	ifstream inputFile;
	inputFile.open("Employees.txt.txt");

	if (!inputFile)
	{
		cout << "ERROR, UNABLE TO OPEN YOUR FILE";
		return 1;
	}

	else
	{
		string name;
		int hours;
		Employee* e1 = new Employee;
		while (!inputFile.eof())
		{
			inputFile >> name >> hours;
			Node* obj = new Node;
			obj->name = name;
			obj->hours = hours;
			obj->wage = obj->calculateWage();
			e1->append(obj);
			obj->next = nullptr;
		}

		e1->printDetails();

		ofstream outputFile;
		outputFile.open("Wages.txt.txt");

		if (!outputFile)
		{
			cout << "ERROR! UNABLE TO OPEN FILE";
		}

		Node* temp = e1->head;

		while (temp != nullptr)
		{
			outputFile << temp->name<<endl;
			outputFile << temp->wage<<endl;
			temp = temp->next;
		}

		cout << endl;
		cout << "DONE!";

	}
	



	return 0;	
}
