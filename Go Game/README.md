# goGame c++

## Overview
Console-based Go game implementation in C++ with:
- configurable board size,
- turn timer,
- suicide move checking,
- capture logic,
- game history persistence (`game_history.txt`).

## Key File
- `timerAdded.cpp`: main game implementation and entry point.

## Features
- 2-player local play (Black/White turns).
- Timeout-based auto-pass behavior.
- Move validation and capture processing.
- End conditions:
  - manual stop (`-2 -2`),
  - two consecutive passes (`-1 -1`).

## Notes
- Uses `system("cls")`, so this is Windows-console oriented.
- Ensure write permissions for `game_history.txt`.

## Build
Compile `timerAdded.cpp` in your C++ compiler or create a Visual Studio project around it.
