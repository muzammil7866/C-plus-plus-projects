#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<Windows.h> 
#include<iomanip>

using namespace std;

void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetTextColor() {
    setTextColor(7);
}

bool isPrime(int no) {
    int count = 0;
    for (int i = 2; i < no; i++) {
        if (no % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}

int getSize() {
    int count = 0, totalLines = 0;

    ifstream inputFile("Dictionary.txt");

    if (!inputFile.is_open()) {
        cout << "FILE NOT FOUND!" << endl;
        return 0;
    }

    string word;
    while (getline(inputFile, word)) {
        count++;
    }

    inputFile.close();
    totalLines = count;

    // balance factor should be between 0.7 and 0.8
    while ((count * 1.0 / totalLines) > 0.8 || (count * 1.0 / totalLines) < 0.7) {
        totalLines += 5;
    }

    while (!isPrime(totalLines)) {
        totalLines++;
    }

    cout << totalLines;
    return totalLines;
}

bool hasSpace(const string& str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            return true;
        }
    }
    return false;
}

class TrieNode {
public:
    string word;
    string meaning;
    bool isWordEnd;
    TrieNode* next[26];

    TrieNode(const string word, const string meaning) {
        this->word = word;
        this->meaning = meaning;
        isWordEnd = false;

        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

class TrieTree {
private:
    TrieNode* root;
    int predictCount;

public:
    TrieTree() {
        root = new TrieNode("", "");
        predictCount = 0;
    }

    // Insert one word into one trie node
    void insert(const string& word, const string& meaning) {
        TrieNode* current = root;
        int wordSize = word.length();

        for (int i = 0; i < wordSize; i++) {
            int index = word[i] - 'a';

            if (current->next[index] == nullptr) {
                current->next[index] = new TrieNode("", "");
            }

            current = current->next[index];
        }

        current->word = word;
        current->meaning = meaning;
        current->isWordEnd = true;
    }

    // Search for a word in the trie
    TrieNode* searchWord(const string& word) {
        TrieNode* current = root;
        int wordSize = word.length();

        for (int i = 0; i < wordSize; i++) {
            int index = word[i] - 'a';

            if (current->next[index] == nullptr) {
                return nullptr; // Word not found
            }

            current = current->next[index];
        }

        if (current != nullptr && current->isWordEnd) {
            return current; // Word found
        }

        return nullptr; // Prefix of a longer word
    }

    void updateWord(const string& word, const string& newMeaning) {
        TrieNode* current = root;
        int wordSize = word.length();

        for (int i = 0; i < wordSize; i++) {
            int index = word[i] - 'a';

            if (current->next[index] == nullptr) {
                // Word not found, do nothing
                return;
            }

            current = current->next[index];
        }

        if (current != nullptr && current->isWordEnd) {
            current->meaning = newMeaning;
        }
        // Word not found or given word is a actually a prefix of a longer word
    }

    // Predict words based on the input string
    void predictWords(const string& input) {
        TrieNode* current = root;
        string prefix = "";

        // Traverse the Trie to the node representing the input string
        for (int i = 1; i < input.length(); i++) {
            int index = input[i] - 'a';

            if (current->next[index] == nullptr) {
                cout << "NO WORDS FOUND BASED ON THE GIVEN PREFIX." << endl;
                return;
            }

            prefix += input[i];
            current = current->next[index];
        }

        // Display the 10 closest words
        cout << "PREDICTED WORDS STARTING FROM '" << input << "':" << endl << endl << endl;
        displayClosestWords(current, prefix, predictCount);
    }

    // Display 10 closest words starting from the given TrieNode
    void displayClosestWords(TrieNode* node, const string& prefix, int& predictCount) {
        if (node == nullptr || predictCount >= 10) {
            return;
        }

        // If the current node represents the end of a word, display it
        if (node->isWordEnd) {
            cout << "\t\t" << setw(20) << prefix;
            cout << "\t" << "( " << node->meaning << " )" << endl;
            predictCount++;
        }

        // Recursively traverse and display words from child nodes
        for (int i = 0; i < 26 && predictCount < 10; i++) {
            if (node->next[i] != nullptr) {
                displayClosestWords(node->next[i], prefix + char('a' + i), predictCount);
            }
        }
    }

    void deleteWord(const string& word) {
        TrieNode* current = root;
        int wordSize = word.length();

        // Traverse the Trie to the node representing the input string
        for (int i = 0; i < wordSize; i++) {
            int index = word[i] - 'a';

            if (current->next[index] == nullptr) {
                // Word not found, do nothing
                return;
            }

            current = current->next[index];
        }

        // If the given word is a prefix of another word, do not delete
        if (!current->isWordEnd) {
            return;
        }

        // Mark isWordEnd as false to "delete" the word
        current->isWordEnd = false;
        cout << "YOUR WORD [" << word << "] IS SUCCESSFULLY DELETED FROM THE TRIE TREE!";
    }

    // Load words from a file into the trie
    void LoadDictionary() {
        ifstream inputFile("Dictionary.txt", ios::in);
        int count = 0;

        if (!inputFile.is_open()) {
            cout << "FILE NOT FOUND!" << endl;
            exit(1);
        }

        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string word, meaning;

            // Extract the first word
            if (!(iss >> word)) {
                cout << "Error reading word from line: " << line << endl;
                continue;
            }

            // Extract the rest of the line as the meaning
            getline(iss, meaning);

            // Add the word and meaning to the trie
            insert(word, meaning);
        }

        inputFile.close();
    }

    // Display the meaning of a word
    void displayMeaning(const string& word) {
        TrieNode* result = searchWord(word);

        if (result != nullptr) {
            setTextColor(10); // Set text color to green
            cout << "WORD: " << setw(50) << result->word << endl;
            cout << "MEANING: " << setw(50) << result->meaning << endl;
            resetTextColor(); // Reset text color to default
        }
        else {
            setTextColor(12); // Set text color to red
            cout << "WORD [" << word << "] NOT FOUND IN THE TRIE DICTIONARY!" << endl;
            resetTextColor(); // Reset text color to default
        }
    }

    ~TrieTree() {
        deleteTrie(root);
    }

    void deleteTrie(TrieNode* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            deleteTrie(node->next[i]);
        }

        delete node;
    }
};

class Word {
    string word;
    string meaning;

public:
    Word() {
        this->word = "EmptyWordSpace";
        this->meaning = "EmptyWordMeaning";
    }

    void initializeWord(const string& word, const string& meaning) {
        this->word = word;
        this->meaning = meaning;
    }

    string& getWord() {
        return this->word;
    }

    string& getMeaning() {
        return this->meaning;
    }
};

class HashTable {
private:
    Word* linearProbingTable;
    int size;

    // Hash function to get the right index
    int hashFunction(const string str) {
        const int prime = 7;
        int hashValue = 0;

        for (char ch : str) {
            hashValue = (hashValue * prime + ch) % size;
        }

        return hashValue;
    }

    int linearProbing(int index, int attempt) {
        return (index + attempt) % size;
    }

public:
    // Constructor creates the hash linearProbingTable
    HashTable(int size) {
        this->size = size;
        linearProbingTable = new Word[size];
    }

    void updateFile() {
        ofstream outputFile("Dictionary.txt", ios::out);  // Open the file for writing

        if (!outputFile.is_open()) {
            cout << "\tUNABLE TO READ FROM DICTIONARY.TXT FILE!" << endl;
            return;
        }

        for (int i = 0; i < size; ++i) {
            if (linearProbingTable[i].getWord() != "EmptyWordSpace" && linearProbingTable[i].getWord() != "DeletedWord") {
                outputFile << linearProbingTable[i].getWord() << "\t" << linearProbingTable[i].getMeaning() << endl;
            }
        }

        cout << endl << "\tDICTIONARY.TXT FILE HAS BEEN UPDATED SUCCESSFULLY!" << endl;

        outputFile.close();
    }

    void LoadDictionary() {
        ifstream inputFile("Dictionary.txt", ios::in);
        int count = 0;

        if (!inputFile.is_open()) {
            cout << "FILE NOT FOUND!" << endl;
            exit(1);
        }

        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string word, meaning;

            // Extract the first word
            if (!(iss >> word)) {
                cout << "Error reading word from line: " << line << endl;
                continue;
            }

            // Extract the rest of the line as the meaning
            getline(iss, meaning);

            // Add the word and meaning to the hash table
            addWordToHashTable(word, meaning);
        }

        inputFile.close();
    }

    // Insert a word into the hash table
    void addWordToHashTable(const string& word, const string& meaning) {
        int index = hashFunction(word);
        int attempt = 0;

        while (linearProbingTable[index].getWord() != "EmptyWordSpace") {
            attempt++;
            index = linearProbing(index, attempt);
        }

        linearProbingTable[index].initializeWord(word, meaning);
    }

    void AddWord(const string& word, const string& meaning) {
        addWordToHashTable(word, meaning);
        cout << "YOUR WORD HAS BEEN ADDED SUCCESSFULLY!" << endl;
        updateFile();
    }

    // Search for a word in the hash table
    bool searchWord(const string word) {
        int index = hashFunction(word);
        int startingIndex = index;
        int attempt = 0;

        while (linearProbingTable[index].getWord() != "EmptyWordSpace") {
            if (linearProbingTable[index].getWord() == word) {
                setTextColor(10); // Set text color to green
                cout << "YOUR WORD WAS FOUND IN THE DICTIONARY!" << endl << endl;
                cout << "WORD: " << setw(50) << linearProbingTable[index].getWord() << endl;
                cout << "MEANING: " << setw(50) << linearProbingTable[index].getMeaning() << endl;
                resetTextColor(); // Reset text color to default
                return true;
            }
            attempt++;
            index = linearProbing(startingIndex, attempt);
            if (index == startingIndex) {
                break;
            }
        }

        setTextColor(12); // Set text color to red
        cout << "WORD [" << word << "] WAS NOT FOUND IN THE HASH DICTIONARY!" << endl;
        resetTextColor(); // Reset text color to default

        return false;
    }


    // Find a word and update it
    void updateWord(const string& word, const string& meaning) {
        int index = hashFunction(word);
        int initialIndex = index;
        int startingIndex = index;
        int attempt = 0;

        while (linearProbingTable[index].getWord() != "EmptyWordSpace") {
            if (linearProbingTable[index].getWord() == word) {

                linearProbingTable[index].getMeaning() = meaning;
                cout << endl << "\tWORD MEANING UPDATED IN HASH DICTIONARY!" << endl << endl;
                cout << "WORD: " << linearProbingTable[index].getWord() << endl;
                cout << "NEW MEANING: " << linearProbingTable[index].getMeaning() << endl;
                updateFile();
                return;
            }
            attempt++;
            index = linearProbing(startingIndex, attempt);
            if (index == startingIndex) {
                break;
            }
        }
    }

    // Delete a word from the hash table
    void DeleteWord(const string word) {
        int index = hashFunction(word);
        int initialIndex = index;
        int attempt = 0;

        while (linearProbingTable[index].getWord() != "EmptyWordSpace") {
            if (linearProbingTable[index].getWord() == word) {
                linearProbingTable[index].getWord() = "DeletedWord";
                cout << "REMOVED WORD [" << word << "] AT INDEX " << index << " FROM HASH DICTIONARY!" << endl;
                updateFile();
                return;
            }
            attempt++;
            index = linearProbing(initialIndex, attempt);
            if (index == initialIndex) {
                break;
            }
        }
        cout << "WORD [" << word << "] NOT FOUND IN THE HASH DICTIONARY. NOTHING TO REMOVE!" << endl;
    }

    ~HashTable() {
        delete[] linearProbingTable;
    }
};

int main() {
    int size = getSize();
    HashTable hashDictionary(size);
    TrieTree trieDictionary;

    int choice;
    string word, meaning;
    cout << endl;

    setTextColor(10); // Set text color to green
    hashDictionary.LoadDictionary();
    cout << "GETTING HASH TABLE CONTENTS FROM FILE";

    for (int i = 0; i < 3; i++) {
        Sleep(300);
        cout << ".";
    }

    cout << endl;
    resetTextColor(); // Reset text color to default

    trieDictionary.LoadDictionary();

    setTextColor(10); // Set text color to green
    cout << "GETTING TRIE TREE CONTENTS FROM FILE";

    for (int i = 0; i < 3; i++) {
        Sleep(200);
        cout << ".";
    }

    cout << endl << endl << "SETTING UP DICTIONARY AND TRIE TREE CONTENTS HAS BEEN SUCCESSFUL! : )";

    resetTextColor(); // Reset text color to default

    cout << endl << endl;

    system("pause");
    system("cls");

    while (true) {
        setTextColor(11); // Set text color to light cyan
        cout << endl;
        cout << "\t\t\t\t.___  ___.  _______ .__   __.  __    __  " << endl;
        cout << "\t\t\t\t|   \\/   | |   ____||  \\ |  | |  |  |  | " << endl;
        cout << "\t\t\t\t|  \\  /  | |  |__   |   \\|  | |  |  |  | " << endl;
        cout << "\t\t\t\t|  |\\/|  | |   __|  |  . `  | |  |  |  | " << endl;
        cout << "\t\t\t\t|  |  |  | |  |____ |  |\\   | |  `--'  |" << endl;
        cout << "\t\t\t\t|__|  |__| |_______||__| \\__|  \\______/" << endl;
        resetTextColor(); // Reset text color to default

        cout << endl << endl << endl;

        setTextColor(14); // Set text color to yellow
        //cout << "\t1. LOAD DICTIONARY CONTENTS INTO BOTH HASH AND TRIE FROM THE FILE" << endl << endl;
        cout << "\t1. ADD WORD TO BOTH THE HASH AND TRIE DICTIONARY" << endl << endl;
        cout << "\t2. SEARCH WORD IN THE HASH DICTIONARY" << endl << endl;
        cout << "\t3. DELETE WORD FROM BOTH THE TRIE AND HASH DICTIONARY" << endl << endl;
        cout << "\t4. UPDATE WORD IN BOTH TRIE AND HASH DICTIONARY" << endl << endl;
        cout << "\t5. UPDATE DICTIONARY FILE USING HASH" << endl << endl;
        cout << "\t6. PREDICT WORDS USING TRIE" << endl << endl;
        cout << "\t7. SEARCH WORD IN TRIE DICTIONARY" << endl << endl;
        cout << "\t8. EXIT" << endl << endl << endl;
        cout << "\t\tENTER YOUR CHOICE: ";

        resetTextColor(); // Reset text color to default

        cin >> choice;
        cout << endl << endl;

        switch (choice) {
        //case 1:
        //    setTextColor(10); // Set text color to green
        //    hashDictionary.LoadDictionary();
        //    cout << "GETTING HASH TABLE CONTENTS FROM FILE";

        //    for (int i = 0; i < 3; i++) {
        //        Sleep(500);
        //        cout << ".";
        //    }

        //    cout << endl;
        //    resetTextColor(); // Reset text color to default

        //    trieDictionary.LoadDictionary();

        //    setTextColor(10); // Set text color to green
        //    cout << "GETTING TRIE TREE CONTENTS FROM FILE";

        //    for (int i = 0; i < 3; i++) {
        //        Sleep(700);
        //        cout << ".";
        //    }

        //    cout << endl << endl << "SETTING UP DICTIONARY AND TRIE TREE CONTENTS HAS BEEN SUCCESSFUL! : )";

        //    resetTextColor(); // Reset text color to default

        //    cout << endl << endl;

        //    system("pause");
        //    system("cls");
        //    break;

        case 1:
            cout << "ENTER THE WORD: ";
            cin.ignore();
            getline(cin, word);

            if (!hashDictionary.searchWord(word)) {
                cout << "ENTER MEANING FOR YOUR WORD: ";
                getline(cin, meaning);

                setTextColor(10); // Set text color to green
                hashDictionary.AddWord(word, meaning);
                trieDictionary.insert(word, meaning);
                cout << "\tWORD HAS BEEN SUCCESFFULY ADDED INTO THE TREE" << endl;
                resetTextColor(); // Reset text color to default
                hashDictionary.updateFile();
            }
            cout << endl << endl;

            system("pause");
            system("cls");

            break;

        case 2:
            cout << "ENTER YOUR WORD: ";
            cin >> word;

            if (!hashDictionary.searchWord(word)) {
                setTextColor(12); // Set text color to red
                cout << "WORD [" << word << "] WAS NOT FOUND IN THE HASH DICTIONARY!" << endl;
                resetTextColor(); // Reset text color to default
            }

            cout << endl << endl;

            system("pause");
            system("cls");
            break;

        case 3:
            cout << "ENTER YOUR WORD: ";
            cin.ignore();
            getline(cin, word);

            setTextColor(12); // Set text color to red
            hashDictionary.DeleteWord(word);
            trieDictionary.deleteWord(word);
            resetTextColor(); // Reset text color to default

            cout << endl << endl;

            system("pause");
            system("cls");
            break;

        case 4:
            cout << "ENTER WORD TO UPDATE ITS MEANING: ";
            cin.ignore();
            getline(cin, word);

            if (hashDictionary.searchWord(word)) {
                cout << "ENTER THE NEW MEANING: ";
                getline(cin, meaning);

                setTextColor(10); // Set text color to green
                hashDictionary.updateWord(word, meaning);
                trieDictionary.updateWord(word, meaning);
                cout << "\tWORD MEANING UPDATED IN TREE!" << endl;
                resetTextColor(); // Reset text color to default
            }
            else {
                setTextColor(12); // Set text color to red
                cout << "WORD [" << word << "] IS NOT PRESENT IN THE DICTIONARY!" << endl;
                int option;
                cout << "ENTER (1) IF YOU WANT TO ADD THE WORD, ENTER (2) IF YOU WANT TO CONTINUE WITHOUT ADDING: ";
                cin >> option;

                if (option == 1) {
                    cout << "ENTER MEANING FOR YOUR WORD: ";
                    cin.ignore();
                    getline(cin, meaning);

                    hashDictionary.AddWord(word, meaning);
                    trieDictionary.insert(word, meaning);
                }
                else if (option == 2) {
                    // Do nothing
                }
                else {
                    setTextColor(12); // Set text color to red
                    cout << "INVALID OPTION!";
                    resetTextColor(); // Reset text color to default
                }
            }

            cout << endl << endl;

            system("pause");
            system("cls");
            break;

        case 5:
            setTextColor(10); // Set text color to green
            hashDictionary.updateFile();
            resetTextColor(); // Reset text color to default

            cout << endl << endl;

            system("pause");
            system("cls");
            break;

        case 6:
            cout << "ENTER THE STARTING CHARACTERS: ";
            cin >> word;
            trieDictionary.predictWords(word);
            cout << endl << endl;

            system("pause");
            system("cls");
            break;

        case 7:
            cout << "ENTER THE WORD TO SEARCH IN TRIE TREE: ";
            cin >> word;
            trieDictionary.displayMeaning(word);
            cout << endl << endl;

            system("pause");
            system("cls");
            break;

        case 8:
            setTextColor(14); // Set text color to yellow
            cout << endl << endl;

            system("pause");
            system("cls");
            resetTextColor(); // Reset text color to default
            exit(0);

        default:
            setTextColor(12); // Set text color to red
            cout << "INVALID ENTRY, CHOOSE ANOTHER OPTION!" << endl;
            resetTextColor(); // Reset text color to default

            cout << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}