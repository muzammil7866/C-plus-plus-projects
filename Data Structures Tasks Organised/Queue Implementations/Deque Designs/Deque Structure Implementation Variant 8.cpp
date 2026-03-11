#include<iostream>
using namespace std;
class Queue
{
public:
	char *array;
	int maxSize;
	int front;
	int end;

	Queue()
	{
		maxSize = 20;
		array = new char[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			array[i] = '\0';
		}

		front = -1;
		end = -1;
	}

	void enqueue(char a)
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

	char dequeue()
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
class Vertex {

public:

	char label;

	Vertex()
	{
		label = '\0';
	}

	Vertex(char label)
	{
		this->label = label;
	}

};
	
class Edge {

public:
	int data;

	Edge()
	{
		data = 0;
	}

	Edge(int data)
	{
		this->data = data;
	}
};

class Graph
{
public:

	Vertex *ver;
	Edge **edg;
	int vertexCount;

	Graph()
	{
		ver = nullptr;
		edg = nullptr;
		vertexCount = 0;
	}



	Graph(int a)
	{
		vertexCount = a;

		ver = new Vertex[vertexCount];

		edg = new Edge*[vertexCount];

		for (int i = 0; i < vertexCount; i++)
		{
			edg[i] = new Edge[vertexCount];
		}

	}

	void makeEmpty()
	{
		char a = 65;

		for (int i = 0; i < vertexCount; i++)
		{
			ver[i].label = a;
			a++;
		}

		
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				edg[i][j] = -1;
			}
		}

		

	}


	void addVertex(Vertex& obj)
	{
		vertexCount++;

		Vertex* ver2 = new Vertex[vertexCount];

		for (int i = 0; i < vertexCount-1; i++)
		{
			ver2[i] = ver[i];
		}

		ver2[vertexCount - 1].label = obj.label;

		Edge** edg2 = new Edge*[vertexCount];

		for (int i = 0; i < vertexCount; i++)
		{
			edg2[i] = new Edge[vertexCount];
		}

		for (int i = 0; i < vertexCount-1; i++)
		{
			for (int j = 0; j < vertexCount-1; j++)
			{
				edg2[i][j] = edg[i][j];
			}
		}

		for (int i = 0; i < vertexCount; i++)
		{
			edg2[vertexCount - 1][i] = -1;
			edg2[i][vertexCount-1] = -1;
		}

		edg = edg2;
		ver = ver2;

	}

	void addEdgeUD(Vertex from, Vertex to, int data)
	{
		
		edg[vertexIndex(from)][vertexIndex(to)].data = data;
		edg[vertexIndex(to)][vertexIndex(from)].data = data;

	}

	void addEdgeD(Vertex from, Vertex to, int data)
	{

		edg[vertexIndex(from)][vertexIndex(to)].data = data;

	}

	int vertexIndex(Vertex obj)
	{
		
		for (int i = 0; i < vertexCount; i++)
		{
			if (ver[i].label == obj.label)
			{
				return i;
			}

		}


		return -1;
	}

	int weight(Vertex from, Vertex to)
	{
		return edg[vertexIndex(from)][vertexIndex(to)].data;
	}


	Queue getToVertices(Vertex& a, Queue& b)
	{
		for (int i = 0; i < vertexCount; i++)
		{
			if(edg[vertexIndex(a)][i].data != -1)
				b.enqueue(ver[i].label);
		}

		return b;
	}


	void display()
	{
		cout << " ";
		for (int i = 0; i < vertexCount; i++)
		{
			cout<<ver[i].label<<" ";
		}

		cout << endl;
		for (int i = 0; i < vertexCount; i++)
		{
			cout << ver[i].label << " ";
			for (int j = 0; j < vertexCount; j++)
			{
				cout<<edg[i][j].data<<" ";
			}
			cout << endl;
		}
	}

};
int main()
{

	bool end1 = false;

	while (end1 != true)
	{
		int ch;
		cout << "ENTER (1) IF YOU WANT TO CREATE A DIRECTED GRAPH AND ENTER (2) IF YOU WANT TO CREATE A UNDIRECTED GRAPH: ";
		cin >> ch;

		system("cls");

		if (ch == 1)
		{
			int size;
			cout << "ENTER THE NUMBER OF VERTEX IN GRAPH: ";
			cin >> size;

			if (size < 0)
			{
				cout << "INVALID INPUT!";
			}

			else
			{
				Graph obj(size);
				Vertex ver1('A');
				Vertex ver2('B');
				Vertex ver3('C');
				Vertex ver4('D');

				int option;
				bool end = false;

				while (end != true)
				{
					cout << "CHOOSE OPTION:" << endl;
					cout << "1) MAKE EMPTY (MUST)" << endl;
					cout << "2) ADD VERTEX" << endl;
					cout << "3) ADD EDGE" << endl;
					cout << "4) WEIGHT" << endl;
					cout << "5) ADJACENT VERTICES" << endl;
					cout << "6) DISPLAY" << endl;
					cout << "7) EXIT" << endl;
					cout << "ENTER: ";
					cin >> option;

					if (option == 1)
					{
						obj.makeEmpty();
						system("pause");
						system("cls");
					}

					if (option == 2)
					{
						char temp;
						cout << "ADD LABEL OF VERTEX: ";
						cin >> temp;

						Vertex temp2(temp);

						obj.addVertex(temp2);
						system("pause");
						system("cls");
					}

					if (option == 3)
					{
						char from, to;
						cout << "ENTER LABEL OF THE FROM VERTEX: ";
						cin >> from;

						cout << "ENTER LABEL OF THE TO VERTEX: ";
						cin >> to;

						Vertex a(from), b(to);

						int temp;
						cout << "ENTER WEIGHT TO ADD: ";
						cin >> temp;

						obj.addEdgeD(a, b, temp);
						system("pause");
						system("cls");
					}

					if (option == 4)
					{

						char from, to;
						cout << "ENTER LABEL OF THE FROM VERTEX: ";
						cin >> from;

						cout << "ENTER LABEL OF THE TO VERTEX: ";
						cin >> to;

						Vertex a(from), b(to);

						cout << obj.weight(a, b);
						system("pause");
						system("cls");
					}

					if (option == 5)
					{
						Queue temp;
						char temp2;
						cout << "ADD LABEL OF THE VERTEX TO GET TO ITS ADJACENT VERTICES: ";
						cin >> temp2;

						Vertex temp3(temp2);

						temp = obj.getToVertices(temp3, temp);

						while (!temp.isEmpty())
						{
							cout << temp.dequeue() << " ";
						}


						system("pause");
						system("cls");
					}

					if (option == 6)
					{
						obj.display();
						system("pause");
						system("cls");
					}

					if (option == 7)
					{
						end = true;
						end1 = true;
						system("pause");
						system("cls");
					}
				}
			}
		}

		else if (ch == 2)
		{
			int size;
			cout << "ENTER THE NUMBER OF VERTEX IN GRAPH: ";
			cin >> size;

			if (size < 0)
			{
				cout << "INVALID INPUT!";
			}

			else
			{
				Graph obj(size);
				Vertex ver1('A');
				Vertex ver2('B');
				Vertex ver3('C');
				Vertex ver4('D');

				int option;
				bool end = false;

				while (end != true)
				{
					cout << "CHOOSE OPTION:" << endl;
					cout << "1) MAKE EMPTY (MUST)" << endl;
					cout << "2) ADD VERTEX" << endl;
					cout << "3) ADD EDGE" << endl;
					cout << "4) WEIGHT" << endl;
					cout << "5) ADJACENT VERTICES" << endl;
					cout << "6) DISPLAY" << endl;
					cout << "7) EXIT" << endl;
					cout << "ENTER: ";
					cin >> option;

					if (option == 1)
					{
						obj.makeEmpty();
						system("pause");
						system("cls");
					}

					if (option == 2)
					{
						char temp;
						cout << "ADD LABEL OF VERTEX: ";
						cin >> temp;

						Vertex temp2(temp);

						obj.addVertex(temp2);
						system("pause");
						system("cls");
					}

					if (option == 3)
					{
						char from, to;
						cout << "ENTER LABEL OF THE FROM VERTEX: ";
						cin >> from;

						cout << "ENTER LABEL OF THE TO VERTEX: ";
						cin >> to;

						Vertex a(from), b(to);

						int temp;
						cout << "ENTER WEIGHT TO ADD: ";
						cin >> temp;

						obj.addEdgeUD(a, b, temp);
						system("pause");
						system("cls");
					}

					if (option == 4)
					{
						char from, to;
						cout << "ENTER LABEL OF THE FROM VERTEX: ";
						cin >> from;

						cout << "ENTER LABEL OF THE TO VERTEX: ";
						cin >> to;

						cout << obj.weight(from, to);
						system("pause");
						system("cls");
					}

					if (option == 5)
					{
						Queue temp;
						char temp2;
						cout << "ADD LABEL OF THE VERTEX TO GET TO ITS ADJACENT VERTICES: ";
						cin >> temp2;

						Vertex temp3(temp2);

						temp = obj.getToVertices(temp3, temp);

						while (!temp.isEmpty())
						{
							cout << temp.dequeue() << " ";
						}


						system("pause");
						system("cls");
					}

					if (option == 6)
					{
						obj.display();
						system("pause");
						system("cls");
					}

					if (option == 7)
					{
						end = true;
						end1 = true;
						system("pause");
						system("cls");
					}
				}
			}
		}



		}

	system("pause");
	return 0;
}