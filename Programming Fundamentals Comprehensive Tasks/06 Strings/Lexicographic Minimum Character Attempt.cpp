#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    int size = 0;

    cout << "enter your text: ";
    getline(cin, text);
    size = text.length();

    // Loop through each character position in the string
    for (int i = 0; i < size - 1; i++)
    {
        // Assume the current position holds the smallest character
        int min_index = i; 

        // Check the rest of the string to find the actual smallest character
        for (int j = i + 1; j < size; j++)
        {
            if (text[j] < text[min_index])
            {
                min_index = j; // Update the index if a smaller character is found
            }
        }

        // Swap the found minimum character with the character at position 'i'
        if (min_index != i)
        {
            char temp = text[i];
            text[i] = text[min_index];
            text[min_index] = temp;
        }
    }

    // Print the final result outside of the loops
    cout << "Sorted text: " << text << endl;

    return 0;
}