#include<iostream>
using namespace std;
class stud {
private:
int a;
int b;
int c;
public:
void set(int a, int b, int c)
{
//		(*this).a = a;
//		(*this).b = b;
//		(*this).c = c;
}
void get()
{
	cout<<a<<"\t"<<b<<"\t"<<c;
	cout << endl;
}
};
int main()
{
stud s1;
//	s1.set(5, 6, 7);
//	s1.get();
//	system("pause");
return 0;
}
