#include <iostream>
using namespace std;

// ------------------ Book Structure ------------------
struct Book {
    int id;
    char title[50];
    char author[50];
    bool isIssued;
};

// ------------------ Global Book Array ------------------
const int MAX_BOOKS = 100;
Book books[MAX_BOOKS];
int bookCount = 0;

// ------------------ Functions ------------------

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    }

    cout << "Enter Book ID: ";
    cin >> books[bookCount].id;
    cin.ignore();
    cout << "Enter Book Title: ";
    cin.getline(books[bookCount].title, 50);
    cout << "Enter Author Name: ";
    cin.getline(books[bookCount].author, 50);
    books[bookCount].isIssued = false;

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
        cout << books[i].id << " | " << books[i].title << " | " << books[i].author;
        cout << " | " << (books[i].isIssued ? "Issued" : "Available") << "\n";
    }
}

void modifyBook() {
    int id;
    cout << "Enter Book ID to modify: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            cout << "Enter new title: ";
            cin.getline(books[i].title, 50);
            cout << "Enter new author: ";
            cin.getline(books[i].author, 50);
            found = true;
            cout << "✅ Book modified successfully!\n";
            break;
        }
    }
    if (!found) cout << "❌ Book not found.\n";
}

void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            found = true;
            cout << "✅ Book deleted successfully!\n";
            break;
        }
    }
    if (!found) cout << "❌ Book not found.\n";
}

// ------------------ Menu ------------------

void bookMenu() {
    int choice;
    do {
        cout << "\n=== Book Management Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Modify Book\n";
        cout << "4. Delete Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: modifyBook(); break;
            case 4: deleteBook(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "❗ Invalid choice.\n";
        }
    } while (choice != 0);
}

// ------------------ Main ------------------

int main() {
    bookMenu();
    return 0;
}