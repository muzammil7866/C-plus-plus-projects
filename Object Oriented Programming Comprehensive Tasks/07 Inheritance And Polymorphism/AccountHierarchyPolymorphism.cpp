#include <iostream>
using namespace std;
class Account
{
//
public:
float balance;
int inc;
//		
//	Account()
{
	balance = 10000;
	inc = 0;
//
}
//
void annualInc()
{
//		
}
//
void zakatDeduc()
{
	balance = balance - (0.025 * balance);
	cout << "BALANCE AFTER ZAKAT DEDUCTION IS: " << balance;
//
}
};
//
class Current : public Account
{
//
};
//
class Savings : public Account
{
public:
void annualInc()
{
	inc = 5;
	balance = balance * 1.05;
	cout << "BALANCE AFTER ANNUAL INCREMENT IS: " << balance;
}
//
};
//
int main()
{
Current obj;
//	obj.zakatDeduc();
cout << endl;
//	obj.annualInc();
//
Savings obj2;
//	obj2.annualInc();
//
return 0;	
}
