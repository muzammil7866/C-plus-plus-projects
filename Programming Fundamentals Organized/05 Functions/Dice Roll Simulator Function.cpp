#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int randnum(int num);
int main()
{
	int diceroll = -1, sum=0, temp=0;
	while (diceroll != 2)
	{
		cout << "Enter 1 for 'Yes' and Enter 2 for 'No'" << endl << "Do you want to roll the dice : ";
		cin >> diceroll;

		if (diceroll == 1)
		{
			temp = randnum(diceroll);
			sum = sum + temp;
			cout << "You got: " << temp << endl;
		}


	}
	cout<<"Your total score is: "<<sum;

	return 0;
}

int randnum(int num)
{
	srand(time(0));
	num = rand() % 6 + 1;

	return num;
}