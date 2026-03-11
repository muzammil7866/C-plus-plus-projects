#include <iostream>
#include <string>
using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int main()
{
    string text;
    text = "Hello, how are you.";

    int array[MAX_ROWS][MAX_COLS];

    int size = text.length();

    int cols[MAX_ROWS]; 
    int count2 = 0;

    for (int i = 0; i < size; i++)
    {
        int count = 0;

        while (i < size && (text[i] != ' ' && text[i] != '.' && text[i] != ','))
        {
            array[count2][count] = text[i]; 
            count++;
            i++; 
        }

        if (count > 0) 
        {
            cols[count2] = count;
            count2++;
        }
    }

    for (int i = 0; i < count2; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            cout << static_cast<char>(array[i][j])<<" ";
        }
        cout << endl;
    }

    return 0;
}
