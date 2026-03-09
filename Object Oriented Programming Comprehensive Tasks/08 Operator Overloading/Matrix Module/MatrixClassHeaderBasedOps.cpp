#include <iostream>
#include"Matrix.h"
using namespace std;


int main()
{
	Matrix obj1;
	obj1.setRandC(3,3);

	obj1.setMatrix();
	

	-obj1;
	obj1.displayMatrix();
return 0;
}
