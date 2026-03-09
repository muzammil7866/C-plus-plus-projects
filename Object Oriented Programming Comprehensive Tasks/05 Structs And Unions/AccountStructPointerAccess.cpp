#include <iostream>
using namespace std;
void swap(int& ptra, int& ptrb); //function header showing the parameter list and their data type
int main()
{
//	int a, b;
//	int* ptra, * ptrb; //declares two pointers of integer type
cout << "Enter the first number: ";cin >> a;
cout << "Enter the second number: ";
cin >> b;
//
ptra = &a; //pointer points to the address of first number
ptrb = &b; //pointer points to the address of second number
//
//	swap(ptra, ptrb); //function takes in two pointers as argument
//
cout << "The first number is: " << *ptra << endl; //outputs the swapped value pointed by the pointer
cout << "The second number is: " << *ptrb << endl; //outputs the swapped value pointed by the pointer
return 0;
}
//
void swap(int& ptra, int& ptrb) //takes pass by reference parameters that would change the original values in the main 
{
//	//values are swapped using pointers
int temp = ptra;
ptra = ptrb;
ptrb = temp;
//
}
