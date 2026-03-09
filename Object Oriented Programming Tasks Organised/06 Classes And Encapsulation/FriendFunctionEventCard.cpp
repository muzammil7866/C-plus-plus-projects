#include <iostream>
using namespace std;
class Shape
{
public:
void draw()
{
	cout << endl;
}
};
//
class Rectangle: public Shape
{
public:
void draw()
{
	cout << "\t* * * * * * * * * * *" << endl;
	cout << "\t*                   *" <<endl;
	cout << "\t*                   *" << endl;
	cout << "\t*                   *" << endl;
	cout << "\t*                   *" << endl;
	cout << "\t*                   *" << endl;
	cout << "\t*                   *" << endl;
	cout << "\t*                   *" << endl;
	cout << "\t* * * * * * * * * * *" << endl;
}
};
//
class Circle : public Shape
{
public:
void draw()
{
	cout << "\t             *   *   *                   "            << endl;
	cout << "\t         *               *               "            <<endl;
	cout << "\t      *                     *            "            << endl;
	cout << "\t    *                         *          "            << endl;
	cout << "\t   *                           *         "            << endl;
	cout << "\t  *                             *        "            << endl;
	cout << "\t *                               *       "            << endl;
	cout << "\t *                               *       "            << endl;
	cout << "\t *                               *       "            << endl;
	cout << "\t  *                             *        "            << endl;
	cout << "\t   *                           *         "            << endl;
	cout << "\t     *                       *           "            << endl;
	cout << "\t       *                   *             "            << endl;
	cout << "\t          *             *                "            << endl;
	cout << "\t             *   *   *                   "            << endl;
}
};
int main()
{
Circle obj1;
Rectangle obj2;
//
bool repeat = true;
while (repeat != false)
{
	int option;
cout<<endl;
	cout << "ENTER THE CORRESPONDING VALUES TO CALCULATE THE AREA: " << endl;
	cout << "\tENTER 1 FOR CIRCLE : " << endl;
	cout << "\tENTER 2 FOR RECTANGLE: " << endl;
	cout << "ENTER YOUR VALUE: ";
	cin >> option;
//
//
	if (option == 1)
	{
		repeat = false;
//			obj1.draw();
	}
	else if (option == 2)
	{
		repeat = false;
//			obj2.draw();
	}
//
	else
	{
		cout << "INVALID INPUT! " << endl;
		cout << "ENTER OPTION AGAIN!"<<endl;
		repeat = true;
	}
}
//
return 0;
}
