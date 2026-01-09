#include <iostream>
#include <map>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\nCONTACT MANAGEMENT SYSTEM" << endl;
    cout << "\n\n\t1. Add Contact" << endl;
    cout << "\n\t2. Search Contact" << endl;
    cout << "\n\t3. Delete Contact" << endl;
    cout << "\n\t4. Display All Contacts" << endl;
    cout << "\n\t5. Exit" << endl;
    cout << "\n\nChoose an option: ";
}

int main() {

    map<string, string> contacts;

    int choice;

    while (true) {
        system("cls");
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            break; // Exit the program
        }

        switch (choice) {

        case 1:
        {
            system("cls");
            // Add Contact
            string name, phone;
            cout << "\n\tEnter contact name: ";
            cin.ignore(); // Ignore the newline left in the buffer
            getline(cin, name); // Get the full name (including spaces)
            cout << "\n\tEnter contact phone number: ";
            getline(cin, phone);

            // Add to the map
            contacts[name] = phone;
            cout << "\nContact added successfully!" << endl<<endl;
            system("pause");
            break;
        }

        case 2:
        {
            system("cls");
            // Search Contact
            string name;
            cout << "\n\tEnter contact name to search: ";
            cin.ignore();
            getline(cin, name);

            //auto detects the object type of iterator
            //.find() returns object if any key in contacts matches the name or else points at the end of map
            auto it = contacts.find(name);

           if (it != contacts.end()) //if it does not point to end then it means name is found
          
            {
                cout << "\nContact found: " << it->first << " - " << it->second << endl<<endl;
            }
           //points at end means name not found
            else {
                cout << "\nContact not found." << endl<<endl;
            }
            system("pause");
            break;
        }

        case 3: { // Delete Contact
            system("cls");
            string name;
            cout << "\n\tEnter contact name to delete: ";
            cin.ignore();
            getline(cin, name);

            auto it = contacts.find(name);
            if (it != contacts.end()) {
                contacts.erase(it);
                cout << "\nContact deleted successfully!" << endl << endl;
            }
            else {
                cout << "\nContact not found." << endl<<endl;
            }
            system("pause");
            break;
        }

        case 4: { // Display All Contacts
            system("cls");
            cout << "\n\tAll Contacts: " << endl;

            cout << endl;

            //const to make sure that original object is not modified
            //auto automatically detects which object type is each element in contacts
            //& used to avoid making copy of object
            for (const auto& contact : contacts) {
                cout << contact.first << " - " << contact.second << endl<<endl;
            }

            system("pause");
            break;
        }

        default:
            cout << "\n\tInvalid option. Please try again." << endl<<endl;
            system("pause");
        }

    }
    return 0;
}
