#include <iostream>
using namespace std;

// Ensure division includes decimals, otherwise 22/7 evaluates to 3
const double pie = (22.0 / 7.0); 

// Function prototypes
void area(float rad);
void area(float a, int b);
void sphere(float a);
void area(int a, int b);
void area(int a);

int main()
{
    int l = 0, w = 0, h = 0;
    float rad = 0.0; // Changed to float so it triggers the correct overloaded functions!
    int pos = 0;

    cout << "Choose the shape whose area you want to calculate" << endl;
    cout << "Enter 1 for Circle" << endl;
    cout << "Enter 2 for Rectangle" << endl;
    cout << "Enter 3 for Square" << endl;
    cout << "Enter 4 for Sphere" << endl; // Fixed typo here
    cout << "Enter 5 for Cylinder: ";
    cin >> pos;
    cout << endl;

    if (pos == 1)
    {
        cout << "Enter the radius of your circle (in dec): ";   
        cin >> rad;
        area(rad); // Calls area(float) -> Circle
    }
    else if (pos == 2)
    {
        cout << "Enter the length of your rectangle (in int): ";
        cin >> l;
        cout << "Enter the width of your rectangle (in int): ";
        cin >> w;
        area(l, w); // Calls area(int, int) -> Rectangle
    }
    else if (pos == 3)
    {
        cout << "Enter the length of your square (in int): ";
        cin >> l;
        area(l); // Calls area(int) -> Square
    }
    else if (pos == 4)
    {
        cout << "Enter the radius of your sphere (in dec): ";
        cin >> rad;
        sphere(rad); // Fixed to call the actual sphere function
    }
    else if (pos == 5)
    {
        cout << "Enter the radius of your cylinder (in float): ";
        cin >> rad;
        cout << "Enter the height of your cylinder (in int): ";
        cin >> h;
        area(rad, h); // Calls area(float, int) -> Cylinder
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

void area(float rad)
{
    float result = pie * rad * rad; 
    cout << "Area of Circle is: " << result << endl;
}

void area(int a, int b)
{
    float result = a * b;
    cout << "Area of Rectangle is: " << result << endl;
}

void area(float a, int b)
{
    float result = 2 * pie * a * b + 2 * pie * a * a;
    cout << "Area of Cylinder is: " << result << endl;
}

void area(int l)
{
    float result = l * l;
    cout << "Area of Square is: " << result << endl;
}

void sphere(float a)
{
    float result = 4 * pie * a * a;
    cout << "Area of Sphere is: " << result << endl;
}