#include<iostream>
using namespace std; 
class Stack
{
public:
	int top;
	static int size;
	int array[5];


	Stack()
	{
		top = -1;
		size = 5;
		for (int i = 0; i <=size-1; i++)
		{
			array[i] = 0;
		}
	}


	void push()
	{
		if (top+1 < size)
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

	void pop()
	{
		if (top > -1)
		{
			
			//cout << "ENTER THE POPPING ITEM WHICH YOU WANT TO ENTER INTO THE STACK AT THE INDEX " << top << ": ";
			//cin >> array[top];
			array[top] = 0;
			top--;
			cout << endl;
		}
		
		else
		{
			cout << "YOUR STACK IS EMPTY! IT CANNOT POP MORE ITEMS OFF THE STACK." << endl;
		}


	}

	int peek(int pos)
	{
		return array[pos - 1];
	}

	void display()
	{
		for (int i = size-1; i >= 0; i--)
		{
			cout << array[i];
			cout << endl;
		}
	}

	int count()
	{
		return top+1;
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
		cout << "(1) PUSH ITEM \n(2) POP ITEM \n(3) PEEK INTO \n(4) GET ITEMS COUNT \n(5) EXIT MENU \n" << endl;

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
			int num;
			cout << "ENTER THE POSITION TO PEEK ITS ITEM: ";
			cin >> num;
			cout<<"THE ITEM IS: "<<obj.peek(num);
			cout << endl;
		}
		else if (option == 4)
		{
			cout<<"THE ITEMS CURRENTLY IN THE STACK ARE: "<<obj.count()<<endl;
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
