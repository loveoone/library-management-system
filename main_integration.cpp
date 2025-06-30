#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

// ================== STRUCT DEFINITIONS ==================
struct Book {
    string isbn;
    string title;
    string author;
};

struct Member {
    int memberId;
    string name;
};

struct Transaction {
    string isbn;
    int memberId;
    string borrowDate;
    string dueDate;
};

// ================== GLOBAL DATA ==================
vector<Book> books = {
    {"123456", "The Great Gatsby", "F. Scott Fitzgerald"},
    {"789012", "1984", "George Orwell"},
    {"345678", "Pride and Prejudice", "Jane Austen"}
};

vector<Member> members = {
    {1, "Alice Smith"},
    {2, "Bob Johnson"}
};

vector<Transaction> transactions = {
    {"123456", 1, "2025-06-01", "2025-06-15"},
    {"789012", 2, "2025-06-10", "2025-06-24"},
    {"345678", 1, "2025-06-20", "2025-07-05"}
};

// ================== IMPLEMENTED MODULES ==================

// ✅ Book Management - Afomiya
void bookMenu() {
    struct BookLocal {
        int id;
        char title[50];
        char author[50];
        bool isIssued;
    };
    const int MAX_BOOKS = 100;
    static BookLocal booksLocal[MAX_BOOKS];
    static int bookCount = 0;

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
                cout << "Library is full.\n";
                continue;
            }
            cout << "Enter Book ID: ";
            cin >> booksLocal[bookCount].id;
            cin.ignore();
            cout << "Enter Book Title: ";
            cin.getline(booksLocal[bookCount].title, 50);
            cout << "Enter Author Name: ";
            cin.getline(booksLocal[bookCount].author, 50);
            booksLocal[bookCount].isIssued = false;
            bookCount++;
            cout << "Book added successfully.\n";
        }
        else if (choice == 2) {
            if (bookCount == 0) {
                cout << "No books available.\n";
            } else {
                for (int i = 0; i < bookCount; i++) {
                    cout << booksLocal[i].id << " | "
                         << booksLocal[i].title << " | "
                         << booksLocal[i].author << " | "
                         << (booksLocal[i].isIssued ? "Issued" : "Available") << endl;
                }
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to modify: ";
            cin >> id;
            cin.ignore();
            bool found = false;
            for (int i = 0; i < bookCount; i++) {
                if (booksLocal[i].id == id) {
                    cout << "Enter new title: ";
                    cin.getline(booksLocal[i].title, 50);
                    cout << "Enter new author: ";
                    cin.getline(booksLocal[i].author, 50);
                    cout << "Book modified successfully.\n";
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
                if (booksLocal[i].id == id) {
                    for (int j = i; j < bookCount - 1; j++) {
                        booksLocal[j] = booksLocal[j + 1];
                    }
                    bookCount--;
                    cout << "Book deleted successfully.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
    } while (choice != 0);
}

// ✅ Book Return - Nahom
void returnBook() {
    string bookId;
    cout << "Enter Book ISBN to return: ";
    cin >> bookId;

    bool found = false;
    for (auto& t : transactions) {
        if (t.isbn == bookId) {
            found = true;
            cout << "Book with ISBN " << bookId << " returned successfully.\n";
            break;
        }
    }
    if (!found) {
        cout << "Book with ISBN " << bookId << " not found in transaction records.\n";
    }
}

// ✅ Report Generation - Samuel
string getCurrentDate() {
    time_t now = time(nullptr);
    struct tm* t = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", t);
    return string(buffer);
}

void generateBorrowedBooksTextReport(
    const vector<Transaction>& transactions,
    const vector<Book>& books,
    const vector<Member>& members,
    const string& filename
) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Could not open file " << filename << endl;
        return;
    }

    outFile << left << setw(15) << "ISBN"
            << setw(30) << "Book Title"
            << setw(20) << "Member Name"
            << setw(15) << "Borrow Date"
            << setw(15) << "Due Date"
            << setw(10) << "Status" << endl;
    outFile << string(105, '-') << endl;

    string currentDate = getCurrentDate();
    for (const auto& transaction : transactions) {
        string bookTitle = "Unknown";
        string memberName = "Unknown";

        for (const auto& book : books) {
            if (book.isbn == transaction.isbn) {
                bookTitle = book.title;
                break;
            }
        }
        for (const auto& member : members) {
            if (member.memberId == transaction.memberId) {
                memberName = member.name;
                break;
            }
        }

        string status = (transaction.dueDate < currentDate) ? "Overdue" : "On Time";

        outFile << left << setw(15) << transaction.isbn
                << setw(30) << bookTitle
                << setw(20) << memberName
                << setw(15) << transaction.borrowDate
                << setw(15) << transaction.dueDate
                << setw(10) << status << endl;
    }

    outFile.close();
    cout << "Text report generated: " << filename << endl;
}

void generateBorrowedBooksCSVReport(
    const vector<Transaction>& transactions,
    const vector<Book>& books,
    const vector<Member>& members,
    const string& filename
) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Could not open file " << filename << endl;
        return;
    }

    outFile << "ISBN,Book Title,Member Name,Borrow Date,Due Date,Status\n";

    string currentDate = getCurrentDate();
    for (const auto& transaction : transactions) {
        string bookTitle = "Unknown";
        string memberName = "Unknown";

        for (const auto& book : books) {
            if (book.isbn == transaction.isbn) {
                bookTitle = book.title;
                break;
            }
        }
        for (const auto& member : members) {
            if (member.memberId == transaction.memberId) {
                memberName = member.name;
                break;
            }
        }

        string status = (transaction.dueDate < currentDate) ? "Overdue" : "On Time";

        outFile << transaction.isbn << "," << bookTitle << "," << memberName << ","
                << transaction.borrowDate << "," << transaction.dueDate << ","
                << status << "\n";
    }

    outFile.close();
    cout << "CSV report generated: " << filename << endl;
}

// ================== PLACEHOLDER FUNCTIONS ==================

// 🚧 User Management - Afomiya
void manageUsers() {
    cout << "[User Management] Module not implemented yet.\n";
}

// 🚧 Book Issuing - Biruk
void issueBook() {
    cout << "[Book Issuing] Module not implemented yet.\n";
}

// 🚧 File Handling - Tewodrose
void handleFiles() {
    cout << "[File Handling] Module not implemented yet.\n";
}

// 🚧 Backup & Recovery - Harun
void backupSystem() {
    cout << "[Backup & Recovery] Module not implemented yet.\n";
}

// 🚧 Search System - Huzeyfa
void searchBooks() {
    cout << "[Search System] Module not implemented yet.\n";
}

// ================== MAIN MENU ==================
void mainMenu() {
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Book Management\n";
        cout << "2. User Management\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. File Handling\n";
        cout << "6. Backup & Recovery\n";
        cout << "7. Search Book\n";
        cout << "8. Generate Reports\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bookMenu(); break;
            case 2: manageUsers(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: handleFiles(); break;
            case 6: backupSystem(); break;
            case 7: searchBooks(); break;
            case 8:
                generateBorrowedBooksTextReport(transactions, books, members, "borrowed_books.txt");
                generateBorrowedBooksCSVReport(transactions, books, members, "borrowed_books.csv");
                break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// ================== MAIN ==================
int main() {
    mainMenu();
    return 0;
}
