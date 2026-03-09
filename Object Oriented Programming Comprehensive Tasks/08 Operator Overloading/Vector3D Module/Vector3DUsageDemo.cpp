#include<iostream>
#include "Vector3D.h" //header file attached
using namespace std;


int main()
{
	Vector3D obj, obj2, obj3(obj); //object declaration

	//setters
	obj.setDest(2, -3, 1); 
	obj2.setDest(4, -1, 5);

	cout << "ORIGINAL MATRICES: " << endl;
	cout << endl;

	//original contents of matrix A
	cout << "MATRIX A: " << endl << endl;
	//getters
	obj.getSource();
	obj.getDest();

	//original contents of matrix B
	cout << endl;
	cout << "MATRIX B: " << endl << endl;
	obj2.getSource(); 
	obj2.getDest();
	cout << endl;

	//code for copy constuctor called on Matrix C to copy matrix A into it
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "(COPY CONSTRUCTOR CALLED TO COPY MATRIX A INTO MATRIX C)" << endl << endl;
	cout << "MATRIX C: " << endl;
	obj3.getSource();
	obj3.getDest();
	cout << endl;

	//addition
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "AFTER ADDITION OF BOTH MATRICES: " << endl << endl;
	obj3 = obj + obj2;
	obj3.getSource();
	obj3.getDest();
	cout << endl;
	
	//resetting the original matrices
	obj.setDest(2, -3, 1);
	obj2.setDest(4, -1, 5);

	//subtraction
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "AFTER SUBTRACTION OF BOTH MATRICES: " << endl << endl;
	obj3 = obj - obj2;
	obj3.getSource();
	obj3.getDest();
	cout << endl;

	obj.setDest(2, -3, 1);
	obj2.setDest(4, -1, 5);

	//dot products
	double temp = obj * obj2;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "THE DOT PRODUCT OF BOTH MATRICES IS: \n\t" << temp << endl << endl;
	cout << endl;

	//cross product
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "AFTER CROSS PRODUCT OF BOTH MATRICES: " << endl << endl;
	obj3 = obj % obj2;
	obj3.getSource();
	obj3.getDest();
	cout << endl;


	obj.setDest(2, -3, 1);
	obj2.setDest(4, -1, 5);

	//incrementing in matrix using prefix operator
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "AFTER INCREMENTING MATRIX A USING PREFIX OPERATOR: " << endl << endl;
	
	//displays original matrix
	cout << "ORIGINAL: " << endl;
	obj.getSource();
	obj.getDest();

	
	//displays modified matrix
	cout << "AFTER: " << endl;
	++obj;
	obj.getSource();
	obj.getDest();
	cout << endl;

	obj.setDest(2, -3, 1);
	obj2.setDest(4, -1, 5);

	//incrementing in matrix using postfix operator
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "AFTER INCREMENTING MATRIX A USING POSTFIX OPERATOR: " << endl << endl;

	//displays original matrix
	cout << "ORIGINAL: " << endl;
	obj.getSource();
	obj.getDest();


	//displays modified matrix
	cout << "AFTER: " << endl;
	obj++;
	obj.getSource();
	obj.getDest();
	cout << endl;

	obj.setDest(2, -3, 1);
	obj2.setDest(4, -1, 5);

	//decrementing in matrix using prefix operator
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "AFTER DECREMENTING MATRIX B USING PREFIX OPERATOR: " << endl << endl;

	//displays original matrix
	cout << "ORIGINAL: " << endl;
	obj2.getSource();
	obj2.getDest();


	//displays modified matrix
	cout << "AFTER: " << endl;
	--obj2;
	obj2.getSource();
	obj2.getDest();
	cout << endl;

	obj.setDest(2, -3, 1);
	obj2.setDest(4, -1, 5);

	//decrementing in matrix using postfix operator
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "AFTER DECREMENTING MATRIX B USING POSTFIX OPERATOR: " << endl << endl;
	cout << "ORIGINAL: " << endl;
	obj2.getSource();
	obj2.getDest();

	cout << "AFTER: " << endl;
	obj2--;
	obj2.getSource();
	obj2.getDest();
	cout << endl;



	return 0;
}

