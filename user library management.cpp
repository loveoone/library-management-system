#include <iostream>
using namespace std;

const int MAX_USERS = 100;
const int MAX_BOOKS = 100;
const int MAX_NAME_LEN = 50;
const int MAX_TITLE_LEN = 100;

int userIds[MAX_USERS];
char userNames[MAX_USERS][MAX_NAME_LEN];
int userCount = 0;

int bookIds[MAX_BOOKS];
char bookTitles[MAX_BOOKS][MAX_TITLE_LEN];
bool bookIsIssued[MAX_BOOKS];
int issuedToUserId[MAX_BOOKS];
int bookCount = 0;

// Function to read a line into char array
void readLine(char arr[], int length) {
    cin.ignore(); // clear previous newline
    for (int i = 0; i < length; i++) {
        char c = cin.get();
        if (c == '\n') {
            arr[i] = '\0';
            break;
        }
        arr[i] = c;
    }
}

// Add user
void addUser() {
    if (userCount >= MAX_USERS) {
        cout << "User limit reached!\n";
        return;
    }

    cout << "Enter user ID: ";
    cin >> userIds[userCount];

    cout << "Enter user name: ";
    readLine(userNames[userCount], MAX_NAME_LEN);

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
    cin >> bookIds[bookCount];

    cout << "Enter book title: ";
    readLine(bookTitles[bookCount], MAX_TITLE_LEN);

    bookIsIssued[bookCount] = false;
    issuedToUserId[bookCount] = -1;
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

    int bookIndex = -1;
    for (int i = 0; i < bookCount; i++) {
        if (bookIds[i] == bookId) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        cout << "Book not found!\n";
        return;
    }

    if (bookIsIssued[bookIndex]) {
        cout << "Book already issued!\n";
        return;
    }

    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (userIds[i] == userId) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        cout << "User not found!\n";
        return;
    }

    bookIsIssued[bookIndex] = true;
    issuedToUserId[bookIndex] = userId;

    cout << "Book issued to " << userNames[userIndex] << "!\n";
}

// View issued books
void viewIssuedBooks() {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookIsIssued[i]) {
            found = true;
            cout << "Book ID: " << bookIds[i]
                 << ", Title: " << bookTitles[i]
                 << ", Issued to User ID: " << issuedToUserId[i] << "\n";
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


    
   
