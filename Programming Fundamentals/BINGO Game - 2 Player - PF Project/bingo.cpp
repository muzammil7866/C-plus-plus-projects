#include<iostream> //for standard input/output operations
#include<cstdlib> //for random number generation functions
#include<ctime> //for time functions used in random seeding
#include<fstream> //for file handling operations
#include<string> //for string manipulation
#include<windows.h> //for Windows-specific functions (like color)
#include<iomanip> //for output formatting (like setw)
#include<conio.h> //for getch() (password masking)

using namespace std;

// Function prototypes
bool signup();
bool login();
void mainMenu();
int gameID();
void generateBoard(int board1[][5]);
void displayBoard(int board1[][5], string p, int id);
int toss(string p1, string p2);
void playGame(int board1[][5], int board2[][5], int start, string p1, string p2, int id);
bool winCheck(int board[][5], string p, int id);
string getPassword(); // Helper function for password input

int main()
{
    system("color 3");
    bool validInput = false;
    char choice;

    while (!validInput)
    {
        cout << "\t\t LOGIN MENU " << endl << endl << endl;
        cout << "\tPRESS 1 TO LOGIN" << endl;
        cout << "\tPRESS 2 TO SIGNUP" << endl;
        cout << "\nENTER HERE: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        if (choice == '1')
        {
            bool found = false;
            while (!found)
            {
                found = login();
                if (!found)
                {
                    cout << "Login failed. Try again or press 0 to return to main menu: ";
                    char retry;
                    cin >> retry;
                    if (retry == '0') break;
                    cin.ignore();
                }
            }
            if (found) mainMenu();
            validInput = false;
            system("cls");
        }
        else if (choice == '2')
        {
            bool valid = false;
            while (!valid)
            {
                valid = signup();
                if (!valid)
                {
                    cout << "Press any key to try again or 0 to return to main menu: ";
                    char retry = _getch();
                    if (retry == '0') break;
                }
            }
            if (valid) mainMenu();
            validInput = false;
            system("cls");
        }
        else
        {
            cout << "\nINVALID INPUT!\n\n";
            system("pause");
            system("cls");
        }
    }
    return 0;
}

string getPassword()
{
    string password;
    char ch;
    while ((ch = _getch()) != 13) // 13 is Enter key
    {
        if (ch == 8) // Backspace
        {
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            cout << '*';
            password += ch;
        }
    }
    cout << endl;
    return password;
}

bool signup()
{
    system("cls");
    cout << "\tEnter your name : ";
    string name;
    getline(cin, name);

    cout << "\tEnter your password : ";
    string pw = getPassword();

    fstream fHand;
    fHand.open("login.txt", ios::in);

    if (!fHand.is_open())
    {
        cout << "\nUNABLE TO CREATE ACCOUNT, TRY AGAIN!";
        return false;
    }

    string namef, pwf;
    bool valid = true;

    // Check if username exists
    while (getline(fHand, namef) && getline(fHand, pwf))
    {
        if (namef == name)
        {
            cout << "USERNAME ALREADY TAKEN, CHOOSE ANOTHER!" << endl;
            valid = false;
            break;
        }
    }
    fHand.close();

    if (valid)
    {
        fHand.open("login.txt", ios::app);
        if (fHand.is_open())
        {
            // Avoid adding empty lines at start of file
            fHand.seekg(0, ios::end);
            if (fHand.tellg() > 0)
                fHand << endl;
            fHand << name << endl << pw;
            cout << "\nACCOUNT CREATED SUCCESSFULLY, WELCOME " << name << "!" << endl;
        }
        else
        {
            cout << "Failed to open file for writing!" << endl;
            valid = false;
        }
        fHand.close();
    }
    return valid;
}

bool login()
{
    system("cls");
    cout << "\tEnter your name : ";
    string name;
    getline(cin, name);

    cout << "\tEnter your password : ";
    string pw = getPassword();

    fstream fHand;
    fHand.open("login.txt");

    if (!fHand.is_open())
    {
        cout << "\nUNABLE TO RETRIEVE LOGIN INFO FROM DATABASE!";
        return false;
    }

    string namef, pwf;
    bool found = false;

    while (getline(fHand, namef) && getline(fHand, pwf))
    {
        if (namef == name && pw == pwf)
        {
            cout << "\nLOGGED IN SUCCESSFULLY, WELCOME " << name << "!" << endl << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nINVALID USERNAME OR PASSWORD, TRY AGAIN!" << endl << endl;
    }

    fHand.close();
    return found;
}

int gameID()
{
    srand(static_cast<unsigned int>(time(0)));
    int thisGameID = rand() % 9000 + 1000; // Generate 4-digit ID
    system("cls");
    cout << "YOUR GAME ID IS: " << thisGameID << endl;
    return thisGameID;
}

void generateBoard(int board1[][5])
{
    // Create a pool of numbers 1-25
    int numbers[25];
    for (int i = 0; i < 25; i++)
    {
        numbers[i] = i + 1;
    }

    // Shuffle the numbers
    for (int i = 24; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(numbers[i], numbers[j]);
    }

    // Fill the board
    int index = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board1[i][j] = numbers[index++];
        }
    }
}

void displayBoard(int board1[][5], string p, int id)
{
    system("cls");
    cout << "YOUR GAME ID IS: " << id << endl << endl;
    cout << "HERE IS YOUR BOARD " << p << "!" << endl << endl << endl;

    cout << "|";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board1[i][j] == 0)
                cout << setw(3) << "X" << setw(3) << "|"; // Mark selected numbers with X
            else
                cout << setw(3) << board1[i][j] << setw(3) << "|";
        }
        if (i != 4)
            cout << endl << endl << "|";
    }
    cout << endl << endl;
}

int toss(string p1, string p2)
{
    system("cls");
    int num = rand() % 2 + 1;

    cout << "'";
    cout << (num == 1 ? p1 : p2);
    cout << "' WINS THE TOSS\n" << endl;
    cout << "TAKE YOUR FIRST TURN!\n\n";
    system("pause");
    return num;
}

void playGame(int board1[][5], int board2[][5], int start, string p1, string p2, int id)
{
    int currentPlayer = start;
    bool gameOver = false;

    while (!gameOver)
    {
        bool validInput = false;
        int num = 0;

        // Display current player's board
        displayBoard((currentPlayer == 1) ? board1 : board2,
            (currentPlayer == 1) ? p1 : p2, id);

        // Get valid input
        while (!validInput)
        {
            cout << "\nCHOOSE YOUR NUMBER (1-25): ";
            if (!(cin >> num))
            {
                cout << "INVALID INPUT! PLEASE ENTER A NUMBER.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (num < 1 || num > 25)
            {
                cout << "NUMBER MUST BE BETWEEN 1 AND 25!\n";
                continue;
            }

            validInput = true;
        }

        // Mark the number on both boards
        bool numberFound = false;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board1[i][j] == num)
                {
                    board1[i][j] = 0;
                    numberFound = true;
                }
                if (board2[i][j] == num)
                {
                    board2[i][j] = 0;
                }
            }
        }

        if (!numberFound)
        {
            cout << "\nNUMBER ALREADY SELECTED OR NOT FOUND! TRY AGAIN.\n";
            system("pause");
            continue;
        }

        // Check for winner
        if (winCheck(board1, p1, id) || winCheck(board2, p2, id))
        {
            gameOver = true;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        system("cls");
    }
}

bool winCheck(int board[][5], string p, int id)
{
    int lines = 0;

    // Check rows and columns
    for (int i = 0; i < 5; i++)
    {
        bool rowComplete = true;
        bool colComplete = true;

        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] != 0) rowComplete = false;
            if (board[j][i] != 0) colComplete = false;
        }

        if (rowComplete) lines++;
        if (colComplete) lines++;
    }

    // Check diagonals
    bool diag1Complete = true;
    bool diag2Complete = true;
    for (int i = 0; i < 5; i++)
    {
        if (board[i][i] != 0) diag1Complete = false;
        if (board[i][4 - i] != 0) diag2Complete = false;
    }
    if (diag1Complete) lines++;
    if (diag2Complete) lines++;

    if (lines >= 5)
    {
        int score = lines * 100;
        ofstream fHand("playersHistory.txt", ios::app);
        if (fHand.is_open())
        {
            // Check if file is empty to avoid leading newline
            fHand.seekp(0, ios::end);
            if (fHand.tellp() > 0)
                fHand << endl;
            fHand << id << endl << p << endl << score;
            fHand.close();
        }

        cout << "\n\nCONGRATULATIONS " << p << "! YOU COMPLETED " << lines << " LINES!" << endl;
        cout << "YOUR SCORE: " << score << endl << endl;
        system("pause");
        return true;
    }
    return false;
}

void mainMenu()
{
    system("cls");
    int mainChoice = 0;

    while (true)
    {
        cout << "......................................" << endl;
        cout << "\t      B I N G O" << endl;
        cout << "......................................" << endl << endl;

        cout << "\t1. Play Game" << endl << endl;
        cout << "\t2. Game History" << endl << endl;
        cout << "\t3. How to Play" << endl << endl;
        cout << "\t4. Exit" << endl << endl;
        cout << "Choose your option: ";

        if (!(cin >> mainChoice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "INVALID INPUT! PLEASE ENTER A NUMBER (1-4).\n";
            system("pause");
            system("cls");
            continue;
        }

        cin.ignore(); // Clear newline from buffer

        switch (mainChoice)
        {
        case 1: // Play Game
        {
            int id = gameID();
            string p1, p2;

            cout << "\nENTER THE NAME OF PLAYER 1: ";
            getline(cin, p1);
            cout << "ENTER THE NAME OF PLAYER 2: ";
            getline(cin, p2);

            int board1[5][5] = { 0 };
            int board2[5][5] = { 0 };

            generateBoard(board1);
            generateBoard(board2);

            displayBoard(board1, p1, id);
            system("pause");
            displayBoard(board2, p2, id);
            system("pause");

            int start = toss(p1, p2);
            playGame(board1, board2, start, p1, p2, id);

            // After game ends, return to menu
            system("cls");
            break;
        }
        case 2: // Game History
        {
            system("cls");
            ifstream fHand("playersHistory.txt");
            if (!fHand.is_open())
            {
                cout << "NO GAME HISTORY AVAILABLE!\n";
            }
            else
            {
                string id, name, score;
                cout << "\tGAME HISTORY\n\n";
                cout << "\tGame ID\tPlayer\t\tScore\n";
                cout << "\t-------\t-------\t\t-----\n";

                while (getline(fHand, id) && getline(fHand, name) && getline(fHand, score))
                {
                    cout << "\t" << setw(7) << left << id
                        << "\t" << setw(10) << left << name
                        << "\t" << score << endl;
                }
                fHand.close();
            }
            system("pause");
            system("cls");
            break;
        }
        case 3: // How to Play
        {
            system("cls");
            cout << "\n\t      INSTRUCTIONS\n\n";
            cout << "1. Each player gets a 5x5 board with random numbers (1-25)\n\n";
            cout << "2. Players take turns selecting numbers from their board\n\n";
            cout << "3. Selected numbers are marked on both boards\n\n";
            cout << "4. The first player to complete 5 lines wins:\n\n";
            cout << "\t- Rows, columns, or diagonals count as lines\n\n";
            cout << "\t- Each line is worth 100 points\n\n";
            cout << "5. The player with the highest score wins!\n\n";
            system("pause");
            system("cls");
            break;
        }
        case 4: // Exit
            return;
        default:
            cout << "INVALID CHOICE! PLEASE SELECT 1-4.\n";
            system("pause");
            system("cls");
        }
    }
}