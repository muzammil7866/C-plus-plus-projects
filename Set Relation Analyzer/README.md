# Set Relation Analyzer

A C++ console application (Visual Studio project) for analyzing mathematical relations between finite sets in Discrete Structures.

## Features

- Takes two user-defined sets `A` and `B`
- Normalizes inputs by sorting and removing duplicate elements
- Computes `|A x B|` and total number of possible relations from `A` to `B`
- Displays Cartesian product `A x B` explicitly
- For equal-set domain (`A = B`), provides:
  - Reflexive relation existence and count
  - Symmetric relation existence and count
  - Anti-symmetric relation existence and count
  - Count for `(Reflexive AND Symmetric)` relations
  - Count for `(Symmetric AND Anti-symmetric)` relations
- Uses validated console input for sizes, set values, and menu options

## Business Goals Achieved

- **Reliability:** Invalid user input no longer crashes or breaks the program flow
- **Correctness:** Relation formulas and property applicability are explicit and mathematically aligned
- **Maintainability:** Cleaner modern C++ structure reduces bug risk and is easier to extend
- **Portability of Repository:** Build artifacts and machine-local files are ignored for clean Git history
- **Academic Utility:** Ready-to-demo console workflow for coursework and viva/lab evaluation

## Tech Stack

- Language: C++
- IDE: Visual Studio Community
- Project Type: Console Application (`.sln` + `.vcxproj`)

## Build and Run (Visual Studio)

1. Open `Set Relation Analyzer.sln` in Visual Studio Community.
2. Choose build configuration (`Debug` or `Release`) and target platform (`x64` recommended).
3. Build the solution.
4. Run without debugging (`Ctrl + F5`) for console interaction.

## Project Structure

- `Source.cpp` -> Main application source
- `Set Relation Analyzer.sln` -> Visual Studio solution
- `Set Relation Analyzer.vcxproj` -> Visual Studio C++ project file
- `Set Relation Analyzer.vcxproj.filters` -> Visual Studio filter mapping
- `.gitignore` -> Ignores Visual Studio/cache/build artifacts

## Notes

- Mathematical properties like reflexive/symmetric/anti-symmetric are defined for relations on a single set (`A x A`), so the app marks them as not applicable when `A != B`.
- Input sets are normalized internally (sorted + unique), so repeated elements entered by users are handled safely.
