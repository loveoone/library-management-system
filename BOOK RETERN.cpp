#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;
const int TITLE_LEN = 50;

struct Book {
    int id;
    char title[TITLE_LEN];
    bool isIssued;
};

Book library[MAX_BOOKS];
int totalBooks = 0;

// Function to copy string manually (since <string> is not used)
void copyTitle(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0' && i < TITLE_LEN - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to initialize sample books
void initializeLibrary() {
    library[0].id = 01;
    copyTitle(library[0].title, "physics ");
    library[0].isIssued = true;

    library[1].id = 02;
    copyTitle(library[1].title, "chemistry");
    library[1].isIssued = false;

    library[2].id = 03;
    copyTitle(library[2].title, "biology");
    library[2].isIssued = true;

    totalBooks = 3;
}

// Function to return a book
void returnBook() {
    int bookId;
    cout << "Enter Book ID to return: ";
    cin >> bookId;

    bool found = false;

    for (int i = 0; i < totalBooks; i++) {
        if (library[i].id == bookId) {
            found = true;
            if (library[i].isIssued) {
                library[i].isIssued = false;
                cout << "Book \"" << library[i].title << "\" (ID: " << bookId << ") has been returned successfully.\n";
            } else {
                cout << "Book \"" << library[i].title << "\" (ID: " << bookId << ") was not issued.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Book with ID " << bookId << " not found in the library.\n";
    }
}

int main() {
    initializeLibrary();

    cout << "Library Management System: Book Return :- \n";
    returnBook();

    return 0;
}
