#include <iostream>
using namespace std;
class Number
{
private:
int num; //members
//
public:
//	Number(int n) //constructor to initialise the member
{
	num = n;
}
//
//	Number operator+(Number n) //operator overloading of + by passing a parameter
{
	return Number(num + n.num); //adds the num of the parameter followed by the function call and the num with which it is called. Then it returns the sum.
}
//
void display()
{
	cout << num << endl; //prints num
}
};
int main()
{
Number a(5), b(10); //declares and initialises a and b
Number c = a + b; //operator overloading done by calling the function of +
//	c.display(); //displays the value of sum = 15
return 0;
}
