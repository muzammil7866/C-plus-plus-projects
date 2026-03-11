#include<iostream>
#include<string>
#include<fstream>
using namespace std;
bool isPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}

	if (num == 2)
	{
		return true;
	}

	for (int i = 2; i < num - 1; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}
int nearestGreaterPrime(int num)
{
	bool prime = false;
	int count = 1;
	while (prime != true)
	{
		if (isPrime(num + count))
		{
			return num + count;
		}

		count++;
	}
}

int suitableHashSize(float stringNumber, float bf)
{
	float roughSize = stringNumber * (1 - bf);
	cout << roughSize << endl;
	roughSize = stringNumber + roughSize;
	cout << roughSize;
	return nearestGreaterPrime(roughSize);
}

class Cell
{
public:
	int data;
	Cell* next;

	Cell()
	{
		data = -1;
		next = nullptr;
	}

	Cell(int a)
	{
		data = a;
		next = nullptr;
	}
};
class Hash
{
public:

	int** arr;
	float size;
	float currSize;
	float bucketNo;

	Hash(int tablesize, int bucketSize)
	{
		size = tablesize;
		bucketNo = bucketSize;

		arr = new int * [size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = new int[bucketNo];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < bucketNo; j++)
			{
				arr[i][j] = -1;
			}
		}
	}

	int hashFunction(const int key)
	{
		return key % int(size);
	}

	int BetterhashFunction(const string str)
	{
		int num = 0;
		int temp;
		for (int i = 0; i < str.length(); i++)
		{
			temp = str[i];
			num += temp;
		}

		cout << num;

		return num % int(size);
	}

	void insert(int a)
	{
		//-2 for deleted
		//-1 for empty
		int key = hashFunction(a);

		if (arr[key][0] == -1 || arr[key][0] == -2)
		{
			arr[key][0] = a;
			cout << a << " INSERTED!";
			currSize++;
		}

		else
		{
			system("pause");
			system("cls");
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO TACKLE THE COLLISION. " << endl;
			cout << "ENTER (1) FOR BUCKETING: ";
			cin >> option;

			if (option == 1)
			{
				bool done = false;
				for (int i = 1; i < bucketNo; i++)
				{
					if (arr[key][i] == -1 || arr[key][i] == -2)
					{
						arr[key][i] = a;
						cout << a << " INSERTED!";
						currSize++;
						done = true;
						break;
					}
				}

				if (done != true)
				{
					cout << "OVERFLOW HAS OCCURED SO CANNOT INSERT!"<<endl;
					cout << "INCREASING THE SIZE OF BUCKETS FROM " << bucketNo << " to " << bucketNo * 2<<endl;

					bucketNo = bucketNo * 2;
					int** newHash = new int* [size];

					for (int i = 0; i < size; i++)
					{
						newHash[i] = new int[bucketNo];
					}

					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < bucketNo; j++)
						{
							newHash[i][j] = -1;
						}
					}

					int** temp = arr;
					arr = newHash;
					currSize = 0;

					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < bucketNo/2; j++)
						{
							if (temp[i][j] != -1 && temp[i][j] != -2)
							{
								insert(temp[i][j]);
							}
						}
					}

					insert(a);
					cout << "YOU CAN CONTINUE IN INSERTING MORE ITEMS INTO THE HASH WITH UPDATED BUCKET SIZE!";
				}

				
				

			}

		}
		checkAndRehashing();
		cout << endl;
	}

	bool search(int a)
	{
		int key = hashFunction(a);


		if (arr[key][0] == -1)
		{
			cout << a << " NOT FOUND!";
			return false;
		}

		else if (arr[key][0] == a)
		{
			cout << a << " FOUND!" << endl;
			return true;
		}

		else
		{
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO SEARCH BASED ON THE COLLISION. " << endl;
			cout << "ENTER (1) FOR BUCKETING: ";
			cin >> option;

			if (option == 1)
			{
				bool done = false;
				for (int i = 1; i < bucketNo; i++)
				{
					if (arr[key][i] == a)
					{
						cout << a << " FOUND!";
						done = true;
						return true;
					}
				}

				if (done != true)
				{
					cout << a << " NOT FOUND!";
					return false;
				}
			}

		}
		cout << endl;
	}

	void deleteValue(int a)
	{
		int key = hashFunction(a);

		if (arr[key][0] == -1)
		{
			cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
		}


		else if (arr[key][0] == a)
		{
			arr[key][0] = -2;

			cout << a << " FOUND AND DELETED!" << endl;
			currSize--;
		}

		else
		{
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO DELETE BASED ON THE COLLISION. " << endl;
			cout << "ENTER (1) FOR BUCKETING: ";
			cin >> option;

			if (option == 1)
			{
				bool done = false;
				for (int i = 1; i < bucketNo; i++)
				{
					if (arr[key][i] == a)
					{
						arr[key][i] = -2;
						cout << a << " FOUND AND DELETED!" << endl;
						currSize--;
						done = true;
						break;
					}
				}

				if (done != true)
				{
					cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
				}

			}

			}

		cout << endl;
	}


	double getBalanceFactor()
	{
		cout << currSize / size;
		return currSize / size;
	}

	void checkAndRehashing()
	{
		//complete rehashing function
		if (getBalanceFactor() > 0.7)
		{
			cout << endl;
			cout << "AS THE LOAD FACTOR OF YOUR HASH HAS INCREASED MORE THAN 70%, THUS REHASHING NEEDS TO BE IMPLEMENTED!" << endl;

			int temp = size;
			int** temp2 = arr;
			int newSize = size * 2;
			int** newHash = new int * [newSize];

			for (int i = 0; i < newSize; i++)
			{
				newHash[i] = new int[bucketNo];
			}


			for (int i = 0; i < newSize; i++)
			{
				for (int j = 0; j < bucketNo; j++)
				{
					newHash[i][j] = -1;
				}
			}
			size = newSize;
			arr = newHash;
			currSize = 0;

			for (int i = 0; i < temp; i++)
			{
				for (int j = 0; j < bucketNo; j++)
				{
					if (temp2[i][j] != -1 && temp2[i][j] != -2)
					{
						insert(temp2[i][j]);
					}
				}
			}


			cout << "REHASHING HAS BEEN SUCCESSFULLY DONE, YOU CAN CONTINUE WITH INSERTING MORE ITEMS INTO THE HASH TABLE!" << endl;

		}

	}


};
int main()
{

	//fstream fHand;
	//fHand.open("Data.txt");

	//if (!fHand.is_open())
	//{
	//	cout << "FILE IS NOT FOUND!";
	//}
	//else
	//{
	//	cout << "FILE IS FOUND!" << endl;

	//	float size = 0;
	//	while (!fHand.eof())
	//	{
	//		string line;
	//		fHand >> line;
	//		cout << line << endl;
	//		size++;
	//	}

	//	fHand.close();
	//	cout << "FILE SIZE: " << size << endl;
	//	float balanceFactor = 0.75;
	//	int hashSize = suitableHashSize(size, balanceFactor);
	//	cout << "SUITABLE HASH SIZE (THAT IS PRIME) W.R.T. THE BALANCE FACTOR: " << hashSize;
	Hash obj(15, 3);

	bool end = false;

	/*system("pause");
	system("cls");*/
	while (end != true)
	{
		system("cls");
		int option = 0;
		cout << "CHOOSE THE OPTION FROM THE MENU" << endl;
		cout << "ENTER (1) FOR INSERTION, ENTER (2) FOR SEARCHING, ENTER (3) FOR DELETION, ENTER (4) TO IMPLEMENT OPEN HASHSING W.R.T. THE QUESTION: ";
		cin >> option;

		if (option == 1)
		{
			int val;
			cout << "ENTER THE INTEGER VALUE TO INSERT: ";
			cin >> val;

			obj.insert(val);
		}
		else if (option == 2)
		{
			int val;
			cout << "ENTER THE INTEGER VALUE TO SEARCH: ";
			cin >> val;

			obj.search(val);
		}


		else if (option == 3)
		{
			int val;
			cout << "ENTER THE INTEGER VALUE TO SEARCH: ";
			cin >> val;

			obj.deleteValue(val);
		}

		else if (option == 4)
		{
			/*fstream fHand;
			fHand.open("Data.txt");

			if (!fHand.is_open())
			{
				cout << "FILE IS NOT FOUND!";
			}
			else
			{
				cout << "FILE IS FOUND!" << endl;

				while (!fHand.eof())
				{
					int line;
					fHand >> line;
					cout << line << endl;
					obj.insert(line);
				}

				fHand.close();
			}*/

			obj.insert(17);
			obj.insert(26);
			obj.insert(15);
			obj.insert(9);
			obj.insert(11);
			obj.insert(43);
			obj.insert(75);
			obj.insert(19);
			obj.insert(35);
			obj.insert(45);
			obj.insert(55);
			obj.insert(9);
			obj.insert(10);
			obj.insert(21);
			obj.insert(61);
			obj.insert(23);
		}

		system("pause");
	}
	system("pause");
	return 0;
}