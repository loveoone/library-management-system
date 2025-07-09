#include <iostream>
using namespace std;

const int SIZE = 100;

int ids[SIZE];
char titles[SIZE][100];
char issuedTos[SIZE][100];
char issueDates[SIZE][20];
bool isIssueds[SIZE];
int bookCount = 0;

// Manual string copy
void copy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Manual string compare (returns true if equal)
bool equal(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

// Add a new book
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
    cin.ignore();  // clear newline
    cout << "Enter Title: ";
    cin.getline(titles[bookCount], 100);

    isIssueds[bookCount] = false;
    issuedTos[bookCount][0] = '\0';
    issueDates[bookCount][0] = '\0';
    bookCount++;

    cout << "Book added.\n";
}

// Issue a book to a user
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
                char borrower[100];
                cin.getline(borrower, 100);
                copy(issuedTos[i], borrower);

                cout << "Issue Date: ";
                char date[20];
                cin.getline(date, 20);
                copy(issueDates[i], date);

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

// Return a book
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
                issuedTos[i][0] = '\0';
                issueDates[i][0] = '\0';
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

// View issued books
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

// Main menu
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