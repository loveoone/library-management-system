#include <iostream>
using namespace std;

// ================== GLOBAL DATA ==================
const int MAX_BOOKS = 100;
int bookIds[MAX_BOOKS];
char bookTitles[MAX_BOOKS][50];
char bookAuthors[MAX_BOOKS][50];
bool bookIssued[MAX_BOOKS];
int bookCount = 0;

const int MAX_MEMBERS = 10;
int memberIds[MAX_MEMBERS] = {1, 2};
char memberNames[MAX_MEMBERS][50] = {"Alice Smith", "Bob Johnson"};

const int MAX_TRANSACTIONS = 100;
char transISBN[MAX_TRANSACTIONS][10];
int transMemberId[MAX_TRANSACTIONS];
char transBorrowDate[MAX_TRANSACTIONS][11];
char transDueDate[MAX_TRANSACTIONS][11];
int transactionCount = 3;

// Preloaded transactions
void loadSampleTransactions() {
    strcpy(transISBN[0], "123456");
    transMemberId[0] = 1;
    strcpy(transBorrowDate[0], "2025-06-01");
    strcpy(transDueDate[0], "2025-06-15");

    strcpy(transISBN[1], "789012");
    transMemberId[1] = 2;
    strcpy(transBorrowDate[1], "2025-06-10");
    strcpy(transDueDate[1], "2025-06-24");

    strcpy(transISBN[2], "345678");
    transMemberId[2] = 1;
    strcpy(transBorrowDate[2], "2025-06-20");
    strcpy(transDueDate[2], "2025-07-05");
}

// ================== BOOK MANAGEMENT ==================
void bookMenu() {
    int choice;
    do {
        cout << "\nBook Management Menu\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Modify Book\n";
        cout << "4. Delete Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (bookCount >= MAX_BOOKS) {
                cout << "Library full.\n";
                continue;
            }
            cout << "Enter Book ID: ";
            cin >> bookIds[bookCount];
            cin.ignore();
            cout << "Enter Title: ";
            cin.getline(bookTitles[bookCount], 50);
            cout << "Enter Author: ";
            cin.getline(bookAuthors[bookCount], 50);
            bookIssued[bookCount] = false;
            bookCount++;
            cout << "Book added.\n";
        }
        else if (choice == 2) {
            for (int i = 0; i < bookCount; i++) {
                cout << bookIds[i] << " | "
                     << bookTitles[i] << " | "
                     << bookAuthors[i] << " | "
                     << (bookIssued[i] ? "Issued" : "Available") << endl;
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to modify: ";
            cin >> id;
            cin.ignore();
            bool found = false;
            for (int i = 0; i < bookCount; i++) {
                if (bookIds[i] == id) {
                    cout << "Enter new title: ";
                    cin.getline(bookTitles[i], 50);
                    cout << "Enter new author: ";
                    cin.getline(bookAuthors[i], 50);
                    cout << "Book updated.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to delete: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < bookCount; i++) {
                if (bookIds[i] == id) {
                    for (int j = i; j < bookCount - 1; j++) {
                        bookIds[j] = bookIds[j + 1];
                        strcpy(bookTitles[j], bookTitles[j + 1]);
                        strcpy(bookAuthors[j], bookAuthors[j + 1]);
                        bookIssued[j] = bookIssued[j + 1];
                    }
                    bookCount--;
                    cout << "Book deleted.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
    } while (choice != 0);
}

// ================== RETURN BOOK ==================
void returnBook() {
    char isbn[10];
    cout << "Enter Book ISBN to return: ";
    cin >> isbn;

    bool found = false;
    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transISBN[i], isbn) == 0) {
            cout << "Book with ISBN " << isbn << " returned.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found in transactions.\n";
    }
}

// ================== REPORT (Simple Display) ==================
void generateReport() {
    cout << "\nBorrowed Books Report\n";
    cout << "ISBN\tMember ID\tBorrow Date\tDue Date\n";
    for (int i = 0; i < transactionCount; i++) {
        cout << transISBN[i] << "\t"
             << transMemberId[i] << "\t\t"
             << transBorrowDate[i] << "\t"
             << transDueDate[i] << endl;
    }
}

// ================== MAIN MENU ==================
void mainMenu() {
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Book Management\n";
        cout << "2. Return Book\n";
        cout << "3. View Report\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bookMenu(); break;
            case 2: returnBook(); break;
            case 3: generateReport(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid.\n";
        }
    } while (choice != 0);
}

// ================== MAIN ==================
int main() {
    loadSampleTransactions();
    mainMenu();
    return 0;
}