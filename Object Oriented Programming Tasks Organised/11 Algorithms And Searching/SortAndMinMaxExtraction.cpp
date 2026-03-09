#include<iostream>    
#include<algorithm>
using namespace std;
void arrayFunction(int array[], int n)
{
    sort(array, array + n);

    cout << "\n\nAFTER SORTING ARRAY: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << array[i];
    }

    cout << "\n\nSMALLEST ELEMENT OF ARRAY: " << array[0] << endl;
    cout << "\nLARGEST ELEMENT OF ARRAY: " << array[n - 1];
    cout << endl;

}
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

    arrayFunction(array, n);

    return 0;
}