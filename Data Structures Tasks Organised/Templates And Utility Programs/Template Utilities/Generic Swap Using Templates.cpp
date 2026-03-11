#include <iostream>
using namespace std;

template <typename T> //defines template

void SWAP(T& a, T& b) //function performs swapping using template i.e. it takes the type of parameter that is passed to it
{
	T temp = a;
	a = b;
	b = temp;
}			       
int main()
{
			   
	cout << "\t\tSWAPPING USING TEMPLATE FUNCTION: ";
	cout << endl << endl;

	int a=1, b=0;
	float c=4.5, d=8.1;
	char e = 'A', f = 'V';

	cout << "PREVIOUS VALUES: \n";
	cout << "A: "<< a << " B: "<< b;
	cout << endl;
	
	cout << "C: "<< c << " D: " << d;
	cout << endl;
	
	cout << "E: "<< e << " F: " << f;
	cout << endl;

	SWAP(a, b); //int type parameters passed
	SWAP(c, d); //float type parameters passed
	SWAP(e, f); //char type parameters passed

	cout << endl << endl;
	cout << "AFTER VALUES: \n";
	cout << "A: " << a << " B: " << b;
	cout << endl;
	
	cout << "C: " << c << " D: " << d;
	cout << endl;
	
	cout << "E: " << e << " F: " << f;
	cout << endl;
	
	return 0;
}
