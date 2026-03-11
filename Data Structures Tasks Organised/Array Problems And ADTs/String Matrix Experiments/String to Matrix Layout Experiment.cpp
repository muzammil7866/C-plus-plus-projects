#include<iostream>
#include<string>
using namespace std;
int main()
{
	string text;
	text = "Hello how are you?";
	cout << text;


	const int MAX_ROWS = 100;
	const int MAX_COLS = 100;

	int array[MAX_ROWS][MAX_COLS];
	

	int size = text.length();

	int cols[100];
	int count2 = 0;

	for (int i = 0; i < size; i++)
	{
		int count = 0;

		while (text[i] != ' ' || text[i] != '.' || text[i] != '.')
		{
			array[i][count] = text[i];
			count++;
		}

		cols[i] = count;
		count2 = i;
	}

	for (int i = 0; i < count2; i++)
	{
		for (int j = 0; j < cols[i]; j++)
		{
			cout << array[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}