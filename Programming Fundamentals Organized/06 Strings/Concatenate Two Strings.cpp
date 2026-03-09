#include <iostream>
#include <string>
using namespace std;
int main()
{
string a, b;
int sizea, sizeb=0;
cout << "enter string 1: ";
getline(cin, a);
cout << "enter string 2: ";
getline(cin, b);
sizea = a.length();
sizeb = b.length();
//	
//
a = a + ' ' + b;
cout << a;
//
//
}
