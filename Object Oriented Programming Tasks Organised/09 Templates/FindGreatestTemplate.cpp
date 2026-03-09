#include <iostream>
using namespace std;
//
template <typename T>
//
T FindGreatest(T& a, T& b, T&c, T&d) 
{
if (a > b && a > c && a > d)
	return a;
//	
else if (b > a && b > c && b > d)
	return b;
//	
else if (c > a && c > b && c > d)
	return c;
//	
else
	return d;
}
int main()
{
int a=2, b=5, c=1, d=8;
float e = 87.2, f = 11.2, g = 43.4, h = 33.7;
//
int temp = FindGreatest(a, b, c, d);
cout << "LARGEST: "<< temp << endl;
//	
float temp2 = FindGreatest(e, f, g, h);
cout << "LARGEST: " << temp2 << endl;
//
return 0;
}
