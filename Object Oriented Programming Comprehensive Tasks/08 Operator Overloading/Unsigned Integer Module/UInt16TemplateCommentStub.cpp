#include <iostream>
#include "UInt16.h"
using namespace std;
//
//OP_STATUS UInt16::status = SUCCESS; //initially last arithematic operation is kept success
//
int main(int argc, char** argv)
{ 
//	
UInt16 a;
cout << "DEFAULT CONSTRUCTOR CALLED FOR A ";
cout<<endl<<endl;
//
UInt16 b(18);
cout << "PARAMETERISED CONSTRUCTOR CALLED FOR B TO SET B = 18"<<endl;
cout << "VALUE OF B: " << b.get();
cout<< endl << endl;
//
//
cout << "AFTER USING COPY CONSTRUCTOR TO COPY VALUE OF A INTO C: "<<endl;
UInt16 c(a);
cout << "VALUE OF A: " << a.get()<<endl;
cout << "VALUE OF C: " << c.get();
cout << endl << endl;
//
cout << "AFTER USING ASSIGNMENT TO COPY VALUE OF B INTO C: " << endl;
//	c.assignment(b);
cout << "VALUE OF B: " << a.get() << endl;
cout << "VALUE OF C: " << c.get();
cout << endl << endl;
//
cout << "AFTER CALLING SETTER OF THE CLASS TO SET A = 10 " << endl;
//	a.set(10);
cout << "VALUE OF A: " << a.get();
cout << endl << endl;
//
cout << "CALLING CHECK STATUS TO CHECK THE STATUS OF THE LAST ARITHEMATIC FUNCTION PERFORMED: "<<endl;
cout << "THE STATUS IS: ";
//
	for(int i = 0; i < 7; i++)
	{
		cout << a.checkStatus()[i]; //displays each character of either 'SUCCESS' or 'FAILURE'
	}
//	
cout << endl << endl;
//
cout << "SIZE OF THE OPERATIONS IS: " << a.size();
cout << endl << endl;
//
//	/* We can call a different arithmetic operation */
//
cout << "PERFORMING ADDITION OF A AND B: "<<endl;
c = b.add(a);
cout << "VALUE OF A: " << a.get()<<endl;
cout << "VALUE OF B: " << b.get()<<endl;
cout << "b + a = ";	
cout << c.get() << " ";
cout << endl << endl;
//
cout << "PERFORMING SUBTRACTION OF A AND B: " << endl;
c = b.sub(a);
cout << "VALUE OF A: " << a.get() << endl;
cout << "VALUE OF B: " << b.get() << endl;
cout << "b - a  = ";
cout<<c.get()<<" ";
cout << endl << endl;
//
cout << "PERFORMING MULTIPLICATION OF A AND B: " << endl;
c = b.mup(a);
cout << "VALUE OF A: " << a.get() << endl;
cout << "VALUE OF B: " << b.get() << endl;
cout << "b * a = ";
cout << c.get() << " ";
cout << endl << endl;
//
cout << "PERFORMING DIVISION OF A AND B: " << endl;
c = b.div(a);
cout << "VALUE OF A: " << a.get() << endl;
cout << "VALUE OF B: " << b.get() << endl;
cout << "b / a = ";
cout << c.get() << " (answer is not a float value as the calculation is being performed for the unsigned 'int')";
cout << endl << endl;
//	
//
return 0;
}

