#include <iostream>
using namespace std;
class TwoStack {
public:
	int* array;
	int top1;
	int top2; //for stack 2
	int size;
	int mid; //half of the size of array

	TwoStack()
	{
		size = 10;
		array = new int[size];
		top1 = -1;
		mid = size / 2; //for dividing stack into two parts
		top2 = mid - 1;

		for (int i = 0; i < size; i++) //initialising
		{
			array[i] = 0;
		}

	}

	void push1(int a) //adds item to stack 1
	{
		if (!isFull1())
			array[++top1] = a;

		else
			cout << "YOUR STACK 1 IS FULL!";
		
	}
	
	void push2(int a) //adds item to stack 2
	{
		if (!isFull2())
			array[++top2] = a;

		else
			cout << "YOUR STACK 2 IS FULL!";
	}

	int pop1() //removes item from stack 1
	{
		if (!isEmpty1())
		{
			int temp;
			temp = array[top1];
			array[top1] = 0;
			top1--;
			
			return temp;
		}

		else
		{
			cout << "YOUR STACK 1 IS EMPTY!";
		}
	}

	int pop2() //removes item from stack 2
	{
		if (!isEmpty2())
		{
			int temp;
			temp = array[top2];
			array[top2] = 0;
			top2--;
			return temp;
		}

		else
		{
			cout << "YOUR STACK 2 IS EMPTY!";
		}
	}

	void display() //displays whole array in lifo order
	{
		cout << endl;
		for (int i = size - 1; i >= 0; i--) 
		{
			cout << array[i];
			cout << endl;

			if (i == mid)
			{
				cout << endl;
			}
		}
	}


	bool isEmpty1() //checks if first stack is empty
	{
		if (top1 == -1)
		{
			return true;
		}

		return false;
	}

	bool isEmpty2() //checks if second stack is empty
	{
		if (top2 == mid-1)
		{
			return true;
		}

		return false;
	}

	bool isFull1() //checks if first stack is full
	{
		if (top1 == mid-1)
		{
			return true;
		}

		return false;
	}

	bool isFull2() //checks if second stack is full
	{
		if (top2 == size - 1)
		{
			return true;
		}

		return false;
	}

};
int main()
{
	
	TwoStack obj;
	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) PUSH 1 \n(2) PUSH 2 \n(3) POP 1 \n(4) POP 2 \n(5) EXIT MENU \n" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int a;
			cout << "ENTER THE VALUE YOU WANT TO PUSH: ";
			cin >> a;
			obj.push1(a);
			obj.display();
		}

		else if (option == 2)
		{
			int a;
			cout << "ENTER THE VALUE YOU WANT TO PUSH: ";
			cin >> a;
			obj.push2(a);
			obj.display();
		}
		else if (option == 3)
		{
			obj.pop1();
			obj.display();
		}
		else if (option == 4)
		{
			obj.pop2();
			obj.display();
		}
		else if (option == 5)
		{
			end = true;
		}

		else
		{
			cout << "INVALID OPTION!" << endl;
		}


		system("pause");
		system("cls");


	}


}

