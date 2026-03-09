#include <iostream>
using namespace std;
int main()
{
int x = 10.2, y = 20.8, z = 50.6;
	//following if statements checks the condition if it outputs true or false
if (z > 10)
	cout << "true" << endl;
else
	cout << "false"<<endl;
	
if ((x <= 5) || (y < 15))
	cout << "true" << endl;
else
	cout << "false" << endl;

if ((x != 5) && (x != z))
	cout << "true" << endl;
else
	cout << "false" << endl;

if ((z >= x) || (x + y >= z))
	cout << "true" << endl;
else
	cout << "false" << endl;

if ((x <= y - 20) && (y >= z * 2) || (z / 2 - 2 != 20))
	cout << "true" << endl;
else
	cout << "false" << endl;

return 0;
}
