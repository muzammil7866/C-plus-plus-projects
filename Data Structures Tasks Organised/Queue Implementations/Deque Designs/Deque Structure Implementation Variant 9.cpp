#include<iostream>
#include<string>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class Stack
{
public:
	int top;
	static int size;
	char array[20];


	Stack()
	{
		top = -1;
		size = 20;
		for (int i = 0; i <= size - 1; i++)
		{
			array[i] = 0;
		}
	}


	void push(char a)
	{
		if (top + 1 < size)
		{
			top++;
			array[top] = a;
		}

		else
		{
			cout << "YOUR STACK IS FULL! IT CANNOT PUSH MORE ITEMS INTO THE STACK." << endl;
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

	int pop()
	{
		if (top > -1)
		{

			//cout << "ENTER THE POPPING ITEM WHICH YOU WANT TO ENTER INTO THE STACK AT THE INDEX " << top << ": ";
			//cin >> array[top];
			int temp = array[top];
			array[top] = 0;
			top--;
			return temp;
		}

		else
		{
			cout << "YOUR STACK IS EMPTY! IT CANNOT POP MORE ITEMS OFF THE STACK." << endl;
		}


	}

	int getTop()
	{
		if (top == -1)
		{
			cout << "STACK IS EMPTY";
		}
		else
			return array[top];
	}

	int peek(int pos)
	{
		return array[pos - 1];
	}

	void display()
	{
		for (int i = size - 1; i >= 0; i--)
		{
			cout << array[i];
			cout << endl;
		}
	}

	int count()
	{
		return top + 1;
	}

};
int Stack::size = 20;


class Queue
{
public:
	int* array;
	int maxSize;
	int front;
	int end;

	Queue()
	{
		maxSize = 50;
		array = new int[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			array[i] = 0;
		}

		front = -1;
		end = -1;
	}

	int getFront()
	{
		return array[front];
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
class Vertex {

public:

	int label;

	Vertex()
	{
		label = 1;
	}

	Vertex(int label)
	{
		this->label = label;
	}

};

class Edge {

public:
	char data;

	Edge()
	{
		data = '0';
	}

	Edge(char data)
	{
		this->data = data;
	}
};

class Graph
{
public:

	Vertex* ver;
	Edge** edg;
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

		edg = new Edge * [vertexCount];

		for (int i = 0; i < vertexCount; i++)
		{
			edg[i] = new Edge[vertexCount];
		}

	}

	void makeEmpty()
	{

		for (int i = 0; i < vertexCount; i++)
		{
			ver[i].label = i+1;
		}


		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				edg[i][j] = '0';
			}
		}



	}

	void addVertex(Vertex& obj)
	{
		vertexCount++;

		Vertex* ver2= new Vertex[vertexCount];

		for (int i = 0; i < vertexCount - 1; i++)
		{
			ver2[i] = ver[i];
		}


		ver2[vertexCount - 1].label = obj.label;

		Edge** edg2 = new Edge * [vertexCount];

		for (int i = 0; i < vertexCount; i++)
		{
			edg2[i] = new Edge[vertexCount];
		}

		for (int i = 0; i < vertexCount - 1; i++)
		{
			for (int j = 0; j < vertexCount - 1; j++)
			{
				edg2[i][j] = edg[i][j];
			}
		}

		for (int i = 0; i < vertexCount; i++)
		{
			edg2[vertexCount - 1][i] = '0';
			edg2[i][vertexCount - 1] = '0';
		}

		edg = edg2;
		ver = ver2;

	}

	void addEdgeUD(Vertex from, Vertex to, char data)
	{

		edg[vertexIndex(from)][vertexIndex(to)].data = data;
		edg[vertexIndex(to)][vertexIndex(from)].data = data;

	}

	void addEdgeD(Vertex from, Vertex to, char data)
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

	/*int vertexIndexC(Vertex obj)
	{

		for (int i = 0; i < vertexCount; i++)
		{
			if (ver[i].label == obj.label)
			{
				return i;
			}

		}


		return -1;
	}*/

	char weight(Vertex from, Vertex to)
	{
		return edg[vertexIndex(from)][vertexIndex(to)].data;
	}

		void DFS()
	{
		if (vertexCount == 0)
		{
			cout << "GRAPH IS EMPTY!";
		}
		else
		{
			Stack obj;
			bool* visited = new bool[vertexCount];
			for (int i = 0; i < vertexCount; i++)
			{
				visited[i] = false;
			}


			for (int i = 0; i < vertexCount; i++)
			{
				Vertex* frontNode = &ver[i];
				obj.push(frontNode->label);
				while (!(obj.top == -1))
				{
					int temp = obj.pop();
					Vertex temp3(temp);
					int temp2 = vertexIndex(temp3);

					if (visited[temp2] == false)
						cout << temp << " ";

					visited[temp2] = true;


					Queue temp4;

					Vertex temp5(temp);
					getToVertices(temp5, temp4);

					while (!temp4.isEmpty())
					{
						Vertex temp(temp4.getFront());
						if (visited[vertexIndex(temp)] != true)
						{
							obj.push(temp4.dequeue());
						}

						else
						{
							temp4.dequeue();
						}
					}
				}
			}
		}
	}
	void BFS()
	{
		if (vertexCount == 0)
		{
			cout << "GRAPH IS EMPTY!";
		}
		else
		{
			Queue obj;
			bool* visited = new bool[vertexCount];
			for (int i = 0; i < vertexCount; i++)
			{
				visited[i] = false;
			}


			for (int i = 0; i < vertexCount; i++)
			{
				Vertex* frontNode = &ver[i];
				obj.enqueue(frontNode->label);
				while (!obj.isEmpty())
				{
					int temp = obj.dequeue();
					Vertex temp3(temp);
					int temp2 = vertexIndex(temp3);

					if (visited[temp2] == false)
						cout << temp << " ";

					visited[temp2] = true;


					Queue temp4;

					Vertex temp5(temp);
					getToVertices(temp5, temp4);

					while (!temp4.isEmpty())
					{
						Vertex temp(temp4.getFront());
						if (visited[vertexIndex(temp)] != true)
						{
							obj.enqueue(temp4.dequeue());
						}

						else
						{
							temp4.dequeue();
						}
					}
				}
			}
		}
	}


	Queue getToVertices(Vertex& a, Queue& b)
	{
		for (int i = 0; i < vertexCount; i++)
		{
			if (edg[vertexIndex(a)][i].data != '0')
				b.enqueue(ver[i].label);
		}

		return b;
	}


	void display()
	{
		cout << setw(6)<<" ";
		for (int i = 0; i < vertexCount; i++)
		{
			cout << setw(3)<<ver[i].label << " ";
		}

		cout << endl;
		for (int i = 0; i < vertexCount; i++)
		{
			cout << setw(5)<<ver[i].label << " ";
			for (int j = 0; j < vertexCount; j++)
			{
				cout <<setw(3)<< edg[i][j].data << " ";
			}
			cout << endl;
		}
	}


	void generateAMWrtData(char ** data)
	{
		int count = 15;
		int count2 = 1;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (data[i][j] != '1' && i - 1 >= 0 && data[i - 1][j] != '1') //up
				{
					edg[vertexIndex(count2)][vertexIndex(count2-15)].data = data[i-1][j];
				}

				if (data[i][j] != '1' && j + 1 <= 14 && data[i][j+1] != '1') //right
				{
					edg[vertexIndex(count2)][vertexIndex(count2 + 1)].data = data[i][j + 1];
				}
				
				if (data[i][j] != '1' && i - 1 >= 0 && j + 1 <= 14 && data[i - 1][j+1] != '1') //up and right
				{
					edg[vertexIndex(count2)][vertexIndex(count2 -14)].data = data[i-1][j + 1];
				}
				count2++;

			}
		}
	}

};
int main()
{
	fstream fHand;
	fHand.open("robot.txt");

	if (!fHand.is_open())
	{
		cout << "CANNOT OPEN YOUR FILE!" << endl;
	}
	else
	{
		cout << "FILE READ SUCCESSFUL!" << endl;
		int countR = 15;
		int countC = 15;
		char** data = new char* [countR];

		for (int i = 0; i < countR; i++)
		{
			data[i] = new char[countC];
		}

		for (int i = 0; i < countR; i++)
		{
			for (int j = 0; j < countC; j++)
			{
				data[i][j] = '0';
			}
		}


		for (int i = 0; i < countR; i++)
		{
			string line;
			getline(fHand, line);
			int size = line.size();

			for (int j = 0; j < countC; j++)
			{
				data[i][j] = line[j];
			}
		}

		fHand.close();

		for (int i = 0; i < countR; i++)
		{
			for (int j = 0; j < countC; j++)
			{
				cout << data[i][j];
			}

			cout << endl;
		}

		Graph obj(15*15);
		obj.makeEmpty();
		obj.generateAMWrtData(data);


		// 0 for empty
		// 1 for obstacle
		// 2 for start
		// 3 for goal

		/*fHand.open("robot.txt");

		if (!fHand.is_open())
		{
			cout << "CANNOT OPEN YOUR FILE!" << endl;
		}
		else
		{
			cout << "FILE READ SUCCESSFUL!" << endl;


			while (rowCount > 0)
			{
				string line;
				getline(fHand, line);
				int size = line.size();
				cout << line << endl;
				int colCount = 0;
				while (colCount < size)
				{

					Vertex* a = new Vertex(rowCount);
					Vertex* b = new Vertex(colCount + 1);
					obj.addEdgeD(*a, *b, line[colCount]);

					colCount++;
				}
				rowCount--;
			}*/

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
				cout << "6) BFS" << endl;
				cout << "7) DFS" << endl;
				cout << "8) DIJKSTRA" << endl;
				cout << "9) DISPLAY" << endl;
				cout << "10) EXIT" << endl;
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
					int temp = obj.vertexCount + 1;

					Vertex temp2(temp);

					obj.addVertex(temp2);
					system("pause");
					system("cls");
				}

				if (option == 3)
				{
					int from, to;
					cout << "ENTER LABEL OF THE FROM VERTEX: ";
					cin >> from;

					cout << "ENTER LABEL OF THE TO VERTEX: ";
					cin >> to;

					Vertex a(from), b(to);

					char temp;
					cout << "ENTER WEIGHT TO ADD: ";
					cin >> temp;

					obj.addEdgeUD(a, b, temp);
					system("pause");
					system("cls");
				}

				if (option == 4)
				{
					int from, to;
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
					int temp2;
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
					obj.BFS();
					system("pause");
					system("cls");
				}

				if (option == 7)
				{
					obj.DFS();
					system("pause");
					system("cls");
				}

				if (option == 8)
				{

					system("pause");
					system("cls");
				}

				if (option == 9)
				{
					obj.display();
					system("pause");
					system("cls");
				}

				if (option == 10)
				{
					end = true;
					system("pause");
					system("cls");
				}
			}

		}


		return 0;
	}