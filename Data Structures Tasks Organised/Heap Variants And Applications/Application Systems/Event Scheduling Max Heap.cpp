
//CODE FOR AN EVENT SCHEDULING SYSTEM USING THE CONCEPTS OF MAX HEAP TO WORK BASED ON URGENCY OF EVENT

#include<iostream>
#include<math.h>
using namespace std;
class Queue
{
public:
	int* array;
	int maxSize;
	int front;
	int end;

	Queue()
	{
		maxSize = 20;
		array = new int[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			array[i] = 0;
		}

		front = -1;
		end = -1;
	}

	void enqueue(int a)
	{
		if (front == -1)
		{
			front = 0;
			end = 0;
			array[end] = a;
		}

		else
		{
			if (this->isFull())
			{
				cout << "YOU CANNOT ADD MORE ITEMS INTO THE QUEUE AS IT IS FULL!";
			}

			else
			{
				end++;
				array[end] = a;
			}
		}
	}

	bool isFull()const //ADDING CONST AS THE FUNCTION DOES NOT ALTERS ANY VALUE(S)
	{
		if (end == maxSize - 1)
		{
			return true;
		}

		else
			return false;
	}

	void display()const //SAME CONST
	{
		cout << endl;

		for (int i = 0; i < maxSize; i++)
		{

			cout << array[i] << " ";
		}
		cout << endl;
	}

	bool isEmpty() const
	{
		if (front == -1)
			return true;

		else
			return false;
	}

	int dequeue()
	{
		if (this->isEmpty())
		{
			cout << "CANNOT DEQUEUE AS THE QUEUE IS EMPTY!";
			return -1;
		}

		else
		{
			if (end == 0)
			{
				int temp = array[end];
				front = -1;
				end = -1;

				array[end + 1] = 0;

				return temp;
			}

			else
			{
				int temp = array[front];

				for (int i = front; i < end; i++)
				{
					array[i] = array[i + 1];
				}

				end--;

				array[end + 1] = 0;


				return temp;
			}
		}
	}
};
class Event
{
public:
	Event* left;
	Event* right;
	int urgency; 

	Event() //DEFAULT CONSTRUCTOR FOR INITIALISING THE EVENT VALUES
	{
		left = nullptr;
		right = nullptr;
		urgency = 0;

	}

	Event(int value) //PARAMETERISED CONSTRUCTOR FOR INITIALISING THE EVENT VALUES
	{
		left = nullptr;
		right = nullptr;
		urgency = value;

	}

};

class EventSchedulingSystem
{
public:
	int* arr;
	int maxEvents;
	int currEvents;

	EventSchedulingSystem(int size) //PARAMETERISED CONSTRUCTOR FOR INITIALISING THE SYSTEM
	{
		maxEvents = size;
		arr = new int[maxEvents];
		currEvents = 0;

	}

	int linearSearch(int value) //TO SEARCH FOR AN EVENT IN THE SCHEDULING SYSTEM
	{
		for (int i = 0; i < currEvents; i++)
		{
			if (value == arr[i])
			{
				return 1;
			}
		}

		return 0;

	}

	int getIdx(int value) //TO SEARCH FOR AN EVENT IN THE SCHEDULING SYSTEM
	{
		for (int i = 0; i < currEvents; i++)
		{
			if (value == arr[i])
			{
				return i;
			}
		}

		return -1;

	}



	int linearSearch2(int value, int val2) //TO SEARCH FOR AN EVENT IN THE SCHEDULING SYSTEM
	{
		for (int i = 0; i < currEvents; i++)
		{
			if (value == arr[i])
			{
				arr[i] = val2;
				return 1;
			}
		}

		return 0;

	}

	void display() //DISPLAYS EVENTS IN THE SYSTEM
	{
		for (int i = 0; i < currEvents; i++)
		{
			cout << arr[i] << " ";
		}
	}

	int height() //GETS THE HEIGHT OF THE SYSTEM
	{
		return ceil(log2(currEvents + 1)) - 1;
	}

	int getParentIndex(int i) //RETURNS INDEX OF THE PARENT EVENT
	{
		return (i - 1) / 2;
	}
	void eventInsert(int& value) //INSERTS A NEW EVENT
	{
		if (currEvents == maxEvents)
		{
			cout << "SYSTEM IS FULL SO CANNOT INSERT ANY MORE OF THE EVENTS!";
		}

		else
		{
			currEvents++;
			int i = currEvents - 1;
			arr[i] = value;

			while (i != 0 && arr[getParentIndex(i)] < arr[i]) //careful
			{

				swaps(arr[getParentIndex(i)], arr[i]);
				i = getParentIndex(i);

			}

		}
	}
	int getLeftIndex(int i) //GETS INDEX OF THE LEFT EVENT
	{
		return 2 * i + 1;
	}

	int getRightIndex(int i) //GETS INDEX OF THE RIGHT EVENT
	{
		return 2 * i + 2;
	}

	void swaps(int& a, int& b) //SWAPS TWO EVENTS
	{
		int temp = a;
		a = b;
		b = temp;
	}
	void urgentBalance(int i) //BALANCES OUT THE STRUCTURE TO ORGANISE EVENTS WITH THE MOST PRIORITY FIRST
	{
		int left = getLeftIndex(i);
		int right = getRightIndex(i);
		int minimum = i;

		if (left < currEvents && arr[left] > arr[i])
		{
			minimum = left;
			if (right < currEvents && arr[right] > arr[minimum])
			{
				minimum = right;
			}
		}

		if (minimum != i)
		{
			swaps(arr[i], arr[minimum]);
			cout << arr[minimum];
			urgentBalance(minimum);
		}


	}
	int getNext() //GETS THE NEXT URGENT EVENT IN THE SYSTEM
	{
			return arr[0];
	}

	int extractNextUrgent() //REMOVES THE NEXT URGENT EVENT IN THE SYSTEM AND BALANCES SYSTEM ALONG
	{
		if (currEvents <= 0)
		{
			return INT_MAX;
		}

		else if (currEvents == 1)
		{
			currEvents--;
			return arr[0];
		}
		else {

			int temp = arr[0];

			arr[0] = arr[currEvents - 1];
			currEvents--;

			urgentBalance(0);
			return temp;
		}


	}

	void perculateUp(int& a, int b) //PART OF THE BALANCE PART TO ORGANISE EVENTS BY SWAPPING
	{
		arr[a] = b;

		while (a != 0 && arr[getParentIndex(a)] < arr[a])
		{
			swaps(arr[getParentIndex(a)], arr[a]);
			a = getParentIndex(a);
		}

	}

	void deleteEvent(int i) //DELETES THE EVENT FROM THE SYSTEM
	{
		perculateUp(i, INT_MIN);
		extractNextUrgent();
	}

};
int main()
{

	EventSchedulingSystem obj(10);
	Queue queue1;
	bool end = false;

	while (end != true)
	{
		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) INSERT EVENT  \n(2) SEARCH/RESCHEDULE EVENT\n(3) CANCEL EVENT \n(4) GET NEXT URGENT EVENT \n(5) EXTRACT NEXT URGENT EVENT \n(6) HEIGHT OF THE SYSTEM \n(7) DISPLAY EVENTS IN THE SYSTEM \n(8) HANDLING OVERLAPPING EVENTS \n(9) EXIT MENU \n" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			int value;
			cout << "ENTER THE URGENCY VALUE FOR THE EVENT THAT YOU WANT TO INSERT: ";
			cin >> value;
			obj.eventInsert(value);
		}

		else if (option == 2)
		{
			int value;
			cout << "ENTER THE URGENCY VAUE OF EVENT THAT YOU WANT TO SEARCH: ";
			cin >> value;
			if (obj.linearSearch(value))
			{
				cout << "FOUND!";

				int option;
				cout << "DO YOU WANT TO RESCHEDULE EVENT, 1 FOR YES, 2 FOR NO: ";
				cin >> option;

				if (option == 1)
				{
					int urgency;
					cout << "ENTER THE URGENCY OF EVENT: ";
					cin >> urgency;
					obj.linearSearch2(value, urgency);
				}
			}

			else
			{
				cout << "NOT FOUND!";
			}
		}
		else if (option == 3)
		{
			int value;
			cout << "ENTER THE URGENCY VAUE OF THE EVENT THAT YOU WANT TO DELETE: ";
			cin >> value;
			if (obj.linearSearch(value))
			{
				int idx = obj.getIdx(value);
				obj.deleteEvent(idx);
				
			}

			else
			{
				cout << "EVENT DOES NOT EXIST IN THE SYSTEM!";
			}


		}
		else if (option == 4)
		{
			if (obj.currEvents == 0)
			{
				cout << "THERE ARE NO EVENTS AT THE MOMENT IN THE SYSTEM!";
			}
			else
			{ 
			cout << obj.getNext();
			}
		}
		else if (option == 5)
		{
			if (obj.currEvents == 0)
			{
				cout << "THERE ARE NO EVENTS AT THE MOMENT IN THE SYSTEM!";
			}
			else
			{
				cout << obj.extractNextUrgent();
			}
			
		}

		else if (option == 6)
		{
			cout << obj.height();
		}
		else if (option == 7)
		{
			obj.display();
		}
		else if (option == 8)
		{
			int no;
			cout << "HOW MANY OVERLAPPING EVENTS ARE THERE: ";
			cin >> no;

			int* arr = new int[no];

			cout << "ENTER URGENCY VALUE OF ANY ONE OF THE " << no << " EVENTS: ";
			cout << endl;
			cin >> arr[0];

			for (int i = 1; i < no; i++)
			{
				arr[i] = arr[0];
			}

			
			cout << "ENTERING THESE INTO THE SYSTEM QUEUE, YOU CAN CHOOSE HOW TO HANDLE THESE EVENTS USING FIFO LATER!";
			
			for (int i = 0; i < no; i++)
			{
				
				queue1.enqueue(arr[i]);
				
			}

			for (int i = 0; i < no; i++)
			{
				int temp = queue1.dequeue();
				obj.eventInsert(temp);
			}
			
		}

		else if (option == 9)
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