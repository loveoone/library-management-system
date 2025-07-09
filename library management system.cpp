#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;

int ids[SIZE];
string titles[SIZE];
string issuedTos[SIZE];
string issueDates[SIZE];
bool isIssueds[SIZE];
int bookCount = 0;

void addBook() {
    cout << "Enter Book ID: ";
    int newID; 
    cin >> newID;
    // Check for duplicate ID
    for (int i = 0; i < bookCount; i++) {
        if (ids[i] == newID) {
            cout << "Book ID already exists. Try again.\n";
            return;
        }
    }
    ids[bookCount] = newID;
    cin.ignore();  // Clear newline

    cout << "Enter Title: ";
    getline(cin, titles[bookCount]);
    isIssueds[bookCount] = false;
    issuedTos[bookCount] = "";
    issueDates[bookCount] = "";
    bookCount++;
    cout << "Book added.\n";
}

void issueBook() {
    if (bookCount == 0) {
        cout << "No books available to issue.\n";
        return;
    }
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (ids[i] == id) {
            found = true;
            if (!isIssueds[i]) {
                cout << "Issued To: ";
                getline(cin, issuedTos[i]);
                cout << "Issue Date: ";
                getline(cin, issueDates[i]);
                isIssueds[i] = true;
                cout << "Book issued.\n";
                return;
            } else {
                cout << "Book already issued to " << issuedTos[i] << ".\n";
                return;
            }
        }
    }
    if (!found) cout << "Book not found.\n";
}

void returnBook() {
    if (bookCount == 0) {
        cout << "No books in library.\n";
        return;
    }
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (ids[i] == id) {
            found = true;
            if (isIssueds[i]) {
                isIssueds[i] = false;
                issuedTos[i] = "";
                issueDates[i] = "";
                cout << "Book returned successfully.\n";
                return;
            } else {
                cout << "Book was not issued.\n";
                return;
            }
        }
    }
    if (!found) cout << "Book not found.\n";
}

void viewIssued() {
    cout << "\n--- Issued Books ---\n";
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (isIssueds[i]) {
            cout << "Book ID: " << ids[i] << "\n";
            cout << "Title: " << titles[i] << "\n";
            cout << "Issued To: " << issuedTos[i] << "\n";
            cout << "Issue Date: " << issueDates[i] << "\n";
            cout << "--------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No books are currently issued.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Book\n2. Issue Book\n3. Return Book\n4. View Issued Books\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: viewIssued(); break;
            case 0: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
mestakakle nager kalwe eywte este