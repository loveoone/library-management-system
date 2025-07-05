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
    cin >> ids[bookCount];

    cout << "Enter Title (no spaces): ";
    cin >> titles[bookCount]; // reads single word (no spaces)

    isIssueds[bookCount] = false;
    bookCount++;
    cout << "Book added.\n";
}

void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (ids[i] == id && !isIssueds[i]) {
            cout << "Issued To (no spaces): ";
            cin >> issuedTos[i];
            cout << "Issue Date (no spaces): ";
            cin >> issueDates[i];
            isIssueds[i] = true;
            cout << "Book issued.\n";
            return;
        }
    }
    cout << "Book not found or already issued.\n";
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
        cout << "\n1. Add Book\n2. Issue Book\n3. View Issued Books\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) addBook();
        else if (choice == 2) issueBook();
        else if (choice == 3) viewIssued();
    } while (choice != 0);
    return 0;
}
