#include <iostream>
#include<string>
#include<Windows.h>
#include<cstring>
using namespace std;
class Stack
{
public:
	int top;
	int size;
	string array[20];


	Stack()
	{
		top = -1;
		size = 20;
		for (int i = 0; i <= size - 1; i++)
		{
			array[i] = '\0';
		}
	}


	void push()
	{
		if (top + 1 < size)
		{
			top++;
			cout << "ENTER THE ITEM WHICH YOU WANT TO ENTER INTO THE STACK AT THE INDEX " << top << ": ";
			cin >> array[top];
			cout << endl;
		}

		else
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
		}
	}

	void push(string value)
	{
		if (top + 1 < size)
		{
			top++;
			array[top] = value;
			cout << endl;
		}

		else
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
		}
	}

	string pop()
	{
		if (top > -1)
		{

			//cout << "ENTER THE POPPING ITEM WHICH YOU WANT TO ENTER INTO THE STACK AT THE INDEX " << top << ": ";
			//cin >> array[top];
			string temp = array[top];
			array[top] = '\0';
			top--;
			cout << endl;

			return temp;
		}

		else
		{
			cout << "YOUR STACK IS EMPTY! IT CANNOT POP MORE ITEMS OFF THE STACK." << endl;
			return "-1";
		}


	}

	string peek(int pos)
	{
		return array[pos - 1];
	}

	void display()
	{
		cout << endl << endl;

		for (int i = top; i >= 0; i--)
		{
			cout << array[i];
			cout << endl;
		}

		cout << endl;
	}

	int count()
	{
		return top + 1;
	}

	bool isFull()
	{
		if (top == size - 1)
		{
			return true;
		}

		else
			return false;
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}

		else
			return false;
	}
};
int main()
{
	Stack obj;
	bool end = false;
	string c0 = "DISABLED", c1 = "ENABLED";
	string undo = c0, redo = c0;
	string thisCommand;
	int count = 0;
	Stack Undo, Redo;
	while (end != true)
	{
		cout << "UNDO: " << undo;
		cout << ", REDO: " << redo;
		cout << endl;
		cout << "ENTER YOUR COMMAND: ";
		
		getline(cin, thisCommand);

		if (thisCommand == "quit")
		{
			cout << "PROGRAM TERMINATING";
			int count = 0;
			while (count < 3)
			{
			cout << ".";
			Sleep(700);
			
			count++;
			}
			end = true;
		}
		else {

			if(thisCommand == "undo")
			{
					if (undo == c1)
					{
						string temp = obj.pop();
						Undo.push(temp);
						cout << temp << " UNDONE! ";
						obj.display();
						count++;
						redo = c1;

						if (obj.isEmpty())
							undo = c0;
					}

					else
					{
						cout << "CANNOT UNDO ANYMORE!" << endl;
					}
				}
			
			
			else if (thisCommand == "redo")
			{
				if (redo == c1)
				{
					
					string temp = Undo.pop();
					obj.push(temp);
					


					if (Undo.isEmpty())
						redo = c0;

					obj.display();
				}
				else
				{
					cout << "CANNOT REDO ANYMORE!"<<endl;
				}
			}
			else
			{
				while (!Undo.isEmpty())
				{
					Undo.pop();
				}

				obj.push(thisCommand);
				undo = c1;
				obj.display();
				count++;
				redo = c0;
			}

		}

	}

	return 0;	
}
