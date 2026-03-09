#include <iostream>
using namespace std;
int main()
 {
double firstNum, secondNum;
cout << "Enter two nonzero numbers: ";
cin >> firstNum >> secondNum;
if(firstNum==0 || secondNum==0)
{
cout << "Both numbers must be non zero"<<endl;
}
else if(firstNum>secondNum)
{
	cout<<firstNum/secondNum;
}
else if(firstNum<secondNum)
{
	cout<<secondNum/firstNum;
}
else
{
	cout<<firstNum*secondNum;
}
return 0;
}
