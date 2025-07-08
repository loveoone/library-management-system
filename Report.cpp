
#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string books[100];
    int bookCount;
    string borrowers[100];
    int borrowCount;

public:
    Library() {
        bookCount = 0;
        borrowCount = 0;
    }

    void addBook(string title) {
        if (bookCount < 100) {
            books[bookCount] = title;
            bookCount++;
            cout << "Book added: " << title << endl;
        } else {
            cout << "Library full!" << endl;
        }
    }

    void borrowBook(string book, string borrower) {
        if (borrowCount < 100) {
            borrowers[borrowCount] = borrower + " borrowed " + book;
            borrowCount++;
            cout << borrower << " borrowed " << book << endl;
        } else {
            cout << "Borrow limit reached!" << endl;
        }
    }

    void generateReport() {
        cout << "\n=== Library Report ===" << endl;
        
        cout << "\nAvailable Books (" << bookCount << "):" << endl;
        for (int i = 0; i < bookCount; i++) {
            cout << "- " << books[i] << endl;
        }

        cout << "\nBorrowed Books (" << borrowCount << "):" << endl;
        for (int i = 0; i < borrowCount; i++) {
            cout << "- " << borrowers[i] << endl;
        }

        cout << "\nTotal Items: " << bookCount + borrowCount << endl;
        cout << "====================" << endl;
    }
};

int main() {
    Library lib;

    // Sample data
    lib.addBook("The Great Gatsby");
    lib.addBook("1984");
    lib.addBook("To Kill a Mockingbird");
    lib.borrowBook("1984", "Alice");
    lib.borrowBook("The Great Gatsby", "Bob");

    // Generate report
    lib.generateReport();

    return 0;
}
