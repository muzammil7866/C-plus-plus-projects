#include<iostream>
#include<string>
using namespace std;
template <typename A, typename B, typename C>
class Record
{
	//data members
	string name;
	int age;
	double salary;

public:

	Record(A a, B b, C c) //parameterised constructor
	{
		name = a;
		age = b;
		salary = c;
	}
	void output() //for outputting
	{
		cout << "\t\tDETAILS OF USER: " << endl;
		cout << name << endl;
		cout << age << endl;
		cout << salary << endl;

	}

};
int main()
{

	Record<string, int, int > student1("Muzammil", 21, 250000); //object declared using template argument list
	student1.output(); //to output





	system("pause");


	return 0;
}
