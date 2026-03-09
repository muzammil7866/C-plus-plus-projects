#include <iostream>
using namespace std;
class shape {
//
double width;
double height;
//
public:
//
void setterShape()
{
	cout << "Enter your width: " << endl;
	cin >> width;
	cout << "Enter your height: " << endl;
	cin >> height;
}
};
int main()
{
shape obj3;
//	obj3.setterShape();
//	
//
return 0;
}
