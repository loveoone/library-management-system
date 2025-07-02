#include <iostream>
using namespace std;

// ------------------ Structures ------------------

struct Book {
    int id;
    char title[50];
    char author[50];
    bool isIssued;
};

struct User {
    int id;
    char name[50];
    char role[20];
};

// ------------------ Global Arrays ------------------

const int MAX_BOOKS = 100;
Book books[MAX_BOOKS];
int bookCount = 0;

const int MAX_USERS = 100;
User users[MAX_USERS];
int userCount = 0;

// ------------------ Simulated File Functions ------------------

void simulateBookData() {
    // Simulate loading books
    books[0] = {101, "C++ Primer", "Stanley Lippman", false};
    books[1] = {102, "Algorithms", "CLRS", true};
    bookCount = 2;
}

void simulateUserData() {
    // Simulate loading users
    users[0] = {201, "Alice", "student"};
    users[1] = {202, "Bob", "staff"};
    userCount = 2;
}

void printSavedBooks() {
    cout << "\n📚 Simulated Saved Book Data:\n";
    for (int i = 0; i < bookCount; i++) {
        cout << books[i].id << " | " << books[i].title << " | " << books[i].author;
        cout << " | " << (books[i].isIssued ? "Issued" : "Available") << "\n";
    }
}

void printSavedUsers() {
    cout << "\n👤 Simulated Saved User Data:\n";
    for (int i = 0; i < userCount; i++) {
        cout << users[i].id << " | " << users[i].name << " | " << users[i].role << "\n";
    }
}

// ------------------ Main (Demo) ------------------

int main() {
    simulateBookData();
    simulateUserData();

    cout << "📁 Simulated File Load Complete.\n";

    printSavedBooks();
    printSavedUsers();

    return 0;
}