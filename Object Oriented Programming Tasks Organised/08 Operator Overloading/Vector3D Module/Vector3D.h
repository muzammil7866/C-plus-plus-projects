#include <iostream>
using namespace std;
class Vector3D
{
public:
	
	double* p; //source point
	double* q; //destination point

	
	Vector3D(); //constructor
	Vector3D(double* a, double* b, int size); //parameterised constructor
	Vector3D(Vector3D& a); //copy constructor
	//~Vector3D(); //destructor
	Vector3D operator + (Vector3D a); //overloading + for adding
	Vector3D operator - (Vector3D a); //overloading - for subtracting
	double operator * (Vector3D a); //overloading * for dot product
	Vector3D operator % (Vector3D a); //overloading % for cross product
	void operator ++ (); //overloading ++ for prefix increment
	void operator ++ (int a); //overloading ++ for postfix increment
	void operator -- (); //overloading -- for prefix decrement
	void operator -- (int a); //overloading -- for postfix overloading
	void setSource(double a, double b, double c); //setter source point
	void setDest(double a, double b, double c); //setter destination point
	double* getSource(); //getter source point
	double* getDest(); //getter destination point

};