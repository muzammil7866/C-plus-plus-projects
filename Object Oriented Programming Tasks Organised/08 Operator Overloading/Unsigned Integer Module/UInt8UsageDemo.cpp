#include<iostream>
#include "Task 2.h"

using namespace std;

OP_STATUS UInt::status = SUCCESS;

int main()
{
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "THE CASE OF UNSIGNED INTEGER 8: " << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
	UInt8 a8;
		cout << "DEFAULT CONSTRUCTOR CALLED FOR A ";
		cout<<endl<<endl;
	
		UInt8 b8(18);
		cout << "PARAMETERISED CONSTRUCTOR CALLED FOR B TO SET B = 18"<<endl;
		cout << "VALUE OF B: " << b8.get();
		cout<< endl << endl;
	
	
		cout << "AFTER USING COPY CONSTRUCTOR TO COPY VALUE OF A INTO C: "<<endl;
		UInt8 c8(a8);
		cout << "VALUE OF A: " << a8.get()<<endl;
		cout << "VALUE OF C: " << c8.get();
		cout << endl << endl;

		cout << "AFTER USING ASSIGNMENT TO COPY VALUE OF B INTO C: " << endl;
		c8.assignment(b8);
		cout << "VALUE OF B: " << a8.get() << endl;
		cout << "VALUE OF C: " << c8.get();
		cout << endl << endl;

		cout << "AFTER CALLING SETTER OF THE CLASS TO SET A = 10 " << endl;
		a8.set(10);
		cout << "VALUE OF A: " << a8.get();
		cout << endl << endl;
	
		cout << "CALLING CHECK STATUS TO CHECK THE STATUS OF THE LAST ARITHEMATIC FUNCTION PERFORMED: "<<endl;
		cout << "THE STATUS IS: ";
			for(int i = 0; i < 7; i++)
			{
				cout << a8.checkStatus()[i];
			}
		
		cout << endl << endl;
	
		cout << "SIZE OF THE OPERATIONS IS: " << a8.size();
		cout << endl << endl;
	
		/* We can call a different arithmetic operation */
	
		cout << "PERFORMING ADDITION OF A AND B: "<<endl;
		c8 = b8.add(a8);
		cout << "VALUE OF A: " << a8.get()<<endl;
		cout << "VALUE OF B: " << b8.get()<<endl;
		cout << "b + a = ";	
		cout << c8.get() << " ";
		cout << endl << endl;
	
		cout << "PERFORMING SUBTRACTION OF A AND B: " << endl;
		c8 = b8.sub(a8);
		cout << "VALUE OF A: " << a8.get() << endl;
		cout << "VALUE OF B: " << b8.get() << endl;
		cout << "b - a  = ";
		cout<<c8.get()<<" ";
		cout << endl << endl;
	
		cout << "PERFORMING MULTIPLICATION OF A AND B: " << endl;
		c8 = b8.mup(a8);
		cout << "VALUE OF A: " << a8.get() << endl;
		cout << "VALUE OF B: " << b8.get() << endl;
		cout << "b * a = ";
		cout << c8.get() << " ";
		cout << endl << endl;
	
		cout << "PERFORMING DIVISION OF A AND B: " << endl;
		c8 = b8.div(a8);
		cout << "VALUE OF A: " << a8.get() << endl;
		cout << "VALUE OF B: " << b8.get() << endl;
		cout << "b / a = ";
		cout << c8.get() << " (answer is not a float value as the calculation is being performed for the unsigned 'int')";
		cout << endl << endl;

		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "THE CASE OF UNSIGNED INTEGER 16: " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		UInt16 a16;
		cout << "DEFAULT CONSTRUCTOR CALLED FOR A ";
		cout << endl << endl;

		UInt16 b16(18);
		cout << "PARAMETERISED CONSTRUCTOR CALLED FOR B TO SET B = 18" << endl;
		cout << "VALUE OF B: " << b16.get();
		cout << endl << endl;


		cout << "AFTER USING COPY CONSTRUCTOR TO COPY VALUE OF A INTO C: " << endl;
		UInt16 c16(a16);
		cout << "VALUE OF A: " << a16.get() << endl;
		cout << "VALUE OF C: " << c16.get();
		cout << endl << endl;

		cout << "AFTER USING ASSIGNMENT TO COPY VALUE OF B INTO C: " << endl;
		c16.assignment(b16);
		cout << "VALUE OF B: " << a16.get() << endl;
		cout << "VALUE OF C: " << c16.get();
		cout << endl << endl;

		cout << "AFTER CALLING SETTER OF THE CLASS TO SET A = 10 " << endl;
		a16.set(10);
		cout << "VALUE OF A: " << a16.get();
		cout << endl << endl;

		cout << "CALLING CHECK STATUS TO CHECK THE STATUS OF THE LAST ARITHEMATIC FUNCTION PERFORMED: " << endl;
		cout << "THE STATUS IS: ";
		for (int i = 0; i < 7; i++)
		{
			cout << a16.checkStatus()[i];
		}

		cout << endl << endl;

		cout << "SIZE OF THE OPERATIONS IS: " << a16.size();
		cout << endl << endl;

		/* We can call a different arithmetic operation */

		cout << "PERFORMING ADDITION OF A AND B: " << endl;
		c16 = b16.add(a16);
		cout << "VALUE OF A: " << a16.get() << endl;
		cout << "VALUE OF B: " << b16.get() << endl;
		cout << "b + a = ";
		cout << c16.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING SUBTRACTION OF A AND B: " << endl;
		c16 = b16.sub(a16);
		cout << "VALUE OF A: " << a16.get() << endl;
		cout << "VALUE OF B: " << b16.get() << endl;
		cout << "b - a  = ";
		cout << c16.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING MULTIPLICATION OF A AND B: " << endl;
		c16 = b16.mup(a16);
		cout << "VALUE OF A: " << a16.get() << endl;
		cout << "VALUE OF B: " << b16.get() << endl;
		cout << "b * a = ";
		cout << c16.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING DIVISION OF A AND B: " << endl;
		c16 = b16.div(a16);
		cout << "VALUE OF A: " << a16.get() << endl;
		cout << "VALUE OF B: " << b16.get() << endl;
		cout << "b / a = ";
		cout << c16.get() << " (answer is not a float value as the calculation is being performed for the unsigned 'int')";
		cout << endl << endl;

		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "THE CASE OF UNSIGNED INTEGER 24: " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		UInt24 a24;
		cout << "DEFAULT CONSTRUCTOR CALLED FOR A ";
		cout << endl << endl;

		UInt24 b24(18);
		cout << "PARAMETERISED CONSTRUCTOR CALLED FOR B TO SET B = 18" << endl;
		cout << "VALUE OF B: " << b24.get();
		cout << endl << endl;


		cout << "AFTER USING COPY CONSTRUCTOR TO COPY VALUE OF A INTO C: " << endl;
		UInt24 c24(a24);
		cout << "VALUE OF A: " << a24.get() << endl;
		cout << "VALUE OF C: " << c24.get();
		cout << endl << endl;

		cout << "AFTER USING ASSIGNMENT TO COPY VALUE OF B INTO C: " << endl;
		c24.assignment(b24);
		cout << "VALUE OF B: " << a24.get() << endl;
		cout << "VALUE OF C: " << c24.get();
		cout << endl << endl;

		cout << "AFTER CALLING SETTER OF THE CLASS TO SET A = 10 " << endl;
		a24.set(10);
		cout << "VALUE OF A: " << a24.get();
		cout << endl << endl;

		cout << "CALLING CHECK STATUS TO CHECK THE STATUS OF THE LAST ARITHEMATIC FUNCTION PERFORMED: " << endl;
		cout << "THE STATUS IS: ";
		for (int i = 0; i < 7; i++)
		{
			cout << a24.checkStatus()[i];
		}

		cout << endl << endl;

		cout << "SIZE OF THE OPERATIONS IS: " << a24.size();
		cout << endl << endl;

		/* We can call a different arithmetic operation */

		cout << "PERFORMING ADDITION OF A AND B: " << endl;
		c24 = b24.add(a24);
		cout << "VALUE OF A: " << a24.get() << endl;
		cout << "VALUE OF B: " << b24.get() << endl;
		cout << "b + a = ";
		cout << c24.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING SUBTRACTION OF A AND B: " << endl;
		c24 = b24.sub(a24);
		cout << "VALUE OF A: " << a24.get() << endl;
		cout << "VALUE OF B: " << b24.get() << endl;
		cout << "b - a  = ";
		cout << c24.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING MULTIPLICATION OF A AND B: " << endl;
		c24 = b24.mup(a24);
		cout << "VALUE OF A: " << a24.get() << endl;
		cout << "VALUE OF B: " << b24.get() << endl;
		cout << "b * a = ";
		cout << c24.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING DIVISION OF A AND B: " << endl;
		c24 = b24.div(a24);
		cout << "VALUE OF A: " << a24.get() << endl;
		cout << "VALUE OF B: " << b24.get() << endl;
		cout << "b / a = ";
		cout << c24.get() << " (answer is not a float value as the calculation is being performed for the unsigned 'int')";
		cout << endl << endl;

		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "THE CASE OF UNSIGNED INTEGER 32: " << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
		UInt32 a32;
		cout << "DEFAULT CONSTRUCTOR CALLED FOR A ";
		cout << endl << endl;

		UInt32 b32(18);
		cout << "PARAMETERISED CONSTRUCTOR CALLED FOR B TO SET B = 18" << endl;
		cout << "VALUE OF B: " << b32.get();
		cout << endl << endl;


		
		cout << "AFTER USING COPY CONSTRUCTOR TO COPY VALUE OF A INTO C: " << endl;
		UInt32 c32(a32);
		cout << "VALUE OF A: " << a32.get() << endl;
		cout << "VALUE OF C: " << c32.get();
		cout << endl << endl;

		cout << "AFTER USING ASSIGNMENT TO COPY VALUE OF B INTO C: " << endl;
		c32.assignment(b32);
		cout << "VALUE OF B: " << a32.get() << endl;
		cout << "VALUE OF C: " << c32.get();
		cout << endl << endl;


		cout << "AFTER CALLING SETTER OF THE CLASS TO SET A = 10 " << endl;
		a32.set(10);
		cout << "VALUE OF A: " << a32.get();
		cout << endl << endl;


		cout << "CALLING CHECK STATUS TO CHECK THE STATUS OF THE LAST ARITHEMATIC FUNCTION PERFORMED: " << endl;
		cout << "THE STATUS IS: ";
		for (int i = 0; i < 7; i++)
		{
			cout << a32.checkStatus()[i];
		}

		cout << endl << endl;

		cout << "SIZE OF THE OPERATIONS IS: " << a32.size();
		cout << endl << endl;

		/* We can call a different arithmetic operation */

		cout << "PERFORMING ADDITION OF A AND B: " << endl;
		c32 = b32.add(a32);
		cout << "VALUE OF A: " << a32.get() << endl;
		cout << "VALUE OF B: " << b32.get() << endl;
		cout << "b + a = ";
		cout << c32.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING SUBTRACTION OF A AND B: " << endl;
		c32 = b32.sub(a32);
		cout << "VALUE OF A: " << a32.get() << endl;
		cout << "VALUE OF B: " << b32.get() << endl;
		cout << "b - a  = ";
		cout << c32.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING MULTIPLICATION OF A AND B: " << endl;
		c32 = b32.mup(a32);
		cout << "VALUE OF A: " << a32.get() << endl;
		cout << "VALUE OF B: " << b32.get() << endl;
		cout << "b * a = ";
		cout << c32.get() << " ";
		cout << endl << endl;

		cout << "PERFORMING DIVISION OF A AND B: " << endl;
		c32 = b32.div(a32);
		cout << "VALUE OF A: " << a32.get() << endl;
		cout << "VALUE OF B: " << b32.get() << endl;
		cout << "b / a = ";
		cout << c32.get() << " (answer is not a float value as the calculation is being performed for the unsigned 'int')";
		cout << endl << endl;

	return 0;

}