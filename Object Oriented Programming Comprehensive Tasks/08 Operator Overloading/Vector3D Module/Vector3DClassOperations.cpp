#include <iostream>
#include "Vector3D.h"
using namespace std;

//constructor
Vector3D::Vector3D()
{
	//memory assigned from heap using DMA
	p = new double[3]; //3 coordinates (x,y,z) in vector
	q = new double[3]; 

	for (int i = 0; i < 3; i++)
	{
		p[i] = 0;
		q[i] = 0;
	}
}

//parameterised constructor to assign values on declaration
Vector3D::Vector3D(double* a, double* b, int size)
{
	p = a;
	q = b;
}

//copy constructor copies the contents of the object passed into the object for which constructor is called
Vector3D::Vector3D(Vector3D& a)
{
	p = a.p;
	q = a.q;
}

////destructor to deallocate memory of heap
//Vector3D::~Vector3D()
{
//	delete[] p;
//	delete[] q;
}

//addition overloading
Vector3D Vector3D::operator + (Vector3D a)
{
	double vecA[3] = { 0,0,0 };
	double vecB[3] = { 0,0,0 };

	//calculates the specific matrix represented by the starting and destination point
	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
		vecB[i] = a.q[i] - a.p[i];
	}

	//resultant vector
	Vector3D res;

	//matrices addition performed coordinate by coordinate
	for (int i = 0; i < 3; i++)
	{
		res.p[i] = 0;
		res.q[i] = vecA[i] + vecB[i];

	}

	//resultant vector returned
	return res;
}

//subtraction overloading
Vector3D Vector3D::operator - (Vector3D a)
{
	double vecA[3] = { 0,0,0 };
	double vecB[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
		vecB[i] = a.q[i] - a.p[i];
	}

	Vector3D res;

	//subtraction performed coordinate by coordinate
	for (int i = 0; i < 3; i++)
	{
		res.p[i] = 0;
		res.q[i] = vecA[i] - vecB[i];

	}


	return res;
}

//dot product usng asterik overloading
double Vector3D::operator * (Vector3D a)
{
	double vecA[3] = { 0,0,0 };
	double vecB[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
		vecB[i] = a.q[i] - a.p[i];
	}

	
	double dot = 0;
//performs dot prouct 
	for (int i = 0; i < 3; i++)
	{
		dot = dot + (vecA[i] * vecB[i]);
	}

	return dot;
}

//cross product using mod overloading
Vector3D Vector3D::operator % (Vector3D a)
{
	double vecA[3] = { 0,0,0 };
	double vecB[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
		vecB[i] = a.q[i] - a.p[i];
	}

	Vector3D cross;

	for (int i = 0; i < 3; i++)
	{
		p[i] = 0;
	}
	//code for finding the cross product

	cross.q[0] = vecA[1] * vecB[2] - vecA[2] * vecB[1];
	cross.q[1] = -1 * (vecA[0] * vecB[2] - vecA[2] * vecB[0]);
	cross.q[2] = vecA[0] * vecB[1] - vecA[1] * vecB[0];

	return cross;
}

//prefix increment overloading
void Vector3D::operator ++ ()
{
	double vecA[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
	}

	
	for (int i = 0; i < 3; i++)
	{
		vecA[i]++; //increments in each element
		this->p[i] = 0;
		this->q[i] = vecA[i];  //destination point equals the incremented value
	}


}

//postfix increment overloading
void Vector3D::operator ++ (int a)
{
	double vecA[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
	}

	
	for (int i = 0; i < 3; i++)
	{
		vecA[i]++; //increments in each element
		this->p[i] = 0;
		this->q[i] = vecA[i];  //destination point equals the incremented value
	}


}
//prefix decrement overloading
void Vector3D::operator -- ()
{
	double vecA[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
	}

	for (int i = 0; i < 3; i++)
	{
		vecA[i]--; //decrements in each element
		this->p[i] = 0;
		this->q[i] = vecA[i]; //destination point equals the decremented value
	}
}

//postfix decrement overloading
void Vector3D::operator -- (int a)
{
	double vecA[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++)
	{
		vecA[i] = q[i] - p[i];
	}

	for (int i = 0; i < 3; i++)
	{
		vecA[i]--; //decrements in each element
		this->p[i] = 0;
		this->q[i] = vecA[i]; //destination point equals the decremented value
	}
}

//setter source point
void Vector3D::setSource(double a, double b, double c)
{
	p[0] = a;
	p[1] = b;
	p[2] = c;
}

//set destination point
void Vector3D::setDest(double a, double b, double c)
{
	q[0] = a;
	q[1] = b;
	q[2] = c;
}

//getter of source point
double* Vector3D::getSource()
{
	cout << "\tSOURCE POINT OF VECTOR IS: \n\t[" << p[0] << ", " << p[1] << ", " << p[2] << "]";
	cout << endl;
	cout << endl;

	return p;
}

//getter of destination point
double* Vector3D::getDest()
{
	cout << "\tDESTINATION POINT OF VECTOR IS: \n\t[" << q[0] << ", " << q[1] << ", " << q[2] << "]";
	cout << endl;


	return q;
}

