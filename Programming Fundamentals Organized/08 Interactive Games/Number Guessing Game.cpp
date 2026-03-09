#include <iostream>
using namespace std;
int main()
{
srand(time(0));
int randNum = 0, num = 0, turns = 5;
randNum = (rand() % 100 + 1);
cout << randNum;
cout << "(You have 5 tries in total)" << endl << "Enter your guess between 1 and 100: ";
cin >> num;
while (num != randNum && turns > 1)
{
	if (num > randNum)
	{
		turns--;
		cout << "You have " << turns << " tries left."<<endl<<"Try again, your number is higher than the actual number: "<<endl;
		cin >> num;
//			
	}
//
	else if (num < randNum)
	{
		turns--;
		cout << "You have " << turns << " tries left." << endl << "Try again, your number is lesser than the actual number: ";
		cin >> num;
//			
	}
}
//
if (num == randNum)
{
	cout << "Congratulations! You won in "<<(5-turns)<<" turns";
}
//
else if (num != randNum)
{
	cout << "You lost as you are out of turns";
//
}
//
//
//
return 0;
}
