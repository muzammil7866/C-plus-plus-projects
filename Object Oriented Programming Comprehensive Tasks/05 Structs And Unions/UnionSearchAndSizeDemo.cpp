#include<iostream>
using namespace std;
struct method1
{
	char clientspasswords[20];
	char cnic[20];
	int fileno;
};
union method2
{
	char clientspasswords[20];
	char cnic[20];
	int fileno;
	

};
int main()
{
	int num;
	method1 database[100];
	method2 database[100];
	cout << "How do you want to search the client: " << endl;
	cout << "(1) Using method 1" << endl << "(2) Using Method 2" << endl;
	cin >> num;

	//method 1 is only by one i.e. either by cnic or either by file number
	//method 2 is that it can enter both but only one would be able to search the client

}