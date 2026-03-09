#include<iostream> //for standard input/output operations
#include<cstdlib> //for random number generation functions
#include<ctime> //for time functions used in random seeding
#include<fstream> //for file handling operations
#include<string> //for string manipulation
#include<windows.h> //for Windows-specific functions (like color)
#include<iomanip> //for output formatting (like setw)
#include<conio.h> //for getch() (password masking)

using namespace std;

// Color Constants
const int BLUE = 3;
const int GREEN = 10;
const int RED = 12;
const int CYAN = 11;
const int YELLOW = 14;
const int WHITE = 15;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printHeader(string title) {
    setColor(CYAN);
    cout << "========================================" << endl;
    cout << "\t    " << title << endl;
    cout << "========================================" << endl << endl;
    setColor(WHITE);    
}

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
    // Set terminal to UTF-8 to support box-drawing characters
    SetConsoleOutputCP(CP_UTF8);
    system("color 3");
    bool validInput = false;
    char choice;

    while (!validInput)
    {
        printHeader("BINGO - 2 PLAYER PRO");
        setColor(YELLOW);
        cout << "\t[1] LOGIN" << endl;
        cout << "\t[2] SIGNUP" << endl;
        setColor(WHITE);
        cout << "\nENTER YOUR CHOICE: ";
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
    int thisGameID = rand() % 9000 + 1000;
    system("cls");
    setColor(GREEN);
    cout << "----------------------------------------" << endl;
    cout << "      SUCCESS! GAME ID: " << thisGameID << endl;
    cout << "----------------------------------------" << endl;
    setColor(WHITE);
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
    setColor(CYAN);
    cout << "GAME ID: " << id << " | PLAYER: " << p << endl;
    cout << "----------------------------------------" << endl << endl;

    setColor(YELLOW);
    cout << "  +------+------+------+------+------+" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "  |";
        for (int j = 0; j < 5; j++)
        {
            if (board1[i][j] == 0) {
                setColor(RED);
                cout << "  X   ";
                setColor(YELLOW);
                cout << "|";
            }
            else {
                setColor(WHITE);
                if (board1[i][j] < 10) cout << "  " << board1[i][j] << "   ";
                else cout << "  " << board1[i][j] << "  ";
                setColor(YELLOW);
                cout << "|";
            }
        }
        cout << endl;
        if (i < 4)
            cout << "  +------+------+------+------+------+" << endl;
    }
    cout << "  +------+------+------+------+------+" << endl;
    setColor(WHITE);
    cout << endl;
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

        cout << "\n\n";
        setColor(GREEN);
        cout << "****************************************" << endl;
        cout << "   CONGRATULATIONS " << p << "!" << endl;
        cout << "   YOU COMPLETED " << lines << " LINES!" << endl;
        cout << "   YOUR SCORE: " << score << endl;
        cout << "****************************************" << endl;
        setColor(WHITE);
        cout << endl;
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
        printHeader("MAIN MENU");
        setColor(YELLOW);
        cout << "\t[1] Play Game" << endl;
        cout << "\t[2] Game History" << endl;
        cout << "\t[3] How to Play" << endl;
        cout << "\t[4] Exit" << endl;
        setColor(WHITE);
        cout << "\nChoose your option: ";

        if (!(cin >> mainChoice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            setColor(RED);
            cout << "\nINVALID INPUT! PLEASE ENTER A NUMBER (1-4).\n";
            setColor(WHITE);
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
                printHeader("GAME HISTORY");
                setColor(CYAN);
                cout << left << setw(10) << "Game ID" << setw(15) << "Player" << setw(10) << "Score" << endl;
                cout << "----------------------------------------" << endl;
                setColor(WHITE);

                while (getline(fHand, id) && getline(fHand, name) && getline(fHand, score))
                {
                    cout << left << setw(10) << id
                        << setw(15) << name
                        << setw(10) << score << endl;
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
            printHeader("HOW TO PLAY");
            setColor(YELLOW);
            cout << "1. "; setColor(WHITE); cout << "Each player gets a 5x5 board (1-25).\n";
            setColor(YELLOW);
            cout << "2. "; setColor(WHITE); cout << "Players take turns selecting numbers.\n";
            setColor(YELLOW);
            cout << "3. "; setColor(WHITE); cout << "Numbers are marked with a Red 'X' on both boards.\n";
            setColor(YELLOW);
            cout << "4. "; setColor(WHITE); cout << "Complete 5 lines (Row/Col/Diag) to win.\n";
            setColor(YELLOW);
            cout << "5. "; setColor(WHITE); cout << "Each line is worth 100 points.\n\n";
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