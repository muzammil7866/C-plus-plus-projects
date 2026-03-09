#include <iostream>
using namespace std;
int main()
{
	int option=0, shape = 0, size=0, length=0, width =0, count=0;
	bool endmenu = false;
	bool endshape = false;
	while (endmenu != true)
	{

		endshape = false;
		cout << "Select a shape from the given menu: " << endl;
		cout << "Press 1 to diplay the Square" << endl;
		cout << "Press 2 to diplay the Triangle" << endl;
		cout << "Press 3 to diplay the Rhombus" << endl;
		cout << "Press 4 to diplay the Rectangle" << endl;
		cout << "Press 5 to diplay the Paralellogram" << endl;
		cout << "Press 6 to exit the Menu: ";
		cin >> option;


		switch (option)
		{
			
		case 1:
		{
			while (endshape != true)
			{
				cout << "Do you want your square to be Filled or Hollow: " << endl;
				cout << "Press 1 for Filled" << endl;
				cout << "Press 2 for Hollow: ";
				cin >> shape;
				endshape = false;
			
				if (shape == 1)
				{
					cout << "Enter the size of your square: ";
					cin >> size;

					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < size; j++)
						{
							cout << "* ";
						}
						cout << endl;
					}
					endshape = true;
				}

				else if (shape == 2)
				{
					size = 6;
					
						for (int i = 0; i < size; i++)
						{
							cout << "* ";
						}
						cout << endl<<"*         *"<<endl;
						cout <<"*         *"<<endl;
						cout << "*         *" << endl;
						cout  << "*         *" << endl;
						for (int i = 0; i < size; i++)
						{
							cout << "* ";
						}
						cout << endl;
						endshape = true;
				}

				else
				{
					cout << "Wrong input, choose again." << endl;
					endshape = false;
				}
			}
			break;
		}
		case 2:
		{		
				cout << "Enter the size of your triangle: ";
				cin >> size;

				for (int i = 1; i <= size; i++)
				{
					for (int j = 1; j <= i; j++)
					{
						cout << "* ";
					}
					cout << endl;
				}
				endshape = true;
			
					break;
		}
		case 3:
		{
			cout << "Do you want your shape to be forward or backward: " << endl;
			cout << "Press 1 for Forward" << endl;
			cout << "Press 2 for Backward:";
			cin >> shape;
			if (shape == 1)
			{

			}

			else if (shape == 2)
			{

			}

			else
			{

			}
			break;
		}
		case 4:
		{
			while (endshape != true)
			{
				cout << "Do you want your rectangle to be forward or backward: " << endl;
				cout << "Press 1 for Forward rectangle" << endl;
				cout << "Press 2 for Backward rectangle: ";
				cin >> shape;
				endshape = false;

				if (shape == 1)
				{
					cout << "Enter the length of your rectangle: ";
					cin >> length;
					cout << "Enter the width of your rectangle: ";
					cin >> width;
					for (int i = 0; i < width; i++)
					{
						for (int j = 0; j < length; j++)
						{
							cout << "* ";
						}
						cout << endl;
					}
					endshape = true;
				}

				else if (shape == 2)
				{
					cout << "Enter the length of your square: ";
					cin >> length;
					cout << "Enter the width of your square: ";
					cin >> width;
					for (int i = 0; i < width; i++)
					{
						for (int j = 0; j < length; j++)
						{
							cout << "* ";
						}
						cout << endl;
					}
					endshape = true;

				}

				else
				{
					cout << "Wrong input, choose again." << endl;
					endshape = false;
				}
			}
			break;		}
		case 5:
		{
			cout << "Do you want your shape to be forward or backward: " << endl;
			cout << "Press 1 for Forward" << endl;
			cout << "Press 2 for Backward: ";
			cin >> shape;
			if (shape == 1)
			{

			}

			else if (shape == 2)
			{

			}

			else
			{

			}
			break;
		}
		case 6:
		{

			endmenu = true;
			break;
		}
		default:
		{
			cout << "Wrong input, choose again.";
			break;
		}
		}


	}

	return 0;
}