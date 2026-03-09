#include<iostream>
using namespace std;
int main()
{
	char array[4][4] = { {'S','0','1','1'}, {'1', '1','0','1'},{'0','1','1', '1'}, {'1', '0', 'D', '1'} };

	int** array2 = new int*[4];
	for (int i = 0; i < 10; i++)
	{
		array2 = new int*[4];
	}

	char* ptr_D = new char;
	char* ptr_S = array[0];


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{	
			if (array[i][j] == 'D')
			{
				*ptr_D = array[i][j];
			}
		}
	}

	int temp = array[0][0];
	while (temp != 'D')
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				
				if (array[i + 1][j] == '1')
				{
					cout << "Take the next path to index: " << i + 1 << " " << j << endl;
					temp = array[i + 1][j];
				}
				if (array[i][j + 1] == '1')
				{
					cout << "Take the next path to index: " << i << " " << j + 1 << endl;
					temp = array[i][j+1];
				}
				if (array[i + 1][j] == 'D')
				{
					temp = 'D';
				}
				if (array[i][j + 1] == 'D')
				{
					temp = 'D';
				}

				if (i == 3)
					temp = 'D';
				
				}

		}
	}

	cout << *ptr_D<<endl;
	cout << *ptr_S << endl;

	return 0;
}