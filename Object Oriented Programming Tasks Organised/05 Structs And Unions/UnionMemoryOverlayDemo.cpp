#include<iostream>
using namespace std;
void fib(int terms);
int num1 = 0; //globally declares the number 1 as the first term of the sequence
int num2 = 1; //globally declares the number 2 as the first term of the sequence
int main()
{
int terms = 0;
cout << "Enter the number of terms of your fibonacci sequence: "; 
cin >> terms; //user enters the number of terms to be printed in the sequence
cout << "FIBONACCI SEQUENCE: " << endl;
cout << num1 << " " << num2<<" "; //first two terms are outputted with a space in between
//	fib(terms-2); //function call is made to print the fibonacci sequence, but the terms are decremented by two as the first two terms are displayed as it is in the main
//	
return 0;
}
//
void fib(int terms)
{
int temp;
if (terms > 0) //base case which checks if the required number of terms by user are printed
{
//		//this block of code performs the swap function
	temp = num1;
	num1 = num2;
	num2 = temp + num1;
//
	cout << num2<<" "; //prints the updated number 2 which is the sum of the previous number 1 and previous number 2 
//		fib(terms - 1); //function call is again made but this time one less than the previous terms as we have already printed one term in the previous call
}
//
}
