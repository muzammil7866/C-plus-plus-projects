# FirstGUI

## Overview
A wxWidgets-based C++ GUI starter project (`wxApp` + `wxFrame`).

## Current State
- `App.cpp` has active app bootstrap code (`wxIMPLEMENT_APP(App)`).
- `MainFrame.h` declares frame constructor and event handlers.
- `MainFrame.cpp`
- Project depends on `WXWIN` include/lib paths in the Visual Studio project settings.

## Dependency Requirements
This project will only build if wxWidgets is installed and environment/configuration paths are set correctly.