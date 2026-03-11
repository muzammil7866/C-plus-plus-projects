#include <iostream>
using namespace std;
int minNum(int list[], int size, int i, int min) //calculates minimum number in an array
{
	if (i == size) //completes iterating list
	{
		return min;
	}

	else
	{
		if (list[i]<= min) //compares the next index with the existing value of min
		{
			min = list[i];
		}


		minNum(list, size, i + 1, min); //recursively iterates the list 

	}
}
int main()
{
	int list[5] = { 11,53,8,90,110 };
	int size = 5;

	cout << minNum(list, size, 0, list[0]);


	return 0;	
}
