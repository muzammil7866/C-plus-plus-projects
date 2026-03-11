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

	int* arr;
	float size;
	float currSize;

	Hash(int tablesize)
	{
		size = tablesize;

		arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = -1;
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

		if (arr[key] == -1 || arr[key] == -2)
		{
			cout << a << " INSERTED!";
			arr[key] = a;
			currSize++;
		}

		else
		{
			system("pause");
			system("cls");
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO TACKLE THE COLLISION. "<<endl;
			cout << "ENTER (1) FOR LINEAR PROBING, ENTER (2) FOR QUADRATIC PROBING, ENTER (3) FOR DOUBLE HASHING: ";
			cin >> option;

			if (option == 1) {

				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count;
					if (key>size-1)
					{
						int key2 = 0;
						while (arr[key2] != -1 || arr[key2] != -1)
						{
							key2++;
							if (key2>= hashFunction(a))
							{
								cout << "CANNOT INSERT IN THE VALUE AS HASH LIMIT AS REACHED!";
								done = true;
								break;
							}
						}

						if (key2 >= hashFunction(a))
						{
							break;
						}

						arr[key2] = a;
						cout << a << " INSERTED!";
						currSize++;
						done = true;
					}

					if (arr[key] == -1 || arr[key] == -2)
					{
						cout << a << " INSERTED!";
						arr[key] = a;
						currSize++;
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

					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1 || arr[key] == -2)
						{
							key2++;
							if (key2 >= size-1)
							{
								cout << "CANNOT INSERT IN THE VALUE AS HASH LIMIT AS REACHED!";
								done = true;
								break;
							}
						}

						if (key2 >= size - 1)
						{
							break;
						}

						arr[key2] = a;
						cout << a << " INSERTED!";
						currSize++;
						done = true;
					}

					if (arr[key] == -1 || arr[key] == -2)
					{
						cout << a << " INSERTED!";
						arr[key] = a;
						currSize++;
						done = true;
					}

					count++;

				}
			}
			else if (option == 3)
			{
				bool done = false;
				int count = 0;
				while (done != true)
				{
					int key = hashFunction(a) + hashFunction(a) + count;

					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1 || arr[key] == -2)
						{
							key2++;
							if (key2 >= size - 1)
							{
								cout << "CANNOT INSERT IN THE VALUE AS HASH LIMIT AS REACHED!";
								done = true;
								break;
							}
						}

						if (key2 >= size - 1)
						{
							break;
						}

						arr[key2] = a;
						cout << a << " INSERTED!";
						currSize++;
						done = true;
					}

					if (arr[key] == -1 || arr[key] == -2)
					{
						cout << a << " INSERTED!";
						arr[key] = a;
						currSize++;
						done = true;
					}

					count++;

				}
			}

			else
			{
				cout << "INVALID OPTION!";
			}

		}
		checkAndRehashing();
		cout << endl;
	}

	bool search(int a)
	{
		int key = hashFunction(a);


		if (arr[key] == -1)
		{
			cout << a << " NOT FOUND!";
			return false;
		}

		else if (arr[key] == a)
		{
			cout << a << " FOUND!"<<endl;
			return true;
		}

		else
		{
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO SEARCH BASED ON THE COLLISION. " << endl;
			cout << "ENTER (1) BY LINEAR PROBING, ENTER (2) BY QUADRATIC PROBING, ENTER (3) BY DOUBLE HASHING: ";
			cin >> option;

			if (option == 1) {

				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count;
					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1)
						{
							key2++;
							if (key2 >= hashFunction(a))
							{
								cout << a << " NOT FOUND!";
								return false;
								done = true;
								break;
							}
						}

						if (key2 >= hashFunction(a))
						{
							cout << a << " NOT FOUND!";
							return false;
							break;
						}

						if (arr[key2] == -1)
						{
							cout << a << " NOT FOUND!";
							done = true;
							return false;
						}
						

					}

					if (arr[key] == a)
					{
						cout << a << " FOUND!";
						done = true;
						return true;
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
					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1)
						{
							key2++;
							if (key2 >= size - 1)
							{
								cout << a << " NOT FOUND!";
								return false;
								done = true;
								break;
							}
						}

						if (key2 >= size - 1)
						{
							cout << a << " NOT FOUND!";
							return false;
							break;
						}

						if (arr[key2] == -1)
						{
							cout << a << " NOT FOUND!";
							done = true;
							return false;
						}


					}

					if (arr[key] == a)
					{
						cout << a << " FOUND!";
						done = true;
						return true;
					}

					count++;

				}
			}
			else if (option == 3)
			{
				bool done = false;
				int count = 0;
				while (done != true)
				{
					int key = hashFunction(a) + hashFunction(a) + count;
					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1)
						{
							key2++;
							if (key2 >= size - 1)
							{
								cout << a << " NOT FOUND!";
								return false;
								done = true;
								break;
							}
						}

						if (key2 >= size - 1)
						{
							cout << a << " NOT FOUND!";
							return false;
							break;
						}

						if (arr[key2] == -1)
						{
							cout << a << " NOT FOUND!";
							done = true;
							return false;
						}


					}

					if (arr[key] == a)
					{
						cout << a << " FOUND!";
						done = true;
						return true;
					}

					count++;

				}
			}

			else
			{
				cout << "INVALID OPTION!";
			}

		}
		cout << endl;
	}

	void deleteValue(int a)
	{
		int key = hashFunction(a);

		if (arr[key] == -1)
		{
			cout<< a << " NOT FOUND!";
		}


		else if (arr[key] == a)
		{
			arr[key] = -2;
			cout << a << " FOUND AND DELETED!" << endl;
			currSize--;
		}

		else
		{
			int option;
			cout << "CHOOSE OPTION FOR HOW DO YOU WANT TO DELETE BASED ON THE COLLISION. " << endl;
			cout << "ENTER (1) FOR LINEAR PROBING, ENTER (2) FOR QUADRATIC PROBING, ENTER (3) FOR DOUBLE HASHING: ";
			cin >> option;

			if (option == 1) {

				bool done = false;
				int count = 1;
				while (done != true)
				{
					int key = hashFunction(a) + count;
					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1)
						{
							key2++;
							if (key2 >= hashFunction(a))
							{
								cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
								done = true;
								break;
							}
						}

						if (key2 >= hashFunction(a))
						{
							cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
							break;
						}

						if (arr[key2] == -1)
						{
							cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
							done = true;
						}


					}

					if (arr[key] == a)
					{
						cout << a << " FOUND AND DELETED!";
						arr[key] = -2;
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
					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1)
						{
							key2++;
							if (key2 >= size - 1)
							{
								cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
								done = true;
								break;
							}
						}

						if (key2 >= size - 1)
						{
							cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
							break;
						}

						if (arr[key2] == -1)
						{
							cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
							done = true;
						}


					}

					if (arr[key] == a)
					{
						cout << a << " FOUND AND DELETED!";
						arr[key] = -2;
						done = true;
					}

					count++;

				}
			}
			else if (option == 3)
			{
				bool done = false;
				int count = 0;
				while (done != true)
				{
					int key = hashFunction(a) + hashFunction(a) + count;
					if (key > size - 1)
					{
						int key2 = 0;
						while (arr[key2] != -1)
						{
							key2++;
							if (key2 >= size - 1)
							{
								cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
								done = true;
								break;
							}
						}

						if (key2 >= size - 1)
						{
							cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
							break;
						}

						if (arr[key2] == -1)
						{
							cout << a << " NOT FOUND SO COULD NOT BE DELETED!";
							done = true;
						}


					}

					if (arr[key] == a)
					{
						cout << a << " FOUND AND DELETED!";
						arr[key] = -2;
						done = true;
					}

					count++;

				}
			}

			else
			{
				cout << "INVALID OPTION!";
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
		if (getBalanceFactor() > 0.7)
		{
			cout << endl;
			cout << "AS THE LOAD FACTOR OF YOUR HASH HAS INCREASED MORE THAN 70%, THUS REHASHING NEEDS TO BE IMPLEMENTED!"<<endl;

			int temp = size;
			int* temp2 = arr;
			int newSize = size * 2;
			int* newHash = new int[newSize];

			for (int i = 0; i < newSize; i++)
			{
				newHash[i] = -1;
			}
			
			size = newSize;
			arr = newHash;
			currSize = 0;

			for (int i = 0; i < temp; i++)
			{
				if (temp2[i] != -1 && temp2[i] != -2)
				{
					insert(temp2[i]);
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
		Hash obj(15);

		bool end = false;

		/*system("pause");
		system("cls");*/
		while (end != true)
		{
			system("cls");
			int option = 0;
			cout << "CHOOSE THE OPTION FROM THE MENU" << endl;
			cout << "ENTER (1) FOR INSERTION, ENTER (2) FOR SEARCHING, ENTER (3) FOR DELETION, ENTER (4) TO IMPLEMENT CLOSED HASHSING W.R.T. THE QUESTION: ";
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