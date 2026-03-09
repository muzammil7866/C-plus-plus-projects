#include <iostream>
using namespace std;

void upperhalf(int array[][4], int b);
void bottomhalf(int array[][4], int b);

int main()
{
    int choice = 0;
    int array[4][4] = { 0 };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter the element of Array at index [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

    // Fixed the typo for choice 2 here
    cout << "\nSelect an option" << endl;
    cout << "Enter 1 for Upper Half" << endl;
    cout << "Enter 2 for Bottom Half: ";
    cin >> choice;
    cout << endl;

    if (choice == 1)
        upperhalf(array, 4);
    else if (choice == 2)
        bottomhalf(array, 4);
    else
        cout << "Invalid choice." << endl;

    return 0;
}

void upperhalf(int array[][4], int b)
{
    cout << "--- Upper Half ---" << endl;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            // Print if column index is greater than or equal to row index
            if (j >= i)
                cout << array[i][j] << "\t";
            else
                cout << "\t"; // Keeps the shape of the matrix intact
        }
        cout << endl;
    }
}

void bottomhalf(int array[][4], int b)
{
    cout << "--- Bottom Half ---" << endl;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            // Print if row index is greater than or equal to column index
            if (i >= j)
                cout << array[i][j] << "\t";
            else
                cout << "\t"; // Keeps the shape of the matrix intact
        }
        cout << endl;
    }
}