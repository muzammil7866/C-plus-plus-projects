#include <iostream>
using namespace std;
class Base {
public:
 void print() {
	cout << "Base Function" << endl;
}
};
class Derived : public Base {
public:
void print() {
	cout << "Derived Function" << endl;
}
};
int main() {
Derived derived1;
Base* base1 = new Base;
//	derived1.print();
//	base1->print();
//	base1->print();
Base* base2 = new Base;
base2 = &derived1;
//	base2->print();
//	//Create two objects of base class and call base print fucntion with each and then derived with each
	return 0;
}
