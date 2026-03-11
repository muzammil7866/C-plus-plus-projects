#include<iostream>
using namespace std; 
class Stack
{
public:
	int top;
	static int size;
	int* array;

	Stack()
	{
		top = -1;
		size = 5;
		array = new int[5];
		for (int i = 0; i < size; i++) //initialising
		{
			array[i] = 0;
		}
	}


	void push() //adds items to stack
	{
		if (top+1 < size) //stack not full
		{
			top++;
			cout << "ENTER THE ITEM WHICH YOU WANT TO ENTER INTO THE STACK AT THE INDEX " << top <<": ";
			cin >> array[top];
			cout << endl;
		}

		else 
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
		}
	}

	void pop() //removes items from stack
	{
		if (top > -1) //stack not empty
		{
			
			array[top] = 0; 
			top--;
			cout << endl;
		}
		
		else
		{
			cout << "YOUR STACK IS EMPTY! IT CANNOT POP MORE ITEMS OFF THE STACK." << endl;
		}


	}

	int peek(int pos) //gives item at a specific position
	{
		return array[pos - 1];
	}

	void display() //display stack items in LIFO order
	{
		cout << endl;
		for (int i = size-1; i >= 0; i--)
		{
			cout << array[i];
			cout << endl;
		}
	}

	int count() //no of current items in stack
	{
		return top+1;
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}

		return false;
	}

	bool isFull()
	{
		if (top == size-1)
		{
			return true;
		}

		return false;
	}



};
int Stack::size = 5;

int main()
{
	Stack obj;
	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) PUSH ITEM \n(2) POP ITEM \n(3) IS EMPTY? \n(4) IS FULL? \n(5) EXIT MENU \n" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			obj.push();
		}
		
		else if (option == 2)
		{
			obj.pop();
		}
		else if (option == 3)
		{
			if (obj.isEmpty() == true)
			{
				cout <<endl<< "YOUR STACK IS EMPTY!";
			}

			else
			{
				cout<<endl<<"YOUR STACK IS NOT EMPTY!";
			}
			
		}
		else if (option == 4)
		{
			if (obj.isFull() == true)
			{
				cout <<endl<< "YOUR STACK IS FULL!";
			}

			else
			{
				cout <<endl<< "YOUR STACK IS NOT FULL!";
			}
		}
		else if (option == 5)
		{
			end = true;
		}

		else
		{
			cout << "INVALID OPTION!"<<endl;
		}


		obj.display();
		system("pause");
		system("cls");
		

	}
	
	
}
