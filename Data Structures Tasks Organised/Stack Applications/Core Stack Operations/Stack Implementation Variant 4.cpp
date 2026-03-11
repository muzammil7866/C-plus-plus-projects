#include<iostream>
using namespace std;

class ShoppingList
{
public:
	class Data
	{
	public:
		int id;
		int barCode;
		string item;
		float price;
		Data* next;

		Data()
		{
			item = "";
			price = 0;
			next = nullptr;
		}

		Data(int id, string item, float price)
		{
			this->id = id;
			this->item = item;
			this->price = price;
		}


	};

	Data* head;


	ShoppingList()
	{
		head = nullptr;

	}

	void appendNode(Data* obj)
	{

		if (head == nullptr)
		{
			head = obj;
		}

		else
		{
			Data* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = obj;
		}
	}

	void output()
	{
		Data* temp = head;

		while (temp != nullptr)
		{
			cout << temp->id << " " << temp->item << " " << temp->price;
			temp = temp->next;
			cout << endl;
		}
	}
};

class Stack
{
public:
	int top;
	static int size;
	Data* array;

	Stack()
	{
		top = -1;
		size = 5;
		array = new Data[5];

	}


	void push(ShoppingList obj)
	{
		if (top + 1 < size)
		{

			ShoppingList temp = obj.head;

		}
		while ()
			top++;

		cout << endl;
	}

		else
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
			}
}

Data pop()
{
	if (top > -1)
	{

		cout << "ENTER THE POPPING ITEM WHICH YOU WANT TO ENTER INTO THE STACK AT THE INDEX " << top << ": ";
		cin >> array[top];
		array[top].id = 0;
		array[top].price = 0;
		array[top].item = "";

		top--;
		cout << endl;
	}

	else
	{
		cout << "YOUR STACK IS EMPTY! IT CANNOT POP MORE ITEMS OFF THE STACK." << endl;
	}


}


Data peek(int pos)
{
	return array[pos - 1];
}

void display()
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << array[i].id << endl;
		cout << array[i].item << endl;
		cout << array[i].price << endl;
		cout << endl;
	}
}

int count()
{
	return top + 1;
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
	if (top == size - 1)
	{
		return true;
	}

	return false;
}



};
int Stack::size = 5;
int main()
{

	Data n1(1, "abc", 172);
	Data n2(1, "abc", 11);

	ShoppingList obj;

	Stack s1;

	obj.appendNode(&n1);
	obj.appendNode(&n2);

	obj.output();

	s1.push(obj);
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
				cout << "YOUR STACK IS EMPTY!";
			}

			else
			{
				cout<<"YOUR STACK IS NOT EMPTY!";
			}

		}
		else if (option == 4)
		{
			if (obj.isFull() == true)
			{
				cout << "YOUR STACK IS FULL!";
			}

			else
			{
				cout << "YOUR STACK IS NOT FULL!";
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
