#include <iostream>
using namespace std;
void reverseDigs(int num);
bool multiple(int num, int num2);
char previousAlpha(char a);
char Upper_to_lower(char a);
void isPerfect(int num);
int main()
{
	int perfectCheck = 1;
	isPerfect(perfectCheck);

	int num;
	int num1 = 0, num2 = 0;
	cout << "Enter your number to reverse it: ";
	cin >> num;
	reverseDigs(num);
	cout << endl;
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;
	multiple(num1, num2);
	char a, b, c;
	cout << "Enter three alphabets: ";
	cin >> a >> b >> c;
	cout << endl;
	a = previousAlpha(a);
	cout << a <<endl;
	b = previousAlpha(b);
	cout << b << endl;
	c = previousAlpha(c);
	cout << c << endl;
	char A, B, C, D;
	cout << "Enter four uppercase characters: ";
	cin >> A>>B>>C>>D;
	cout << endl;
	A = Upper_to_lower(A);
	cout << A << endl;
	B = Upper_to_lower(B);
	cout << B << endl;
	C = Upper_to_lower(C);
	cout << C<< endl;
	D = Upper_to_lower(D);
	cout << D << endl;
	

	return 0;
}

void reverseDigs(int num)
{
	int dig = 0;
	int rem = num;
	while (rem > 0)
	{
		dig = rem % 10;
		rem = rem / 10;
		cout << dig;
	}
}
bool multiple(int num, int num2)
{
	bool isMultiple = false;
	do
	{
		if (num2 % num == 0)
		{
			isMultiple = true;
			cout << num2 << " is a multiple of " << num<<endl;
			return isMultiple;
		}
		else
		{
			isMultiple = false;
			cout << num2 << " is not a multiple of " << num<<endl;
			return isMultiple;
		}
	} while (isMultiple != true);
}

char previousAlpha(char a)
{
	if (a == 'a')
		a = 'z';
	else if (a == 'A')
		a = 'Z';
	else
		a--;

	return a;
}

char Upper_to_lower(char a)
{

	a = tolower(a);

	return a;
}

void isPerfect(int num)
{
	while (num <= 1000)
	{	
		if (num == 6 || num == 28 || num == 496)
		cout << "Divisors of number " << num<<" are: ";
		int divisorSum = 0;
		int count = 1;
		while (count < num)
		{
			
			if (num % count == 0)
			{
				if(num == 6 || num == 28 || num == 496)
					cout << count << " ";
				divisorSum = divisorSum + count;
			}
			count++;
		}
		if (divisorSum == num)
		{
			cout <<endl<< "Number " << num << " is a perfect number"<<endl;
		}

		
		num++;
	}
}