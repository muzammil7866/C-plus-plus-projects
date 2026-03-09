#include <iostream>
using namespace std;
int sumOfNumbers(int upperBound);
int main()
{
int upperBound=0;
cout << "Enter the upper bound: ";
cin >> upperBound;
//
sumOfNumbers(upperBound);
}
//
//int sumOfNumbers(int upperBound)
{
int evenSum = 0, oddSum = 0, diff=0;
int count = 1;
while (count <= upperBound)
{
	if (count % 2 == 0)
		evenSum = evenSum + count;
	else
		oddSum = oddSum + count;
	count++;
}
cout << "Sum of odd numbers till the upperbound is: " << oddSum<<endl;
cout << "Sum of even numbers till the upperbound is: " << evenSum<<endl;
diff = evenSum - oddSum;
cout << "The absoulute difference is: " << diff;
return diff;
}
