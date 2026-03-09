#include <iostream>
#include <string>
using namespace std;
class Student {
public:
	int id;
	string name;
	void insert(int i, string n) //initialises the attributes for the object it is called
	{
		id = i;
		name = n;
//
	 }
   void display() //displays the attributes for the object it is called
	{
	   cout << id<<" "; 
	   cout << name;
	   cout << endl;
		  }
};
//
int main(void) 
{
Student s1;
Student s2;
//	s1.insert(201, "Sonoo"); //calls function for the object to initialise attributes
//	s2.insert(405, "Batman"); //calls function for the object 2 to initialise attributes
//	s1.display(); //calls function for the object to display attributes
//	s2.display(); //calls function for the object 2 to display attributes
//	
//	
return 0;
}
