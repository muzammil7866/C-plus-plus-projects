#include<iostream>
using namespace std;
class stud {
private:
const int a = 10;
int b;
const int c=20;
public:
//	stud() 
{	
	b = 10;
};
//
int geta()const
{
	return a;
}
int getb()
{
	return b;
}
int getc()const
{
	return c;
}
void set(int b, int c)
{
	b = b;
	c = c;
}
void get()
{
	cout << a << "\t" << b << "\t" << c;
}
};
//
int main()
{
stud s2;
//	s2.set(6, 7);
//	s2.get();
cout << endl;
cout<<"A: "<<s2.geta()<<"\t"<< "B: " << s2.getb() <<"\t"<< "C : " << s2.getc();
cout << endl;
//
//
//	system("pause");
return 0;
}
