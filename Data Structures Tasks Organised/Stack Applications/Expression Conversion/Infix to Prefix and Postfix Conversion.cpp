#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
class Node
{
public:
	char* c;
	Node* next;

	Node()
	{
		c = new char;
		*c = '\0';
		next = nullptr;
	}

	Node(char a)
	{
		c = new char;
		*c = '\0';
		*c = a;
		next = nullptr;
	}
};
class Stack
{
public:
	Node* head;
	Node* top;

	Stack()
	{
		head = nullptr;
		top = nullptr;
		
	}


	void push(char a)
	{
		if (head == nullptr)
		{
			Node* temp = new Node(a);
			*temp->c = a;
			head = temp;
			top = temp;
		}

		else{
			Node* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			Node* temp2 = new Node(a);
			*temp2->c = a;
			temp->next = temp2;
			top = temp2;

		}
	}

	char pop()
	{
		Node* temp = head;

		if (head == nullptr)
		{
			cout << "CANNOT POP FURTHER AS THE LINKED STRUCTURE IS EMPTY!";
			return -1;
		}
		
		else if (temp->next == nullptr)
		{
			
			char temp2 = *(temp->c);

			delete temp;
			head = nullptr;
			top = nullptr;
			return temp2;

		}


		else
		{

			while (temp->next->next != nullptr)
			{
				temp = temp->next;
			}

			char temp2 = *(temp->next->c);
			delete temp->next;
			temp->next = nullptr;
			top = temp;

			return temp2;
		}


	}

	void display()
	{
		Node* temp = head;
		while (temp!= nullptr)
		{
			cout << *temp->c;
			temp = temp->next;
		}
	}


};

int main()
{
	Stack obj;
	bool end = false;


	

	obj.display();
	while (end != true)
	{
		Stack stack;

		int option;
		cout << "CHOOSE FROM AMONG THE FOLLOWING: " << endl;
		cout << "(1) SOLVING THROUGH PREFIX NOTATION \n(2) SOLVING THROUGH POSTFIX NOTATION \n(3) EXIT MENU \n" << endl;

		cout << "\n\n" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> option;

		if (option == 1)
		{
			string b;
			string a = "";
			string postfixExp = "";
			cout << "WRITE AN INFIX NOTATION (EACH UNIT SEPERATED BY A SPACE): ";
			cin.ignore();
			getline(cin, b);

			
			for (int i = b.length() - 1; i >= 0; i--)
			{
				a += b[i];
			}

			int count = 0;
			cout << setw(15) << left << "THIS TOKEN:" << "\t" << setw(15) << left << "POSTFIX EXPRESSION:" << "\t" << setw(15) << left << "STACK";
			while (count < a.length())
			{

				cout << endl << setw(15) << left << a[count] << "\t" << setw(15) << left << postfixExp << "\t" << setw(15) << left << "\t";
				stack.display();

				if (a[count] != '+' && a[count] != '-' && a[count] != '/' && a[count] != '*' && a[count] != ')')
				{
					string thisToken = "";

					if (a[count] == '(')
					{
						stack.push(a[count]);
						count += 2;
					}


					while (a[count] != 32)
					{
						thisToken += a[count];
						count++;
						if (count == a.length())
							break;


					}




					postfixExp += thisToken;

					if (count == a.length())
						break;
					count++;
				}

				if (a[count] == '*')
				{

					if (stack.top == nullptr)
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '+')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '-')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('*');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('*');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('*');
					}
				}

				else if (a[count] == '/')
				{


					if (stack.top == nullptr)
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '+')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '-')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('/');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('/');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('/');
					}
				}

				else if (a[count] == '+')
				{

					if (stack.top == nullptr)
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '+')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('+');
					}



					else if (*stack.top->c == '-')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('+');
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('+');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('+');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('+');
					}
				}

				else if (a[count] == '-')
				{

					if (stack.top == nullptr)
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '+')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('-');
					}


					else if (*stack.top->c == '-')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;

							postfixExp += stack.pop();
						}
						stack.push('-');
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('-');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('-');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('-');
					}
				}
				else if (a[count] == ')')
				{
					while (*stack.top->c != '(')
					{
						postfixExp += stack.pop();
					}


					stack.pop();



				}

				count++;
				count++;


			}

			while (stack.top != nullptr)
			{
				postfixExp += stack.pop();
			}

			string prefixExp = "";

			for (int i = postfixExp.length() - 1; i >= 0; i--)
			{
				prefixExp += postfixExp[i];
			}


			cout << endl << endl << "PREFIX EQUIVALENT EXPRESSION: " << prefixExp << "\t";
			Node* temp = stack.head;

			while (temp != nullptr)
			{
				cout << *temp->c << " ";
				temp = temp->next;
			}


			cout << endl << endl << "FINAL ANSWER AFTER EVALUATION: ";

		}

		else if (option == 2)
		{
			string b;
			string a = "";
			string postfixExp = "";
			cout << "WRITE AN INFIX NOTATION (EACH UNIT SEPERATED BY A SPACE): ";
			cin.ignore();
			getline(cin, a);

			string c = "";

			for (int i = 0; i < a.length(); i++)
			{
				if(a[i] != ' ')
					c += a[i];
			}


			cout << c<<endl;

			int count = 0;
			cout << setw(15) << left<<"THIS TOKEN:" <<"\t"<< setw(15) << left << "POSTFIX EXPRESSION:"<<"\t"<< setw(15) << left << "STACK";
			while (count < a.length())
			{
				
				cout <<endl<< setw(15) <<left<< a[count] << "\t" << setw(15) <<left<< postfixExp <<"\t"<< setw(15) << left << "\t";
				stack.display();

				if (a[count] != '+' && a[count] != '-' && a[count] != '/' && a[count] != '*' && a[count] != ')')
				{
					string thisToken = "";

					if (a[count] == '(')
					{
						stack.push(a[count]);
						count += 2;
					}


					while (a[count] != 32)
					{
						thisToken += a[count];
						count++;
						if (count == a.length())
							break;


					}




					postfixExp += thisToken;

					if (count == a.length())
						break;
					count++;
				}

				if (a[count] == '*')
				{
					
					if(stack.top == nullptr)
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '+')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '-')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('*');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('*');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if(*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('*');
					}
				}

				else if (a[count] == '/')
				{
					

					if (stack.top == nullptr)
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '+')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '-')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('/');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}

						stack.push('/');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('/');
					}
				}

				else if (a[count] == '+')
				{

					if (stack.top == nullptr)
					{
						stack.push(a[count]);
					}
					
					else if (*stack.top->c == '+')
						{
							while (stack.top != nullptr)
							{
								if (*stack.top->c == '(')
									break;
								postfixExp += stack.pop();
							}

							stack.push('+');
					}

					

					else if (*stack.top->c == '-')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('+');
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('+');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('+');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('+');
					}
				}

				else if (a[count] == '-')
				{
				
					if (stack.top == nullptr)
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == '+')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('-');
					}


					else if (*stack.top->c == '-')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;

							postfixExp += stack.pop();
						}
						stack.push('-');
					}

					else if (*stack.top->c == '*')
					{
						while (stack.top != nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('-');
					}

					else if (*stack.top->c == '/')
					{
						while (stack.top == nullptr)
						{
							if (*stack.top->c == '(')
								break;
							postfixExp += stack.pop();
						}
						stack.push('-');
					}

					else if (*stack.top->c == '(')
					{
						stack.push(a[count]);
					}

					else if (*stack.top->c == ')')
					{
						while (*stack.top->c != '(')
						{
							postfixExp += stack.pop();
						}

						stack.pop();
						stack.push('-');
					}
					}
				else if (a[count] == ')')
				{
					while (*stack.top->c != '(')
					{
						postfixExp += stack.pop();
					}


					stack.pop();



					}

				count++;
				count++;


			}
			
			while (stack.top!= nullptr)
			{
				postfixExp += stack.pop();
			}

				

			cout <<endl<<endl<<"POSTFIX EQUIVALENT EXPRESSION: "<< postfixExp << "\t";
			Node* temp = stack.head;

			while (temp!= nullptr)
			{
				cout << *temp->c<<" ";
				temp = temp->next;
			}


			cout <<endl<<endl<< "FINAL ANSWER AFTER EVALUATION: ";

		}

		else if (option == 3)
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
