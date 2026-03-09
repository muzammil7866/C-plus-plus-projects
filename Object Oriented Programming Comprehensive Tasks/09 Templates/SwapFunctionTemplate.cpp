#include <iostream>
using namespace std;
//
template <typename T>
//
void SWAP(T& a, T& b) 
{
T temp = a;
a = b;
b = temp;
}
int main()
{
int a=1, b=0;
//
float c=4.5, d=8.1;
//	
char e = 'A', f = 'V';
//
cout << "PREVIOUS VALUES: \n";
cout << "A: "<< a << " B: "<< b;
cout << endl;
//	
cout << "C: "<< c << " D: " << d;
cout << endl;
//	
cout << "E: "<< e << " F: " << f;
cout << endl;
//
//	SWAP(a, b);
//	SWAP(c, d);
//	SWAP(e, f);
//
//	
cout << "AFTER VALUES: \n";
cout << "A: " << a << " B: " << b;
cout << endl;
//	
cout << "C: " << c << " D: " << d;
cout << endl;
//	
cout << "E: " << e << " F: " << f;
cout << endl;
//	
return 0;
}
