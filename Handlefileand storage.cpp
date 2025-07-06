#include <iostream>
using namespace std;

// ------------------ Constants ------------------
const int MAX_BOOKS = 100;
const int MAX_USERS = 100;

// ------------------ Book Data ------------------
int bookIDs[MAX_BOOKS];
const char bookTitles[MAX_BOOKS];
const char bookAuthors[MAX_BOOKS];
bool bookIssued[MAX_BOOKS];
int bookCount = 0;

// ------------------ User Data ------------------
int userIDs[MAX_USERS];
const char userNames[MAX_USERS];
const char userRoles[MAX_USERS];
int userCount = 0;

// ------------------ Simulated File Functions ------------------
void simulateBookData() {
    bookIDs[0] = 101;
    bookTitles[0] = "C++ Primer";
    bookAuthors[0] = " ኦሾ";
    bookIssued[0] = false;

    bookIDs[1] = 102;
    bookTitles[1] = "Algorithms";
    bookAuthors[1] = "CLRS";
    bookIssued[1] = true;

    bookCount = 2;
}

void simulateUserData() {
    userIDs[0] = 201;
    userNames[0] = "Tedi";
    userRoles[0] = "student";

    userIDs[1] = 202;
    userNames[1] = "Mr.Dagmawi";
    userRoles[1] = "staff";

    userCount = 2;
}

void printSavedBooks() {
    cout << "\n Simulated Saved Book Data:\n";
    for (int i = 0; i < bookCount; i++) {
        cout << bookIDs[i] << " | " << bookTitles[i] << " | " << bookAuthors[i];
        cout << " | " << (bookIssued[i] ? "Issued" : "Available") << "\n";
    }
}

void printSavedUsers() {
    cout << "\n Simulated Saved User Data:\n";
    for (int i = 0; i < userCount; i++) {
        cout << userIDs[i] << " | " << userNames[i] << " | " << userRoles[i] << "\n";
    }
}

// ---------- Main --------------
int main() {
    simulateBookData();
    simulateUserData();

    cout << " Simulated File Load Complete.\n";
    printSavedBooks();
    printSavedUsers();

    return 0;
}