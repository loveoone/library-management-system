#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Book {
public:
    int bookID;
    string title;
    string author;
    bool isIssued;

    Book() {
        bookID = 0;
        title = "";
        author = "";
        isIssued = false;
    }

    void inputBook() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        isIssued = false;
    }

    void displayBook() const {
        cout << bookID << " | " << title << " | " << author 
             << " | " << (isIssued ? "Issued" : "Available") << endl;
    }

    void modifyBook() {
        cout << "Editing Book ID: " << bookID << endl;
        cout << "Enter new Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter new Author: ";
        getline(cin, author);
    }
};

// File handling helpers
void saveBooksToFile(const vector<Book>& books) {
    ofstream file("books.txt");
    for (const Book& b : books) {
        file << b.bookID << "|" << b.title << "|" << b.author << "|" << b.isIssued << "\n";
    }
    file.close();
}

vector<Book> loadBooksFromFile() {
    vector<Book> books;
    ifstream file("books.txt");
    Book b;
    while (file >> b.bookID) {
        file.ignore(); // skip '|'
        getline(file, b.title, '|');
        getline(file, b.author, '|');
        file >> b.isIssued;
        file.ignore(); // skip newline
        books.push_back(b);
    }
    file.close();
    return books;
}

// Menu system for managing books
void bookMenu() {
    vector<Book> books = loadBooksFromFile();
    int choice;
    do {
        cout << "\n--- Book Management Menu ---\n";
        cout << "1. Add Book\n2. Display All Books\n3. Modify Book\n4. Delete Book\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Book b;
            b.inputBook();
            books.push_back(b);
            saveBooksToFile(books);
            cout << "Book added successfully!\n";
        } 
        else if (choice == 2) {
            cout << "\nBook List:\n";
            for (const Book& b : books) {
                b.displayBook();
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to modify: ";
            cin >> id;
            bool found = false;
            for (Book& b : books) {
                if (b.bookID == id) {
                    b.modifyBook();
                    found = true;
                    break;
                }
            }
            if (found) {
                saveBooksToFile(books);
                cout << "Book updated successfully!\n";
            } else {
                cout << "Book not found.\n";
            }
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to delete: ";
            cin >> id;
            bool deleted = false;
            for (auto it = books.begin(); it != books.end(); ++it) {
                if (it->bookID == id) {
                    books.erase(it);
                    deleted = true;
                    break;
                }
            }
            if (deleted) {
                saveBooksToFile(books);
                cout << "Book deleted successfully.\n";
            } else {
                cout << "Book not found.\n";
            }
        }
    } while (choice != 0);
}

int main() {
    bookMenu(); // You can later call this from the main UI integration
    return 0;
}