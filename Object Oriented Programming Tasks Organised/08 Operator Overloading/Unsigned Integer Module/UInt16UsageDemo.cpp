#include<iostream>
#include"Task 3.h"
using namespace std;

OP_STATUS UInt::status = SUCCESS;

int main()
{
	UInt16 a;
		cout << "DEFAULT CONSTRUCTOR CALLED FOR A ";
		cout<<endl<<endl;
	
		UInt16 b(18);
		cout << "PARAMETERISED CONSTRUCTOR CALLED FOR B TO SET B = 18"<<endl;
		cout << "VALUE OF B: " << b.get();
		cout<< endl << endl;
	

		cout << "AFTER USING COPY CONSTRUCTOR TO COPY VALUE OF A INTO C: "<<endl;
		UInt16 c(a);
		cout << "VALUE OF A: " << a.get()<<endl;
		cout << "VALUE OF C: " << c.get();
		cout << endl << endl;

		cout << "AFTER USING ASSIGNMENT TO COPY VALUE OF B INTO C: " << endl;
		c = b;
		cout << "VALUE OF B: " << a.get() << endl;
		cout << "VALUE OF C: " << c.get();
		cout << endl << endl;
 
 

		cout << "AFTER CALLING SETTER OF THE CLASS TO SET A = 10 " << endl;
		a.set(10);
		cout << "VALUE OF A: " << a.get();
		cout << endl << endl;
	
		cout << "CALLING CHECK STATUS TO CHECK THE STATUS OF THE LAST ARITHEMATIC FUNCTION PERFORMED: "<<endl;
		cout << "THE STATUS IS: ";
			for(int i = 0; i < 7; i++)
			{
				cout << a.checkStatus()[i];
			}
		
		cout << endl << endl;
	
		cout << "SIZE OF THE OPERATIONS IS: " << a.size();
		cout << endl << endl;
	
		/* We can call a different arithmetic operation */
	
		cout << "PERFORMING ADDITION USING OPERATOR OVERLOADING OF A AND B: "<<endl;
		c = b + a;
		cout << "VALUE OF A: " << a.get()<<endl;
		cout << "VALUE OF B: " << b.get()<<endl;
		cout << "b + a = ";	
		cout << c.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING SUBTRACTION USING OPERATOR OVERLOADING OF A AND B: " << endl;
		c = b - a;
		cout << "VALUE OF A: " << a.get() << endl;
		cout << "VALUE OF B: " << b.get() << endl;
		cout << "b - a  = ";
		cout<<c.get()<<" ";
		cout << endl << endl;
	
		cout << "PERFORMING MULTIPLICATION USING OPERATOR OVERLOADING OF A AND B: " << endl;
		c = b * a;
		cout << "VALUE OF A: " << a.get() << endl;
		cout << "VALUE OF B: " << b.get() << endl;
		cout << "b * a = ";
		cout << c.get() << " ";
		cout << endl << endl;
	
		cout << "PERFORMING DIVISION USING OPERATOR OVERLOADING OF A AND B: " << endl;
		c = b / a;
		cout << "VALUE OF A: " << a.get() << endl;
		cout << "VALUE OF B: " << b.get() << endl;
		cout << "b / a = ";
		cout << c.get() << " (answer is not a float value as the calculation is being performed for the unsigned 'int')";
		cout << endl << endl;
	return 0;

}
