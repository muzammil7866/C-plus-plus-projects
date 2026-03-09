#include<iostream>    
#include<algorithm>
using namespace std;
int main()
{
    //array initialisation
    int array[5] = { 5, 2, 6, 32, 19 };

    int n = sizeof(array) / sizeof(array[0]);

    cout << "BEFORE SORTING ARRAY : ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << array[i];
    }

    sort(array, array + n);

    cout << "\n\nAFTER SORTING ARRAY: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << array[i];
    }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + array[i];
    }

    cout << "\n\nAVERAGE OF ARRAY: "<<sum/n;
    cout << endl;
    cout << endl;

    cout << "EVEN NUMBERS IN ARRAY: { ";
    for (int i = 0; i < n;i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i]<<" ";
        }
    }
    cout << "}\n";

    cout << "\nODD NUMBERS IN ARRAY: { ";
    for (int i = 0; i < n;i++)
    {
        if (array[i] % 2 == 1)
        {
            cout << array[i] << " ";
        }
    }
    cout << "}\n";
    return 0;
}