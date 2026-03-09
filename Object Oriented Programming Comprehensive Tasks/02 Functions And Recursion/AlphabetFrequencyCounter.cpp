#include <iostream>
#include<string>
using namespace std;
int* count(string ptr); //function prototype
int main()
{
string text; //declares a string
int* ptr; //declares a pointer
cout<<"Enter a string: ";
getline(cin, text); //inputs a string
ptr=count(text); //function called that returns the count of each alphabet in the string
char alpha = 'a';
for (int i = 0; i < 26; i++) 
{
	if (*(ptr + i) > 0) //check if the count of alphabet is more than one, this is used to print only those alphabets occuring atleast once
	{
		cout << alpha << ": " << *(ptr + i) << endl; //prints the alphabet and count of that alphabet
	}
	alpha++; //moves to the next alphabet
}


return 0;
}
int* count(string text) //function header taking a string variable
{
int* counter = new int[26]; //dynamically allocates an array
int size = text.length(); //used to store the size of the string passed
	
for (int i = 0; i < 26; i++)
*(counter + i) = 0; //initialises each element of the array with 0

for (int i = 0; i < size; i++)
{
	char alpha = 'a'; //used to track the lowercase alphabets
	char alpha2 = 'A'; //used to track the uppercase alphabets

	for (int j = 0; j < 26; j++)
	{
		if (text[i] == alpha || text[i] == alpha2) //checks if each element of the array is either equal to the uppercase alphabet or lowercase alphabet of the same type
				*(counter + j) = *(counter + j) + 1; //count in the array of that alphabet is incremented 
			alpha++; //moves to the next lowercase alphabet check 
			alpha2++; //moves to the next uppercase alphabet check
	}
}

return counter; //returns the base index pointer of the array containing the count of each alphabet in the string variable passed
}
