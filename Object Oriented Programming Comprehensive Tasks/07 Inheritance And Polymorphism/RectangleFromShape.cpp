#include <iostream>
using namespace std;
//union temp { //defines the union
int a;
char b;
double c;
//
};
int main()
{
temp obj1; //decalares object
obj1.a = 65;
cout << obj1.a << " " << obj1.b << " " << obj1.c << endl; //displays the attributes of object
cout<<"SIZE OF UNION: "<<sizeof(temp)<<endl; //displays the size of the whole union object
//
obj1.b = 'A';
cout << obj1.a << " " << obj1.b << " " << obj1.c << endl; //displays the attributes of object
cout << "SIZE OF UNION: " << sizeof(temp) << endl; //displays the size of the whole union object
//
obj1.c = 97.5;
cout << obj1.a << " "<<obj1.b <<" "<< obj1.c<<endl; //displays the attributes of object
cout << "SIZE OF UNION: " << sizeof(temp) << endl; //displays the size of the whole union object
//
//
//	
return 0;
}
