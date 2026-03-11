#include<iostream>
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

	bool connected()
	{

	}

};
int Stack::size = 20;

class Queue
{
public:
	char* array;
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

	int getFront()
	{
		return array[front];
	}
};
class Vertex {

public:

	char label;
	Vertex* next;
	int weight;

	Vertex()
	{
		label = '\0';
		weight = 0;
		next = nullptr;
	}

	Vertex(char label, int w)
	{
		this->label = label;
		next = nullptr;
		weight = w;
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

	Vertex* ver;
	int vertexCount;

	Graph()
	{
		ver = nullptr;
		vertexCount = 0;

		makeEmpty();
	}



	Graph(int a)
	{
		vertexCount = a;
		ver = new Vertex[vertexCount];
		makeEmpty();


	}

	void makeEmpty()
	{

		char a = 65;

		for (int i = 0; i < vertexCount; i++)
		{
			ver[i].label = a;
			a++;
		}

	}


	void addVertex()
	{
		char temp = 65;
		vertexCount++;
		Vertex* ver2 = new Vertex[vertexCount];

		for (int i = 0; i < vertexCount - 1; i++)
		{
			ver2[i] = ver[i];
			temp++;
		}

		Vertex* obj = new Vertex(temp, 0);
		ver2[vertexCount - 1] = *obj;

		ver = ver2;

	}

	void addEdgeD(Vertex from, Vertex to, int data)
	{
		if (from.label == to.label)
		{
			ver[vertexIndex(to)].weight = data;
		}
		else
		{
			Vertex* nextObj = new Vertex;
			nextObj->label = to.label;
			nextObj->weight = data;

			Vertex* temp = &ver[vertexIndex(from)];
			cout << temp->label;

			bool quick = false;
			while (temp->next != nullptr)
			{
				if (temp->next->label > to.label && temp->next->next == nullptr)
				{
					Vertex* forward = temp->next;
					temp->next = nextObj;
					nextObj->next = forward;
					quick = true;
				}


				temp = temp->next;
			}
			if (quick == false)
			{
				temp->next = nextObj;
			}
		}
	}

	void addEdgeUD(Vertex from, Vertex to, int data)
	{
		if (from.label == to.label)
		{
			ver[vertexIndex(to)].weight = data;
		}
		else
		{
			Vertex* nextObj = new Vertex;
			nextObj->label = to.label;
			nextObj->weight = data;

			Vertex* temp = &ver[vertexIndex(from)];
			cout << temp->label;

			bool quick = false;
			while (temp->next != nullptr)
			{
				if (temp->next->label > to.label && temp->next->next == nullptr)
				{
					Vertex* forward = temp->next;
					temp->next = nextObj;
					nextObj->next = forward;
					quick = true;
				}


				temp = temp->next;
			}
			if (quick == false)
			{
				temp->next = nextObj;
			}
		}
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
		if (vertexIndex(from) == -1 || vertexIndex(to) == -1)
		{
			cout << "INVALID ENTRY!";
		}
		else
		{
			Vertex* temp = &ver[vertexIndex(from)];

			while (temp != nullptr)
			{
				if (temp->label == to.label) {
					return temp->weight;
				}

				temp = temp->next;
			}
		}
	}


	Queue getToVertices(Vertex& a, Queue& b)
	{
		if (vertexIndex(a) == -1)
		{
			cout << "INVALID ENTRY!";
		}
		else
		{
			Vertex* temp = &ver[vertexIndex(a)];

			if (temp->weight != 0)
			{
				b.enqueue(temp->label);

			}

			temp = temp->next;

			while (temp != nullptr)
			{
				b.enqueue(temp->label);
				temp = temp->next;
			}


			return b;
		}
	}


	void display()
	{

		for (int i = 0; i < vertexCount; i++)
		{
			Vertex* temp = &ver[i];

			while (temp != nullptr)
			{
				cout << temp->label << "(" << temp->weight << ") ";

				temp = temp->next;
			}

			cout << endl;

		}
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
					char temp = obj.pop();
					Vertex temp3(temp, 0);
					int temp2 = vertexIndex(temp3);

					if (visited[temp2] == false)
					{
						cout << temp << " ";
						visited[temp2] = true;
					}


					Queue temp4;

					Vertex temp5(temp, 0);
					getToVertices(temp5, temp4);

					while (!temp4.isEmpty())
					{
						Vertex temp(temp4.getFront(), 0);
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
	bool cycleDetectUD()
	{
		if (vertexCount == 0)
		{
			cout << "GRAPH IS EMPTY!";
		}
		else
		{
			Stack obj;
			bool* visited = new bool[vertexCount];
			int* otherCheck = new int[vertexCount];
			for (int i = 0; i < vertexCount; i++)
			{
				visited[i] = false;
			}

			for (int i = 0; i < vertexCount; i++)
			{
				otherCheck[i] = -1;
			}



			for (int i = 0; i < vertexCount; i++)
			{

				for (int i = 0; i < vertexCount; i++)
				{
					visited[i] = false;
				}

				for (int i = 0; i < vertexCount; i++)
				{
					otherCheck[i] = -1;
				}

				Vertex* frontNode = &ver[i];
				obj.push(frontNode->label);
				while (!(obj.top == -1))
				{
					Vertex tempVer(obj.getTop(), 0);
					bool tempPresent = otherCheck[vertexIndex(tempVer)];

					char temp = obj.pop();
					Vertex temp3(temp, 0);
					int temp2 = vertexIndex(temp3);

					if (visited[temp2] == false)
					{

						cout << temp << " ";
						visited[temp2] = true;
						otherCheck[temp2] = 1;

					}

					else if (otherCheck[temp2] == 1)
					{
						return true;
					}

					Queue temp4;

					Vertex temp5(temp, 0);
					getToVertices(temp5, temp4);

					while (!temp4.isEmpty())
					{
						Vertex temp(temp4.getFront(), 0);
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

		return false;
	}

	bool cycleDetectD()
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

				for (int i = 0; i < vertexCount; i++)
				{
					visited[i] = false;
				}

				Vertex* frontNode = &ver[i];
				obj.push(frontNode->label);
				while (!(obj.top == -1))
				{

					char temp = obj.pop();
					Vertex temp3(temp, 0);
					int temp2 = vertexIndex(temp3);

					if (visited[temp2] == false)
					{

						cout << temp << " ";
						visited[temp2] = true;

					}

					Queue temp4;

					Vertex temp5(temp, 0);
					getToVertices(temp5, temp4);

					while (!temp4.isEmpty())
					{
						Vertex temp(temp4.getFront(), 0);
						if (visited[vertexIndex(temp)] != true)
						{
							obj.push(temp4.dequeue());
						}



						else
						{
							return true;
						}
					}
				}
			}
		}

		return false;
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
					char temp = obj.dequeue();
					Vertex temp3(temp, 0);
					int temp2 = vertexIndex(temp3);

					if (visited[temp2] == false)
						cout << temp << " ";

					visited[temp2] = true;


					Queue temp4;

					Vertex temp5(temp, 0);
					getToVertices(temp5, temp4);

					while (!temp4.isEmpty())
					{
						Vertex temp(temp4.getFront(), 0);
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



	int getVertexCount()
	{
		return vertexCount;
	}

	bool search(Vertex a, char b)
	{
		Vertex* temp = &a;
		while (temp != nullptr)
		{
			if (temp->label == b)
			{
				return true;
			}

			temp = temp->next;
		}
		return false;
	}


	bool checkConnected()
	{

		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{

				if (search(ver[i], ver[j].label) == false && ver[i].label != ver[j].label)
				{
					return false;
				}

			}
		}

		return true;
	}

	bool isBipartite(Graph& graph) {
		int vertexCount = graph.getVertexCount();
		if (vertexCount == 0) {
			cout << "GRAPH IS EMPTY!";
			return false;
		}

		int* color = new int[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			color[i] = -1; // Initialize color as unassigned
		}

		Queue queue;
		for (int i = 0; i < vertexCount; i++) {
			if (color[i] == -1) {
				color[i] = 1; // Assign the first color to the source vertex

				queue.enqueue(graph.ver[i].label);

				while (!queue.isEmpty()) {
					char currentLabel = queue.dequeue();
					int currentIndex = graph.vertexIndex(Vertex(currentLabel, 0));

					Vertex currentVertex = graph.ver[currentIndex];
					Queue adjacentVerticesQueue;
					graph.getToVertices(currentVertex, adjacentVerticesQueue);

					while (!adjacentVerticesQueue.isEmpty()) {
						char adjacentLabel = adjacentVerticesQueue.dequeue();
						int adjacentIndex = graph.vertexIndex(Vertex(adjacentLabel, 0));

						if (color[adjacentIndex] == -1) {
							color[adjacentIndex] = 1 - color[currentIndex];
							queue.enqueue(adjacentLabel);
						}
						else if (color[adjacentIndex] == color[currentIndex]) {
							cout << "Graph is not bipartite. It contains an odd cycle." << endl;
							delete[] color;
							return false;
						}
					}
				}
			}
		}

		cout << "Graph is bipartite." << endl;
		delete[] color;
		return true;
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


				int option;
				bool end = false;

				while (end != true)
				{
					cout << "CHOOSE OPTION:" << endl;
					cout << "1) MAKE EMPTY (DONE BY DEFAULT)" << endl;
					cout << "2) GET VERTEX COUNT" << endl;
					cout << "3) ADD VERTEX" << endl;
					cout << "4) ADD EDGE" << endl;
					cout << "5) WEIGHT" << endl;
					cout << "6) ADJACENT VERTICES" << endl;
					cout << "7) BREADTH FIRST SEARCH (BFS)" << endl;
					cout << "8) DEPTH FIRST SEARCH (DFS)" << endl;
					cout << "9) BIPARTITE CHECK" << endl;
					cout << "10) CONNECTED" << endl;
					cout << "11) CYCLE DETECTION" << endl;
					cout << "12) DISPLAY" << endl;
					cout << "13) EXIT" << endl;
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
						cout << obj.getVertexCount();
						system("pause");
						system("cls");
					}

					if (option == 3)
					{
						obj.addVertex();
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

						Vertex a(from, 0), b(to, 0);

						int temp;
						cout << "ENTER WEIGHT TO ADD: ";
						cin >> temp;

						if (obj.vertexIndex(a) == -1 || obj.vertexIndex(b) == -1)
						{
							cout << "INVALID ENTRY!";
						}

						else {

							obj.addEdgeD(a, b, temp);
						}
						system("pause");
						system("cls");
					}

					if (option == 5)
					{

						char from, to;
						cout << "ENTER LABEL OF THE FROM VERTEX: ";
						cin >> from;

						cout << "ENTER LABEL OF THE TO VERTEX: ";
						cin >> to;
						Vertex a(from, 0), b(to, 0);
						cout << obj.weight(a, b);
						system("pause");
						system("cls");
					}

					if (option == 6)
					{
						Queue temp;
						char temp2;
						cout << "ADD LABEL OF THE VERTEX TO GET TO ITS ADJACENT VERTICES: ";
						cin >> temp2;

						Vertex* ver = new Vertex(temp2, 0);
						if (obj.vertexIndex(*ver) == -1)
						{
							cout << "INVALID INPUT!";
						}

						else
						{
							Vertex temp3(temp2, 0);

							temp = obj.getToVertices(temp3, temp);

							while (!temp.isEmpty())
							{
								cout << temp.dequeue() << " ";
							}

						}
						system("pause");
						system("cls");
					}

					if (option == 7)
					{
						obj.BFS();
						system("pause");
						system("cls");
					}

					if (option == 8)
					{
						obj.DFS();
						system("pause");
						system("cls");
					}

					if (option == 9)
					{
						if (obj.isBipartite(obj))
						{
							cout << "GRAPH IS BIPARTITE";
						}
						else
							cout << "GRAPH IS NOT BIPARTITE";

						system("pause");
						system("cls");
					}

					if (option == 10)
					{
						if (obj.checkConnected())
						{
							cout << "GRAPH IS CONNECTED!";
						}
						else
						{
							cout << "GRAPH IS NOT CONNECTED!";
						}

						system("pause");
						system("cls");
					}

					if (option == 11)
					{
						if (obj.cycleDetectD())
						{
							cout << "GRAPH CONSISTS OF CYCLE!";
						}

						else
						{
							cout << "GRAPH CONSISTS OF NO CYCLE!";
						}
						system("pause");
						system("cls");
					}
					if (option == 12)
					{
						obj.display();
						system("pause");
						system("cls");
					}

					if (option == 13)
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

				int option;
				bool end = false;

				while (end != true)
				{
					cout << "CHOOSE OPTION:" << endl;
					cout << "1) MAKE EMPTY (DONE BY DEFAULT)" << endl;
					cout << "2) GET VERTEX COUNT" << endl;
					cout << "3) ADD VERTEX" << endl;
					cout << "4) ADD EDGE" << endl;
					cout << "5) WEIGHT" << endl;
					cout << "6) ADJACENT VERTICES" << endl;
					cout << "7) BREADTH FIRST SEARCH (BFS)" << endl;
					cout << "8) DEPTH FIRST SEARCH (DFS)" << endl;
					cout << "9) DISPLAY" << endl;
					cout << "10) CHECK IF GRAPH IS CONNECTED" << endl;
					cout << "11) CHECK IF GRAPH IS BIPARTITE" << endl;
					cout << "12) CYCLE DETECTION" << endl;
					cout << "13) EXIT" << endl;
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
						cout << obj.getVertexCount();
						system("pause");
						system("cls");
					}
					if (option == 3)
					{
						obj.addVertex();
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

						Vertex a(from, 0), b(to, 0);

						if (obj.vertexIndex(a) == -1 || obj.vertexIndex(b) == -1)
						{
							cout << "INVALID INPUT!";
						}
						else
						{
							int temp;
							cout << "ENTER WEIGHT TO ADD: ";
							cin >> temp;

							if (from != to)
							{
								obj.addEdgeUD(a, b, temp);
								obj.addEdgeUD(b, a, temp);
							}

							else
							{
								obj.addEdgeUD(a, b, temp);
							}
						}
						system("pause");
						system("cls");
					}

					if (option == 5)
					{
						char from, to;
						cout << "ENTER LABEL OF THE FROM VERTEX: ";
						cin >> from;

						cout << "ENTER LABEL OF THE TO VERTEX: ";
						cin >> to;
						Vertex a(from, 0), b(to, 0);
						if (obj.vertexIndex(a) == -1 || obj.vertexIndex(b) == -1)
						{
							cout << "INALID INPUT!";
						}
						else
						{
							cout << obj.weight(a, b);
						}
						system("pause");
						system("cls");
					}

					if (option == 6)
					{
						Queue temp;
						char temp2;
						cout << "ADD LABEL OF THE VERTEX TO GET TO ITS ADJACENT VERTICES: ";
						cin >> temp2;

						Vertex temp3(temp2, 0);

						if (obj.vertexIndex(temp3) == -1)
						{
							cout << "INVALID INPUT!";
						}
						else
						{
							temp = obj.getToVertices(temp3, temp);

							while (!temp.isEmpty())
							{
								cout << temp.dequeue() << " ";
							}

						}
						system("pause");
						system("cls");
					}


					if (option == 7)
					{
						obj.BFS();
						system("pause");
						system("cls");
					}

					if (option == 8)
					{
						obj.DFS();
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
						if (obj.checkConnected())
						{
							cout << "GRAPH IS CONNECTED!";
						}

						else
						{
							cout << "GRAPH IS NOT CONNECTED!";
						}

						system("pause");
						system("cls");
					}

					if (option == 11)
					{
						if (obj.isBipartite(obj))
						{
							cout << "GRAPH IS BIPARTITE!";
						}

						else
						{
							cout << "GRAPH IS NOT BIPARTITE!";
						}

						system("pause");
						system("cls");
					}

					if (option == 12)
					{
						if (obj.cycleDetectUD())
						{
							cout << "GRAPH HAS A CYCELE!";
						}

						else
						{
							cout << "GRAPH HAS NO CYCLE!";
						}

						system("pause");
						system("cls");
					}

					if (option == 13)
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