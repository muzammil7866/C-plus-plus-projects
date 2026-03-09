#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    cout << "Enter your text: ";
    getline(cin, text);
    
    int size = text.length();
    
    // We start looking for the end of the very last word
    int word_end = size - 1; 

    cout << "Reversed words: ";
    
    // Loop backwards through the string starting from the last character
    for (int i = size - 1; i >= 0; i--)
    {
        // We found a space OR we reached the very beginning of the string (index 0)
        if (text[i] == ' ' || i == 0)
        {
            // If we are at index 0, the word starts there. 
            // Otherwise, it starts one character AFTER the space we just found.
            int word_start = (i == 0) ? 0 : i + 1;
            
            // Print the word from its start to its end
            for (int j = word_start; j <= word_end; j++)
            {
                cout << text[j];
            }
            
            // Print a space to separate the words
            cout << " ";
            
            // Move our 'word_end' tracker to just before the space we found
            word_end = i - 1;
        }
    }
    
    cout << endl;
    return 0;
}