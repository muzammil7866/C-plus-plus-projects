#include <iostream>
using namespace std;
int main()
{
int count;
cout << "Enter number of integers you want to enter: ";
cin >> count;
int array[50];
//
for (int i = 0; i < count; i++) //takes in the inputs
{
	cout << "Enter number "<<i+1<<" : ";
	cin >> array[i];
}
cout << endl;
//
for (int i = 0; i < count; i++) //displays the inputs for the check
{
	cout << array[i]<<" ";
}
//
cout << endl;
//
int min = array[0], max = array[0], middle;
int newcount = 0;
while (newcount < count)	//used to access each value of array
{
	if (array[newcount] < min) //checks if each value is smaller than minimum
		min = array[newcount];
//
	if (array[newcount] > max) //checks if each value is greater than maximum
		max = array[newcount];
//
//		newcount++;
}
//
cout << "Maximum number is: " << max << endl;
cout << "Minimum number is: " << min << endl;
//
float average;
if (count % 2 == 0) //checks if the number of entries is even
{
	middle = count / 2;
	average = (array[middle-1] + array[middle])/2; //calculates average median value
	cout << "averaged middle is " << average<<endl;
}
//
else //works for odd values of numbetr of entries
{
	middle = count / 2;
//
	middle = array[middle];
	cout << "middle is " << middle<<endl;
}
return 0;
}
