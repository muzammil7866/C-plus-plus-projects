#include<iostream>
#include<iomanip>
using namespace std;
double* momentum1(double* velocity, double mass);
double* randVec();
int main()
{
//	srand(time(0));
//
double momentum[1000][3];
//
for (int i = 0; i < 1000; i++)
{
	double* ptr = randVec();
	double mass = 1 + rand() % 10;
	double* ptr2 = momentum1(ptr, mass);
	cout << "Components of vector " << i + 1<<": "<<endl;
	for (int j = 0; j < 3; j++)
	{
//			*(*(momentum + i) + j) = *(ptr2+j);
		cout << *(*(momentum + i) + j)<<" "<<setw(3);
//
	}
	cout << endl;
}
//
double avg1 = 0, avg2 = 0, avg3 = 0;
for (int i = 0; i < 1000; i++)
{
//		
	for (int j = 0; j < 3; j++)
	{
		avg1 = avg1 + *(*(momentum + i) + 0);
		avg2 = avg2 + *(*(momentum + i) + 1);
		avg3 = avg3 + *(*(momentum + i) + 2);
	}
//
}
cout << endl<<endl<<endl;
cout << "**********Components of the average momentum vector of 1000 vectors: *********"<< endl;
cout <<"x= "<<avg1 / 1000<<endl;
cout <<"y= " << avg2 / 1000<<endl;
cout <<"z= " << avg3 / 1000<<endl;
return 0;
}
double* randVec()
{
//	double *array = new double[3];
//	
for (int i = 0; i < 3; i++)
{
//		*(array+i) =  - 100 + rand() % 200 + 1;
}
//
return array;
//
//
}
double* momentum1(double* velocity, double mass)
{
//	double m1, m2, m3;
m1 = *(velocity)*mass;
m2 = *(velocity + 1) * mass;
m3 = *(velocity + 2) * mass;
//
//	//cout<<endl;
///*	cout << "Momentum due to x = " << m1 << endl;
cout << "Momentum due to y = " << m2 << endl;
cout << "Momentum due to z = " << m3 << endl;
//	*/
double* momentumm = new double[3];
//	*(momentumm) = m1;
//	*(momentumm + 1) = m2;
//	*(momentumm + 2) = m3;
//
return momentumm;
//
}
