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
	float roughSize = stringNumber * (1-bf);
	cout << roughSize<<endl;
	roughSize = stringNumber + roughSize;
	cout << roughSize;
	return nearestGreaterPrime(roughSize);
}

class Hash
{
public:

	string* arr;
	int size;

	Hash(int tablesize)
	{
		size = tablesize;

		arr = new string[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = "empty";
		}
	}

	int hashFunction(const string str)
	{
		return str.length();
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

		return num % size;
	}

	void insert(string a)
	{
		int key = hashFunction(a);

		if (arr[key] == "empty")
		{
			cout << "INSERTED!";
			arr[key] = a;
		}

		else
		{
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO TACKLE THE COLLISION. "<<endl;
			cout << "ENTER (1) FOR LINEAR PROBING, ENTER (2) FOR QUADRATIC PROBING, ENTER (3) FOR SEPERATE CHAINING: ";
			cin >> option;

			if (option == 1) {

				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count;
					if (arr[key] == "empty")
					{
						cout << "INSERTED!"<<endl;
						arr[key] = a;
						done = true;
					}

					count++;

				}
			}

			else if (option == 2)
			{
				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count*count;
					if (arr[key] == "empty")
					{
						cout << "INSERTED!" << endl;
						arr[key] = a;
						done = true;
					}

					count++;

				}
			}
			//else if (option == 3)
			//{
			//	string** temp = new string * [size];

			//	for (int i = 0; i < size; i++)
			//	{
			//		arr[i] = nullptr;
			//	}

			//	arr = *temp;
			//}

			else
			{
				cout << "INVALID OPTION!";
			}

		}
	}

	bool search(string a)
	{
		int key = hashFunction(a);

		if (arr[key] == "empty")
		{
			cout << "NOT FOUND!";
		}

		else if (arr[key] == a)
		{
			cout << "FOUND!"<<endl;
		}

		else
		{
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO SEARCH BASED ON THE COLLISION. " << endl;
			cout << "ENTER (1) BY LINEAR PROBING, ENTER (2) BY QUADRATIC PROBING, ENTER (3) BY SEPERATE CHAINING: ";
			cin >> option;

			if (option == 1) {

				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count;
					if (arr[key] == a)
					{
						cout << "FOUND!";
						return true;
					}

					else if (arr[key] == "empty")
					{
						return false;
					}

					count++;

				}
			}

			else if (option == 2)
			{
				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count*count;
					if (arr[key] == a)
					{
						cout << "FOUND!" << endl;
						return true;
					}

					else if (arr[key] == "empty")
					{
						return false;
					}

					count++;

				}
			}
			/*else if (option == 3)
			{
				string** temp = new string * [size];

				for (int i = 0; i < size; i++)
				{
					arr[i] = nullptr;
				}

				arr = *temp;
			}*/

			else
			{
				cout << "INVALID OPTION!";
			}

		}
	}

	void deleteValue(string a)
	{
		int key = hashFunction(a);

		if (arr[key] == "empty")
		{
			cout<<"VALUE NOT FOUND!";
		}


		else if (arr[key] == a)
		{
			arr[key] = "empty";
			cout << "FOUND AND DELETED!" << endl;
		}

		else
		{
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO DELETE BASED ON THE COLLISION. " << endl;
			cout << "ENTER (1) FOR LINEAR PROBING, ENTER (2) FOR QUADRATIC PROBING, ENTER (3) FOR SEPERATE CHAINING: ";
			cin >> option;

			if (option == 1) {

				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count;
					if (arr[key] == a)
					{
						cout << "FOUND AND DELETED!";
						arr[key] = "empty";
						done = true;
				
					}

					count++;

				}
			}

			else if (option == 2)
			{
				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count * count;
					if (arr[key] == a)
					{
						cout << "FOUND AND DELETED!";
						arr[key] = "empty";
						done = true;
					}

					count++;

				}
			}
			/*else if (option == 3)
			{
				string** temp = new string * [size];

				for (int i = 0; i < size; i++)
				{
					arr[i] = nullptr;
				}

				arr = *temp;
			}*/

			else
			{
				cout << "INVALID OPTION!";
			}

		}
	}



};
int main()
{

	fstream fHand;
	fHand.open("Data.txt");

	if (!fHand.is_open())
	{
		cout << "FILE IS NOT FOUND!";
	}
	else
	{
		cout << "FILE IS FOUND!" << endl;

		float size = 0;
		while (!fHand.eof())
		{
			string line;
			fHand >> line;
			cout << line << endl;
			size++;
		}

		fHand.close();
		cout << "FILE SIZE: " << size << endl;
		float balanceFactor = 0.75;
		int hashSize = suitableHashSize(size, balanceFactor);
		cout << "SUITABLE HASH SIZE (THAT IS PRIME) W.R.T. THE BALANCE FACTOR: " << hashSize;

		Hash obj(hashSize);

		bool end = false;

		system("pause");
		system("cls");
		while (end != true)
		{
			system("cls");
			int option = 0;
			cout << "CHOOSE THE OPTION FROM THE MENU" << endl;
			cout << "ENTER (1) FOR INSERTION, ENTER (2) FOR SEARCHING, ENTER (3) FOR DELETION, ENTER (4) TO ENTER THE FILE DATA INTO THE HASH TABLE: ";
			cin >> option;

			if (option == 1)
			{
				string val;
				cout << "ENTER THE STRING VALUE TO INSERT: ";
				cin >> val;

				obj.insert(val);
			}
			else if (option == 2)
			{
				string val;
				cout << "ENTER THE STRING VALUE TO SEARCH: ";
				cin >> val;

				obj.search(val);
			}


			else if (option == 3)
			{
				string val;
				cout << "ENTER THE STRING VALUE TO SEARCH: ";
				cin >> val;

				obj.deleteValue(val);
			}

			else if (option == 4)
			{
				fstream fHand;
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
						string line;
						fHand >> line;
						cout << line << endl;
						obj.insert(line);
					}

					fHand.close();
				}
			}

			system("pause");
		}
	}
	system("pause");
	return 0;


}