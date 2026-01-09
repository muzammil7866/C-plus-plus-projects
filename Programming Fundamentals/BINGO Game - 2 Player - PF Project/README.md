# 🎮 Bingo - 2 Player Pro

A premium console-based Bingo experience built with C++. This project demonstrates fundamental programming concepts while providing an engaging, competitive gameplay environment with persistent data tracking.

## 🎯 Business Goals Achieved

- **User Engagement & Retention**: Implemented a secure Login/Signup system to personalize the user experience and maintain progress.
- **Data Integrity & Persistence**: Utilizes file-based storage (`login.txt`, `playersHistory.txt`) to ensure user credentials and game statistics are preserved across sessions.
- **Operational Efficiency**: Automated win detection and board generation logic reduces manual overhead and ensures fair gameplay.
- **Improved UX/UI**: Leverages terminal color coding and ASCII headers to provide a more intuitive and visually appealing interface than standard console apps.
- **Scalability**: The modular code structure allows for easy addition of new features, such as difficulty levels or global leaderboards.

## 🚀 Key Features

- **Secure Authentication**: Password masking and account validation for player security.
- **Dynamic Board Logic**: Randomized 5x5 board generation using Fisher-Yates shuffle algorithm style logic.
- **Fair Play Mechanics**: Randomized toss system to decide starting turns.
- **Real-time Win Detection**: Continuous monitoring of rows, columns, and diagonals for Bingo completion.
- **Historical Tracking**: Detailed game logs including unique Game IDs and scores.

## 🏗️ Project Structure

- `bingo.cpp`: The core application containing game logic, UI rendering, and file I/O.
- `login.txt`: Local database for storing encrypted/masked user credentials.
- `playersHistory.txt`: Persistent log of past games, winners, and scores.
- `bingo.exe`: Compiled executable for Windows environments.

## 🛠️ How to Run

1. **Prerequisites**: Windows OS and a C++ compiler (like MinGW/GCC).
2. **Compile**:
   ```bash
   g++ bingo.cpp -o bingo
   ```
3. **Execute**:
   ```bash
   ./bingo
   ```

## 🎮 Gameplay Guide

1. **Access**: Log in or create a new account to enter the main menu.
2. **Initialization**: Start a new game to receive a unique **Game ID**.
3. **Setup**: Enter player names; the system will generate two unique 5x5 boards.
4. **Turns**: Call out numbers (1-25) strategically. Numbers are marked on both boards simultaneously.
5. **Winning**: The first player to complete **5 lines** (horizontal, vertical, or diagonal) wins!

---
*Developed as a Programming Fundamentals Project.*