#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    int size;
    
    cout << "Enter your text: ";
    getline(cin, text);
    size = text.length();
    
    int maxlength = 0;
    int currentlength = 0;
    int longestword_start = 0; // To keep track of where the longest word begins
    int currentword_start = 0;

    // We loop up to 'size' (inclusive) so we can process the very last word 
    // when we hit the end of the string.
    for (int i = 0; i <= size; i++)
    {
        // If we hit a space OR the end of the string, the current word is finished
        if (i == size || text[i] == ' ')
        {
            // Compare the word we just finished with our maximum
            if (currentlength > maxlength)
            {
                maxlength = currentlength;
                longestword_start = currentword_start;
            }
            
            // Reset for the next word
            currentlength = 0;
            currentword_start = i + 1; 
        }
        else
        {
            // If it's a regular character, just increase our current word count
            currentlength++;
        }
    }

    // Print the results
    cout << "The length of the longest word is: " << maxlength << endl;
    
    // We can use the start index and the max length to print the actual word!
    cout << "The longest word is: " << text.substr(longestword_start, maxlength) << endl;

    return 0;
}