#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {

long long readNonNegativeInt(const string& prompt) {
    while (true) {
        cout << prompt;

        long long value;
        if (cin >> value && value >= 0) {
            return value;
        }

        cout << "Invalid input. Please enter a non-negative integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readAnyInt(const string& prompt) {
    while (true) {
        cout << prompt;

        int value;
        if (cin >> value) {
            return value;
        }

        cout << "Invalid input. Please enter an integer value.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readMenuOption() {
    while (true) {
        cout << "\nEnter option (1-9): ";

        int option;
        if (cin >> option && option >= 1 && option <= 9) {
            return option;
        }

        cout << "Invalid menu option. Please choose from 1 to 9.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

vector<int> readSet(const string& label, int size) {
    vector<int> values;
    values.reserve(static_cast<size_t>(size));

    cout << "\nEnter elements for " << label << ":\n";
    for (int i = 0; i < size; ++i) {
        values.push_back(readAnyInt("Element " + to_string(i + 1) + ": "));
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    return values;
}

void displaySet(const vector<int>& setValues, const string& label) {
    cout << label << " = {";
    for (size_t i = 0; i < setValues.size(); ++i) {
        cout << setValues[i];
        if (i + 1 < setValues.size()) {
            cout << ", ";
        }
    }
    cout << "}\n";
}

void displayCartesianProduct(const vector<int>& setA, const vector<int>& setB) {
    cout << "\nA x B = {";

    bool first = true;
    for (int a : setA) {
        for (int b : setB) {
            if (!first) {
                cout << ", ";
            }
            cout << "(" << a << ", " << b << ")";
            first = false;
        }
    }

    cout << "}\n";
}

string powerOfTwoAsString(long long exponent) {
    if (exponent < 0) {
        return "undefined";
    }

    if (exponent <= 62) {
        unsigned long long value = 1ULL << exponent;
        return to_string(value);
    }

    ostringstream out;
    out << "2^" << exponent << " (~" << scientific << setprecision(4)
        << powl(2.0L, static_cast<long double>(exponent)) << ")";
    return out.str();
}

string antiSymmetricCountAsString(long long n) {
    if (n < 0) {
        return "undefined";
    }

    const long long pairs = n * (n - 1) / 2;
    long double approx = powl(3.0L, static_cast<long double>(pairs)) *
                        powl(2.0L, static_cast<long double>(n));

    ostringstream out;
    out << "2^" << n << " * 3^" << pairs;

    if (n <= 12) {
        out << " (= " << fixed << setprecision(0) << approx << ")";
    } else {
        out << " (~" << scientific << setprecision(4) << approx << ")";
    }

    return out.str();
}

bool areEqualSets(const vector<int>& setA, const vector<int>& setB) {
    return setA == setB;
}

void showMenu() {
    cout << "\n========== SET RELATION ANALYZER ==========";
    cout << "\n1) Show |A x B| and total relations from A to B";
    cout << "\n2) Display sets";
    cout << "\n3) Display Cartesian product (A x B)";
    cout << "\n4) Reflexive relation existence + count";
    cout << "\n5) Symmetric relation existence + count";
    cout << "\n6) Anti-symmetric relation existence + count";
    cout << "\n7) Both Reflexive and Symmetric existence + count";
    cout << "\n8) Both Symmetric and Anti-symmetric existence + count";
    cout << "\n9) Exit";
    cout << "\n==========================================\n";
}

} // namespace

int main() {
    cout << "SET RELATION ANALYZER\n";
    cout << "This program removes duplicates and sorts each set automatically.\n";

    int sizeA = static_cast<int>(readNonNegativeInt("\nEnter number of elements in Set A: "));
    vector<int> setA = readSet("Set A", sizeA);

    int sizeB = static_cast<int>(readNonNegativeInt("\nEnter number of elements in Set B: "));
    vector<int> setB = readSet("Set B", sizeB);

    cout << "\nNormalized Sets (sorted, unique):\n";
    displaySet(setA, "A");
    displaySet(setB, "B");

    while (true) {
        showMenu();
        const int option = readMenuOption();

        const long long nA = static_cast<long long>(setA.size());
        const long long nB = static_cast<long long>(setB.size());
        const bool equalDomain = areEqualSets(setA, setB);

        if (option == 1) {
              const long long cartesianSize = nA * nB;
              cout << "\n|A x B| (number of ordered pairs) = |A| * |B| = "
                  << nA << " * " << nB << " = " << cartesianSize << "\n";
              cout << "Total number of relations from A to B = 2^(|A|*|B|) = 2^"
                  << cartesianSize << " = " << powerOfTwoAsString(cartesianSize) << "\n";
            continue;
        }

        if (option == 2) {
            cout << "\n";
            displaySet(setA, "A");
            displaySet(setB, "B");
            continue;
        }

        if (option == 3) {
            displayCartesianProduct(setA, setB);
            continue;
        }

        if (option == 9) {
            cout << "\nThanks for using Set Relation Analyzer.\n";
            break;
        }

        if (!equalDomain) {
            cout << "\nThis property is defined for relations on a single set (A x A).\n";
            cout << "Current sets are not equal, so this check is not applicable.\n";
            continue;
        }

        if (option == 4) {
            cout << "\nReflexive relations exist on A x A: YES\n";
            cout << "Count of reflexive relations: "
                 << powerOfTwoAsString(nA * (nA - 1)) << "\n";
            continue;
        }

        if (option == 5) {
            cout << "\nSymmetric relations exist on A x A: YES\n";
            cout << "Count of symmetric relations: "
                 << powerOfTwoAsString((nA * (nA + 1)) / 2) << "\n";
            continue;
        }

        if (option == 6) {
            cout << "\nAnti-symmetric relations exist on A x A: YES\n";
            cout << "Count of anti-symmetric relations: "
                 << antiSymmetricCountAsString(nA) << "\n";
            continue;
        }

        if (option == 7) {
            cout << "\nRelations that are both reflexive and symmetric exist on A x A: YES\n";
            cout << "Count of (reflexive AND symmetric) relations: "
                 << powerOfTwoAsString((nA * (nA - 1)) / 2) << "\n";
            continue;
        }

        if (option == 8) {
            cout << "\nRelations that are both symmetric and anti-symmetric exist on A x A: YES\n";
            cout << "Count of (symmetric AND anti-symmetric) relations: "
                 << powerOfTwoAsString(nA) << "\n";
            continue;
        }

        cout << "\nUnexpected option state. Please try again.\n";
    }

    return 0;
}
