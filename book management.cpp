#include <iostream>
using namespace std;

// ------------------ Global Arrays ------------------

const int MAX_BOOKS = 100;
int bookIDs[MAX_BOOKS];
char bookTitles[MAX_BOOKS][50];
char bookAuthors[MAX_BOOKS][50];
bool bookIssued[MAX_BOOKS];
int bookCount = 0;

// ------------------ Functions ------------------

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    }

    cout << "Enter Book ID: ";
    cin >> bookIDs[bookCount];
    cin.ignore();
    cout << "Enter Book Title: ";
    cin.getline(bookTitles[bookCount], 50);
    cout << "Enter Author Name: ";
    cin.getline(bookAuthors[bookCount], 50);
    bookIssued[bookCount] = false;

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
        cout << bookIDs[i] << " | " << bookTitles[i] << " | " << bookAuthors[i];
        cout << " | " << (bookIssued[i] ? "Issued" : "Available") << "\n";
    }
}

void modifyBook() {
    int id;
    cout << "Enter Book ID to modify: ";
    cin >> id;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookIDs[i] == id) {
            cout << "Enter new title: ";
            cin.getline(bookTitles[i], 50);
            cout << "Enter new author: ";
            cin.getline(bookAuthors[i], 50);
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
        if (bookIDs[i] == id) {
            for (int j = i; j < bookCount - 1; j++) {
                bookIDs[j] = bookIDs[j + 1];
                strcpy(bookTitles[j], bookTitles[j + 1]);
                strcpy(bookAuthors[j], bookAuthors[j + 1]);
                bookIssued[j] = bookIssued[j + 1];
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