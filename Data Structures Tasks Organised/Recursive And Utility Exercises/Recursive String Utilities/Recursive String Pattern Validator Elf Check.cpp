#include <iostream>
#include <string>
using namespace std;
//checks if string contains e/E, l/L and f/F
bool elfish(const string word, int index, bool hasE, bool hasL, bool hasF) {


	if (index == word.length()+1) //string size ends
	{
		return false;
	}
	if (hasE == true && hasL == true && hasF == true) //contains all three
	{
		return true;
	}
	else
	{
		if (word[index] == 'e' || word[index] == 'E')
		{
			hasE = true;
			
		}
		cout << hasE;

		if (word[index] == 'l' || word[index] == 'L')
		{
			hasL = true;
			
		}
		cout << hasL;

		if (word[index] == 'f' || word[index] == 'F')
		{
			hasF = true;
			cout << hasF;
		}
		cout << hasF;

		
	}

	return elfish(word, index + 1, hasE, hasL, hasF); //recursively iterates the string
}
int main();
int main() {
	string word;
	cout << "Enter a word: ";
	cin >> word;
	bool isElfish = false;
	isElfish = elfish(word, 0, false, false, false);
	

	if (isElfish) {
		cout << word << " is elfish." << endl;
	}
	else {
		cout << word << " is not elfish." << endl;
	}
	return 0;



}