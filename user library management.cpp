#include <iostream>
using namespace std;

const int MAX_USERS = 100;
const int MAX_BOOKS = 100;
const int MAX_NAME_LEN = 50;
const int MAX_TITLE_LEN = 100;

struct User {
    int id;
    char name[MAX_NAME_LEN];
};

struct Book {
    int id;
    char title[MAX_TITLE_LEN];
    bool isIssued;
    int issuedToUserId;
};

User users[MAX_USERS];
Book books[MAX_BOOKS];
int userCount = 0;
int bookCount = 0;

// Add user
void addUser() {
    if (userCount >= MAX_USERS) {
        cout << "User limit reached!\n";
        return;
    }

    cout << "Enter user ID: ";
    cin >> users[userCount].id;
    cin.ignore(); // remove newline
    cout << "Enter user name: ";
    cin.getline(users[userCount].name, MAX_NAME_LEN);

    userCount++;
    cout << "User added successfully!\n";
}

// Add book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Book limit reached!\n";
        return;
    }

    cout << "Enter book ID: ";
    cin >> books[bookCount].id;
    cin.ignore();
    cout << "Enter book title: ";
    cin.getline(books[bookCount].title, MAX_TITLE_LEN);

    books[bookCount].isIssued = false;
    books[bookCount].issuedToUserId = -1;
    bookCount++;
    cout << "Book added successfully!\n";
}

// Issue book
void issueBook() {
    int bookId, userId;
    cout << "Enter book ID to issue: ";
    cin >> bookId;
    cout << "Enter user ID to issue to: ";
    cin >> userId;

    // Find book
    int bookIndex = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        cout << "Book not found!\n";
        return;
    }

    if (books[bookIndex].isIssued) {
        cout << "Book already issued!\n";
        return;
    }

    // Find user
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == userId) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        cout << "User not found!\n";
        return;
    }

    books[bookIndex].isIssued = true;
    books[bookIndex].issuedToUserId = userId;
    cout << "Book issued to " << users[userIndex].name << "!\n";
}

// View issued books
void viewIssuedBooks() {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isIssued) {
            found = true;
            cout << "Book ID: " << books[i].id 
                 << ", Title: " << books[i].title 
                 << ", Issued to User ID: " << books[i].issuedToUserId << "\n";
        }
    }

    if (!found) {
        cout << "No books issued.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Library Management Menu ---\n";
        cout << "1. Add User\n";
        cout << "2. Add Book\n";
        cout << "3. Issue Book\n";
        cout << "4. View Issued Books\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addUser(); break;
            case 2: addBook(); break;
            case 3: issueBook(); break;
            case 4: viewIssuedBooks(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
