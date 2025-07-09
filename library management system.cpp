#include <iostream>
#include <string>  // kept as you requested
using namespace std;

// ------------------ Constants ------------------
const int MAX_USERS = 100;
const int MAX_BOOKS = 100;
const int MAX_NAME_LEN = 50;
const int MAX_TITLE_LEN = 100;

// ------------------ User Data ------------------
int userIds[MAX_USERS];
char userNames[MAX_USERS][MAX_NAME_LEN];
int userCount = 0;

// ------------------ Book Data ------------------
int bookIds[MAX_BOOKS];
char bookTitles[MAX_BOOKS][MAX_TITLE_LEN];
char bookAuthors[MAX_BOOKS][MAX_TITLE_LEN];
bool bookIssued[MAX_BOOKS];
int issuedToUserId[MAX_BOOKS];
int bookCount = 0;

// ------------------ Manual strcpy ------------------
void manualStrcpy(char* dest, const char* src) {
    int i = 0;
    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// ------------------ Manual strcmp ------------------
int manualStrcmp(const char* s1, const char* s2) {
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

// ------------------ Input line to char array ------------------
void readLine(char arr[], int length) {
    cin.ignore(); // clear input buffer
    int i = 0;
    char c;
    while (i < length - 1) {
        c = cin.get();
        if (c == '\n') break;
        arr[i++] = c;
    }
    arr[i] = '\0';
}

// ------------------ User Management ------------------
void addUser() {
    if (userCount >= MAX_USERS) {
        cout << "User limit reached!\n";
        return;
    }

    cout << "Enter user ID: ";
    cin >> userIds[userCount];
    readLine(userNames[userCount], MAX_NAME_LEN);
    userCount++;
    cout << "User added successfully!\n";
}

void listUsers() {
    if (userCount == 0) {
        cout << "No users available.\n";
        return;
    }
    cout << "\n--- User List ---\n";
    for (int i = 0; i < userCount; i++) {
        cout << "ID: " << userIds[i] << " | Name: " << userNames[i] << "\n";
    }
}

// ------------------ Book Management ------------------
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    }

    cout << "Enter Book ID: ";
    cin >> bookIds[bookCount];
    readLine(bookTitles[bookCount], MAX_TITLE_LEN);
    readLine(bookAuthors[bookCount], MAX_TITLE_LEN);
    bookIssued[bookCount] = false;
    issuedToUserId[bookCount] = -1;
    bookCount++;
    cout << "✅ Book added successfully!\n";
}

void viewBooks() {
    if (bookCount == 0) {
        cout << "No books available.\n";
        return;
    }
    cout << "\n--- Book List ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << bookIds[i] << " | " << bookTitles[i] << " | " << bookAuthors[i]
             << " | " << (bookIssued[i] ? "Issued" : "Available") << "\n";
    }
}

void modifyBook() {
    int id;
    cout << "Enter Book ID to modify: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookIds[i] == id) {
            readLine(bookTitles[i], MAX_TITLE_LEN);
            readLine(bookAuthors[i], MAX_TITLE_LEN);
            found = true;
            cout << "✅ Book modified successfully!\n";
            break;
        }
    }
    if (!found) cout << "❌ Book not found.\n";
}void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookIds[i] == id) {
            for (int j = i; j < bookCount - 1; j++) {
                bookIds[j] = bookIds[j+1];
                manualStrcpy(bookTitles[j], bookTitles[j+1]);
                manualStrcpy(bookAuthors[j], bookAuthors[j+1]);
                bookIssued[j] = bookIssued[j+1];
                issuedToUserId[j] = issuedToUserId[j+1];
            }
            bookCount--;
            found = true;
            cout << "✅ Book deleted successfully!\n";
            break;
        }
    }
    if (!found) cout << "❌ Book not found.\n";
}

// ------------------ Issue & Return ------------------
void issueBook() {
    int bookId, userId;
    cout << "Enter Book ID to issue: ";
    cin >> bookId;
    cout << "Enter User ID to issue to: ";
    cin >> userId;

    int bookIndex = -1, userIndex = -1;
    for (int i = 0; i < bookCount; i++) {
        if (bookIds[i] == bookId) bookIndex = i;
    }
    for (int i = 0; i < userCount; i++) {
        if (userIds[i] == userId) userIndex = i;
    }

    if (bookIndex == -1) {
        cout << "Book not found!\n";
        return;
    }
    if (userIndex == -1) {
        cout << "User not found!\n";
        return;
    }
    if (bookIssued[bookIndex]) {
        cout << "Book already issued!\n";
        return;
    }

    bookIssued[bookIndex] = true;
    issuedToUserId[bookIndex] = userId;

    cout << "Book issued to " << userNames[userIndex] << " successfully.\n";
}

void returnBook() {
    int bookId;
    cout << "Enter Book ID to return: ";
    cin >> bookId;

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
    if (!bookIssued[bookIndex]) {
        cout << "Book is not issued currently.\n";
        return;
    }
    bookIssued[bookIndex] = false;
    issuedToUserId[bookIndex] = -1;
    cout << "Book returned successfully.\n";
}

void viewIssuedBooks() {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookIssued[i]) {
            found = true;
            cout << "Book ID: " << bookIds[i] << ", Title: " << bookTitles[i]
                 << ", Issued to User ID: " << issuedToUserId[i] << "\n";
        }
    }
    if (!found) cout << "No books currently issued.\n";
}

// ------------------ File Search ------------------
const int MAX_FILES = 100;
char files[MAX_FILES][200];
int fileCount = 0;

void readFilePath(char path[], int length) {
    cin.ignore();
    int i = 0;
    char c;
    while (i < length - 1) {
        c = cin.get();
        if (c == '\n') break;
        path[i++] = c;
    }
    path[i] = '\0';
}

void fileSearch() {
    cout << "Enter number of files to scan: ";
    cin >> fileCount;
    if (fileCount > MAX_FILES) fileCount = MAX_FILES;

    for (int i = 0; i < fileCount; i++) {
        cout << "Enter file path #" << (i + 1) << ": ";
        readFilePath(files[i], 200);
    }

    cout << "Enter filename to search for: ";
    char target[100];
    cin.ignore();
    int i = 0;
    char c;
    while (i < 99) {
        c = cin.get();
        if (c == '\n') break;
        target[i++] = c;
    }
    target[i] = '\0';

    bool found = false;
    for (int i = 0; i < fileCount; i++) {
        // Extract filename from path
        int lastSlash = -1;
        for (int j = 0; files[i][j] != '\0'; j++) {
            if (files[i][j] == '/' || files[i][j] == '\\') lastSlash = j;
        }
        const char* name = &files[i][lastSlash + 1];

        if (manualStrcmp(name, target) == 0) {
            cout << "Found: " << files[i] << "\n";
            found = true;
        }
    }
    if (!found) cout << "File not found.\n";
}// ------------------ Main Menu ------------------
void mainMenu() {
    int choice;
    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. User Management\n2. Book Management\n3. Issue Book\n4. Return Book\n5. View Issued Books\n6. File Search\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int uchoice;
                do {
                    cout << "\n--- User Menu ---\n1. Add User\n2. List Users\n0. Back\nChoice: ";
                    cin >> uchoice;
                    cin.ignore();
                    if (uchoice == 1) addUser();
                    else if (uchoice == 2) listUsers();
                } while (uchoice != 0);
                break;
            }
            case 2: {
                int bchoice;
                do {
                    cout << "\n--- Book Menu ---\n1. Add Book\n2. View Books\n3. Modify Book\n4. Delete Book\n0. Back\nChoice: ";
                    cin >> bchoice;
                    cin.ignore();
                    if (bchoice == 1) addBook();
                    else if (bchoice == 2) viewBooks();
                    else if (bchoice == 3) modifyBook();
                    else if (bchoice == 4) deleteBook();
                } while (bchoice != 0);
                break;
            }
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: viewIssuedBooks(); break;
            case 6: fileSearch(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// ------------------ Main ------------------
int main() {
    mainMenu();
    return 0;
}
