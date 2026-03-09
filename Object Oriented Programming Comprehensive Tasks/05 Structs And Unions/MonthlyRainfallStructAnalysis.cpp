#include <iostream>
#include <string>
using namespace std;
int main()
{
string* ptrtext; //declares a string pointer
ptrtext = new string; //dynamically allocates the memory for ptrtext
cout << "Enter your text: "; 
//	getline(cin,*ptrtext); //takes input from user of string type
cout << *ptrtext; //diplays the input using pointer
//
//
return 0;
}
