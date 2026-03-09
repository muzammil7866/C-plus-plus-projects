#include <iostream>
using namespace std;
class BankAccount
{
public:
float balance;
int AccNo;
float IntRate;

BankAccount(float a, int b, float c)
{
	balance = a;
	AccNo = b;
	IntRate = c;
}

void deposit(float a)
{
	balance = balance + a;
}

void withdraw(float a)
{
	balance = balance - a;
}

float calcInt()
{
	return IntRate / 100 * balance;
}

float getBalance()
{
	return balance;
}

void display()
{
	cout << "ACCOUNT NO: " << AccNo<< endl;
	cout << "INTEREST RATE: " <<IntRate<<"%"<<endl;
	cout << "CURRENT BALANCE: RS. " << balance<< endl;
}
friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount)
{
if (from.AccNo == to.AccNo)
{
	cout << "ACCOUNT NUMBER CANNOT BE SAME OF BOTH "<<endl;
	return false;
}
//
else
{
	from.balance = from.balance - amount;
	to.balance = to.balance + amount;
	return true;
}
}
int main()
{
BankAccount obj1(54000.323, 432479324, 5.6);
cout << "DETAILS OF ACCOUNT A: " << endl;
obj1.display();
cout << endl;
BankAccount obj2(73452.563, 235832041, 8.9);
cout << "DETAILS OF ACCOUNT B: " << endl;
obj2.display();
cout << endl;

transfer(obj1, obj2, 31441);
cout << "DETAILS AFTER TRANSFER FROM ACCOUNT A TO ACCOUNT B: "<<endl<<endl;
cout << "AMOUNT TRANSFERRED IS RS. 31441"<<endl;
cout << "DETAILS OF ACCOUNT A: " << endl;
obj1.display();
cout << endl;
cout << "DETAILS OF ACCOUNT B: " << endl;
obj2.display();
cout << endl;
return 0;
}
