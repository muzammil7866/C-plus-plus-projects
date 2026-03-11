#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;
    
const int MAX_SIZE = 19;
char board[MAX_SIZE][MAX_SIZE];
int boardSize;
int BlackScore = 0;
int WhiteScore = 0;
const string HISTORY_FILE = "game_history.txt";

void initializeBoard() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = '.';
        }
    }
}

void saveToFile(const string& message) {
    ofstream file(HISTORY_FILE, ios::out); 
    file << message;
    file.close();
}

void appendToFile(const string& message) {
    ofstream file(HISTORY_FILE, ios::app);
    file << message;
    file.close();
}

void displayBoard() {
    stringstream ss;
    ss << "   ";
    for (int i = 1; i <= boardSize; i++) {
        if (i < 10) {
            ss << " " << i << " ";
        }
        else {
            ss << i << " ";
        }
    }
    ss << endl;

    for (int i = 0; i < boardSize; i++) {
        if (i + 1 < 10) {
            ss << " " << i + 1 << " ";
        }
        else {
            ss << i + 1 << " ";
        }

        for (int j = 0; j < boardSize; j++) {
            ss << " " << board[i][j] << " ";
        }
        ss << endl;
    }
    cout << ss.str();
    appendToFile(ss.str());
}

void calculateTerritory() {
    int blackMarkers = 0;
    int whiteMarkers = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == 'B') {
                blackMarkers++;
            }
            else if (board[i][j] == 'W') {
                whiteMarkers++;
            }
        }
    }

    BlackScore += blackMarkers;
    WhiteScore += whiteMarkers;
}

bool isValidMove(int x, int y) {
    return (x >= 0 && x < boardSize && y >= 0 && y < boardSize && board[x][y] == '.');
}

void checkLiberties(int startX, int startY, char color, bool visited[MAX_SIZE][MAX_SIZE], bool& hasLiberty) {
    
    int positions[MAX_SIZE * MAX_SIZE][2];

    int count = 0;

    positions[count][0] = startX;
    positions[count][1] = startY;
    count++;

    for (int i = 0; i < count; i++) {
        int x = positions[i][0];
        int y = positions[i][1];

        if (x < 0 || x >= boardSize || y < 0 || y >= boardSize || visited[x][y]) {
            continue;
        }

        visited[x][y] = true;

        if (board[x][y] == '.') {
            hasLiberty = true;
            return;
        }

        if (board[x][y] != color) {
            continue;
        }

        positions[count][0] = x + 1;
        positions[count][1] = y;
        count++;
        positions[count][0] = x - 1;
        positions[count][1] = y;
        count++;
        positions[count][0] = x;
        positions[count][1] = y + 1;
        count++;
        positions[count][0] = x;
        positions[count][1] = y - 1;
        count++;
    }
}


bool isSuicidalMove(int x, int y, char currentPlayer) {
    board[x][y] = currentPlayer;

    bool visited[MAX_SIZE][MAX_SIZE] = { false };
    bool hasLiberty = false;
    checkLiberties(x, y, currentPlayer, visited, hasLiberty);

    board[x][y] = '.';
    return !hasLiberty;
}

int removeStones(int startX, int startY, char color) {
    int positions[MAX_SIZE * MAX_SIZE][2];
    int count = 0;
    int removed = 0;

    positions[count][0] = startX;
    positions[count][1] = startY;
    count++;

    for (int i = 0; i < count; i++) {
        int x = positions[i][0];
        int y = positions[i][1];

        if (x < 0 || x >= boardSize || y < 0 || y >= boardSize || board[x][y] != color) {
            continue;
        }

        board[x][y] = '.';
        removed++;

        positions[count][0] = x + 1;
        positions[count][1] = y;
        count++;
        positions[count][0] = x - 1;
        positions[count][1] = y;
        count++;
        positions[count][0] = x;
        positions[count][1] = y + 1;
        count++;
        positions[count][0] = x;
        positions[count][1] = y - 1;
        count++;
    }
    return removed;
}

void captureStones(int x, int y, char opponent, char currentPlayer) {
    bool visited[MAX_SIZE][MAX_SIZE] = { false };
    bool hasLiberty = false;
    checkLiberties(x, y, opponent, visited, hasLiberty);

    if (!hasLiberty) {
        int captured = removeStones(x, y, opponent);
        if (currentPlayer == 'B') {
            BlackScore += captured;
        }
        else {
            WhiteScore += captured;
        }
    }
}

void playGame() {
    char currentPlayer = 'B';
    int x, y, passCount = 0;
    saveToFile(""); 

    while (true) {
        displayBoard();
        cout << endl;
        cout << "Black Score: " << BlackScore << ", White Score: " << WhiteScore << endl;
        appendToFile("Black Score: " + to_string(BlackScore) + ", White Score: " + to_string(WhiteScore) + "\n");

        atomic<bool> timeExpired(false);
        thread timerThread([&]() {
            for (int i = 15; i >= 0; --i) {
                if (timeExpired.load()) return; 
                cout << "\rPlayer " << currentPlayer << "'s Timer: ";
                if (i < 10) {
                    cout << " " << i;
                }
                else {
                    cout << i;
                }
                cout << " seconds remaining, (Enter row and column, -1 -1 to pass, or -2 -2 to end the game): " << flush;

                this_thread::sleep_for(chrono::seconds(1));
            }
            timeExpired.store(true);
            cout << "\rTime's expired! Player " << currentPlayer << " passed their turn automatically. Enter        -1 -1      to continue: " << endl;
            });

        cout << "\nPlayer " << currentPlayer << "'s turn (Enter row and column, -1 -1 to pass, or -2 -2 to end the game): ";
        bool validInput = false;

        while (!validInput && !timeExpired.load()) {
            cin >> x >> y;

            if (timeExpired.load()) break;

            if (x == -2 && y == -2) { 
                timeExpired.store(true); 
                timerThread.join();

                calculateTerritory();
                cout << "Game ended by players!" << endl;
                appendToFile("Game ended by players!\n");
                return;
            }

            if (x == -1 && y == -1) { 
                validInput = true;
                cout << "Player " << currentPlayer << " passed their turn." << endl;
                appendToFile("Player " + string(1, currentPlayer) + " passed their turn.\n");
                passCount++;

                if (passCount == 2) { 
                    calculateTerritory();
                    cout << "Both players passed consecutively. Final Scores:" << endl;
                    cout << "Black: " << BlackScore << endl;
                    cout << "White: " << WhiteScore << endl;

                    appendToFile("Both players passed consecutively. Final Scores:\n");
                    appendToFile("Black: " + to_string(BlackScore) + "\n");
                    appendToFile("White: " + to_string(WhiteScore) + "\n");

                    if (BlackScore > WhiteScore) {
                        cout << "Black wins!" << endl;
                        appendToFile("Black wins!\n");
                    }
                    else if (WhiteScore > BlackScore) {
                        cout << "White wins!" << endl;
                        appendToFile("White wins!\n");
                    }
                    else {
                        cout << "It's a draw!" << endl;
                        appendToFile("It's a draw!\n");
                    }

                    timerThread.join();
                    return;
                }

                timeExpired.store(true); 
                if (currentPlayer == 'B') {
                    currentPlayer = 'W';
                }
                else {
                    currentPlayer = 'B';
                }
            }
            else { 
                x -= 1;
                y -= 1;

                if (isValidMove(x, y)) {
                    if (isSuicidalMove(x, y, currentPlayer)) {
                        cout << "Invalid move: Suicide is not allowed. Try again." << endl;
                        appendToFile("Invalid move: Suicide is not allowed. Try again.\n");
                    }
                    else {
                        validInput = true;
                        board[x][y] = currentPlayer;

                        char opponent = 'B';
                        if (currentPlayer == 'B') {
                            opponent = 'W';
                        }
                        captureStones(x + 1, y, opponent, currentPlayer);
                        captureStones(x - 1, y, opponent, currentPlayer);
                        captureStones(x, y + 1, opponent, currentPlayer);
                        captureStones(x, y - 1, opponent, currentPlayer);

                        if (currentPlayer == 'B') {
                            currentPlayer = 'W';
                        }
                        else {
                            currentPlayer = 'B';
                        }
                        passCount = 0;
                        timeExpired.store(true);
                    }
                }
                else {
                    cout << "Invalid move. Try again." << endl;
                    appendToFile("Invalid move. Try again.\n");
                }
            }
        }

        if (timeExpired.load() && !validInput) {
            appendToFile("Player " + string(1, currentPlayer) + " passed due to timeout.\n");
            passCount++;

            if (passCount == 2) {
                cout << "Both players passed consecutively. Final Scores:" << endl;
                
                cout << "Black: " << BlackScore << endl;
                cout << "White: " << WhiteScore << endl;

                appendToFile("Both players passed consecutively. Final Scores:\n");
                appendToFile("Black: " + to_string(BlackScore) + "\n");
                appendToFile("White: " + to_string(WhiteScore) + "\n");

                if (BlackScore > WhiteScore) {
                    cout << "Black wins!" << endl;
                    appendToFile("Black wins!\n");
                }
                else if (WhiteScore > BlackScore) {
                    cout << "White wins!" << endl;
                    appendToFile("White wins!\n");
                }
                else {
                    cout << "It's a draw!" << endl;
                    appendToFile("It's a draw!\n");
                }

                timerThread.join();
                return;
            }

            if (currentPlayer == 'B') {
                currentPlayer = 'W';
            }
            else {
                currentPlayer = 'B';
            }
        }

        timerThread.join(); 
    }
}


void showHistory() {
    ifstream file(HISTORY_FILE);
    if (file.is_open()) {
        string line;
        cout << "Game History:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to read game history." << endl;
    }
}

int main() {
    cout << "Enter board size (between 5 and 19): ";
    cin >> boardSize;
    if (boardSize < 5 || boardSize > 19) {
        cout << "Invalid board size. Exiting..." << endl;
        return 0;
    }

    initializeBoard();
    playGame();

    cout << "Would you like to view the game history? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        system("cls");

        cout << "History of the Game (turn by turn): " << endl << endl;
        showHistory();
    }

    return 0;
}
