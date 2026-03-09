#include <iostream>
using namespace std;
template <typename T>
class Calculator
{
public:
T obj;
T obj2;
//
T add()
{
	return obj + obj2;
}
//
T sub()
{
	return obj - obj2;
}
//
T mup()
{
	return obj * obj2;
}
//
T div()
{
	return obj / obj2;
}
//
T Avg()
{
	return (obj + obj2) / 2;
}
};
int main()
{
Calculator<int> a;
a.obj = 5;
a.obj2 = 7;
//
cout<<"ADDITION IS: "<<a.add();
cout << endl;
cout << "SUBTRACTION IS: " << a.sub();
cout << endl;
cout << "MULTIPLICATION IS: " << a.mup();
cout << endl;
cout << "DIVISION IS: " << a.div();
cout << endl;
cout << "AVERAGE IS: " << a.Avg();
//
//
return 0;	
}
