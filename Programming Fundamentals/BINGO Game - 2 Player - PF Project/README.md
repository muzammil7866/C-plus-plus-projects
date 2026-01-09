# BINGO Game - Professional 2-Player Edition

A robust, console-based Bingo game implemented in C++, featuring a secure-ish authentication layer, dynamic board generation, and persistent game history tracking. This project demonstrates core programming fundamentals including file I/O, randomized algorithms, and structured software design.

## Business Goals

- **User Retention**: Provides a competitive 2-player experience to keep users engaged.
- **Data Integrity**: Ensures fair play with randomized board generation and prevents unauthorized access via a password-protected login system.
- **Performance Tracking**: Maintains a persistent history of games, allowing players to track their progress and scores over time.
- **Educational Value**: Serves as a primary example of implementing business logic (win conditions, turn management) in a C++ environment.

## Features

- **Secure Authentication**: Signup and login system with password masking for user privacy.
- **Dynamic Boards**: Automatic generation of unique 5x5 Bingo boards (numbers 1-25) for every game.
- **Fair Play Mechanics**: Integrated "Toss" system to determine the starting player.
- **Intuitive UI**: Console-based interface with clear board visualization and turn-based prompts.
- **Persistent Data**: 
    - `login.txt`: Stores encrypted-style (plain text for now) user credentials.
    - `playersHistory.txt`: Maintains a record of Game IDs, Player Names, and winning Scores.

## Prerequisites

- **OS**: Windows (Required for `windows.h` and console-specific functions).
- **Compiler**: A C++ compiler such as `g++` (MinGW).

## Installation & Setup

1. **Clone the repository** (or navigate to the project folder).
2. **Compile the program**:
   ```bash
   g++ bingo.cpp -o bingo.exe
   ```
3. **Run the game**:
   ```bash
   ./bingo.exe
   ```

## How to Play

1. **Authentication**: Start by creating an account or logging in with existing credentials.
2. **Setup**: Once in the main menu, select "Play Game". Enter the names of the two competing players.
3. **The Game**: 
    - The system performs a random toss to decide who goes first.
    - Players take turns calling numbers between 1 and 25.
    - The called number is automatically marked (multiplied by 0) on both boards.
4. **Winning**: The first player to complete **5 lines** (rows, columns, or diagonals) wins the round.
5. **Scoring**: Each completed line adds to the player's performance score, which is then saved to the history.

## Project Structure

- `bingo.cpp`: The main source code containing game logic, UI rendering, and file handling.
- `login.txt`: Local database for user authentication.
- `playersHistory.txt`: Record of all completed games.