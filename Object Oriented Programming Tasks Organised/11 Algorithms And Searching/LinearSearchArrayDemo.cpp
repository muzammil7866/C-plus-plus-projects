#include <iostream>
using namespace std;
class myClass
{
//	//member
int secret;
//
public:
//	//constructor
//	myClass()
{
	secret = 0;
//
}
//	
//	//prints the value of secret
void print()
{
	cout << "VALUE OF SECRET: ";
	cout << secret << endl;
}
//
//	//friend class declared
friend class secondClass;
//
};
//
class secondClass
{
public:
//	//function that updates the value of secret of another class
void changeSecret(myClass& obj) //takes object as parameter of foreign class
{
	int temp;
	cout << "ENTER THE VALUE OF SECRET: ";
	cin >> temp; //value of secret stored in temp
//
	obj.secret = temp; //value copied to the secret of object and thus updated
}
};
int main()
{
myClass obj1; //declares object
//	obj1.print(); //displays secret
secondClass obj2;//declares object of foreign class
//	obj2.changeSecret(obj1); //updates value of secret
//	obj1.print(); //displays secret
//
//
//
//
return 0;
}
