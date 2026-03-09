#include <iostream>
using namespace std;
int main()
{
int num1 = 0, num2 = 0;
char opr = 0;
srand(time(0));
int count = 0;
int userans = 0, correctans = 0;
bool endtry = false;
int question = 1;
cout << "You will be answering 3 questions in this test and be given report after each question." <<endl<< endl;
while (question <= 3)
{
	cout << endl<< "Question: " << question << endl;
	num1 = rand() % 10;
//
	num2 = rand() % 10;
	while (opr != '+' && opr != '*' && opr != '-' && opr != '/')
	{
//
		opr = (rand() % 8) + 40;
	}
//
//
	cout << num1 << " " << opr << " " << num2 << " = " << "'?'" << endl;
//
//
//
	switch (opr)
	{
	case '+':
	{
		correctans = num1 + num2;
//	
		break;
	}
	case '-':
	{
		correctans = num1 - num2;
//	
		break;
//
	}
	case '/':
	{
		correctans = num1 / num2;
			break;
//
	}
	case '*':
	{
		correctans = num1 * num2;
			break;
//
	}
	}
//
	count = 0;
	endtry = false;
	while (endtry != true)
//
	{	
		cout << endl<<"Your answer: ";
		cin >> userans;
//
		if (userans == correctans)
		{
			cout << "Very good!";
			cout << "You answered it correct in " << count+1 << " turns: ";
			cout << endl << "Correct answer was: " << num1 << " " << opr << " " << num2 << " = " << correctans << endl;
				count++;
			endtry = true;
		}
		else
		{
			count++;
			if (count == 3)
			{
				endtry = true;
				cout << "Your answer was incorrect all 3 times";
				cout << endl<< "Correct answer was: " << num1 << " " << opr << " " << num2 << " = " << correctans << endl;
			}
			else
			{
//
				cout << "Try again, you have " << 3 - count << " attempts left: ";
				endtry = false;
			}
		}
	}
//		
	question++;
}
return 0;
}
