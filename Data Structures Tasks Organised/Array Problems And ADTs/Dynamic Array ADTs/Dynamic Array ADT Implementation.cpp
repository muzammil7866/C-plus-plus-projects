#include<iostream>
using namespace std;
class Array
{

	int* arr;
	int size;
	int count;

public:

	Array()
	{
		cout << "ENTER THE SIZE FOR YOUR ARRAY: ";
		cin >> size;
		arr = new int;
		count = 0;

	}

	Array(int a)
	{
		arr = new int[a];
		size = a;
		count = 0;
		
	}

	Array(Array& obj)
	{
		size = obj.size;
		count = obj.count;
		arr = new int[size];

		for (int i = 0;i < count;i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	~Array()
	{
		delete[] arr;
	}



	void printList()
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
	}

	int searchElementLinear(int a)
	{
		for (int i = 0; i < count; i++)
		{
			if (arr[i] == a)
			{
				return i;
			}
		}

		return -1;
	}

	int searchElementBinary(int a)
	{
		for (int i = 0; i < count; i++)
		{

		}
		return 0;
	}

	void insertElementAt(int a, int pos)
	{
		if (pos > count - 1)
		{
			cout << "CANNOT INSERT ELEMENTS INTO THE ARRAY IN A NON CONTIGUOUS MANNER";
		}

		else 
		{
			arr[pos] = a;
		}

		}

	bool isEmpty()
	{
		if (count == 0)
		{
			return true;
		}

		else
			return false;
	}
	
	bool isFull()
	{
		if (count == size)
		{
			return true;
		}

		else
			return false;
	}

	bool deleteElement(int a)
	{
		bool found = false;

		for (int i = 0; i < count; i++)
		{
			if (arr[i] == a)
			{
				found = true;
				arr[i] = 0;
				return found;
			}
		}
		if (this->isEmpty() == true)
		{
			cout << "CANNOT PERFORM DELETION AS THE ARRAY IS EMPTY. ";
		}
		else if (found == false)
		{
			cout << "YOUR VALUE IS NOT FOUND IN THE ARRAY ";
			return found;
		}
	}

	int length()
	{
		return count;
	}

	void reverseList()
	{
		Array temp(this->size);
		this->copyList(temp);
		int count2 = 0;

		for (int i = count - 1; i >= 0; i--)
		{

			this->arr[count2] = temp.arr[i];
			count2++;
		}

	}

	void emptyList()
	{
		for (int i = 0; i < count; i++)
		{
			arr[i] = 0;
		}
		count = 0;
	}

	void copyList(Array& obj)
	{
		for (int i = 0; i < count; i++)
		{
			obj.arr[i] = arr[i];
		}
		obj.count = count;
		obj.size = size;
	}

	Array* growArray()
	{
		int size;
		cout << "ENTER THE SIZE OF THE BIGGER ARRAY: ";
		cin >> size;
		Array* ptr2 = new Array(size);
		
		for (int i = 0; i < count; i++)
		{
			ptr2->arr[i] = arr[i];
		}

		ptr2->count = count;
		ptr2->size = size;

		return ptr2;
	}

	void input()
	{
		cout << "ENTER THE VALUE: ";
		cin >> arr[count++];

	}

};
int main()
{
	bool end = false;
	int option;

	Array* obj = new Array;
	Array* obj2 = new Array(obj->length());
	system("cls");

	while (end != true)
	{
		cout << "   KINDLY CHOOSE ONE OF THE FOLLOWING MODULES TO ACCESS YOUR RESPECTIVE INTEREST: ";
		cout << endl << endl;
		cout << "\t\tENTER (1) TO INSERT ELEMENT INTO YOUR ARRAY" << endl;
		cout << "\t\tENTER (2) TO PRINT YOU ARRAY" << endl;
		cout << "\t\tENTER (3) TO SEARCH AN ELEMENT IN YOUR ARRAY USING LINEAR SEARCH" << endl;
		cout << "\t\tENTER (4) TO SEARCH AN ELEMENT IN YOUR ARRAY USING BINARY SEARCH" << endl;
		cout << "\t\tENTER (5) TO INSERT AN ELEMENT IN YOUR ARRAY" << endl;
		cout << "\t\tENTER (6) TO DELETE AN ELEMENT FROM YOUR ARRAY" << endl;
		cout << "\t\tENTER (7) TO CHECK IF YOUR ARRAY IS FULL" << endl;
		cout << "\t\tENTER (8) TO CHECK IF YOUR ARRAY IS EMPTY" << endl;
		cout << "\t\tENTER (9) TO MAKE A COPY OF YOUR ARRAY" << endl;
		cout << "\t\tENTER (10) TO GROW YOUR ARRAY" << endl;
		cout << "\t\tENTER (11) TO REVERSE YOUR ARRAY" << endl;
		cout << "\t\tENTER (12) TO ACQUIRE LENGTH OF YOUR ARRAY" << endl;
		cout << "\t\tENTER (13) TO END THE PROGRAM" << endl;

		cout << endl << endl;
		cout << "\tENTER YOUR OPTION: ";
		cin >> option;
		cout << endl;

		if (option == 1)
		{
			obj->input();

			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 2)
		{
			obj->printList();

			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 3)
		{
			int num;
			cout << "ENTER THE ELEMENT THAT YOU WANT TO SEARCH IN YOUR ARRAY: ";
			cin >> num;
			if (obj->searchElementLinear(num) == -1)
			{
				cout << "YOUR ELEMENT WAS NOT FOUND";
			}
			else
			{
				cout << "YOUR ELEMENT WAS FOUND AT THE INDEX: " << obj->searchElementLinear(num);
			}

			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 4)
		{
			int num;
			cout << "ENTER THE ELEMENT THAT YOU WANT TO SEARCH IN YOUR ARRAY: ";
			cin >> num;
			if (obj->searchElementLinear(num) == -1)
			{
				cout << "YOUR ELEMENT WAS NOT FOUND";
			}
			else
			{
				cout << "YOUR ELEMENT WAS FOUND AT THE INDEX: " << obj->searchElementBinary(num);
			}

			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 5)
		{
			int pos, num;
			cout << "ENTER THE ELEMENT THAT YOU WANT TO INSERT INTO THE ARRAY: ";
			cin >> num;
			cout << "ENTER THE POSITION IN WHICH YOU WANT TO INSERT THE VALUE: ";
			cin >> pos;

			obj->insertElementAt(num, pos);

			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 6)
		{
			int num;
			cout << "ENTER THE ELEMENT THAT YOU WANT TO DELETE FROM THE ARRAY: ";
			cin >> num;

			if (obj->deleteElement(num) == true)
			{
				cout << "YOUR ELEMENT WAS DELETED";
			}

			cout << endl;
			system("pause");
			system("cls");
			
		}

		else if (option == 7)
		{
			if (obj->isFull() == true)
			{
				cout << "YOUR ARRAY IS FULL";
			}

			else
				cout << "YOUR ARRAY IS NOT FULL";

			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 8)
		{
			if (obj->isEmpty() == true)
			{
				cout << "YOUR ARRAY IS EMPTY";
			}

			else
				cout << "YOUR ARRAY IS NOT EMPTY";
			
			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 9)
		{

			obj->copyList(*obj2);

			cout<<"YOUR LIST HAS BEEN COPIED INTO ANOTHER ARRAY";
			cout << endl;
			obj2->printList();
			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 10)
		{
			obj->growArray();

			cout << "YOUR LIST HAS BEEN COPIED WITH INCREASED ARRAY SIZE";
			cout << endl;
			obj->printList();
			cout << endl;
			system("pause");
			system("cls");
		}

		else if (option == 11)
		{
			obj->reverseList();
			cout << endl;
			obj->printList();
			system("pause");
			system("cls");
		}

		else if (option == 12)
		{
			cout<<"LENGTH OF ARRAY: "<<obj->length();
			cout << endl;
			obj->printList();
			system("pause");
			system("cls");
		}

		

		else if (option == 13)
		{
			end = true;
			cout << endl;
			system("pause");
			system("cls");
		}

		else
		{
			cout << "INVALID OPTION, CHOOSE ANOTHER!";
			cout << endl;
			system("pause");
			system("cls");

		}



	}
	
	
	system("pause");

	return 0;
}