#include<iostream>
using namespace std;
int* randArray(int n); //function prototype
int main()
{

int* ptr = randArray(100); //size of the array passed as parameter to the function
cout << "***********ODD INDEXES OF THE ARRAY**********"<<endl;
for (int i = 0; i <= (100 - 1); i++) //loop used to access the elements of array 
{
	if (i % 2 != 0) //checks if index is an odd number
	{
		cout << "Element at index ["<<i<<"] is: "<< * (ptr + i) <<endl; //prints the index and its value
	}
}
	
cout << "***********INDEXES THAT ARE THE MULTIPLES OF 3 & 5************" << endl;
for (int i = 0; i <= (100 - 1); i++)
{
	if (i % 3 == 0 && i%5 ==0) //checks if the index is a multiple of 3 and also a multiple of 5
	{
		cout << "Element at index [" << i << "] is: " << *(ptr + i) << endl; //prints the index and its value
	}
}

	delete[] ptr; //releases the memory of ptr to heap

	

}
int* randArray(int n) //function header
{
	srand(time(0)); //generates new random numbers each time the compiler is run by altering the system clock
int* array = new int[n]; //dynamically allocates array of size n

for (int i = 0; i <= (n-1); i++)
{
		*(array + i) = rand(); //generates the random numbers in each element of array
}

return array;
}
