#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<windows.h>
#include<iomanip>
using namespace std;
int main()
{

	int player_1[5][5];
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			player_1[i][j] = (rand() % 25 + 1);
		}
	}
	cout << endl << endl;
	cout << name1 << ":" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "|" << setw(3) << player_1[i][j] << setw(3) << "|";
		}
		cout << endl;
	}
}
