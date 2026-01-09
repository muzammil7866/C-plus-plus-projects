# Bingo Game

A console-based Bingo game with user authentication and game history tracking.

## Features
- Login/Signup system
- Random 5x5 board generation  
- 2-player turn-based gameplay
- Automatic win detection
- Score tracking & history

## How to Run
```bash
g++ bingo.cpp -o bingo
```

## Gameplay

1. Login or create account

2. Start new game (gets unique ID)

3. Enter player names

4. Take turns calling numbers (1-25)

5. First to complete 5 lines wins

**Note:** Windows OS required (uses Windows headers)

Files created:

**login.txt** - Stores user credentials

**playersHistory.txt** - Saves game record