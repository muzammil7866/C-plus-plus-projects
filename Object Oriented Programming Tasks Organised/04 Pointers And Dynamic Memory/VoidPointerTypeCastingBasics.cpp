#include <iostream>
using namespace std;
int main()
{
	short* numPtr, result;
	numPtr = &result;
	void* genericPtr =numPtr;
	result = short(genericPtr) + 7;
	cout << result;


	return 0;
}
